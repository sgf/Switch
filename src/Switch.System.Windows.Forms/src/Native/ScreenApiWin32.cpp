#if defined(_WIN32)

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "WindowProcedureApiWin32.hpp"

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
