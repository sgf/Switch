#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>
#include "WindowProcedureApiWin32.hpp"
#include "../../include/Switch/System/Windows/Forms/Panel.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::PanelApi::Create(const System::Windows::Forms::Panel& panel) {
  HWND handle = CreateWindowEx(WS_EX_CONTROLPARENT, WC_DIALOG, panel.Text().w_str().c_str(), WS_CHILD | WS_CLIPSIBLINGS, panel.Left, panel.Top, panel.Width, panel.Height, (HWND)panel.Parent()().Handle(), (HMENU)0, GetModuleHandle(NULL), (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

System::Drawing::Size Native::PanelApi::GetDefaultSize() {
  return System::Drawing::Size(200, 100);
}

void Native::PanelApi::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  SetWindowLongPtr((HWND)panel.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)panel.Handle(), GWL_STYLE) & ~WS_BORDER);
  SetWindowLongPtr((HWND)panel.Handle(), GWL_EXSTYLE, GetWindowLongPtr((HWND)panel.Handle(), GWL_EXSTYLE) & ~WS_EX_CLIENTEDGE);
  switch (panel.BorderStyle) {
  case BorderStyle::FixedSingle: SetWindowLongPtr((HWND)panel.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)panel.Handle(), GWL_STYLE) | WS_BORDER); break;
  case BorderStyle::Fixed3D: SetWindowLongPtr((HWND)panel.Handle(), GWL_EXSTYLE, GetWindowLongPtr((HWND)panel.Handle(), GWL_EXSTYLE) | WS_EX_CLIENTEDGE); break;
  }
  SetWindowPos((HWND)panel.Handle(), NULL, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
}

#endif
