#include <Switch/Abstract.hpp>
#include <Switch/RefPtr.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(AbstractTest, CreateClassNotInheritedFromAnAbstract) {
    static string result;
    result = "";
    struct NotAnAbstract {
      ~NotAnAbstract() {result += "~NotAnAbstract";}
    };

    struct NotInheritedFromAnAbstract : public NotAnAbstract {
      ~NotInheritedFromAnAbstract() {result += "~NotInheritedFromAnAbstract";}
    };

    using_($<NotAnAbstract> value = new_<NotInheritedFromAnAbstract>());
    GTEST_ASSERT_EQ("~NotAnAbstract", result);
  }

  TEST(AbstractTest, CreateClassInheritedFromAnAbstract) {
    static string result;
    result = "";
    struct AnAbstract abstract_ {
      ~AnAbstract() {result += "~AnAbstract";}
    };

    struct InheritedFromAnAbstract : public AnAbstract {
      ~InheritedFromAnAbstract() {result += "~InheritedFromAnAbstract";}
    };

    using_($<AnAbstract> value = new_<InheritedFromAnAbstract>());
    GTEST_ASSERT_EQ("~InheritedFromAnAbstract~AnAbstract", result);
  }
}
