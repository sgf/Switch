#include "../../../../Native/Api.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/FontDialog.hpp"

using namespace System;
using namespace System::Windows::Forms;

FontDialog::FontDialog() {
  this->Reset();
}

void FontDialog::Reset() {
  this->allowSimulations = true;
  this->allowVectorFonts  = true;
  this->allowVerticalFonts = true;
  this->allowScriptChange = true;
  this->Color = System::Drawing::Color::Black;
  this->fixedPitchOnly = false;
  this->Font = System::Drawing::Font(System::Drawing::FontFamily::GenericSansSerif, 8.25f);
  this->fontMustExist = false;
  this->maxSize = 0;
  this->minSize = 0;
  this->scriptOnly = false;
  this->showApply = false;
  this->ShowColor = false;
  this->ShowEffects = false;
  this->ShowHelp = false;
}

bool FontDialog::RunDialog(intptr hwndOwner) {
  return Native::CommonDialog::RunFontDialog(hwndOwner, *this);
}
