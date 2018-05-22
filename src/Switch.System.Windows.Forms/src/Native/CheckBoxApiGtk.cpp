#if defined(__linux__)

#include <gtkmm/checkbutton.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/CheckBox.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class CheckBox : public Widget<Gtk::CheckButton> {
  public:
    CheckBox() {}
    void SetCheckState(System::Windows::Forms::CheckState checkState) {
      ((Gtk::CheckButton*)this->handle)->set_inconsistent(checkState == System::Windows::Forms::CheckState::Indeterminate);
      ((Gtk::CheckButton*)this->handle)->set_active(checkState == System::Windows::Forms::CheckState::Checked);
    }
    void Text(const string& text) override {((Gtk::CheckButton*)this->handle)->set_label(text.c_str());}
  };
}

intptr Native::CheckBoxApi::Create(const System::Windows::Forms::CheckBox& checkBox) {
  Native::CheckBox* handle = new Native::CheckBox();
  handle->Move(checkBox.Location().X, checkBox.Location().Y);
  handle->Text(checkBox.Text);
  handle->Visible(true);
  return (intptr)handle;
}

void Native::CheckBoxApi::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {

}

void Native::CheckBoxApi::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  ((Native::CheckBox*)checkBox.Handle())->SetCheckState(checkBox.CheckState);
}

#endif
