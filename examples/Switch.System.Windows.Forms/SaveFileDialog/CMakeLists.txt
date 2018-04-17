cmake_minimum_required(VERSION 3.2)

project(SaveFileDialog)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.FileDialog")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(SaveFileDialog ${SWITCH_GUI} SaveFileDialog.cpp)
target_link_libraries(SaveFileDialog Switch.System.Windows.Forms)
