#include "../../../../include/Switch/System/Reflection/AssemblyIdentifierAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyIdentifierAttribute::AssemblyIdentifierAttribute(const string& identifier, const object& executingAssembly) : identifier(identifier) {
  __assembly_identifier_attribute__() = new_<System::Reflection::AssemblyIdentifierAttribute>(identifier);
}

$<System::Reflection::AssemblyIdentifierAttribute>& __assembly_identifier_attribute__() {
  static $<System::Reflection::AssemblyIdentifierAttribute> identifier;
  return identifier;
}
