// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_interfaces:msg/RobotTwist2D.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST2_D__STRUCT_H_
#define ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST2_D__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'twist'
#include "geometry_msgs/msg/detail/vector3__struct.h"

// Struct defined in msg/RobotTwist2D in the package ros2_interfaces.
typedef struct ros2_interfaces__msg__RobotTwist2D
{
  geometry_msgs__msg__Vector3__Sequence twist;
} ros2_interfaces__msg__RobotTwist2D;

// Struct for a sequence of ros2_interfaces__msg__RobotTwist2D.
typedef struct ros2_interfaces__msg__RobotTwist2D__Sequence
{
  ros2_interfaces__msg__RobotTwist2D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__msg__RobotTwist2D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_INTERFACES__MSG__DETAIL__ROBOT_TWIST2_D__STRUCT_H_
