macro(BuildSwitchTests)
  #_____________________________________________________________________________
  #                                                                 Switch Tests
  print("Switch Tests")
  if (BUILD_SWITCH_TESTS)
    enable_testing()
  endif()

  #_____________________________________________________________________________
  #                                                      Switch.Core.ManualTests
  if (BUILD_SWITCH_TESTS AND BUILD_SWITCH_CORE)
    print("  [X] Switch.Core.ManualTests")
    add_subdirectory("tests/Switch.Core.ManualTests")
  else()
    print("  [ ] Switch.Core.ManualTests")
  endif()

  #_____________________________________________________________________________
  #                                                        Switch.Core.UnitTests
  if (BUILD_SWITCH_TESTS AND BUILD_SWITCH_CORE)
    print("  [X] Switch.Core.UnitTests")
    add_subdirectory("tests/Switch.Core.UnitTests")
  else()
    print("  [ ] Switch.Core.UnitTests")
  endif()

  #_____________________________________________________________________________
  #                                                    Switch.System.ManualTests
  if (BUILD_SWITCH_TESTS AND BUILD_SWITCH_SYSTEM)
    print("  [X] Switch.System.ManualTests")
    add_subdirectory("tests/Switch.System.ManualTests")
  else()
    print("  [ ] Switch.System.ManualTests")
  endif()

  #_____________________________________________________________________________
  #                                                      Switch.System.UnitTests
  if (BUILD_SWITCH_TESTS AND BUILD_SWITCH_SYSTEM)
    print("  [X] Switch.System.UnitTests")
    add_subdirectory("tests/Switch.System.UnitTests")
  else()
    print("  [ ] Switch.System.UnitTests")
  endif()

  #_____________________________________________________________________________
  #                                                      Switch.System.UnitTests
  if (BUILD_SWITCH_TESTS AND BUILD_SWITCH_SYSTEM_CORE)
    print("  [X] Switch.System.Core.UnitTests")
    add_subdirectory("tests/Switch.System.Core.UnitTests")
  else()
    print("  [ ] Switch.System.Core.UnitTests")
  endif()

  #_____________________________________________________________________________
  #                                            Switch.System.Drawing.ManualTests
  if (NOT IOS AND NOT ANDROID AND NOT CMAKE_HOST_SOLARIS AND BUILD_SWITCH_TESTS AND BUILD_SWITCH_SYSTEM_DRAWING)
    print("  [X] Switch.System.Drawing.ManualTests")
    add_subdirectory("tests/Switch.System.Drawing.ManualTests")
  else()
    print("  [ ] Switch.System.Drawing.ManualTests")
  endif()

  #_____________________________________________________________________________
  #                                              Switch.System.Drawing.UnitTests
  if (NOT IOS AND NOT ANDROID AND NOT CMAKE_HOST_SOLARIS AND BUILD_SWITCH_TESTS AND BUILD_SWITCH_SYSTEM_DRAWING)
    print("  [X] Switch.System.Drawing.UnitTests")
    add_subdirectory("tests/Switch.System.Drawing.UnitTests")
  else()
    print("  [ ] Switch.System.Drawing.UnitTests")
  endif()

  #_____________________________________________________________________________
  #                                      Switch.System.Windows.Forms.ManualTests
  if (NOT IOS AND NOT ANDROID AND NOT CMAKE_HOST_SOLARIS AND BUILD_SWITCH_TESTS AND BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
    print("  [X] Switch.System.Windows.Forms.ManualTests")
    add_subdirectory("tests/Switch.System.Windows.Forms.ManualTests")
  else()
    print("  [ ] Switch.System.Windows.Forms.ManualTests")
  endif()

  #_____________________________________________________________________________
  #                                        Switch.System.Windows.Forms.UnitTests
  if (NOT IOS AND NOT ANDROID AND NOT CMAKE_HOST_SOLARIS AND BUILD_SWITCH_TESTS AND BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
    print("  [X] Switch.System.Windows.Forms.UnitTests")
    add_subdirectory("tests/Switch.System.Windows.Forms.UnitTests")
  else()
    print("  [ ] Switch.System.Windows.Forms.UnitTests")
  endif()

  #_____________________________________________________________________________
  #                                                Switch.TUnit.Core.ManualTests
  if (BUILD_SWITCH_TESTS AND BUILD_SWITCH_TUNIT_CORE)
    print("  [X] Switch.TUnit.ManualTests")
    add_subdirectory("tests/Switch.TUnit.ManualTests")
  else()
    print("  [ ] Switch.TUnit.ManualTests")
  endif()

  #_____________________________________________________________________________
  #                                                  Switch.TUnit.Core.UnitTests
  if (BUILD_SWITCH_TESTS AND BUILD_SWITCH_TUNIT_CORE)
    print("  [X] Switch.TUnit.Core.UnitTests")
    add_subdirectory("tests/Switch.TUnit.UnitTests")
  else()
    print("  [ ] Switch.TUnit.Core.UnitTests")
  endif()

  #_____________________________________________________________________________
  #                                           Switch.TUnit.Framework.ManualTests
  if (BUILD_SWITCH_TESTS AND BUILD_SWITCH_TUNIT_FRAMEWORK)
    print("  [X] Switch.TUnit.Framework.ManualTests")
    add_subdirectory("tests/Switch.TUnit.Framework.ManualTests")
  else()
    print("  [ ] Switch.TUnit.Framework.ManualTests")
  endif()
endmacro()
