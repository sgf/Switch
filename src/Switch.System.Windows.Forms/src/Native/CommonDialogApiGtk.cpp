#if defined(__linux__)

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/ColorDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/OpenFileDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/SaveFileDialog.hpp"

extern Glib::RefPtr<Gtk::Application> __application__;

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

bool Native::CommonDialog::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog& colorDialog) {
  Gtk::Window* window = hwnd != IntPtr::Zero ? (Gtk::Window*)hwnd : __application__->get_active_window();
  Gtk::ColorChooserDialog colorChooserDialog("");
  if (window != null) colorChooserDialog.set_transient_for(*window);
  colorChooserDialog.set_modal(true);
  colorChooserDialog.set_rgba(Native::Widget::FromColor(colorDialog.Color));

  if (colorChooserDialog.run() == Gtk::RESPONSE_CANCEL) return false;
  if (colorChooserDialog.get_rgba() != Native::Widget::FromColor(colorDialog.Color)) colorDialog.Color = Native::Widget::ToColor(colorChooserDialog.get_rgba());
  return true;
}

bool Native::CommonDialog::RunOpenFileDialog(intptr hwnd, System::Windows::Forms::OpenFileDialog& openFileDialog) {
  Gtk::Window* window = hwnd != IntPtr::Zero ? (Gtk::Window*)hwnd : __application__->get_active_window();

  Gtk::FileChooserDialog fileChooserDialog(openFileDialog.Title().c_str(), Gtk::FILE_CHOOSER_ACTION_OPEN);
  if (window != null) fileChooserDialog.set_transient_for(*window);
  fileChooserDialog.set_modal(true);
  fileChooserDialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
  fileChooserDialog.add_button("Open", Gtk::RESPONSE_OK);

  if (fileChooserDialog.run() == Gtk::RESPONSE_CANCEL) return false;
  return true;
}

bool Native::CommonDialog::RunSaveFileDialog(intptr hwnd, System::Windows::Forms::SaveFileDialog& saveFileDialog) {
  Gtk::Window* window = hwnd != IntPtr::Zero ? (Gtk::Window*)hwnd : __application__->get_active_window();
  Gtk::FileChooserDialog fileChooserDialog(saveFileDialog.Title().c_str(), Gtk::FILE_CHOOSER_ACTION_SAVE);
  if (window != null) fileChooserDialog.set_transient_for(*window);
  fileChooserDialog.set_modal(true);
  fileChooserDialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
  fileChooserDialog.add_button("Save", Gtk::RESPONSE_OK);
  fileChooserDialog.set_filename("Undefined");

  if (fileChooserDialog.run() == Gtk::RESPONSE_CANCEL) return false;
  return true;
}

#endif