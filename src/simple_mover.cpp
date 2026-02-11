#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/msg/pose.hpp>


int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("simple_mover");
    RCLCPP_INFO(node->get_logger(), "My log message %d", 4);
    rclcpp::shutdown();
    return 0;
}