cmake_minimum_required(VERSION 3.2)

project(CheckBox)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.CheckBox")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(CheckBox ${SWITCH_GUI} CheckBox.cpp)
target_link_libraries(CheckBox Switch.System.Windows.Forms)
