/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "RegisteredMethod.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      /// @par Library
      /// Switch.TUnit.Framework
      enum class TestState {
        Considered,
        Ignored
      };
    }
  }
}

using namespace Switch;
