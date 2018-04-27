/// @file
/// @brief Contains Switch::System::Comparison delegate.
#pragma once

#include "../Attribute.hpp"
#include "../Guid.hpp"
#include "../String.hpp"

/// @cond
/// Internal used only
#if !defined(SWITCH_APPLICATION_VERSION)
#  if defined(SWITCH_LIBRARY_VERSION)
#    define SWITCH_APPLICATION_VERSION SWITCH_LIBRARY_VERSION
#  else
#    define SWITCH_APPLICATION_VERSION "1.0.0"
#  endif
#endif
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System.Reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
    namespace Reflection {
      class AssemblyVersionAttribute final : public Attribute {
      public:
        explicit AssemblyVersionAttribute(const string& version) : version(version) {}

        /// @cond
        /// Internal used only
        AssemblyVersionAttribute(const string& version, const object& executingAssembly);
        /// @endcond

        property_<string, readonly_> Version {
          get_ {return this->version;}
        };

      protected:
        $<object> GetTypeId() const override {return new_<System::Guid>(System::Guid::NewGuid());}

      private:
        string version;
      };
    }
  }
}

using namespace Switch;

/// @cond
$<System::Reflection::AssemblyVersionAttribute>& __assembly_version_attribute__();
/// @endcond

#define AssemblyVersion_(version) \
  System::Reflection::AssemblyVersionAttribute __assemblyVersionAttribute {version == "" || version == "*" ? SWITCH_APPLICATION_VERSION : version, object()}
