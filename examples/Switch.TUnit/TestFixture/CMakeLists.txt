cmake_minimum_required(VERSION 3.2)

project(TestFixture)

find_package(Switch REQUIRED)
add_executable(TestFixture TestFixture.cpp)
target_link_libraries(TestFixture Switch.TUnit.Main)
