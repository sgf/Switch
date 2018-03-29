#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Drawing2D/DashStyle.hpp"
#include "../../include/Switch/System/Drawing/Color.hpp"
#include "../../include/Switch/System/Drawing/Pen.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::PenApi::CreatePen(const System::Drawing::Drawing2D::DashStyle& dashStyle, int32 width, const Color& color) {
  return (intptr)::CreatePen((int32)dashStyle, width, RGB(color.R, color.G, color.B));
}

void Native::PenApi::DeletePen(intptr handle) {
  DeleteObject((HGDIOBJ)handle);
}

#endif
