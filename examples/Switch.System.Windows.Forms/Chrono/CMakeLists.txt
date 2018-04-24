cmake_minimum_required(VERSION 3.2)

project(Chrono)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.Form")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(Chrono ${SWITCH_GUI} Chrono.cpp)
target_link_libraries(Chrono Switch.System.Windows.Forms)
