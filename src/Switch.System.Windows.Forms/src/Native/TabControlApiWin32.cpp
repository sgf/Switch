#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>
#include "Api.hpp"
#include "WindowProcedureApiWin32.hpp"
#include "../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../include/Switch/System/Windows/Forms/TabPage.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::TabControlApi::Create(const System::Windows::Forms::TabControl& tabControl) {
  static INITCOMMONCONTROLSEX icc;
  icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
  icc.dwICC = ICC_TAB_CLASSES;
  InitCommonControlsEx(&icc);

  HWND handle = CreateWindowEx(WS_EX_CONTROLPARENT, WC_TABCONTROL, tabControl.Text().w_str().c_str(), WS_CHILD | WS_CLIPSIBLINGS, tabControl.Left, tabControl.Top, tabControl.Width, tabControl.Height, (HWND)tabControl.Parent()().Handle(), (HMENU)0, GetModuleHandle(NULL), (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

System::Drawing::Size Native::TabControlApi::GetDefaultSize() {
  return System::Drawing::Size(200, 100);
}

int32 Native::TabControlApi::GetSelectedTabPageIndex(const System::Windows::Forms::TabControl& tabControl) {
  return TabCtrl_GetCurSel((HWND)tabControl.Handle());
}

System::Drawing::Rectangle Native::TabControlApi::GetTabPageRectangle(const System::Windows::Forms::TabControl& tabControl) {
  RECT tabPageRectangle {tabControl.Left, tabControl.Top, tabControl.Right, tabControl.Bottom};
  TabCtrl_AdjustRect((HWND)tabControl.Handle(), false, &tabPageRectangle);
  return System::Drawing::Rectangle(tabPageRectangle.left - tabControl.Location().X, tabPageRectangle.top - tabControl.Location().Y, tabPageRectangle.right - tabPageRectangle.left, tabPageRectangle.bottom - tabPageRectangle.top);
}

void Native::TabControlApi::SetAlignment(const System::Windows::Forms::TabControl& tabControl) {
}

void Native::TabControlApi::InsertTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage) {
  std::wstring name = tabPage.Text().w_str();
  TCITEM tcItem;
  tcItem.mask = TCIF_TEXT | TCIF_IMAGE;
  tcItem.iImage = -1;
  tcItem.pszText = (wchar*)name.c_str();
  TabCtrl_InsertItem((HWND)tabControl.Handle(), index, &tcItem);
}

void Native::TabControlApi::RemoveTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage) {
  TabCtrl_DeleteItem((HWND)tabControl.Handle(), index);
}

#endif
