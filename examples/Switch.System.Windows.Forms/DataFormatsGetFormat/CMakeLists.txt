cmake_minimum_required(VERSION 3.2)

project(DataFormatsGetFormat)
find_package(Switch REQUIRED)
add_executable(DataFormatsGetFormat  DataFormatsGetFormat.cpp)
target_link_libraries(DataFormatsGetFormat Switch.System.Windows.Forms)
