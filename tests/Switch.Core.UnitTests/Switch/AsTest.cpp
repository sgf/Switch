#include <Switch/Any.hpp>
#include <Switch/As.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(AsTest, StringAsString) {
    string s = "Test";
    string& r = as<string>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, StringAsObject) {
    string s = "Test";
    object& r = as<object>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, StringAsIComparable) {
    string s = "Test";
    IComparable& r = as<IComparable>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, StringAsInt32) {
    string s = "Test";
    ASSERT_THROW(as<Int32>(s), InvalidCastException);
  }

  TEST(AsTest, ObjectFromStringAsString) {
    string s = "Test";
    object& o = s;
    string& r = as<string>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, ObjectFromStringAsObject) {
    string s = "Test";
    object& o = s;
    object& r = as<object>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, ObjectFromStringAsIComparable) {
    string s = "Test";
    object& o = s;
    IComparable& r = as<IComparable>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }


  TEST(AsTest, ObjectFromStringAsInt32) {
    string s = "Test";
    object& o = s;
    ASSERT_THROW(as<Int32>(o), InvalidCastException);
  }

  TEST(AsTest, ConstStringAsString) {
    const string s = "Test";
    const string& r = as<string>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, ConstStringAsObject) {
    const string s = "Test";
    const object& r = as<object>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, ConstStringAsIComparable) {
    const string s = "Test";
    const IComparable& r = as<IComparable>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, ConstStringAsInt32) {
    const string s = "Test";
    ASSERT_THROW(as<Int32>(s), InvalidCastException);
  }

  TEST(AsTest, ConstObjectFromStringAsString) {
    const string s = "Test";
    const object& o = s;
    const string& r = as<string>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, ConstObjectFromConstStringAsObject) {
    const string s = "Test";
    const object& o = s;
    const object& r = as<object>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, ConstObjectFromConstStringAsIComparable) {
    const string s = "Test";
    const object& o = s;
    const IComparable& r = as<IComparable>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }

  TEST(AsTest, ConstObjectFromConstStringAsInt32) {
    const string s = "Test";
    const object& o = s;
    ASSERT_THROW(as<Int32>(o), InvalidCastException);
  }

  TEST(AsTest, StringPtrAsString) {
    string str = "test";
    string* s = &str;
    string* r = as<string>(s);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, StringPtrAsObject) {
    string str = "test";
    string* s = &str;
    object* r = as<object>(s);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, StringPtrAsIComparable) {
    string str = "test";
    string* s = &str;
    IComparable* r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, StringPtrAsInt32) {
    string str = "test";
    string* s = &str;
    ASSERT_THROW(as<Int32>(s), InvalidCastException);
  }

  TEST(AsTest, ObjectPtrFromStringPtrAsString) {
    string str = "test";
    string* s = &str;
    object* o = s;
    string* r = as<string>(o);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, ObjectPtrFromStringPtrAsObject) {
    string str = "test";
    string* s = &str;
    object* o = s;
    object* r = as<object>(o);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, ObjectPtrFromStringPtrAsIComparable) {
    string str = "test";
    string* s = &str;
    object* o = s;
    IComparable* r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, ObjectPtrFromStringPtrAsInt32) {
    string str = "test";
    string* s = &str;
    object* o = s;
    ASSERT_THROW(as<Int32>(o), InvalidCastException);
  }

  TEST(AsTest, StringPtrNullAsString) {
    string* s = null;
    string* r = as<string>(s);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, StringPtrNullAsObject) {
    string* s = null;
    object* r = as<object>(s);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, StringPtrNullAsIComparable) {
    string* s = null;
    IComparable* r = as<IComparable>(s);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, StringPtrNullAsInt32) {
    string* s = null;
    IComparable* r = as<Int32>(s);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ObjectPtrFromStringPtrNullAsString) {
    string* s = null;
    object* o = s;
    string* r = as<string>(o);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ObjectPtrFromStringPtrNullAsObject) {
    string* s = null;
    object* o = s;
    object* r = as<object>(o);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ObjectPtrFromStringPtrNullAsIComparable) {
    string* s = null;
    object* o = s;
    IComparable* r = as<IComparable>(o);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ObjectPtrFromStringPtrNullAsInt32) {
    string* s = null;
    object* o = s;
    Int32* r = as<Int32>(o);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ConstStringPtrAsString) {
    string str = "test";
    const string* s = &str;
    const string* r = as<string>(s);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, ConstStringPtrAsObject) {
    string str = "test";
    const string* s = &str;
    const object* r = as<object>(s);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, ConstStringPtrAsIComparable) {
    string str = "test";
    const string* s = &str;
    const IComparable* r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, ConstStringPtrAsInt32) {
    string str = "test";
    const string* s = &str;
    ASSERT_THROW(as<Int32>(s), InvalidCastException);
  }

  TEST(AsTest, ConstObjectPtrFromStringPtrAsString) {
    string str = "test";
    const string* s = &str;
    const object* o = s;
    const string* r = as<string>(o);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, ConstObjectPtrFromStringPtrAsObject) {
    string str = "test";
    const string* s = &str;
    const object* o = s;
    const object* r = as<object>(o);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, ConstObjectPtrFromStringPtrAsIComparable) {
    string str = "test";
    const string* s = &str;
    const object* o = s;
    const IComparable* r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s, r);
  }

  TEST(AsTest, ConstObjectPtrFromStringPtrAsInt32) {
    string str = "test";
    const string* s = &str;
    const object* o = s;
    ASSERT_THROW(as<Int32>(o), InvalidCastException);
  }

  TEST(AsTest, ConstStringPtrNullAsString) {
    const string* s = null;
    const string* r = as<string>(s);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ConstStringPtrNullAsObject) {
    const string* s = null;
    const object* r = as<object>(s);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ConstStringPtrNullAsIComparable) {
    const string* s = null;
    const IComparable* r = as<IComparable>(s);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ConstStringPtrNullAsInt32) {
    const string* s = null;
    const Int32* r = as<Int32>(s);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ConstObjectPtrFromStringPtrNullAsString) {
    const string* s = null;
    const object* o = s;
    const string* r = as<string>(o);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ConstObjectPtrFromStringPtrNullAsObject) {
    const string* s = null;
    const object* o = s;
    const object* r = as<object>(o);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ConstObjectPtrFromStringPtrNullAsIComparable) {
    const string* s = null;
    const object* o = s;
    const IComparable* r = as<IComparable>(o);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, ConstObjectPtrFromStringPtrNullAsInt32) {
    const string* s = null;
    const object* o = s;
    const Int32* r = as<Int32>(o);
    ASSERT_EQ(null, r);
  }

  TEST(AsTest, RefPtrStringAsString) {
    $<string> s = new_<string>("Test");
    $<string> r = as<string>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefPtrStringAsObject) {
    $<string> s = new_<string>("Test");
    $<object> r = as<object>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefPtrStringAsIComparable) {
    $<string> s = new_<string>("Test");
    $<IComparable> r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefPtrStringAsInt32) {
    $<string> s = new_<string>("Test");
    $<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefPtrObjectFromStringAsString) {
    $<string> s = new_<string>("Test");
    $<object> o = as<object>(s);
    $<string> r = as<string>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefPtrObjectFromStringAsObject) {
    $<string> s = new_<string>("Test");
    $<object> o = as<object>(s);
    $<object> r = as<object>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefPtrObjectFromStringAsIComparable) {
    $<string> s = new_<string>("Test");
    $<object> o = as<object>(s);
    $<IComparable> r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefPtrObjectFromStringAsInt32) {
    $<string> s = new_<string>("Test");
    $<object> o = as<object>(s);
    $<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefPtrStringNullAsString) {
    $<string> s = $<string>::Null();
    $<string> r = as<string>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefPtrStringNullAsObject) {
    $<string> s = $<string>::Null();
    $<object> r = as<object>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefPtrStringNullAsIComparable) {
    $<string> s = $<string>::Null();
    $<IComparable> r = as<IComparable>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefPtrStringNullAsInt32) {
    $<string> s = $<string>::Null();
    $<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefPtrObjectFromStringNullAsString) {
    $<string> s = $<string>::Null();
    $<object> o = as<object>(s);
    $<string> r = as<string>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefPtrObjectFromStringNullAsObject) {
    $<string> s = $<string>::Null();
    $<object> o = as<object>(s);
    $<object> r = as<object>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefPtrObjectFromStringNullAsIComparable) {
    $<string> s = $<string>::Null();
    $<object> o = as<object>(s);
    $<IComparable> r = as<IComparable>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefPtrObjectFromStringNullAsInt32) {
    $<string> s = $<string>::Null();
    $<object> o = as<object>(s);
    $<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpStringAsString) {
    const $<string> s = new_<string>("Test");
    const $<string> r = as<string>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstSpStringAsObject) {
    const $<string> s = new_<string>("Test");
    const $<object> r = as<object>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstSpStringAsIComparable) {
    const $<string> s = new_<string>("Test");
    const $<IComparable> r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstSpStringAsInt32) {
    const $<string> s = new_<string>("Test");
    const $<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpObjectFromStringAsString) {
    const $<string> s = new_<string>("Test");
    const $<object> o = as<object>(s);
    const $<string> r = as<string>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstSpObjectFromStringAsObject) {
    const $<string> s = new_<string>("Test");
    const $<object> o = as<object>(s);
    const $<object> r = as<object>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstSpObjectFromStringAsIComparable) {
    const $<string> s = new_<string>("Test");
    const $<object> o = as<object>(s);
    const $<IComparable> r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstSpObjectFromStringAsInt32) {
    const $<string> s = new_<string>("Test");
    const $<object> o = as<object>(s);
    const $<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpStringNullAsString) {
    const $<string> s = $<string>::Null();
    const $<string> r = as<string>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpStringNullAsObject) {
    const $<string> s = $<string>::Null();
    const $<object> r = as<object>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpStringNullAsIComparable) {
    const $<string> s = $<string>::Null();
    const $<IComparable> r = as<IComparable>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpStringNullAsInt32) {
    const $<string> s = $<string>::Null();
    const $<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpObjectFromStringNullAsString) {
    const $<string> s = $<string>::Null();
    const $<object> o = as<object>(s);
    const $<string> r = as<string>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpObjectFromStringNullAsObject) {
    const $<string> s = $<string>::Null();
    const $<object> o = as<object>(s);
    const $<object> r = as<object>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpObjectFromStringNullAsIComparable) {
    const $<string> s = $<string>::Null();
    const $<object> o = as<object>(s);
    const $<IComparable> r = as<IComparable>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstSpObjectFromStringNullAsInt32) {
    const $<string> s = $<string>::Null();
    const $<object> o = as<object>(s);
    const $<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefStringAsString) {
    string str = "Test";
    ref<string> s = str;
    ref<string> r = as<string>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefStringAsObject) {
    string str = "Test";
    ref<string> s = str;
    ref<object> r = as<object>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefStringAsIComparable) {
    string str = "Test";
    ref<string> s = str;
    ref<IComparable> r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefStringAsInt32) {
    string str = "Test";
    ref<string> s = str;
    ref<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefObjectFromStringAsString) {
    string str = "Test";
    ref<string> s = str;
    ref<object> o = as<object>(s);
    ref<string> r = as<string>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefObjectFromStringAsObject) {
    string str = "Test";
    ref<string> s = str;
    ref<object> o = as<object>(s);
    ref<object> r = as<object>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefObjectFromStringAsIComparable) {
    string str = "Test";
    ref<string> s = str;
    ref<object> o = as<object>(s);
    ref<IComparable> r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, RefObjectFromStringAsInt32) {
    string str = "Test";
    ref<string> s = str;
    ref<object> o = as<object>(s);
    ref<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefStringNullAsString) {
    ref<string> s = ref<string>::Null();
    ref<string> r = as<string>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefStringNullAsObject) {
    ref<string> s = ref<string>::Null();
    ref<object> r = as<object>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefStringNullAsIComparable) {
    ref<string> s = ref<string>::Null();
    ref<IComparable> r = as<IComparable>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefStringNullAsInt32) {
    ref<string> s = ref<string>::Null();
    ref<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefObjectFromStringNullAsString) {
    ref<string> s = ref<string>::Null();
    ref<object> o = as<object>(s);
    ref<string> r = as<string>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefObjectFromStringNullAsObject) {
    ref<string> s = ref<string>::Null();
    ref<object> o = as<object>(s);
    ref<object> r = as<object>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefObjectFromStringNullAsIComparable) {
    ref<string> s = ref<string>::Null();
    ref<object> o = as<object>(s);
    ref<IComparable> r = as<IComparable>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, RefObjectFromStringNullAsInt32) {
    ref<string> s = ref<string>::Null();
    ref<object> o = as<object>(s);
    ref<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefStringAsString) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<string> r = as<string>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstRefStringAsObject) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> r = as<object>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstRefStringAsIComparable) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<IComparable> r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstRefStringAsInt32) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefObjectFromStringAsString) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> o = as<object>(s);
    const ref<string> r = as<string>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstRefObjectFromStringAsObject) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> o = as<object>(s);
    const ref<object> r = as<object>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstRefObjectFromStringAsIComparable) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> o = as<object>(s);
    const ref<IComparable> r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }

  TEST(AsTest, ConstRefObjectFromStringAsInt32) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> o = as<object>(s);
    const ref<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefStringNullAsString) {
    const ref<string> s = ref<string>::Null();
    const ref<string> r = as<string>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefStringNullAsObject) {
    const ref<string> s = ref<string>::Null();
    const ref<object> r = as<object>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefStringNullAsIComparable) {
    const ref<string> s = ref<string>::Null();
    const ref<IComparable> r = as<IComparable>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefStringNullAsInt32) {
    const ref<string> s = ref<string>::Null();
    const ref<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefObjectFromStringNullAsString) {
    const ref<string> s = ref<string>::Null();
    const ref<object> o = as<object>(s);
    const ref<string> r = as<string>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefObjectFromStringNullAsObject) {
    const ref<string> s = ref<string>::Null();
    const ref<object> o = as<object>(s);
    const ref<object> r = as<object>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefObjectFromStringNullAsIComparable) {
    const ref<string> s = ref<string>::Null();
    const ref<object> o = as<object>(s);
    const ref<IComparable> r = as<IComparable>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, ConstRefObjectFromStringNullAsInt32) {
    const ref<string> s = ref<string>::Null();
    const ref<object> o = as<object>(s);
    const ref<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }

  TEST(AsTest, AnyInt32ToInt32) {
    Any a = 42;
    int32 b = as<Int32>(a);
    GTEST_ASSERT_EQ(42, b);
  }

  TEST(AsTest, AnyInt32ToString) {
    Any a = 42;
    string b = a.ToString();
    GTEST_ASSERT_EQ("42", b);
  }

  TEST(AsTest, Int32DifferentOfZeroAsBool) {
    int32 a = 42;
    bool b = as<bool>(a);
    ASSERT_TRUE(b);
  }

  TEST(AsTest, Int32EqualsToZeroAsBool) {
    int32 a = 0;
    bool b = as<bool>(a);
    ASSERT_FALSE(b);
  }

  TEST(AsTest, Int32AsByte) {
    int32 a = 42;
    byte b = as<byte>(a);
    GTEST_ASSERT_EQ(42, b);
  }

  TEST(AsTest, Int32AsString) {
    int32 a = 42;
    string b = as<string>(a);
    GTEST_ASSERT_EQ("42", b);
  }
}
