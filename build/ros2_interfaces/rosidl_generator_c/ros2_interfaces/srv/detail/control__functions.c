// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_interfaces:srv/Control.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/srv/detail/control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
ros2_interfaces__srv__Control_Request__init(ros2_interfaces__srv__Control_Request * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // status
  return true;
}

void
ros2_interfaces__srv__Control_Request__fini(ros2_interfaces__srv__Control_Request * msg)
{
  if (!msg) {
    return;
  }
  // id
  // status
}

bool
ros2_interfaces__srv__Control_Request__are_equal(const ros2_interfaces__srv__Control_Request * lhs, const ros2_interfaces__srv__Control_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  return true;
}

bool
ros2_interfaces__srv__Control_Request__copy(
  const ros2_interfaces__srv__Control_Request * input,
  ros2_interfaces__srv__Control_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // status
  output->status = input->status;
  return true;
}

ros2_interfaces__srv__Control_Request *
ros2_interfaces__srv__Control_Request__create()
{
  ros2_interfaces__srv__Control_Request * msg = (ros2_interfaces__srv__Control_Request *)malloc(sizeof(ros2_interfaces__srv__Control_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_interfaces__srv__Control_Request));
  bool success = ros2_interfaces__srv__Control_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ros2_interfaces__srv__Control_Request__destroy(ros2_interfaces__srv__Control_Request * msg)
{
  if (msg) {
    ros2_interfaces__srv__Control_Request__fini(msg);
  }
  free(msg);
}


bool
ros2_interfaces__srv__Control_Request__Sequence__init(ros2_interfaces__srv__Control_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ros2_interfaces__srv__Control_Request * data = NULL;
  if (size) {
    data = (ros2_interfaces__srv__Control_Request *)calloc(size, sizeof(ros2_interfaces__srv__Control_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_interfaces__srv__Control_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_interfaces__srv__Control_Request__fini(&data[i - 1]);
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
ros2_interfaces__srv__Control_Request__Sequence__fini(ros2_interfaces__srv__Control_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_interfaces__srv__Control_Request__fini(&array->data[i]);
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

ros2_interfaces__srv__Control_Request__Sequence *
ros2_interfaces__srv__Control_Request__Sequence__create(size_t size)
{
  ros2_interfaces__srv__Control_Request__Sequence * array = (ros2_interfaces__srv__Control_Request__Sequence *)malloc(sizeof(ros2_interfaces__srv__Control_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ros2_interfaces__srv__Control_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ros2_interfaces__srv__Control_Request__Sequence__destroy(ros2_interfaces__srv__Control_Request__Sequence * array)
{
  if (array) {
    ros2_interfaces__srv__Control_Request__Sequence__fini(array);
  }
  free(array);
}

bool
ros2_interfaces__srv__Control_Request__Sequence__are_equal(const ros2_interfaces__srv__Control_Request__Sequence * lhs, const ros2_interfaces__srv__Control_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_interfaces__srv__Control_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_interfaces__srv__Control_Request__Sequence__copy(
  const ros2_interfaces__srv__Control_Request__Sequence * input,
  ros2_interfaces__srv__Control_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_interfaces__srv__Control_Request);
    ros2_interfaces__srv__Control_Request * data =
      (ros2_interfaces__srv__Control_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_interfaces__srv__Control_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ros2_interfaces__srv__Control_Request__fini(&data[i]);
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
    if (!ros2_interfaces__srv__Control_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose2_d__functions.h"

bool
ros2_interfaces__srv__Control_Response__init(ros2_interfaces__srv__Control_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // action
  // pose
  if (!geometry_msgs__msg__Pose2D__init(&msg->pose)) {
    ros2_interfaces__srv__Control_Response__fini(msg);
    return false;
  }
  return true;
}

void
ros2_interfaces__srv__Control_Response__fini(ros2_interfaces__srv__Control_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // action
  // pose
  geometry_msgs__msg__Pose2D__fini(&msg->pose);
}

bool
ros2_interfaces__srv__Control_Response__are_equal(const ros2_interfaces__srv__Control_Response * lhs, const ros2_interfaces__srv__Control_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // action
  if (lhs->action != rhs->action) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose2D__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
ros2_interfaces__srv__Control_Response__copy(
  const ros2_interfaces__srv__Control_Response * input,
  ros2_interfaces__srv__Control_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // action
  output->action = input->action;
  // pose
  if (!geometry_msgs__msg__Pose2D__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

ros2_interfaces__srv__Control_Response *
ros2_interfaces__srv__Control_Response__create()
{
  ros2_interfaces__srv__Control_Response * msg = (ros2_interfaces__srv__Control_Response *)malloc(sizeof(ros2_interfaces__srv__Control_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_interfaces__srv__Control_Response));
  bool success = ros2_interfaces__srv__Control_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ros2_interfaces__srv__Control_Response__destroy(ros2_interfaces__srv__Control_Response * msg)
{
  if (msg) {
    ros2_interfaces__srv__Control_Response__fini(msg);
  }
  free(msg);
}


bool
ros2_interfaces__srv__Control_Response__Sequence__init(ros2_interfaces__srv__Control_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ros2_interfaces__srv__Control_Response * data = NULL;
  if (size) {
    data = (ros2_interfaces__srv__Control_Response *)calloc(size, sizeof(ros2_interfaces__srv__Control_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_interfaces__srv__Control_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_interfaces__srv__Control_Response__fini(&data[i - 1]);
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
ros2_interfaces__srv__Control_Response__Sequence__fini(ros2_interfaces__srv__Control_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_interfaces__srv__Control_Response__fini(&array->data[i]);
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

ros2_interfaces__srv__Control_Response__Sequence *
ros2_interfaces__srv__Control_Response__Sequence__create(size_t size)
{
  ros2_interfaces__srv__Control_Response__Sequence * array = (ros2_interfaces__srv__Control_Response__Sequence *)malloc(sizeof(ros2_interfaces__srv__Control_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ros2_interfaces__srv__Control_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ros2_interfaces__srv__Control_Response__Sequence__destroy(ros2_interfaces__srv__Control_Response__Sequence * array)
{
  if (array) {
    ros2_interfaces__srv__Control_Response__Sequence__fini(array);
  }
  free(array);
}

bool
ros2_interfaces__srv__Control_Response__Sequence__are_equal(const ros2_interfaces__srv__Control_Response__Sequence * lhs, const ros2_interfaces__srv__Control_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_interfaces__srv__Control_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_interfaces__srv__Control_Response__Sequence__copy(
  const ros2_interfaces__srv__Control_Response__Sequence * input,
  ros2_interfaces__srv__Control_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_interfaces__srv__Control_Response);
    ros2_interfaces__srv__Control_Response * data =
      (ros2_interfaces__srv__Control_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_interfaces__srv__Control_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ros2_interfaces__srv__Control_Response__fini(&data[i]);
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
    if (!ros2_interfaces__srv__Control_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
