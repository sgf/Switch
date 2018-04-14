#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>
#include "WindowProcedureApiWin32.hpp"
#include "../../include/Switch/System/Windows/Forms/TabPage.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::TabPageApi::Create(const System::Windows::Forms::TabPage& tabPage) {
  HWND handle = CreateWindowEx(WS_EX_CONTROLPARENT, WC_DIALOG, tabPage.Text().w_str().c_str(), WS_CHILD | WS_CLIPSIBLINGS, tabPage.Left, tabPage.Top, tabPage.Width, tabPage.Height, (HWND)tabPage.Parent()().Handle(), (HMENU)0, GetModuleHandle(NULL), (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

void Native::TabPageApi::SetBorderStyle(const System::Windows::Forms::TabPage& tabPage) {
  SetWindowLongPtr((HWND)tabPage.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)tabPage.Handle(), GWL_STYLE) & ~WS_BORDER);
  SetWindowLongPtr((HWND)tabPage.Handle(), GWL_EXSTYLE, GetWindowLongPtr((HWND)tabPage.Handle(), GWL_EXSTYLE) & ~WS_EX_CLIENTEDGE);
  switch (tabPage.BorderStyle) {
  case BorderStyle::FixedSingle: SetWindowLongPtr((HWND)tabPage.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)tabPage.Handle(), GWL_STYLE) | WS_BORDER); break;
  case BorderStyle::Fixed3D: SetWindowLongPtr((HWND)tabPage.Handle(), GWL_EXSTYLE, GetWindowLongPtr((HWND)tabPage.Handle(), GWL_EXSTYLE) | WS_EX_CLIENTEDGE); break;
  }
  SetWindowPos((HWND)tabPage.Handle(), NULL, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
}

#endif
