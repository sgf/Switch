#include <Switch/Property.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(PropertyWriteOnlyTest, CreatePropertyAndSetItWithEqualOperator) {
    int32 v = 42;
    property_<int32, writeonly_> Value {
      set_ {v = value;}
    };

    Value = 24;
    ASSERT_EQ(24, v);
  }

  TEST(PropertyWriteOnlyTest, CreatePropertyAndSetItWithSetFunction) {
    int32 v = 42;
    property_<int32, writeonly_> Value {
      set_ {v = value;}
    };

    Value.Set(24);
    ASSERT_EQ(24, v);
  }

  TEST(PropertyWriteOnlyTest, CreatePropertyAndSetItWithFunctor) {
    int32 v = 42;
    property_<int32, writeonly_> Value {
      set_ {v = value;}
    };

    Value(24);
    ASSERT_EQ(24, v);
  }

  class PropertyWriteTestClass {
  public:
    PropertyWriteTestClass() {}
    PropertyWriteTestClass(const PropertyWriteTestClass& property) : name(property.name) {}

    property_<string, writeonly_> Name {
      set_ {this->name = value;}
    };

  public:
    string name = "Test property";
  };

  TEST(PropertyWriteOnlyTest, PropertyCopyConstructor) {
    refptr<PropertyWriteTestClass> p1 = new_<PropertyWriteTestClass>();
    refptr<PropertyWriteTestClass> p2 = new_<PropertyWriteTestClass>(*p1);
    p2->Name = "Other Value";
    p1 = null;
    ASSERT_EQ("Other Value", p2->name);
  }

  TEST(PropertyWriteOnlyTest, PropertyEqualOperator) {
    refptr<PropertyWriteTestClass> p1 = new_<PropertyWriteTestClass>();
    refptr<PropertyWriteTestClass> p2 = new_<PropertyWriteTestClass>();
    *p2 = *p1;
    p2->Name = "Other Value";
    p1 = null;
    ASSERT_EQ("Other Value", p2->name);
  }
}

