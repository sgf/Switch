#if defined(__APPLE__)
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

namespace {
  class CocoaApi static_ {
  public:
    static NSColor* FromColor(const System::Drawing::Color& color) {
      return [NSColor colorWithCalibratedRed:as<double>(color.R()) / 0xFF green:as<double>(color.G()) / 0xFF blue:as<double>(color.B()) / 0xFF alpha:as<double>(color.A()) / 0xFF];
    }
    
    static System::Drawing::Rectangle GetBounds(const System::Windows::Forms::Control& control) {
      if (is<System::Windows::Forms::Form>(control))
        return System::Drawing::Rectangle(control.Left + Screen::AllScreens()[0].WorkingArea().X, Screen::AllScreens()[0].Bounds().Height - Screen::AllScreens()[0].WorkingArea().Y - control.Top - control.Height, control.Width, control.Height);
      if (is<System::Windows::Forms::TabPage>(control))
        return System::Drawing::Rectangle(control.Left, control.Top, control.Width, control.Height);
      int32 captionHeight = !is<Form>(control.Parent()) || as<Form>(control.Parent())().FormBorderStyle == FormBorderStyle::None ? 0 : Native::SystemInformationApi::GetCaptionHeight();
      return System::Drawing::Rectangle(control.Left, control.Parent()().Height - control.Height - control.Top - captionHeight, control.Width, control.Height);
    }
  };
}

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
  Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
  const_cast<System::Windows::Forms::Control&>(control).WndProc(message);
  return (intptr)handle;
}

void Native::ControlApi::DefWndProc(System::Windows::Forms::Message& message) {
  @autoreleasepool {
    NSEvent* event = (NSEvent*)message.Handle();
    if (event.type == NSEventTypeKeyUp)
      [[NSApp keyWindow] sendEvent:event];
    else
      [NSApp sendEvent:event];
  }
}

void Native::ControlApi::Destroy(const System::Windows::Forms::Control& control) {
  Native::WindowProcedure::Controls.Remove(control.Handle);
  Message message = Message::Create(control.Handle, WM_DESTROY, 0, 0, 0, IntPtr::Zero);
  const_cast<System::Windows::Forms::Control&>(control).WndProc(message);
}

intptr Native::ControlApi::GetHandleWindowFromDeviceContext(intptr hdc) {
  return hdc;
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
  if (is<System::Windows::Forms::Form>(control)) {
    ((NSWindow*)control.Handle()).backgroundColor = CocoaApi::FromColor(control.BackColor);
  } else if (is<System::Windows::Forms::Label>(control)) {
    ((NSTextField*)control.Handle()).drawsBackground = YES;
    ((NSTextField*)control.Handle()).backgroundColor = CocoaApi::FromColor(control.BackColor);
  } else if (is<System::Windows::Forms::GroupBox>(control)) {
    ((NSBox*)control.Handle()).contentView.layer.backgroundColor = CocoaApi::FromColor(control.BackColor).CGColor;
  } else if (is<System::Windows::Forms::TabPage>(control)) {
    //[(NSTabViewItem*)control.Handle() setWantsLayer:YES];
    //((NSTabViewItem*)control.Handle()).layer.backgroundColor = CocoaApi::FromColor(control.BackColor).CGColor;
  } else if (is<System::Windows::Forms::Panel>(control)) {
    ((NSScrollView*)control.Handle()).backgroundColor = CocoaApi::FromColor(control.BackColor);
  } else {
    [(NSControl*)control.Handle() setWantsLayer:YES];
    ((NSControl*)control.Handle()).layer.backgroundColor = CocoaApi::FromColor(control.BackColor).CGColor;
  }
}

void Native::ControlApi::SetClientSize(System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Form>(control)) {
      [(NSWindow*)control.Handle() setContentSize:NSMakeSize(control.ClientSize().Width(), control.ClientSize().Height())];
      control.Size = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width, ((NSControl*)control.Handle()).frame.size.height);
    } else  if (is<System::Windows::Forms::Button>(control)) {
      [(NSButton*)control.Handle() setFrameSize:NSMakeSize(control.ClientSize().Width + 2, control.ClientSize().Height + 2)];
      control.Size = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width - 2, ((NSControl*)control.Handle()).frame.size.height - 2);
    } else {
      [(NSControl*)control.Handle() setFrameSize:NSMakeSize(control.ClientSize().Width(), control.ClientSize().Height())];
      control.Size = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width, ((NSControl*)control.Handle()).frame.size.height);
    }
  }
}

void Native::ControlApi::SetEnabled(const System::Windows::Forms::Control& control) {
  //if (!is<System::Windows::Forms::ContainerControl>(control) && !is<System::Windows::Forms::ProgressBar>(control))
  //  [(NSControl*)control.Handle() setEnabled:control.Enabled()];
}

bool Native::ControlApi::SetFocus(const System::Windows::Forms::Control& control) {
  return true;
}

void Native::ControlApi::SetFont(const System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Button>(control) || is<System::Windows::Forms::CheckBox>(control) || is<System::Windows::Forms::Label>(control) || is<System::Windows::Forms::RadioButton>(control))
    [(NSControl*)control.Handle() setFont:((NSFont*)control.Font().ToHFont())];
}

void Native::ControlApi::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  if (control) {
    SetForeColor(control());
  }
}

void Native::ControlApi::SetForeColor(const System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Label>(control))
    [(NSTextField*)control.Handle() setTextColor:CocoaApi::FromColor(control.ForeColor)];
}

void Native::ControlApi::SetLocation(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = CocoaApi::GetBounds(control);
    if (is<System::Windows::Forms::Button>(control)) {
      [(NSControl*)control.Handle() setFrameOrigin:NSMakePoint(bounds.Left - 1, bounds.Top - 1)];
    } else if (is<System::Windows::Forms::TabPage>(control)) {
      // Don't set the location
    }  else {
      [(NSControl*)control.Handle() setFrameOrigin:NSMakePoint(bounds.Left, bounds.Top)];
    }
  }
}

void Native::ControlApi::SetParent(const System::Windows::Forms::Control& control) {
}

void Native::ControlApi::SetSize(System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Form>(control)) {
      [((NSWindow*)control.Handle()) setFrame:NSMakeRect(0, 0, control.Width(), control.Height()) display:true];
      control.ClientSize = System::Drawing::Size(((NSWindow*)control.Handle()).contentLayoutRect.size.width, ((NSWindow*)control.Handle()).contentLayoutRect.size.height);
    } else if (is<System::Windows::Forms::TabPage>(control)) {
      // don't change the size...
    } else if (is<System::Windows::Forms::Button>(control)) {
      [(NSButton*)control.Handle() setFrameSize:NSMakeSize(control.Width() + 2, control.Height() + 2)];
      control.ClientSize = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width - 2, ((NSControl*)control.Handle()).frame.size.height - 2);
    } else {
      [(NSControl*)control.Handle() setFrameSize:NSMakeSize(control.Width(), control.Height())];
      control.ClientSize = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width, ((NSControl*)control.Handle()).frame.size.height);
    }
  }
}

void Native::ControlApi::SetTabStop(const System::Windows::Forms::Control& control) {
}

void Native::ControlApi::SetText(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Button>(control) || is<System::Windows::Forms::GroupBox>(control))
      [(NSButton*)control.Handle()  setTitle:[NSString stringWithUTF8String:control.Text().c_str()]];
    else if (is<System::Windows::Forms::Form>(control))
      [(NSWindow*)control.Handle()  setTitle:[NSString stringWithUTF8String:control.Text().c_str()]];
    else if (!is<System::Windows::Forms::Panel>(control) && !is<System::Windows::Forms::ProgressBar>(control) && !is<System::Windows::Forms::TabControl>(control))
      [(NSControl*)control.Handle()  setStringValue:[NSString stringWithUTF8String:control.Text().c_str()]];
  }
}

void Native::ControlApi::SetVisible(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Form>(control)) {
      if (control.Visible ) {
        [(NSWindow*)control.Handle() makeKeyAndOrderFront:NSApp];
        [NSApp activateIgnoringOtherApps:YES];
      } else {
        [(NSWindow*)control.Handle() orderOut:nil];
      }
    } else if (is<System::Windows::Forms::TabPage>(control)) {
      // Don't chnage the visibility
    } else {
      [(NSControl*)control.Handle() setHidden:control.Visible ? NO : YES];
    }
  }
}

#endif
