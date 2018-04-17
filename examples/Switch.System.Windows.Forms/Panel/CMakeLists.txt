cmake_minimum_required(VERSION 3.2)

project(Panel)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.Panel")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(Panel ${SWITCH_GUI} Panel.cpp)
target_link_libraries(Panel Switch.System.Windows.Forms)
