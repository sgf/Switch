#include <Switch/System/Windows/Forms/AnchorStyles.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(AnchorStylesTest, None) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::AnchorStyles::None);
    ASSERT_EQ("None", System::Enum<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::None).ToString());
  }

  TEST(AnchorStylesTest, Top) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::AnchorStyles::Top);
    ASSERT_EQ("Top", System::Enum<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top).ToString());
  }

  TEST(AnchorStylesTest, Bottom) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::AnchorStyles::Bottom);
    ASSERT_EQ("Bottom", System::Enum<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Bottom).ToString());
  }

  TEST(AnchorStylesTest, Left) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::AnchorStyles::Left);
    ASSERT_EQ("Left", System::Enum<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left).ToString());
  }

  TEST(AnchorStylesTest, Right) {
    ASSERT_EQ(8, (int32)System::Windows::Forms::AnchorStyles::Right);
    ASSERT_EQ("Right", System::Enum<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Right).ToString());
  }
}
