#define TRACE

#include <Switch/Nameof.hpp>
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Drawing/FontFamily.hpp>
#include <Switch/System/Drawing/Font.hpp>

using namespace System;
using namespace System::Drawing;

namespace ManualTests {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("GenericMonospace : \"{0}\"", FontFamily::GenericMonospace().Name);
      Console::WriteLine("GenericSansSerif : \"{0}\"", FontFamily::GenericSansSerif().Name);
      Console::WriteLine("GenericSerif : \"{0}\"", FontFamily::GenericSerif().Name);
      Console::WriteLine("Families : {0}", FontFamily::Families().Length);
      for (System::Drawing::FontFamily fontFamily : System::Drawing::FontFamily::Families())
        Console::WriteLine("  fontFamily = \"{0}\"", fontFamily.Name);

      Font font("Wingdings 2", 23.0f, FontStyle::Bold);
      Console::WriteLine("font = {0}", font);
    }
  };
}

startup_(ManualTests::Program);
