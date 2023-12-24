// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_interfaces:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__ROBOT_POSE__STRUCT_H_
#define ROS2_INTERFACES__MSG__DETAIL__ROBOT_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__struct.h"

// Struct defined in msg/RobotPose in the package ros2_interfaces.
typedef struct ros2_interfaces__msg__RobotPose
{
  geometry_msgs__msg__Pose2D__Sequence pose;
} ros2_interfaces__msg__RobotPose;

// Struct for a sequence of ros2_interfaces__msg__RobotPose.
typedef struct ros2_interfaces__msg__RobotPose__Sequence
{
  ros2_interfaces__msg__RobotPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__msg__RobotPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_INTERFACES__MSG__DETAIL__ROBOT_POSE__STRUCT_H_
