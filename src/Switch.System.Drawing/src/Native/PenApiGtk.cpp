#if defined(__linux__)
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Drawing2D/DashStyle.hpp"
#include "../../include/Switch/System/Drawing/Color.hpp"
#include "../../include/Switch/System/Drawing/Pen.hpp"

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>

using namespace System;
using namespace System::Drawing;

namespace {
}

intptr Native::PenApi::CreatePen(const System::Drawing::Drawing2D::DashStyle& dashStyle, int32 width, const Color& color) {
  return IntPtr::Zero;
}

void Native::PenApi::DeletePen(intptr handle) {
}

#endif
