#include "../../../../Native/Api.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/SaveFileDialog.hpp"

using namespace System;
using namespace System::Windows::Forms;

SaveFileDialog::SaveFileDialog() {
  this->Reset();
}

void SaveFileDialog::Reset() {
  this->FileDialog::addExtension = true;
  this->FileDialog::autoUpgradeEnabled = true;
  this->FileDialog::checkFileExists = false;
  this->FileDialog::checkPathExists = false;
  this->FileDialog::fileDialogCustomPlaceCollection.Clear();
  this->FileDialog::defaultExt = "";
  this->FileDialog::dereferenceLinks = true;
  this->FileDialog::fileName = "";
  this->FileDialog::fileNames.Clear();
  this->FileDialog::filter = "";
  this->FileDialog::filterIndex = 1;
  this->FileDialog::initialDirectory = "";
  this->FileDialog::restoreDirectory = false;
  this->FileDialog::showHelp = false;
  this->FileDialog::supportMultiDottedExtensions = false;
  this->FileDialog::title = "";
  this->FileDialog::validateNames = true;
  this->createPrompt = false;
}

bool SaveFileDialog::RunDialog(intptr hwndOwner) {
  return Native::CommonDialog::RunSaveFileDialog(hwndOwner, *this);
}
