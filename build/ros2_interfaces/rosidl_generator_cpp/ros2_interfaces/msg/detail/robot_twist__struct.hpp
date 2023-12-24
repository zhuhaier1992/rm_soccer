// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_interfaces:msg/RobotTwist.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST__STRUCT_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__msg__RobotTwist __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__msg__RobotTwist __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotTwist_
{
  using Type = RobotTwist_<ContainerAllocator>;

  explicit RobotTwist_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit RobotTwist_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _twist_type =
    std::vector<geometry_msgs::msg::Twist_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Twist_<ContainerAllocator>>>;
  _twist_type twist;

  // setters for named parameter idiom
  Type & set__twist(
    const std::vector<geometry_msgs::msg::Twist_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Twist_<ContainerAllocator>>> & _arg)
  {
    this->twist = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interfaces::msg::RobotTwist_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::msg::RobotTwist_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::msg::RobotTwist_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::msg::RobotTwist_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::RobotTwist_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::RobotTwist_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::RobotTwist_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::RobotTwist_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::msg::RobotTwist_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::msg::RobotTwist_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__msg__RobotTwist
    std::shared_ptr<ros2_interfaces::msg::RobotTwist_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__msg__RobotTwist
    std::shared_ptr<ros2_interfaces::msg::RobotTwist_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTwist_ & other) const
  {
    if (this->twist != other.twist) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTwist_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTwist_

// alias to use template instance with default allocator
using RobotTwist =
  ros2_interfaces::msg::RobotTwist_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST__STRUCT_HPP_
