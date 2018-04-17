cmake_minimum_required(VERSION 3.2)

project(ApplicationEnableVisualStyle)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.ApplicationEnableVisualStyle")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(ApplicationEnableVisualStyle ${SWITCH_GUI} ApplicationEnableVisualStyle.cpp)
target_link_libraries(ApplicationEnableVisualStyle Switch.System.Windows.Forms)
