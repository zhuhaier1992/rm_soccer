// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros2_interfaces:msg/RobotPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros2_interfaces/msg/detail/robot_pose__rosidl_typesupport_introspection_c.h"
#include "ros2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros2_interfaces/msg/detail/robot_pose__functions.h"
#include "ros2_interfaces/msg/detail/robot_pose__struct.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/pose2_d.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose2_d__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RobotPose__rosidl_typesupport_introspection_c__RobotPose_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_interfaces__msg__RobotPose__init(message_memory);
}

void RobotPose__rosidl_typesupport_introspection_c__RobotPose_fini_function(void * message_memory)
{
  ros2_interfaces__msg__RobotPose__fini(message_memory);
}

size_t RobotPose__rosidl_typesupport_introspection_c__size_function__Pose2D__pose(
  const void * untyped_member)
{
  const geometry_msgs__msg__Pose2D__Sequence * member =
    (const geometry_msgs__msg__Pose2D__Sequence *)(untyped_member);
  return member->size;
}

const void * RobotPose__rosidl_typesupport_introspection_c__get_const_function__Pose2D__pose(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Pose2D__Sequence * member =
    (const geometry_msgs__msg__Pose2D__Sequence *)(untyped_member);
  return &member->data[index];
}

void * RobotPose__rosidl_typesupport_introspection_c__get_function__Pose2D__pose(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Pose2D__Sequence * member =
    (geometry_msgs__msg__Pose2D__Sequence *)(untyped_member);
  return &member->data[index];
}

bool RobotPose__rosidl_typesupport_introspection_c__resize_function__Pose2D__pose(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Pose2D__Sequence * member =
    (geometry_msgs__msg__Pose2D__Sequence *)(untyped_member);
  geometry_msgs__msg__Pose2D__Sequence__fini(member);
  return geometry_msgs__msg__Pose2D__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember RobotPose__rosidl_typesupport_introspection_c__RobotPose_message_member_array[1] = {
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_interfaces__msg__RobotPose, pose),  // bytes offset in struct
    NULL,  // default value
    RobotPose__rosidl_typesupport_introspection_c__size_function__Pose2D__pose,  // size() function pointer
    RobotPose__rosidl_typesupport_introspection_c__get_const_function__Pose2D__pose,  // get_const(index) function pointer
    RobotPose__rosidl_typesupport_introspection_c__get_function__Pose2D__pose,  // get(index) function pointer
    RobotPose__rosidl_typesupport_introspection_c__resize_function__Pose2D__pose  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RobotPose__rosidl_typesupport_introspection_c__RobotPose_message_members = {
  "ros2_interfaces__msg",  // message namespace
  "RobotPose",  // message name
  1,  // number of fields
  sizeof(ros2_interfaces__msg__RobotPose),
  RobotPose__rosidl_typesupport_introspection_c__RobotPose_message_member_array,  // message members
  RobotPose__rosidl_typesupport_introspection_c__RobotPose_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotPose__rosidl_typesupport_introspection_c__RobotPose_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RobotPose__rosidl_typesupport_introspection_c__RobotPose_message_type_support_handle = {
  0,
  &RobotPose__rosidl_typesupport_introspection_c__RobotPose_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_interfaces, msg, RobotPose)() {
  RobotPose__rosidl_typesupport_introspection_c__RobotPose_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose2D)();
  if (!RobotPose__rosidl_typesupport_introspection_c__RobotPose_message_type_support_handle.typesupport_identifier) {
    RobotPose__rosidl_typesupport_introspection_c__RobotPose_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RobotPose__rosidl_typesupport_introspection_c__RobotPose_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
