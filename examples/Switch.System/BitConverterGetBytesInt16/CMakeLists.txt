cmake_minimum_required(VERSION 3.2)

project(BitConverterGetBytesInt16)
find_package(Switch REQUIRED)
add_executable(BitConverterGetBytesInt16 BitConverterGetBytesInt16.cpp)
target_link_libraries(BitConverterGetBytesInt16 Switch.System)
