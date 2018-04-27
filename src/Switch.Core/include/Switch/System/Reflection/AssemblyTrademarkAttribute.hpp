/// @file
/// @brief Contains Switch::System::Comparison delegate.
#pragma once

#include "../Attribute.hpp"
#include "../Guid.hpp"
#include "../String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System.Reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
    namespace Reflection {
      class AssemblyTrademarkAttribute final : public Attribute {
      public:
        explicit AssemblyTrademarkAttribute(const string& trademark) : trademark(trademark) {}

        /// @cond
        /// Internal used only
        AssemblyTrademarkAttribute(const string& trademark, const object& executingAssembly);
        /// @endcond

        property_<string, readonly_> Trademark {
          get_ {return this->trademark;}
        };

      protected:
        $<object> GetTypeId() const override {return new_<System::Guid>(System::Guid::NewGuid());}

      private:
        string trademark;
      };
    }
  }
}

using namespace Switch;

/// @cond
$<System::Reflection::AssemblyTrademarkAttribute>& __assembly_trademark_attribute__();
/// @endcond

#define AssemblyTrademark_(trademark) \
  System::Reflection::AssemblyTrademarkAttribute __assemblyTrademarkAttribute {trademark, object()}
