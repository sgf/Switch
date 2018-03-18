#include "../../../../Native/Api.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/ColorDialog.hpp"

using namespace System;
using namespace System::Windows::Forms;

ColorDialog::ColorDialog() {
  this->Reset();
}

void ColorDialog::Reset() {
  this->AllowFullOpen = true;
  this->AnyColor = false;
  this->Color = System::Drawing::Color::Black;
  for (int32 index = 0; index < this->CustomColors().Length; index++)
    this->CustomColors()[index] = System::Drawing::Color::White;
  this->FullOpen = false;
  this->ShowHelp = false;
}

bool ColorDialog::RunDialog(intptr hwndOwner) {
  return Native::CommonDialog::RunColorDialog(hwndOwner, *this);
}
