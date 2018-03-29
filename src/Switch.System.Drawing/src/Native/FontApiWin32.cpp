#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>
#undef CreateFont

#include "Api.hpp"
#include "../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../include/Switch/System/Drawing/FontStyle.hpp"
#include "../../include/Switch/System/Drawing/GraphicsUnit.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::FontApi::CreateFont(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet, bool gdiVerticalFont) {
  return IntPtr::Zero;
}

void Native::FontApi::DeleteFont(intptr hfont) {
}

#endif
