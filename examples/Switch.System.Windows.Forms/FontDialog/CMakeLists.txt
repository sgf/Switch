cmake_minimum_required(VERSION 3.2)

project(FontDialog)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.FontDialog")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(FontDialog ${SWITCH_GUI} FontDialog.cpp)
target_link_libraries(FontDialog Switch.System.Windows.Forms)
