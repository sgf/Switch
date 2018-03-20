#include <Switch/System/Enum.hpp>
#include <Switch/System/Globalization/NumberStyles.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(NumberStylesTest, None) {
    ASSERT_EQ(0, (int32)System::Globalization::NumberStyles::None);
    ASSERT_EQ("None", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::None).ToString());
  }

  TEST(NumberStylesTest, AllowLeadingWhite) {
    ASSERT_EQ(1, (int32)System::Globalization::NumberStyles::AllowLeadingWhite);
    ASSERT_EQ("AllowLeadingWhite", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowLeadingWhite).ToString());
  }

  TEST(NumberStylesTest, AllowTrailingWhite) {
    ASSERT_EQ(2, (int32)System::Globalization::NumberStyles::AllowTrailingWhite);
    ASSERT_EQ("AllowTrailingWhite", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowTrailingWhite).ToString());
  }

  TEST(NumberStylesTest, AllowLeadingSign) {
    ASSERT_EQ(4, (int32)System::Globalization::NumberStyles::AllowLeadingSign);
    ASSERT_EQ("AllowLeadingSign", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowLeadingSign).ToString());
  }

  TEST(NumberStylesTest, Integer) {
    ASSERT_EQ(7, (int32)System::Globalization::NumberStyles::Integer);
    ASSERT_EQ("Integer", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::Integer).ToString());
  }

  TEST(NumberStylesTest, AllowTrailingSign) {
    ASSERT_EQ(8, (int32)System::Globalization::NumberStyles::AllowTrailingSign);
    ASSERT_EQ("AllowTrailingSign", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowTrailingSign).ToString());
  }

  TEST(NumberStylesTest, AllowParentheses) {
    ASSERT_EQ(16, (int32)System::Globalization::NumberStyles::AllowParentheses);
    ASSERT_EQ("AllowParentheses", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowParentheses).ToString());
  }

  TEST(NumberStylesTest, AllowDecimalPoint) {
    ASSERT_EQ(32, (int32)System::Globalization::NumberStyles::AllowDecimalPoint);
    ASSERT_EQ("AllowDecimalPoint", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowDecimalPoint).ToString());
  }

  TEST(NumberStylesTest, AllowThousands) {
    ASSERT_EQ(64, (int32)System::Globalization::NumberStyles::AllowThousands);
    ASSERT_EQ("AllowThousands", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowThousands).ToString());
  }

  TEST(NumberStylesTest, Number) {
    ASSERT_EQ(111, (int32)System::Globalization::NumberStyles::Number);
    ASSERT_EQ("Number", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::Number).ToString());
  }

  TEST(NumberStylesTest, AllowExponent) {
    ASSERT_EQ(128, (int32)System::Globalization::NumberStyles::AllowExponent);
    ASSERT_EQ("AllowExponent", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowExponent).ToString());
  }

  TEST(NumberStylesTest, Float) {
    ASSERT_EQ(167, (int32)System::Globalization::NumberStyles::Float);
    ASSERT_EQ("Float", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::Float).ToString());
  }

  TEST(NumberStylesTest, AllowCurrencySymbol) {
    ASSERT_EQ(256, (int32)System::Globalization::NumberStyles::AllowCurrencySymbol);
    ASSERT_EQ("AllowCurrencySymbol", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowCurrencySymbol).ToString());
  }

  TEST(NumberStylesTest, Currency) {
    ASSERT_EQ(383, (int32)System::Globalization::NumberStyles::Currency);
    ASSERT_EQ("Currency", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::Currency).ToString());
  }

  TEST(NumberStylesTest, Any) {
    ASSERT_EQ(511, (int32)System::Globalization::NumberStyles::Any);
    ASSERT_EQ("Any", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::Any).ToString());
  }

  TEST(NumberStylesTest, AllowHexSpecifier) {
    ASSERT_EQ(512, (int32)System::Globalization::NumberStyles::AllowHexSpecifier);
    ASSERT_EQ("AllowHexSpecifier", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::AllowHexSpecifier).ToString());
  }

  TEST(NumberStylesTest, HexNumber) {
    ASSERT_EQ(515, (int32)System::Globalization::NumberStyles::HexNumber);
    ASSERT_EQ("HexNumber", Enum<System::Globalization::NumberStyles>(System::Globalization::NumberStyles::HexNumber).ToString());
  }
}
