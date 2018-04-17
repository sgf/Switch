cmake_minimum_required(VERSION 3.2)

project(WndProc)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.WndProc")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(WndProc ${SWITCH_GUI} WndProc.cpp)
target_link_libraries(WndProc Switch.System.Windows.Forms)
