#include "../../../../include/Switch/System/Drawing/Font.hpp"
#include "../../../../include/Switch/System/Drawing/Graphics.hpp"
#include "../../../Native/Api.hpp"
#include <Switch/System/Tuple.hpp>
#include <Switch/System/NotImplementedException.hpp>

using namespace System;

System::Drawing::Font::Font(const Switch::System::Drawing::Font& prototype, System::Drawing::FontStyle newStyle) {
  this->data->fontFamily = prototype.data->fontFamily;
  this->data->originalFontName = prototype.data->originalFontName;
  this->data->size = prototype.data->size;
  this->data->style = newStyle;
  this->data->unit = prototype.data->unit;
  this->data->gdiCharSet = prototype.data->gdiCharSet;
  this->data->gdiVerticalFont = prototype.data->gdiVerticalFont;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->style = style;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->gdiCharSet = gdiCharSet;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet, bool gdiVerticalFont) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->gdiCharSet = gdiCharSet;
  this->data->gdiVerticalFont = gdiVerticalFont;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize) {
  this->data->fontFamily = System::Drawing::FontFamily(familyName);
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize, System::Drawing::FontStyle style) {
  this->data->fontFamily = System::Drawing::FontFamily(familyName);
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->style = style;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit) {
  this->data->fontFamily = System::Drawing::FontFamily(familyName);
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet) {
  this->data->fontFamily = System::Drawing::FontFamily(familyName);
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->gdiCharSet = gdiCharSet;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet, bool gdiVerticalFont) {
  this->data->fontFamily = System::Drawing::FontFamily(familyName);
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->gdiCharSet = gdiCharSet;
  this->data->gdiVerticalFont = gdiVerticalFont;
  this->data->hfont = Native::FontApi::CreateFont(this->data->fontFamily, this->data->size, this->data->style, this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font::~Font() {
  if (this->data.IsUnique() && this->data->hfont != IntPtr::Zero)
    Native::FontApi::DeleteFont(this->data->hfont);
}

System::Drawing::Font System::Drawing::Font::FromHdc(intptr hdc) {
  throw NotImplementedException(caller_);
}

System::Drawing::Font System::Drawing::Font::FromHFont(intptr hfont) {
  throw NotImplementedException(caller_);
}

System::Drawing::Font System::Drawing::Font::FromLogFontHandle(intptr logfont, intptr hdc) {
  throw NotImplementedException(caller_);
}

float System::Drawing::Font::GetHeight() const {
  return 0;
}

float System::Drawing::Font::GetHeight(const Graphics& graphics) const {
  return 0;
}

float System::Drawing::Font::GetSizeInPoint() const {
  switch (this->data->unit) {
  case GraphicsUnit::World: return this->data->size;
  case GraphicsUnit::Display: return this->data->size;
  case GraphicsUnit::Pixel: return this->data->size;
  case GraphicsUnit::Point: return this->data->size;
  case GraphicsUnit::Inch: return this->data->size;
  case GraphicsUnit::Document: return this->data->size;
  case GraphicsUnit::Millimeter: return this->data->size;
  default: return this->data->size;
  }
}
