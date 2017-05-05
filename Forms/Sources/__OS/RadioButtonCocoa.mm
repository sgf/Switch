#if defined(__APPLE__) && defined(__use_native_interface__)
#include "WindowProcedureCocoa.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

@interface RadioButtonCocoa : NSButton
- (IBAction) Click:(id)sender;
@end

@implementation RadioButtonCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  //ref<Control> control = System::Windows::Forms::Control::FromHandle((intptr)sender);
  //if (is<System::Windows::Forms::RadioButton>(control))
  //  as<System::Windows::Forms::RadioButton>(control)().Checked = !as<System::Windows::Forms::RadioButton>(control)().Checked;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(__OS::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr FormsApi::RadioButton::Create(const System::Windows::Forms::RadioButton& radioButton) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = __OS::WindowProcedure::GetBounds(radioButton);
    RadioButtonCocoa *handle = [[[RadioButtonCocoa alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)radioButton.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:radioButton.Text().c_str()]];
    [handle setButtonType:NSButtonTypeRadio];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:[RadioButtonCocoa alloc]];
    [handle setAction:@selector(Click:)];
    __OS::WindowProcedure::Controls[(intptr)handle] = radioButton;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::RadioButton&>(radioButton).WndProc(message);
    return (intptr)handle;
  }
}

void FormsApi::RadioButton::SetAutoCheck(const System::Windows::Forms::RadioButton& radioButton) {
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  [(NSButton*)radioButton.Handle() setState:radioButton.Checked()];
}

#endif