cmake_minimum_required(VERSION 3.2)

project(FormClick)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.FormClick")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(FormClick ${SWITCH_GUI} FormClick.cpp)
target_link_libraries(FormClick Switch.System.Windows.Forms)
