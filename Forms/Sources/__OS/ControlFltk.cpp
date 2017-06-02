#if defined(__use_fltk_interface__)
#include "WidgetFltk.h"

#include <FL/Fl_Group.H>

#include <Pcf/Undef.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Control : public __OS::Widget, public Fl_Widget {
  public:
    Control(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Widget(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Widget::handle(event);
      //this->Fl_Widget::draw();
      return 1;
    }
  };

  System::Drawing::Point PointToForm(const System::Windows::Forms::Control& control, const System::Drawing::Point point) {
    System::Drawing::Point pointToForm = point;
    ref<System::Windows::Forms::Control> workControl = control;
    while (workControl().Parent() != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
      workControl = workControl().Parent();
      pointToForm += workControl().Location();
    }
    return pointToForm;
  }
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  __OS::Control* handle = CreateControl<__OS::Control>(control);
  return (intptr)handle;
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {
  if (defWindowProcs.ContainsKey(message.HWnd) && message.Handle() != FL_NO_EVENT)
    message.Result = defWindowProcs[message.HWnd()]((int32)message.Handle);
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  if (control.Handle != IntPtr::Zero) {
    if (is<System::Windows::Forms::ContainerControl>(control)) {
      for (int index = 0; index < ((Fl_Group&)((__OS::Widget*)control.Handle())->ToWidget()).children(); index++)
        ((Fl_Group&)((__OS::Widget*)control.Handle())->ToWidget()).remove(index);
    }
    Message message = Message::Create((intptr)control.Handle, WM_DESTROY, 0, 0, 0, FL_NO_EVENT);
    const_cast<System::Windows::Forms::Control&>(control).WndProc(message);
    delete (__OS::Widget*)control.Handle();
  }
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return hdc;
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {
  ((__OS::Widget*)control.Handle())->ToWidget().redraw();
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {
  ((__OS::Widget*)control.Handle())->ToWidget().redraw();
}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  System::Drawing::Point pointToClient = point - control.Location();
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent() != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToClient -= workControl().Location();
  }
  
  if (workControl().Parent != null)
    pointToClient -= workControl().Parent()().Location();
  
  return pointToClient;
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  System::Drawing::Point pointToScreen = point + control.Location();
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToScreen += workControl().Location();
  }
  
  if (workControl().Parent != null)
    pointToScreen += workControl().Parent()().Location();
  
  return pointToScreen;
}

void FormsApi::Control::SetBackColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((__OS::Widget*)control().Handle())->BackColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control)().IsDefault ? System::Drawing::SystemColors::Highlight() : control().BackColor());
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->BackColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control).IsDefault ? System::Drawing::SystemColors::Highlight() : control.BackColor());
}

void FormsApi::Control::SetClientSize(System::Windows::Forms::Control &control) {
  if (is<System::Windows::Forms::Form>(control)) {
    ((__OS::Widget*)control.Handle())->ToWidget().size(control.ClientSize().Width, control.ClientSize().Height);
    control.Size = System::Drawing::Size::Add(control.ClientSize, {0, SystemInformation::GetCaptionHeight()});
  } else if (is<System::Windows::Forms::ProgressBar>(control)) {
    System::Drawing::Point formLocation = PointToForm(control, control.Location);
    int32 offset = control.Height > 6 ? (control.Height - 6) / 2 : 0;
    ((__OS::Widget*)control.Handle())->ToWidget().position(formLocation.X, formLocation.Y + offset);
    ((__OS::Widget*)control.Handle())->ToWidget().size(control.Size().Width, 6);
    control.Size = control.ClientSize;
  } else {
    ((__OS::Widget*)control.Handle())->ToWidget().size(control.ClientSize().Width, control.ClientSize().Height);
    control.Size = control.ClientSize;
  }
}

void FormsApi::Control::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((__OS::Widget*)control().Handle())->ForeColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control)().IsDefault ? System::Drawing::Color::White() : control().ForeColor());
}

bool FormsApi::Control::SetFocus(const System::Windows::Forms::Control &control) {
  Fl_Widget& widget = ((__OS::Widget*)control.Handle())->ToWidget();
  Fl::focus(&widget);
  return true;
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ForeColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control).IsDefault ? System::Drawing::Color::White() : control.ForeColor());
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Form>(control))
    ((__OS::Widget*)control.Handle())->ToWidget().position(control.Location().X, control.Location().Y + SystemInformation::GetCaptionHeight());
  else if (is<System::Windows::Forms::ProgressBar>(control)) {
    System::Drawing::Point formLocation = PointToForm(control, control.Location);
    int32 offset = control.Height > 6 ? (control.Height - 6) / 2 : 0;
    ((__OS::Widget*)control.Handle())->ToWidget().position(formLocation.X, formLocation.Y + offset);
  } else {
    System::Drawing::Point formLocation = PointToForm(control, control.Location);
    ((__OS::Widget*)control.Handle())->ToWidget().position(formLocation.X, formLocation.Y);
  }
}

void FormsApi::Control::SetParent(const System::Windows::Forms::Control& control) {
  if (((Fl_Group&)((__OS::Widget*)control.Handle())->ToWidget()).parent() != null)
    ((__OS::Widget*)control.Handle())->ToWidget().parent()->remove(((__OS::Widget*)control.Handle())->ToWidget());
  if (control.Parent() != null)
    ((__OS::Widget*)control.Parent()().Handle())->Container().add(((__OS::Widget*)control.Handle())->ToWidget());
}

void FormsApi::Control::SetSize(System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Form>(control)) {
    ((__OS::Widget*)control.Handle())->ToWidget().size(control.Size().Width, control.Size().Height - SystemInformation::GetCaptionHeight());
    control.ClientSize = System::Drawing::Size::Subtract(control.Size, {0, SystemInformation::GetCaptionHeight()});
  } else if (is<System::Windows::Forms::ProgressBar>(control)) {
    System::Drawing::Point formLocation = PointToForm(control, control.Location);
    int32 offset = control.Height > 6 ? (control.Height - 6) / 2 : 0;
    ((__OS::Widget*)control.Handle())->ToWidget().position(formLocation.X, formLocation.Y + offset);
    ((__OS::Widget*)control.Handle())->ToWidget().size(control.Size().Width, 6);
    control.ClientSize = control.Size;
  } else {
    ((__OS::Widget*)control.Handle())->ToWidget().size(control.Size().Width, control.Size().Height);
    control.ClientSize = control.Size;
  }
}

void FormsApi::Control::SetTabStop(const System::Windows::Forms::Control &control) {
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ToWidget().label(control.Text().c_str());
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  if (control.Visible)
    ((__OS::Widget*)control.Handle())->ToWidget().show();
  else
    ((__OS::Widget*)control.Handle())->ToWidget().hide();
}

#endif