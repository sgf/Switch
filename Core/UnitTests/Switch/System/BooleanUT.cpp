#include <Switch/System/Boolean.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class BooleanTest : public TestFixture {
  protected:
    void SetUp() override {}
    
    void TearDown() override {}
    
    void ConstructorDefault() {
      TUnit::Assert::IsFalse(Boolean(), sw_current_information);
    }
    
    void ConstructorWithFalse() {
      TUnit::Assert::IsFalse(Boolean(false), sw_current_information);
    }
    
    void ConstructorWithTrue() {
      TUnit::Assert::IsTrue(Boolean(true), sw_current_information);
    }
    
    void ConstructorWith0() {
      TUnit::Assert::IsFalse(Boolean(0), sw_current_information);
    }
    
    void ConstructorWith1() {
      TUnit::Assert::IsTrue(Boolean(1), sw_current_information);
    }
    
    void ConstructorWithBooleanFalse() {
      TUnit::Assert::IsFalse(Boolean(Boolean::False), sw_current_information);
    }
    
    void ConstructorWithBooleanTrue() {
      TUnit::Assert::IsTrue(Boolean(Boolean::True), sw_current_information);
    }
    
    void ConstructorByCopyWithBooleanFalse() {
      TUnit::Assert::IsFalse(Boolean(Boolean(false)), sw_current_information);
    }
    
    void ConstructorByCopyWithBooleanTrue() {
      TUnit::Assert::IsTrue(Boolean(Boolean(true)), sw_current_information);
    }
    
    void ParseBooleanFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse(Boolean::FalseString));
    }
    
    void ParseBooleanTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse(Boolean::TrueString));
    }
    
    void ParseFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("False"));
    }
    
    void ParseTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("True"));
    }
    
    void ParseTrailedWithSpaceFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("False     "));
    }
    
    void ParseTrailedWithSpaceTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("True       "));
    }
    
    void ParsePrecededWithSpaceFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("     False"));
    }
    
    void ParsePrecededWithSpaceTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("       True"));
    }
    
    void ParseLowerCaseFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("false"));
    }
    
    void ParseLowerCaseTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("true"));
    }
    
    void ParseUpperCaseFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("FALSE"));
    }
    
    void ParseUpperCaseTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("TRUE"));
    }
    
    void ParseAnyCaseFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("FaLsE"));
    }
    
    void ParseAnyCaseTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("tRuE"));
    }
    
    void ParseBadFormatFalseString() {
      TUnit::Assert::Throws<FormatException>(sw_delegate {Boolean::Parse("fal se");});
    }
    
    void ParseABadFormatTrueString() {
      TUnit::Assert::Throws<FormatException>(sw_delegate {Boolean::Parse("tru e");});
    }
    
    void ParseABadFormatString() {
      TUnit::Assert::Throws<FormatException>(sw_delegate {Boolean::Parse("Not true or false");});
    }
    
  };
  
  sw_test(BooleanTest, ConstructorDefault)
  sw_test(BooleanTest, ConstructorWithFalse)
  sw_test(BooleanTest, ConstructorWithTrue)
  sw_test(BooleanTest, ConstructorWith0)
  sw_test(BooleanTest, ConstructorWith1)
  sw_test(BooleanTest, ConstructorWithBooleanFalse)
  sw_test(BooleanTest, ConstructorWithBooleanTrue)
  sw_test(BooleanTest, ConstructorByCopyWithBooleanFalse)
  sw_test(BooleanTest, ConstructorByCopyWithBooleanTrue)
  sw_test(BooleanTest, ParseBooleanFalseString)
  sw_test(BooleanTest, ParseBooleanTrueString)
  sw_test(BooleanTest, ParseFalseString)
  sw_test(BooleanTest, ParseTrueString)
  sw_test(BooleanTest, ParseTrailedWithSpaceFalseString)
  sw_test(BooleanTest, ParseTrailedWithSpaceTrueString)
  sw_test(BooleanTest, ParsePrecededWithSpaceFalseString)
  sw_test(BooleanTest, ParsePrecededWithSpaceTrueString)
  sw_test(BooleanTest, ParseLowerCaseFalseString)
  sw_test(BooleanTest, ParseLowerCaseTrueString)
  sw_test(BooleanTest, ParseUpperCaseFalseString)
  sw_test(BooleanTest, ParseUpperCaseTrueString)
  sw_test(BooleanTest, ParseAnyCaseFalseString)
  sw_test(BooleanTest, ParseAnyCaseTrueString)
  sw_test(BooleanTest, ParseBadFormatFalseString)
  sw_test(BooleanTest, ParseABadFormatTrueString)
  sw_test(BooleanTest, ParseABadFormatString)
  
  TEST(Boolean, TryParse) {
    bool result;
    TUnit::Assert::IsTrue(Boolean::TryParse(Boolean::TrueString, result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse(Boolean::FalseString, result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("True", result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("False", result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("true", result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("false", result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("TRUE", result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("FALSE", result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("true      ", result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("    false", result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsFalse(Boolean::TryParse("Not true or false", result));    
  }
  
#if defined(_WIN32)
#pragma warning(push)
#pragma warning(disable:4305)
#endif

  TEST(Boolean, Equals) {
    TUnit::Assert::IsTrue(Boolean(true).Equals(Boolean(true)));
    TUnit::Assert::IsFalse(Boolean(true).Equals(Boolean(false)));
    TUnit::Assert::IsTrue(Boolean(false).Equals(Boolean(false)));
    TUnit::Assert::IsFalse(Boolean(false).Equals(Boolean(true)));
    
    TUnit::Assert::IsTrue(Boolean(false).Equals((const Object &)Boolean(false)));
    TUnit::Assert::IsFalse(Boolean(false).Equals((const Object &)Boolean(true)));
    TUnit::Assert::IsFalse(Boolean(false).Equals(int32(24)));    
  }

#if defined(_WIN32)
#pragma warning(pop)
#endif
  
  TEST(Boolean, GetHashCode) {
    TUnit::Assert::AreEqual(Boolean(true).GetHashCode(), int32(1));
    TUnit::Assert::AreEqual(Boolean(false).GetHashCode(), int32(0));
    
    Boolean bool1(true);
    object* obj = &bool1;
    TUnit::Assert::AreEqual(obj->GetHashCode(), int32(1));
    
    Boolean bool2(false);
    object* obj1 = &bool2;
    TUnit::Assert::AreEqual(obj1->GetHashCode(), int32(0));
  }
  
  TEST(Boolean, ToString) {
    TUnit::Assert::AreEqual("False", Boolean().ToString());
    TUnit::Assert::AreEqual("True", Boolean(true).ToString());
    TUnit::Assert::AreEqual("False", Boolean(false).ToString());
    TUnit::Assert::AreEqual("True", string(Boolean::TrueString));
    TUnit::Assert::AreEqual("False", string(Boolean::FalseString));
  }
  
  TEST(Boolean, CompareTo) {
    TUnit::Assert::LessOrEqual(Boolean(false).CompareTo(Boolean(true)), 0);
    TUnit::Assert::GreaterOrEqual(Boolean(true).CompareTo(Boolean(false)), 0);
    TUnit::Assert::AreEqual(Boolean(false).CompareTo(Boolean(false)), 0);
    TUnit::Assert::AreEqual(Boolean(true).CompareTo(Boolean(true)), 0);
    TUnit::Assert::AreEqual(Boolean(false).CompareTo((const IComparable&)Boolean(false)), 0);
    TUnit::Assert::AreEqual(Boolean(false).CompareTo(0), 0);
    TUnit::Assert::GreaterOrEqual(Boolean(true).CompareTo(0),0);    
  }
  
  TEST(Boolean,GetTypeCode) {
    TUnit::Assert::AreEqual(TypeCode::Boolean, Boolean().GetTypeCode());
  }
  
}