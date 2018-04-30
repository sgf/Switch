cmake_minimum_required(VERSION 3.2)

project(MouseEvent)
find_package(Switch REQUIRED)
add_custom_target(MouseEvent SOURCES MouseEvent.cpp Properties/AssemblyInfo.cpp)
#add_executable(MouseEvent ${SWITCH_GUI} MouseEvent.cpp)
#target_link_libraries(MouseEvent Switch.System.Windows.Forms)

