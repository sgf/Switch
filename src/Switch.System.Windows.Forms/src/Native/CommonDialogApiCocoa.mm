#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

bool Native::CommonDialog::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog &colorDialog) {
  return false;
}

#endif
