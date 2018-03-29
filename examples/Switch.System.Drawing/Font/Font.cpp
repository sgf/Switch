#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Font font1(FontFamily::GenericMonospace, 42.0f, FontStyle::Bold);
      Console::WriteLine("font1 = {0}", font1);

      Font font2("Times", 24.0f);
      Console::WriteLine("font2 = {0}", font2);

      Font font3(FontFamily::GenericSerif, 24.0f);
      Console::WriteLine("font3 = {0}", font3);

      Console::WriteLine("font1 {0} font2", font1 == font2 ? "==" : "!=");
      Console::WriteLine("font2 {0} font3", font2 == font3 ? "==" : "!=");
    }
  };
}

startup_(Examples::Program);

// This code can produces the following output if you run on macOS:
//
// font1 = [Font: Name=Courier, Size=42, Units=3, GdiCharSet=1, GdiVerticalFont=False]
// font2 = [Font: Name=Times, Size=24, Units=3, GdiCharSet=1, GdiVerticalFont=False]
// font3 = [Font: Name=Times, Size=24, Units=3, GdiCharSet=1, GdiVerticalFont=False]
// font1 != font2
// font2 == font3
