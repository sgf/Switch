cmake_minimum_required(VERSION 3.2)

project(Abstract)
find_package(Switch REQUIRED)
add_executable(Abstract Abstract.cpp)
target_link_libraries(Abstract Switch.System)
