#include "../../../../include/Switch/System/Reflection/AssemblyCompanyAttribute.hpp"

using namespace System;
using namespace System::Reflection;

AssemblyCompanyAttribute::AssemblyCompanyAttribute(const string& company, const object& executingAssembly) : company(company) {
  __assembly_company_attribute__() = new_<System::Reflection::AssemblyCompanyAttribute>(company);
}

$<System::Reflection::AssemblyCompanyAttribute>& __assembly_company_attribute__() {
  static $<System::Reflection::AssemblyCompanyAttribute> company;
  return company;
}
