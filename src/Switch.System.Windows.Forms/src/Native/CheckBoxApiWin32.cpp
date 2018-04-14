#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "WindowProcedureApiWin32.hpp"
#include "../../include/Switch/System/Windows/Forms/CheckBox.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::CheckBoxApi::Create(const System::Windows::Forms::CheckBox& checkBox) {
  HWND handle = CreateWindowEx(0, WC_BUTTON, checkBox.Text().w_str().c_str(), WS_CHILD | BS_3STATE, checkBox.Left, checkBox.Top, checkBox.Width, checkBox.Height, (HWND)checkBox.Parent()().Handle(), (HMENU)0, GetModuleHandle(NULL), (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

void Native::CheckBoxApi::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
}

void Native::CheckBoxApi::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  SendMessage((HWND)checkBox.Handle(), BM_SETCHECK, (int32)checkBox.CheckState(), 0);
}

#endif
