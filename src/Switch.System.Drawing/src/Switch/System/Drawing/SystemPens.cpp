#include "../../../../include/Switch/System/Drawing/SystemColors.hpp"
#include "../../../../include/Switch/System/Drawing/SystemPens.hpp"

using namespace System;
using namespace System::Drawing;

property_<Pen, readonly_> SystemPens::ActiveBorder {
  [] {return Pen(SystemColors::ActiveBorder);}
};

property_<Pen, readonly_> SystemPens::ActiveCaption {
  [] {return Pen(SystemColors::ActiveCaption);}
};

property_<Pen, readonly_> SystemPens::ActiveCaptionText {
  [] {return Pen(SystemColors::ActiveCaptionText);}
};

property_<Pen, readonly_> SystemPens::AppWorkspace {
  [] {return Pen(SystemColors::AppWorkspace);}
};

property_<Pen, readonly_> SystemPens::Control {
  [] {return Pen(SystemColors::Control);}
};

property_<Pen, readonly_> SystemPens::ControlDark {
  [] {return Pen(SystemColors::ControlDark);}
};

property_<Pen, readonly_> SystemPens::ControlDarkDark {
  [] {return Pen(SystemColors::ControlDarkDark);}
};

property_<Pen, readonly_> SystemPens::ControlLight {
  [] {return Pen(SystemColors::ControlLight);}
};

property_<Pen, readonly_> SystemPens::ControlLightLight {
  [] {return Pen(SystemColors::ControlLightLight);}
};

property_<Pen, readonly_> SystemPens::ControlText {
  [] {return Pen(SystemColors::ControlText);}
};

property_<Pen, readonly_> SystemPens::Desktop {
  [] {return Pen(SystemColors::Desktop);}
};

property_<Pen, readonly_> SystemPens::GrayText {
  [] {return Pen(SystemColors::GrayText);}
};

property_<Pen, readonly_> SystemPens::Highlight {
  [] {return Pen(SystemColors::Highlight);}
};

property_<Pen, readonly_> SystemPens::HighlightText {
  [] {return Pen(SystemColors::HighlightText);}
};

property_<Pen, readonly_> SystemPens::HotTrack {
  [] {return Pen(SystemColors::HotTrack);}
};

property_<Pen, readonly_> SystemPens::InactiveBorder {
  [] {return Pen(SystemColors::InactiveBorder);}
};

property_<Pen, readonly_> SystemPens::InactiveCaption {
  [] {return Pen(SystemColors::InactiveCaption);}
};

property_<Pen, readonly_> SystemPens::InactiveCaptionText {
  [] {return Pen(SystemColors::InactiveCaptionText);}
};

property_<Pen, readonly_> SystemPens::Info {
  [] {return Pen(SystemColors::Info);}
};

property_<Pen, readonly_> SystemPens::InfoText {
  [] {return Pen(SystemColors::InfoText);}
};

property_<Pen, readonly_> SystemPens::Menu {
  [] {return Pen(SystemColors::Menu);}
};

property_<Pen, readonly_> SystemPens::MenuText {
  [] {return Pen(SystemColors::MenuText);}
};

property_<Pen, readonly_> SystemPens::ScrollBar {
  [] {return Pen(SystemColors::ScrollBar);}
};

property_<Pen, readonly_> SystemPens::Window {
  [] {return Pen(SystemColors::Window);}
};

property_<Pen, readonly_> SystemPens::WindowFrame {
  [] {return Pen(SystemColors::WindowFrame);}
};

property_<Pen, readonly_> SystemPens::WindowText {
  [] {return Pen(SystemColors::WindowText);}
};

property_<Pen, readonly_> SystemPens::ButtonFace {
  [] {return Pen(SystemColors::ButtonFace);}
};

property_<Pen, readonly_> SystemPens::ButtonHighlight {
  [] {return Pen(SystemColors::ButtonHighlight);}
};

property_<Pen, readonly_> SystemPens::ButtonShadow {
  [] {return Pen(SystemColors::ButtonShadow);}
};

property_<Pen, readonly_> SystemPens::GradientActiveCaption {
  [] {return Pen(SystemColors::GradientActiveCaption);}
};

property_<Pen, readonly_> SystemPens::GradientInactiveCaption {
  [] {return Pen(SystemColors::GradientInactiveCaption);}
};

property_<Pen, readonly_> SystemPens::MenuBar {
  [] {return Pen(SystemColors::MenuBar);}
};

property_<Pen, readonly_> SystemPens::MenuHighlight {
  [] {return Pen(SystemColors::MenuHighlight);}
};

Pen SystemPens::FromSystemColor(const Color& color) {
  return Pen(color);
}
