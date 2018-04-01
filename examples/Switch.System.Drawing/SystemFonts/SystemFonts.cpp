#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("SystemFont::DefaultFont :");
      Font font = SystemFonts::DefaultFont;
      Console::WriteLine("font = {0}", font);
      Console::WriteLine("IsSystemFont = {0}", font.IsSystemFont);
      Console::WriteLine("Name = {0}", font.Name);
      Console::WriteLine("Size = {0} {1}", font.Size, font.Unit);
      Console::WriteLine("SizeInPoints = {0} Point", font.SizeInPoints);
      Console::WriteLine("Style = {0}", font.Style);
      Console::WriteLine();

      Console::WriteLine("SystemFont::CaptionFont :");
      font = SystemFonts::CaptionFont;
      Console::WriteLine("font = {0}", font);
      Console::WriteLine("IsSystemFont = {0}", font.IsSystemFont);
      Console::WriteLine("Name = {0}", font.Name);
      Console::WriteLine("Size = {0} {1}", font.Size, font.Unit);
      Console::WriteLine("SizeInPoints = {0} Point", font.SizeInPoints);
      Console::WriteLine("Style = {0}", font.Style);
      Console::WriteLine();
    }
  };
}

startup_(Examples::Program);

// This code can produces the following output:
//
// color = Color [Control]
// Argb = 0xFFE2E2E2
// Alpha = 255
// Red = 226
// Green = 226
// Blue = 226
//
// color = Color [ActiveCaptionText]
// Argb = 0xFF000000
// Alpha = 255
// Red = 0
// Green = 0
// Blue = 0
//
