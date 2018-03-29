#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Font.hpp"
#include "../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../include/Switch/System/Drawing/FontStyle.hpp"
#include "../../include/Switch/System/Drawing/GraphicsUnit.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::FontApi::CreateFont(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet, bool gdiVerticalFont) {
  NSFont* hfont = [NSFont fontWithName:[NSString stringWithUTF8String:family.Name().c_str()] size:emSize];;
  if ((style & System::Drawing::FontStyle::Bold) == System::Drawing::FontStyle::Bold) hfont = [[NSFontManager sharedFontManager] convertFont:hfont toHaveTrait:NSFontBoldTrait];
  if ((style & System::Drawing::FontStyle::Italic) == System::Drawing::FontStyle::Italic) hfont = [[NSFontManager sharedFontManager] convertFont:hfont toHaveTrait:NSFontItalicTrait];
  return (intptr)hfont;
}

void Native::FontApi::DeleteFont(intptr hfont) {
  [(NSFont*)hfont release];
}

System::Drawing::Font Native::FontApi::GetCaptionFont() {
  return __system_font_crerator__()("Times", 13.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetDefaultFont() {
  return __system_font_crerator__()("Times", 13.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetDialogFont() {
  return __system_font_crerator__()("Times", 13.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetIconTitleFont() {
  return __system_font_crerator__()("Times", 13.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetMenuFont() {
  return __system_font_crerator__()("Times", 13.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetMessageBoxFont() {
  return __system_font_crerator__()("Times", 13.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetSmallCaptionFont() {
  return __system_font_crerator__()("Times", 13.0f, FontStyle::Regular);
}

System::Drawing::Font Native::FontApi::GetStatusFont() {
  return __system_font_crerator__()("Times", 13.0f, FontStyle::Regular);
}
#endif
