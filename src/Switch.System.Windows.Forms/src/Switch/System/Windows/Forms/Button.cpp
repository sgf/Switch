#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Button.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Button::CreateHandle() {
  this->handle = Native::ButtonApi::Create(*this);
  this->Control::CreateHandle();
  Native::ButtonApi::SetIsDefault(*this);
}

