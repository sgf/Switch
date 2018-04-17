cmake_minimum_required(VERSION 3.2)

project(SystemSound)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.SystemSound")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(SystemSound ${SWITCH_GUI} SystemSound.cpp)
target_link_libraries(SystemSound Switch.System.Windows.Forms)
