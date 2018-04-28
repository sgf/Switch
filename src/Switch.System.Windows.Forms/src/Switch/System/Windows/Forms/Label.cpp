#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Label.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Label::CreateHandle() {
  this->handle = Native::LabelApi::Create(*this);
  this->Control::CreateHandle();
  Native::LabelApi::SetBorderStyle(*this);
  Native::LabelApi::SetTextAlign(*this);
}

void Label::SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle) {
  if (this->borderStyle != borderStyle) {
    this->borderStyle = borderStyle;
    if (this->IsHandleCreated)
      Native::LabelApi::SetBorderStyle(*this);
  }
}

void Label::SetTextAlign(System::Drawing::ContentAlignment textAlign) {
  if (this->textAlign != textAlign) {
    this->textAlign = textAlign;
    if (this->IsHandleCreated)
      Native::LabelApi::SetTextAlign(*this);
  }
}
