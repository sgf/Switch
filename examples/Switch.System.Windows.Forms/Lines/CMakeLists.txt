cmake_minimum_required(VERSION 3.2)

project(Lines)
find_package(Switch REQUIRED)
add_executable(Lines ${SWITCH_GUI} Lines.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(Lines Switch.System.Windows.Forms)
