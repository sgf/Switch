#include "../../../../Native/Api.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/ColorDialog.hpp"

using namespace System;
using namespace System::Windows::Forms;

ColorDialog::ColorDialog() {
  this->Reset();
}

void ColorDialog::Reset() {
  this->allowFullOpen = true;
  this->anyColor = false;
  this->color = System::Drawing::Color::Black;
}

bool ColorDialog::RunDialog(intptr hwndOwner) {
  return Native::CommonDialog::RunColorDialog(hwndOwner, *this);
}
