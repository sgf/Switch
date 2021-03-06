#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      ExceptionPtr exceptionPtr;

      Thread thread(ThreadStart(delegate_ {
        try {
          throw ArgumentNullException("Ouch there are an error !", caller_);
        } catch (...) {
          exceptionPtr = ExceptionPtr::CurrentException();
        }
      }));
      thread.Start();
      thread.Join();

      if (exceptionPtr) {
        try {
          exceptionPtr.Rethrow();
        } catch (const ArgumentNullException& exception) {
          Console::WriteLine(exception.Message);
        }
      }
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// Ouch there are an error !
