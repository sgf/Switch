#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../../../Native/Api.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void TabControl::CreateHandle() {
  this->handle = Native::TabControlApi::Create(*this);
  this->Control::CreateHandle();
  Native::TabControlApi::SetAlignment(*this);
  Native::TabControlApi::GetTabPageRectangle(*this); // ???
  for (int32 index = 0; index < this->tabPages.Count; index++) {
    this->tabPages[index]().Parent = *this;
    this->tabPages[index]().CreateControl();
    this->tabPages[index]().Visible = index == 0;
    this->InsertTabPage(index, this->tabPages[index]());
    this->tabPages[index]().Bounds = Native::TabControlApi::GetTabPageRectangle(*this);
  }
}

void TabControl::OnNotifyMessage(const Message& m) {
  int32 selectedIndex = Native::TabControlApi::GetSelectedTabPageIndex(*this);
  for (int32 index = 0; index < this->tabPages.Count; index++)
    this->tabPages[index]->Visible = index == selectedIndex;
}

void TabControl::OnSizeChanged(const EventArgs& e) {
  this->Control::OnSizeChanged(e);
  for (int32 index = 0; index < this->tabPages.Count; index++)
    this->tabPages[index]().Bounds = Native::TabControlApi::GetTabPageRectangle(*this);
}

void TabControl::SetAlignment(TabAlignment alignment) {
  if (this->alignment != alignment) {
    this->alignment = alignment;
    if (this->IsHandleCreated)
      Native::TabControlApi::SetAlignment(*this);
  }
}

void TabControl::InsertTabPage(int32 index, const TabPage& tabPage) {
  if (this->IsHandleCreated)
    Native::TabControlApi::InsertTabPage(*this, index, tabPage);
}

void TabControl::RemoveTabPage(int32 index, const TabPage& tabPage) {
  if (this->IsHandleCreated)
    Native::TabControlApi::RemoveTabPage(*this, index, tabPage);
}

