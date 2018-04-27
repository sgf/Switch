#include "../../../../include/Switch/System/Reflection/AssemblyGuidAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyGuidAttribute::AssemblyGuidAttribute(const string& guid, const object& executingAssembly) : guid(guid) {
  __assembly_guid_attribute__() = new_<System::Reflection::AssemblyGuidAttribute>(guid);
}

$<System::Reflection::AssemblyGuidAttribute>& __assembly_guid_attribute__() {
  static $<System::Reflection::AssemblyGuidAttribute> guid;
  return guid;
}
