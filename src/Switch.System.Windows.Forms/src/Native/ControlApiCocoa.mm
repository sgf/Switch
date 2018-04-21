#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "WindowProcedureApiCocoa.hpp"
#include <Switch/System/Diagnostics/Debug.hpp>
#include "../../include/Switch/System/Windows/Forms/CheckBox.hpp"
#include "../../include/Switch/System/Windows/Forms/Control.hpp"
#include "../../include/Switch/System/Windows/Forms/GroupBox.hpp"
#include "../../include/Switch/System/Windows/Forms/Label.hpp"
#include "../../include/Switch/System/Windows/Forms/ProgressBar.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"
#include "../../include/Switch/System/Windows/Forms/RadioButton.hpp"
#include "../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../include/Switch/System/Windows/Forms/TabPage.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface ControlCocoa : NSControl
- (IBAction) Click:(id)sender;
@end

@implementation ControlCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(Native::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr Native::ControlApi::Create(const System::Windows::Forms::Control& control) {
  ControlCocoa *handle = [[[ControlCocoa alloc] init] autorelease];
  if (is<System::Windows::Forms::Form>(control.Parent()))
    [[(NSWindow*)control.Parent()().Handle() contentView] addSubview: handle];

  [handle setStringValue:[NSString stringWithUTF8String:control.Text().c_str()]];
  [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [handle setWantsLayer:YES];
  [handle setTarget:handle];
  [handle setAction:@selector(Click:)];
  Native::WindowProcedure::Controls[(intptr)handle] = control;
  SendMessage((intptr)handle, WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)handle;
}

void Native::ControlApi::DefWndProc(System::Windows::Forms::Message& message) {
  NSEvent* event = (NSEvent*)message.Handle();
  if (event.type == NSEventTypeKeyUp)
    [[NSApp keyWindow] sendEvent:event];
  else
    [NSApp sendEvent:event];
}

void Native::ControlApi::Destroy(const System::Windows::Forms::Control& control) {
  if (!is<System::Windows::Forms::Button>(control))
    return;
  Native::WindowProcedure::Controls.Remove((intptr)((Native::IWidget*)control.Handle())->Handle());
  Message message = Message::Create((intptr)((Native::IWidget*)control.Handle())->Handle(), WM_DESTROY, 0, 0, 0, IntPtr::Zero);
  const_cast<System::Windows::Forms::Control&>(control).WndProc(message);
  delete (Native::IWidget*)control.Handle();
}

intptr Native::ControlApi::GetHandleWindowFromDeviceContext(intptr hdc) {
  return hdc;
}

System::Drawing::Size Native::ControlApi::GetTextSize(const System::Windows::Forms::Control &control) {
  /*
  NSSize size = [[NSString stringWithUTF8String:control.Text().c_str()] sizeWithAttributes:[NSDictionary dictionaryWithObject:(NSFont*)control.Font().ToHFont() forKey:NSFontAttributeName]];
  return System::Drawing::Size(size.width, size.height);
   */
  NSSize size = [[NSAttributedString alloc] initWithString:[NSString stringWithUTF8String:control.Text().c_str()] attributes:[NSDictionary dictionaryWithObjectsAndKeys:[NSString stringWithUTF8String:control.Font().Name().c_str()], NSFontNameAttribute, [NSNumber numberWithFloat:control.Font().SizeInPoints], NSFontSizeAttribute, nil]].size;
  return System::Drawing::Size(size.width, size.height);
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
  if (control) {
    SetBackColor(control());
  }
}

void Native::ControlApi::SetBackColor(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->BackColor(control.BackColor);
}

void Native::ControlApi::SetClientSize(System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->ClientSize(control.ClientSize);
  control.Size = ((Native::IWidget*)control.Handle())->Size();
}

void Native::ControlApi::SetCursor(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->Cursor(control.Cursor);
}

void Native::ControlApi::SetEnabled(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->Enabled(control.Enabled);
}

bool Native::ControlApi::SetFocus(const System::Windows::Forms::Control& control) {
  return true;
}

void Native::ControlApi::SetFont(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->Font(control.Font);
}

void Native::ControlApi::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  if (control) {
    SetForeColor(control());
  }
}

void Native::ControlApi::SetForeColor(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->ForeColor(control.ForeColor);
}

void Native::ControlApi::SetLocation(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->Location(control.Parent == null ? null : (Native::IWidget*)control.Parent()->Handle(), control.Location);
}

void Native::ControlApi::SetParent(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->RemoveParent();
  if (control.Parent != null)
    ((Native::IWidget*)control.Parent()->Handle())->AddChild((IWidget*)control.Handle());
}

void Native::ControlApi::SetSize(System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->Size(control.Size);
  control.ClientSize = ((Native::IWidget*)control.Handle())->ClientSize();
}

void Native::ControlApi::SetTabStop(const System::Windows::Forms::Control& control) {
}

void Native::ControlApi::SetText(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->Text(control.Text);
}

void Native::ControlApi::SetVisible(const System::Windows::Forms::Control& control) {
  ((Native::IWidget*)control.Handle())->Visible(control.Visible);
}

#endif
