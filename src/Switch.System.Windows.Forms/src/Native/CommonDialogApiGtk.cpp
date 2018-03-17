#if defined(__linux__)

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>
#include "WidgetGtk.hpp"

extern Glib::RefPtr<Gtk::Application> __application__;

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

bool Native::CommonDialog::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog& colorDialog) {
  Gtk::Window* window = hwnd != IntPtr::Zero ? (Gtk::Window*)hwnd : __application__->get_active_window();

  Gtk::ColorChooserDialog colorChooserDialog("Color");
  if (window != null) colorChooserDialog.set_transient_for(*window);
  colorChooserDialog.set_modal(true);
  colorChooserDialog.set_rgba(Native::Widget::FromColor(colorDialog.Color));

  int result = colorChooserDialog.run();
  if (result == Gtk::RESPONSE_CANCEL) return false;
  if (colorChooserDialog.get_rgba() != Native::Widget::FromColor(colorDialog.Color)) colorDialog.Color = Native::Widget::ToColor(colorChooserDialog.get_rgba());
  return true;
}

#endif
