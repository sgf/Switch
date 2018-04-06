#include <Switch/System/Windows/Forms/CheckState.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(CheckStateTest, Unchecked) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::CheckState::Unchecked);
    ASSERT_EQ("Unchecked", System::Enum<System::Windows::Forms::CheckState>(System::Windows::Forms::CheckState::Unchecked).ToString());
  }

  TEST(CheckStateTest, Checked) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::CheckState::Checked);
    ASSERT_EQ("Checked", System::Enum<System::Windows::Forms::CheckState>(System::Windows::Forms::CheckState::Checked).ToString());
  }

  TEST(CheckStateTest, Indeterminate) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::CheckState::Indeterminate);
    ASSERT_EQ("Indeterminate", System::Enum<System::Windows::Forms::CheckState>(System::Windows::Forms::CheckState::Indeterminate).ToString());
  }
}
