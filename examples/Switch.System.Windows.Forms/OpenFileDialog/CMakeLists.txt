cmake_minimum_required(VERSION 3.2)

project(OpenFileDialog)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.OpenFileDialog")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(OpenFileDialog ${SWITCH_GUI} OpenFileDialog.cpp)
target_link_libraries(OpenFileDialog Switch.System.Windows.Forms)
