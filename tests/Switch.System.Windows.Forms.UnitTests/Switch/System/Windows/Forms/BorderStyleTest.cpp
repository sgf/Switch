#include <Switch/System/Windows/Forms/BorderStyle.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(BorderStyleTest, None) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::BorderStyle::None);
    ASSERT_EQ("None", System::Enum<System::Windows::Forms::BorderStyle>(System::Windows::Forms::BorderStyle::None).ToString());
  }

  TEST(BorderStyleTest, FixedSingle) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::BorderStyle::FixedSingle);
    ASSERT_EQ("FixedSingle", System::Enum<System::Windows::Forms::BorderStyle>(System::Windows::Forms::BorderStyle::FixedSingle).ToString());
  }

  TEST(BorderStyleTest, Fixed3D) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::BorderStyle::Fixed3D);
    ASSERT_EQ("Fixed3D", System::Enum<System::Windows::Forms::BorderStyle>(System::Windows::Forms::BorderStyle::Fixed3D).ToString());
  }
}
