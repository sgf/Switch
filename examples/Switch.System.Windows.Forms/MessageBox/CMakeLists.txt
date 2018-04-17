cmake_minimum_required(VERSION 3.2)

project(MessageBox)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.MessageBox")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(MessageBox ${SWITCH_GUI} MessageBox.cpp)
target_link_libraries(MessageBox Switch.System.Windows.Forms)
