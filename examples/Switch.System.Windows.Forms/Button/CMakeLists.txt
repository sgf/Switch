cmake_minimum_required(VERSION 3.2)

project(Button)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.Button")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(Button ${SWITCH_GUI} Button.cpp)
target_link_libraries(Button Switch.System.Windows.Forms)
