#pragma once
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/msg/pose.hpp>

namespace moveit_myarms
{
    class RobotController
    {
        public:
        RobotController(std::shared_ptr<rclcpp::Node> node);

        bool planToPose(geometry_msgs::msg::Pose target_pose);

        private:
        rclcpp::Node::SharedPtr node_;
        std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
    };
}