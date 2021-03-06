#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>
#include "WindowProcedureApiWin32.hpp"
#include "../../include/Switch/System/Windows/Forms/Label.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace Native;

intptr Native::LabelApi::Create(const System::Windows::Forms::Label& label) {
  HWND handle = CreateWindowEx(0, WC_STATIC, label.Text().w_str().c_str(), WS_CHILD, label.Left, label.Top, label.Width, label.Height, (HWND)label.Parent()().Handle(), (HMENU)0, GetModuleHandle(NULL), (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

System::Drawing::Size Native::LabelApi::GetDefaultSize() {
  return System::Drawing::Size(100, 23);
}

void Native::LabelApi::SetBorderStyle(const System::Windows::Forms::Label& label) {
  SetWindowLongPtr((HWND)label.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)label.Handle(), GWL_STYLE) & ~WS_BORDER);
  SetWindowLongPtr((HWND)label.Handle(), GWL_EXSTYLE, GetWindowLongPtr((HWND)label.Handle(), GWL_EXSTYLE) & ~WS_EX_CLIENTEDGE);
  switch (label.BorderStyle) {
  case BorderStyle::FixedSingle: SetWindowLongPtr((HWND)label.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)label.Handle(), GWL_STYLE) | WS_BORDER); break;
  case BorderStyle::Fixed3D: SetWindowLongPtr((HWND)label.Handle(), GWL_EXSTYLE, GetWindowLongPtr((HWND)label.Handle(), GWL_EXSTYLE) | WS_EX_CLIENTEDGE); break;
  }
  SetWindowPos((HWND)label.Handle(), NULL, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
}

void Native::LabelApi::SetTextAlign(const System::Windows::Forms::Label& label) {
  SetWindowLongPtr((HWND)label.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)label.Handle(), GWL_STYLE) & ~SS_LEFT & ~SS_RIGHT & ~SS_CENTER);
  switch (label.TextAlign()) {
  case ContentAlignment::TopLeft:
  case ContentAlignment::MiddleLeft:
  case ContentAlignment::BottomLeft: SetWindowLongPtr((HWND)label.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)label.Handle(), GWL_STYLE) | SS_LEFT); break;

  case ContentAlignment::TopRight:
  case ContentAlignment::MiddleRight:
  case ContentAlignment::BottomRight: SetWindowLongPtr((HWND)label.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)label.Handle(), GWL_STYLE) | SS_RIGHT); break;

  case ContentAlignment::TopCenter:
  case ContentAlignment::MiddleCenter:
  case ContentAlignment::BottomCenter: SetWindowLongPtr((HWND)label.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)label.Handle(), GWL_STYLE) | SS_CENTER); break;
  }
}

#endif
