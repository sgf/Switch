cmake_minimum_required(VERSION 3.2)

project(FontChangedEvent)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.FontChangedEvent")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(FontChangedEvent ${SWITCH_GUI} FontChangedEvent.cpp)
target_link_libraries(FontChangedEvent Switch.System.Windows.Forms)
