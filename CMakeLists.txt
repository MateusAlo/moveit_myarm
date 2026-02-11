cmake_minimum_required(VERSION 3.8)
project(moveit_myarm)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(simple_mover src/simple_mover.cpp)

# target_include_directories(simple_mover PUBLIC
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include>
# )


ament_target_dependencies(simple_mover
  rclcpp
  tf2_geometry_msgs
  moveit_ros_planning_interface
  geometry_msgs
)

install(TARGETS simple_mover
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()