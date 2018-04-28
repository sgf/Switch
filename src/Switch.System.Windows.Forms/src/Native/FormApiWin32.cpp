#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>
#include "WindowProcedureApiWin32.hpp"
#include "../../include/Switch/System/Windows/Forms/Form.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"

using namespace System;
using namespace System::Windows::Forms;

void Native::FormApi::Close(System::Windows::Forms::Form& form) {
  CloseWindow((HWND)form.Handle());
}

intptr Native::FormApi::Create(System::Windows::Forms::Form& form, bool withClientsize) {
  System::Drawing::Rectangle bounds = form.Bounds;
  bounds.X = bounds.X + Screen::AllScreens()[0].WorkingArea().X;
  bounds.Y = bounds.Y + Screen::AllScreens()[0].WorkingArea().Y;
  switch (form.StartPosition) {
  case FormStartPosition::CenterScreen: bounds = System::Drawing::Rectangle((Screen::AllScreens()[0].WorkingArea().Width + Screen::AllScreens()[0].WorkingArea().X - form.Width) / 2, (Screen::AllScreens()[0].WorkingArea().Height + Screen::AllScreens()[0].WorkingArea().Y - form.Height) / 2, form.Width, form.Height); break;
  case FormStartPosition::Manual: bounds = form.Bounds; break;
  case FormStartPosition::WindowsDefaultBounds: bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT); break;
  case FormStartPosition::CenterParent:
  case FormStartPosition::WindowsDefaultLocation: bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, form.Width, form.Height); break;
  }

  HWND handle = CreateWindowEx(0, WC_DIALOG, form.Text().w_str().c_str(), WS_OVERLAPPED | WS_CAPTION | WS_CLIPSIBLINGS | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_GROUP, bounds.Left, bounds.Top, bounds.Width, bounds.Height, NULL, (HMENU)0, GetModuleHandle(NULL), (LPVOID)NULL);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);

  if (withClientsize && form.StartPosition == FormStartPosition::CenterScreen) {
    RECT rect = { 0, 0, form.ClientSize().Width, form.ClientSize().Height };
    AdjustWindowRectEx(&rect, GetWindowLong(handle, GWL_STYLE), false /*menu == null*/, GetWindowLong(handle, GWL_EXSTYLE));
    form.Size = System::Drawing::Size(rect.right - rect.left, rect.bottom - rect.top);
    bounds = System::Drawing::Rectangle((Screen::AllScreens()[0].WorkingArea().Width + Screen::AllScreens()[0].WorkingArea().X - form.Width) / 2, (Screen::AllScreens()[0].WorkingArea().Height + Screen::AllScreens()[0].WorkingArea().Y - form.Height) / 2, form.Width, form.Height);
    form.Location = System::Drawing::Point(bounds.Left, bounds.Top);
    form.Size = System::Drawing::Size(bounds.Width, bounds.Height);
  } else {
    RECT rect = { 0, 0, 0, 0 };
    GetWindowRect(handle, &rect);
    form.Location = System::Drawing::Point(rect.left, rect.top);
    form.Size = System::Drawing::Size(rect.right - rect.left, rect.bottom - rect.top);
  }

  return (intptr)handle;
}

#endif
