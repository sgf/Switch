#include "../../../../include/Switch/System/Reflection/AssemblyProductAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyProductAttribute::AssemblyProductAttribute(const string& product, const object& executingAssembly) : product(product) {
  __assembly_product_attribute__() = new_<System::Reflection::AssemblyProductAttribute>(product);
}

$<System::Reflection::AssemblyProductAttribute>& __assembly_product_attribute__() {
  static $<System::Reflection::AssemblyProductAttribute> product;
  return product;
}
