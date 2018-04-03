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
  Pango::FontDescription fontDescription = Gtk::Button().get_style_context()->get_font();
  return __system_drawing_font_accessor__()(fontDescription.get_family().c_str(), fontDescription.get_size() / PANGO_SCALE, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetDefaultFont() {
  Pango::FontDescription fontDescription = Gtk::Button().get_style_context()->get_font();
  return __system_drawing_font_accessor__()(fontDescription.get_family().c_str(), fontDescription.get_size() / PANGO_SCALE, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetDialogFont() {
  Pango::FontDescription fontDescription = Gtk::Button().get_style_context()->get_font();
  return __system_drawing_font_accessor__()(fontDescription.get_family().c_str(), fontDescription.get_size() / PANGO_SCALE, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetIconTitleFont() {
  Pango::FontDescription fontDescription = Gtk::Button().get_style_context()->get_font();
  return __system_drawing_font_accessor__()(fontDescription.get_family().c_str(), fontDescription.get_size() / PANGO_SCALE, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetMenuFont() {
  Pango::FontDescription fontDescription = Gtk::Button().get_style_context()->get_font();
  return __system_drawing_font_accessor__()(fontDescription.get_family().c_str(), fontDescription.get_size() / PANGO_SCALE, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetMessageBoxFont() {
  Pango::FontDescription fontDescription = Gtk::Button().get_style_context()->get_font();
  return __system_drawing_font_accessor__()(fontDescription.get_family().c_str(), fontDescription.get_size() / PANGO_SCALE, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetSmallCaptionFont() {
  Pango::FontDescription fontDescription = Gtk::Button().get_style_context()->get_font();
  return __system_drawing_font_accessor__()(fontDescription.get_family().c_str(), fontDescription.get_size() / PANGO_SCALE, FontStyle::Regular);
}

System::Drawing::Font Native::SystemFontsApi::GetStatusFont() {
  Pango::FontDescription fontDescription = Gtk::Button().get_style_context()->get_font();
  return __system_drawing_font_accessor__()(fontDescription.get_family().c_str(), fontDescription.get_size() / PANGO_SCALE, FontStyle::Regular);
}

#endif
