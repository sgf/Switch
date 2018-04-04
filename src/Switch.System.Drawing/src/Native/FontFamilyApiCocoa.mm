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

System::Array<System::Drawing::FontFamily> Native::FontFamilyApi::GetInstalledFontFamilies() {
  NSArray* fonts = [[[NSFontManager sharedFontManager] availableFontFamilies] sortedArrayUsingSelector:@selector(localizedCaseInsensitiveCompare:)];
  List<System::Drawing::FontFamily> families;
  for (NSString *item in fonts) {
    string* familyName = new string([item UTF8String]);
    families.Add(System::Drawing::FontFamily((intptr)familyName));
  }
  return families.ToArray();
}

System::Drawing::FontFamily Native::FontFamilyApi::GetFontFamilyFromName(const string& name) {
  if ([[NSFontManager sharedFontManager] availableMembersOfFontFamily:[NSString stringWithUTF8String:name.c_str()]] == nil)
    throw ArgumentException(caller_);
  string* familyName = new string(name);
  return System::Drawing::FontFamily((intptr)familyName);
}

string Native::FontFamilyApi::GetName(intptr handle) {
  if (handle == 0) return "";
  return *(string*)handle;
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
    delete (string*)handle;
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
