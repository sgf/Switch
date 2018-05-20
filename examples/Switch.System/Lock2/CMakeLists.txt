cmake_minimum_required(VERSION 3.2)

project(Lock2)
find_package(Switch REQUIRED)
add_executable(Lock2 Lock2.cpp)
target_link_libraries(Lock2 Switch.System)
