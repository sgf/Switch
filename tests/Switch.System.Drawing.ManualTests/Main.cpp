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
      Font font("Arial", 64.0f, GraphicsUnit::Pixel);
      Console::WriteLine("font = {0}", font);
      Console::WriteLine("Size = {0}", font.Size);
      Console::WriteLine("Unit = {0}", font.Unit);
      Console::WriteLine("SizeInPoint = {0}", font.SizeInPoints);
    }
  };
}

startup_(ManualTests::Program);
