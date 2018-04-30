cmake_minimum_required(VERSION 3.2)

project(FolderBrowserDialog)
find_package(Switch REQUIRED)
add_executable(FolderBrowserDialog ${SWITCH_GUI} FolderBrowserDialog.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(FolderBrowserDialog Switch.System.Windows.Forms)
