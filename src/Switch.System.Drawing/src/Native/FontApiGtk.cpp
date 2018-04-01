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

using namespace System;
using namespace System::Drawing;

intptr Native::FontApi::CreateFont(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, byte gdiCharSet, bool gdiVerticalFont) {
  return IntPtr::Zero;
}

void Native::FontApi::DeleteFont(intptr hfont) {
}

float Native::FontApi::GetHeight(float emSize) {
  return GetHeight(emSize, IntPtr::Zero);
}

float Native::FontApi::GetHeight(float emSize, intptr hdc) {
  return emSize / 3 * 4;
}

#endif
