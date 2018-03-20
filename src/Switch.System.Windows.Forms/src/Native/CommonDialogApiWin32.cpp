#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Switch/Undef.hpp>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/ColorDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/OpenFileDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/SaveFileDialog.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

bool Native::CommonDialog::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog& colorDialog) {
  CHOOSECOLOR chooseColor;
  COLORREF customColors[16];
  for (int32 index = 0; index < colorDialog.CustomColors().Length; index++)
    customColors[index] = RGB(colorDialog.CustomColors()[index].R, colorDialog.CustomColors()[index].G, colorDialog.CustomColors()[index].B);
  memset(&chooseColor, 0, sizeof(chooseColor));
  chooseColor.lStructSize = sizeof(chooseColor);
  chooseColor.hwndOwner = (HWND)hwnd;
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
  return false;
}

bool Native::CommonDialog::RunSaveFileDialog(intptr hwnd, System::Windows::Forms::SaveFileDialog& saveFileDialog) {
  return false;
}

#endif
