// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:srv/Control.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "ros2_interfaces/msg/rosidl_typesupport_c__visibility_control.h"
#include "ros2_interfaces/srv/detail/control__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Control_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Control_Request_type_support_ids_t;

static const _Control_Request_type_support_ids_t _Control_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Control_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Control_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Control_Request_type_support_symbol_names_t _Control_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, Control_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_interfaces, srv, Control_Request)),
  }
};

typedef struct _Control_Request_type_support_data_t
{
  void * data[2];
} _Control_Request_type_support_data_t;

static _Control_Request_type_support_data_t _Control_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Control_Request_message_typesupport_map = {
  2,
  "ros2_interfaces",
  &_Control_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Control_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Control_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Control_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Control_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace ros2_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ros2_interfaces, srv, Control_Request)() {
  return &::ros2_interfaces::srv::rosidl_typesupport_c::Control_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ros2_interfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "ros2_interfaces/srv/detail/control__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Control_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Control_Response_type_support_ids_t;

static const _Control_Response_type_support_ids_t _Control_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Control_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Control_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Control_Response_type_support_symbol_names_t _Control_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, Control_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_interfaces, srv, Control_Response)),
  }
};

typedef struct _Control_Response_type_support_data_t
{
  void * data[2];
} _Control_Response_type_support_data_t;

static _Control_Response_type_support_data_t _Control_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Control_Response_message_typesupport_map = {
  2,
  "ros2_interfaces",
  &_Control_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Control_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Control_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Control_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Control_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace ros2_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ros2_interfaces, srv, Control_Response)() {
  return &::ros2_interfaces::srv::rosidl_typesupport_c::Control_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ros2_interfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ros2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Control_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Control_type_support_ids_t;

static const _Control_type_support_ids_t _Control_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Control_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Control_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Control_type_support_symbol_names_t _Control_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_interfaces, srv, Control)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_interfaces, srv, Control)),
  }
};

typedef struct _Control_type_support_data_t
{
  void * data[2];
} _Control_type_support_data_t;

static _Control_type_support_data_t _Control_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Control_service_typesupport_map = {
  2,
  "ros2_interfaces",
  &_Control_service_typesupport_ids.typesupport_identifier[0],
  &_Control_service_typesupport_symbol_names.symbol_name[0],
  &_Control_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Control_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Control_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace ros2_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_ros2_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, ros2_interfaces, srv, Control)() {
  return &::ros2_interfaces::srv::rosidl_typesupport_c::Control_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
