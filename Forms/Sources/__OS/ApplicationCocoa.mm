#if defined(__APPLE__) && defined(__use_native_interface__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include <Pcf/System/Console.h>
#include <Pcf/System/Convert.h>
#include <Pcf/System/NotImplementedException.h>
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/Collections/Generic/Dictionary.h>
#include <Pcf/System/Collections/Generic/Queue.h>
#include "../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "FormsApi.h"
#include "WindowMessageKey.h"
#include "WindowProcedureCocoa.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  class CocoaApi {
  public:
    CocoaApi() {
      this->CreateAppication();
      this->CreateMenuBar();
    }

    void MessageLoop(EventHandler idle) {
      @autoreleasepool {
        this->messageLoopRunning = true;
        while (messageLoopRunning) {
          NSEvent* event = idle.IsEmpty() ? this->GetMessage() : this->PeekMessage();
          if (event != nil) {
            DispatchMessage(event);
          } else
            idle(object(), EventArgs());
        }
      }
    }
    
  private:
    void CreateAppication() {
      @autoreleasepool {
        [NSApplication sharedApplication];
        [NSApp finishLaunching];
        this->IgnoreMessages();
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
      }
    }

    void CreateMenuBar() {
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
    
    void DispatchMessage(NSEvent* event) {
      __OS::WindowProcedure::WndProc(event);
    }
    
    NSEvent* GetMessage() const {
      @autoreleasepool {
        return [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate dateWithTimeIntervalSinceNow:Double::MaxValue] inMode:NSDefaultRunLoopMode dequeue:YES];
      }
    }
    
    void IgnoreMessages() const {
      @autoreleasepool {
        NSEvent *ignoredEvent;
        do
          ignoredEvent = [NSApp nextEventMatchingMask:(NSEventMaskAny & ~NSEventMaskSystemDefined) untilDate:[NSDate dateWithTimeIntervalSinceNow:0] inMode:NSDefaultRunLoopMode dequeue:YES];
        while (ignoredEvent);
      }
    }
    
    NSEvent* PeekMessage() const {
      @autoreleasepool {
        return [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate dateWithTimeIntervalSinceNow:0.0] inMode:NSDefaultRunLoopMode dequeue:YES];
      }
    }

    bool messageLoopRunning = false;
  };
  
  refptr<CocoaApi> cocoaApi;
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::AddForm(const System::Windows::Forms::Form& form) {
}

void FormsApi::Application::Exit() {
  Environment::Exit(0);
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
  @autoreleasepool {
    System::Collections::Generic::SortedDictionary<MessageBoxIcon, string> beep = {{(MessageBoxIcon)0, "Funk"}, {MessageBoxIcon::Error, "Sosumi"}, {MessageBoxIcon::Question, "Purr"}, {MessageBoxIcon::Warning, "Hero"}, {MessageBoxIcon::Information, "Glass"}, {(MessageBoxIcon)0xFFFFFFFF, "Funk"}};
    [[NSSound soundNamed:[NSString stringWithUTF8String:beep[type].c_str()]] play];
  }
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  cocoaApi().MessageLoop(idle);
}

namespace {
  void MessageBoxAddButtonsOK(NSAlert *alert) {
    [alert addButtonWithTitle:@"OK"];
  }
  
  void MessageBoxAddButtonsOKCancel(NSAlert *alert) {
    [alert addButtonWithTitle:@"OK"];
    [alert addButtonWithTitle:@"Cancel"];
  }
  
  void MessageBoxAddButtonsAbortRetryIgnore(NSAlert *alert) {
    [alert addButtonWithTitle:@"Abort"];
    [alert addButtonWithTitle:@"Retry"];
    [alert addButtonWithTitle:@"Ignore"];
  }
  
  void MessageBoxAddButtonsYesNoCancel(NSAlert *alert) {
    [alert addButtonWithTitle:@"Yes"];
    [alert addButtonWithTitle:@"No"];
    [alert addButtonWithTitle:@"Cancel"];
  }
  
  void MessageBoxAddButtonsYesNo(NSAlert *alert) {
    [alert addButtonWithTitle:@"Yes"];
    [alert addButtonWithTitle:@"No"];
  }
  
  void MessageBoxAddButtonsRetryCancel(NSAlert *alert) {
    [alert addButtonWithTitle:@"Retry"];
    [alert addButtonWithTitle:@"Cancel"];
  }
  
  DialogResult MessageBoxShowModalOK(NSAlert *alert) {
    [alert runModal];
    return DialogResult::OK;
  }
  
  DialogResult MessageBoxShowModalOKCancel(NSAlert *alert) {
    return [alert runModal] == NSAlertFirstButtonReturn ? DialogResult::OK : DialogResult::Cancel;
  }
  
  DialogResult MessageBoxShowModalAbortRetryIgnore(NSAlert *alert) {
    NSModalResponse result = [alert runModal];
    if (result == NSAlertFirstButtonReturn)
      return DialogResult::Abort;
    if (result == NSAlertSecondButtonReturn)
      return DialogResult::Retry;
    return DialogResult::Ignore;
  }
  
  DialogResult MessageBoxShowModalYesNoCancel(NSAlert *alert) {
    NSModalResponse result = [alert runModal];
    if (result == NSAlertFirstButtonReturn)
      return DialogResult::Yes;
    if (result == NSAlertSecondButtonReturn)
      return DialogResult::No;
    return DialogResult::Cancel;
  }
  
  DialogResult MessageBoxShowModalYesNo(NSAlert *alert) {
    return [alert runModal] == NSAlertFirstButtonReturn ? DialogResult::Yes : DialogResult::No;
  }
  
  DialogResult MessageBoxShowModalRetryCancel(NSAlert *alert) {
    return [alert runModal] == NSAlertFirstButtonReturn ? DialogResult::Retry : DialogResult::Cancel;
  }
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  static SortedDictionary<MessageBoxButtons, delegate<void, NSAlert*>> addButtons = {{MessageBoxButtons::OK, MessageBoxAddButtonsOK}, {MessageBoxButtons::OKCancel, MessageBoxAddButtonsOKCancel}, {MessageBoxButtons::AbortRetryIgnore, MessageBoxAddButtonsAbortRetryIgnore}, {MessageBoxButtons::YesNoCancel, MessageBoxAddButtonsYesNoCancel}, {MessageBoxButtons::YesNo, MessageBoxAddButtonsYesNo}, {MessageBoxButtons::RetryCancel, MessageBoxAddButtonsRetryCancel}};
  static SortedDictionary<MessageBoxIcon, NSAlertStyle>  messageBoxIcon = {{MessageBoxIcon::None, NSAlertStyleWarning}, {MessageBoxIcon::Exclamation, NSAlertStyleCritical}, {MessageBoxIcon::Information, NSAlertStyleInformational}, {MessageBoxIcon::Question, NSAlertStyleInformational}, {MessageBoxIcon::Stop, NSAlertStyleCritical}};
  static SortedDictionary<MessageBoxButtons, delegate<DialogResult, NSAlert*>> showModal = {{MessageBoxButtons::OK, MessageBoxShowModalOK}, {MessageBoxButtons::OKCancel, MessageBoxShowModalOKCancel}, {MessageBoxButtons::AbortRetryIgnore, MessageBoxShowModalAbortRetryIgnore}, {MessageBoxButtons::YesNoCancel, MessageBoxShowModalYesNoCancel}, {MessageBoxButtons::YesNo, MessageBoxShowModalYesNo}, {MessageBoxButtons::RetryCancel, MessageBoxShowModalRetryCancel}};
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
  cocoaApi = pcf_new<CocoaApi>();
}

void FormsApi::Application::Stop() {
  cocoaApi = null;
}

#endif
