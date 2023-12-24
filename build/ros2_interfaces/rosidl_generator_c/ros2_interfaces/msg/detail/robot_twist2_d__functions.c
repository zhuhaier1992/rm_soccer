// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_interfaces:msg/RobotTwist2D.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/robot_twist2_d__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `twist`
#include "geometry_msgs/msg/detail/pose2_d__functions.h"

bool
ros2_interfaces__msg__RobotTwist2D__init(ros2_interfaces__msg__RobotTwist2D * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ros2_interfaces__msg__RobotTwist2D__fini(msg);
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Pose2D__Sequence__init(&msg->twist, 0)) {
    ros2_interfaces__msg__RobotTwist2D__fini(msg);
    return false;
  }
  return true;
}

void
ros2_interfaces__msg__RobotTwist2D__fini(ros2_interfaces__msg__RobotTwist2D * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // twist
  geometry_msgs__msg__Pose2D__Sequence__fini(&msg->twist);
}

bool
ros2_interfaces__msg__RobotTwist2D__are_equal(const ros2_interfaces__msg__RobotTwist2D * lhs, const ros2_interfaces__msg__RobotTwist2D * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Pose2D__Sequence__are_equal(
      &(lhs->twist), &(rhs->twist)))
  {
    return false;
  }
  return true;
}

bool
ros2_interfaces__msg__RobotTwist2D__copy(
  const ros2_interfaces__msg__RobotTwist2D * input,
  ros2_interfaces__msg__RobotTwist2D * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Pose2D__Sequence__copy(
      &(input->twist), &(output->twist)))
  {
    return false;
  }
  return true;
}

ros2_interfaces__msg__RobotTwist2D *
ros2_interfaces__msg__RobotTwist2D__create()
{
  ros2_interfaces__msg__RobotTwist2D * msg = (ros2_interfaces__msg__RobotTwist2D *)malloc(sizeof(ros2_interfaces__msg__RobotTwist2D));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_interfaces__msg__RobotTwist2D));
  bool success = ros2_interfaces__msg__RobotTwist2D__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ros2_interfaces__msg__RobotTwist2D__destroy(ros2_interfaces__msg__RobotTwist2D * msg)
{
  if (msg) {
    ros2_interfaces__msg__RobotTwist2D__fini(msg);
  }
  free(msg);
}


bool
ros2_interfaces__msg__RobotTwist2D__Sequence__init(ros2_interfaces__msg__RobotTwist2D__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ros2_interfaces__msg__RobotTwist2D * data = NULL;
  if (size) {
    data = (ros2_interfaces__msg__RobotTwist2D *)calloc(size, sizeof(ros2_interfaces__msg__RobotTwist2D));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_interfaces__msg__RobotTwist2D__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_interfaces__msg__RobotTwist2D__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros2_interfaces__msg__RobotTwist2D__Sequence__fini(ros2_interfaces__msg__RobotTwist2D__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_interfaces__msg__RobotTwist2D__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros2_interfaces__msg__RobotTwist2D__Sequence *
ros2_interfaces__msg__RobotTwist2D__Sequence__create(size_t size)
{
  ros2_interfaces__msg__RobotTwist2D__Sequence * array = (ros2_interfaces__msg__RobotTwist2D__Sequence *)malloc(sizeof(ros2_interfaces__msg__RobotTwist2D__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ros2_interfaces__msg__RobotTwist2D__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ros2_interfaces__msg__RobotTwist2D__Sequence__destroy(ros2_interfaces__msg__RobotTwist2D__Sequence * array)
{
  if (array) {
    ros2_interfaces__msg__RobotTwist2D__Sequence__fini(array);
  }
  free(array);
}

bool
ros2_interfaces__msg__RobotTwist2D__Sequence__are_equal(const ros2_interfaces__msg__RobotTwist2D__Sequence * lhs, const ros2_interfaces__msg__RobotTwist2D__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_interfaces__msg__RobotTwist2D__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_interfaces__msg__RobotTwist2D__Sequence__copy(
  const ros2_interfaces__msg__RobotTwist2D__Sequence * input,
  ros2_interfaces__msg__RobotTwist2D__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_interfaces__msg__RobotTwist2D);
    ros2_interfaces__msg__RobotTwist2D * data =
      (ros2_interfaces__msg__RobotTwist2D *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_interfaces__msg__RobotTwist2D__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ros2_interfaces__msg__RobotTwist2D__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_interfaces__msg__RobotTwist2D__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
