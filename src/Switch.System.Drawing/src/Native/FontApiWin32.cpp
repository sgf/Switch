#if defined(_WIN32)

#define UNICODE

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
  //return (intptr)CreateFontW((int32)(emSize / 3 * 4), 0, 0, 0, (style & FontStyle::Bold) == FontStyle::Bold ? FW_BOLD : FW_DONTCARE, (style & FontStyle::Italic) == FontStyle::Italic ? TRUE : FALSE, (style & FontStyle::Underline) == FontStyle::Underline ? TRUE : FALSE, (style & FontStyle::Strikeout) == FontStyle::Strikeout ? TRUE : FALSE, gdiCharSet, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, family.Name().w_str().c_str());
  return (intptr)CreateFontW(-MulDiv((int32)emSize, GetDeviceCaps(GetDC(GetActiveWindow()), LOGPIXELSY), 72), 0, 0, 0, (style & FontStyle::Bold) == FontStyle::Bold ? FW_BOLD : FW_DONTCARE, (style & FontStyle::Italic) == FontStyle::Italic ? TRUE : FALSE, (style & FontStyle::Underline) == FontStyle::Underline ? TRUE : FALSE, (style & FontStyle::Strikeout) == FontStyle::Strikeout ? TRUE : FALSE, gdiCharSet, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, family.Name().w_str().c_str());
}

void Native::FontApi::DeleteFont(intptr hfont) {
  DeleteObject((HGDIOBJ)hfont);
}

System::Drawing::Font Native::FontApi::GetCaptionFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetDefaultFont() {
  ///   Font::CreateFrom, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
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
