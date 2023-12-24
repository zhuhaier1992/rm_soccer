// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_interfaces:msg/RobotTwist.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST__TRAITS_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST__TRAITS_HPP_

#include "ros2_interfaces/msg/detail/robot_twist__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros2_interfaces::msg::RobotTwist & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: twist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.twist.size() == 0) {
      out << "twist: []\n";
    } else {
      out << "twist:\n";
      for (auto item : msg.twist) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros2_interfaces::msg::RobotTwist & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros2_interfaces::msg::RobotTwist>()
{
  return "ros2_interfaces::msg::RobotTwist";
}

template<>
inline const char * name<ros2_interfaces::msg::RobotTwist>()
{
  return "ros2_interfaces/msg/RobotTwist";
}

template<>
struct has_fixed_size<ros2_interfaces::msg::RobotTwist>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_interfaces::msg::RobotTwist>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_interfaces::msg::RobotTwist>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST__TRAITS_HPP_
