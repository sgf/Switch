#if defined(__linux__)
#include "Api.hpp"

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>
#include <glib.h>
#include <pango/pangocairo.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace {
  static PangoFontFamily** pangoFontFamilies = null;
  static int32 pangoFontFamiliesMax = 0;
};

Array<System::Drawing::FontFamily> Native::FontFamilyApi::GetInstalledFontFamilies() {
  System::Collections::Generic::List<System::Drawing::FontFamily> families;

  PangoFontMap* fontmap = pango_cairo_font_map_get_default();
  pango_font_map_list_families (fontmap, &pangoFontFamilies, &pangoFontFamiliesMax);
  for (int32 index = 0; index < pangoFontFamiliesMax; index++)
    families.Add(System::Drawing::FontFamily((intptr)index));

  return families.ToArray();
}

System::Drawing::FontFamily Native::FontFamilyApi::GetFontFamilyFromName(const string& name) {
  for (int32 index = 0; index < pangoFontFamiliesMax; index++)
    if (GetName((intptr)index) == name)
      return System::Drawing::FontFamily((intptr)index);
  throw ArgumentException(caller_);
}

string Native::FontFamilyApi::GetName(intptr handle) {
  if ((int32)handle >= pangoFontFamiliesMax) throw InvalidOperationException(caller_);
  return pango_font_family_get_name (pangoFontFamilies[(int32)handle]);
}

bool Native::FontFamilyApi::IsStyleAvailable(intptr handle, FontStyle style) {
  if (handle == 0) return false;

  /*
  if ((style & FontStyle::Italic) == FontStyle::Italic && result->lfItalic == 0) return false;
  if ((style & FontStyle::Underline) == FontStyle::Underline && result->lfUnderline == 0) return false;
  if ((style & FontStyle::Strikeout) == FontStyle::Strikeout && result->lfStrikeOut == 0) return false;
  */
  return true;
}

void Native::FontFamilyApi::ReleaseResource(intptr handle) {
  if (pangoFontFamilies != null)
    g_free (pangoFontFamilies);
}

#endif
