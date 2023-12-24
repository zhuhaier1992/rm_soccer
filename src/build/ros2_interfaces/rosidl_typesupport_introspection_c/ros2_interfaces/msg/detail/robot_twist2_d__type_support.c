// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros2_interfaces:msg/RobotTwist2D.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros2_interfaces/msg/detail/robot_twist2_d__rosidl_typesupport_introspection_c.h"
#include "ros2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros2_interfaces/msg/detail/robot_twist2_d__functions.h"
#include "ros2_interfaces/msg/detail/robot_twist2_d__struct.h"


// Include directives for member types
// Member `twist`
#include "geometry_msgs/msg/vector3.h"
// Member `twist`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_interfaces__msg__RobotTwist2D__init(message_memory);
}

void RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_fini_function(void * message_memory)
{
  ros2_interfaces__msg__RobotTwist2D__fini(message_memory);
}

size_t RobotTwist2D__rosidl_typesupport_introspection_c__size_function__Vector3__twist(
  const void * untyped_member)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return member->size;
}

const void * RobotTwist2D__rosidl_typesupport_introspection_c__get_const_function__Vector3__twist(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

void * RobotTwist2D__rosidl_typesupport_introspection_c__get_function__Vector3__twist(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

bool RobotTwist2D__rosidl_typesupport_introspection_c__resize_function__Vector3__twist(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  geometry_msgs__msg__Vector3__Sequence__fini(member);
  return geometry_msgs__msg__Vector3__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_message_member_array[1] = {
  {
    "twist",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__RobotTwist2D, twist),  // bytes offset in struct
    NULL,  // default value
    RobotTwist2D__rosidl_typesupport_introspection_c__size_function__Vector3__twist,  // size() function pointer
    RobotTwist2D__rosidl_typesupport_introspection_c__get_const_function__Vector3__twist,  // get_const(index) function pointer
    RobotTwist2D__rosidl_typesupport_introspection_c__get_function__Vector3__twist,  // get(index) function pointer
    RobotTwist2D__rosidl_typesupport_introspection_c__resize_function__Vector3__twist  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_message_members = {
  "ros2_interfaces__msg",  // message namespace
  "RobotTwist2D",  // message name
  1,  // number of fields
  sizeof(ros2_interfaces__msg__RobotTwist2D),
  RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_message_member_array,  // message members
  RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_message_type_support_handle = {
  0,
  &RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_interfaces, msg, RobotTwist2D)() {
  RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_message_type_support_handle.typesupport_identifier) {
    RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RobotTwist2D__rosidl_typesupport_introspection_c__RobotTwist2D_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
