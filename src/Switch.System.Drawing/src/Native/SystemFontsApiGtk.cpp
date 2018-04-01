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

System::Drawing::Font Native::SystemFontsApi::GetCaptionFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetDefaultFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetDialogFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetIconTitleFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetMenuFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetMessageBoxFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetSmallCaptionFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetStatusFont() {
  return __system_font_crerator__()("Sans", 12.0f, FontStyle::Regular);
}

#endif
