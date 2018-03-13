cmake_minimum_required(VERSION 3.2)

project(WndProc)
find_package(Switch REQUIRED)
add_executable(WndProc ${SWITCH_GUI} WndProc.cpp)
target_link_libraries(WndProc Switch.System.Windows.Forms)
