#include <Pcf/Pcf>

using namespace System;
using namespace System::Threading;
using namespace System::Threading::Tasks;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      try {
        Parallel::Invoke(
                         BasicAction,  // Param #0 - static method
                         pcf_delegate {     // Param #1 - lambda expression
                           pcf_lock(lck)
                             Console::WriteLine("Method=beta, Thread={0}", Thread::CurrentThread().ManagedThreadId);
                         },
                         delegate<void> {pcf_delegate {    // Param #2 - in-line delegate
                           pcf_lock(lck)
                             Console::WriteLine("Method=gamma, Thread={0}", Thread::CurrentThread().ManagedThreadId);
                           }}
                         );
      }
      // No exception is expected in this example, but if one is still thrown from a task,
      // it will be wrapped in AggregateException and propagated to the main thread.
      catch (const AggregateException& e) {
        Console::WriteLine("An action has thrown an exception. THIS WAS UNEXPECTED.\n{0}", e.InnerException().ToString());
      }
    }
    
    static void BasicAction() {
      pcf_lock(lck)
        Console::WriteLine("Method=alpha, Thread={0}", Thread::CurrentThread().ManagedThreadId);
    }
    
    static object lck;
  };
  
  object Program::lck;
}

pcf_startup (Examples::Program)

// This code produces the following output:
//