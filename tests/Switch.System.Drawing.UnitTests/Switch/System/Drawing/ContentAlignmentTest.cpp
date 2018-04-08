#include <Switch/System/Drawing/ContentAlignment.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(ContentAlignmentTest, TopLeft) {
    ASSERT_EQ(1, (int32)System::Drawing::ContentAlignment::TopLeft);
    ASSERT_EQ("TopLeft", System::Enum<System::Drawing::ContentAlignment>(System::Drawing::ContentAlignment::TopLeft).ToString());
  }

  TEST(ContentAlignmentTest, TopCenter) {
    ASSERT_EQ(2, (int32)System::Drawing::ContentAlignment::TopCenter);
    ASSERT_EQ("TopCenter", System::Enum<System::Drawing::ContentAlignment>(System::Drawing::ContentAlignment::TopCenter).ToString());
  }

  TEST(ContentAlignmentTest, TopRight) {
    ASSERT_EQ(4, (int32)System::Drawing::ContentAlignment::TopRight);
    ASSERT_EQ("TopRight", System::Enum<System::Drawing::ContentAlignment>(System::Drawing::ContentAlignment::TopRight).ToString());
  }

  TEST(ContentAlignmentTest, MiddleLeft) {
    ASSERT_EQ(16, (int32)System::Drawing::ContentAlignment::MiddleLeft);
    ASSERT_EQ("MiddleLeft", System::Enum<System::Drawing::ContentAlignment>(System::Drawing::ContentAlignment::MiddleLeft).ToString());
  }

  TEST(ContentAlignmentTest, MiddleCenter) {
    ASSERT_EQ(32, (int32)System::Drawing::ContentAlignment::MiddleCenter);
    ASSERT_EQ("MiddleCenter", System::Enum<System::Drawing::ContentAlignment>(System::Drawing::ContentAlignment::MiddleCenter).ToString());
  }

  TEST(ContentAlignmentTest, MiddleRight) {
    ASSERT_EQ(64, (int32)System::Drawing::ContentAlignment::MiddleRight);
    ASSERT_EQ("MiddleRight", System::Enum<System::Drawing::ContentAlignment>(System::Drawing::ContentAlignment::MiddleRight).ToString());
  }

  TEST(ContentAlignmentTest, BottomLeft) {
    ASSERT_EQ(256, (int32)System::Drawing::ContentAlignment::BottomLeft);
    ASSERT_EQ("BottomLeft", System::Enum<System::Drawing::ContentAlignment>(System::Drawing::ContentAlignment::BottomLeft).ToString());
  }

  TEST(ContentAlignmentTest, BottomCenter) {
    ASSERT_EQ(512, (int32)System::Drawing::ContentAlignment::BottomCenter);
    ASSERT_EQ("BottomCenter", System::Enum<System::Drawing::ContentAlignment>(System::Drawing::ContentAlignment::BottomCenter).ToString());
  }

  TEST(ContentAlignmentTest, BottomRight) {
    ASSERT_EQ(1024, (int32)System::Drawing::ContentAlignment::BottomRight);
    ASSERT_EQ("BottomRight", System::Enum<System::Drawing::ContentAlignment>(System::Drawing::ContentAlignment::BottomRight).ToString());
  }
}
