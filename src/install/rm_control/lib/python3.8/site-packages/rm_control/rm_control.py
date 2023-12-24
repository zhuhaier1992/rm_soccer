import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from robomaster_msgs.action import Move
from ros2_interfaces.msg import RobotPose
from geometry_msgs.msg import Twist, Vector3, Pose2D

from .utils import trans_relative_co

target_pose=[Pose2D(x=-2.3, y=-1.2, theta=0.),
             Pose2D(x=-2., y=0., theta=0.),
             Pose2D(x=-2.3, y=1.2, theta=0.),]

class RobotControl(Node):

    total=0
    def __init__(self, name):
        super().__init__(name)
        # total+=1
        self.name=name
        self.id=int(self.get_name()[2])
        
        self.get_logger().info(f"节点已启动：{name}!")
        # self.action_client_ = ActionClient(self, Move, 'move')
        self.send_goal_timer_ = self.create_timer(1, self.send_goal)
        self.goal_pub=self.create_publisher(Twist, f'/RM{self.id}/cmd_vel',5)
        self.pose_sub=self.create_subscription(RobotPose, 'robot_pose', self.send_goal, 10)
        self.global_target=target_pose[self.id-1]
        self.pose=Pose2D()

    def send_goal(self, msg=None):
        # self.get_logger().info(f'rm{self.id}: listening')
        if msg==None:
            return
        self.pose=msg.pose[self.id]
        # self.get_logger().info(f'RM{self.id} current pose: {self.pose}')
        self.get_logger().info(self.get_name())
        self.global_target.x=msg.pose[0].x
        rel_target=trans_relative_co(self.pose, self.global_target)
        # self.get_logger().info(f'RM{self.id} sending goal: {rel_target}')
        self.goal_pub.publish(self.pose2d_to_twist(rel_target))
        

    @staticmethod
    def pose2d_to_twist(pose: Pose2D):
        return Twist(linear=Vector3(x=pose.x, y=pose.y), angular=Vector3(z=pose.theta))

    def get_rel_pose(self):
        pass


def main(args=None):
    rclpy.init(args=args)
    robot_control = RobotControl(name='RM1')
    rclpy.spin(robot_control)
    robot_control.destroy_node()
    rclpy.shutdown()