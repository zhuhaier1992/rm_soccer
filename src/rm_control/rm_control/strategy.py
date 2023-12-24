import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from robomaster_msgs.action import Move
from ros2_interfaces.msg import RobotPose, RobotTwist2D
from ros2_interfaces.srv import Control
from geometry_msgs.msg import Twist, Vector3, Pose2D
import time
import message_filters
from .utils import *

target_pose=[Pose2D(x=-2.7, y=-1.2, theta=0.),
              Pose2D(x=-2.3, y=0., theta=0.),
              Pose2D(x=-2.7, y=1.2, theta=0.),
              Pose2D(x=1.3, y=-1.2, theta=0.),
              Pose2D(x=0.9, y=0., theta=0.),
              Pose2D(x=1.3, y=1.2, theta=0.),]
whole_range=[[-4.07,2.7],[-2.26,2.4]]
safe_range_x=[-3.2, 1.9]
safe_range_y=[-2., 2.2]
attacker=0
shooter=0
pg1=Pose2D(x=-4.0, y=0.) # 上方队伍的球门
pg2=Pose2D(x=2.7, y=0.) # 下方的球门

class Strategy(Node):
    def __init__(self, name):
        super().__init__(name)
        self.name=name
        self.get_logger().info(f"strategy已启动!")
        self.goal_pub=self.create_service(Control, 'control', self.resp_control)
        # self.pose_sub=self.create_subscription(RobotPose, 'robot_pose', self.get_poses, 10)
        # self.twist_sub=self.create_subscription(RobotTwist2D, 'robot_twist', self.get_twists, 10)
        self.pose_sub=message_filters.Subscriber(self, RobotPose,'robot_pose')
        self.twist_sub=message_filters.Subscriber(self, RobotTwist2D,'robot_twist')
        ts = message_filters.TimeSynchronizer([self.twist_sub, self.pose_sub], 10)
        ts.registerCallback(self.get_poses)
        
        self.poses=RobotPose()
        self.twists=RobotTwist2D()
        self.target_poses=np.zeros((6,3))
        self.recv_status=[1]*6 # 默认6台都是move
        self.status=[1]*6 # 默认6台都是move
        self.action=[0]*6 
        self.kicker=0
        self.catcher=0
        self.vb=np.zeros(2)


    def resp_control(self, request, response):
        global shooter
        
        id=request.id
        self.recv_status[id-1]=request.status

        response.pose=nparray_to_pose2d(self.target_poses[id-1])
        # self.get_logger().info(f'reponse id is {id}')
        response.status=self.status[id-1]
        # self.get_logger().info(f'recv: {id}, {response.status}')
        return response


    def get_poses(self, msg1=None, msg2=None):
        global shooter
        # self.get_logger().info(f'getting poses:{msg1}, {msg2}')
        if msg1==None:
            self.get_logger().error('twist is none')
            self.status=[0]*6
            return 
        elif len(msg1.twist) == 0:
            self.get_logger().error('twist is []')
            self.status=[0]*6
            return 
        else:
            try:
                self.twists=msg1
                self.vb=np.array([self.twists.twist[0].x, self.twists.twist[0].y,0])
            except Exception as e:
                self.get_logger().error(f'error in get_twist(): {e}')
                self.status=[0]*6
                return 

        if len(msg2.pose)==0:
            self.get_logger().error(f'poses is []: {msg2}')
            self.status=[0]*6
            return 
        elif len(msg2.pose) >= 7:
            self.status=[1]*6
            # try:
            p=msg2.pose[:7] # list of Pose2D
            self.poses.pose=p
            p_arr=pose2d_to_nparray(p) # np array
            
            # self.get_logger().info(f'oob is {oob}')
            if 3 in self.recv_status: # 有rm在抓球
                self.target_poses[self.catcher-1]=pose2d_to_nparray(calc_catching_pose(p[0], p[self.catcher]))
            elif 4 in self.recv_status: # catcher抓住了球，reset中
                self.target_poses=pose2d_to_nparray(target_pose)
            else: # 正常游戏状态
                oob=self.out_of_boundary(p[0])
                if oob!=0:
                    self.catcher=oob
                    self.get_logger().info(f'RM{self.catcher} starts to catch')
                    self.target_poses=pose2d_to_nparray(p)
                    self.target_poses[oob-1]=pose2d_to_nparray(calc_catching_pose(p[0], p[oob]))
                    self.status=[4]*6
                    self.status[oob-1]=3 # 该rm变为catcher
                elif 2 not in self.recv_status: #没人在踢球
                    shooter, t, p_collide=find_closest(self.poses, self.twists.twist[0])
                    pb=p[0]
                    self.kicker=shooter
                    self.status[shooter-1]=2
                    pb_arr=pose2d_to_nparray(pb)
                    
                    sp=np.array([0,0,0]) # shoot position
                    if self.kicker in [1,2,3]:
                        sp=shoot_position(pb, pg2)+self.vb
                        a=0.4
                        b=1.6                     
                    else:
                        sp=shoot_position(pb, pg1)+self.vb
                        a=1.6
                        b=0.4

                    for i in range(3):
                        self.target_poses[i]=np.array([pb_arr[0]-a, target_pose[i].y, 
                                        calc_aiming_goal(p_arr[i+1], pose2d_to_nparray(pg2))])
                        
                    for i in range(3,6):
                        self.target_poses[i]=np.array([pb_arr[0]+b, target_pose[i].y, 
                                        calc_aiming_goal(p_arr[i+1], pose2d_to_nparray(pg1))])
                    self.target_poses[shooter-1]=sp

                    # self.get_logger().info(f'self.target: {self.target_poses}')
                    np.clip(self.target_poses, [safe_range_x[0], safe_range_y[0],-4],
                            [safe_range_x[1], safe_range_y[1],4], out=self.target_poses)
                else: # 有人在踢球
                    pb=p[0]
                    pb_arr=pose2d_to_nparray(pb)
                    if self.kicker in [1,2,3]:
                        sp=shoot_position(pb, pg2)+self.vb
                        a=0.4
                        b=1.2                     
                    else:
                        sp=shoot_position(pb, pg1)+self.vb
                        a=1.2
                        b=0.4

                    for i in range(3):
                        self.target_poses[i]=np.array([pb_arr[0]-a, target_pose[i].y, 
                                        calc_aiming_goal(p_arr[i+1], pose2d_to_nparray(pg2))])
                        
                    for i in range(3,6):
                        self.target_poses[i]=np.array([pb_arr[0]+b, target_pose[i].y, 
                                        calc_aiming_goal(p_arr[i+1], pose2d_to_nparray(pg1))])
                    self.target_poses[self.kicker-1]=sp

                    # self.get_logger().info(f'self.target: {self.target_poses}')
                    np.clip(self.target_poses, [safe_range_x[0], safe_range_y[0],-4],
                            [safe_range_x[1], safe_range_y[1],4], out=self.target_poses)
                    # pass
                    # self.get_logger().info(f'self.target clipped: {self.target_poses}')
                # return self.target_poses
            # except Exception as e:
            #     self.get_logger().error(f'len of poses: {len(msg2.pose)}')
            #     self.get_logger().error(e)
    

    @staticmethod
    def out_of_boundary(pb: Pose2D):
        if pb.y<safe_range_y[0]:
            return 1
        elif pb.y>safe_range_y[1]:
            return 3
        elif pb.x>safe_range_x[1] or pb.x<safe_range_x[0]:
            return 2
        else:
            return 0



def main(args=None):
    rclpy.init(args=args)
    strategy = Strategy(name='strategy')
    rclpy.spin(strategy)
    strategy.destroy_node()
    rclpy.shutdown()