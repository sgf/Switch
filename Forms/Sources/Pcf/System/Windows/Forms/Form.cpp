#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Form.h"
#include "../../../../__OS/FormsApi.h"

#include <Pcf/System/EventArgs.h>
#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

void Form::Close() {
  FormsApi::Control::Close(*this);
}

void Form::CreateHandle() {
  this->data->messageActions = {{WM_CLOSE,{*this, &Form::WmClose}}};
  this->data->handle = FormsApi::Control::Create(*this);
  this->Control::CreateHandle();
}

void Form::WndProc(Message& message) {
  if (this->data->messageActions.ContainsKey(message.Msg))
    this->data->messageActions[message.Msg](message);
  else {
    System::Diagnostics::Debug::WriteLine("Form::WndProc message=" + message + ", name=" + this->data->name);
    this->Control::WndProc(message);
  }
}

void Form::WmClose(Message& message) {
  FormClosingEventArgs e;
  this->OnFormClosing(e);
  if (e.Cancel != true) {
    this->Control::WndProc(message);
    this->OnFormClosed(FormClosedEventArgs(e.CloseReason));
  }
}


