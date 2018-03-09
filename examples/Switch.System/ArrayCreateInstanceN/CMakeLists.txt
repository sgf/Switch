cmake_minimum_required(VERSION 3.2)

project(ArrayCreateInstanceN)
find_package(Switch REQUIRED)
add_executable(ArrayCreateInstanceN ArrayCreateInstanceN.cpp)
target_link_libraries(ArrayCreateInstanceN Switch.System)
