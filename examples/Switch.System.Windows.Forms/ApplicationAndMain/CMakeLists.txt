cmake_minimum_required(VERSION 3.2)

project(ApplicationAndMain)
find_package(Switch REQUIRED)
add_executable(ApplicationAndMain ${SWITCH_GUI} ApplicationAndMain.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(ApplicationAndMain Switch.System.Windows.Forms)
