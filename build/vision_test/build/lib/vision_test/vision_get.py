from rclpy.node import Node
from sensor_msgs.msg import Image
from robomaster_msgs.msg import H264Packet
from typing import Iterator, Any
from cv_bridge import CvBridge

import cv2
import rclpy
import numpy as np


class LibMediaDecoder:

    def __init__(self) -> None:
        import libmedia_codec
        self._video_decoder = libmedia_codec.H264Decoder()

    def decode(self, data: bytes) -> Iterator[np.ndarray]:
        # rclpy.logging.get_logger("decoder").info(f"decode {len(data)} {data[:10]}")
        frames = self._video_decoder.decode(data)
        # rclpy.logging.get_logger("decoder").info(f"-> {len(frames)}")
        for frame_data in frames:
            (frame, width, height, _) = frame_data
            if frame:
                frame = np.frombuffer(frame, dtype=np.ubyte)
                yield frame.reshape((height, width, 3))

class VisionNode(Node):
    def __init__(self, name):
        super().__init__(name)
        self.decoder=LibMediaDecoder()
        self.bridge = CvBridge()
        self.sub=self.create_subscription(Image, 'image_raw', 
                                          self.show_frame, 10)

    def show_frame(self, msg: Image):
        self.get_logger().info(str(msg.header))

        cv_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')


        # 在opencv的显示窗口中绘制一个圆，作为标记
        (rows,cols,channels) = cv_image.shape
        if cols > 60 and rows > 60 :
            cv2.circle(cv_image, (60, 60), 30, (0,0,255), -1)

        # 显示Opencv格式的图像
        cv2.imshow("Image window", cv_image)
        cv2.waitKey(3)

def main(args: Any = None):
    rclpy.init(args=args)
    node = VisionNode('vision_get')
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

