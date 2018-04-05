#if defined(__linux__)
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Font.hpp"
#include "../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../include/Switch/System/Drawing/FontStyle.hpp"
#include "../../include/Switch/System/Drawing/GraphicsUnit.hpp"

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>
#include <pangomm.h>

using namespace System;
using namespace System::Drawing;

intptr Native::FontApi::Create(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, byte gdiCharSet, bool gdiVerticalFont) {
  Pango::FontDescription* fontDescription = new Pango::FontDescription(family.Name().c_str());
  fontDescription->set_size(emSize * PANGO_SCALE);
  fontDescription->set_style((style & System::Drawing::FontStyle ::Italic) == System::Drawing::FontStyle::Italic ? Pango::STYLE_ITALIC : Pango::STYLE_NORMAL);
  fontDescription->set_weight((style & System::Drawing::FontStyle ::Bold) == System::Drawing::FontStyle::Bold ? Pango::WEIGHT_BOLD : Pango::WEIGHT_NORMAL);
  return (intptr)fontDescription;
}

void Native::FontApi::Destroy(intptr hfont) {
  delete (Pango::FontDescription*)hfont;
}

void Native::FontApi::GetInformation(intptr hfont, string& name, float& size, System::Drawing::FontStyle& style) {
  name = ((Pango::FontDescription*)hfont)->get_family().c_str();
  size = ((Pango::FontDescription*)hfont)->get_size() / PANGO_SCALE;
  if (((Pango::FontDescription*)hfont)->get_style() & Pango::STYLE_ITALIC) style|= System::Drawing::FontStyle::Italic;
  if (((Pango::FontDescription*)hfont)->get_weight() >= Pango::WEIGHT_BOLD) style |= System::Drawing::FontStyle::Bold;
}

float Native::FontApi::GetHeight(float emSize, intptr hdc) {
  return emSize / 3 * 4;
}

float Native::FontApi::GetSize(float height, intptr hdc) {
  return height / 4 * 3;
}

#endif
