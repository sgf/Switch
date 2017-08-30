/// @file
/// @brief Contains Switch::System::ICloneable interface.
#pragma once

#include "../Interface.hpp"
#include "../Types.hpp"
#include "../RefPtr.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class Object;
    /// @endcond
    
    /// @interface ICloneable
    /// @brief Supports cloning, which creates a new instance of a class with the same value as an existing instance.
    class sw_public ICloneable sw_interface {
    public:
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return object A new object that is a copy of this instance.
      virtual refptr<Object> Clone() const = 0;
    };
  }
}

using namespace Switch;
