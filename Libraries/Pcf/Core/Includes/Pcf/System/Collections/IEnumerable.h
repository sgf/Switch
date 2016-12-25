/// @file
/// @brief Contains Pcf::System::Collections::IEnumerable interface.
#pragma once

#include "../../Any.h"
#include "IEnumerator.h"
#include "Generic/IEnumerable.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Exposes the enumerator, which supports a simple iteration over a non-generic collection.
      using IEnumerable = System::Collections::Generic::IEnumerable<Any>;
    }
  }
}

using namespace Pcf;
