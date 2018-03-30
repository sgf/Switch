#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>
#undef CreateFont

#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Font.hpp"
#include "../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../include/Switch/System/Drawing/FontStyle.hpp"
#include "../../include/Switch/System/Drawing/GraphicsUnit.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::FontApi::CreateFont(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, byte gdiCharSet, bool gdiVerticalFont) {
  return IntPtr::Zero;
}

void Native::FontApi::DeleteFont(intptr hfont) {
}

System::Drawing::Font Native::FontApi::GetCaptionFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetDefaultFont() {
  return __system_font_crerator__()("Microsoft Sans Serif", 8.25f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetDialogFont() {
  return __system_font_crerator__()("Tahoma", 8.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetIconTitleFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetMenuFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetMessageBoxFont() {
  return __system_font_crerator__()("Tahoma", 8.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetSmallCaptionFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetStatusFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

#endif
