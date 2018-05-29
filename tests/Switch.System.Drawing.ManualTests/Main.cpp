#include <Switch/Switch.System.Drawing>

using namespace System;
using namespace System::Drawing;

namespace ManualTests {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

startup_(ManualTests::Program);
