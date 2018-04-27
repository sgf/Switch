/// @file
/// @brief Contains Switch::System::Comparison delegate.
#pragma once

#include "Guid.hpp"
#include "String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents the base class for custom attributes.
    class Attribute : public object {
    public:
      /// @brief When implemented in a derived class, gets a unique identifier for this Attribute.
      /// @remarks As implemented, this identifier is merely the Type of the attribute. However, it is intended that the unique identifier be used to identify two attributes of the same type.
      property_ < $<object>, readonly_ > TypeId {
        get_ {return this->GetTypeId();}
      };

    protected:
      /// @brief Initializes a new instance of the Attribute class.
      /// @remarks This constructor is only called by classes that derive from Attribute.
      Attribute() {}

      /// @brief When implemented in a derived class, gets a unique identifier for this Attribute.
      /// @remarks As implemented, this identifier is merely the Type of the attribute. However, it is intended that the unique identifier be used to identify two attributes of the same type.
      virtual $<object> GetTypeId() const = 0;
    };
  }
}

using namespace Switch;
