#include <moveit_myarm/robot_controller.hpp>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/msg/pose.hpp>

namespace moveit_myarms
{
    RobotController::RobotController(rclcpp::Node::SharedPtr node) : node_(node)
    {
        move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(node_, "ur_manipulator");
    }
    bool RobotController::planToPose(geometry_msgs::msg::Pose target_pose)
    {
        move_group_->setPoseTarget(target_pose);
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        auto const success = static_cast<bool>(move_group_->plan(plan));
        if(success) {
            move_group_->execute(plan);
        } 
        else {
            RCLCPP_ERROR(node_->get_logger(), "Planning failed!");
        }
        return success;
    }
};