// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_interfaces:srv/Control.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__CONTROL__TRAITS_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__CONTROL__TRAITS_HPP_

#include "ros2_interfaces/srv/detail/control__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros2_interfaces::srv::Control_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros2_interfaces::srv::Control_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros2_interfaces::srv::Control_Request>()
{
  return "ros2_interfaces::srv::Control_Request";
}

template<>
inline const char * name<ros2_interfaces::srv::Control_Request>()
{
  return "ros2_interfaces/srv/Control_Request";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::Control_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_interfaces::srv::Control_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_interfaces::srv::Control_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros2_interfaces::srv::Control_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action: ";
    value_to_yaml(msg.action, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros2_interfaces::srv::Control_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros2_interfaces::srv::Control_Response>()
{
  return "ros2_interfaces::srv::Control_Response";
}

template<>
inline const char * name<ros2_interfaces::srv::Control_Response>()
{
  return "ros2_interfaces/srv/Control_Response";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::Control_Response>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose2D>::value> {};

template<>
struct has_bounded_size<ros2_interfaces::srv::Control_Response>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose2D>::value> {};

template<>
struct is_message<ros2_interfaces::srv::Control_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_interfaces::srv::Control>()
{
  return "ros2_interfaces::srv::Control";
}

template<>
inline const char * name<ros2_interfaces::srv::Control>()
{
  return "ros2_interfaces/srv/Control";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::Control>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_interfaces::srv::Control_Request>::value &&
    has_fixed_size<ros2_interfaces::srv::Control_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_interfaces::srv::Control>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_interfaces::srv::Control_Request>::value &&
    has_bounded_size<ros2_interfaces::srv::Control_Response>::value
  >
{
};

template<>
struct is_service<ros2_interfaces::srv::Control>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_interfaces::srv::Control_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_interfaces::srv::Control_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_INTERFACES__SRV__DETAIL__CONTROL__TRAITS_HPP_
