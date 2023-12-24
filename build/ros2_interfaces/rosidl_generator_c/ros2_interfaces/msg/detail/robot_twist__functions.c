// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_interfaces:msg/RobotTwist.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/robot_twist__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `twist`
#include "geometry_msgs/msg/detail/twist__functions.h"

bool
ros2_interfaces__msg__RobotTwist__init(ros2_interfaces__msg__RobotTwist * msg)
{
  if (!msg) {
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__Sequence__init(&msg->twist, 0)) {
    ros2_interfaces__msg__RobotTwist__fini(msg);
    return false;
  }
  return true;
}

void
ros2_interfaces__msg__RobotTwist__fini(ros2_interfaces__msg__RobotTwist * msg)
{
  if (!msg) {
    return;
  }
  // twist
  geometry_msgs__msg__Twist__Sequence__fini(&msg->twist);
}

bool
ros2_interfaces__msg__RobotTwist__are_equal(const ros2_interfaces__msg__RobotTwist * lhs, const ros2_interfaces__msg__RobotTwist * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__Sequence__are_equal(
      &(lhs->twist), &(rhs->twist)))
  {
    return false;
  }
  return true;
}

bool
ros2_interfaces__msg__RobotTwist__copy(
  const ros2_interfaces__msg__RobotTwist * input,
  ros2_interfaces__msg__RobotTwist * output)
{
  if (!input || !output) {
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__Sequence__copy(
      &(input->twist), &(output->twist)))
  {
    return false;
  }
  return true;
}

ros2_interfaces__msg__RobotTwist *
ros2_interfaces__msg__RobotTwist__create()
{
  ros2_interfaces__msg__RobotTwist * msg = (ros2_interfaces__msg__RobotTwist *)malloc(sizeof(ros2_interfaces__msg__RobotTwist));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_interfaces__msg__RobotTwist));
  bool success = ros2_interfaces__msg__RobotTwist__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ros2_interfaces__msg__RobotTwist__destroy(ros2_interfaces__msg__RobotTwist * msg)
{
  if (msg) {
    ros2_interfaces__msg__RobotTwist__fini(msg);
  }
  free(msg);
}


bool
ros2_interfaces__msg__RobotTwist__Sequence__init(ros2_interfaces__msg__RobotTwist__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ros2_interfaces__msg__RobotTwist * data = NULL;
  if (size) {
    data = (ros2_interfaces__msg__RobotTwist *)calloc(size, sizeof(ros2_interfaces__msg__RobotTwist));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_interfaces__msg__RobotTwist__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_interfaces__msg__RobotTwist__fini(&data[i - 1]);
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
ros2_interfaces__msg__RobotTwist__Sequence__fini(ros2_interfaces__msg__RobotTwist__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_interfaces__msg__RobotTwist__fini(&array->data[i]);
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

ros2_interfaces__msg__RobotTwist__Sequence *
ros2_interfaces__msg__RobotTwist__Sequence__create(size_t size)
{
  ros2_interfaces__msg__RobotTwist__Sequence * array = (ros2_interfaces__msg__RobotTwist__Sequence *)malloc(sizeof(ros2_interfaces__msg__RobotTwist__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ros2_interfaces__msg__RobotTwist__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ros2_interfaces__msg__RobotTwist__Sequence__destroy(ros2_interfaces__msg__RobotTwist__Sequence * array)
{
  if (array) {
    ros2_interfaces__msg__RobotTwist__Sequence__fini(array);
  }
  free(array);
}

bool
ros2_interfaces__msg__RobotTwist__Sequence__are_equal(const ros2_interfaces__msg__RobotTwist__Sequence * lhs, const ros2_interfaces__msg__RobotTwist__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_interfaces__msg__RobotTwist__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_interfaces__msg__RobotTwist__Sequence__copy(
  const ros2_interfaces__msg__RobotTwist__Sequence * input,
  ros2_interfaces__msg__RobotTwist__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_interfaces__msg__RobotTwist);
    ros2_interfaces__msg__RobotTwist * data =
      (ros2_interfaces__msg__RobotTwist *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_interfaces__msg__RobotTwist__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ros2_interfaces__msg__RobotTwist__fini(&data[i]);
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
    if (!ros2_interfaces__msg__RobotTwist__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
