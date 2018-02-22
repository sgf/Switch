#if defined(_WIN32)

#define UNJCODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

struct Win32Screen : public object {
  int32 bitsPerPixel = 0;
  System::Drawing::Rectangle bounds;
  string deviceName;
  bool primary = false;
  System::Drawing::Rectangle workingArea;
};

int screenNumber = 0;
static BOOL CALLBACK ScreenCallback(HMONITOR monitor, HDC handle, LPRECT rect, LPARAM data) {
  List<Win32Screen>* win32Screens = (List<Win32Screen>*)data;
  MONITORINFOEX monitorInfo;
  monitorInfo.cbSize = sizeof(monitorInfo);
  GetMonitorInfo(monitor, &monitorInfo);
  Win32Screen win32Screen;
  win32Screen.bitsPerPixel = 32;
  win32Screen.bounds = { monitorInfo.rcMonitor.left, monitorInfo.rcMonitor.top, monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left, monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top };
  win32Screen.deviceName = string::Format("\\\\.\\DISPLAY{0}", ++screenNumber);
  win32Screen.primary = win32Screen.deviceName == "\\\\.\\DISPLAY1";
  win32Screen.workingArea = { monitorInfo.rcWork.left, monitorInfo.rcWork.top, monitorInfo.rcWork.right - monitorInfo.rcWork.left, monitorInfo.rcWork.bottom - monitorInfo.rcWork.top };
  win32Screens->Add(win32Screen);
  return true;
}

Array<Screen> __screens__::__get_screens__() {
  List<Screen> screens;
  List<Win32Screen> win32Screens;
  screenNumber = 0;
  EnumDisplayMonitors(null, null, ScreenCallback, (LPARAM)&win32Screens);
  for (Win32Screen win32Screen : win32Screens) {
    Screen screen;
    screen.bitsPerPixel = win32Screen.bitsPerPixel;
    screen.bounds = win32Screen.bounds;
    screen.deviceName = win32Screen.deviceName;
    screen.primary = win32Screen.primary;
    screen.workingArea = win32Screen.workingArea;
    screens.Add(screen);
  }
  return screens.ToArray();
}

Array<Screen> Native::ScreenApi::GetScreens() {
  return __screens__::__get_screens__();
}

#endif
