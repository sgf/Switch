#if defined(__linux__)
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Brush.hpp"
#include "../../include/Switch/System/Drawing/Pen.hpp"
#include "../../include/Switch/System/Drawing/Rectangle.hpp"

#undef get_

#undef interface_
#undef get_
#undef set_

using namespace System;
using namespace System::Drawing;

intptr Native::GdiApi::GetDeviceContext(intptr hwnd) {
  return hwnd;
}

/*
 intptr Native::GdiApi::BeginPaint(intptr hwnd, System::Drawing::Rectangle& clipRectangle) {
 return IntPtr::Zero;
 }

 void Native::GdiApi::EndPaint(intptr hwnd, intptr hdc) {
 }*/

void Native::GdiApi::ReleaseDeviceContext(intptr hwnd, intptr hdc) {
}

System::Drawing::Rectangle Native::GdiApi::GetClipRectangleFromHdc(intptr hdc) {
  return {};
}

System::Drawing::Rectangle Native::GdiApi::GetClipRectangleFromHwnd(intptr hwnd) {
  return {};
}

void Native::GdiApi::DrawRectangle(intptr handle, const System::Drawing::Pen& pen, int32 x, int32 y, int32 w, int32 h) {
}

void Native::GdiApi::FillPie(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
}

void Native::GdiApi::FillRectangle(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h) {
}

#endif
