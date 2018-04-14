#if defined(__APPLE__)
#include <Quartz/Quartz.h>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/Cursor.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::CursorApi::Create() {
  return IntPtr::Zero;
}

void Native::CursorApi::Destroy(intptr handle) {
  if (handle != IntPtr::Zero) {
    
  }
}

System::Drawing::Point Native::CursorApi::GetPosition() {
  NSPoint position = [NSEvent mouseLocation];
  return System::Drawing::Point(position.x, position.y);
}

void Native::CursorApi::SetPosition(const System::Drawing::Point &position) {
  CGDisplayMoveCursorToPoint(kCGDirectMainDisplay, CGPointMake(position.X, position.Y));
}

void Native::CursorApi::Hide() {
  CGDisplayHideCursor(kCGDirectMainDisplay);
}

void Native::CursorApi::Show() {
  CGDisplayShowCursor(kCGDirectMainDisplay);
}

#endif
