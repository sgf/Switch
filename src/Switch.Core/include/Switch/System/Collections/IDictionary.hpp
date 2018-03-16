/// @file
/// @brief Contains Switch::System::Collections::IDictionary interface.
#pragma once

#include "../../Any.hpp"
#include "ICollection.hpp"
#include "Generic/IDictionary.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Represents a nongeneric collection of key/value pairs
      /// @par Library
      /// Switch.Core
      using IDictionary = System::Collections::Generic::IDictionary<Any, Any>;
    }
  }
}

using namespace Switch;
