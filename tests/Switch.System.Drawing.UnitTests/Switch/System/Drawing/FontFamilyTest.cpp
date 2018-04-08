#include <Switch/System/NotImplementedException.hpp>
#include <Switch/System/Drawing/FontFamily.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(FontFamilyTest, DefaultContructor) {
    FontFamily fontFamily;
    
    ASSERT_EQ("", fontFamily.Name);
  }

  TEST(FontFamilyTest, ContructorWithEmptyString) {
    ASSERT_THROW(FontFamily(""), ArgumentException);
  }
  
  TEST(FontFamilyTest, ContructorWithUnknownFontFamilyName) {
    ASSERT_THROW(FontFamily("Unknown FontFamily name"), ArgumentException);
  }
  
  TEST(FontFamilyTest, Families) {
    ASSERT_NE(0, FontFamily::Families().Count);
  }
  
  TEST(FontFamilyTest, ContructorWithName) {
    FontFamily fontFamily(FontFamily::Families()[1].Name);
    
    ASSERT_EQ(FontFamily::Families()[1].Name, fontFamily.Name);
  }
  
  TEST(FontFamilyTest, ContructorWithGenericFontFamilies) {
    FontFamily fontFamily(Switch::System::Drawing::Text::GenericFontFamilies::Monospace);
    
    ASSERT_EQ(FontFamily::GenericMonospace().Name, fontFamily.Name);
  }

  TEST(FontFamilyTest, GenericMonospace) {
    ASSERT_TRUE(FontFamily::GenericMonospace().Name() != "");
  }

  TEST(FontFamilyTest, GenericSansSerif) {
    ASSERT_TRUE(FontFamily::GenericSansSerif().Name() != "");
  }

  TEST(FontFamilyTest, GenericSerif) {
    ASSERT_TRUE(FontFamily::GenericSerif().Name() != "");
  }

  TEST(FontFamilyTest, GetCellAscent) {
    ASSERT_THROW(FontFamily::GenericSansSerif().GetCellAscent(Switch::System::Drawing::FontStyle::Regular), NotImplementedException);
  }

  TEST(FontFamilyTest, GetCellDescent) {
    ASSERT_THROW(FontFamily::GenericSansSerif().GetCellDescent(Switch::System::Drawing::FontStyle::Regular), NotImplementedException);
  }
}
