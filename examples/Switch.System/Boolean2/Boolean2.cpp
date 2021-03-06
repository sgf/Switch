#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Boolean raining = false;
      Boolean busLate = true;

      Console::WriteLine("It is raining: {0}", raining ? "Yes" : "No");
      Console::WriteLine("The bus is late: {0}", busLate ? "Yes" : "No");
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// It is raining: No
// The bus is late: Yes
