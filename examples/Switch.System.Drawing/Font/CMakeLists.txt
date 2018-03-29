cmake_minimum_required(VERSION 3.2)

project(Font)
find_package(Switch REQUIRED)
add_executable(Font Font.cpp)
target_link_libraries(Font Switch.System.Drawing)
