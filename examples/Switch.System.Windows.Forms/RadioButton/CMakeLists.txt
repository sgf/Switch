cmake_minimum_required(VERSION 3.2)

project(RadioButton)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.RadioButton")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(RadioButton ${SWITCH_GUI} RadioButton.cpp)
target_link_libraries(RadioButton Switch.System.Windows.Forms)
