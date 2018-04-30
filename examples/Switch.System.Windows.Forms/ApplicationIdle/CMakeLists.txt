cmake_minimum_required(VERSION 3.2)

project(ApplicationIdle)
find_package(Switch REQUIRED)
add_executable(ApplicationIdle ${SWITCH_GUI} ApplicationIdle.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(ApplicationIdle Switch.System.Windows.Forms)
