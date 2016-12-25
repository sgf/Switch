/// @file
/// @brief Contains Pcf::Unused <> operator.
#pragma once

#include "Async.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief  It may be used to suppress the "unused variable" or "unused local typedefs" compiler warnings when the variable or typedef can't be removed or commented out, e.g. when some blocks of the code are conditionally activated.
  /// @param args variables to suppress the unsed warning
  ///
  /// This example sho how to use Unused():
  /// @include Unused.cpp
  template <typename ...Args>
  void Unused(Args&&... args) {}
}

using namespace Pcf;
