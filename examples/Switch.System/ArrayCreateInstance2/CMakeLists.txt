cmake_minimum_required(VERSION 3.2)

project(ArrayCreateInstance2)
find_package(Switch REQUIRED)
add_executable(ArrayCreateInstance2 ArrayCreateInstance2.cpp)
target_link_libraries(ArrayCreateInstance2 Switch.System)
