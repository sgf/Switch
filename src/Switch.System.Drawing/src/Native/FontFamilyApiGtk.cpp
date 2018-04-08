#if defined(__linux__)
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../include/Switch/System/Drawing/FontStyle.hpp"

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
  // if (pangoFontFamilies != null) {
  //   g_free (pangoFontFamilies);
  //   pangoFontFamilies = null;
  // }
  if (pangoFontFamilies == null)
    pango_font_map_list_families(pango_cairo_font_map_get_default(), &pangoFontFamilies, &pangoFontFamiliesMax);
  System::Collections::Generic::List<System::Drawing::FontFamily> families;
  for (int32 index = 0; index < pangoFontFamiliesMax; index++)
    families.Add(System::Drawing::FontFamily((intptr)index));
  families.Sort(delegate_(const System::Drawing::FontFamily & a, const System::Drawing::FontFamily & b) {return a.Name().CompareTo(b.Name);});
  return families.ToArray();
}

System::Drawing::FontFamily Native::FontFamilyApi::GetFontFamilyFromName(const string& name) {
  if (pangoFontFamilies == null)
    pango_font_map_list_families(pango_cairo_font_map_get_default(), &pangoFontFamilies, &pangoFontFamiliesMax);
  for (int32 index = 0; index < pangoFontFamiliesMax; index++)
    if (GetName((intptr)index) == name)
      return System::Drawing::FontFamily((intptr)index);
  throw ArgumentException(caller_);
}

string Native::FontFamilyApi::GetName(intptr handle) {
  if ((int32)handle >= pangoFontFamiliesMax) throw InvalidOperationException(caller_);
  return pango_font_family_get_name(pangoFontFamilies[(int32)handle]);
}

bool Native::FontFamilyApi::IsStyleAvailable(intptr handle, FontStyle style) {
  if ((int32)handle >= pangoFontFamiliesMax) return false;

  /*
  if ((style & FontStyle::Italic) == FontStyle::Italic && result->lfItalic == 0) return false;
  if ((style & FontStyle::Underline) == FontStyle::Underline && result->lfUnderline == 0) return false;
  if ((style & FontStyle::Strikeout) == FontStyle::Strikeout && result->lfStrikeOut == 0) return false;
  */
  return true;
}

void Native::FontFamilyApi::ReleaseResource(intptr handle) {
}

string Native::FontFamilyApi::GenericFontFamilySerifName() {
  return "Serif";
}

string Native::FontFamilyApi::GenericFontFamilySansSerifName() {
  return "Sans";
}

string Native::FontFamilyApi::GenericFontFamilyMonospaceName() {
  return "Monospace";
}

#endif
