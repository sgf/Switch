cmake_minimum_required(VERSION 3.2)

project(ApplicationEnableVisualSyle)
find_package(Switch REQUIRED)
add_executable(ApplicationEnableVisualSyle ${SWITCH_GUI} ApplicationEnableVisualSyle.cpp)
target_link_libraries(ApplicationEnableVisualSyle Switch.System.Windows.Forms)
