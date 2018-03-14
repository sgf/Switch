cmake_minimum_required(VERSION 3.2)

project(LocationChangedEvent)
find_package(Switch REQUIRED)
add_custom_target(LocationChangedEvent SOURCES LocationChangedEvent.cpp)
#add_executable(LocationChangedEvent ${SWITCH_GUI} LocationChangedEvent.cpp)
#target_link_libraries(LocationChangedEvent Switch.System.Windows.Forms)
