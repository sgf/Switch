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

// This code can produces the following output on macOS:
//
// SystemFont::DefaultFont :
// font = [Font: Name=.AppleSystemUIFont, Size=9.75, Units=3, GdiCharSet=1, GdiVerticalFont=False]
// IsSystemFont = True
// Name = .AppleSystemUIFont
// Size = 9.75 Point
// SizeInPoints = 9.75 Point
// Style = Regular
//
// SystemFont::CaptionFont :
// font = [Font: Name=.AppleSystemUIFont, Size=9.75, Units=3, GdiCharSet=1, GdiVerticalFont=False]
// IsSystemFont = True
// Name = .AppleSystemUIFont
// Size = 9.75 Point
// SizeInPoints = 9.75 Point
// Style = Regular
//
