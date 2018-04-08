#include <Switch/System/Drawing/FontStyle.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(FontStyleTest, Regular) {
    ASSERT_EQ(0, (int32)System::Drawing::FontStyle::Regular);
    ASSERT_EQ("Regular", System::Enum<System::Drawing::FontStyle>(System::Drawing::FontStyle::Regular).ToString());
  }

  TEST(FontStyleTest, Bold) {
    ASSERT_EQ(1, (int32)System::Drawing::FontStyle::Bold);
    ASSERT_EQ("Bold", System::Enum<System::Drawing::FontStyle>(System::Drawing::FontStyle::Bold).ToString());
  }

  TEST(FontStyleTest, Italic) {
    ASSERT_EQ(2, (int32)System::Drawing::FontStyle::Italic);
    ASSERT_EQ("Italic", System::Enum<System::Drawing::FontStyle>(System::Drawing::FontStyle::Italic).ToString());
  }

  TEST(FontStyleTest, Underline) {
    ASSERT_EQ(4, (int32)System::Drawing::FontStyle::Underline);
    ASSERT_EQ("Underline", System::Enum<System::Drawing::FontStyle>(System::Drawing::FontStyle::Underline).ToString());
  }

  TEST(FontStyleTest, Strikeout) {
    ASSERT_EQ(8, (int32)System::Drawing::FontStyle::Strikeout);
    ASSERT_EQ("Strikeout", System::Enum<System::Drawing::FontStyle>(System::Drawing::FontStyle::Strikeout).ToString());
  }
}
