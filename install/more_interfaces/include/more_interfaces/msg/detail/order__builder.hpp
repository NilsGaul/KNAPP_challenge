// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from more_interfaces:msg/Order.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__ORDER__BUILDER_HPP_
#define MORE_INTERFACES__MSG__DETAIL__ORDER__BUILDER_HPP_

#include "more_interfaces/msg/detail/order__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace more_interfaces
{

namespace msg
{

namespace builder
{

class Init_Order_description
{
public:
  explicit Init_Order_description(::more_interfaces::msg::Order & msg)
  : msg_(msg)
  {}
  ::more_interfaces::msg::Order description(::more_interfaces::msg::Order::_description_type arg)
  {
    msg_.description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::more_interfaces::msg::Order msg_;
};

class Init_Order_order_id
{
public:
  Init_Order_order_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Order_description order_id(::more_interfaces::msg::Order::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return Init_Order_description(msg_);
  }

private:
  ::more_interfaces::msg::Order msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::msg::Order>()
{
  return more_interfaces::msg::builder::Init_Order_order_id();
}

}  // namespace more_interfaces

#endif  // MORE_INTERFACES__MSG__DETAIL__ORDER__BUILDER_HPP_
