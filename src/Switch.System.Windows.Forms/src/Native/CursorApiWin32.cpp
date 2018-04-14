#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Switch/Undef.hpp>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/Cursor.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::CursorApi::Create() {
  return IntPtr::Zero;
}

void Native::CursorApi::Destroy(intptr handle) {

}

System::Drawing::Point Native::CursorApi::GetPosition() {
  POINT position;
  GetCursorPos(&position);
  return System::Drawing::Point(position.x, position.y);
}

void Native::CursorApi::SetPosition(const System::Drawing::Point& position) {
  SetCursorPos(position.X, position.Y);
}

void Native::CursorApi::Hide() {
  ShowCursor(FALSE);
}

void Native::CursorApi::Show() {
  ShowCursor(TRUE);
}

#endif
