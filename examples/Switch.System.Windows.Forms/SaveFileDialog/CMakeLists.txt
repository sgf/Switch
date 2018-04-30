cmake_minimum_required(VERSION 3.2)

project(SaveFileDialog)
find_package(Switch REQUIRED)
add_executable(SaveFileDialog ${SWITCH_GUI} SaveFileDialog.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(SaveFileDialog Switch.System.Windows.Forms)
