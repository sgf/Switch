cmake_minimum_required(VERSION 3.2)

project(FolderBrowserDialog)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.FolderBrowserDialog")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(FolderBrowserDialog ${SWITCH_GUI} FolderBrowserDialog.cpp)
target_link_libraries(FolderBrowserDialog Switch.System.Windows.Forms)
