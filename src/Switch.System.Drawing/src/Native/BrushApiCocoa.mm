#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "Api.hpp"
#include "../../include/Switch/System/Drawing/Brush.hpp"
#include "../../include/Switch/System/Drawing/Color.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::BrushApi::CreateSolidBrush(const Color& color) {
  return IntPtr::Zero;
}

void Native::BrushApi::DeleteBrush(intptr handle) {
}

#endif
