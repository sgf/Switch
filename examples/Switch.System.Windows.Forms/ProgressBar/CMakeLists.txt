cmake_minimum_required(VERSION 3.2)

project(ProgressBar)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.ProgressBar")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(ProgressBar ${SWITCH_GUI} ProgressBar.cpp)
target_link_libraries(ProgressBar Switch.System.Windows.Forms)
