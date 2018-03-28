#define TRACE

#include <Switch/Nameof.hpp>
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Drawing/FontFamily.hpp>

using namespace System;
using namespace System::Drawing;

namespace ManualTests {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("GenericMonospacef : \"{0}\"", FontFamily::GenericMonospace().Name);
      Console::WriteLine("GenericSansSerif : \"{0}\"", FontFamily::GenericSansSerif().Name);
      Console::WriteLine("GenericSerif : \"{0}\"", FontFamily::GenericSerif().Name);
      Console::WriteLine("Families :");
      for (System::Drawing::FontFamily fontFamily : System::Drawing::FontFamily::Families())
        Console::WriteLine("  fontFamily = \"{0}\"", fontFamily.Name);
    }
  };
}

startup_(ManualTests::Program);
