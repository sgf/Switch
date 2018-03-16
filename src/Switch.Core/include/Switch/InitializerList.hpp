/// @file
/// @brief Contains Switch::InitializerList <T> class.
#pragma once

#include <initializer_list>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @par Library
  /// Switch.Core
  template<typename T>
  using InitializerList = std::initializer_list<T>;
}

using namespace Switch;
