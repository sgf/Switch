#include <Switch/Switch>

namespace Examples {
  class Program {
  public:
    static void Main() {
      object lock;

      // The first way : easy with Switch keyword :
      lock_(lock) {
        System::Console::WriteLine("Run in threadsafe mode...");
      }

      // The second way : with Switch Monitor :
      System::Threading::Monitor::Enter(lock);
      try {
        System::Console::WriteLine("Run in threadsafe mode...");
        System::Threading::Monitor::Exit(lock);
      } catch (...) {
        System::Threading::Monitor::Exit(lock);
      }

      // The third way : with your own Lockguard object :
      struct LockGuard {
        explicit LockGuard(const object& lock) : lock(lock) {System::Threading::Monitor::Enter(this->lock);}
        ~LockGuard() {System::Threading::Monitor::Exit(this->lock);}
        LockGuard() = delete;
        LockGuard(const LockGuard&) = delete;
        LockGuard& operator=(const LockGuard&) = delete;
      private:
        const object lock;
      };

      {
        LockGuard lockGuard(lock);
        System::Console::WriteLine("Run in threadsafe mode...");
      }

    }
  };
}

startup_(Examples::Program);
