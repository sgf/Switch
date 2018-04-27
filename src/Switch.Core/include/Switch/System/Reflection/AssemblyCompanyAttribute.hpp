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
      class AssemblyCompanyAttribute final : public Attribute {
      public:
        explicit AssemblyCompanyAttribute(const string& company) : company(company) {}

        /// @cond
        /// Internal used only
        AssemblyCompanyAttribute(const string& value, const object& executingAssembly);
        /// @endcond

        property_<string, readonly_> Company {
          get_ {return this->company;}
        };

      protected:
        $<object> GetTypeId() const override {return new_<System::Guid>(System::Guid::NewGuid());}

      private:
        string company;
      };
    }
  }
}

using namespace Switch;

/// @cond
$<System::Reflection::AssemblyCompanyAttribute>& __assembly_company_attribute__();
/// @endcond

#define AssemblyCompany_(company) \
  System::Reflection::AssemblyCompanyAttribute __assemblyCompanyAttribute {company, object()}
