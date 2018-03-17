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
  this->customColors = Array<System::Drawing::Color>();
  this->fullOpen = false;
}

bool ColorDialog::RunDialog(intptr hwndOwner) {
  return Native::CommonDialog::RunColorDialog(hwndOwner, *this);
}
