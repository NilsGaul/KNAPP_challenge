// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from more_interfaces:msg/Order.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__ORDER__FUNCTIONS_H_
#define MORE_INTERFACES__MSG__DETAIL__ORDER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "more_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "more_interfaces/msg/detail/order__struct.h"

/// Initialize msg/Order message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * more_interfaces__msg__Order
 * )) before or use
 * more_interfaces__msg__Order__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
bool
more_interfaces__msg__Order__init(more_interfaces__msg__Order * msg);

/// Finalize msg/Order message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
void
more_interfaces__msg__Order__fini(more_interfaces__msg__Order * msg);

/// Create msg/Order message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * more_interfaces__msg__Order__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
more_interfaces__msg__Order *
more_interfaces__msg__Order__create();

/// Destroy msg/Order message.
/**
 * It calls
 * more_interfaces__msg__Order__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
void
more_interfaces__msg__Order__destroy(more_interfaces__msg__Order * msg);


/// Initialize array of msg/Order messages.
/**
 * It allocates the memory for the number of elements and calls
 * more_interfaces__msg__Order__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
bool
more_interfaces__msg__Order__Sequence__init(more_interfaces__msg__Order__Sequence * array, size_t size);

/// Finalize array of msg/Order messages.
/**
 * It calls
 * more_interfaces__msg__Order__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
void
more_interfaces__msg__Order__Sequence__fini(more_interfaces__msg__Order__Sequence * array);

/// Create array of msg/Order messages.
/**
 * It allocates the memory for the array and calls
 * more_interfaces__msg__Order__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
more_interfaces__msg__Order__Sequence *
more_interfaces__msg__Order__Sequence__create(size_t size);

/// Destroy array of msg/Order messages.
/**
 * It calls
 * more_interfaces__msg__Order__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
void
more_interfaces__msg__Order__Sequence__destroy(more_interfaces__msg__Order__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // MORE_INTERFACES__MSG__DETAIL__ORDER__FUNCTIONS_H_
