cmake_minimum_required(VERSION 3.2)

project(MessageBox3)
find_package(Switch REQUIRED)
add_executable(MessageBox3 ${SWITCH_GUI} MessageBox3.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(MessageBox3 Switch.System.Windows.Forms)
