#include <Switch/System/Drawing/SystemBrushes.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(SystemBrushesTest, ActiveBorder) {
    SolidBrush brush = SystemBrushes::ActiveBorder;
    ASSERT_EQ(SystemColors::ActiveBorder, brush.Color);
  }
  
  TEST(SystemBrushesTest, ActiveCaption) {
    SolidBrush brush = SystemBrushes::ActiveCaption;
    ASSERT_EQ(SystemColors::ActiveCaption, brush.Color);
  }
  
  TEST(SystemBrushesTest, ActiveCaptionText) {
    SolidBrush brush = SystemBrushes::ActiveCaptionText;
    ASSERT_EQ(SystemColors::ActiveCaptionText, brush.Color);
  }
  
  TEST(SystemBrushesTest, AppWorkspace) {
    SolidBrush brush = SystemBrushes::AppWorkspace;
    ASSERT_EQ(SystemColors::AppWorkspace, brush.Color);
  }
  
  TEST(SystemBrushesTest, ButtonFace) {
    SolidBrush brush = SystemBrushes::ButtonFace;
    ASSERT_EQ(SystemColors::ButtonFace, brush.Color);
  }
  
  TEST(SystemBrushesTest, ButtonHighlight) {
    SolidBrush brush = SystemBrushes::ButtonHighlight;
    ASSERT_EQ(SystemColors::ButtonHighlight, brush.Color);
  }
  
  TEST(SystemBrushesTest, ButtonShadow) {
    SolidBrush brush = SystemBrushes::ButtonShadow;
    ASSERT_EQ(SystemColors::ButtonShadow, brush.Color);
  }
  
  TEST(SystemBrushesTest, Control) {
    SolidBrush brush = SystemBrushes::Control;
    ASSERT_EQ(SystemColors::Control, brush.Color);
  }
  
  TEST(SystemBrushesTest, ControlDark) {
    SolidBrush brush = SystemBrushes::ControlDark;
    ASSERT_EQ(SystemColors::ControlDark, brush.Color);
  }
  
  TEST(SystemBrushesTest, ControlDarkDark) {
    SolidBrush brush = SystemBrushes::ControlDarkDark;
    ASSERT_EQ(SystemColors::ControlDarkDark, brush.Color);
  }
  
  TEST(SystemBrushesTest, ControlLight) {
    SolidBrush brush = SystemBrushes::ControlLight;
    ASSERT_EQ(SystemColors::ControlLight, brush.Color);
  }
  
  TEST(SystemBrushesTest, ControlLightLight) {
    SolidBrush brush = SystemBrushes::ControlLightLight;
    ASSERT_EQ(SystemColors::ControlLightLight, brush.Color);
  }
  
  TEST(SystemBrushesTest, ControlText) {
    SolidBrush brush = SystemBrushes::ControlText;
    ASSERT_EQ(SystemColors::ControlText, brush.Color);
  }
  
  TEST(SystemBrushesTest, Desktop) {
    SolidBrush brush = SystemBrushes::Desktop;
    ASSERT_EQ(SystemColors::Desktop, brush.Color);
  }
  
  TEST(SystemBrushesTest, GradientActiveCaption) {
    SolidBrush brush = SystemBrushes::GradientActiveCaption;
    ASSERT_EQ(SystemColors::GradientActiveCaption, brush.Color);
  }
  
  TEST(SystemBrushesTest, GradientInactiveCaption) {
    SolidBrush brush = SystemBrushes::GradientInactiveCaption;
    ASSERT_EQ(SystemColors::GradientInactiveCaption, brush.Color);
  }

  TEST(SystemBrushesTest, GrayText) {
    SolidBrush brush = SystemBrushes::GrayText;
    ASSERT_EQ(SystemColors::GrayText, brush.Color);
  }
  
  TEST(SystemBrushesTest, Highlight) {
    SolidBrush brush = SystemBrushes::Highlight;
    ASSERT_EQ(SystemColors::Highlight, brush.Color);
  }
  
  TEST(SystemBrushesTest, HighlightText) {
    SolidBrush brush = SystemBrushes::HighlightText;
    ASSERT_EQ(SystemColors::HighlightText, brush.Color);
  }
  
  TEST(SystemBrushesTest, HotTrack) {
    SolidBrush brush = SystemBrushes::HotTrack;
    ASSERT_EQ(SystemColors::HotTrack, brush.Color);
  }
  
  TEST(SystemBrushesTest, InactiveBorder) {
    SolidBrush brush = SystemBrushes::InactiveBorder;
    ASSERT_EQ(SystemColors::InactiveBorder, brush.Color);
  }
  
  TEST(SystemBrushesTest, InactiveCaption) {
    SolidBrush brush = SystemBrushes::InactiveCaption;
    ASSERT_EQ(SystemColors::InactiveCaption, brush.Color);
  }
  
  TEST(SystemBrushesTest, InactiveCaptionText) {
    SolidBrush brush = SystemBrushes::InactiveCaptionText;
    ASSERT_EQ(SystemColors::InactiveCaptionText, brush.Color);
  }
  
  TEST(SystemBrushesTest, Info) {
    SolidBrush brush = SystemBrushes::Info;
    ASSERT_EQ(SystemColors::Info, brush.Color);
  }
  
  TEST(SystemBrushesTest, InfoText) {
    SolidBrush brush = SystemBrushes::InfoText;
    ASSERT_EQ(SystemColors::InfoText, brush.Color);
  }
  
  TEST(SystemBrushesTest, Menu) {
    SolidBrush brush = SystemBrushes::Menu;
    ASSERT_EQ(SystemColors::Menu, brush.Color);
  }
  
  TEST(SystemBrushesTest, MenuBar) {
    SolidBrush brush = SystemBrushes::MenuBar;
    ASSERT_EQ(SystemColors::MenuBar, brush.Color);
  }
  
  TEST(SystemBrushesTest, MenuHighlight) {
    SolidBrush brush = SystemBrushes::MenuHighlight;
    ASSERT_EQ(SystemColors::MenuHighlight, brush.Color);
  }

  TEST(SystemBrushesTest, MenuText) {
    SolidBrush brush = SystemBrushes::MenuText;
    ASSERT_EQ(SystemColors::MenuText, brush.Color);
  }
  
  TEST(SystemBrushesTest, ScrollBar) {
    SolidBrush brush = SystemBrushes::ScrollBar;
    ASSERT_EQ(SystemColors::ScrollBar, brush.Color);
  }
  
  TEST(SystemBrushesTest, Window) {
    SolidBrush brush = SystemBrushes::Window;
    ASSERT_EQ(SystemColors::Window, brush.Color);
  }
  
  TEST(SystemBrushesTest, WindowFrame) {
    SolidBrush brush = SystemBrushes::WindowFrame;
    ASSERT_EQ(SystemColors::WindowFrame, brush.Color);
  }
  
  TEST(SystemBrushesTest, WindowText) {
    SolidBrush brush = SystemBrushes::WindowText;
    ASSERT_EQ(SystemColors::WindowText, brush.Color);
  }
}

