// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros2_interfaces:srv/Control.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/srv/detail/control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_interfaces/srv/detail/control__struct.h"
#include "ros2_interfaces/srv/detail/control__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Control_Request__ros_msg_type = ros2_interfaces__srv__Control_Request;

static bool _Control_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Control_Request__ros_msg_type * ros_message = static_cast<const _Control_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: status
  {
    cdr << ros_message->status;
  }

  return true;
}

static bool _Control_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Control_Request__ros_msg_type * ros_message = static_cast<_Control_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr >> ros_message->id;
  }

  // Field name: status
  {
    cdr >> ros_message->status;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t get_serialized_size_ros2_interfaces__srv__Control_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Control_Request__ros_msg_type * ros_message = static_cast<const _Control_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name id
  {
    size_t item_size = sizeof(ros_message->id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Control_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_interfaces__srv__Control_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t max_serialized_size_ros2_interfaces__srv__Control_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Control_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ros2_interfaces__srv__Control_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Control_Request = {
  "ros2_interfaces::srv",
  "Control_Request",
  _Control_Request__cdr_serialize,
  _Control_Request__cdr_deserialize,
  _Control_Request__get_serialized_size,
  _Control_Request__max_serialized_size
};

static rosidl_message_type_support_t _Control_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Control_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, Control_Request)() {
  return &_Control_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ros2_interfaces/srv/detail/control__struct.h"
// already included above
// #include "ros2_interfaces/srv/detail/control__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/pose2_d__functions.h"  // pose

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
size_t get_serialized_size_geometry_msgs__msg__Pose2D(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
size_t max_serialized_size_geometry_msgs__msg__Pose2D(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros2_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose2D)();


using _Control_Response__ros_msg_type = ros2_interfaces__srv__Control_Response;

static bool _Control_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Control_Response__ros_msg_type * ros_message = static_cast<const _Control_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr << ros_message->status;
  }

  // Field name: action
  {
    cdr << ros_message->action;
  }

  // Field name: pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose2D
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->pose, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Control_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Control_Response__ros_msg_type * ros_message = static_cast<_Control_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr >> ros_message->status;
  }

  // Field name: action
  {
    cdr >> ros_message->action;
  }

  // Field name: pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose2D
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->pose))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t get_serialized_size_ros2_interfaces__srv__Control_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Control_Response__ros_msg_type * ros_message = static_cast<const _Control_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name action
  {
    size_t item_size = sizeof(ros_message->action);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pose

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose2D(
    &(ros_message->pose), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Control_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_interfaces__srv__Control_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_interfaces
size_t max_serialized_size_ros2_interfaces__srv__Control_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: action
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pose
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Pose2D(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Control_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ros2_interfaces__srv__Control_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Control_Response = {
  "ros2_interfaces::srv",
  "Control_Response",
  _Control_Response__cdr_serialize,
  _Control_Response__cdr_deserialize,
  _Control_Response__get_serialized_size,
  _Control_Response__max_serialized_size
};

static rosidl_message_type_support_t _Control_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Control_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, Control_Response)() {
  return &_Control_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_interfaces/srv/control.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Control__callbacks = {
  "ros2_interfaces::srv",
  "Control",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, Control_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, Control_Response)(),
};

static rosidl_service_type_support_t Control__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Control__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, Control)() {
  return &Control__handle;
}

#if defined(__cplusplus)
}
#endif
