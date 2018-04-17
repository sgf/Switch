cmake_minimum_required(VERSION 3.2)

project(MouseEvent)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.MouseEvent")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_custom_target(MouseEvent SOURCES MouseEvent.cpp)
#add_executable(MouseEvent ${SWITCH_GUI} MouseEvent.cpp)
#target_link_libraries(MouseEvent Switch.System.Windows.Forms)

