#_______________________________________________________________________________
#                                                                        Project
cmake_minimum_required(VERSION 3.2)
include(../scripts/cmake/Version.cmake)
project(Switch.Examples VERSION ${SWITCH_VERSION})
set(PROJECT_BRIEF "These examples show how to use Switch.")
set(PROJECT_AUTHOR gammasoft71)

#_______________________________________________________________________________
#                                                             add Switch package
find_package(Switch REQUIRED)

#_______________________________________________________________________________
#                                                                  Build Options
option(BUILD_DESIGN_PATTERNS_EXAMPLES "Build DesignPatterns examples" ON)
option(BUILD_SWITCH_SYSTEM_EXAMPLES "Build Switch.System examples" ON)
option(BUILD_SWITCH_SYSTEM_DRAWING_EXAMPLES "Build Switch.System.Drawing examples" ON)
option(BUILD_SWITCH_SYSTEM_WINDOWS_FORMS_EXAMPLES "Build SwitchSystem.Windows.Forms examples" ON)
option(BUILD_SWITCH_TUNIT_EXAMPLES "Build Switch.TUnit examples" ON)
option(BUILD_SWITCH_TUNIT_FRAMEWORK_EXAMPLES "Build Switch.TUnit.Framework examples" ON)
option(BUILD_SWITCH_TUNIT_WINFORMS_TUTORIAL "Build Switch Winforms tutorial" ON)

#_______________________________________________________________________________
#                                                                Verbose Options
option(ENABLE_VERBOSE "Enable verbose" OFF)

#_______________________________________________________________________________
#                                                                   standard C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#_______________________________________________________________________________
#                                                    enable USE_FOLDERS property
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#_______________________________________________________________________________
#                                                         executable output path
if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else()
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif()

#_______________________________________________________________________________
#                                                         include Switch modules
include(../scripts/cmake/GetInformations.cmake)
include(../scripts/cmake/Print.cmake)

#_______________________________________________________________________________
#                                                               Get Informations
GetInformations()

#_______________________________________________________________________________
#                                                                    subdir list
macro(subdirlist RESULT CURRENT_DIR)
  file(GLOB children RELATIVE ${CURRENT_DIR} ${CURRENT_DIR}/*)
  set(dirlist "")
  foreach (child ${children})
    if (IS_DIRECTORY ${CURRENT_DIR}/${child})
      LIST(APPEND dirlist ${child})
    endif ()
  endforeach ()
  set(${RESULT} ${dirlist})
endmacro()

#_______________________________________________________________________________
#                                                    add subdrirectory childrens
macro(add_subdirectory_childrens CURRENT_DIR)
  subdirlist(SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DIR}")
  foreach (SUBDIR ${SUBDIRS})
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DIR}/${SUBDIR}")
    set_target_properties(${SUBDIR} PROPERTIES FOLDER ${CURRENT_DIR})
  endforeach ()
endmacro ()

#_______________________________________________________________________________
#                                                 Build Design Patterns examples
print("Generating Switch Examples")
if (BUILD_DESIGN_PATTERNS_EXAMPLES)
  print("  [X] DesignPatterns")
  add_subdirectory_childrens("DesignPatterns")
else()
  print("  [ ] DesignPatterns")
endif()

#_______________________________________________________________________________
#                                                   Build Switch.System examples
if (BUILD_SWITCH_SYSTEM_EXAMPLES)
  print("  [X] Switch.System")
  add_subdirectory_childrens("Switch.System")
else()
  print("  [ ] Switch.System")
endif()

#_______________________________________________________________________________
#                                           Build Switch.System.Drawing examples
if (BUILD_SWITCH_SYSTEM_DRAWING_EXAMPLES)
  print("  [X] Switch.System.Drawing")
  add_subdirectory_childrens("Switch.System.Drawing")
endif()

#_______________________________________________________________________________
#                                     Build Switch.System.Windows.Forms examples
if (BUILD_SWITCH_SYSTEM_WINDOWS_FORMS_EXAMPLES)
  print("  [X] Switch.System.Windows.Forms")
  add_subdirectory_childrens("Switch.System.Windows.Forms")
else()
  print("  [ ] Switch.System.Windows.Forms")
endif()

#_______________________________________________________________________________
#                                                    Build Switch.TUnit examples
if (BUILD_SWITCH_TUNIT_EXAMPLES)
  print("  [X] Switch.TUnit")
  add_subdirectory_childrens("Switch.TUnit")
else()
  print("  [ ] Switch.TUnit")
endif()

#_______________________________________________________________________________
#                                          Build Switch.TUnit.Framework examples
if (BUILD_SWITCH_TUNIT_FRAMEWORK_EXAMPLES)
  print("  [X] Switch.TUnit.Framework")
  add_subdirectory_childrens("Switch.TUnit.Framework")
else()
  print("  [ ] Switch.TUnit.Framework")
endif()

#_______________________________________________________________________________
#                                                        Build Winforms tutorial
if (BUILD_SWITCH_TUNIT_WINFORMS_TUTORIAL)
  print("  [X] Winforms tutorial")
  add_subdirectory_childrens("WinformsTutorial")
else()
  print("  [ ] Winforms tutorial")
endif()
