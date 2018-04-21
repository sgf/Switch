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

@interface CocoaControl : NSScrollView
@property (strong) NSCursor* cursor;
@property Native::IWidget* widget;
@end

@implementation CocoaControl
- (id)initWithIWidget:(Native::IWidget*)iWidget {
  [super init];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [self setBorderType:NSNoBorder];
  [self setDrawsBackground:NO];
  [self setWidget:iWidget];
  return self;
}

- (void)resetCursorRects {
  [super resetCursorRects];
  if ([self cursor] != nil)
    [self addCursorRect:[self bounds] cursor:[self cursor]];
}
@end

namespace Native {
  class Control : public WidgetControl<CocoaControl> {
  public:
    Control() {this->handle = [[CocoaControl alloc] initWithIWidget:this];}
    void BackColor(const System::Drawing::Color& color) override {}
    System::Drawing::Size ClientSize() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void ClientSize(const System::Drawing::Size& size) override {[this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];}
    void Cursor(const System::Windows::Forms::Cursor& cursor) override {[this->handle setCursor:(NSCursor *)cursor.Handle()];}
    void Enabled(bool enabled) override {}
    void Font(const System::Drawing::Font& font) override {}
    void ForeColor(const System::Drawing::Color& color) override {}
    void IsDefault(bool isDefault) {}
    void RemoveParent() override {[this->handle removeFromSuperview];}
    System::Drawing::Size Size() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void Size(const System::Drawing::Size& size) override {[this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];}
    void Text(const string& text) override {}
    NSView* View() override {return this->handle;}
    void Visible(bool visible) override {[this->handle setHidden:visible ? NO : YES];}
  };
}

intptr Native::ControlApi::Create(const System::Windows::Forms::Control& control) {
  Native::Control* widget = new Native::Control();
  Native::WindowProcedure::Controls[(intptr)widget] = control;
  SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
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
