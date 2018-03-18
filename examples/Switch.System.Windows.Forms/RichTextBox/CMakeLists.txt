cmake_minimum_required(VERSION 3.2)

project(RichTextBox)
find_package(Switch REQUIRED)
add_custom_target(RichTextBox SOURCES RichTextBox.cpp)
#add_executable(RichTextBox ${SWITCH_GUI} RichTextBox.cpp)
#target_link_libraries(RichTextBox Switch.System.Windows.Forms)
