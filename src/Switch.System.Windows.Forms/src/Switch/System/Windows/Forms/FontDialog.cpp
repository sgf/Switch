#include "../../../../Native/Api.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/FontDialog.hpp"
#include <Switch/System/Drawing/SystemFonts.hpp>

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
  this->Color = System::Drawing::SystemColors::ControlText;
  this->fixedPitchOnly = false;
  this->Font = System::Drawing::SystemFonts::DefaultFont;
  this->fontMustExist = false;
  this->maxSize = 0;
  this->minSize = 0;
  this->scriptOnly = false;
  this->showApply = false;
  this->ShowColor = false;
  this->ShowEffects = true;
  this->ShowHelp = false;
}

bool FontDialog::RunDialog(intptr hwndOwner) {
  return Native::CommonDialogApi::RunFontDialog(hwndOwner, *this);
}
