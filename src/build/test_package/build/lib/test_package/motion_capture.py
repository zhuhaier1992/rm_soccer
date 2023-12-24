from nokov.nokovsdk import *
import time
import sys, getopt

import rclpy
from rclpy.node import Node
from ros2_interfaces.msg import RobotPose, RobotTwist2D
from geometry_msgs.msg import Pose2D, Vector3, Point, Twist
from collections import deque
from math import atan2
from typing import List
import copy

preFrmNo=0
curFrmNo = 0
pi=3.14159265
no_robots=2

class MotionCapture(Node):
    def __init__(self,name):
        super().__init__(name)
        serverIp = '10.1.1.198'
        print ('serverIp is %s' % serverIp)
        client = PySDKClient()

        ver = client.PySeekerVersion()
        print('SeekerSDK Sample Client 2.4.0.3142(SeekerSDK ver. %d.%d.%d.%d)' % (ver[0], ver[1], ver[2], ver[3]))

        client.PySetVerbosityLevel(0)
        client.PySetMessageCallback(self.py_msg_func)
        client.PySetDataCallback(self.py_data_func, None)

        print("Begin to init the SDK Client")
        ret = client.Initialize(bytes(serverIp, encoding = "utf8"))

        if ret == 0:
            print("Connect to the Seeker Succeed")
        else:
            print("Connect Failed: [%d]" % ret)
            exit(0)

        #Give 5 seconds to system to init forceplate device
        ret = client.PyWaitForForcePlateInit(5000)
        if (ret != 0):
            print("Init ForcePlate Failed[%d]" % ret)
            exit(0)

        client.PySetForcePlateCallback(self.py_forcePlate_func, None)
        
        self.robot_pose_publisher_ = self.create_publisher(RobotPose,"robot_pose", 10) 
        self.robot_twist_publisher_ = self.create_publisher(RobotTwist2D,"robot_twist", 10) 
        self.poses = RobotPose()
        self.twists = RobotTwist2D()
        self.tdq=deque()
        self.pdq=deque()
        self.theta_dq=deque()
        time.sleep(2)
        print('motion capture initialization finished!!')
        while(True):
            self.publisher()
            time.sleep(1)


    def publisher(self):
        self.robot_pose_publisher_.publish(self.poses) # 发布消息
        self.robot_twist_publisher_.publish(self.twists) # 发布消息
        self.get_logger().info(f'当前位置：{self.poses}')
        self.get_logger().info(f'当前速度：{self.twists}')


    def py_data_func(self, pFrameOfMocapData, pUserData):
        if pFrameOfMocapData == None:  
            print("Not get the data frame.\n")
        else:
            frameData = pFrameOfMocapData.contents
            global preFrmNo, curFrmNo 
            curFrmNo = frameData.iFrame
            if curFrmNo == preFrmNo:
                return

            preFrmNo = curFrmNo

            self.poses.pose=[]
            self.twists.twist=[]
            
            for iBody in range(frameData.nRigidBodies):
                body = frameData.RigidBodies[iBody]
                self.poses.pose.append(Pose2D(x=body.x/1000, y=body.y/1000, theta=self.get_ori(body.qz, body.qw)))

            if frameData.nOtherMarkers!=1:
                raise(Exception, 'other unknown markers')
            else:
                pose_ball=Pose2D(x=frameData.OtherMarkers[0][0]/1000,
                                 y=frameData.OtherMarkers[0][1]/1000)
                self.poses.pose.append(pose_ball)

        # if curFrmNo % 3==0:        
        self.tdq.append(time.time())
        self.pdq.append(copy.deepcopy(self.poses.pose))
        self.theta_dq.append(copy.deepcopy(self.poses.pose))

        if len(self.tdq)>2 and len(self.pdq)>2:
            self.tdq.popleft()
            self.pdq.popleft()
            dt=self.tdq[1]-self.tdq[0]
            if dt!=0:
                for i in range(no_robots):
                    x=(self.pdq[1][i].x-self.pdq[0][i].x)/dt
                    y=(self.pdq[1][i].y-self.pdq[0][i].y)/dt
                    z=(self.pdq[1][i].theta-self.pdq[0][i].theta)/dt
                    self.twists.twist.append(Vector3(x=x/1000, y=y/1000, z=z))

                


    def py_msg_func(iLogLevel, szLogMessage):
        szLevel = "None"
        if iLogLevel == 4:
            szLevel = "Debug"
        elif iLogLevel == 3:
            szLevel = "Info"
        elif iLogLevel == 2:
            szLevel = "Warning"
        elif iLogLevel == 1:
            szLevel = "Error"
    
        print("[%s] %s" % (szLevel, cast(szLogMessage, c_char_p).value))

    def py_forcePlate_func(pFocePlates, pUserData):
        if pFocePlates == None:  
            print("Not get the forcePlate frame.\n")
            pass
        else:
            ForcePlatesData = pFocePlates.contents
            print("iFrame:%d" % ForcePlatesData.iFrame)
            for iForcePlate in range(ForcePlatesData.nForcePlates):
                print("Fxyz:[%f,%f,%f] xyz:[%f,%f,%f] MFree:[%f]" % (
                    ForcePlatesData.ForcePlates[iForcePlate].Fxyz[0],
                    ForcePlatesData.ForcePlates[iForcePlate].Fxyz[1],
                    ForcePlatesData.ForcePlates[iForcePlate].Fxyz[2],
                    ForcePlatesData.ForcePlates[iForcePlate].xyz[0],
                    ForcePlatesData.ForcePlates[iForcePlate].xyz[1],
                    ForcePlatesData.ForcePlates[iForcePlate].xyz[2],
                    ForcePlatesData.ForcePlates[iForcePlate].Mfree
                ))

    @staticmethod    
    def get_ori(z,w):
        return atan2(2*w*z,1-2*z**2)*180/pi+90 # 动捕建立刚体时以y轴为朝向，但实际返回的偏转角度还是以x轴，所以+90°以获得y轴偏转角

def main(args=None):
    rclpy.init(args=args) # 初始化rclpy
    node = MotionCapture("test")  # 新建一个节点
    rclpy.spin_once(node) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    rclpy.shutdown() # 关闭rclpy



