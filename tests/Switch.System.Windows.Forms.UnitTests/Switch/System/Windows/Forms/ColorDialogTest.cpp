#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/ColorDialog.hpp>
#include <Switch/As.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(ColorDialogTest, DefaultConstructor) {
    ColorDialog colorDialog;

    ASSERT_TRUE(colorDialog.AllowFullOpen);
    ASSERT_FALSE(colorDialog.AnyColor);
    ASSERT_EQ(System::Drawing::Color::Black, colorDialog.Color);
    ASSERT_EQ(16, colorDialog.CustomColors().Count);
    for (Color customColor : colorDialog.CustomColors())
      ASSERT_EQ(System::Drawing::Color::White, customColor);
    ASSERT_FALSE(colorDialog.FullOpen);
    ASSERT_FALSE(colorDialog.ShowHelp);
    ASSERT_FALSE(colorDialog.SolidColorOnly);
  }

  TEST(ColorDialogTest, AllowFullOpen) {
    ColorDialog colorDialog;

    colorDialog.AllowFullOpen = false;

    ASSERT_FALSE(colorDialog.AllowFullOpen);
  }

  TEST(ColorDialogTest, AnyColor) {
    ColorDialog colorDialog;

    colorDialog.AnyColor = true;

    ASSERT_TRUE(colorDialog.AnyColor);
  }

  TEST(ColorDialogTest, Color) {
    ColorDialog colorDialog;

    colorDialog.Color = System::Drawing::Color::LightGreen;

    ASSERT_EQ(System::Drawing::Color::LightGreen, colorDialog.Color);
  }

  TEST(ColorDialogTest, CustomColor) {
    ColorDialog colorDialog;

    for (int32 index = 0; index < colorDialog.CustomColors().Count; index++)
      colorDialog.CustomColors()[index] = System::Drawing::Color::LightGreen;

    for (Color customColor : colorDialog.CustomColors())
      ASSERT_EQ(System::Drawing::Color::LightGreen, customColor);
  }

  TEST(ColorDialogTest, FullOpen) {
    ColorDialog colorDialog;

    colorDialog.FullOpen = true;

    ASSERT_TRUE(colorDialog.FullOpen);
  }

  TEST(ColorDialogTest, ShowHelp) {
    ColorDialog colorDialog;

    colorDialog.ShowHelp = true;

    ASSERT_TRUE(colorDialog.ShowHelp);
  }

  TEST(ColorDialogTest, SolidColorOnly) {
    ColorDialog colorDialog;

    colorDialog.SolidColorOnly = true;

    ASSERT_TRUE(colorDialog.SolidColorOnly);
  }

  TEST(ColorDialogTest, Reset) {
    ColorDialog colorDialog;

    colorDialog.AllowFullOpen = false;
    colorDialog.AnyColor = true;
    colorDialog.Color = System::Drawing::Color::LightGreen;
    for (int32 index = 0; index < colorDialog.CustomColors().Count; index++)
      colorDialog.CustomColors()[index] = System::Drawing::Color::LightGreen;
    colorDialog.FullOpen = true;
    colorDialog.ShowHelp = true;
    colorDialog.SolidColorOnly = true;

    colorDialog.Reset();

    ASSERT_TRUE(colorDialog.AllowFullOpen);
    ASSERT_FALSE(colorDialog.AnyColor);
    ASSERT_EQ(System::Drawing::Color::Black, colorDialog.Color);
    ASSERT_EQ(16, colorDialog.CustomColors().Count);
    for (Color customColor : colorDialog.CustomColors())
      ASSERT_EQ(System::Drawing::Color::White, customColor);
    ASSERT_FALSE(colorDialog.FullOpen);
    ASSERT_FALSE(colorDialog.ShowHelp);
    ASSERT_FALSE(colorDialog.SolidColorOnly);
  }
}
