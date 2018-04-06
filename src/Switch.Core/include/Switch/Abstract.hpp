/// @file
/// @brief Contains #abstract_ keyword.
#pragma once

#include "System/Object.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent an abstract class.
  /// @par Library
  /// Switch.Core
  struct core_export_ Abstract : public System::Object {
  protected:
    Abstract() {}
  public:
    ~Abstract() override = 0;
  };

  /// @brief This keyword is used to represents an abstract class.
  /// @par Examples
  /// @include Abstract.cpp
  /// @ingroup Keywords
#define abstract_ \
: public Abstract
}

using namespace Switch;
