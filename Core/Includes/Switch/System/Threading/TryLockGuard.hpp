/// @file
/// @brief Contains Switch::System::Threading::TryLockGuard class.
#pragma once

#include "../Object.hpp"
#include "../TimeSpan.hpp"
#include "TimeOut.hpp"
#include "../../Types.hpp"
#include "../../Using.hpp"

/// @cond
namespace Switch {
  namespace System {
    namespace Threading {
      class sw_public TryLockGuard : public object {
      public:
        explicit TryLockGuard(const object& lock);
        TryLockGuard(const object& lock, int32 timeout);
        TryLockGuard(const object& lock, int64 timeout);
        TryLockGuard(const object& lock, const TimeSpan& timeout);
        ~TryLockGuard();
        
        Property<bool, ReadOnly> Result {
          sw_get {return this->result;}
        };
        
      private:
        TryLockGuard() = delete;
        TryLockGuard(const TryLockGuard&) = delete;
        TryLockGuard& operator =(const TryLockGuard&) = delete;

        const object& lock;
        bool result = false;
      };
    }
  }
}
/// @endcond

using namespace Switch;