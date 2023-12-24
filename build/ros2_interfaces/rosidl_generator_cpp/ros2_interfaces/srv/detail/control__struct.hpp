// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_interfaces:srv/Control.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__CONTROL__STRUCT_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__CONTROL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__srv__Control_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__srv__Control_Request __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Control_Request_
{
  using Type = Control_Request_<ContainerAllocator>;

  explicit Control_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->status = 0l;
    }
  }

  explicit Control_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->status = 0l;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _status_type =
    int32_t;
  _status_type status;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interfaces::srv::Control_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::srv::Control_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::srv::Control_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::srv::Control_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::Control_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::Control_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::Control_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::Control_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::srv::Control_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::srv::Control_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__srv__Control_Request
    std::shared_ptr<ros2_interfaces::srv::Control_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__srv__Control_Request
    std::shared_ptr<ros2_interfaces::srv::Control_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Control_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Control_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Control_Request_

// alias to use template instance with default allocator
using Control_Request =
  ros2_interfaces::srv::Control_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_interfaces


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__srv__Control_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__srv__Control_Response __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Control_Response_
{
  using Type = Control_Response_<ContainerAllocator>;

  explicit Control_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->action = 0l;
    }
  }

  explicit Control_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->action = 0l;
    }
  }

  // field types and members
  using _status_type =
    int32_t;
  _status_type status;
  using _action_type =
    int32_t;
  _action_type action;
  using _pose_type =
    geometry_msgs::msg::Pose2D_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__action(
    const int32_t & _arg)
  {
    this->action = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose2D_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interfaces::srv::Control_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::srv::Control_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::srv::Control_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::srv::Control_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::Control_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::Control_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::Control_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::Control_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::srv::Control_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::srv::Control_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__srv__Control_Response
    std::shared_ptr<ros2_interfaces::srv::Control_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__srv__Control_Response
    std::shared_ptr<ros2_interfaces::srv::Control_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Control_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->action != other.action) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const Control_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Control_Response_

// alias to use template instance with default allocator
using Control_Response =
  ros2_interfaces::srv::Control_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_interfaces

namespace ros2_interfaces
{

namespace srv
{

struct Control
{
  using Request = ros2_interfaces::srv::Control_Request;
  using Response = ros2_interfaces::srv::Control_Response;
};

}  // namespace srv

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__SRV__DETAIL__CONTROL__STRUCT_HPP_
