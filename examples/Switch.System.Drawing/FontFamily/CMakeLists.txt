cmake_minimum_required(VERSION 3.2)

project(FontFamily)
find_package(Switch REQUIRED)
add_executable(FontFamily FontFamily.cpp)
target_link_libraries(FontFamily Switch.System.Drawing)
