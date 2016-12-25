/// @file
/// @brief Contains Pcf::System::Collections::IComparer interface.
#pragma once

#include "../../Any.h"
#include "Generic/IComparer.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief interface IComparer exposes a method that compares two objects.
      using IComparer = System::Collections::Generic::IComparer<Any>;
    }
  }
}

using namespace Pcf;
