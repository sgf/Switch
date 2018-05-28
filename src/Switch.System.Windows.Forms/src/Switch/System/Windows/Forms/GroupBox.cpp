#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/GroupBox.hpp"
#include "../../../../Native/Api.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void GroupBox::CreateHandle() {
  this->handle = Native::GroupBoxApi::Create(*this);
  this->Control::CreateHandle();
}

System::Drawing::Size GroupBox::GetDefaultSize() const {
  return Native::GroupBoxApi::GetDefaultSize();
}
