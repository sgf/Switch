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
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->style = style;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->gdiCharSet = gdiCharSet;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet, bool gdiVerticalFont) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->gdiCharSet = gdiCharSet;
  this->data->gdiVerticalFont = gdiVerticalFont;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::GraphicsUnit unit) {
  this->data->fontFamily = family;
  this->data->originalFontName = family.Name;
  this->data->size = emSize;
  this->data->unit = unit;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize) {
  try {
    this->data->fontFamily = System::Drawing::FontFamily(familyName);
  } catch (const System::ArgumentException& e) {
    this->data->fontFamily = System::Drawing::FontFamily::GenericSansSerif;
  }
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize, System::Drawing::FontStyle style) {
  try {
    this->data->fontFamily = System::Drawing::FontFamily(familyName);
  } catch (const System::ArgumentException& e) {
    this->data->fontFamily = System::Drawing::FontFamily::GenericSansSerif;
  }
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->style = style;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit) {
  try {
    this->data->fontFamily = System::Drawing::FontFamily(familyName);
  } catch (const System::ArgumentException& e) {
    this->data->fontFamily = System::Drawing::FontFamily::GenericSansSerif;
  }
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet) {
  try {
    this->data->fontFamily = System::Drawing::FontFamily(familyName);
  } catch (const System::ArgumentException& e) {
    this->data->fontFamily = System::Drawing::FontFamily::GenericSansSerif;
  }
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->gdiCharSet = gdiCharSet;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet, bool gdiVerticalFont) {
  try {
    this->data->fontFamily = System::Drawing::FontFamily(familyName);
  } catch (const System::ArgumentException& e) {
    this->data->fontFamily = System::Drawing::FontFamily::GenericSansSerif;
  }
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->style = style;
  this->data->unit = unit;
  this->data->gdiCharSet = gdiCharSet;
  this->data->gdiVerticalFont = gdiVerticalFont;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font(const string& familyName, float emSize, System::Drawing::GraphicsUnit unit) {
  try {
    this->data->fontFamily = System::Drawing::FontFamily(familyName);
  } catch (const System::ArgumentException& e) {
    this->data->fontFamily = System::Drawing::FontFamily::GenericSansSerif;
  }
  this->data->originalFontName = familyName;
  this->data->size = emSize;
  this->data->unit = unit;
  this->data->hfont = Native::FontApi::Create(this->data->fontFamily, this->GetSizeInPoints(), this->data->style, this->data->gdiCharSet, this->data->gdiVerticalFont);
}

System::Drawing::Font::Font::~Font() {
  if (this->data.IsUnique() && this->data->hfont != IntPtr::Zero)
    Native::FontApi::Destroy(this->data->hfont);
}

System::Drawing::Font System::Drawing::Font::FromHdc(intptr hdc) {
  throw NotImplementedException(caller_);
}

System::Drawing::Font System::Drawing::Font::FromHFont(intptr hfont) {
  System::Drawing::Font font;
  font.data->hfont = hfont;
  Native::FontApi::GetInformation(font.data->hfont, font.data->originalFontName, font.data->size, font.data->style);
  font.data->fontFamily = System::Drawing::FontFamily(font.data->originalFontName);
  return font;
}

float System::Drawing::Font::GetHeight() const {
  return Native::FontApi::GetHeight(this->data->size, IntPtr::Zero);
}

float System::Drawing::Font::GetHeight(const Graphics& graphics) const {
  return Native::FontApi::GetHeight(this->data->size, graphics.GetHdc());
}

float System::Drawing::Font::GetSizeInPoints() const {
  switch (this->data->unit) {
  case GraphicsUnit::World: return this->data->size * 0.75f;;
  case GraphicsUnit::Display: return this->data->size / 75.0f * 72.0f;
  case GraphicsUnit::Pixel: return this->data->size * 0.75f;
  case GraphicsUnit::Point: return this->data->size;
  case GraphicsUnit::Inch: return this->data->size * 72.0f;
  case GraphicsUnit::Document: return this->data->size / 300.0f * 72.0f;
  case GraphicsUnit::Millimeter: return this->data->size / 25.4f * 72.0f;
  default: return this->data->size;
  }
}

float System::Drawing::Font::GetSize(float height, intptr hdc) {
  return Native::FontApi::GetSize(height, hdc);
}

