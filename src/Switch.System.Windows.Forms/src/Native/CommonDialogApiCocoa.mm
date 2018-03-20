#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/ColorDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/OpenFileDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/SaveFileDialog.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

bool Native::CommonDialog::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog &colorDialog) {
  return false;
}

bool Native::CommonDialog::RunOpenFileDialog(intptr hwnd, System::Windows::Forms::OpenFileDialog &openFileDialog) {
  return false;
}

bool Native::CommonDialog::RunSaveFileDialog(intptr hwnd, System::Windows::Forms::SaveFileDialog &saveFileDialog) {
  return false;
}

#endif
