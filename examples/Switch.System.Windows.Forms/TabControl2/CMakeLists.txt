cmake_minimum_required(VERSION 3.2)

project(TabControl)
find_package(Switch REQUIRED)
add_executable(TabControl2 ${SWITCH_GUI} TabControl2.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(TabControl2 Switch.System.Windows.Forms)
