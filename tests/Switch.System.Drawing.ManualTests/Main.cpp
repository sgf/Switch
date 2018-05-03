#include <Switch/Switch.System.Drawing>

using namespace System;
using namespace System::Drawing;

namespace ManualTests {
  class Program {
  public:
    static void PrintColor(const Color& color) {
      Console::WriteLine("{0} :", color);
      Console::WriteLine("A = {0}", color.A);
      Console::WriteLine("R = {0}", color.R);
      Console::WriteLine("G = {0}", color.G);
      Console::WriteLine("B = {0}", color.B);
      Console::WriteLine("H = {0}", color.GetHue());
      Console::WriteLine("S = {0}", color.GetSaturation());
      Console::WriteLine("V = {0}", color.GetBrightness());
      Console::WriteLine();
    }

    // The main entry point for the application.
    static void Main() {
      PrintColor(Color::FromHsb(Color::Blue().GetHue(), Color::Blue().GetSaturation(), Color::Blue().GetBrightness()));
      PrintColor(Color::DarkBlue);
    }
  };
}

startup_(ManualTests::Program);
