#if defined(__linux__)

#include <gtkmm/widget.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/Button.hpp"
#include "../../include/Switch/System/Windows/Forms/Form.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  struct GtkWidget : public Gtk::Widget {
    GtkWidget() {}
  };

  class Control : public Widget<GtkWidget> {
  public:
    Control() {}
    void Text(const string& text) override {}
  };
}

intptr Native::ControlApi::Create(const System::Windows::Forms::Control& control) {
  Native::Control* handle = new Native::Control();
  handle->Move(control.Location().X, control.Location().Y);
  handle->Text(control.Text);
  handle->Visible(true);
  return (intptr)handle;
}

void Native::ControlApi::DefWndProc(System::Windows::Forms::Message& message) {

}

void Native::ControlApi::Destroy(const System::Windows::Forms::Control& control) {
  delete (IWidget*)control.Handle();
}

intptr Native::ControlApi::GetHandleWindowFromDeviceContext(intptr hdc) {
  return hdc;
}

System::Drawing::Size Native::ControlApi::GetTextSize(const System::Windows::Forms::Control& control) {
  return System::Drawing::Size();
}

void Native::ControlApi::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {

}

void Native::ControlApi::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {

}

System::Drawing::Point Native::ControlApi::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  System::Drawing::Point pointToClient = point - System::Drawing::Size(control.Location);
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent() != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToClient -= System::Drawing::Size(workControl().Location);
  }

  if (workControl().Parent != null)
    pointToClient -= System::Drawing::Size(workControl().Parent()().Location);

  return pointToClient;
}

System::Drawing::Point Native::ControlApi::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  System::Drawing::Point pointToScreen = point + System::Drawing::Size(control.Location);
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToScreen += System::Drawing::Size(workControl().Location);
  }

  if (workControl().Parent != null)
    pointToScreen += System::Drawing::Size(workControl().Parent()().Location);

  return pointToScreen;
}

intptr Native::ControlApi::SendMessage(intptr handle, int32 msg, intptr wparam, intptr lparam) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(handle);
  if (control == null) return -1;
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create(handle, msg, wparam, lparam, 0);
  control().WndProc(message);
  return message.Result;
}

void Native::ControlApi::SetBackColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((IWidget*)control().Handle())->BackColor(control().BackColor());
}

void Native::ControlApi::SetBackColor(const System::Windows::Forms::Control& control) {
  ((IWidget*)control.Handle())->BackColor(control.BackColor());
}

void Native::ControlApi::SetClientSize(System::Windows::Forms::Control& control) {
  ((IWidget*)control.Handle())->ClientSize(control.ClientSize);
  if (is<System::Windows::Forms::Form>(control))
    control.Size = System::Drawing::Size::Add(control.ClientSize, {0, SystemInformationApi::GetCaptionHeight()});
  else
    control.Size = control.ClientSize;
}

void Native::ControlApi::SetCursor(const System::Windows::Forms::Control& control) {
  ((IWidget*)control.Handle())->Cursor(control.Cursor);
}

void Native::ControlApi::SetEnabled(const System::Windows::Forms::Control& control) {
  ((IWidget*)control.Handle())->Enabled(control.Enabled);
}

bool Native::ControlApi::SetFocus(const System::Windows::Forms::Control& control) {
  ((IWidget*)control.Handle())->Focus();
  return true;
}

void Native::ControlApi::SetFont(const System::Windows::Forms::Control& control) {
  ((IWidget*)control.Handle())->Font(control.Font);
}

void Native::ControlApi::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((IWidget*)control().Handle())->ForeColor(control().ForeColor());
}

void Native::ControlApi::SetForeColor(const System::Windows::Forms::Control& control) {
  ((IWidget*)control.Handle())->ForeColor(control.ForeColor());
}

void Native::ControlApi::SetLocation(const System::Windows::Forms::Control& control) {
  ((IWidget*)control.Handle())->Move(control.Location().X, control.Location().Y);
}

void Native::ControlApi::SetParent(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->RemoveParent();
  if (control.Parent != null) {
    ((Native::IWidget*) control.Parent()->Handle())->AddChild((IWidget*) control.Handle());
    SetLocation(control);
    SetVisible(control);
  }
  if (control.Parent() != null) {
    //((Native::Widget*)control.Handle())->ToWidget().reparent(((Native::Widget*)control.Parent()().Handle())->Container());
  }
}

void Native::ControlApi::SetSize(System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Form>(control)) {
    ((Native::IWidget*)control.Handle())->Size(System::Drawing::Size::Subtract(control.Size, {0, SystemInformationApi::GetCaptionHeight()}));
    control.ClientSize = System::Drawing::Size::Subtract(control.Size, {0, SystemInformationApi::GetCaptionHeight()});
  } else {
    ((Native::IWidget*)control.Handle())->Size(control.Size);
    control.ClientSize = control.Size;
  }
}

void Native::ControlApi::SetTabStop(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->TabStop(control.TabStop);
}

void Native::ControlApi::SetText(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->Text(control.Text);
}

void Native::ControlApi::SetVisible(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->Visible(control.Visible);
}

#endif
