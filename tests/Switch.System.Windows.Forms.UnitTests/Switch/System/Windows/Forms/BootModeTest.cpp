#include <Switch/System/Windows/Forms/BootMode.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(BootModeTest, Normal) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::BootMode::Normal);
    ASSERT_EQ("Normal", System::Enum<System::Windows::Forms::BootMode>(System::Windows::Forms::BootMode::Normal).ToString());
  }

  TEST(BootModeTest, FailSafe) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::BootMode::FailSafe);
    ASSERT_EQ("FailSafe", System::Enum<System::Windows::Forms::BootMode>(System::Windows::Forms::BootMode::FailSafe).ToString());
  }

  TEST(BootModeTest, FailSafeWithNetwork) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::BootMode::FailSafeWithNetwork);
    ASSERT_EQ("FailSafeWithNetwork", System::Enum<System::Windows::Forms::BootMode>(System::Windows::Forms::BootMode::FailSafeWithNetwork).ToString());
  }
}
