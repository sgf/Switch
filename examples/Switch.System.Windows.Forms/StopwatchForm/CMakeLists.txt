cmake_minimum_required(VERSION 3.2)

project(StopwatchForm)
find_package(Switch REQUIRED)
add_executable(StopwatchForm ${SWITCH_GUI} StopwatchForm.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(StopwatchForm Switch.System.Windows.Forms)
