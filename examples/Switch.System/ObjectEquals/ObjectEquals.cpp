#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      refptr<Object> object1 = new_<Object>();
      refptr<Object> object2 = new_<Object>();

      refptr<Object> object3 = object2;
      Console::WriteLine(object1->Equals(*object3));
      object3 = object1;
      Console::WriteLine(object1->Equals(*object3));
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// False
// True
