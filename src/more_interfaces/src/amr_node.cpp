#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "more_interfaces/msg/order.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class RobotNode : public rclcpp::Node
{
public:
  RobotNode()
  : Node("OrderOptimizer")
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
    500ms, std::bind(&RobotNode::timer_callback, this));

    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&RobotNode::topic_callback, this, _1));

    //Task 2
    subscription_current_position = this->create_subscription<geometry_msgs::msg::PoseStamped>(
      "currentPosition", 10, std::bind(&RobotNode::currentPosition_callback, this, _1));

    subscription_next_order = this->create_subscription<more_interfaces::msg::Order>(
      "nextOrder", 10, std::bind(&RobotNode::nextOrder_callback, this, _1));

    //Task 3
    this->declare_parameter<std::string>("path_parameter", "/home/nils/knapp_ws/src/files");
      timer_path_param = this->create_wall_timer(
      1000ms, std::bind(&RobotNode::respond, this));

  }

   void respond()
    {
      this->get_parameter("path_parameter", path_param);
      RCLCPP_INFO(this->get_logger(), "Current path:  %s", path_param.c_str());
    }

private:
  void timer_callback()
  {
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;

  std::string path_param;
  rclcpp::TimerBase::SharedPtr timer_path_param;


  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
  }


  void currentPosition_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "I heard at currentPosition_callback: '%s' !", msg->header.frame_id);
  }

  void nextOrder_callback(const more_interfaces::msg::Order::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "I heard at nextOrder_callback: '%s' !", msg->description);
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr subscription_current_position;
  rclcpp::Subscription<more_interfaces::msg::Order>::SharedPtr subscription_next_order;


  
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RobotNode>());
  rclcpp::shutdown();

  return 0;
}
