#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

intptr Native::TabPageApi::Create(const System::Windows::Forms::TabPage& tabPage) {
  @autoreleasepool {
    NSTabViewItem* handle = [[NSTabViewItem alloc] init];
    [handle setLabel:[NSString stringWithUTF8String:tabPage.Text().c_str()]];
    return (intptr)handle;
  }
}

void Native::TabPageApi::SetBorderStyle(const System::Windows::Forms::TabPage& tabPage) {
}

#endif
