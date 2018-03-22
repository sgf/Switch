cmake_minimum_required(VERSION 3.2)

project(Label)
find_package(Switch REQUIRED)
add_executable(Label ${SWITCH_GUI} Label.cpp)
target_link_libraries(Label Switch.System.Windows.Forms)
