#include <Switch/Switch.Core.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("1 = {0}, 2 = {1}, 3 = {2}", 1, 2, 3);
    }
  };
}

startup_(Examples::Program);
