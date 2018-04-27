#include "../../../../include/Switch/System/Reflection/AssemblyTitleAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyTitleAttribute::AssemblyTitleAttribute(const string& title, const object& executingAssembly) : title(title) {
  __assembly_title_attribute__() = new_<System::Reflection::AssemblyTitleAttribute>(title);
}

$<System::Reflection::AssemblyTitleAttribute>& __assembly_title_attribute__() {
  static $<System::Reflection::AssemblyTitleAttribute> title;
  return title;
}
