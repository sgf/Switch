cmake_minimum_required(VERSION 3.2)

project(Form)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.Form")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(Form ${SWITCH_GUI} Form.cpp)
target_link_libraries(Form Switch.System.Windows.Forms)
