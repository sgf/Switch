#_______________________________________________________________________________
#                                                                   standard C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#_______________________________________________________________________________
#                                                              add compile flags
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
endif()

#_______________________________________________________________________________
#                                                          add external packages
if(NOT APPLE AND NOT ANDROID AND NOT CMAKE_HOST_SOLARIS AND UNIX)
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(GTKMM gtkmm-3.0)
  if(NOT GTKMM_FOUND)
    message(FATAL_ERROR "gtkmm-3.0 not found!")
  endif()
  include_directories(${GTKMM_INCLUDE_DIRS})
  link_directories(${GTKMM_LIBRARY_DIRS})
endif ()

#_______________________________________________________________________________
#                                                                 set SWITCH_GUI
if(MSVC)
  set(SWITCH_GUI WIN32)
elseif (APPLE)
  set(SWITCH_GUI MACOSX_BUNDLE)
elseif(UNIX)
  set(SWITCH_GUI)
endif ()

#_______________________________________________________________________________
#                                                 set SWITCH_CORE_LINK_LIBRARIES
if(MSVC)
  set(SWITCH_CORE_LINK_LIBRARIES ws2_32 iphlpapi rpcrt4)
elseif (APPLE)
  set(SWITCH_CORE_LINK_LIBRARIES dl pthread)
elseif(ANDROID)
  set(SWITCH_CORE_LINK_LIBRARIES)
elseif(UNIX)
  set(SWITCH_CORE_LINK_LIBRARIES dl rt uuid pthread)
endif ()

#_______________________________________________________________________________
#                                              set SWITCH_SYSTEM_LINK_FRAMEWORKS
if (APPLE)
  set(SWITCH_SYSTEM_LINK_FRAMEWORKS "-framework Cocoa -framework Foundation")
else ()
  set(SWITCH_SYSTEM_LINK_FRAMEWORKS)
endif ()

#_______________________________________________________________________________
#                                       set SWITCH_SYSTEM_DRAWING_LINK_LIBRARIES
if(MSVC)
  set(SWITCH_SYSTEM_DRAWING_LINK_LIBRARIES uxtheme comctl32)
elseif (APPLE)
  set(SWITCH_SYSTEM_DRAWING_LINK_LIBRARIES)
elseif(UNIX)
  set(SWITCH_SYSTEM_DRAWING_LINK_LIBRARIES ${GTKMM_LIBRARIES})
endif ()
