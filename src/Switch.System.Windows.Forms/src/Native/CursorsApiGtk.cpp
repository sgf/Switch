#if defined(__linux__)

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
  return System::Drawing::Point();
}

void Native::CursorApi::SetPosition(const System::Drawing::Point& position) {
}

void Native::CursorApi::Hide() {
}

void Native::CursorApi::Show() {
}

#endif
