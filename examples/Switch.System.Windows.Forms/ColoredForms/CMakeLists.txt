cmake_minimum_required(VERSION 3.2)

project(ColoredForms)
find_package(Switch REQUIRED)
add_executable(ColoredForms ${SWITCH_GUI} ColoredForms.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(ColoredForms Switch.System.Windows.Forms)
