#_______________________________________________________________________________
#                                                               ReadAssemblyInfo
macro(ReadAssemblyInfo ASSEMBLY_INFO)
  file(READ "${CMAKE_CURRENT_SOURCE_DIR}/${ASSEMBLY_INFO}" ASSEMBLY_INFO_STRING)
  string(REPLACE "\n" ";" ASSEMBLY_INFO_LIST ${ASSEMBLY_INFO_STRING})
  list(REMOVE_ITEM ASSEMBLY_INFO_LIST "")

  foreach(ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LIST})
    string(STRIP ${ASSEMBLY_INFO_LINE} ASSEMBLY_INFO_LINE)
    if (${ASSEMBLY_INFO_LINE} MATCHES "(AssemblyCopyright_*)")
      string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "(\"" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "\")" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      SetSwitchApplicationCopyright("${ASSEMBLY_INFO_LINE}")
    endif()

    string(STRIP ${ASSEMBLY_INFO_LINE} ASSEMBLY_INFO_LINE)
    if (${ASSEMBLY_INFO_LINE} MATCHES "(AssemblyIdentifier_*)")
      string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "(\"" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "\")" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      SetSwitchApplicationIdentifier("${ASSEMBLY_INFO_LINE}")
    endif()

    if (${ASSEMBLY_INFO_LINE} MATCHES "(AssemblyDescription_*)")
      string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "(\"" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "\")" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      SetSwitchApplicationInformation("${ASSEMBLY_INFO_LINE}")
    endif()

    if (${ASSEMBLY_INFO_LINE} MATCHES "(AssemblyVersion_*)")
      string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "(\"" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "\")" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      if ("${ASSEMBLY_INFO_LINE}" STREQUAL "" OR "${ASSEMBLY_INFO_LINE}" STREQUAL "*")
        if (APPLICATION_VERSION)
          SetSwitchApplicationVersion("${APPLICATION_VERSION}")
        else()
          SetSwitchApplicationVersion("${PROJECT_VERSION}")
        endif()
      else()
        SetSwitchApplicationVersion("${ASSEMBLY_INFO_LINE}")
      endif()
    endif()

    if (${ASSEMBLY_INFO_LINE} MATCHES "(AssemblyProduct_*)")
      string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "(\"" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      string(REPLACE "\")" "" ASSEMBLY_INFO_LINE ${ASSEMBLY_INFO_LINE})
      SetSwitchApplicationName("${ASSEMBLY_INFO_LINE}")
    endif()

  endforeach()
endmacro()

#_______________________________________________________________________________
#                                                  SetSwitchApplicationCopyright
macro(SetSwitchApplicationCopyright APPLICATION_COPYRIGHT)
  if(MSVC)
  elseif (APPLE)
    set(MACOSX_BUNDLE_COPYRIGHT ${APPLICATION_COPYRIGHT})
  elseif (UNIX)
  endif()
endmacro()

#_______________________________________________________________________________
#                                                       SetSwitchApplicationIcon
macro(SetSwitchApplicationIcon PATH_APPLICATION_ICON)
  if(MSVC)
    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/application.rc "IDI_ICON1 ICON DISCARDABLE \"${CMAKE_CURRENT_SOURCE_DIR}/${PATH_APPLICATION_ICON}.ico\"\n")
  elseif (APPLE)
    configure_file(${PATH_APPLICATION_ICON}.icns ${CMAKE_CURRENT_BINARY_DIR}/application.icns COPYONLY)
    set(MACOSX_BUNDLE_ICON_FILE application.icns)
    set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/application.icns PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
  elseif (UNIX)
  endif()
endmacro()

#_______________________________________________________________________________
#                                                 SetSwitchApplicationIdentifier
macro(SetSwitchApplicationIdentifier APPLICATION_IDENTIFIER)
  if(MSVC)
  elseif (APPLE)
    set(MACOSX_BUNDLE_GUI_IDENTIFIER "${APPLICATION_IDENTIFIER}")
  elseif (UNIX)
  endif()
endmacro()

#_______________________________________________________________________________
#                                                SetSwitchApplicationInformation
macro(SetSwitchApplicationInformation APPLICATION_INFORMATION)
  if(MSVC)
    elseif (APPLE)
  set(MACOSX_BUNDLE_INFO_STRING "${APPLICATION_INFORMATION}")
    elseif (UNIX)
  endif()
endmacro()

#_______________________________________________________________________________
#                                                       SetSwitchApplicationName
macro(SetSwitchApplicationName APPLICATION_NAME)
  if(MSVC)
    elseif (APPLE)
  set(MACOSX_BUNDLE_BUNDLE_NAME "${APPLICATION_NAME}")
    elseif (UNIX)
  endif()
endmacro()

#_______________________________________________________________________________
#                                                    SetSwitchApplicationVersion
macro(SetSwitchApplicationVersion APPLICATION_VER)
  set(APPLICATION_VERSION "${APPLICATION_VER}")
  if(MSVC)
  elseif (APPLE)
    set(MACOSX_BUNDLE_BUNDLE_VERSION "${APPLICATION_VERSION}")
  elseif (UNIX)
  endif()
endmacro()

#_______________________________________________________________________________
#                                                                   standard C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#_______________________________________________________________________________
#                                                     add compile and link flags
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
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
#                                                        set application version
if (NOT APPLICATION_VERSION)
  set(APPLICATION_VERSION "${PROJECT_VERSION}")
  SetSwitchApplicationVersion(${APPLICATION_VERSION})
endif()

#_______________________________________________________________________________
#        set application informations if Properties/AssemblyInfo.cpp file exists
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Properties/AssemblyInfo.cpp")
  ReadAssemblyInfo("Properties/AssemblyInfo.cpp")
endif()

#_______________________________________________________________________________
#                                               set default SWITCH_RESOURCE_FILE
if(MSVC)
  if (EXISTS ${CMAKE_INSTALL_PREFIX}/resource/Switch/default.rc)
    configure_file(${CMAKE_INSTALL_PREFIX}/resource/Switch/default.rc ${CMAKE_CURRENT_BINARY_DIR}/application.rc COPYONLY)
    set(SWITCH_RESOURCE_FILE ${CMAKE_CURRENT_BINARY_DIR}/application.rc)
  endif()
elseif (APPLE)
  if (EXISTS ${CMAKE_INSTALL_PREFIX}/resource/Switch/default.icns)
    configure_file(${CMAKE_INSTALL_PREFIX}/resource/Switch/default.icns ${CMAKE_CURRENT_BINARY_DIR}/application.icns COPYONLY)
    set(SWITCH_RESOURCE_FILE ${CMAKE_CURRENT_BINARY_DIR}/application.icns)
  endif()
elseif(UNIX)
endif ()

#_______________________________________________________________________________
#                                                                 set SWITCH_GUI
if(MSVC)
  set(SWITCH_GUI WIN32 ${SWITCH_RESOURCE_FILE})
elseif (APPLE)
  set(SWITCH_GUI MACOSX_BUNDLE ${SWITCH_RESOURCE_FILE})
elseif(UNIX)
  set(SWITCH_GUI ${SWITCH_RESOURCE_FILE})
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
