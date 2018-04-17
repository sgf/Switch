cmake_minimum_required(VERSION 3.2)

project(EnableChangedEvent)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.EnableChangeEvent")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(EnableChangedEvent ${SWITCH_GUI} EnableChangedEvent.cpp)
target_link_libraries(EnableChangedEvent Switch.System.Windows.Forms)
