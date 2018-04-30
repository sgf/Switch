cmake_minimum_required(VERSION 3.2)

project(MessageBox2)
find_package(Switch REQUIRED)
add_executable(MessageBox2 ${SWITCH_GUI} MessageBox2.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(MessageBox2 Switch.System.Windows.Forms)
