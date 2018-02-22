#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"
#include <Switch/Microsoft/Win32/Registry.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace {
  class CocoaApi static_ {
  public:
    static NSWindowStyleMask FormToNSWindowStyleMask(const Form& form) {
      constexpr int CP_NOCLOSE_BUTTON = 0x200;
      NSWindowStyleMask windowStyleMask = NSWindowStyleMaskBorderless;
      
      if (form.FormBorderStyle != FormBorderStyle::None) {
        windowStyleMask |= NSWindowStyleMaskTitled;
        
        if (form.MaximizeBox && (form.FormBorderStyle == FormBorderStyle::Sizable || form.FormBorderStyle == FormBorderStyle::SizableToolWindow))
          windowStyleMask |= NSWindowStyleMaskResizable;
        
        if (form.MinimizeBox)
          windowStyleMask |= NSWindowStyleMaskMiniaturizable;
        
        if (CP_NOCLOSE_BUTTON /*(form.GetCreateParams().ClassStyle | CP_NOCLOSE_BUTTON) == CP_NOCLOSE_BUTTON*/)
          windowStyleMask |= NSWindowStyleMaskClosable;
      }
      
      return windowStyleMask;
    }
  };
}

@interface FormCocoa : NSWindow
- (BOOL)windowShouldClose:(id)sender;
@end

@implementation FormCocoa
- (BOOL)windowShouldClose:(id)sender {
  Message event = Message::Create((intptr)sender, WM_CLOSE, 0, 0, 0, 0);
  const_cast<Control&>(Native::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
  return NO;
}
@end

void Native::FormApi::Close(System::Windows::Forms::Form& form) {
  Message event = Message::Create((intptr)form.Handle(), WM_CLOSE, 0, 0, 0, 0);
  form.WndProc(event);
  //[(NSWindow*)form.Handle() close];
}

intptr Native::FormApi::Create(System::Windows::Forms::Form& form) {
  @autoreleasepool {
    static Microsoft::Win32::RegistryKey key = Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Gammasoft71").CreateSubKey("Switch").CreateSubKey("Forms");
    static int32 location = as<Int32>(key.GetValue("DefaultLocation", 20));
    
    System::Drawing::Rectangle bounds = form.Bounds;
    switch (form.StartPosition) {
      case FormStartPosition::CenterScreen: bounds = System::Drawing::Rectangle((Screen::AllScreens()[0].WorkingArea().Width + Screen::AllScreens()[0].WorkingArea().X - form.Width) / 2, (Screen::AllScreens()[0].WorkingArea().Height + Screen::AllScreens()[0].WorkingArea().Y - form.Height) / 2, form.Width, form.Height); break;
      case FormStartPosition::Manual: bounds = form.Bounds; break;
      case FormStartPosition::WindowsDefaultBounds: bounds = System::Drawing::Rectangle(location, location, Screen::AllScreens()[0].WorkingArea().Width / 4 * 3, Screen::AllScreens()[0].WorkingArea().Height / 4 * 3); break;
      case FormStartPosition::CenterParent:
      case FormStartPosition::WindowsDefaultLocation: bounds = System::Drawing::Rectangle(location, location, form.Width, form.Height); break;
      default: break;
    }
    form.Location= System::Drawing::Point(bounds.Left, bounds.Top);
    form.Size= System::Drawing::Size(bounds.Width, bounds.Height);
    
    static bool nextLocation = true; // Strangely, on Windows the first location is used 2 times; this boolean simumate it.
    if (form.StartPosition == FormStartPosition::WindowsDefaultBounds || form.StartPosition == FormStartPosition::CenterParent || form.StartPosition == FormStartPosition::WindowsDefaultLocation) {
      nextLocation = !(nextLocation == true && location == 20);
      if (nextLocation) {
        location = location < 180 ? location + 20 : 20;
        key.SetValue("DefaultLocation", location, Microsoft::Win32::RegistryValueKind::DWord);
      }
    }
    
    FormCocoa* handle = [[FormCocoa alloc] init];
    [handle setStyleMask: CocoaApi::FormToNSWindowStyleMask(form)];
    //[handle setFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height()) display:YES];
    //[handle setFrameTopLeftPoint:NSMakePoint(bounds.X(), bounds.Y())];
    
    [handle setTitle:[NSString stringWithUTF8String:form.Text().c_str()]];
    [handle makeKeyAndOrderFront:nil];
    [NSApp activateIgnoringOtherApps:YES];
    //handle.color = CocoaApi::FromColor(form.ForeColor);
    Native::WindowProcedure::Controls[(intptr)handle] = form;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Form&>(form).WndProc(message);
    return (intptr)handle;
  }
}

#endif

