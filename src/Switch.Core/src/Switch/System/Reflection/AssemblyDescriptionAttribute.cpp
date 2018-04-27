#include "../../../../include/Switch/System/Reflection/AssemblyDescriptionAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyDescriptionAttribute::AssemblyDescriptionAttribute(const string& description, const object& executingAssembly) : description(description) {
  __assembly_description_attribute__() = new_<System::Reflection::AssemblyDescriptionAttribute>(description);
}

$<System::Reflection::AssemblyDescriptionAttribute>& __assembly_description_attribute__() {
  static $<System::Reflection::AssemblyDescriptionAttribute> description;
  return description;
}
