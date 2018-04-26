cmake_minimum_required(VERSION 3.2)

project(FormWithAssemblyInfo)
find_package(Switch REQUIRED)
add_executable(FormWithAssemblyInfo ${SWITCH_GUI} Form.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(FormWithAssemblyInfo Switch.System.Windows.Forms)
