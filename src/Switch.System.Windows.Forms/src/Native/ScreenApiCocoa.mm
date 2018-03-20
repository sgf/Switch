#if defined(__APPLE__)
#import <AppKit/AppKit.h>
#include <CoreGraphics/CoreGraphics.h>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"

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
    CGRect bounds = CGDisplayBounds(activeDisplays[index]);
    screen.bounds = {int(bounds.origin.x), int(bounds.origin.y), int(bounds.size.width), int(bounds.size.height)};
    screen.deviceName = string::Format("\\\\.\\DISPLAY{0}", index + 1);
    screen.primary = index == 0;
    NSRect workArea = [[[NSScreen screens] objectAtIndex:index] visibleFrame];
    // Do not used workArea.origin.y : this is the eight of Dock and height coordonate is inverted (start on bottom).
    const int menuHaight = 23;
    screen.workingArea = {int(workArea.origin.x), menuHaight, int(workArea.size.width), int(workArea.size.height)-menuHaight};
    screens.Add(screen);
  }
  
  return screens.ToArray();
}

Array<Screen> Native::ScreenApi::GetScreens() {
  return __screens__::__get_screens__();
}

#endif
