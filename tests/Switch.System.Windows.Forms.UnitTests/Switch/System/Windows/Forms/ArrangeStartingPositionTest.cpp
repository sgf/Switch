#include <Switch/System/Windows/Forms/ArrangeStartingPosition.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(ArrangeStartingPositionTest, BottomLeft) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::ArrangeStartingPosition::BottomLeft);
    ASSERT_EQ("BottomLeft", System::Enum<System::Windows::Forms::ArrangeStartingPosition>(System::Windows::Forms::ArrangeStartingPosition::BottomLeft).ToString());
  }

  TEST(ArrangeStartingPositionTest, BottomRight) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::ArrangeStartingPosition::BottomRight);
    ASSERT_EQ("BottomRight", System::Enum<System::Windows::Forms::ArrangeStartingPosition>(System::Windows::Forms::ArrangeStartingPosition::BottomRight).ToString());
  }

  TEST(ArrangeStartingPositionTest, TopLeft) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::ArrangeStartingPosition::TopLeft);
    ASSERT_EQ("TopLeft", System::Enum<System::Windows::Forms::ArrangeStartingPosition>(System::Windows::Forms::ArrangeStartingPosition::TopLeft).ToString());
  }

  TEST(ArrangeStartingPositionTest, TopRight) {
    ASSERT_EQ(3, (int32)System::Windows::Forms::ArrangeStartingPosition::TopRight);
    ASSERT_EQ("TopRight", System::Enum<System::Windows::Forms::ArrangeStartingPosition>(System::Windows::Forms::ArrangeStartingPosition::TopRight).ToString());
  }

  TEST(ArrangeStartingPositionTest, Hide) {
    ASSERT_EQ(8, (int32)System::Windows::Forms::ArrangeStartingPosition::Hide);
    ASSERT_EQ("Hide", System::Enum<System::Windows::Forms::ArrangeStartingPosition>(System::Windows::Forms::ArrangeStartingPosition::Hide).ToString());
  }
}
