#include <gtest/gtest.h>
#include <Switch/System/Drawing/SystemColors.hpp>
#include <Switch/System/Drawing/SystemFonts.hpp>
#include <Switch/System/Windows/Forms/FontDialog.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(FontDialogTest, DefaultConstructor) {
    FontDialog fontDialog;

    ASSERT_TRUE(fontDialog.AllowScriptChange);
    ASSERT_TRUE(fontDialog.AllowSimulations);
    ASSERT_TRUE(fontDialog.AllowVectorFonts);
    ASSERT_TRUE(fontDialog.AllowVerticalFonts);
    ASSERT_EQ(SystemColors::ControlText, fontDialog.Color);
    ASSERT_FALSE(fontDialog.FixedPitchOnly);
    ASSERT_EQ(SystemFonts::DefaultFont, fontDialog.Font);
    ASSERT_FALSE(fontDialog.FontMustExist);
    ASSERT_EQ(0, fontDialog.MaxSize);
    ASSERT_EQ(0, fontDialog.MinSize);
    ASSERT_FALSE(fontDialog.ScriptOnly);
    ASSERT_FALSE(fontDialog.ShowApply);
    ASSERT_FALSE(fontDialog.ShowColor);
    ASSERT_TRUE(fontDialog.ShowEffects);
    ASSERT_FALSE(fontDialog.ShowHelp);
  }

  TEST(FontDialogTest, AllowScriptChange) {
    FontDialog fontDialog;

    fontDialog.AllowScriptChange = false;

    ASSERT_FALSE(fontDialog.AllowScriptChange);
  }

  TEST(FontDialogTest, AllowSimulations) {
    FontDialog fontDialog;

    fontDialog.AllowSimulations = false;

    ASSERT_FALSE(fontDialog.AllowSimulations);
  }

  TEST(FontDialogTest, AllowVectorFonts) {
    FontDialog fontDialog;

    fontDialog.AllowVectorFonts = false;

    ASSERT_FALSE(fontDialog.AllowVectorFonts);
  }

  TEST(FontDialogTest, AllowVerticalFonts) {
    FontDialog fontDialog;

    fontDialog.AllowVerticalFonts = false;

    ASSERT_FALSE(fontDialog.AllowVerticalFonts);
  }

  TEST(FontDialogTest, Color) {
    FontDialog fontDialog;

    fontDialog.Color = Color::Blue;

    ASSERT_EQ(Color::Blue, fontDialog.Color);
  }

  TEST(FontDialogTest, FixedPitchOnly) {
    FontDialog fontDialog;

    fontDialog.FixedPitchOnly = true;

    ASSERT_TRUE(fontDialog.FixedPitchOnly);
  }

  TEST(FontDialogTest, Font) {
    FontDialog fontDialog;

    fontDialog.Font = Font(FontFamily::GenericMonospace, 16.0f, FontStyle::Italic);

    ASSERT_EQ(Font(FontFamily::GenericMonospace, 16.0f, FontStyle::Italic), fontDialog.Font);
  }

  TEST(FontDialogTest, FontMustExist) {
    FontDialog fontDialog;

    fontDialog.FontMustExist = true;

    ASSERT_TRUE(fontDialog.FontMustExist);
  }

  TEST(FontDialogTest, MaxSize) {
    FontDialog fontDialog;

    fontDialog.MaxSize = 16;

    ASSERT_EQ(16, fontDialog.MaxSize);
  }

  TEST(FontDialogTest, MinSize) {
    FontDialog fontDialog;

    fontDialog.MinSize = 16;

    ASSERT_EQ(16, fontDialog.MinSize);
  }

  TEST(FontDialogTest, ScriptOnly) {
    FontDialog fontDialog;

    fontDialog.ScriptOnly = true;

    ASSERT_TRUE(fontDialog.ScriptOnly);
  }

  TEST(FontDialogTest, ShowApply) {
    FontDialog fontDialog;

    fontDialog.ShowApply = true;

    ASSERT_TRUE(fontDialog.ShowApply);
  }

  TEST(FontDialogTest, ShowColor) {
    FontDialog fontDialog;

    fontDialog.ShowColor = true;

    ASSERT_TRUE(fontDialog.ShowColor);
  }

  TEST(FontDialogTest, ShowEffects) {
    FontDialog fontDialog;

    fontDialog.ShowEffects = false;

    ASSERT_FALSE(fontDialog.ShowEffects);
  }

  TEST(FontDialogTest, ShowHelp) {
    FontDialog fontDialog;

    fontDialog.ShowHelp = true;

    ASSERT_TRUE(fontDialog.ShowHelp);
  }

  TEST(FontDialogTest, Reset) {
    FontDialog fontDialog;
    fontDialog.AllowScriptChange = false;
    fontDialog.AllowSimulations = false;
    fontDialog.AllowVectorFonts = false;
    fontDialog.AllowVerticalFonts = false;
    fontDialog.Color = Color::Blue;
    fontDialog.FixedPitchOnly = true;
    fontDialog.Font = Font(FontFamily::GenericMonospace, 16.0f, FontStyle::Italic);
    fontDialog.FontMustExist = true;
    fontDialog.MaxSize = 16;
    fontDialog.MinSize = 16;
    fontDialog.ScriptOnly = true;
    fontDialog.ShowApply = true;
    fontDialog.ShowColor = true;
    fontDialog.ShowEffects = false;
    fontDialog.ShowHelp = true;

    fontDialog.Reset();

    ASSERT_TRUE(fontDialog.AllowScriptChange);
    ASSERT_TRUE(fontDialog.AllowSimulations);
    ASSERT_TRUE(fontDialog.AllowVectorFonts);
    ASSERT_TRUE(fontDialog.AllowVerticalFonts);
    ASSERT_EQ(SystemColors::ControlText, fontDialog.Color);
    ASSERT_FALSE(fontDialog.FixedPitchOnly);
    ASSERT_EQ(SystemFonts::DefaultFont, fontDialog.Font);
    ASSERT_FALSE(fontDialog.FontMustExist);
    ASSERT_EQ(0, fontDialog.MaxSize);
    ASSERT_EQ(0, fontDialog.MinSize);
    ASSERT_FALSE(fontDialog.ScriptOnly);
    ASSERT_FALSE(fontDialog.ShowApply);
    ASSERT_FALSE(fontDialog.ShowColor);
    ASSERT_TRUE(fontDialog.ShowEffects);
    ASSERT_FALSE(fontDialog.ShowHelp);
  }

  TEST(FontDialogTest, SetMaxSizeLessThenZero) {
    FontDialog fontDialog;

    fontDialog.MaxSize = -3;

    ASSERT_EQ(0, fontDialog.MaxSize);
  }

  TEST(FontDialogTest, SetMaxSizeGreaterThenMinSize) {
    FontDialog fontDialog;

    fontDialog.MinSize = 10;
    fontDialog.MaxSize = 16;

    ASSERT_EQ(10, fontDialog.MinSize);
    ASSERT_EQ(16, fontDialog.MaxSize);
  }

  TEST(FontDialogTest, SetMaxSizeLessThenMinSize) {
    FontDialog fontDialog;

    fontDialog.MinSize = 20;
    fontDialog.MaxSize = 16;

    ASSERT_EQ(16, fontDialog.MinSize);
    ASSERT_EQ(16, fontDialog.MaxSize);
  }

  TEST(FontDialogTest, SetMinSizeLessThenZero) {
    FontDialog fontDialog;

    fontDialog.MinSize = -3;

    ASSERT_EQ(0, fontDialog.MinSize);
  }

  TEST(FontDialogTest, SetMinSizeLessThenMaxSize) {
    FontDialog fontDialog;

    fontDialog.MaxSize = 16;
    fontDialog.MinSize = 10;

    ASSERT_EQ(16, fontDialog.MaxSize);
    ASSERT_EQ(10, fontDialog.MinSize);
  }

  TEST(FontDialogTest, SetMinSizeGreaterThenMaxSize) {
    FontDialog fontDialog;

    fontDialog.MaxSize = 16;
    fontDialog.MinSize = 20;

    ASSERT_EQ(20, fontDialog.MaxSize);
    ASSERT_EQ(20, fontDialog.MinSize);
  }
}
