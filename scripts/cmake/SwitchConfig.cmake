#_______________________________________________________________________________
#                                                                include modules
include(${CMAKE_CURRENT_LIST_DIR}/Switch.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/SwitchDependencies.cmake)

#_______________________________________________________________________________
#                                                          set include directory
get_filename_component(SWITCH_INCLUDE_DIRS 
  "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)

#_______________________________________________________________________________
#                                                        set libraries directory
get_filename_component(SWITCH_LIBRARIES_DIRS 
  "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

#_______________________________________________________________________________
#                                                          add external packages
find_package(call_stack REQUIRED)
find_package(CURL REQUIRED)
find_package(easywsclient REQUIRED)
find_package(GTest REQUIRED)
find_package(JPEG REQUIRED)
find_package(RS232 REQUIRED)
find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)

#_______________________________________________________________________________
#                                        set switch application version variable
if (NOT SWITCH_APPLICATION_VERSION)
  set(SWITCH_APPLICATION_VERSION "${APPLICATION_VERSION}")
  add_definitions(-DSWITCH_APPLICATION_VERSION="${SWITCH_APPLICATION_VERSION}")
endif()

#_______________________________________________________________________________
#                                                                  set libraries
set(SWITCH_LIBRARY Switch.TUnit.Core Switch.System.Windows.Forms
  Switch.System.Drawing Switch.System.Core Switch.System Switch.Core)
set(SWITCH_LIBRARIES ${SWITCH_LIBRARY})
set(SWITCH_WITH_TUNIT_MAIN_LIBRARY Switch.TUnit.Main ${SWITCH_LIBRARIES})
set(SWITCH_WITH_TUNIT_MAIN_LIBRARIES ${SWITCH_WITH_TUNIT_MAIN_LIBRARY})

#_______________________________________________________________________________
#                                                                      set found
set(Switch_FOUND TRUE)
set(SWITCH_FOUND TRUE)
