#if defined(__APPLE__)
#include "Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

bool Native::CommonDialog::RunColorDialog(intptr hwnd, const System::Windows::Forms::ColorDialog &colorDialog) {
  return false;
}

#endif
