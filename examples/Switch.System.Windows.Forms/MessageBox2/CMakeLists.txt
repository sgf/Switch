cmake_minimum_required(VERSION 3.2)

project(MessageBox2)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.MessageBox2")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(MessageBox2 ${SWITCH_GUI} MessageBox2.cpp)
target_link_libraries(MessageBox2 Switch.System.Windows.Forms)
