cmake_minimum_required(VERSION 3.2)

project(SomeControls)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.SomeControls")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(SomeControls ${SWITCH_GUI} SomeControls.cpp)
target_link_libraries(SomeControls Switch.System.Windows.Forms)
