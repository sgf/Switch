#include "../../../../../include/Switch/System/Windows/Forms/TabPage.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../../../Native/Api.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void TabPage::CreateHandle() {
  this->handle = Native::TabPageApi::Create(*this);
  this->Control::CreateHandle();
  Native::TabPageApi::SetBorderStyle(*this);
}

void TabPage::SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle) {
  if (this->borderStyle != borderStyle) {
    this->borderStyle = borderStyle;
    if (this->IsHandleCreated)
      Native::TabPageApi::SetBorderStyle(*this);
  }
}

void TabPage::SetParent(ref<Control> parent) {
  if (!is<TabControl>(parent))
    throw ArgumentException(caller_);
  Control::SetParent(parent);
}
