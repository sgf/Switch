#include <utility>
#include <Switch/Switch.System.Drawing>

using namespace System;
using namespace System::Drawing;

namespace ManualTests {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Pen pen(SolidBrush {Color::Green});
      pen.CompoundArray = {1.0f, 2.0f, 0.0f, 4.0f};
      Console::WriteLine("pen.Color = {0}", pen.Color);
    }
  };
}

startup_(ManualTests::Program);
