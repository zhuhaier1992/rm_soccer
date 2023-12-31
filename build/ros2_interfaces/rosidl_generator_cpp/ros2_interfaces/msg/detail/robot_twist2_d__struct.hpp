// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_interfaces:msg/RobotTwist2D.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST2_D__STRUCT_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST2_D__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'twist'
#include "geometry_msgs/msg/detail/pose2_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__msg__RobotTwist2D __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__msg__RobotTwist2D __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotTwist2D_
{
  using Type = RobotTwist2D_<ContainerAllocator>;

  explicit RobotTwist2D_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit RobotTwist2D_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _twist_type =
    std::vector<geometry_msgs::msg::Pose2D_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Pose2D_<ContainerAllocator>>>;
  _twist_type twist;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__twist(
    const std::vector<geometry_msgs::msg::Pose2D_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Pose2D_<ContainerAllocator>>> & _arg)
  {
    this->twist = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__msg__RobotTwist2D
    std::shared_ptr<ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__msg__RobotTwist2D
    std::shared_ptr<ros2_interfaces::msg::RobotTwist2D_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTwist2D_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->twist != other.twist) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTwist2D_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTwist2D_

// alias to use template instance with default allocator
using RobotTwist2D =
  ros2_interfaces::msg::RobotTwist2D_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST2_D__STRUCT_HPP_
