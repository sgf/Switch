cmake_minimum_required(VERSION 3.2)

project(Panel)
find_package(Switch REQUIRED)
add_executable(Panel ${SWITCH_GUI} Panel.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(Panel Switch.System.Windows.Forms)
