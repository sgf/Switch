#define TRACE


#include <Switch/Switch.System.Drawing>

using namespace System;
using namespace System::Drawing;

namespace ManualTests {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine(Color::FromArgb(0x80, Color::Blue).ToString());
    }
  };
}

startup_(ManualTests::Program);
