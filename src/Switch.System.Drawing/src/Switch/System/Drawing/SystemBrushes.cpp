#include "../../../../include/Switch/System/Drawing/SystemBrushes.hpp"
#include "../../../../include/Switch/System/Drawing/SystemColors.hpp"

using namespace System;
using namespace System::Drawing;

property_<SolidBrush, readonly_> SystemBrushes::ActiveBorder {
  [] {return SolidBrush(SystemColors::ActiveBorder);}
};

property_<SolidBrush, readonly_> SystemBrushes::ActiveCaption {
  [] {return SolidBrush(SystemColors::ActiveCaption);}
};

property_<SolidBrush, readonly_> SystemBrushes::ActiveCaptionText {
  [] {return SolidBrush(SystemColors::ActiveCaptionText);}
};

property_<SolidBrush, readonly_> SystemBrushes::AppWorkspace {
  [] {return SolidBrush(SystemColors::AppWorkspace);}
};

property_<SolidBrush, readonly_> SystemBrushes::Control {
  [] {return SolidBrush(SystemColors::Control);}
};

property_<SolidBrush, readonly_> SystemBrushes::ControlDark {
  [] {return SolidBrush(SystemColors::ControlDark);}
};

property_<SolidBrush, readonly_> SystemBrushes::ControlDarkDark {
  [] {return SolidBrush(SystemColors::ControlDarkDark);}
};

property_<SolidBrush, readonly_> SystemBrushes::ControlLight {
  [] {return SolidBrush(SystemColors::ControlLight);}
};

property_<SolidBrush, readonly_> SystemBrushes::ControlLightLight {
  [] {return SolidBrush(SystemColors::ControlLightLight);}
};

property_<SolidBrush, readonly_> SystemBrushes::ControlText {
  [] {return SolidBrush(SystemColors::ControlText);}
};

property_<SolidBrush, readonly_> SystemBrushes::Desktop {
  [] {return SolidBrush(SystemColors::Desktop);}
};

property_<SolidBrush, readonly_> SystemBrushes::GrayText {
  [] {return SolidBrush(SystemColors::GrayText);}
};

property_<SolidBrush, readonly_> SystemBrushes::Highlight {
  [] {return SolidBrush(SystemColors::Highlight);}
};

property_<SolidBrush, readonly_> SystemBrushes::HighlightText {
  [] {return SolidBrush(SystemColors::HighlightText);}
};

property_<SolidBrush, readonly_> SystemBrushes::HotTrack {
  [] {return SolidBrush(SystemColors::HotTrack);}
};

property_<SolidBrush, readonly_> SystemBrushes::InactiveBorder {
  [] {return SolidBrush(SystemColors::InactiveBorder);}
};

property_<SolidBrush, readonly_> SystemBrushes::InactiveCaption {
  [] {return SolidBrush(SystemColors::InactiveCaption);}
};

property_<SolidBrush, readonly_> SystemBrushes::InactiveCaptionText {
  [] {return SolidBrush(SystemColors::InactiveCaptionText);}
};

property_<SolidBrush, readonly_> SystemBrushes::Info {
  [] {return SolidBrush(SystemColors::Info);}
};

property_<SolidBrush, readonly_> SystemBrushes::InfoText {
  [] {return SolidBrush(SystemColors::InfoText);}
};

property_<SolidBrush, readonly_> SystemBrushes::Menu {
  [] {return SolidBrush(SystemColors::Menu);}
};

property_<SolidBrush, readonly_> SystemBrushes::MenuText {
  [] {return SolidBrush(SystemColors::MenuText);}
};

property_<SolidBrush, readonly_> SystemBrushes::ScrollBar {
  [] {return SolidBrush(SystemColors::ScrollBar);}
};

property_<SolidBrush, readonly_> SystemBrushes::Window {
  [] {return SolidBrush(SystemColors::Window);}
};

property_<SolidBrush, readonly_> SystemBrushes::WindowFrame {
  [] {return SolidBrush(SystemColors::WindowFrame);}
};

property_<SolidBrush, readonly_> SystemBrushes::WindowText {
  [] {return SolidBrush(SystemColors::WindowText);}
};

property_<SolidBrush, readonly_> SystemBrushes::ButtonFace {
  [] {return SolidBrush(SystemColors::ButtonFace);}
};

property_<SolidBrush, readonly_> SystemBrushes::ButtonHighlight {
  [] {return SolidBrush(SystemColors::ButtonHighlight);}
};

property_<SolidBrush, readonly_> SystemBrushes::ButtonShadow {
  [] {return SolidBrush(SystemColors::ButtonShadow);}
};

property_<SolidBrush, readonly_> SystemBrushes::GradientActiveCaption {
  [] {return SolidBrush(SystemColors::GradientActiveCaption);}
};

property_<SolidBrush, readonly_> SystemBrushes::GradientInactiveCaption {
  [] {return SolidBrush(SystemColors::GradientInactiveCaption);}
};

property_<SolidBrush, readonly_> SystemBrushes::MenuBar {
  [] {return SolidBrush(SystemColors::MenuBar);}
};

property_<SolidBrush, readonly_> SystemBrushes::MenuHighlight {
  [] {return SolidBrush(SystemColors::MenuHighlight);}
};

SolidBrush SystemBrushes::FromSystemColor(const Color& color) {
  return SolidBrush(color);
}
