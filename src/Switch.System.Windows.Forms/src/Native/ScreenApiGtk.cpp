#if defined(__linux__)
#include <gtkmm.h>

#include "Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

Array<Screen> __screens__::__get_screens__() {
  List<Screen> screens;

  return screens.ToArray();
}

Array<Screen> Native::ScreenApi::GetScreens() {
  return __screens__::__get_screens__();
}

#endif
