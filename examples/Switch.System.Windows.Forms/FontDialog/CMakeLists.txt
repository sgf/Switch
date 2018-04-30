cmake_minimum_required(VERSION 3.2)

project(FontDialog)
find_package(Switch REQUIRED)
add_executable(FontDialog ${SWITCH_GUI} FontDialog.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(FontDialog Switch.System.Windows.Forms)
