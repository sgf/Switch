#include <Switch/System/Drawing/GraphicsUnit.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(GraphicsUnitTest, World) {
    ASSERT_EQ(0, (int32)System::Drawing::GraphicsUnit::World);
    ASSERT_EQ("World", System::Enum<System::Drawing::GraphicsUnit>(System::Drawing::GraphicsUnit::World).ToString());
  }

  TEST(GraphicsUnitTest, Display) {
    ASSERT_EQ(1, (int32)System::Drawing::GraphicsUnit::Display);
    ASSERT_EQ("Display", System::Enum<System::Drawing::GraphicsUnit>(System::Drawing::GraphicsUnit::Display).ToString());
  }

  TEST(GraphicsUnitTest, Pixel) {
    ASSERT_EQ(2, (int32)System::Drawing::GraphicsUnit::Pixel);
    ASSERT_EQ("Pixel", System::Enum<System::Drawing::GraphicsUnit>(System::Drawing::GraphicsUnit::Pixel).ToString());
  }

  TEST(GraphicsUnitTest, Point) {
    ASSERT_EQ(3, (int32)System::Drawing::GraphicsUnit::Point);
    ASSERT_EQ("Point", System::Enum<System::Drawing::GraphicsUnit>(System::Drawing::GraphicsUnit::Point).ToString());
  }

  TEST(GraphicsUnitTest, Inch) {
    ASSERT_EQ(4, (int32)System::Drawing::GraphicsUnit::Inch);
    ASSERT_EQ("Inch", System::Enum<System::Drawing::GraphicsUnit>(System::Drawing::GraphicsUnit::Inch).ToString());
  }

  TEST(GraphicsUnitTest, Document) {
    ASSERT_EQ(5, (int32)System::Drawing::GraphicsUnit::Document);
    ASSERT_EQ("Document", System::Enum<System::Drawing::GraphicsUnit>(System::Drawing::GraphicsUnit::Document).ToString());
  }

  TEST(GraphicsUnitTest, Millimeter) {
    ASSERT_EQ(6, (int32)System::Drawing::GraphicsUnit::Millimeter);
    ASSERT_EQ("Millimeter", System::Enum<System::Drawing::GraphicsUnit>(System::Drawing::GraphicsUnit::Millimeter).ToString());
  }
}
