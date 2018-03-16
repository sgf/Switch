#include "../../../../Native/Api.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/CommonDialog.hpp"

using namespace System;
using namespace System::Windows::Forms;

DialogResult CommonDialog::ShowDialog() {
  return RunDialog(IntPtr::Zero) ? DialogResult::OK : DialogResult::Cancel;
}

DialogResult CommonDialog::ShowDialog(const IWin32Window& owner) {
  return RunDialog(owner.Handle) ? DialogResult::OK : DialogResult::Cancel;
}

intptr CommonDialog::HookProc(intptr hWnd, int32 msg, intptr wparam, intptr lparam) {
  return IntPtr::Zero;
}

void CommonDialog::OnHelpRequest(const EventArgs& e) {
  this->HelpRequest(*as<Component>(this), e);
}

intptr CommonDialog::OwnerWndProc(intptr hWnd, int32 msg, intptr wparam, intptr lparam) {
  if (msg == 0) { //Native::Dialog::GetHelpMessageNumber()
    try {
      this->OnHelpRequest(EventArgs::Empty);
    } catch (const Exception& exception) {
      Application::OnThreadException(exception);
    }
    return IntPtr::Zero;
  }
  return IntPtr::Zero; // Native::Dialog::DefWndProc(hWnd, msg, wparam, lparam);
}
