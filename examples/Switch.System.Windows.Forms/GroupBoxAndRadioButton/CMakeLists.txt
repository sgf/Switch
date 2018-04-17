cmake_minimum_required(VERSION 3.2)

project(GroupBoxAndRadioButton)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.GroupBoxAndRadioButton")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(GroupBoxAndRadioButton ${SWITCH_GUI} GroupBoxAndRadioButton.cpp)
target_link_libraries(GroupBoxAndRadioButton Switch.System.Windows.Forms)
