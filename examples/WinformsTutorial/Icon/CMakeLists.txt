cmake_minimum_required(VERSION 3.2)

project(Icon)
find_package(Switch REQUIRED)
add_executable(Icon ${SWITCH_GUI} Icon.cpp)
target_link_libraries(Icon Switch.System.Windows.Forms)
