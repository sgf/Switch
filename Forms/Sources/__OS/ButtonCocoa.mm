#if defined(__APPLE__) && defined(__use_native_interface__)
#include "WindowProcedureCocoa.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

@interface ButtonCocoa : NSButton
- (IBAction) Click:(id)sender;
@end

@implementation ButtonCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(__OS::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr FormsApi::Button::Create(const System::Windows::Forms::Button& button) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = __OS::WindowProcedure::GetBounds(button);
    ButtonCocoa *handle = [[[ButtonCocoa alloc] initWithFrame:NSMakeRect(bounds.X()-6, bounds.Y()-6, bounds.Width()+12, bounds.Height()+13)] autorelease];
    [[(NSWindow*)button.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:button.Text().c_str()]];
    [handle setButtonType:NSButtonTypeMomentaryPushIn];
    [handle setBezelStyle:NSBezelStyleRounded];
    [handle setTarget:handle];
    [handle setAction:@selector(Click:)];
    __OS::WindowProcedure::Controls[(intptr)handle] = button;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Button&>(button).WndProc(message);
    return (intptr)handle;
  }
}

void FormsApi::Button::SetIsDefault(const System::Windows::Forms::Button& button) {
  [(NSButton*)button.Handle() setKeyEquivalent: [NSString stringWithUTF8String:button.IsDefault ? "\r" : ""]];
}

#endif
