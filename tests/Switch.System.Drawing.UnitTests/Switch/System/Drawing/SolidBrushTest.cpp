#include <Switch/System/Drawing/SolidBrush.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(SolidBrushTest, ConstructorWithColor) {
    SolidBrush solidBrush(Color::Green);

    ASSERT_EQ(Color::Green, solidBrush.Color);
  }

  TEST(SolidBrushTest, CopyConstructor) {
    SolidBrush solidBrush1(Color::Green);

    SolidBrush solidBrush2 = solidBrush1;

    ASSERT_EQ(Color::Green, solidBrush2.Color);
  }

  TEST(SolidBrushTest, CopyOperator) {
    SolidBrush solidBrush1(Color::Green);
    SolidBrush solidBrush2(Color::Blue);

    solidBrush2 = solidBrush1;

    ASSERT_EQ(Color::Green, solidBrush2.Color);
  }

  TEST(SolidBrushTest, Copy) {
    $<SolidBrush> solidBrush1 = new_<SolidBrush>(Color::Green);

    $<SolidBrush> solidBrush2 = new_<SolidBrush>(*solidBrush1);
    solidBrush1->Color = Color::Orange;

    ASSERT_EQ(Color::Orange, solidBrush2->Color);
  }

  TEST(SolidBrushTest, Clone) {
    $<SolidBrush> solidBrush1 = new_<SolidBrush>(Color::Green);

    $<SolidBrush> solidBrush2 = as<SolidBrush>(solidBrush1->Clone());
    solidBrush1->Color = Color::Orange;

    ASSERT_EQ(Color::Green, solidBrush2->Color);
  }
}
