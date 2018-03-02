#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Environment.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Current directory = {0}", Environment::CurrentDirectory);
    }
  };
}

startup_(Examples::Program);
