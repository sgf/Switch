cmake_minimum_required(VERSION 3.2)

project(DataFormatsGetFormat)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.DataFormatsGetFormat")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(DataFormatsGetFormat DataFormatsGetFormat.cpp)
target_link_libraries(DataFormatsGetFormat Switch.System.Windows.Forms)
