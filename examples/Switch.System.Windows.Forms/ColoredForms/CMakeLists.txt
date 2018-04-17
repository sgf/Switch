cmake_minimum_required(VERSION 3.2)

project(ColoredForms)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.ColoredForms")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(ColoredForms ${SWITCH_GUI} ColoredForms.cpp)
target_link_libraries(ColoredForms Switch.System.Windows.Forms)
