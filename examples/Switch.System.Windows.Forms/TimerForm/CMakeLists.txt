cmake_minimum_required(VERSION 3.2)

project(TimerForm)
find_package(Switch REQUIRED)
SetSwitchApplicationCopyright("© 2010 - 2018 by Gammasoft")
SetSwitchApplicationIdentifier("org.gammasoft.timerForm")
SetSwitchApplicationInformation("This example shows how to use Switch")
add_executable(TimerForm ${SWITCH_GUI} TimerForm.cpp)
target_link_libraries(TimerForm Switch.System.Windows.Forms)
