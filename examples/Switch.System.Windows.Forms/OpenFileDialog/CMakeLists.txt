cmake_minimum_required(VERSION 3.2)

project(OpenFileDialog)
find_package(Switch REQUIRED)
add_executable(OpenFileDialog ${SWITCH_GUI} OpenFileDialog.cpp)
target_link_libraries(OpenFileDialog Switch.System.Windows.Forms)
