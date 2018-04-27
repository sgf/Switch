#include "../../../../include/Switch/System/Reflection/AssemblyConfigurationAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyConfigurationAttribute::AssemblyConfigurationAttribute(const string& configuration, const object& executingAssembly) : configuration(configuration) {
  __assembly_configuration_attribute__() = new_<System::Reflection::AssemblyConfigurationAttribute>(configuration);
}

$<System::Reflection::AssemblyConfigurationAttribute>& __assembly_configuration_attribute__() {
  static $<System::Reflection::AssemblyConfigurationAttribute> configuration;
  return configuration;
}
