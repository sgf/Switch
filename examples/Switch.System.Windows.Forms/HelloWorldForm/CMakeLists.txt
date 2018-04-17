cmake_minimum_required(VERSION 3.2)

project(HelloWorldForm)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.HelloWworldForm")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(HelloWorldForm ${SWITCH_GUI} HelloWorldForm.cpp)
target_link_libraries(HelloWorldForm Switch.System.Windows.Forms)
