import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from robomaster_msgs.action import MoveArm
from ros2_interfaces.msg import RobotPose
from ros2_interfaces.srv import Control
from geometry_msgs.msg import Twist, Vector3, Pose2D, PointStamped
import time
from rclpy.parameter import Parameter

from .utils import *

target_pose=[Pose2D(x=-2.7, y=-1.2, theta=0.),
              Pose2D(x=-2.3, y=0., theta=0.),
              Pose2D(x=-2.7, y=1.2, theta=0.),
              Pose2D(x=1.3, y=-1.2, theta=0.),
              Pose2D(x=0.9, y=0., theta=0.),
              Pose2D(x=1.3, y=1.2, theta=0.),]
# arm_pose: high for move, low for catch
arm_pose=[MoveArm.Goal(x=0.15, z=0.06), MoveArm.Goal(x=0.18, z=-0.07)]
attacker=0
shooter=0

class RobotControl(Node):
    def __init__(self, name):
        super().__init__(name)
        self.name=name
        self.id=int(self.get_name()[2])
        # self.param_chassis=Parameter('chassis_timeout', Parameter.Type.DOUBLE, 1.)
        # self.set_parameters([
        #     Parameter('/robomaster.chassis.timeout', Parameter.Type.DOUBLE, 1.)
        # ])
        self.node=Node(node_name='param1',namespace='/RM1/robomaster')
        self.node.declare_parameter('chassis.timeout', 0.1)
        self.node.set_parameters([
            Parameter('chassis.timeout', Parameter.Type.DOUBLE, 1.)
        ])
        
        # self.set_parameters([param])
        self.arm_action=ActionClient(self, MoveArm, '/RM1/move_arm')
        self.get_logger().info(f"节点已启动：{self.get_name()}!")
        # self.action_client_ = ActionClient(self, Move, 'move')
        # self.send_goal_timer_ = self.create_timer(0.1, self.send_req)
        self.goal_pub=self.create_publisher(Twist, f'/RM{self.id}/cmd_vel',5)
        self.pose_sub=self.create_subscription(RobotPose, 'robot_pose', self.update_pose, 10)
        self.arm_sub=self.create_subscription(PointStamped, '/RM1/arm_position', self.update_arm, 10)
        # self.strategy_client = self.create_client(Control, 'control')

        self.global_target=target_pose[self.id-1]
        self.arm_goal=MoveArm.Goal()
        self.pose=Pose2D()
        self.status=3 # 0: stop 1: move 2: kick 3: force stop
        self.action=0 # 0: no action 1: catch 2: release
        self.req_c=Control.Request()
        self.req_c.id=self.id
        self.req_c.status=self.status


    # def send_req(self):
    #     self.future=self.strategy_client.call_async(self.req_c).add_done_callback(self.send_goal)
        
        
    def send_goal(self):
        # t=self.get_parameter('/robomaster.chassis.timeout')
        # self.get_logger().info(f'timeout is {t.value}')
        if self.status==1:
            self.arm_goal=arm_pose[0]
            self.arm_future=self.arm_action.send_goal_async(self.arm_goal)
            # rel_target=trans_relative_co(self.pose, self.global_target)
            # self.goal_pub.publish(self.pose2d_to_twist(rel_target))
            # self.get_logger().info(f'RM{self.id} published goal {self.pose2d_to_twist(rel_target)}')
        elif self.status==2:
            if dis_pose2d(self.pose, self.global_target)<0.02:
                self.goal_pub.publish(self.pose2d_to_twist(Pose2D(x=2)))
                time.sleep(0.5)
                self.status=1
            else:
                rel_target=Pose2D(x=1., y=0., theta=0.)
                self.goal_pub.publish(self.pose2d_to_twist(rel_target))
        elif self.status==3:
            self.arm_goal=arm_pose[1]
            self.arm_future=self.arm_action.send_goal_async(self.arm_goal)



    def arm_callback(self, feedback_msg):
        feedback = feedback_msg.feedback       # 读取反馈的数据
        self.get_logger().info('Received feedback: {%d}' % feedback.progress) 

    def update_arm(self, msg):
        self.get_logger().info(f'cur arm: {msg.point}')


    def update_pose(self, msg):
        if len(msg.pose)==0:
            self.goal_pub.publish(self.pose2d_to_twist(Pose2D(x=0.,y=0.,theta=0.)))
            self.get_logger().info(f'RM{self.id} got error pose data')
            self.status=0
        else:
            self.pose=msg.pose[self.id]


    @staticmethod
    def pose2d_to_twist(pose: Pose2D):
        return Twist(linear=Vector3(x=pose.x, y=pose.y), angular=Vector3(z=pose.theta))


def main(args=None):
    rclpy.init(args=args)
    robot_control = RobotControl(name='RM1')
    robot_control.send_goal()
    rclpy.spin(robot_control)
    robot_control.destroy_node()
    rclpy.shutdown()