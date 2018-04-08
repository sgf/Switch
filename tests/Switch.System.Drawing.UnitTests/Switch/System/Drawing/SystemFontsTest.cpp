#include <Switch/System/Drawing/SystemFonts.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(SystemFontsTest, CaptionFont) {
    //ASSERT_EQ(Font(), SystemFonts::CaptionFont);
    ASSERT_TRUE(SystemFonts::CaptionFont().IsSystemFont);
    ASSERT_EQ(1, SystemFonts::CaptionFont().GdiCharSet());
    ASSERT_FALSE(SystemFonts::CaptionFont().GdiVerticalFont);
    ASSERT_FALSE(SystemFonts::CaptionFont().Bold);
    ASSERT_FALSE(SystemFonts::CaptionFont().Italic);
    ASSERT_FALSE(SystemFonts::CaptionFont().Strikeout);
    ASSERT_FALSE(SystemFonts::CaptionFont().Underline);
  }

  TEST(SystemFontsTest, DefaultFont) {
    //ASSERT_EQ(Font(), SystemFonts::DefaultFont);
    ASSERT_TRUE(SystemFonts::DefaultFont().IsSystemFont);
    ASSERT_EQ(1, SystemFonts::DefaultFont().GdiCharSet());
    ASSERT_FALSE(SystemFonts::DefaultFont().GdiVerticalFont);
    ASSERT_FALSE(SystemFonts::DefaultFont().Bold);
    ASSERT_FALSE(SystemFonts::DefaultFont().Italic);
    ASSERT_FALSE(SystemFonts::DefaultFont().Strikeout);
    ASSERT_FALSE(SystemFonts::DefaultFont().Underline);
  }

  TEST(SystemFontsTest, DialogFont) {
    //ASSERT_EQ(Font(), SystemFonts::DialogFont);
    ASSERT_TRUE(SystemFonts::DialogFont().IsSystemFont);
    ASSERT_EQ(1, SystemFonts::DialogFont().GdiCharSet());
    ASSERT_FALSE(SystemFonts::DialogFont().GdiVerticalFont);
    ASSERT_FALSE(SystemFonts::DialogFont().Bold);
    ASSERT_FALSE(SystemFonts::DialogFont().Italic);
    ASSERT_FALSE(SystemFonts::DialogFont().Strikeout);
    ASSERT_FALSE(SystemFonts::DialogFont().Underline);
  }

  TEST(SystemFontsTest, IconTitleFont) {
    //ASSERT_EQ(Font(), SystemFonts::IconTitleFont);
    ASSERT_TRUE(SystemFonts::IconTitleFont().IsSystemFont);
    ASSERT_EQ(1, SystemFonts::IconTitleFont().GdiCharSet());
    ASSERT_FALSE(SystemFonts::IconTitleFont().GdiVerticalFont);
    ASSERT_FALSE(SystemFonts::IconTitleFont().Bold);
    ASSERT_FALSE(SystemFonts::IconTitleFont().Italic);
    ASSERT_FALSE(SystemFonts::IconTitleFont().Strikeout);
    ASSERT_FALSE(SystemFonts::IconTitleFont().Underline);
  }

  TEST(SystemFontsTest, MenuFont) {
    //ASSERT_EQ(Font(), SystemFonts::MenuFont);
    ASSERT_TRUE(SystemFonts::MenuFont().IsSystemFont);
    ASSERT_EQ(1, SystemFonts::MenuFont().GdiCharSet());
    ASSERT_FALSE(SystemFonts::MenuFont().GdiVerticalFont);
    ASSERT_FALSE(SystemFonts::MenuFont().Bold);
    ASSERT_FALSE(SystemFonts::MenuFont().Italic);
    ASSERT_FALSE(SystemFonts::MenuFont().Strikeout);
    ASSERT_FALSE(SystemFonts::MenuFont().Underline);
  }

  TEST(SystemFontsTest, MessageBoxFont) {
    //ASSERT_EQ(Font(), SystemFonts::MessageBoxFont);
    ASSERT_TRUE(SystemFonts::MessageBoxFont().IsSystemFont);
    ASSERT_EQ(1, SystemFonts::MessageBoxFont().GdiCharSet());
    ASSERT_FALSE(SystemFonts::MessageBoxFont().GdiVerticalFont);
    ASSERT_FALSE(SystemFonts::MessageBoxFont().Bold);
    ASSERT_FALSE(SystemFonts::MessageBoxFont().Italic);
    ASSERT_FALSE(SystemFonts::MessageBoxFont().Strikeout);
    ASSERT_FALSE(SystemFonts::MessageBoxFont().Underline);
  }

  TEST(SystemFontsTest, SmallCaptionFont) {
    //ASSERT_EQ(Font(), SystemFonts::SmallCaptionFont);
    ASSERT_TRUE(SystemFonts::SmallCaptionFont().IsSystemFont);
    ASSERT_EQ(1, SystemFonts::SmallCaptionFont().GdiCharSet());
    ASSERT_FALSE(SystemFonts::SmallCaptionFont().GdiVerticalFont);
    ASSERT_FALSE(SystemFonts::SmallCaptionFont().Bold);
    ASSERT_FALSE(SystemFonts::SmallCaptionFont().Italic);
    ASSERT_FALSE(SystemFonts::SmallCaptionFont().Strikeout);
    ASSERT_FALSE(SystemFonts::SmallCaptionFont().Underline);
  }

  TEST(SystemFontsTest, StatusFont) {
    //ASSERT_EQ(Font(), SystemFonts::StatusFont);
    ASSERT_TRUE(SystemFonts::StatusFont().IsSystemFont);
    ASSERT_EQ(1, SystemFonts::StatusFont().GdiCharSet());
    ASSERT_FALSE(SystemFonts::StatusFont().GdiVerticalFont);
    ASSERT_FALSE(SystemFonts::StatusFont().Bold);
    ASSERT_FALSE(SystemFonts::StatusFont().Italic);
    ASSERT_FALSE(SystemFonts::StatusFont().Strikeout);
    ASSERT_FALSE(SystemFonts::StatusFont().Underline);
  }
}
