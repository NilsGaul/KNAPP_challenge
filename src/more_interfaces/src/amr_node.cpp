#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "more_interfaces/msg/order.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include <iostream>
#include <vector>
#include <dirent.h>
#include <fstream>

#include <yaml-cpp/yaml.h>

using namespace std::chrono_literals;
using std::placeholders::_1;

std::vector<char *> extract_files(const char * path){
  DIR *dir; struct dirent *diread;
  std::vector<char *> files;

  if ((dir = opendir(path)) != nullptr) {
      while ((diread = readdir(dir)) != nullptr) {
          files.push_back(diread->d_name);
      }
      closedir (dir);
  } else {
      perror ("opendir");
  }
  return files;
}


//Task 1
class RobotNode : public rclcpp::Node
{
public:
  RobotNode()
  : Node("OrderOptimizer")
  {
    /*
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
    1000ms, std::bind(&RobotNode::timer_callback, this));
    */


    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&RobotNode::topic_callback, this, _1));
    

    //Task 2
    subscription_current_position = this->create_subscription<geometry_msgs::msg::PoseStamped>(
      "currentPosition", 10, std::bind(&RobotNode::currentPosition_callback, this, _1));

    //Using custom message type "more_interfaces::msg::Order"
    subscription_next_order = this->create_subscription<more_interfaces::msg::Order>(
      "nextOrder", 10, std::bind(&RobotNode::nextOrder_callback, this, _1));

    //Task 3
    this->declare_parameter<std::string>("path_parameter", "/home/nils/knapp_ws/src/files/orders");
    timer_path_param = this->create_wall_timer(
      10000ms, std::bind(&RobotNode::respond, this));

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
    RCLCPP_INFO(this->get_logger(), "nextOrder_callback: id: '%i', description: '%s' !", msg->order_id, msg->description.c_str());

    //Task 5
    //Iterate through all files in 'orders' folder
    std::vector<char *> files = extract_files(path_param.c_str());

    for (auto file : files){
      std::cout << file << "| ";
      std::cout << std::endl;

      //Check for information related to given order

      //auto doc = YAML::LoadFile(std::string(file));
      /*
      std::string text_line;
      std::ifstream current_file(file);
      
      
      while (getline (current_file, text_line)) {
      // Output the text from the file
      std::cout << text_line;
      }
      
      current_file.close();
      */
    } 
  
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
