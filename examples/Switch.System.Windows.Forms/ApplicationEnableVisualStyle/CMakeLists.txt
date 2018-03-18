cmake_minimum_required(VERSION 3.2)

project(ApplicationEnableVisualStyle)
find_package(Switch REQUIRED)
add_executable(ApplicationEnableVisualStyle ${SWITCH_GUI} ApplicationEnableVisualStyle.cpp)
target_link_libraries(ApplicationEnableVisualStyle Switch.System.Windows.Forms)
