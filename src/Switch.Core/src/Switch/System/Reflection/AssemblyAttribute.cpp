#include "../../../../include/Switch/System/Reflection/AssemblyAttribute.hpp"

using namespace System;
using namespace System::Reflection;

$<string>& __assembly_company_attribute__() {
  static $<string> company;
  return company;
}

$<string>& __assembly_configuration_attribute__() {
  static $<string> configuration;
  return configuration;
}

$<string>& __assembly_copyright_attribute__() {
  static $<string> copyright;
  return copyright;
}

$<string>& __assembly_culture_attribute__() {
  static $<string> culture;
  return culture;
}

$<string>& __assembly_description_attribute__() {
  static $<string> description;
  return description;
}

$<string>& __assembly_guid_attribute__() {
  static $<string> guid;
  return guid;
}

$<string>& __assembly_identifier_attribute__() {
  static $<string> identifier;
  return identifier;
}

$<string>& __assembly_product_attribute__() {
  static $<string> product;
  return product;
}

$<string>& __assembly_version_attribute__() {
  static $<string> version;
  return version;
}

$<string>& __assembly_title_attribute__() {
  static $<string> title;
  return title;
}

$<string>& __assembly_trademark_attribute__() {
  static $<string> trademark;
  return trademark;
}

__assembly_attribute__::__assembly_attribute__(const string& attribute, const string& value) {
  if (attribute.ToLower() == "company") __assembly_company_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "configuration") __assembly_configuration_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "copyright") __assembly_copyright_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "culture") __assembly_culture_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "description") __assembly_description_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "guid") __assembly_guid_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "identifier") __assembly_identifier_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "product") __assembly_product_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "version") __assembly_version_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "title") __assembly_title_attribute__() = new_<string>(value);
  else if (attribute.ToLower() == "trademark") __assembly_trademark_attribute__() = new_<string>(value);
  else throw ArgumentException(caller_);
}
