#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"
#include "WidgetCocoa.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;

Native::WindowProcedure::ControlDictionary Native::WindowProcedure::Controls;
bool Native::WindowProcedure::messageLoopRunning = false;
bool Native::WindowProcedure::hover = false;

int32 Native::WindowProcedure::GetMouseButtonState(NSEvent* event) {
  int32 state = 0;
  if ([event buttonNumber] == 1) state &= MK_LBUTTON;
  if ([event buttonNumber] == 2) state &= MK_MBUTTON;
  if ([event buttonNumber] == 3) state &= MK_RBUTTON;
  return state;
}

void Native::WindowProcedure::WndProc(NSEvent* event) {
  // {NSEventTypeLeftMouseDragged, WM_...}, {NSEventTypeRightMouseDragged, WM_...}, {NSEventTypeKeyDown, WM_KEYDOWN}, {NSEventTypeKeyUp, WM_KEYUP}, {NSEventTypeFlagsChanged, WM_...}, {NSEventTypeAppKitDefined, WM_...}, {NSEventTypeSystemDefined, WM_...}, {NSEventTypeApplicationDefined, WM_...}, {NSEventTypePeriodic, WM_...}, {NSEventTypeCursorUpdate, WM_SETCURSOR}, {NSEventTypeScrollWheel, WM_MOUSEWHEEL}, {NSEventTypeTabletPoint, WM_...}, {NSEventTypeTabletProximity, WM_...}, {NSEventTypeOtherMouseDragged, WM_...},
  static System::Collections::Generic::Dictionary<int32, delegate<void, NSEvent*, System::Windows::Forms::Control&>> events = {
    {NSEventTypeMouseEntered, WindowProcedure::MouseEnterEvent}, {NSEventTypeMouseExited, WindowProcedure::MouseLeaveEvent}, {NSEventTypeLeftMouseDown, WindowProcedure::LeftMouseDownEvent}, {NSEventTypeLeftMouseUp, WindowProcedure::LeftMouseUpEvent}, {NSEventTypeRightMouseDown, WindowProcedure::RightMouseDownEvent}, {NSEventTypeRightMouseUp, WindowProcedure::RightMouseUpEvent}, {NSEventTypeMouseMoved, WindowProcedure::MouseMoveEvent}, {NSEventTypeOtherMouseDown, WindowProcedure::OtherMouseDownEvent}, {NSEventTypeOtherMouseUp, WindowProcedure::OtherMouseUpEvent}
  };
  @autoreleasepool {
    if (events.ContainsKey([event type]) && Controls.ContainsKey((intptr)[event window]))
      events[[event type]](event, Controls[(intptr)[event window]]);
    else
      [NSApp sendEvent:event];
  }
}

ref<System::Windows::Forms::Control> Native::WindowProcedure::GetChildAtPoint(const System::Windows::Forms::Control& control, System::Drawing::Point& point) {
  ref<System::Windows::Forms::Control> target = control;
  if (target->Parent != null)
    point.Offset(-target->Left, -target->Top);
  for (ref<System::Windows::Forms::Control> child : target->Controls()) {
    System::Drawing::Point childLocation = point;
    childLocation.Offset(-child->Left, -child->Top);
    if (child->Bounds().Contains(childLocation)) {
      target = GetChildAtPoint(child, point);
      break;
    }
  }
  return target;
}

int32 Native::WindowProcedure::GetMouseXCoordinateRelativeToClientArea(NSEvent* event, System::Windows::Forms::Control& control) {
  int32 captionHeight = !is<System::Windows::Forms::Form>(control) || as<System::Windows::Forms::Form>(control).FormBorderStyle == System::Windows::Forms::FormBorderStyle::None ? 0 : Native::SystemInformationApi::GetCaptionHeight();
  System::Drawing::Point location(event.locationInWindow.x, event.window.frame.size.height - event.locationInWindow.y - captionHeight);
  return location.X;
}

int32 Native::WindowProcedure::GetMouseYCoordinateRelativeToClientArea(NSEvent* event, System::Windows::Forms::Control& control) {
  int32 captionHeight = !is<System::Windows::Forms::Form>(control) || as<System::Windows::Forms::Form>(control).FormBorderStyle == System::Windows::Forms::FormBorderStyle::None ? 0 : Native::SystemInformationApi::GetCaptionHeight();
  System::Drawing::Point location(event.locationInWindow.x, event.window.frame.size.height - event.locationInWindow.y - captionHeight);
  return location.Y;
}

void Native::WindowProcedure::MouseEnterEvent(NSEvent* event, System::Windows::Forms::Control& control) {
  //System::Diagnostics::Debug::WriteLine(string::Format("WM_MOUSEENTER on {0}", control.Name));
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)[event window], WM_MOUSEENTER, notUsed, notUsed, 0, (intptr)event);
  hover = true;
  control.WndProc(message);
}

void Native::WindowProcedure::MouseLeaveEvent(NSEvent* event, System::Windows::Forms::Control& control) {
  //System::Diagnostics::Debug::WriteLine(string::Format("WM_MOUSELEAVE on {0}", control.Name));
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)[event window], WM_MOUSELEAVE, notUsed, notUsed, 0, (intptr)event);
  hover = false;
  control.WndProc(message);
}

void Native::WindowProcedure::LeftMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control) {
  System::Drawing::Point location(GetMouseXCoordinateRelativeToClientArea(event, control), GetMouseYCoordinateRelativeToClientArea(event, control));
  ref<System::Windows::Forms::Control> target = GetChildAtPoint(control, location);
  //System::Diagnostics::Debug::WriteLine(string::Format("WM_LBUTTONDOWN at {0} on {1}", location, target->Name));
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)((Native::IWidget*)target->Handle())->Handle(), WM_LBUTTONDOWN, GetMouseButtonState(event), location.X + (location.Y << 16), 0, (intptr)event);
  target->WndProc(message);
}

void Native::WindowProcedure::LeftMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control) {
  System::Drawing::Point location(GetMouseXCoordinateRelativeToClientArea(event, control), GetMouseYCoordinateRelativeToClientArea(event, control));
  ref<System::Windows::Forms::Control> target = GetChildAtPoint(control, location);
  //System::Diagnostics::Debug::WriteLine(string::Format("WM_LBUTTONUP at {0} on {1}", location, target->Name));
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)((Native::IWidget*)target->Handle())->Handle(), WM_LBUTTONUP, GetMouseButtonState(event), location.X + (location.Y << 16), 0, (intptr)event);
  target->WndProc(message);
}

void Native::WindowProcedure::OtherMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control) {
  System::Drawing::Point location(GetMouseXCoordinateRelativeToClientArea(event, control), GetMouseYCoordinateRelativeToClientArea(event, control));
  ref<System::Windows::Forms::Control> target = GetChildAtPoint(control, location);
  //System::Diagnostics::Debug::WriteLine(string::Format("WM_MBUTTONUP at {0} on {1}", location, target->Name));
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)((Native::IWidget*)target->Handle())->Handle(), WM_MBUTTONUP, GetMouseButtonState(event), location.X + (location.Y << 16), 0, (intptr)event);
  target->WndProc(message);
}

void Native::WindowProcedure::OtherMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control) {
  System::Drawing::Point location(GetMouseXCoordinateRelativeToClientArea(event, control), GetMouseYCoordinateRelativeToClientArea(event, control));
  ref<System::Windows::Forms::Control> target = GetChildAtPoint(control, location);
  //System::Diagnostics::Debug::WriteLine(string::Format("WM_MBUTTONDOWN at {0} on {1}", location, target->Name));
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)((Native::IWidget*)target->Handle())->Handle(), WM_MBUTTONDOWN, GetMouseButtonState(event), location.X + (location.Y << 16), 0, (intptr)event);
  target->WndProc(message);
}

void Native::WindowProcedure::RightMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control) {
  System::Drawing::Point location(GetMouseXCoordinateRelativeToClientArea(event, control), GetMouseYCoordinateRelativeToClientArea(event, control));
  ref<System::Windows::Forms::Control> target = GetChildAtPoint(control, location);
  //System::Diagnostics::Debug::WriteLine(string::Format("WM_RBUTTONDOWN at {0} on {1}", location, target->Name));
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)((Native::IWidget*)target->Handle())->Handle(), WM_RBUTTONDOWN, GetMouseButtonState(event), location.X + (location.Y << 16), 0, (intptr)event);
  target->WndProc(message);
}

void Native::WindowProcedure::RightMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control) {
  System::Drawing::Point location(GetMouseXCoordinateRelativeToClientArea(event, control), GetMouseYCoordinateRelativeToClientArea(event, control));
  ref<System::Windows::Forms::Control> target = GetChildAtPoint(control, location);
  //System::Diagnostics::Debug::WriteLine(string::Format("WM_RBUTTONUP at {0} on {1}", location, target->Name));
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)((Native::IWidget*)target->Handle())->Handle(), WM_RBUTTONUP, GetMouseButtonState(event), location.X + (location.Y << 16), 0, (intptr)event);
  target->WndProc(message);
}

void Native::WindowProcedure::MouseMoveEvent(NSEvent* event, System::Windows::Forms::Control& control) {
  System::Drawing::Point location(GetMouseXCoordinateRelativeToClientArea(event, control), GetMouseYCoordinateRelativeToClientArea(event, control));
  ref<System::Windows::Forms::Control> target = GetChildAtPoint(control, location);
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)((Native::IWidget*)target->Handle())->Handle(), WM_SETCURSOR, (intptr)control.Handle(), (intptr)0x20000001, 0, (intptr)event);
  control.WndProc(message);
  if (hover) {
    message = System::Windows::Forms::Message::Create((intptr)((Native::IWidget*)target->Handle())->Handle(), WM_MOUSEHOVER, GetMouseButtonState(event), location.X + (location.Y << 16), 0, (intptr)event);
    target->WndProc(message);
  }
  message = System::Windows::Forms::Message::Create((intptr)((Native::IWidget*)target->Handle())->Handle(), WM_MOUSEMOVE, GetMouseButtonState(event), location.X + (location.Y << 16), 0, (intptr)event);
  target->WndProc(message);
}

#endif
