#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  namespace ObjectTest {
    class Object1 : public object {
    };
  }

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      $<Object> obj1 = new_<ObjectTest::Object1>();
      Console::WriteLine(obj1->ToString());

      $<Object> obj2 = new_<DateTime>(1971, 1, 5, 23, 5, 0);
      Console::WriteLine(obj2->ToString());

      $<Object> obj3 = new_<Boolean>();
      Console::WriteLine(obj3->ToString());
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// Examples::ObjectTest::Object1
// 5/01/1971 23:05:00
// False
