#include <Switch/Switch.System.hpp>

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace ManualTests {
  class Program static_ {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

//startup_(ManualTests::Program);
int main(int argc, char* argv[]) {
  Environment::SetCommandLineArgs(argv, argc);
  ManualTests::Program::Main();
}
