#include <Switch/System/Text/StringBuilder.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Text;
using namespace TUnit;

namespace SwitchUnitTests {
  class StringBuilderTest : public TestFixture {
  protected:
    void DefaultConstructor() {
      StringBuilder sb;
      Assert::AreEqual(0, sb.Length(), sw_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 16, sw_current_information);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), sw_current_information);
      Assert::AreEqual("", sb.ToString(), sw_current_information);
    }
    
    void ConstructorWithCapacity() {
      StringBuilder sb(1000);
      Assert::AreEqual(0, sb.Length(), sw_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 1000, sw_current_information);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), sw_current_information);
      Assert::AreEqual("", sb.ToString(), sw_current_information);
    }
    
    void ConstructorWithCapacityLesserThanZero() {
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {StringBuilder sb(-1);}, sw_current_information);
    }
    
    void ConstructorWithCapacityAndMaxCapacity() {
      StringBuilder sb(1000, 2000);
      Assert::AreEqual(0, sb.Length(), sw_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 1000, sw_current_information);
      Assert::AreEqual(2000, sb.MaxCapacity(), sw_current_information);
      Assert::AreEqual("", sb.ToString(), sw_current_information);
    }
    
    void ConstructorWithCapacityLesserThanZeroAndMaxCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {StringBuilder sb(1000, 500);}, sw_current_information);
    }
    
    void ConstructorWithCapacityAndMaxCapacityLesserThanOne() {
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {StringBuilder sb(0, 0);}, sw_current_information);
    }
    
    void ConstructorWithCapacityAndMaxCapacityLesserThanCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {StringBuilder sb(1000, 500);}, sw_current_information);
    }
    
    void ConstructorString() {
      Assert::AreEqual("Hello StringBuilder", StringBuilder(String("Hello StringBuilder")).ToString(), sw_current_information);
      Assert::AreEqual("Goodbye", StringBuilder("Goodbye").ToString(), sw_current_information);
    }
    
    void ConstructorStringAndCapacity() {
      StringBuilder sb(String("Hello StringBuilder"), 255);
      Assert::AreEqual("Hello StringBuilder", sb.ToString(), sw_current_information);
      Assert::GreaterOrEqual(sb.Capacity, 255, sw_current_information);
    }
    
    void ConstructorWithStringStartIndexLengthAndCapacity() {
      StringBuilder sb("Hello there", 0, 4, 255);
      Assert::AreEqual("Hell", sb.ToString(), sw_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 255, sw_current_information);
    }
    
    void ConstructorWithStringStartIndexEqualZeroLengthEqualZeroAndCapacity() {
      StringBuilder sb("Hello there", 0, 0, 255);
      Assert::AreEqual("", sb.ToString(), sw_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 255, sw_current_information);
    }
    
    void ConstructorWithStringEmptyStartIndexEqualZeroLengthEqualZeroAndCapacity() {
      Assert::AreEqual("", StringBuilder("", 0, 0, 255).ToString(), sw_current_information);
    }
    
    void ConstructorWithStringStartIndexEqualZeroLengthLesserThanZeroAndCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {StringBuilder sb("Hello", 0, -1, 255);}, sw_current_information);
    }
    
    void ConstructorWithStringStartIndexLesserThanZeroLengthLEqualZeroAndCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {StringBuilder sb("Hello", -1, 0, 255);}, sw_current_information);
    }
    
    void ConstructorWithStringStartIndexEqualZeroLengthAboveStringLengthAndCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {StringBuilder sb("Hello", 0, 6, 255);}, sw_current_information);
    }
    
    void GetCapacity() {
      Assert::GreaterOrEqual(StringBuilder("").Capacity(), 16, sw_current_information);
      Assert::GreaterOrEqual(StringBuilder("Hello").Capacity(), 16, sw_current_information);
      Assert::GreaterOrEqual(StringBuilder(1000).Capacity(), 1000, sw_current_information);
    }
    
    void SetCapacity() {
      StringBuilder sb;
      sb.Capacity = 200;
      Assert::AreEqual(0, sb.Length(), sw_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 200, sw_current_information);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), sw_current_information);
    }
    
    void SetCapacityBetweenLengthAndMaxCapacity() {
      StringBuilder sb(100, 500);
      sb.Length = 100;
      sb.Capacity = 200;
      Assert::AreEqual(100, sb.Length(), sw_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 200, sw_current_information);
      Assert::AreEqual(500, sb.MaxCapacity(), sw_current_information);
    }
    
    void SetCapacityLesserThanLength() {
      StringBuilder sb(100, 500);
      sb.Length = 100;
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {sb.Capacity = 99;}, sw_current_information);
    }
    
    void SetCapacityAboveMaxCapacity() {
      StringBuilder sb(100, 500);
      sb.Length = 100;
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {sb.Capacity = 501;}, sw_current_information);
    }
    
    void GetChar() {
      StringBuilder sb("Hello, world!");
      Assert::AreEqual(U'o', sb[4], sw_current_information);
    }
    
    void GetChar32() {
#if !defined(_WIN32)
      StringBuilder sb(U"こんにちは世界!");
      Assert::AreEqual(U'\U0000306f', sb[4], sw_current_information);
#endif
    }
    
    void SetChar() {
      StringBuilder sb("Hello, world!");
      sb[4] = 'O';
      Assert::AreEqual(U'O', sb[4], sw_current_information);
    }
    
    void SetChar32() {
#if !defined(_WIN32)
      StringBuilder sb(U"こんにちは世界!");
      sb[4] = U'こ';
      Assert::AreEqual(U'こ', sb[4], sw_current_information);
#endif
    }
    
    void GetCharsLesserThanZero() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {sb[-1];}, sw_current_information);
    }
    
    void SetCharsLesserThanZero() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {sb[-1] = 'a';}, sw_current_information);
    }
    
    void GetCharsAboveLength() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {sb[5];}, sw_current_information);
    }
    
    void SetCharsAboveLength() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {sb[5] = 'a';}, sw_current_information);
    }
    
    void GetLength() {
      Assert::AreEqual(0, StringBuilder("").Length(), sw_current_information);
      Assert::AreEqual(1, StringBuilder("0").Length(), sw_current_information);
      Assert::AreEqual(5, StringBuilder("Hello").Length(), sw_current_information);
    }
    
    void SetLength() {
      StringBuilder sb;
      sb.Length = 5;
      Assert::AreEqual(5, sb.Length(), sw_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 16, sw_current_information);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), sw_current_information);
      Assert::AreEqual("", sb.ToString(), sw_current_information);
      Assert::AreEqual(U'\0', sb[0], sw_current_information);
      Assert::AreEqual(U'\0', sb[1], sw_current_information);
      Assert::AreEqual(U'\0', sb[2], sw_current_information);
      Assert::AreEqual(U'\0', sb[3], sw_current_information);
      Assert::AreEqual(U'\0', sb[4], sw_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {sb[5];}, sw_current_information);
    }
    
    void SetLengthLesserThanZero() {
      StringBuilder sb;
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {sb.Length = -1;}, sw_current_information);
    }
    
    void SetLengthAboveMaxCapacity() {
      StringBuilder sb(100, 200);
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {sb.Length = 201;}, sw_current_information);
    }
    
    void SetLengthLesserThanLegnth() {
      StringBuilder sb("Hello, World!");
      sb.Length = 5;
      Assert::AreEqual(5, sb.Length(), sw_current_information);
      Assert::AreEqual("Hello", sb.ToString(), sw_current_information);
    }
    
    void SetLengthAboveCapacity() {
      StringBuilder sb(100);
      sb.Length = 105;
      Assert::GreaterOrEqual(sb.Capacity(), 105, sw_current_information);
    }
    
    void MaxCapacity() {
      Assert::AreEqual(Int32::MaxValue, StringBuilder("").MaxCapacity(), sw_current_information);
      Assert::AreEqual(1, StringBuilder("0").Length(), sw_current_information);
      Assert::AreEqual(5, StringBuilder("Hello").Length(), sw_current_information);
    }
    
    void AppendBoolean() {
      Assert::AreEqual("String Builder True", StringBuilder("String Builder ").Append(true).ToString(), sw_current_information);
    }
    
    void AppendByte() {
      Assert::AreEqual(U"String Builder 255", StringBuilder("String Builder ").Append(Byte::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendChar() {
      Assert::AreEqual("String Builder Y", StringBuilder("String Builder ").Append('Y').ToString(), sw_current_information);
    }
   
    void AppendChar32() {
#if !defined(_WIN32)
      Assert::AreEqual(U"String Builder こ", StringBuilder("String Builder ").Append(U'こ').ToString(), sw_current_information);
#endif
    }
    
    void AppendCharPointer() {
      const char test[] {'a' , 'b', 'c', 'd'};
      Assert::AreEqual("String Builder abcd", StringBuilder("String Builder ").Append(test, 4).ToString(), sw_current_information);
    }
    
    void AppendChar32Pointer() {
#if !defined(_WIN32)
      const char32 test[] {U'こ' , U'ん', U'に', U'ち'};
      Assert::AreEqual(U"String Builder こんにち", StringBuilder("String Builder ").Append(test, 4).ToString(), sw_current_information);
#endif
    }
    
    void AppendChar32WithRepeatCount() {
      Assert::AreEqual("String Builder ******", StringBuilder("String Builder ").Append(U'*', 6).ToString(), sw_current_information);
    }
    
    void AppendArrayChar32() {
      Assert::AreEqual("String Builder abcd", StringBuilder("String Builder ").Append(Array<char32> {'a' , 'b', 'c', 'd'}).ToString(), sw_current_information);
    }
    
    void AppendArrayChar32WithIndexAndCount() {
      Assert::AreEqual("String Builder bc", StringBuilder("String Builder ").Append(Array<char32> {'a' , 'b', 'c', 'd'}, 1, 2).ToString(), sw_current_information);
    }
    
    void AppendDecimal() {
      Assert::AreEqual("String Builder 12.3", StringBuilder("String Builder ").Append(decimal(12.3)).ToString(), sw_current_information);
    }
    
    void AppendDouble() {
      Assert::AreEqual("String Builder 12.3", StringBuilder("String Builder ").Append(double(12.3)).ToString(), sw_current_information);
    }
    
    void AppendInt16() {
      Assert::AreEqual("String Builder 32767", StringBuilder("String Builder ").Append(Int16::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendInt32() {
      Assert::AreEqual("String Builder 2147483647", StringBuilder("String Builder ").Append(Int32::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendInt64() {
      Assert::AreEqual("String Builder 9223372036854775807", StringBuilder("String Builder ").Append(Int64::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendObject() {
      class MyObject : public object {
      public:
        String ToString() const override {return "MyObject string";}
      };
      Assert::AreEqual("String Builder MyObject string", StringBuilder("String Builder ").Append(MyObject()).ToString(), sw_current_information);
    }
    
    void AppendAnyClass() {
      class AnyClass {
      public:
        String ToString() const {return "AnyClass string";}
      };
      Assert::AreEqual(U"String Builder AnyClass string", StringBuilder("String Builder ").Append(AnyClass()).ToString(), sw_current_information);
    }
    
    void AppendSByte() {
      Assert::AreEqual("String Builder 127", StringBuilder("String Builder ").Append(SByte::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendSingle() {
      Assert::AreEqual("String Builder 12.3", StringBuilder("String Builder ").Append(float(12.3)).ToString(), sw_current_information);
    }
    
    void AppendString() {
      Assert::AreEqual("String Builder other", StringBuilder("String Builder ").Append(string("other")).ToString(), sw_current_information);
    }
    
    void AppendStringToExceedMaxMaxValue() {
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {StringBuilder(10, 20).Append("This is a long string");}, sw_current_information);
    }
    
    void AppendcString() {
      Assert::AreEqual("String Builder other", StringBuilder("String Builder ").Append("other").ToString(), sw_current_information);
    }
    
    void AppendwString() {
      Assert::AreEqual("String Builder other", StringBuilder(L"String Builder ").Append("other").ToString(), sw_current_information);
    }
    
    void AppenduString() {
      Assert::AreEqual("String Builder other", StringBuilder(u"String Builder ").Append("other").ToString(), sw_current_information);
    }
    
    void AppendUString() {
      Assert::AreEqual("String Builder other", StringBuilder(U"String Builder ").Append("other").ToString(), sw_current_information);
    }
    
    void AppendUInt16() {
      Assert::AreEqual("String Builder 65535", StringBuilder("String Builder ").Append(UInt16::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendUInt32() {
      Assert::AreEqual("String Builder 4294967295", StringBuilder("String Builder ").Append(UInt32::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendUInt64() {
      Assert::AreEqual("String Builder 18446744073709551615", StringBuilder("String Builder ").Append(UInt64::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendFormatT1() {
      Assert::AreEqual("String Builder 65535", StringBuilder("String Builder ").AppendFormat("{0}", UInt16::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendFormatT2() {
      Assert::AreEqual("String Builder 65535 4294967295", StringBuilder("String Builder ").AppendFormat("{0} {1}", UInt16::MaxValue, UInt32::MaxValue).ToString(), sw_current_information);
    }
    
    void AppendFormatT3() {
      Assert::AreEqual("String Builder 65535 4294967295 12.3", StringBuilder("String Builder ").AppendFormat("{0} {1} {2}", UInt16::MaxValue, UInt32::MaxValue, 12.3).ToString(), sw_current_information);
    }
    
    void AppendFormatT4() {
      Assert::AreEqual("String Builder 65535 4294967295 12.3 True", StringBuilder("String Builder ").AppendFormat("{0} {1} {2} {3}", UInt16::MaxValue, UInt32::MaxValue, 12.3, true).ToString(), sw_current_information);
    }
    
    void AppendFormatT5() {
      Assert::AreEqual("String Builder 65535 4294967295 12.3 True Info", StringBuilder("String Builder ").AppendFormat("{0} {1} {2} {3} {4}", UInt16::MaxValue, UInt32::MaxValue, 12.3, true, "Info").ToString(), sw_current_information);
    }
    
  };
  
  sw_test(StringBuilderTest, DefaultConstructor)
  sw_test(StringBuilderTest, ConstructorWithCapacity)
  sw_test(StringBuilderTest, ConstructorWithCapacityLesserThanZero)
  sw_test(StringBuilderTest, ConstructorWithCapacityAndMaxCapacity)
  sw_test(StringBuilderTest, ConstructorWithCapacityLesserThanZeroAndMaxCapacity)
  sw_test(StringBuilderTest, ConstructorWithCapacityAndMaxCapacityLesserThanOne)
  sw_test(StringBuilderTest, ConstructorWithCapacityAndMaxCapacityLesserThanCapacity)
  sw_test(StringBuilderTest, ConstructorString)
  sw_test(StringBuilderTest, ConstructorStringAndCapacity)
  sw_test(StringBuilderTest, ConstructorWithStringStartIndexLengthAndCapacity)
  sw_test(StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthEqualZeroAndCapacity)
  sw_test(StringBuilderTest, ConstructorWithStringEmptyStartIndexEqualZeroLengthEqualZeroAndCapacity)
  sw_test(StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthLesserThanZeroAndCapacity)
  sw_test(StringBuilderTest, ConstructorWithStringStartIndexLesserThanZeroLengthLEqualZeroAndCapacity)
  sw_test(StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthAboveStringLengthAndCapacity)
  sw_test(StringBuilderTest, GetCapacity)
  sw_test(StringBuilderTest, SetCapacity)
  sw_test(StringBuilderTest, SetCapacityBetweenLengthAndMaxCapacity)
  sw_test(StringBuilderTest, SetCapacityLesserThanLength)
  sw_test(StringBuilderTest, SetCapacityAboveMaxCapacity)
  sw_test(StringBuilderTest, GetChar)
  sw_test(StringBuilderTest, GetChar32)
  sw_test(StringBuilderTest, SetChar)
  sw_test(StringBuilderTest, SetChar32)
  sw_test(StringBuilderTest, GetCharsLesserThanZero)
  sw_test(StringBuilderTest, SetCharsLesserThanZero)
  sw_test(StringBuilderTest, GetCharsAboveLength)
  sw_test(StringBuilderTest, SetCharsAboveLength)
  sw_test(StringBuilderTest, GetLength)
  sw_test(StringBuilderTest, SetLength)
  sw_test(StringBuilderTest, SetLengthLesserThanZero)
  sw_test(StringBuilderTest, SetLengthAboveMaxCapacity)
  sw_test(StringBuilderTest, SetLengthLesserThanLegnth)
  sw_test(StringBuilderTest, SetLengthAboveCapacity)
  sw_test(StringBuilderTest, MaxCapacity)
  sw_test(StringBuilderTest, AppendBoolean)
  sw_test(StringBuilderTest, AppendByte)
  sw_test(StringBuilderTest, AppendChar)
  sw_test(StringBuilderTest, AppendChar32)
  sw_test(StringBuilderTest, AppendCharPointer)
  sw_test(StringBuilderTest, AppendChar32Pointer)
  sw_test(StringBuilderTest, AppendChar32WithRepeatCount)
  sw_test(StringBuilderTest, AppendArrayChar32)
  sw_test(StringBuilderTest, AppendArrayChar32WithIndexAndCount)
  sw_test(StringBuilderTest, AppendDecimal)
  sw_test(StringBuilderTest, AppendDouble)
  sw_test(StringBuilderTest, AppendInt16)
  sw_test(StringBuilderTest, AppendInt32)
  sw_test(StringBuilderTest, AppendInt64)
  sw_test(StringBuilderTest, AppendObject)
  sw_test(StringBuilderTest, AppendAnyClass)
  sw_test(StringBuilderTest, AppendSByte)
  sw_test(StringBuilderTest, AppendSingle)
  sw_test(StringBuilderTest, AppendString)
  sw_test(StringBuilderTest, AppendStringToExceedMaxMaxValue)
  sw_test(StringBuilderTest, AppendcString)
  sw_test(StringBuilderTest, AppendwString)
  sw_test(StringBuilderTest, AppenduString)
  sw_test(StringBuilderTest, AppendUString)
  sw_test(StringBuilderTest, AppendUInt16)
  sw_test(StringBuilderTest, AppendUInt32)
  sw_test(StringBuilderTest, AppendUInt64)
  sw_test(StringBuilderTest, AppendFormatT1)
  sw_test(StringBuilderTest, AppendFormatT2)
  sw_test(StringBuilderTest, AppendFormatT3)
  sw_test(StringBuilderTest, AppendFormatT4)
  sw_test(StringBuilderTest, AppendFormatT5)
  
}
