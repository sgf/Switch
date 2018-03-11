cmake_minimum_required(VERSION 3.2)

project(Simple)
find_package(Switch REQUIRED)
add_executable(Simple ${SWITCH_GUI} Simple.cpp)
target_link_libraries(Simple Switch.System.Windows.Forms)
