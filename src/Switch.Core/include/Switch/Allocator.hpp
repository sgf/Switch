/// @file
/// @brief Contains Switch::System::Allocator <T> class.
#pragma once

#include <cstddef>
#include <memory>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief This is the default Allocator used by all Switch library containers if no user-specified allocator is provided. The default allocator is stateless, that is, all instances of the given allocator are interchangeable, compare equal and can deallocate memory allocated by any other instance of the same allocator type.
  /// @par Library
  /// Switch.Core
  template<typename T>
  using Allocator = std::allocator<T>;
}

using namespace Switch;
