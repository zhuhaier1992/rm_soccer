// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:msg/RobotTwist.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ros2_interfaces/msg/detail/robot_twist__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ros2_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RobotTwist_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2_interfaces::msg::RobotTwist(_init);
}

void RobotTwist_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2_interfaces::msg::RobotTwist *>(message_memory);
  typed_message->~RobotTwist();
}

size_t size_function__RobotTwist__twist(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotTwist__twist(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotTwist__twist(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  return &member[index];
}

void resize_function__RobotTwist__twist(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotTwist_message_member_array[1] = {
  {
    "twist",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Twist>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces::msg::RobotTwist, twist),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotTwist__twist,  // size() function pointer
    get_const_function__RobotTwist__twist,  // get_const(index) function pointer
    get_function__RobotTwist__twist,  // get(index) function pointer
    resize_function__RobotTwist__twist  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotTwist_message_members = {
  "ros2_interfaces::msg",  // message namespace
  "RobotTwist",  // message name
  1,  // number of fields
  sizeof(ros2_interfaces::msg::RobotTwist),
  RobotTwist_message_member_array,  // message members
  RobotTwist_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotTwist_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotTwist_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotTwist_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ros2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_interfaces::msg::RobotTwist>()
{
  return &::ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::RobotTwist_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_interfaces, msg, RobotTwist)() {
  return &::ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::RobotTwist_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
