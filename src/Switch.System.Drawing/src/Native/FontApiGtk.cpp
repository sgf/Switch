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
}

float Native::FontApi::GetHeight(float emSize) {
  return GetHeight(emSize, IntPtr::Zero);
}

float Native::FontApi::GetHeight(float emSize, intptr hdc) {
  return emSize / 3 * 4;
}

#endif
