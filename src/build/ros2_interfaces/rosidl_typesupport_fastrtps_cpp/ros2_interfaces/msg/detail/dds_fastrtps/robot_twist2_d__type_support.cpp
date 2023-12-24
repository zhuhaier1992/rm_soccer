// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:msg/RobotTwist2D.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/robot_twist2_d__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2_interfaces/msg/detail/robot_twist2_d__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Vector3 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Vector3 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Vector3 &,
  size_t current_alignment);
size_t
max_serialized_size_Vector3(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace ros2_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
cdr_serialize(
  const ros2_interfaces::msg::RobotTwist2D & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: twist
  {
    size_t size = ros_message.twist.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.twist[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_interfaces::msg::RobotTwist2D & ros_message)
{
  // Member: twist
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.twist.resize(size);
    for (size_t i = 0; i < size; i++) {
      geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.twist[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
get_serialized_size(
  const ros2_interfaces::msg::RobotTwist2D & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: twist
  {
    size_t array_size = ros_message.twist.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.twist[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
max_serialized_size_RobotTwist2D(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: twist
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector3(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _RobotTwist2D__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_interfaces::msg::RobotTwist2D *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotTwist2D__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_interfaces::msg::RobotTwist2D *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotTwist2D__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_interfaces::msg::RobotTwist2D *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotTwist2D__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RobotTwist2D(full_bounded, 0);
}

static message_type_support_callbacks_t _RobotTwist2D__callbacks = {
  "ros2_interfaces::msg",
  "RobotTwist2D",
  _RobotTwist2D__cdr_serialize,
  _RobotTwist2D__cdr_deserialize,
  _RobotTwist2D__get_serialized_size,
  _RobotTwist2D__max_serialized_size
};

static rosidl_message_type_support_t _RobotTwist2D__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotTwist2D__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ros2_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_interfaces::msg::RobotTwist2D>()
{
  return &ros2_interfaces::msg::typesupport_fastrtps_cpp::_RobotTwist2D__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_interfaces, msg, RobotTwist2D)() {
  return &ros2_interfaces::msg::typesupport_fastrtps_cpp::_RobotTwist2D__handle;
}

#ifdef __cplusplus
}
#endif
