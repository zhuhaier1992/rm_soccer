// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:srv/Control.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__CONTROL__BUILDER_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__CONTROL__BUILDER_HPP_

#include "ros2_interfaces/srv/detail/control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Control_Request_status
{
public:
  explicit Init_Control_Request_status(::ros2_interfaces::srv::Control_Request & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::srv::Control_Request status(::ros2_interfaces::srv::Control_Request::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::srv::Control_Request msg_;
};

class Init_Control_Request_id
{
public:
  Init_Control_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Control_Request_status id(::ros2_interfaces::srv::Control_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Control_Request_status(msg_);
  }

private:
  ::ros2_interfaces::srv::Control_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::srv::Control_Request>()
{
  return ros2_interfaces::srv::builder::Init_Control_Request_id();
}

}  // namespace ros2_interfaces


namespace ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Control_Response_pose
{
public:
  explicit Init_Control_Response_pose(::ros2_interfaces::srv::Control_Response & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::srv::Control_Response pose(::ros2_interfaces::srv::Control_Response::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::srv::Control_Response msg_;
};

class Init_Control_Response_action
{
public:
  explicit Init_Control_Response_action(::ros2_interfaces::srv::Control_Response & msg)
  : msg_(msg)
  {}
  Init_Control_Response_pose action(::ros2_interfaces::srv::Control_Response::_action_type arg)
  {
    msg_.action = std::move(arg);
    return Init_Control_Response_pose(msg_);
  }

private:
  ::ros2_interfaces::srv::Control_Response msg_;
};

class Init_Control_Response_status
{
public:
  Init_Control_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Control_Response_action status(::ros2_interfaces::srv::Control_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Control_Response_action(msg_);
  }

private:
  ::ros2_interfaces::srv::Control_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::srv::Control_Response>()
{
  return ros2_interfaces::srv::builder::Init_Control_Response_status();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__SRV__DETAIL__CONTROL__BUILDER_HPP_
