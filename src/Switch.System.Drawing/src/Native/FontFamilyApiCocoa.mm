#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/ArgumentException.hpp>
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../include/Switch/System/Drawing/FontStyle.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace {
  struct LogFont : public object {
    int32 lfHeight = 1;
    int32 lfWidth = 12;
    int32 lfEscapement = 0;
    int32 lfOrientation = 0;
    int32 lfWeight = 1;
    byte lfItalic = 0;
    byte lfUnderline = 0;
    byte lfStrikeOut = 0;
    byte lfCharSet = 1;
    byte lfOutPrecision = 0;
    byte lfClipPrecision = 0;
    byte lfQuality = 0;
    byte lfPitchAndFamily = 0;
    string lfFaceName = "";
  };
}

System::Array<System::Drawing::FontFamily> Native::FontFamilyApi::GetInstalledFontFamilies() {
  NSArray* fonts = [[[NSFontManager sharedFontManager] availableFontFamilies] sortedArrayUsingSelector:@selector(localizedCaseInsensitiveCompare:)];
  List<System::Drawing::FontFamily> families;
  for (NSString *item in fonts) {
    //NSFont* font = [[NSFontManager sharedFontManager] fontWithFamily:item traits:NSItalicFontMask|NSBoldFontMask weight:0 size:12];
    LogFont* logFont = new LogFont();
    logFont->lfFaceName = [item UTF8String];
    families.Add(System::Drawing::FontFamily((intptr)logFont));
  }
  return families.ToArray();
}

System::Drawing::FontFamily Native::FontFamilyApi::GetFontFamilyFromName(const string& name) {
  if ([[NSFontManager sharedFontManager] availableMembersOfFontFamily:[NSString stringWithUTF8String:name.c_str()]] == nil)
    throw ArgumentException(caller_);
  LogFont* logFont = new LogFont();
  logFont->lfFaceName = name;
  return System::Drawing::FontFamily((intptr)logFont);
}

string Native::FontFamilyApi::GetName(intptr handle) {
  if (handle == 0) return "";
  return ((LogFont*)handle)->lfFaceName;
}

bool Native::FontFamilyApi::IsStyleAvailable(intptr handle, System::Drawing::FontStyle style) {
  if (handle == 0) return false;
  
  /*
   if ((style & FontStyle::Italic) == FontStyle::Italic && result->lfItalic == 0) return false;
   if ((style & FontStyle::Underline) == FontStyle::Underline && result->lfUnderline == 0) return false;
   if ((style & FontStyle::Strikeout) == FontStyle::Strikeout && result->lfStrikeOut == 0) return false;
   */
  return true;
}

void Native::FontFamilyApi::ReleaseResource(intptr handle) {
  if (handle != 0)
    delete (LogFont*)handle;
}

string Native::FontFamilyApi::GenericFontFamilySerifName() {
  return "Times";
}

string Native::FontFamilyApi::GenericFontFamilySansSerifName() {
  return "Helvetica";
}

string Native::FontFamilyApi::GenericFontFamilyMonospaceName() {
  return "Courier";
}

#endif
