cmake_minimum_required(VERSION 3.26)
project(VehicleSoftwareDesign)

set(CMAKE_CXX_STANDARD 14)

add_executable(VehicleSoftwareDesign
        car_management.cpp
)

add_executable(lidar_chassis lidar_chassis.cpp)
add_executable(car_management_class car_management_class.cpp)