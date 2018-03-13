cmake_minimum_required(VERSION 3.2)

project(EnableChangedEvent)
find_package(Switch REQUIRED)
add_executable(EnableChangedEvent ${SWITCH_GUI} EnableChangedEvent.cpp)
target_link_libraries(EnableChangedEvent Switch.System.Windows.Forms)
