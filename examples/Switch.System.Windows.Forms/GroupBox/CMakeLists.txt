cmake_minimum_required(VERSION 3.2)

project(GroupBox)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.GroupBox")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(GroupBox ${SWITCH_GUI} GroupBox.cpp)
target_link_libraries(GroupBox Switch.System.Windows.Forms)
