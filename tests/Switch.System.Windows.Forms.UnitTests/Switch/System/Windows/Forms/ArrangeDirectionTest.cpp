#include <Switch/System/Windows/Forms/ArrangeDirection.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(ArrangeDirectionTest, Left) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::ArrangeDirection::Left);
    ASSERT_EQ("Left", System::Enum<System::Windows::Forms::ArrangeDirection>(System::Windows::Forms::ArrangeDirection::Left).ToString());
  }

  TEST(ArrangeDirectionTest, Up) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::ArrangeDirection::Up);
    ASSERT_EQ("Up", System::Enum<System::Windows::Forms::ArrangeDirection>(System::Windows::Forms::ArrangeDirection::Up).ToString());
  }
}
