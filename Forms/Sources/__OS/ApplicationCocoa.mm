#if defined(__APPLE__)
#include "WindowProcedureCocoa.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

ref<System::Windows::Forms::Form> __mainForm;

namespace {
  class ApplicationApi _static {
  public:
    static void MessageLoop(EventHandler idle) {
      @autoreleasepool {
        messageLoopRunning = true;
        while (messageLoopRunning) {
          NSEvent* event = idle.IsEmpty() ? GetMessage() : PeekMessage();
          if (event != nil)
            DispatchMessage(event);
          idle(object(), EventArgs());
        }
      }
    }

    static void CreateAppication() {
      @autoreleasepool {
        [NSApplication sharedApplication];
        [NSApp finishLaunching];
        IgnoreMessages();
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
      }
    }

    static void CreateMenuBar() {
      static BOOL donethat = NO;
      if (donethat) return;
      donethat = YES;
      NSMenu *mainmenu, *services = nil, *appleMenu;
      NSMenuItem *menuItem;
      NSString *title;
      
      NSString *nsappname = [[[NSBundle mainBundle] performSelector:@selector(localizedInfoDictionary)] objectForKey:@"CFBundleName"];
      if (nsappname == nil)
        nsappname = [[NSProcessInfo processInfo] processName];
      appleMenu = [[NSMenu alloc] initWithTitle:@""];
      /* Add menu items */
      title = [NSString stringWithFormat:NSLocalizedString([NSString stringWithUTF8String:"About %@"],nil), nsappname];
      //menuItem = [appleMenu addItemWithTitle:title action:@selector(showPanel) keyEquivalent:@""];
      //FLaboutItemTarget *about = [[FLaboutItemTarget alloc] init];
      //[menuItem setTarget:about];
      [appleMenu addItem:[NSMenuItem separatorItem]];
      // Print front window
      title = NSLocalizedString([NSString stringWithUTF8String:"Print Front Window"], nil);
      if ([title length] > 0) {
        menuItem = [appleMenu addItemWithTitle:title action:@selector(printPanel) keyEquivalent:@""];
        //[menuItem setTarget:about];
        [menuItem setEnabled:YES];
        [appleMenu addItem:[NSMenuItem separatorItem]];
      }
      // Services Menu
      services = [[NSMenu alloc] initWithTitle:@""];
      menuItem = [appleMenu addItemWithTitle:NSLocalizedString([NSString stringWithUTF8String:"Services"], nil) action:nil keyEquivalent:@""];
      [appleMenu setSubmenu:services forItem:menuItem];
      [appleMenu addItem:[NSMenuItem separatorItem]];
      // Hide AppName
      title = [NSString stringWithFormat:NSLocalizedString([NSString stringWithUTF8String:"Hide %@"],nil), nsappname];
      [appleMenu addItemWithTitle:title action:@selector(hide:) keyEquivalent:@"h"];
      // Hide Others
      menuItem = [appleMenu addItemWithTitle:NSLocalizedString([NSString stringWithUTF8String:"Hide Others"] , nil) action:@selector(hideOtherApplications:) keyEquivalent:@"h"];
      [menuItem setKeyEquivalentModifierMask:(NSEventModifierFlagOption|NSEventModifierFlagCommand)];
      // Show All
      [appleMenu addItemWithTitle:NSLocalizedString([NSString stringWithUTF8String:"Show All"] , nil) action:@selector(unhideAllApplications:) keyEquivalent:@""];
      [appleMenu addItem:[NSMenuItem separatorItem]];
      // Quit AppName
      title = [NSString stringWithFormat:NSLocalizedString([NSString stringWithUTF8String:"Quit %@"] , nil), nsappname];
      menuItem = [appleMenu addItemWithTitle:title action:@selector(terminate:) keyEquivalent:@"q"];
      //[menuItem setTarget:about];
      
      /* Put menu into the menubar */
      menuItem = [[NSMenuItem alloc] initWithTitle:@"" action:nil keyEquivalent:@""];
      [menuItem setSubmenu:appleMenu];
      mainmenu = [[NSMenu alloc] initWithTitle:@""];
      [mainmenu addItem:menuItem];
      [NSApp setMainMenu:mainmenu];
      if (services) {
        [NSApp setServicesMenu:services];
        [services release];
      }
      [mainmenu release];
      [appleMenu release];
      [menuItem release];
    }
    
  private:
    static void DispatchMessage(NSEvent* event) {
      __OS::WindowProcedure::WndProc(event);
    }
    
    static NSEvent* GetMessage() {
      return [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate dateWithTimeIntervalSinceNow:Double::MaxValue] inMode:NSDefaultRunLoopMode dequeue:YES];
    }
    
    static void IgnoreMessages() {
      @autoreleasepool {
        NSEvent *ignoredEvent;
        do
          ignoredEvent = [NSApp nextEventMatchingMask:(NSEventMaskAny & ~NSEventMaskSystemDefined) untilDate:[NSDate dateWithTimeIntervalSinceNow:0] inMode:NSDefaultRunLoopMode dequeue:YES];
        while (ignoredEvent);
      }
    }
    
    static NSEvent* PeekMessage() {
      return [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate dateWithTimeIntervalSinceNow:0.0] inMode:NSDefaultRunLoopMode dequeue:YES];
    }

    static bool messageLoopRunning;
  };
  
  bool ApplicationApi::messageLoopRunning = false;

  class MessageBoxApi _static {
  public:
    static void MessageBoxAddButtonsOK(NSAlert *alert) {
      [alert addButtonWithTitle:@"OK"];
    }
    
    static void MessageBoxAddButtonsOKCancel(NSAlert *alert) {
      [alert addButtonWithTitle:@"OK"];
      [alert addButtonWithTitle:@"Cancel"];
    }
    
    static void MessageBoxAddButtonsAbortRetryIgnore(NSAlert *alert) {
      [alert addButtonWithTitle:@"Abort"];
      [alert addButtonWithTitle:@"Retry"];
      [alert addButtonWithTitle:@"Ignore"];
    }
    
    static void MessageBoxAddButtonsYesNoCancel(NSAlert *alert) {
      [alert addButtonWithTitle:@"Yes"];
      [alert addButtonWithTitle:@"No"];
      [alert addButtonWithTitle:@"Cancel"];
    }
    
    static void MessageBoxAddButtonsYesNo(NSAlert *alert) {
      [alert addButtonWithTitle:@"Yes"];
      [alert addButtonWithTitle:@"No"];
    }
    
    static void MessageBoxAddButtonsRetryCancel(NSAlert *alert) {
      [alert addButtonWithTitle:@"Retry"];
      [alert addButtonWithTitle:@"Cancel"];
    }
    
    static DialogResult MessageBoxShowModalOK(NSAlert *alert) {
      [alert runModal];
      return DialogResult::OK;
    }
    
    static DialogResult MessageBoxShowModalOKCancel(NSAlert *alert) {
      return [alert runModal] == NSAlertFirstButtonReturn ? DialogResult::OK : DialogResult::Cancel;
    }
    
    static DialogResult MessageBoxShowModalAbortRetryIgnore(NSAlert *alert) {
      NSModalResponse result = [alert runModal];
      if (result == NSAlertFirstButtonReturn)
        return DialogResult::Abort;
      if (result == NSAlertSecondButtonReturn)
        return DialogResult::Retry;
      return DialogResult::Ignore;
    }
    
    static DialogResult MessageBoxShowModalYesNoCancel(NSAlert *alert) {
      NSModalResponse result = [alert runModal];
      if (result == NSAlertFirstButtonReturn)
        return DialogResult::Yes;
      if (result == NSAlertSecondButtonReturn)
        return DialogResult::No;
      return DialogResult::Cancel;
    }
    
    static DialogResult MessageBoxShowModalYesNo(NSAlert *alert) {
      return [alert runModal] == NSAlertFirstButtonReturn ? DialogResult::Yes : DialogResult::No;
    }
    
    static DialogResult MessageBoxShowModalRetryCancel(NSAlert *alert) {
      return [alert runModal] == NSAlertFirstButtonReturn ? DialogResult::Retry : DialogResult::Cancel;
    }
  };
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  Environment::Exit(0);
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
  @autoreleasepool {
    System::Collections::Generic::SortedDictionary<MessageBoxIcon, string> beep = {{(MessageBoxIcon)0, "Funk"}, {MessageBoxIcon::Error, "Sosumi"}, {MessageBoxIcon::Question, "Purr"}, {MessageBoxIcon::Warning, "Hero"}, {MessageBoxIcon::Information, "Glass"}, {(MessageBoxIcon)0xFFFFFFFF, "Funk"}};
    [[NSSound soundNamed:[NSString stringWithUTF8String:beep[type].c_str()]] play];
  }
}

void FormsApi::Application::MessageLoop(const System::Windows::Forms::Form& mainForm, EventHandler idle) {
  __mainForm = mainForm;
  ApplicationApi::MessageLoop(idle);
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  static SortedDictionary<MessageBoxButtons, delegate<void, NSAlert*>> addButtons = {{MessageBoxButtons::OK, MessageBoxApi::MessageBoxAddButtonsOK}, {MessageBoxButtons::OKCancel, MessageBoxApi::MessageBoxAddButtonsOKCancel}, {MessageBoxButtons::AbortRetryIgnore, MessageBoxApi::MessageBoxAddButtonsAbortRetryIgnore}, {MessageBoxButtons::YesNoCancel, MessageBoxApi::MessageBoxAddButtonsYesNoCancel}, {MessageBoxButtons::YesNo, MessageBoxApi::MessageBoxAddButtonsYesNo}, {MessageBoxButtons::RetryCancel, MessageBoxApi::MessageBoxAddButtonsRetryCancel}};
  static SortedDictionary<MessageBoxIcon, NSAlertStyle>  messageBoxIcon = {{MessageBoxIcon::None, NSAlertStyleWarning}, {MessageBoxIcon::Exclamation, NSAlertStyleCritical}, {MessageBoxIcon::Information, NSAlertStyleInformational}, {MessageBoxIcon::Question, NSAlertStyleInformational}, {MessageBoxIcon::Stop, NSAlertStyleCritical}};
  static SortedDictionary<MessageBoxButtons, delegate<DialogResult, NSAlert*>> showModal = {{MessageBoxButtons::OK, MessageBoxApi::MessageBoxShowModalOK}, {MessageBoxButtons::OKCancel, MessageBoxApi::MessageBoxShowModalOKCancel}, {MessageBoxButtons::AbortRetryIgnore, MessageBoxApi::MessageBoxShowModalAbortRetryIgnore}, {MessageBoxButtons::YesNoCancel, MessageBoxApi::MessageBoxShowModalYesNoCancel}, {MessageBoxButtons::YesNo, MessageBoxApi::MessageBoxShowModalYesNo}, {MessageBoxButtons::RetryCancel, MessageBoxApi::MessageBoxShowModalRetryCancel}};
  @autoreleasepool {
    NSAlert *alert = [[NSAlert alloc] init];
    addButtons[buttons](alert);
    [alert setMessageText:[NSString stringWithUTF8String:caption.c_str()]];
    [alert setInformativeText:[NSString stringWithUTF8String:message.c_str()]];
    [alert setAlertStyle:messageBoxIcon[icon]];
    if (displayHelpButton)
      [alert setShowsHelp:YES];
    DialogResult result = showModal[buttons](alert);
    NSEvent *ignoredEvent;
    do
      ignoredEvent = [NSApp nextEventMatchingMask:(NSEventMaskAny & ~NSEventMaskSystemDefined) untilDate:[NSDate dateWithTimeIntervalSinceNow:0] inMode:NSDefaultRunLoopMode dequeue:YES];
    while (ignoredEvent);
    return result;
  }
}

void FormsApi::Application::Start() {
  ApplicationApi::CreateAppication();
  ApplicationApi::CreateMenuBar();
}

void FormsApi::Application::Stop() {
  // no implementation
}

#endif
