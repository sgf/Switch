cmake_minimum_required(VERSION 3.2)

project(Application)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.Application")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(Application ${SWITCH_GUI} Application.cpp)
target_link_libraries(Application Switch.System.Windows.Forms)
