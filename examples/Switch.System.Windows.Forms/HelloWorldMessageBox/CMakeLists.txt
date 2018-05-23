cmake_minimum_required(VERSION 3.2)

project(HelloWorldMessageBox)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2018 by Gammasoft.")
SetSwitchApplicationIdentifier("org.gammasoft.HelloWorldMessageBox")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(HelloWorldMessageBox ${SWITCH_GUI} HelloWorldMessageBox.cpp)
target_link_libraries(HelloWorldMessageBox Switch.System.Windows.Forms)
