cmake_minimum_required(VERSION 3.2)

project(TabControl)
find_package(Switch REQUIRED)
add_executable(TabControl ${SWITCH_GUI} TabControl.cpp)
target_link_libraries(TabControl Switch.System.Windows.Forms)
