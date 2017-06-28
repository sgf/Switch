#if defined(__linux__)

#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/window.h>
#include <Pcf/System/Console.hpp>
#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  Glib::RefPtr<Gtk::Application> application = Gtk::Application::create();
  int32 exitCode = 0;
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  Environment::Exit(exitCode);
}

void FormsApi::Application::MessageLoop(const System::Windows::Forms::Form& mainForm, EventHandler idle) {
  Glib::signal_idle().connect(pcf_delegate {
    idle.Invoke(object(), EventArgs::Empty);
    return mainForm.Visible() && !idle.IsEmpty();
  });
  exitCode = application->run(as<Gtk::Window>(((__OS::IWidget*)mainForm.Handle())->ToWidget()));
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
}

namespace {
  void AddButtons(Gtk::MessageDialog& dialog, MessageBoxButtons buttons) {
    switch(buttons) {
    case MessageBoxButtons::AbortRetryIgnore:
      dialog.add_button("Abort", (int)DialogResult::Abort);
      dialog.add_button("Retry", (int)DialogResult::Retry);
      dialog.add_button("Ignore", (int)DialogResult::Ignore);
      break;
    case MessageBoxButtons::OK:
      dialog.add_button("Ok", (int)DialogResult::OK);
      break;
    case MessageBoxButtons::OKCancel:
      dialog.add_button("Ok", (int)DialogResult::OK);
      dialog.add_button("Cancel", (int)DialogResult::Cancel);
      break;
    case MessageBoxButtons::RetryCancel:
      dialog.add_button("Retry", (int)DialogResult::Retry);
      dialog.add_button("Cancel", (int)DialogResult::Cancel);
      break;
    case MessageBoxButtons::YesNo:
      dialog.add_button("Yes", (int)DialogResult::Yes);
      dialog.add_button("No", (int)DialogResult::No);
      break;
    case MessageBoxButtons::YesNoCancel:
      dialog.add_button("Yes", (int)DialogResult::Yes);
      dialog.add_button("No", (int)DialogResult::No);
      dialog.add_button("Cancel", (int)DialogResult::Cancel);
      break;
    }
  }
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  static System::Collections::Generic::SortedDictionary<MessageBoxIcon, Gtk::MessageType> icons = {{MessageBoxIcon::None, Gtk::MESSAGE_OTHER}, {MessageBoxIcon::Error, Gtk::MESSAGE_ERROR}, {MessageBoxIcon::Question, Gtk::MESSAGE_QUESTION}, {MessageBoxIcon::Warning, Gtk::MESSAGE_WARNING}, {MessageBoxIcon::Information, Gtk::MESSAGE_INFO}};
  static refptr<Gtk::Window> emptyWindow = pcf_new<Gtk::Window>();
  Gtk::Window* activeWindow = application->get_active_window();
  if (activeWindow == null) activeWindow = emptyWindow.ToPointer();
  Gtk::MessageDialog dialog(*activeWindow, caption.c_str(), true /* use_markup */, icons[icon], Gtk::BUTTONS_NONE, true);
  AddButtons(dialog, buttons);
  dialog.set_secondary_text(message.c_str());
  dialog.set_modal();
  dialog.set_position(Gtk::WindowPosition::WIN_POS_CENTER);
  int result = dialog.run();
  if (result < 0)
    return DialogResult::Cancel;
  return (DialogResult)result;
}

void FormsApi::Application::Start() {
  // no implementation
}

void FormsApi::Application::Stop() {
  // no implementation
}

#endif
