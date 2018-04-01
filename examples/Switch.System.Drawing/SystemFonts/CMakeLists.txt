cmake_minimum_required(VERSION 3.2)

project(SystemFonts)
find_package(Switch REQUIRED)
add_executable(SystemFonts SystemFonts.cpp)
target_link_libraries(SystemFonts Switch.System.Drawing)
