#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/ColorDialog.hpp"
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

  static NSView* CreateFilterView(NSSavePanel* savePanel, const Array<System::Collections::Generic::KeyValuePair<string, Array<string>>>& filters, int filterIndex) {
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
}

bool Native::CommonDialog::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog &colorDialog) {
  NSColorPanel* colorPanel = [[[NSColorPanel alloc] init] autorelease];
  [colorPanel setIsVisible:YES];
  return false;
}

bool Native::CommonDialog::RunOpenFileDialog(intptr hwnd, System::Windows::Forms::OpenFileDialog &openFileDialog) {
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
    [openPanel setAccessoryView:CreateFilterView(openPanel, openFileDialog.__get_filters__(), openFileDialog.FilterIndex - 1)];

  if ([openPanel runModal] == NSModalResponseCancel) return false;

  if (!openFileDialog.Multiselect)
    openFileDialog.FileName = [[(NSURL*)[[openPanel URLs] objectAtIndex:0] path] UTF8String];
  else{
    NSArray *urls = [openPanel URLs];
    Array<string> fileNames((int32)[urls count]);
    for (int32 index = 0; index < (int32)[urls count]; index++)
      fileNames[index] = [[(NSURL*)[urls objectAtIndex:index] path] UTF8String];
    openFileDialog.__set__file_names__(fileNames);
  }
  return true;
}

bool Native::CommonDialog::RunSaveFileDialog(intptr hwnd, System::Windows::Forms::SaveFileDialog &saveFileDialog) {
  NSSavePanel* savePanel = [[[NSSavePanel alloc] init] autorelease];
  [savePanel setMessage:[NSString stringWithUTF8String:saveFileDialog.Title().c_str()]];
  [savePanel setCanCreateDirectories:YES];
  [savePanel setShowsHiddenFiles:saveFileDialog.ShowHiddenFiles()];
  [savePanel setDirectoryURL:[NSURL fileURLWithPath:[NSString stringWithUTF8String:saveFileDialog.InitialDirectory().c_str()]]];
  [savePanel setNameFieldStringValue:[NSString stringWithUTF8String:saveFileDialog.FileName().c_str()]];
  if (saveFileDialog.__get_filters__().Count != 0)
    [savePanel setAccessoryView:CreateFilterView(savePanel, saveFileDialog.__get_filters__(), saveFileDialog.FilterIndex - 1)];

  if ([savePanel runModal] == NSModalResponseCancel) return false;

  saveFileDialog.FileName = [[[savePanel URL] path] UTF8String];
  return true;
}

#endif
