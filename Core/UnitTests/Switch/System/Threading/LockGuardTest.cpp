#include <Switch/Lock.hpp>
#include <Switch/System/Diagnostics/Stopwatch.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading;
using namespace System::Diagnostics;
using namespace TUnit;

namespace SwitchUnitTests {
  class LockGuardTest : public TestFixture {
  protected:
    void SingleLock() {
      int value = 0;
      object lock;
      
      LockGuard lockGuard(lock);
      ++value;
      
      Assert::AreEqual(1, value, _current_information);
    }
    
    void DoubleLockOnDifferentObjects() {
      int value = 0;
      object lock;
      object lock2;
      
      LockGuard lockGuard(lock);
      ++value;
      LockGuard lockGuard2(lock2);
      ++value;
      
      Assert::AreEqual(2, value, _current_information);
    }
    
    void DoubleLockOnSameObject() {
      int value = 0;
      object lock;
      
      LockGuard lockGuard(lock);
      ++value;
      LockGuard lockGuard2(lock);
      ++value;
      
      Assert::AreEqual(2, value, _current_information);
    }
    
    void LockDuration() {
      object lock;
      int value = 0;
      Stopwatch duration = Stopwatch::StartNew();
      {
        LockGuard lockGuard(lock);
        ++value;
      }
      duration.Stop();
      Assert::LessOrEqual(duration.ElapsedMilliseconds(), 1, _current_information);
    }
 
    void Thread() {
      string s;
      std::thread t1(_delegate {
        LockGuard lockGuard(s);
        for (int i = 0; i < 500; i++)
          s += '1';
      });
      std::thread t2(_delegate {
        LockGuard lockGuard(s);
        for (int i = 0; i < 500; i++)
          s += '2';
      });
      
      if (t1.joinable())
        t1.join();
      if (t2.joinable())
        t2.join();
      
      char32 o = 0;
      int32 i = 0;
      for (char32 c : s) {
        if (o == 0) o = c;
        Assert::IsFalse(++i < 500 && o != c, _current_information);
      }
    }
  };
  
  _test(LockGuardTest, SingleLock)
  _test(LockGuardTest, DoubleLockOnDifferentObjects)
  _test(LockGuardTest, DoubleLockOnSameObject)
  _test(LockGuardTest, LockDuration)
  _test(LockGuardTest, Thread)
}
