/// @file
/// @brief Contains Pcf::System::Threading::LockGuard class.
#pragma once

#include "../Object.h"
#include "../../Using.h"

namespace Pcf {
  namespace System {
    namespace Threading {
      /// @cond
      class LockGuard : public object {
      public:
        explicit LockGuard(const object& lock);
        ~LockGuard();
        
      private:
        LockGuard() = delete;
        LockGuard(const LockGuard&) = delete;
        LockGuard& operator =(const LockGuard&) = delete;

        const object& lock;
      };
      /// @endcond
    }
  }
}

using namespace Pcf;
