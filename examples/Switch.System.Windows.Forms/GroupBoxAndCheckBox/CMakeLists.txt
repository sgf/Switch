cmake_minimum_required(VERSION 3.2)

project(GroupBoxAndCheckBox)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.GRoupBoxAndcheckBox")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(GroupBoxAndCheckBox ${SWITCH_GUI} GroupBoxAndCheckBox.cpp)
target_link_libraries(GroupBoxAndCheckBox Switch.System.Windows.Forms)
