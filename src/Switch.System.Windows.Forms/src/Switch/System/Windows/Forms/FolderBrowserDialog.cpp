#include "../../../../Native/Api.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/FolderBrowserDialog.hpp"

using namespace System;
using namespace System::Windows::Forms;

FolderBrowserDialog::FolderBrowserDialog() {
  this->Reset();
}

void FolderBrowserDialog::Reset() {
  this->description = "";
  this->rootFolder = Environment::SpecialFolder::Desktop;
  this->selectedPath = "";
  this->showNewFolderButton = true;
  this->showHiddenFolders = false;
}

bool FolderBrowserDialog::RunDialog(intptr hwndOwner) {
  return Native::CommonDialog::RunFolderBrowserDialog(hwndOwner, *this);
}
