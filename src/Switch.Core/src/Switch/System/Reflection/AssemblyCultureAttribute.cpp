#include "../../../../include/Switch/System/Reflection/AssemblyCultutreAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyCultureAttribute::AssemblyCultureAttribute(const string& culture, const object& executingAssembly) : culture(culture) {
  __assembly_culture_attribute__() = new_<System::Reflection::AssemblyCultureAttribute>(culture);
}

$<System::Reflection::AssemblyCultureAttribute>& __assembly_culture_attribute__() {
  static $<System::Reflection::AssemblyCultureAttribute> culture;
  return culture;
}
