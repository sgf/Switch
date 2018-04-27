#include "../../../../include/Switch/System/Reflection/AssemblyCopyrightAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyCopyrightAttribute::AssemblyCopyrightAttribute(const string& copyright, const object& executingAssembly) : copyright(copyright) {
  __assembly_copyright_attribute__() = new_<System::Reflection::AssemblyCopyrightAttribute>(copyright);
}

$<System::Reflection::AssemblyCopyrightAttribute>& __assembly_copyright_attribute__() {
  static $<System::Reflection::AssemblyCopyrightAttribute> copyright;
  return copyright;
}
