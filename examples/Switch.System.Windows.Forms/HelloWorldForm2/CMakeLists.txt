cmake_minimum_required(VERSION 3.2)

project(HelloWorldForm2)
find_package(Switch REQUIRED)
add_executable(HelloWorldForm2 ${SWITCH_GUI} HelloWorldForm2.cpp)
target_link_libraries(HelloWorldForm2 Switch.System.Windows.Forms)
