cmake_minimum_required(VERSION 3.2)

Project(ApplicationIcon)
find_package(Switch REQUIRED)
SetSwitchApplicationIcon(Enterprise)
add_executable(ApplicationIcon ${SWITCH_GUI} ApplicationIcon.cpp Properties/AssemblyInfo.cpp)
target_link_libraries(ApplicationIcon Switch.System.Windows.Forms)
