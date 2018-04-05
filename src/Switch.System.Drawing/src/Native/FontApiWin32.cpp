#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"
#include <Switch/System/Math.hpp>
#include "../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../include/Switch/System/Drawing/FontStyle.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::FontApi::Create(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, byte gdiCharSet, bool gdiVerticalFont) {
  return (intptr)CreateFont((int32) - GetHeight(emSize, IntPtr::Zero), 0, 0, 0, (style & FontStyle::Bold) == FontStyle::Bold ? FW_BOLD : FW_DONTCARE, (style & FontStyle::Italic) == FontStyle::Italic ? TRUE : FALSE, (style & FontStyle::Underline) == FontStyle::Underline ? TRUE : FALSE, (style & FontStyle::Strikeout) == FontStyle::Strikeout ? TRUE : FALSE, gdiCharSet, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, family.Name().w_str().c_str());
}

void Native::FontApi::Destroy(intptr hfont) {
  DeleteObject((HGDIOBJ)hfont);
}

void Native::FontApi::GetInformation(intptr hfont, string& name, float& size, System::Drawing::FontStyle& style) {
  LOGFONT logFont;
  GetObject((HANDLE)hfont, sizeof(logFont), &logFont);
  name = logFont.lfFaceName;
  size = GetSize((float)logFont.lfHeight, IntPtr::Zero);
  style = FontStyle::Regular;
  if (logFont.lfWeight >= FW_BOLD) style += FontStyle::Bold;
  if (logFont.lfItalic == TRUE) style += FontStyle::Italic;
  if (logFont.lfUnderline == TRUE) style += FontStyle::Underline;
}

float Native::FontApi::GetHeight(float emSize, intptr hdc) {
  return emSize / 72.0f * (float)GetDeviceCaps(hdc == IntPtr::Zero ? GetDC(GetActiveWindow()) : (HDC)hdc, LOGPIXELSY);
}

float Native::FontApi::GetSize(float height, intptr hdc) {
  return Math::Abs(height * 72.0f / (float)GetDeviceCaps(hdc == IntPtr::Zero ? GetDC(GetActiveWindow()) : (HDC)hdc, LOGPIXELSY));
}

#endif
