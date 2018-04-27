#include "../../../../include/Switch/System/Reflection/AssemblyVersionAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyVersionAttribute::AssemblyVersionAttribute(const string& version, const object& executingAssembly) : version(version) {
  __assembly_version_attribute__() = new_<System::Reflection::AssemblyVersionAttribute>(version);
}

$<System::Reflection::AssemblyVersionAttribute>& __assembly_version_attribute__() {
  static $<System::Reflection::AssemblyVersionAttribute> version;
  return version;
}
