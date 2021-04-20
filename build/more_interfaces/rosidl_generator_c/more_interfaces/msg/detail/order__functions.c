// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from more_interfaces:msg/Order.idl
// generated code does not contain a copyright notice
#include "more_interfaces/msg/detail/order__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `description`
#include "rosidl_runtime_c/string_functions.h"

bool
more_interfaces__msg__Order__init(more_interfaces__msg__Order * msg)
{
  if (!msg) {
    return false;
  }
  // order_id
  // description
  if (!rosidl_runtime_c__String__init(&msg->description)) {
    more_interfaces__msg__Order__fini(msg);
    return false;
  }
  return true;
}

void
more_interfaces__msg__Order__fini(more_interfaces__msg__Order * msg)
{
  if (!msg) {
    return;
  }
  // order_id
  // description
  rosidl_runtime_c__String__fini(&msg->description);
}

more_interfaces__msg__Order *
more_interfaces__msg__Order__create()
{
  more_interfaces__msg__Order * msg = (more_interfaces__msg__Order *)malloc(sizeof(more_interfaces__msg__Order));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(more_interfaces__msg__Order));
  bool success = more_interfaces__msg__Order__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
more_interfaces__msg__Order__destroy(more_interfaces__msg__Order * msg)
{
  if (msg) {
    more_interfaces__msg__Order__fini(msg);
  }
  free(msg);
}


bool
more_interfaces__msg__Order__Sequence__init(more_interfaces__msg__Order__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  more_interfaces__msg__Order * data = NULL;
  if (size) {
    data = (more_interfaces__msg__Order *)calloc(size, sizeof(more_interfaces__msg__Order));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = more_interfaces__msg__Order__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        more_interfaces__msg__Order__fini(&data[i - 1]);
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
more_interfaces__msg__Order__Sequence__fini(more_interfaces__msg__Order__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      more_interfaces__msg__Order__fini(&array->data[i]);
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

more_interfaces__msg__Order__Sequence *
more_interfaces__msg__Order__Sequence__create(size_t size)
{
  more_interfaces__msg__Order__Sequence * array = (more_interfaces__msg__Order__Sequence *)malloc(sizeof(more_interfaces__msg__Order__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = more_interfaces__msg__Order__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
more_interfaces__msg__Order__Sequence__destroy(more_interfaces__msg__Order__Sequence * array)
{
  if (array) {
    more_interfaces__msg__Order__Sequence__fini(array);
  }
  free(array);
}
