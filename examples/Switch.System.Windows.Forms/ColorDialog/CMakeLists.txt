cmake_minimum_required(VERSION 3.2)

project(ColorDialog)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.ColorDialog")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(ColorDialog ${SWITCH_GUI} ColorDialog.cpp)
target_link_libraries(ColorDialog Switch.System.Windows.Forms)
