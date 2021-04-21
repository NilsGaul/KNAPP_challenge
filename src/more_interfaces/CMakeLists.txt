cmake_minimum_required(VERSION 3.5)
project(more_interfaces)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(yaml-cpp REQUIRED)

include_directories(HEADERS_EXECUTABLE
    ${YAML_INCLUDE_DIRS}
    #${YAML_CPP_INCLUDEDIR}
)

#target_link_libraries(${CMAKE_PROJECT_NAME}
#    yaml-cpp
#)

add_executable(amr_node
  src/amr_node.cpp
)

ament_target_dependencies(amr_node
  rclcpp geometry_msgs yaml-cpp
)

install(TARGETS 
 amr_node
 DESTINATION lib/${PROJECT_NAME})

set(msg_files
  "msg/Order.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)

rosidl_target_interfaces(amr_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

ament_export_dependencies(rosidl_default_runtime)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()



ament_package()
