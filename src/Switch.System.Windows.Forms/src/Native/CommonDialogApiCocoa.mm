#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include <Switch/System/IO/Directory.hpp>
#include "WindowProcedureApiCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/ColorDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/FolderBrowserDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/FontDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/OpenFileDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/SaveFileDialog.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace {
  static bool PatternCompare(const string& fileName, const Array<string>& patterns);
}

@interface OpenDelegate : NSObject <NSOpenSavePanelDelegate> {
  NSPopUpButton *popUpButton;
  Array<System::Collections::Generic::KeyValuePair<string, Array<string>>> filters;
}
- (OpenDelegate*)setPopUpButton:(NSPopUpButton*)popUpButton setFilterPetterns:(const Array<System::Collections::Generic::KeyValuePair<string, Array<string>>>&)filters;
- (BOOL)panel:(id)sender shouldShowFilename:(NSString *)filename;
- (BOOL)panel:(id)sender shouldEnableURL:(NSURL *)url;
@end

@implementation OpenDelegate
- (OpenDelegate*)setPopUpButton:(NSPopUpButton*)popUpButton setFilterPetterns:(const Array<System::Collections::Generic::KeyValuePair<string, Array<string>>>&)filters {
  self->popUpButton = popUpButton;
  self->filters = filters;
  return self;
}

- (BOOL)panel:(id)sender shouldShowFilename:(NSString *)filename {
  if ( [popUpButton indexOfSelectedItem] == [popUpButton numberOfItems] - 1) return YES;
  BOOL isdir = NO;
  [[NSFileManager defaultManager] fileExistsAtPath:filename isDirectory:&isdir];
  if (isdir) return YES;
  if (PatternCompare([filename fileSystemRepresentation], filters[[popUpButton indexOfSelectedItem]].Value)) return YES;
  return NO;
}

- (BOOL)panel:(id)sender shouldEnableURL:(NSURL *)url {
  return [self panel:sender shouldShowFilename:[url path]];
}
@end

@interface ColorPanelCocoa : NSColorPanel {
  bool close;
}
- (BOOL)windowShouldClose:(id)sender;
- (void) show;

@end

@implementation ColorPanelCocoa
- (BOOL)windowShouldClose:(id)sender {
  self->close = true;
  return YES;
}

- (void) show {
  self->close = false;
  NSEvent *event;
  do {
    event = [NSApp nextEventMatchingMask:(NSEventMaskAny & ~NSEventMaskSystemDefined) untilDate:[NSDate dateWithTimeIntervalSinceNow:0] inMode:NSDefaultRunLoopMode dequeue:YES];
    Native::WindowProcedure::WndProc(event);
  } while (self->close == false);
}
@end

@interface FontPanelCocoa : NSFontPanel {
  bool close;
}
- (BOOL)windowShouldClose:(id)sender;
- (void) show;

@end

@implementation FontPanelCocoa
- (BOOL)windowShouldClose:(id)sender {
  self->close = true;
  return YES;
}

- (void) show {
  self->close = false;
  NSEvent *event;
  do {
    event = [NSApp nextEventMatchingMask:(NSEventMaskAny & ~NSEventMaskSystemDefined) untilDate:[NSDate dateWithTimeIntervalSinceNow:0] inMode:NSDefaultRunLoopMode dequeue:YES];
    Native::WindowProcedure::WndProc(event);
  } while (self->close == false);
}
@end

namespace {
  static bool PatternCompare(const string& fileName, const string& pattern) {
    if (string::IsNullOrEmpty(pattern))
      return string::IsNullOrEmpty(fileName);

    if (string::IsNullOrEmpty(fileName))
      return false;

    if (pattern == "*" || pattern == "*.*")
      return true;

    if (pattern[0] == '*')
      return PatternCompare(fileName, pattern.Substring(1)) || PatternCompare(fileName.Substring(1), pattern);

    return ((pattern[0] == '?') || (fileName[0] == pattern[0])) && PatternCompare(fileName.Substring(1), pattern.Substring(1));
  }

  static bool PatternCompare(const string& fileName, const Array<string>& patterns) {
    for (auto pattern : patterns)
      if (PatternCompare(fileName, pattern))
        return true;
    return false;
  }

  /*
  static NSView* CreateFilterViewForColorDialog(NSColorPanel* colorPanel) {
    NSButton* buttonCancel = [[[NSButton alloc] initWithFrame:NSMakeRect([colorPanel frame].size.width - 170, 0, 75, 30)] autorelease];
    [buttonCancel setTitle:@"Cancel"];
    [buttonCancel setBezelStyle: NSBezelStyleRounded];
    NSButton* buttonOk = [[[NSButton alloc] initWithFrame:NSMakeRect([colorPanel frame].size.width - 85, 0, 75, 30)] autorelease];
    [buttonOk setTitle:@"OK"];
    [buttonOk setBezelStyle: NSBezelStyleRounded];

    NSView* view = [[[NSView alloc] initWithFrame:NSMakeRect(5, 5, 350, 30 )] autorelease];
    [view addSubview:buttonCancel];
    [view addSubview:buttonOk];

    return view;
  }*/

  static NSView* CreateFilterViewForFileDialog(NSSavePanel* savePanel, const Array<System::Collections::Generic::KeyValuePair<string, Array<string>>>& filters, int filterIndex) {
    NSPopUpButton* popUpButton = [[[NSPopUpButton alloc ] initWithFrame:NSMakeRect(62, 0, 256, 30) pullsDown:NO] autorelease];
    for (auto filter : filters)
      [popUpButton addItemWithTitle:[NSString stringWithUTF8String:filter.Key().c_str()]];
    [popUpButton setAction:@selector(validateVisibleColumns)];
    [popUpButton setTarget:(NSObject*)savePanel];
    [popUpButton selectItemAtIndex:filterIndex];
    OpenDelegate *openDelegate = [[[OpenDelegate alloc] init] autorelease];
    [openDelegate setPopUpButton:popUpButton setFilterPetterns:filters];
    [(NSOpenPanel*)savePanel setDelegate:openDelegate];

    NSBox* box = [[[NSBox alloc] initWithFrame:NSMakeRect(0, 3, 140, 20 )] autorelease];
    [box setBorderType:NSNoBorder];
    [box setTitle:@"Filter:"];
    [box setTitleFont:[NSFont controlContentFontOfSize:NSControlSizeRegular]];
    [box sizeToFit];
    NSPoint boxLocation = [box frame].origin;
    boxLocation.x = [popUpButton frame].origin.x - [box frame].size.width + 15;
    [box setFrameOrigin:boxLocation];

    NSView* view = [[[NSView alloc] initWithFrame:NSMakeRect(5, 5, 350, 30 )] autorelease];
    [view addSubview:box];
    [view addSubview:popUpButton];

    return view;
  }

  static NSColor* FromColor(const System::Drawing::Color& color) {
    return [NSColor colorWithCalibratedRed:as<double>(color.R()) / 0xFF green:as<double>(color.G()) / 0xFF blue:as<double>(color.B()) / 0xFF alpha:as<double>(color.A()) / 0xFF];
  }

  System::Drawing::Color ToColor(NSColor* color) {
    const CGFloat* components = CGColorGetComponents(color.CGColor);
    return System::Drawing::Color::FromArgb(CGColorGetAlpha(color.CGColor) * 0xFF, components[0] * 0xFF, components[1] * 0xFF, components[2] * 0xFF);
  }
}

bool Native::CommonDialogApi::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog &colorDialog) {
  ColorPanelCocoa* colorPanel = [[[ColorPanelCocoa alloc] init] autorelease];
  [colorPanel setIsVisible:YES];
  [colorPanel setColor:FromColor(colorDialog.Color)];
  [colorPanel setFloatingPanel:NO];
  [[colorPanel accessoryView] setBoundsOrigin:NSMakePoint(0, 300)];
  [colorPanel setViewsNeedDisplay:YES];
  //[colorPanel setAccessoryView:CreateFilterViewForColorDialog(colorPanel)];
  [colorPanel show];
  colorDialog.Color = ToColor([colorPanel color]);

  return true;
}

bool Native::CommonDialogApi::RunFolderBrowserDialog(intptr hwnd, System::Windows::Forms::FolderBrowserDialog &folderBrowserDialog) {
  NSOpenPanel* openPanel = [[[NSOpenPanel alloc] init] autorelease];
  [openPanel setCanChooseFiles:NO];
  [openPanel setCanChooseDirectories:YES];
  [openPanel setAllowsMultipleSelection:NO];
  [openPanel setShowsHiddenFiles:folderBrowserDialog.ShowHiddenFolders()];
  string path = Environment::GetFolderPath(folderBrowserDialog.RootFolder);
  if (folderBrowserDialog.SelectedPath != "" && System::IO::Directory::Exists(folderBrowserDialog.SelectedPath))
    path = folderBrowserDialog.SelectedPath;
  [openPanel setDirectoryURL:[NSURL fileURLWithPath:[NSString stringWithUTF8String:path.c_str()]]];

  NSModalResponse response = [openPanel runModal];
  if (NSApp != null && [NSApp mainWindow] != null) {
    NSModalSession session = [NSApp beginModalSessionForWindow:[NSApp mainWindow]];
    [NSApp runModalSession:session];
    [NSApp endModalSession:session];
  }
  if (response == NSModalResponseCancel) return false;

  folderBrowserDialog.SelectedPath = [[(NSURL*)[[openPanel URLs] objectAtIndex:0] path] UTF8String];
  return true;
}

void MyClose(id sender) {
  [NSApp stopModal];
}

@interface NSButtonOk : NSButton
- (IBAction) Click:(id)sender;
@end

@implementation NSButtonOk
- (IBAction) Click:(id)sender {
  [NSApp stopModal];
}
@end

@interface NSSwitchFontPanel : NSPanel {
  NSFontPanel* fontPanel;
}
- (instancetype)init;
@end

@implementation NSSwitchFontPanel
- (instancetype)init {
  return self;
}

@end

bool Native::CommonDialogApi::RunFontDialog(intptr hwnd, System::Windows::Forms::FontDialog& fontDialog) {
  /*
  NSFont* font = (NSFont *)fontDialog.Font().ToHFont();
  NSFontPanel* fontPanel = [NSFontPanel sharedFontPanel];
  [fontPanel setPanelFont:font isMultiple:YES];
  [fontPanel setEnabled:YES];
  NSView* view = [[[NSView alloc] initWithFrame:NSMakeRect(5, 5, 350, 30 )] autorelease];
  NSButton* buttonOk = [NSButton buttonWithTitle:@"OK" target:[NSButtonOk alloc] action: @selector(Click:)];
  [view addSubview:buttonOk];
  [fontPanel setAccessoryView:view];
  if ([NSApp runModalForWindow:fontPanel] == NSModalResponseCancel) return false;
  [fontPanel setIsVisible:NO];
  fontDialog.Font = System::Drawing::Font::FromHFont((intptr)font);
   */

  NSSwitchFontPanel* fontPanel = [[[NSSwitchFontPanel alloc] init] autorelease];

  [fontPanel setIsVisible:YES];

  return true;
}

bool Native::CommonDialogApi::RunOpenFileDialog(intptr hwnd, System::Windows::Forms::OpenFileDialog &openFileDialog) {
  NSOpenPanel* openPanel = [[[NSOpenPanel alloc] init] autorelease];
  [openPanel setMessage:[NSString stringWithUTF8String:openFileDialog.Title().c_str()]];
  [openPanel setCanChooseFiles:YES];
  [openPanel setCanChooseDirectories:NO];
  [openPanel setResolvesAliases:openFileDialog.DereferenceLinks()];
  [openPanel setAllowsMultipleSelection:openFileDialog.Multiselect()];
  [openPanel setShowsHiddenFiles:openFileDialog.ShowHiddenFiles()];
  [openPanel setDirectoryURL:[NSURL fileURLWithPath:[NSString stringWithUTF8String:openFileDialog.InitialDirectory().c_str()]]];
  [openPanel setNameFieldStringValue:[NSString stringWithUTF8String:openFileDialog.FileName().c_str()]];
  if (openFileDialog.__get_filters__().Count != 0)
    [openPanel setAccessoryView:CreateFilterViewForFileDialog(openPanel, openFileDialog.__get_filters__(), openFileDialog.FilterIndex - 1)];

  NSModalResponse response = [openPanel runModal];
  if (NSApp != null && [NSApp mainWindow] != null) {
    NSModalSession session = [NSApp beginModalSessionForWindow:[NSApp mainWindow]];
    [NSApp runModalSession:session];
    [NSApp endModalSession:session];
  }
  if (response == NSModalResponseCancel) return false;

  if (!openFileDialog.Multiselect)
    openFileDialog.FileName = [[(NSURL*)[[openPanel URLs] objectAtIndex:0] path] UTF8String];
  else{
    NSArray *urls = [openPanel URLs];
    Array<string> fileNames((int32)[urls count]);
    for (int32 index = 0; index < (int32)[urls count]; index++)
      fileNames[index] = [[(NSURL*)[urls objectAtIndex:index] path] UTF8String];
    openFileDialog.FileName = fileNames[0];
    openFileDialog.__set__file_names__(fileNames);
  }
  return true;
}

bool Native::CommonDialogApi::RunSaveFileDialog(intptr hwnd, System::Windows::Forms::SaveFileDialog &saveFileDialog) {
  NSSavePanel* savePanel = [[[NSSavePanel alloc] init] autorelease];
  [savePanel setMessage:[NSString stringWithUTF8String:saveFileDialog.Title().c_str()]];
  [savePanel setCanCreateDirectories:YES];
  [savePanel setShowsHiddenFiles:saveFileDialog.ShowHiddenFiles()];
  [savePanel setDirectoryURL:[NSURL fileURLWithPath:[NSString stringWithUTF8String:saveFileDialog.InitialDirectory().c_str()]]];
  [savePanel setNameFieldStringValue:[NSString stringWithUTF8String:saveFileDialog.FileName().c_str()]];
  if (saveFileDialog.__get_filters__().Count != 0)
    [savePanel setAccessoryView:CreateFilterViewForFileDialog(savePanel, saveFileDialog.__get_filters__(), saveFileDialog.FilterIndex - 1)];

  NSModalResponse response = [savePanel runModal];
  if (NSApp != null && [NSApp mainWindow] != null) {
    NSModalSession session = [NSApp beginModalSessionForWindow:[NSApp mainWindow]];
    [NSApp runModalSession:session];
    [NSApp endModalSession:session];
  }
  if (response == NSModalResponseCancel) return false;

  saveFileDialog.FileName = [[[savePanel URL] path] UTF8String];
  return true;
}

#endif
