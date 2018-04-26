/// @file
/// @brief Contains Switch::System::Comparison delegate.
#pragma once

#include "../String.hpp"

/// @cond
$<string>& __assembly_company_attribute__();
$<string>& __assembly_configuration_attribute__();
$<string>& __assembly_copyright_attribute__();
$<string>& __assembly_culture_attribute__();
$<string>& __assembly_description_attribute__();
$<string>& __assembly_guid_attribute__();
$<string>& __assembly_identifier_attribute__();
$<string>& __assembly_product_attribute__();
$<string>& __assembly_version_attribute__();
$<string>& __assembly_title_attribute__();
$<string>& __assembly_trademark_attribute__();
struct __assembly_attribute__ {
  __assembly_attribute__(const string& attribute, const string& value);
};

class AssemblyCompanyAttribute final : public object {
public:
  AssemblyCompanyAttribute(const string& company) : company(company) {}

  property_<string, readonly_> Company {
    get_ {return this->company;}
  };

private:
  string company;
};
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System.Reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
    namespace Reflection {
      class AssemblyCompanyAttribute final : public object {
      public:
        AssemblyCompanyAttribute(const string& company) : company(company) {}

        property_<string, readonly_> Company {
          get_ {return this->company;}
        };

      private:
        string company;
      };

      class AssemblyConfigurationAttribute final : public object {
      public:
        AssemblyConfigurationAttribute(const string& configuration) : configuration(configuration) {}

        property_<string, readonly_> Configuration {
          get_ {return this->configuration;}
        };

      private:
        string configuration;
      };

      class AssemblyCopyrightAttribute final : public object {
      public:
        AssemblyCopyrightAttribute(const string& copyright) : copyright(copyright) {}

        property_<string, readonly_> Copyright {
          get_ {return this->copyright;}
        };

      private:
        string copyright;
      };
    }
  }
}

using namespace Switch;

#define AssemblyCompany_(company) \
  __assembly_attribute__ __assemblyCompanyAttribute {"company", company}

#define AssemblyConfiguration_(configuration) \
  __assembly_attribute__ __assemblyConfigurationAttribute {"configuration", configuration}

#define AssemblyCopyright_(copyright) \
  __assembly_attribute__ __assemblyCopyrightAttribute {"copyright", copyright}

#define AssemblyCulture_(culture) \
  __assembly_attribute__ __assemblyCultureAttribute {"culture", culture}

#define AssemblyDescription_(description) \
  __assembly_attribute__ __assemblyDescriptionAttribute {"description", description}

#define AssemblyGuid_(guid) \
  __assembly_attribute__ __assemblyGuidAttribute {"guid", guid}

#define AssemblyIdentifier_(identifier) \
  __assembly_attribute__ __assemblyIdentifierAttribute {"identifier", identifier}

#define AssemblyProduct_(product) \
  __assembly_attribute__ __assemblyProductAttribute {"product", product}

#define AssemblyVersion_(version) \
  __assembly_attribute__ __assemblyVersionAttribute {"version", version == "" || version == "*" ? SWITCH_APPLICATION_VERSION : version}

#define AssemblyTitle_(title) \
  __assembly_attribute__ __assemblyTitleAttribute {"title", title}

#define AssemblyTrademark_(trademark) \
  __assembly_attribute__ __assemblyTrademarkAttribute {"trademark", trademark}
