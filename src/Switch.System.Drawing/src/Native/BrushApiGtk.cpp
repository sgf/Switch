#if defined(__linux__)
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Brush.hpp"
#include "../../include/Switch/System/Drawing/Color.hpp"

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>

using namespace System;
using namespace System::Drawing;

intptr Native::BrushApi::CreateSolidBrush(const Color& color) {
  return IntPtr::Zero;
}

void Native::BrushApi::DeleteBrush(intptr handle) {
}

#endif
