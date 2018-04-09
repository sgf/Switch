#define TRACE

#include <Switch/Switch.System.Drawing>

using namespace System;
using namespace System::Drawing;

namespace ManualTests {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine(Font(FontFamily("Tahoma", System::Drawing::Text::InstalledFontCollection()), 12.0f, GraphicsUnit::Point));
    }
  };
}

startup_(ManualTests::Program);
