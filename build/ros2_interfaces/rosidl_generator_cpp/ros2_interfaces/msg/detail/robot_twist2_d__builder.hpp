// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:msg/RobotTwist2D.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST2_D__BUILDER_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST2_D__BUILDER_HPP_

#include "ros2_interfaces/msg/detail/robot_twist2_d__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotTwist2D_twist
{
public:
  explicit Init_RobotTwist2D_twist(::ros2_interfaces::msg::RobotTwist2D & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::msg::RobotTwist2D twist(::ros2_interfaces::msg::RobotTwist2D::_twist_type arg)
  {
    msg_.twist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::msg::RobotTwist2D msg_;
};

class Init_RobotTwist2D_header
{
public:
  Init_RobotTwist2D_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTwist2D_twist header(::ros2_interfaces::msg::RobotTwist2D::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotTwist2D_twist(msg_);
  }

private:
  ::ros2_interfaces::msg::RobotTwist2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::msg::RobotTwist2D>()
{
  return ros2_interfaces::msg::builder::Init_RobotTwist2D_header();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST2_D__BUILDER_HPP_
