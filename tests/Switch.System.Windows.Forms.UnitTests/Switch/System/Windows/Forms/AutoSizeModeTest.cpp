#include <Switch/System/Windows/Forms/AutoSizeMode.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(AutoSizeModeTest, GrowAndShrink) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::AutoSizeMode::GrowAndShrink);
    ASSERT_EQ("GrowAndShrink", System::Enum<System::Windows::Forms::AutoSizeMode>(System::Windows::Forms::AutoSizeMode::GrowAndShrink).ToString());
  }

  TEST(AutoSizeModeTest, GrowOnly) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::AutoSizeMode::GrowOnly);
    ASSERT_EQ("GrowOnly", System::Enum<System::Windows::Forms::AutoSizeMode>(System::Windows::Forms::AutoSizeMode::GrowOnly).ToString());
  }
}
