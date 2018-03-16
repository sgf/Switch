/// @file
/// @brief Contains Switch::TUnit::Is class.
#pragma once

#include "Constraints/Empty.hpp"
#include "Constraints/EqualTo.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  namespace TUnit {
    namespace Is {
      /// @par Library
      /// Switch.TUnit.Core
      using EqualTo = Constraints::EqualTo;

      /// @par Library
      /// Switch.TUnit.Core
      using Empty = Constraints::Empty;
    }
  }
}

using namespace Switch;

