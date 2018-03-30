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

intptr Native::FontApi::CreateFont(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet, bool gdiVerticalFont) {
  return IntPtr::Zero;
}

void Native::FontApi::DeleteFont(intptr hfont) {
}

System::Drawing::Font Native::FontApi::GetCaptionFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetDefaultFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetDialogFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetIconTitleFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetMenuFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetMessageBoxFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetSmallCaptionFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetStatusFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

#endif
