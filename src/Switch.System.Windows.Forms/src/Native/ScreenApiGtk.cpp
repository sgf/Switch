#if defined(__linux__)
#include <gdk/gdk.h>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

Array<Screen> __screens__::__get_screens__() {
  List<Screen> screens;

  GdkScreen* gdkScreen = gdk_screen_get_default();
  int screenCount = gdk_screen_get_n_monitors(gdkScreen);

  for (int index = 0; index < screenCount; index++) {
    Screen screen;
    screen.bitsPerPixel = 32;
    GdkRectangle bounds;
    gdk_screen_get_monitor_geometry(gdkScreen, index, &bounds);
    screen.bounds = {bounds.x, bounds.y, bounds.width, bounds.height};
    screen.deviceName = string::Format("\\\\.\\DISPLAY{0}", index + 1);
    screen.primary = index == 0;
    GdkRectangle workingArea;
    gdk_screen_get_monitor_workarea(gdkScreen, index, &workingArea);
    screen.workingArea = {workingArea.x, workingArea.y, workingArea.width, workingArea.height};
    screens.Add(screen);
  }

  return screens.ToArray();
}

Array<Screen> Native::ScreenApi::GetScreens() {
  return __screens__::__get_screens__();
}

#endif
