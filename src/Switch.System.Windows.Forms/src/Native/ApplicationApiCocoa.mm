#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/DialogResult.hpp"
#include "../../include/Switch/System/Windows/Forms/MessageBoxButtons.hpp"
#include "../../include/Switch/System/Windows/Forms/MessageBoxDefaultButton.hpp"
#include "../../include/Switch/System/Windows/Forms/MessageBoxIcon.hpp"
#include "../../include/Switch/System/Windows/Forms/MessageBoxOptions.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref<System::Windows::Forms::Form> __mainForm;

bool __quit = false;
bool __isActive = false;

namespace {
  class ApplicationCocoaApi static_ {
  public:
    static void MessageLoop(EventHandler idle) {
      @autoreleasepool {
        messageLoopRunning = true;
        while (messageLoopRunning && !__quit) {
          if ([NSApp isActive] && !__isActive)
            Native::ControlApi::SendMessage(__mainForm ? __mainForm->Handle : IntPtr::Zero, WM_ACTIVATEAPP, (intptr)true, (intptr)System::Threading::Thread::CurrentThread().ManagedThreadId());
          else if (![NSApp isActive] && __isActive)
            Native::ControlApi::SendMessage(__mainForm ? __mainForm->Handle : IntPtr::Zero, WM_ACTIVATEAPP, (intptr)false, (intptr)System::Threading::Thread::CurrentThread().ManagedThreadId());
          __isActive = [NSApp isActive];
          NSEvent* event = idle.IsEmpty() ? GetMessage() : PeekMessage();
          if (event != nil)
            DispatchMessage(event);
          idle(object(), EventArgs());
        }
        Native::ControlApi::SendMessage(__mainForm->Handle, WM_ACTIVATEAPP, (intptr)false, (intptr)System::Threading::Thread::CurrentThread().ManagedThreadId());
      }
    }

    static void CreateAppication() {
      @autoreleasepool {
        NSMenu* applicationMenu = [[NSMenu alloc] initWithTitle:@"Application"];
        [applicationMenu addItem:[[NSMenuItem alloc] initWithTitle:[NSString stringWithFormat:NSLocalizedString([NSString stringWithUTF8String:"About %@"] , nil), [[NSProcessInfo processInfo] processName]] action:@selector(orderFrontStandardAboutPanel:) keyEquivalent:@""]];
        [applicationMenu addItem:[NSMenuItem separatorItem]];
        NSMenuItem* servicesMenuItem = [applicationMenu addItemWithTitle:NSLocalizedString([NSString stringWithUTF8String:"Services"], nil) action:nil keyEquivalent:@""];
        NSMenu* servicesMenu = [[NSMenu alloc] initWithTitle:@""];
        [applicationMenu setSubmenu:servicesMenu forItem:servicesMenuItem];
        [applicationMenu addItem:[NSMenuItem separatorItem]];
        [applicationMenu addItemWithTitle:[NSString stringWithFormat:NSLocalizedString([NSString stringWithUTF8String:"Hide %@"],nil), [[NSProcessInfo processInfo] processName]] action:@selector(hide:) keyEquivalent:@"h"];
        NSMenuItem* hidOtherMenuItem = [applicationMenu addItemWithTitle:NSLocalizedString([NSString stringWithUTF8String:"Hide Others"] , nil) action:@selector(hideOtherApplications:) keyEquivalent:@"h"];
        [hidOtherMenuItem setKeyEquivalentModifierMask:(NSEventModifierFlagOption|NSEventModifierFlagCommand)];
        [applicationMenu addItemWithTitle:NSLocalizedString([NSString stringWithUTF8String:"Show All"] , nil) action:@selector(unhideAllApplications:) keyEquivalent:@""];
        [applicationMenu addItem:[NSMenuItem separatorItem]];
        [applicationMenu addItem:[[NSMenuItem alloc] initWithTitle:[NSString stringWithFormat:NSLocalizedString([NSString stringWithUTF8String:"Quit %@"] , nil), [[NSProcessInfo processInfo] processName]] action:@selector(terminate:) keyEquivalent:@"q"]];
        
        NSMenuItem* applicationMenuItem = [[NSMenuItem alloc] init];
        [applicationMenuItem setSubmenu:applicationMenu];

        NSMenu* viewMenu = [[NSMenu alloc] initWithTitle:NSLocalizedString(@"View" , nil)];

        NSMenuItem* viewMenuItem = [[NSMenuItem alloc] init];
        [viewMenuItem setSubmenu:viewMenu];

        NSMenu* windowMenu = [[NSMenu alloc] initWithTitle:NSLocalizedString(@"Window" , nil)];
        
        NSMenuItem* windowMenuItem = [[NSMenuItem alloc] init];
        [windowMenuItem setSubmenu:windowMenu];
        
        NSMenu* helpMenu = [[NSMenu alloc] initWithTitle:NSLocalizedString(@"Help" , nil)];
        
        NSMenuItem* helpMenuItem = [[NSMenuItem alloc] init];
        [helpMenuItem setSubmenu:helpMenu];

        NSMenu* mainMenu = [[NSMenu alloc] init];
        [mainMenu addItem:applicationMenuItem];
        [mainMenu addItem:viewMenuItem];
        [mainMenu addItem:windowMenuItem];
        [mainMenu addItem:helpMenuItem];

        [NSApplication sharedApplication];
        [NSApp setMainMenu:mainMenu];
        [NSApp setServicesMenu:servicesMenu];
        [NSApp setWindowsMenu:windowMenu];
        [NSApp setHelpMenu:helpMenu];
        [NSApp setServicesMenu:servicesMenu];
        [NSApp finishLaunching];
        IgnoreMessages();
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
      }
    }
    
  private:
    static void DispatchMessage(NSEvent* event) {
      Native::WindowProcedure::WndProc(event);
    }
    
    static NSEvent* GetMessage() {
      return [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate distantFuture] inMode:NSDefaultRunLoopMode dequeue:YES];
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
      return [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate distantPast] inMode:NSDefaultRunLoopMode dequeue:YES];
    }

    static bool messageLoopRunning;
  };
  
  bool ApplicationCocoaApi::messageLoopRunning = false;

  class MessageBoxApi static_ {
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

bool Native::ApplicationApi::visualStylesEnabled = false;

void Native::ApplicationApi::Exit() {
  __quit = true;
}

void Native::ApplicationApi::MessageLoop(const System::Windows::Forms::Form& mainForm, EventHandler idle) {
  __mainForm = mainForm;
  ApplicationCocoaApi::MessageLoop(idle);
}

DialogResult Native::ApplicationApi::ShowMessageBox(intptr owner, const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  static Dictionary<MessageBoxButtons, delegate<void, NSAlert*>> addButtons = {{MessageBoxButtons::OK, MessageBoxApi::MessageBoxAddButtonsOK}, {MessageBoxButtons::OKCancel, MessageBoxApi::MessageBoxAddButtonsOKCancel}, {MessageBoxButtons::AbortRetryIgnore, MessageBoxApi::MessageBoxAddButtonsAbortRetryIgnore}, {MessageBoxButtons::YesNoCancel, MessageBoxApi::MessageBoxAddButtonsYesNoCancel}, {MessageBoxButtons::YesNo, MessageBoxApi::MessageBoxAddButtonsYesNo}, {MessageBoxButtons::RetryCancel, MessageBoxApi::MessageBoxAddButtonsRetryCancel}};
  static Dictionary<MessageBoxIcon, NSAlertStyle>  messageBoxIcon = {{MessageBoxIcon::None, NSAlertStyleWarning}, {MessageBoxIcon::Exclamation, NSAlertStyleCritical}, {MessageBoxIcon::Information, NSAlertStyleInformational}, {MessageBoxIcon::Question, NSAlertStyleInformational}, {MessageBoxIcon::Stop, NSAlertStyleCritical}};
  static Dictionary<MessageBoxButtons, delegate<DialogResult, NSAlert*>> showModal = {{MessageBoxButtons::OK, MessageBoxApi::MessageBoxShowModalOK}, {MessageBoxButtons::OKCancel, MessageBoxApi::MessageBoxShowModalOKCancel}, {MessageBoxButtons::AbortRetryIgnore, MessageBoxApi::MessageBoxShowModalAbortRetryIgnore}, {MessageBoxButtons::YesNoCancel, MessageBoxApi::MessageBoxShowModalYesNoCancel}, {MessageBoxButtons::YesNo, MessageBoxApi::MessageBoxShowModalYesNo}, {MessageBoxButtons::RetryCancel, MessageBoxApi::MessageBoxShowModalRetryCancel}};
  @autoreleasepool {
    NSAlert *alert = [[NSAlert alloc] init];
    addButtons[buttons](alert);
    [alert setMessageText:[NSString stringWithUTF8String:caption.c_str()]];
    [alert setInformativeText:[NSString stringWithUTF8String:message.c_str()]];
    [alert setAlertStyle:messageBoxIcon[icon]];
    if (displayHelpButton)
      [alert setShowsHelp:YES];
    DialogResult result = showModal[buttons](alert);
    if (NSApp != null && [NSApp mainWindow] != null) {
      NSModalSession session = [NSApp beginModalSessionForWindow:[NSApp mainWindow]];
      [NSApp runModalSession:session];
      [NSApp endModalSession:session];
    }
    return result;
  }
}

void Native::ApplicationApi::Start() {
  ApplicationCocoaApi::CreateAppication();
}

void Native::ApplicationApi::Stop() {
}

#endif
