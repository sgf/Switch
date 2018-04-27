#include "../../../../include/Switch/System/Reflection/AssemblyTrademarkAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyTrademarkAttribute::AssemblyTrademarkAttribute(const string& trademark, const object& executingAssembly) : trademark(trademark) {
  __assembly_trademark_attribute__() = new_<System::Reflection::AssemblyTrademarkAttribute>(trademark);
}

$<System::Reflection::AssemblyTrademarkAttribute>& __assembly_trademark_attribute__() {
  static $<System::Reflection::AssemblyTrademarkAttribute> trademark;
  return trademark;
}
