cmake_minimum_required(VERSION 3.2)

Project(ApplicationIcon)

find_package(Switch REQUIRED)
SetSwitchApplicationIcon(Gammasoft)
add_executable(ApplicationIcon ${SWITCH_GUI} ApplicationIcon.cpp)
target_link_libraries(ApplicationIcon Switch.System.Windows.Forms)
