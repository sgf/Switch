#include <Switch/Switch>

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<string> names = { "Burke", "Connor", "Frank", "Everett", "Albert", "George", "Harris", "David" };

      $<IEnumerable<string>> query = names.Where(delegate_(string s) {return s.Length == 5;})->OrderBy<string>(delegate_(string s) {return s;})->Select<string>(delegate_(string s) {return s.ToUpper();});

      for (string item : *query)
        Console::WriteLine(item);
    }
  };
}

startup_(Examples::Program);

// This code example produces the following output:
//
// BURKE
// DAVID
// FRANK
