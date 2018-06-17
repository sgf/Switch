cmake_minimum_required(VERSION 3.2)

project(MessageBox1)
find_package(Switch REQUIRED)
add_executable(MessageBox1 ${SWITCH_GUI} MessageBox1.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(MessageBox1 Switch.System.Windows.Forms)
