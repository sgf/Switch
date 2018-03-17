cmake_minimum_required(VERSION 3.2)

project(ColorDialog)
find_package(Switch REQUIRED)
add_executable(ColorDialog ${SWITCH_GUI} ColorDialog.cpp)
target_link_libraries(ColorDialog Switch.System.Windows.Forms)
