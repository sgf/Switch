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

bool Native::CommonDialog::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog &colorDialog) {
  NSColorPanel* colorPanel = [[[NSColorPanel alloc] init] autorelease];
  [colorPanel runToolbarCustomizationPalette:null];
  return false;
}

bool Native::CommonDialog::RunOpenFileDialog(intptr hwnd, System::Windows::Forms::OpenFileDialog &openFileDialog) {
  NSOpenPanel* openPanel = [[[NSOpenPanel alloc] init] autorelease];
  [openPanel setMessage:[NSString stringWithUTF8String:openFileDialog.Title().c_str()]];
  [openPanel setCanChooseFiles:TRUE];
  [openPanel setCanChooseDirectories:FALSE];
  [openPanel setResolvesAliases:openFileDialog.DereferenceLinks()];
  [openPanel setAllowsMultipleSelection:openFileDialog.Multiselect()];
  [openPanel setNameFieldLabel:[NSString stringWithUTF8String:openFileDialog.FileName().c_str()]];
  [openPanel setShowsHiddenFiles:openFileDialog.ShowHiddenFiles()];
  [openPanel setDirectoryURL:[NSURL fileURLWithPath:[NSString stringWithUTF8String:openFileDialog.InitialDirectory().c_str()]]];
  [openPanel setNameFieldStringValue:[NSString stringWithUTF8String:openFileDialog.FileName().c_str()]];

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
  [savePanel setNameFieldLabel:[NSString stringWithUTF8String:saveFileDialog.FileName().c_str()]];
  [savePanel setCanCreateDirectories:TRUE];
  [savePanel setShowsHiddenFiles:saveFileDialog.ShowHiddenFiles()];
  [savePanel setDirectoryURL:[NSURL fileURLWithPath:[NSString stringWithUTF8String:saveFileDialog.InitialDirectory().c_str()]]];
  [savePanel setNameFieldStringValue:[NSString stringWithUTF8String:saveFileDialog.FileName().c_str()]];

  if ([savePanel runModal] == NSModalResponseCancel) return false;

  saveFileDialog.FileName = [[[savePanel URL] path] UTF8String];
  return true;
}

#endif
