#if defined(__linux__)

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/window.h>
#include "Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

bool Native::CommonDialog::RunColorDialog(intptr hwnd, const System::Windows::Forms::ColorDialog& colorDialog) {
  return false;
}

#endif
