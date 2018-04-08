#include <Switch/System/Drawing/StringAlignment.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(StringAlignmentTest, Near) {
    ASSERT_EQ(0, (int32)System::Drawing::StringAlignment::Near);
    ASSERT_EQ("Near", System::Enum<System::Drawing::StringAlignment>(System::Drawing::StringAlignment::Near).ToString());
  }

  TEST(StringAlignmentTest, Center) {
    ASSERT_EQ(1, (int32)System::Drawing::StringAlignment::Center);
    ASSERT_EQ("Center", System::Enum<System::Drawing::StringAlignment>(System::Drawing::StringAlignment::Center).ToString());
  }

  TEST(StringAlignmentTest, Far) {
    ASSERT_EQ(2, (int32)System::Drawing::StringAlignment::Far);
    ASSERT_EQ("Far", System::Enum<System::Drawing::StringAlignment>(System::Drawing::StringAlignment::Far).ToString());
  }
}
