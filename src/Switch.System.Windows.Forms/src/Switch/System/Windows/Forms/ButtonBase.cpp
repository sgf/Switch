#include "../../../../../include/Switch/System/Windows/Forms/ButtonBase.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void ButtonBase::SetIsDefault(bool isDefault) {
  if (this->isDefault != isDefault) {
    this->isDefault = isDefault;
    if (this->IsHandleCreated)
      Native::ButtonApi::SetIsDefault(*this);
  }
}
