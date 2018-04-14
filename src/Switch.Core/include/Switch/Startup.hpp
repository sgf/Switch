/// @file
/// @brief Contains #startup_ keyword.
#pragma once

#include<cstdlib>
#include "CoreExport.hpp"
#include "Static.hpp"
#include "System/Environment.hpp"

/// @cond
#if !(defined(WIN32) && defined(DECLARE_HANDLE))
using HINSTANCE = struct HINSTANCE__ { int unused; }*;
#endif

#if !defined(_WIN32)
#define __argc 0
#define __argv null
#endif
/// @endcond

namespace Switch {
  /// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the Main procedure that should run when the application starts.
  /// @par Library
  /// Switch.Core
  /// @param mainClass The class that contains the static Main method.
  /// @par Examples
  /// This example show a Main method without arguments and without return code
  /// @include Main1.cpp
  /// @par
  /// This example show a Main method with a return code without arguments
  /// @include Main2.cpp
  /// @par
  /// This example show a Main method with argument and without return code
  /// @include Main3.cpp
  /// @par
  /// This example show a Main method with argument and return code
  /// @include Main4.cpp
  /// @ingroup Keywords
#define startup_(mainClass) \
  int main(int argc, char* argv[]) {\
    struct Startup static_ {\
      static int Run(void (*startup)(), const System::Array<System::String>& args) {startup(); return System::Environment::ExitCode;}\
      static int Run(int (*startup)(), const System::Array<System::String>& args) {return startup();}\
      static int Run(void (*startup)(const System::Array<System::String>&), const System::Array<System::String>& args) {startup(args); return System::Environment::ExitCode;}\
      static int Run(int (*startup)(const System::Array<System::String>&), const System::Array<System::String>& args) {return startup(args);}\
    };\
    return Startup::Run(mainClass::Main, System::Environment::SetCommandLineArgs(argv, argc));\
  } \
  \
  int WinMain(HINSTANCE instance, HINSTANCE previousInstance, char* commandLine, int commandShow) {\

  /*instance can retrieve with GetModuleHandle(NULL) function */\
  /*previousInstance is always NULL */\
  /*commandLine can retrieve with __argc and __argv global variables*/\
  /*commandShow can retrieve with GetStartupInfo() function */\
  return main(__argc, __argv);\
}\
int __startup_force_to_end_with_semicolon__ = 0
}
