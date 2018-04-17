cmake_minimum_required(VERSION 3.2)

project(TrackBar)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.TrackBar")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(TrackBar ${SWITCH_GUI} TrackBar.cpp)
target_link_libraries(TrackBar Switch.System.Windows.Forms)
