#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Brush.hpp"
#include "../../include/Switch/System/Drawing/Color.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::SolidBrushApi::Create(const Color& color) {
  return (intptr)::CreateSolidBrush(RGB(color.R, color.G, color.B));
}

void Native::SolidBrushApi::Release(intptr handle) {
  DeleteObject((HGDIOBJ)handle);
}

#endif
