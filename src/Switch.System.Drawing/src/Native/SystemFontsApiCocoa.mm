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
  System::Drawing::Font font = System::Drawing::Font::FromHFont((intptr)[NSFont titleBarFontOfSize:[NSFont systemFontSize]]);
  __system_drawing_font_accessor__()(font);
  return font;
}

System::Drawing::Font Native::SystemFontsApi::GetDefaultFont() {
  System::Drawing::Font font = System::Drawing::Font::FromHFont((intptr)[NSFont systemFontOfSize:[NSFont systemFontSize]]);
  __system_drawing_font_accessor__()(font);
  return font;
}

System::Drawing::Font Native::SystemFontsApi::GetDialogFont() {
  System::Drawing::Font font = System::Drawing::Font::FromHFont((intptr)[NSFont paletteFontOfSize:[NSFont systemFontSize]]);
  __system_drawing_font_accessor__()(font);
  return font;
}

System::Drawing::Font Native::SystemFontsApi::GetIconTitleFont() {
  System::Drawing::Font font = System::Drawing::Font::FromHFont((intptr)[NSFont titleBarFontOfSize:[NSFont systemFontSize]]);
  __system_drawing_font_accessor__()(font);
  return font;
}

System::Drawing::Font Native::SystemFontsApi::GetMenuFont() {
  System::Drawing::Font font = System::Drawing::Font::FromHFont((intptr)[NSFont menuFontOfSize:[NSFont systemFontSize]]);
  __system_drawing_font_accessor__()(font);
  return font;
}

System::Drawing::Font Native::SystemFontsApi::GetMessageBoxFont() {
  System::Drawing::Font font = System::Drawing::Font::FromHFont((intptr)[NSFont messageFontOfSize:[NSFont systemFontSize]]);
  __system_drawing_font_accessor__()(font);
  return font;
}

System::Drawing::Font Native::SystemFontsApi::GetSmallCaptionFont() {
  System::Drawing::Font font = System::Drawing::Font::FromHFont((intptr)[NSFont titleBarFontOfSize:[NSFont systemFontSize]]);
  __system_drawing_font_accessor__()(font);
  return font;
}

System::Drawing::Font Native::SystemFontsApi::GetStatusFont() {
  System::Drawing::Font font = System::Drawing::Font::FromHFont((intptr)[NSFont titleBarFontOfSize:[NSFont systemFontSize]]);
  __system_drawing_font_accessor__()(font);
  return font;
}

#endif
