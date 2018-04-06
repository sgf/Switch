#include "../../../../include/Switch/System/Drawing/SolidBrush.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;

SolidBrush::SolidBrush(const System::Drawing::Color& color) {
  *this->color = color;
  this->SetNativeBrush(Native::SolidBrushApi::Create(*this->color));
}

SolidBrush::~SolidBrush() {
  if (this->Brush::brush.IsUnique())
    Native::SolidBrushApi::Release(this->Brush::GetNativeBrush());
}

void SolidBrush::SetColor(const System::Drawing::Color& color) {
  if (*this->color != color) {
    *this->color = color;
    Native::SolidBrushApi::Release(this->Brush::GetNativeBrush());
    this->SetNativeBrush(Native::SolidBrushApi::Create(*this->color));
  }
}
