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
      class AssemblyCopyrightAttribute final : public Attribute {
      public:
        explicit AssemblyCopyrightAttribute(const string& copyright) : copyright(copyright) {}

        /// @cond
        /// Internal used only
        AssemblyCopyrightAttribute(const string& copyright, const object& executingAssembly);
        /// @endcond

        property_<string, readonly_> Copyright {
          get_ {return this->copyright;}
        };

      protected:
        $<object> GetTypeId() const override {return new_<System::Guid>(System::Guid::NewGuid());}

      private:
        string copyright;
      };
    }
  }
}

using namespace Switch;

/// @cond
$<System::Reflection::AssemblyCopyrightAttribute>& __assembly_copyright_attribute__();
/// @endcond

#define AssemblyCopyright_(copyright) \
  System::Reflection::AssemblyCopyrightAttribute __assemblyCopyrightAttribute {copyright, object()}
