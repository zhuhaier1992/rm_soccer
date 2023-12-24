// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_

#include "ros2_interfaces/msg/detail/robot_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotPose_pose
{
public:
  Init_RobotPose_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_interfaces::msg::RobotPose pose(::ros2_interfaces::msg::RobotPose::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::msg::RobotPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::msg::RobotPose>()
{
  return ros2_interfaces::msg::builder::Init_RobotPose_pose();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
