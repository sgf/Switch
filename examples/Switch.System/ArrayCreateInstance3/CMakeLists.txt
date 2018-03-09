cmake_minimum_required(VERSION 3.2)

project(ArrayCreateInstance3)
find_package(Switch REQUIRED)
add_executable(ArrayCreateInstance3 ArrayCreateInstance3.cpp)
target_link_libraries(ArrayCreateInstance3 Switch.System)
