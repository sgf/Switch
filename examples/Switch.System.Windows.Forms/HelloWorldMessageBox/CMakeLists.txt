cmake_minimum_required(VERSION 3.2)

project(HelloWorldMessageBox)
find_package(Switch REQUIRED)
add_executable(HelloWorldMessageBox ${SWITCH_GUI} HelloWorldMessageBox.cpp)
target_link_libraries(HelloWorldMessageBox Switch.System.Windows.Forms)
