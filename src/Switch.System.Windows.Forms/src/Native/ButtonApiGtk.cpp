#if defined(__linux__)

#include <gtkmm/button.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/Button.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class Button : public Widget<Gtk::Button> {
  public:
    Button() {}
    void Text(const string& text) override {((Gtk::Button*)this->handle)->set_label(text.c_str());}
  };
}

intptr Native::ButtonApi::Create(const System::Windows::Forms::Button& button) {
  Native::Button* handle = new Native::Button();
  handle->Move(button.Location().X, button.Location().Y);
  handle->Text(button.Text);
  handle->Visible(true);
  return (intptr)handle;
}

void Native::ButtonApi::SetIsDefault(const System::Windows::Forms::ButtonBase& button) {

}

#endif
