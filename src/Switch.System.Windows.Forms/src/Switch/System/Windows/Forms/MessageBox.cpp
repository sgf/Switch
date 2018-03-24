#include "../../../../../include/Switch/System/Windows/Forms/MessageBox.hpp"
#include <Switch/System/Media/SystemSounds.hpp>
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

namespace {
  DialogResult ShowMessageBox(intptr handle, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton, const string& helpFilePath) {
    System::Collections::Generic::Dictionary<MessageBoxIcon, Action<>> messageBeep = {{MessageBoxIcon::None, delegate_ {}}, {MessageBoxIcon::Hand, {System::Media::SystemSounds::Hand(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Question, {System::Media::SystemSounds::Question(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Exclamation, {System::Media::SystemSounds::Exclamation(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Asterisk, {System::Media::SystemSounds::Asterisk(), &System::Media::SystemSound::Play}}};
    messageBeep[icon]();
    return Native::ApplicationApi::ShowMessageBox(handle, text, caption, buttons, icon, defaultButton, options, displayHelpButton);
  }
}

DialogResult MessageBox::Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return ShowMessageBox(owner.Handle, text, caption, buttons, icon, defaultButton, options, displayHelpButton, "");
}

DialogResult MessageBox::Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath) {
  return ShowMessageBox(owner.Handle, text, caption, buttons, icon, defaultButton, options, true, helpFilePath);
}

DialogResult MessageBox::Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath, HelpNavigator navigator) {
  return ShowMessageBox(owner.Handle, text, caption, buttons, icon, defaultButton, options, true, helpFilePath);
}

DialogResult MessageBox::Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath, HelpNavigator navigator, any param) {
  return ShowMessageBox(owner.Handle, text, caption, buttons, icon, defaultButton, options, true, helpFilePath);
}

DialogResult MessageBox::Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return ShowMessageBox(IntPtr::Zero, text, caption, buttons, icon, defaultButton, options, displayHelpButton, "");
}

DialogResult MessageBox::Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath) {
  return ShowMessageBox(IntPtr::Zero, text, caption, buttons, icon, defaultButton, options, true, helpFilePath);
}

DialogResult MessageBox::Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath, HelpNavigator navigator) {
  return ShowMessageBox(IntPtr::Zero, text, caption, buttons, icon, defaultButton, options, true, helpFilePath);
}

DialogResult MessageBox::Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath, HelpNavigator navigator, any param) {
  return ShowMessageBox(IntPtr::Zero, text, caption, buttons, icon, defaultButton, options, true, helpFilePath);
}
