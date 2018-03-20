#include <Switch/System/Enum.hpp>
#include <Switch/System/Globalization/NumberStyles.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Globalization;

namespace SwitchUnitTests {
  TEST(NumberStylesTest, None) {
    ASSERT_EQ(0, (int32)NumberStyles::None);
    ASSERT_EQ("None", Enum<NumberStyles>(NumberStyles::None).ToString());
  }

  TEST(NumberStylesTest, AllowLeadingWhite) {
    ASSERT_EQ(1, (int32)NumberStyles::AllowLeadingWhite);
    ASSERT_EQ("AllowLeadingWhite", Enum<NumberStyles>(NumberStyles::AllowLeadingWhite).ToString());
  }

  TEST(NumberStylesTest, AllowTrailingWhite) {
    ASSERT_EQ(2, (int32)NumberStyles::AllowTrailingWhite);
    ASSERT_EQ("AllowTrailingWhite", Enum<NumberStyles>(NumberStyles::AllowTrailingWhite).ToString());
  }

  TEST(NumberStylesTest, AllowLeadingSign) {
    ASSERT_EQ(4, (int32)NumberStyles::AllowLeadingSign);
    ASSERT_EQ("AllowLeadingSign", Enum<NumberStyles>(NumberStyles::AllowLeadingSign).ToString());
  }

  TEST(NumberStylesTest, Integer) {
    ASSERT_EQ(7, (int32)NumberStyles::Integer);
    ASSERT_EQ("Integer", Enum<NumberStyles>(NumberStyles::Integer).ToString());
  }

  TEST(NumberStylesTest, AllowTrailingSign) {
    ASSERT_EQ(8, (int32)NumberStyles::AllowTrailingSign);
    ASSERT_EQ("AllowTrailingSign", Enum<NumberStyles>(NumberStyles::AllowTrailingSign).ToString());
  }

  TEST(NumberStylesTest, AllowParentheses) {
    ASSERT_EQ(16, (int32)NumberStyles::AllowParentheses);
    ASSERT_EQ("AllowParentheses", Enum<NumberStyles>(NumberStyles::AllowParentheses).ToString());
  }

  TEST(NumberStylesTest, AllowDecimalPoint) {
    ASSERT_EQ(32, (int32)NumberStyles::AllowDecimalPoint);
    ASSERT_EQ("AllowDecimalPoint", Enum<NumberStyles>(NumberStyles::AllowDecimalPoint).ToString());
  }

  TEST(NumberStylesTest, AllowThousands) {
    ASSERT_EQ(64, (int32)NumberStyles::AllowThousands);
    ASSERT_EQ("AllowThousands", Enum<NumberStyles>(NumberStyles::AllowThousands).ToString());
  }

  TEST(NumberStylesTest, Number) {
    ASSERT_EQ(111, (int32)NumberStyles::Number);
    ASSERT_EQ("Number", Enum<NumberStyles>(NumberStyles::Number).ToString());
  }

  TEST(NumberStylesTest, AllowExponent) {
    ASSERT_EQ(128, (int32)NumberStyles::AllowExponent);
    ASSERT_EQ("AllowExponent", Enum<NumberStyles>(NumberStyles::AllowExponent).ToString());
  }

  TEST(NumberStylesTest, Float) {
    ASSERT_EQ(167, (int32)NumberStyles::Float);
    ASSERT_EQ("Float", Enum<NumberStyles>(NumberStyles::Float).ToString());
  }

  TEST(NumberStylesTest, AllowCurrencySymbol) {
    ASSERT_EQ(256, (int32)NumberStyles::AllowCurrencySymbol);
    ASSERT_EQ("AllowCurrencySymbol", Enum<NumberStyles>(NumberStyles::AllowCurrencySymbol).ToString());
  }

  TEST(NumberStylesTest, Currency) {
    ASSERT_EQ(383, (int32)NumberStyles::Currency);
    ASSERT_EQ("Currency", Enum<NumberStyles>(NumberStyles::Currency).ToString());
  }

  TEST(NumberStylesTest, Any) {
    ASSERT_EQ(511, (int32)NumberStyles::Any);
    ASSERT_EQ("Any", Enum<NumberStyles>(NumberStyles::Any).ToString());
  }

  TEST(NumberStylesTest, AllowHexSpecifier) {
    ASSERT_EQ(512, (int32)NumberStyles::AllowHexSpecifier);
    ASSERT_EQ("AllowHexSpecifier", Enum<NumberStyles>(NumberStyles::AllowHexSpecifier).ToString());
  }

  TEST(NumberStylesTest, HexNumber) {
    ASSERT_EQ(515, (int32)NumberStyles::HexNumber);
    ASSERT_EQ("HexNumber", Enum<NumberStyles>(NumberStyles::HexNumber).ToString());
  }
}
