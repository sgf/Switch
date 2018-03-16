/// @file
/// @brief Contains Switch::System::ArraySegment type.
#pragma once

#include "Array.hpp"

namespace Switch {
  namespace System {
    /// @brief Delimits a section of a one-dimensional array.
    /// @par Library
    /// Switch.Core
    /// @todo Write ArraySegment class.
    template<typename T, typename TAllocator = Allocator<T>>
    using ArraySegment = Array<T, 1, TAllocator>;
  }
}

using namespace Switch;
