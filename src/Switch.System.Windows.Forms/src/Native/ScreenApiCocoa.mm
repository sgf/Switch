#if defined(__APPLE__)
#import <AppKit/AppKit.h>
#include <CoreGraphics/CoreGraphics.h>
#include "Api.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

Array<Screen> __screens__::__get_screens__() {
  List<Screen> screens;
  
  uint32 count = 0;
  CGGetActiveDisplayList(0, null, &count);
  Array<CGDirectDisplayID> activeDisplays(as<int32>(count));
  CGGetActiveDisplayList(count, (CGDirectDisplayID *)activeDisplays.Data(), &count);
  
  for(int32 index = 0; index < as<int32>(count); index++) {
    Screen screen;
    screen.bitsPerPixel = 32;
    CGRect rect = CGDisplayBounds(activeDisplays[index]);
    screen.bounds = {int(rect.origin.x), int(rect.origin.y), int(rect.size.width), int(rect.size.height)};
    screen.deviceName = string::Format("\\\\.\\DISPLAY{0}", index + 1);
    screen.primary = index == 0;
    NSRect area = [[[NSScreen screens] objectAtIndex:index] visibleFrame];
    screen.workingArea = {int(area.origin.x), int(area.origin.y), int(area.size.width), int(area.size.height)};
    screens.Add(screen);
  }
  
  return screens.ToArray();
}

Array<Screen> Native::ScreenApi::GetScreens() {
  return __screens__::__get_screens__();
}

#endif

/*
 Fl::screen_xywh
 Fl::screen_work_area
 */
