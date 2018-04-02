cmake_minimum_required(VERSION 3.2)

project(FontChangedEvent)
find_package(Switch REQUIRED)
add_executable(FontChangedEvent ${SWITCH_GUI} FontChangedEvent.cpp)
target_link_libraries(FontChangedEvent Switch.System.Windows.Forms)
