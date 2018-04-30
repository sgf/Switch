cmake_minimum_required(VERSION 3.2)

project(RichTextBox)
add_custom_target(RichTextBox SOURCES RichTextBox.cpp Properties/AssemblyInfo.cpp)
#add_executable(RichTextBox ${SWITCH_GUI} RichTextBox.cpp Properties/AssemblyInfo.cpp)
#target_link_libraries(RichTextBox Switch.System.Windows.Forms)
