// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_interfaces:srv/Control.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__CONTROL__STRUCT_H_
#define ROS2_INTERFACES__SRV__DETAIL__CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/Control in the package ros2_interfaces.
typedef struct ros2_interfaces__srv__Control_Request
{
  int32_t id;
  int32_t status;
} ros2_interfaces__srv__Control_Request;

// Struct for a sequence of ros2_interfaces__srv__Control_Request.
typedef struct ros2_interfaces__srv__Control_Request__Sequence
{
  ros2_interfaces__srv__Control_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__srv__Control_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__struct.h"

// Struct defined in srv/Control in the package ros2_interfaces.
typedef struct ros2_interfaces__srv__Control_Response
{
  int32_t status;
  int32_t action;
  geometry_msgs__msg__Pose2D pose;
} ros2_interfaces__srv__Control_Response;

// Struct for a sequence of ros2_interfaces__srv__Control_Response.
typedef struct ros2_interfaces__srv__Control_Response__Sequence
{
  ros2_interfaces__srv__Control_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interfaces__srv__Control_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_INTERFACES__SRV__DETAIL__CONTROL__STRUCT_H_
