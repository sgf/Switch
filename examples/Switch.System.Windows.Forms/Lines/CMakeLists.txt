cmake_minimum_required(VERSION 3.2)

project(Lines)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.Lines")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(Lines ${SWITCH_GUI} Lines.cpp)
target_link_libraries(Lines Switch.System.Windows.Forms)
