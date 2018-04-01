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
  return (intptr)CreateFontW(GetHeight(emSize), 0, 0, 0, (style & FontStyle::Bold) == FontStyle::Bold ? FW_BOLD : FW_DONTCARE, (style & FontStyle::Italic) == FontStyle::Italic ? TRUE : FALSE, (style & FontStyle::Underline) == FontStyle::Underline ? TRUE : FALSE, (style & FontStyle::Strikeout) == FontStyle::Strikeout ? TRUE : FALSE, gdiCharSet, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, family.Name().w_str().c_str());
}

void Native::FontApi::DeleteFont(intptr hfont) {
  DeleteObject((HGDIOBJ)hfont);
}

float Native::FontApi::GetHeight(float emSize) {
  return GetHeight(emSize, (intptr)GetDC(GetActiveWindow());
}

float Native::FontApi::GetHeight(float emSize, intptr hdc) {
  return -MulDiv((int32)emSize, GetDeviceCaps((HDC)hdc, LOGPIXELSY), 72);
}

#endif
