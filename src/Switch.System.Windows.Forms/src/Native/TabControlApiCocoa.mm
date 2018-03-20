#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../include/Switch/System/Windows/Forms/TabPage.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

intptr Native::TabControlApi::Create(const System::Windows::Forms::TabControl& tabControl) {
  @autoreleasepool {
    NSTabView* handle = [[[NSTabView alloc] init] autorelease];
    [[(NSWindow*)tabControl.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    //handle.color = CocoaApi::FromColor(tabControl.ForeColor);
    Native::WindowProcedure::Controls[(intptr)handle] = tabControl;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::TabControl&>(tabControl).WndProc(message);
    return (intptr)handle;
  }
}

void Native::TabControlApi::SetAlignment(const System::Windows::Forms::TabControl& tabControl) {
}


int32 Native::TabControlApi::GetSelectedTabPageIndex(const System::Windows::Forms::TabControl& tabControl) {
  return 0;
}

System::Drawing::Rectangle Native::TabControlApi::GetTabPageRectangle(const System::Windows::Forms::TabControl& tabControl) {
  return System::Drawing::Rectangle();
}

void Native::TabControlApi::InsertTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage) {
  [(NSTabView *)tabControl.Handle() insertTabViewItem:(NSTabViewItem *)tabPage.Handle() atIndex:index];
}

void Native::TabControlApi::RemoveTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage) {

}
#endif
