#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>
#include "WindowProcedureApiWin32.hpp"
#include "../../include/Switch/System/Windows/Forms/Button.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::ButtonApi::Create(const System::Windows::Forms::Button& button) {
  HWND handle = CreateWindowEx(0, WC_BUTTON, button.Text().w_str().c_str(), WS_CHILD | BS_PUSHBUTTON | BS_MULTILINE | BS_CENTER | BS_VCENTER, button.Left, button.Top, button.Width, button.Height, (HWND)button.Parent()().Handle(), (HMENU)0, GetModuleHandle(NULL), (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

System::Drawing::Size Native::ButtonApi::GetDefaultSize() {
  return System::Drawing::Size(75, 25);
}

void Native::ButtonApi::SetIsDefault(const System::Windows::Forms::ButtonBase& button) {
  SetWindowLong((HWND)button.Handle(), GWL_STYLE, GetWindowLong((HWND)button.Handle(), GWL_STYLE) | (button.IsDefault ? BS_DEFPUSHBUTTON : BS_PUSHBUTTON));
  SetWindowLong((HWND)button.Handle(), GWL_STYLE, GetWindowLong((HWND)button.Handle(), GWL_STYLE) & (button.IsDefault ? ~BS_PUSHBUTTON : ~BS_DEFPUSHBUTTON));
}

#endif
