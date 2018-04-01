#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Font.hpp"
#include "../../include/Switch/System/Drawing/FontStyle.hpp"
#include "../../include/Switch/System/Drawing/GraphicsUnit.hpp"

using namespace System;
using namespace System::Drawing;

System::Drawing::Font Native::SystemFontsApi::GetCaptionFont() {
  NSFont* hfont = [NSFont titleBarFontOfSize:[NSFont systemFontSize]];
  return __system_font_crerator__()([[hfont fontName] UTF8String], (float)[hfont pointSize] / 4 * 3, FontStyle::Regular);
  [hfont release];
}

System::Drawing::Font Native::SystemFontsApi::GetDefaultFont() {
  NSFont* hfont = [NSFont systemFontOfSize:[NSFont systemFontSize]];
  return __system_font_crerator__()([[hfont fontName] UTF8String], (float)[hfont pointSize] / 4 * 3, FontStyle::Regular);
  [hfont release];
}

System::Drawing::Font Native::SystemFontsApi::GetDialogFont() {
  NSFont* hfont = [NSFont paletteFontOfSize:[NSFont systemFontSize]];
  return __system_font_crerator__()([[hfont fontName] UTF8String], (float)[hfont pointSize] / 4 * 3, FontStyle::Regular);
  [hfont release];
}

System::Drawing::Font Native::SystemFontsApi::GetIconTitleFont() {
  NSFont* hfont = [NSFont titleBarFontOfSize:[NSFont systemFontSize]];
  return __system_font_crerator__()([[hfont fontName] UTF8String], (float)[hfont pointSize] / 4 * 3, FontStyle::Regular);
  [hfont release];
}

System::Drawing::Font Native::SystemFontsApi::GetMenuFont() {
  NSFont* hfont = [NSFont menuFontOfSize:[NSFont systemFontSize]];
  return __system_font_crerator__()([[hfont fontName] UTF8String], (float)[hfont pointSize] / 4 * 3, FontStyle::Regular);
  [hfont release];
}

System::Drawing::Font Native::SystemFontsApi::GetMessageBoxFont() {
  NSFont* hfont = [NSFont messageFontOfSize:[NSFont systemFontSize]];
  return __system_font_crerator__()([[hfont fontName] UTF8String], (float)[hfont pointSize] / 4 * 3, FontStyle::Regular);
  [hfont release];
}

System::Drawing::Font Native::SystemFontsApi::GetSmallCaptionFont() {
  NSFont* hfont = [NSFont titleBarFontOfSize:[NSFont systemFontSize]];
  return __system_font_crerator__()([[hfont fontName] UTF8String], (float)[hfont pointSize] / 4 * 3, FontStyle::Regular);
  [hfont release];
}

System::Drawing::Font Native::SystemFontsApi::GetStatusFont() {
  NSFont* hfont = [NSFont titleBarFontOfSize:[NSFont systemFontSize]];
  return __system_font_crerator__()([[hfont fontName] UTF8String], (float)[hfont pointSize] / 4 * 3, FontStyle::Regular);
  [hfont release];
}
#endif
