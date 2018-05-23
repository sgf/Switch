cmake_minimum_required(VERSION 3.2)

project(ColoredTabPages)
find_package(Switch REQUIRED)
add_executable(ColoredTabPages ${SWITCH_GUI} ColoredTabPages.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(ColoredTabPages Switch.System.Windows.Forms)
