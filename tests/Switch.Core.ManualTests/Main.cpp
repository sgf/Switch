#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Environment.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      for (Environment::SpecialFolder specialFolder : Enum<>::GetValues<Environment::SpecialFolder>())
        Console::WriteLine("{0} ==> {1}", specialFolder, Environment::GetFolderPath(specialFolder));
    }
  };
}

startup_(Examples::Program);

