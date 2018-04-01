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

System::Drawing::Font Native::SystemFontsApi::GetCaptionFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetDefaultFont() {
  ///   Font::CreateFrom, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return __system_font_crerator__()("Microsoft Sans Serif", 8.25f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetDialogFont() {
  return __system_font_crerator__()("Tahoma", 8.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetIconTitleFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetMenuFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetMessageBoxFont() {
  return __system_font_crerator__()("Tahoma", 8.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetSmallCaptionFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetStatusFont() {
  return __system_font_crerator__()("Segoe UI", 9.0f, FontStyle::Regular);
}

#endif
