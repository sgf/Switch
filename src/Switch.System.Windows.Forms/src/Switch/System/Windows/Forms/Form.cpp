#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Form.hpp"
#include "../../../../Native/Api.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Form::Close() {
  FormClosingEventArgs e;
  this->OnFormClosing(e);
  if (e.Cancel != true)
    this->OnFormClosed(FormClosedEventArgs(e.CloseReason));
}

void Form::CreateHandle() {
  if (!this->backColor.HasValue && System::Environment::OSVersion().Platform == System::PlatformID::Unix)
    this->backColor = System::Drawing::SystemColors::Window;
  this->messageActions[WM_CLOSE] = {*this, &Form::WmClose};
  this->handle = Native::FormApi::Create(*this);
  this->Control::CreateHandle();
}

DialogResult Form::ShowDialog() const {
  const_cast<Form*>(this)->Visible = true;
  if (Application::mainForm == null) {
    Application::Init();
    Application::mainForm = *this;
    Application::mainForm().FormClosed += delegate_(const object & sender, const FormClosedEventArgs & e) {
      Application::Exit();
    };
    Application::MessageLoop();
    Application::mainForm = null;
  }
  return this->dialogResult;
}

void Form::WndProc(Message& message) {
  if (message.Msg == WM_CLOSE)
    this->messageActions[message.Msg](message);
  else
    this->Control::WndProc(message);
}

void Form::WmClose(Message& message) {
  FormClosingEventArgs e;
  this->OnFormClosing(e);
  if (e.Cancel != true)
    this->OnFormClosed(FormClosedEventArgs(e.CloseReason));
}


