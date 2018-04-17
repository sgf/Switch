cmake_minimum_required(VERSION 3.2)

project(TabControl)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.TabControl")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(TabControl ${SWITCH_GUI} TabControl.cpp)
target_link_libraries(TabControl Switch.System.Windows.Forms)
