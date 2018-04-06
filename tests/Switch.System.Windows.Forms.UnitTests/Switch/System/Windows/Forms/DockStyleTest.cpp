#include <Switch/System/Windows/Forms/DockStyle.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(DockStyleTest, None) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::DockStyle::None);
    ASSERT_EQ("None", System::Enum<System::Windows::Forms::DockStyle>(System::Windows::Forms::DockStyle::None).ToString());
  }

  TEST(DockStyleTest, Top) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::DockStyle::Top);
    ASSERT_EQ("Top", System::Enum<System::Windows::Forms::DockStyle>(System::Windows::Forms::DockStyle::Top).ToString());
  }

  TEST(DockStyleTest, Bottom) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::DockStyle::Bottom);
    ASSERT_EQ("Bottom", System::Enum<System::Windows::Forms::DockStyle>(System::Windows::Forms::DockStyle::Bottom).ToString());
  }

  TEST(DockStyleTest, Left) {
    ASSERT_EQ(3, (int32)System::Windows::Forms::DockStyle::Left);
    ASSERT_EQ("Left", System::Enum<System::Windows::Forms::DockStyle>(System::Windows::Forms::DockStyle::Left).ToString());
  }

  TEST(DockStyleTest, Right) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::DockStyle::Right);
    ASSERT_EQ("Right", System::Enum<System::Windows::Forms::DockStyle>(System::Windows::Forms::DockStyle::Right).ToString());
  }

  TEST(DockStyleTest, Fill) {
    ASSERT_EQ(5, (int32)System::Windows::Forms::DockStyle::Fill);
    ASSERT_EQ("Fill", System::Enum<System::Windows::Forms::DockStyle>(System::Windows::Forms::DockStyle::Fill).ToString());
  }
}
