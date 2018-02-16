#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Linq/Linq.hpp>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Hello, World!");
      Console::WriteLine(u"Привет мир!");
    }
  };
}

startup_(Examples::Program);

