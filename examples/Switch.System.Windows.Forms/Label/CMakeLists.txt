cmake_minimum_required(VERSION 3.2)

project(Label)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.Label")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(Label ${SWITCH_GUI} Label.cpp)
target_link_libraries(Label Switch.System.Windows.Forms)
