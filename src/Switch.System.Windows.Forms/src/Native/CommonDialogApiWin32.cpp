#if defined(_WIN32)

#define UNICODE
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <CommCtrl.h>
#include <Switch/Undef.hpp>
#include "Api.hpp"
#include <Switch/System/Buffer.hpp>
#include "../../include/Switch/System/Windows/Forms/ColorDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/FolderBrowserDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/OpenFileDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/SaveFileDialog.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace {
  Array<byte> ToFilter(const Array<string>& filters) {
    int32 length = 1;
    for (auto& filter : filters)
      length += (int32)filter.Length + 1;
    Array<byte> result(length * sizeof(wchar));
    int32 index = 0;
    for (auto& filter : filters) {
      Buffer::BlockCopy((const void*)filter.w_str().c_str(), filter.Length * sizeof(wchar), 0, (void*)result.Data(), result.Length * sizeof(wchar), index, filter.Length * sizeof(wchar));
      index += (int32)filter.Length * sizeof(wchar) + sizeof(wchar);
    }
    result[index] += '\0';
    return result;
  }
}

bool Native::CommonDialog::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog& colorDialog) {
  CHOOSECOLOR chooseColor;
  COLORREF customColors[16];
  for (int32 index = 0; index < colorDialog.CustomColors().Length; index++)
    customColors[index] = RGB(colorDialog.CustomColors()[index].R, colorDialog.CustomColors()[index].G, colorDialog.CustomColors()[index].B);
  memset(&chooseColor, 0, sizeof(chooseColor));
  chooseColor.lStructSize = sizeof(chooseColor);
  chooseColor.hwndOwner = hwnd != IntPtr::Zero ? (HWND)hwnd : GetActiveWindow();
  chooseColor.rgbResult = RGB(colorDialog.Color().R, colorDialog.Color().G, colorDialog.Color().B);
  chooseColor.lpCustColors = customColors;
  int flags = CC_RGBINIT; // | CC_ENABLEHOOK;
  if (!colorDialog.AllowFullOpen)
    flags += CC_PREVENTFULLOPEN;
  if (colorDialog.AnyColor)
    flags += CC_ANYCOLOR;
  if (colorDialog.FullOpen && colorDialog.AllowFullOpen)
    flags += CC_FULLOPEN;
  if (colorDialog.ShowHelp)
    flags += CC_SHOWHELP;
  if (colorDialog.SolidColorOnly)
    flags += CC_SOLIDCOLOR;
  chooseColor.Flags = flags;
  if (!ChooseColor(&chooseColor)) return false;
  if (chooseColor.rgbResult != RGB(colorDialog.Color().R, colorDialog.Color().G, colorDialog.Color().B)) colorDialog.Color = System::Drawing::Color::FromArgb(255, GetRValue(chooseColor.rgbResult), GetGValue(chooseColor.rgbResult), GetBValue(chooseColor.rgbResult));

  for (int32 index = 0; index < colorDialog.CustomColors().Length; index++)
    colorDialog.CustomColors()[index] = System::Drawing::Color::FromArgb(255, GetRValue(customColors[index]), GetGValue(customColors[index]), GetBValue(customColors[index]));

  return true;
}

bool Native::CommonDialog::RunOpenFileDialog(intptr hwnd, System::Windows::Forms::OpenFileDialog& openFileDialog) {
  OPENFILENAME openFileName;
  ZeroMemory(&openFileName, sizeof(openFileName));
  openFileName.lStructSize = sizeof(openFileName);

  openFileName.hwndOwner = hwnd != IntPtr::Zero ? (HWND)hwnd : GetActiveWindow();

  const Array<byte> filter = ToFilter(openFileDialog.Filter().Split('|'));
  openFileName.lpstrFilter = openFileDialog.Filter() != "" ? (LPWSTR)filter.Data() : null;
  openFileName.lpstrCustomFilter = null;
  openFileName.nFilterIndex = openFileDialog.Filter() != "" ? openFileDialog.FilterIndex : 0;

  std::wstring fileName(MAX_PATH, ' ');
  openFileName.lpstrFile = (LPWSTR)fileName.c_str();
  openFileName.nMaxFile = MAX_PATH;

  wchar fileTitle[MAX_PATH];
  fileTitle[0] = 0;
  openFileName.lpstrFileTitle = fileTitle;
  openFileName.nMaxFileTitle = MAX_PATH;

  std::wstring initialDirectory = openFileDialog.InitialDirectory().w_str();
  openFileName.lpstrInitialDir = initialDirectory.c_str();

  std::wstring title = openFileDialog.Title().w_str();
  openFileName.lpstrTitle = title.c_str();

  int32 flags = OFN_EXPLORER;
  if (openFileDialog.Multiselect) flags |= OFN_ALLOWMULTISELECT;
  if (!openFileDialog.DereferenceLinks) flags |= OFN_NODEREFERENCELINKS;
  if (openFileDialog.CheckFileExists) flags |= OFN_PATHMUSTEXIST;
  if (openFileDialog.ReadOnlyChecked) flags |= OFN_READONLY;
  if (openFileDialog.ShowHelp) flags |= OFN_SHOWHELP;
  openFileName.Flags = flags;

  openFileName.nFileOffset = 0;
  openFileName.nFileExtension = 0;

  std::wstring defaultExt = openFileDialog.DefaultExt().w_str();
  openFileName.lpstrDefExt = defaultExt.c_str();

  BOOL result = GetOpenFileName(&openFileName);
  if (!result  && CommDlgExtendedError() == 0) return false;

  if (!result  && CommDlgExtendedError() == FNERR_BUFFERTOOSMALL) {
    int32 size = (int32)*fileName.c_str();
    fileName = std::wstring(size, ' ');
    openFileName.lpstrFile = (LPWSTR)fileName.c_str();
    result = GetOpenFileName(&openFileName);
  }

  if (!result  && CommDlgExtendedError() != 0)
    throw InvalidOperationException(caller_);

  if (!openFileDialog.Multiselect)
    openFileDialog.FileName = fileName;
  else {
    System::Collections::Generic::List<string> fileNames;
    string path = fileName;
    for (int32 index = (int32)wcslen(fileName.c_str()) + 1; fileName.c_str()[index] != 0; index += (int32)wcslen(&fileName.c_str()[index]) + 1)
      fileNames.Add(System::IO::Path::Combine(path, &fileName.c_str()[index]));
    openFileDialog.FileName = fileNames[0];
    openFileDialog.__set__file_names__(fileNames.ToArray());
  }
  return true;
}

bool Native::CommonDialog::RunSaveFileDialog(intptr hwnd, System::Windows::Forms::SaveFileDialog& saveFileDialog) {
  OPENFILENAME openFileName;
  ZeroMemory(&openFileName, sizeof(openFileName));
  openFileName.lStructSize = sizeof(openFileName);

  openFileName.hwndOwner = hwnd != IntPtr::Zero ? (HWND)hwnd : GetActiveWindow();

  const Array<byte> filter = ToFilter(saveFileDialog.Filter().Split('|'));
  openFileName.lpstrFilter = saveFileDialog.Filter() != "" ? (LPWSTR)filter.Data() : null;
  openFileName.lpstrCustomFilter = null;
  openFileName.nFilterIndex = saveFileDialog.Filter() != "" ? saveFileDialog.FilterIndex : 0;

  wchar fileName[MAX_PATH];
  wcscpy(fileName, saveFileDialog.FileName().w_str().c_str());
  openFileName.lpstrFile = fileName;
  openFileName.nMaxFile = MAX_PATH;

  wchar fileTitle[MAX_PATH];
  fileTitle[0] = 0;
  openFileName.lpstrFileTitle = fileTitle;
  openFileName.nMaxFileTitle = MAX_PATH;

  std::wstring initialDirectory = saveFileDialog.InitialDirectory().w_str();
  openFileName.lpstrInitialDir = initialDirectory.c_str();

  std::wstring title = saveFileDialog.Title().w_str();
  openFileName.lpstrTitle = title.c_str();

  int32 flags = 0;
  if (saveFileDialog.CreatePrompt) flags |= OFN_CREATEPROMPT;
  if (!saveFileDialog.DereferenceLinks) flags |= OFN_NODEREFERENCELINKS;
  if (saveFileDialog.CheckFileExists) flags |= OFN_PATHMUSTEXIST;
  if (saveFileDialog.ShowHelp) flags |= OFN_SHOWHELP;
  openFileName.Flags = flags;

  openFileName.nFileOffset = 0;
  openFileName.nFileExtension = 0;

  std::wstring defaultExt = saveFileDialog.DefaultExt().w_str();
  openFileName.lpstrDefExt = defaultExt.c_str();

  if (!GetSaveFileName(&openFileName)) return false;

  saveFileDialog.FileName = fileName;
  return true;
}

bool Native::CommonDialog::RunFolderBrowserDialog(intptr hwnd, System::Windows::Forms::FolderBrowserDialog& folderBrowserDialog) {
  return false;
}
#endif
