#include <Switch/System/Drawing/SystemPens.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(SystemPensTest, ActiveBorder) {
    Pen pen = SystemPens::ActiveBorder;
    ASSERT_EQ(SystemColors::ActiveBorder, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ActiveCaption) {
    Pen pen = SystemPens::ActiveCaption;
    ASSERT_EQ(SystemColors::ActiveCaption, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ActiveCaptionText) {
    Pen pen = SystemPens::ActiveCaptionText;
    ASSERT_EQ(SystemColors::ActiveCaptionText, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, AppWorkspace) {
    Pen pen = SystemPens::AppWorkspace;
    ASSERT_EQ(SystemColors::AppWorkspace, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ButtonFace) {
    Pen pen = SystemPens::ButtonFace;
    ASSERT_EQ(SystemColors::ButtonFace, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ButtonHighlight) {
    Pen pen = SystemPens::ButtonHighlight;
    ASSERT_EQ(SystemColors::ButtonHighlight, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ButtonShadow) {
    Pen pen = SystemPens::ButtonShadow;
    ASSERT_EQ(SystemColors::ButtonShadow, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }

  TEST(SystemPensTest, Control) {
    Pen pen = SystemPens::Control;
    ASSERT_EQ(SystemColors::Control, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ControlDark) {
    Pen pen = SystemPens::ControlDark;
    ASSERT_EQ(SystemColors::ControlDark, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ControlDarkDark) {
    Pen pen = SystemPens::ControlDarkDark;
    ASSERT_EQ(SystemColors::ControlDarkDark, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ControlLight) {
    Pen pen = SystemPens::ControlLight;
    ASSERT_EQ(SystemColors::ControlLight, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ControlLightLight) {
    Pen pen = SystemPens::ControlLightLight;
    ASSERT_EQ(SystemColors::ControlLightLight, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ControlText) {
    Pen pen = SystemPens::ControlText;
    ASSERT_EQ(SystemColors::ControlText, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, Desktop) {
    Pen pen = SystemPens::Desktop;
    ASSERT_EQ(SystemColors::Desktop, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, GradientActiveCaption) {
    Pen pen = SystemPens::GradientActiveCaption;
    ASSERT_EQ(SystemColors::GradientActiveCaption, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, GradientInactiveCaption) {
    Pen pen = SystemPens::GradientInactiveCaption;
    ASSERT_EQ(SystemColors::GradientInactiveCaption, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }

  TEST(SystemPensTest, GrayText) {
    Pen pen = SystemPens::GrayText;
    ASSERT_EQ(SystemColors::GrayText, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, Highlight) {
    Pen pen = SystemPens::Highlight;
    ASSERT_EQ(SystemColors::Highlight, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, HighlightText) {
    Pen pen = SystemPens::HighlightText;
    ASSERT_EQ(SystemColors::HighlightText, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, HotTrack) {
    Pen pen = SystemPens::HotTrack;
    ASSERT_EQ(SystemColors::HotTrack, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, InactiveBorder) {
    Pen pen = SystemPens::InactiveBorder;
    ASSERT_EQ(SystemColors::InactiveBorder, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, InactiveCaption) {
    Pen pen = SystemPens::InactiveCaption;
    ASSERT_EQ(SystemColors::InactiveCaption, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, InactiveCaptionText) {
    Pen pen = SystemPens::InactiveCaptionText;
    ASSERT_EQ(SystemColors::InactiveCaptionText, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, Info) {
    Pen pen = SystemPens::Info;
    ASSERT_EQ(SystemColors::Info, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, InfoText) {
    Pen pen = SystemPens::InfoText;
    ASSERT_EQ(SystemColors::InfoText, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, Menu) {
    Pen pen = SystemPens::Menu;
    ASSERT_EQ(SystemColors::Menu, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, MenuBar) {
    Pen pen = SystemPens::MenuBar;
    ASSERT_EQ(SystemColors::MenuBar, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, MenuHighlight) {
    Pen pen = SystemPens::MenuHighlight;
    ASSERT_EQ(SystemColors::MenuHighlight, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }

  TEST(SystemPensTest, MenuText) {
    Pen pen = SystemPens::MenuText;
    ASSERT_EQ(SystemColors::MenuText, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, ScrollBar) {
    Pen pen = SystemPens::ScrollBar;
    ASSERT_EQ(SystemColors::ScrollBar, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, Window) {
    Pen pen = SystemPens::Window;
    ASSERT_EQ(SystemColors::Window, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, WindowFrame) {
    Pen pen = SystemPens::WindowFrame;
    ASSERT_EQ(SystemColors::WindowFrame, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
  
  TEST(SystemPensTest, WindowText) {
    Pen pen = SystemPens::WindowText;
    ASSERT_EQ(SystemColors::WindowText, pen.Color);
    ASSERT_EQ(1, pen.Width);
  }
}

