#if defined(__linux__)

#include <gtkmm/radiobutton.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/RadioButton.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class RadioButton : public Widget<Gtk::RadioButton> {
  public:
    RadioButton() {}
    void Checked(bool checked) {this->handle->set_active(checked);}
    void ResetGroup() {this->handle->reset_group();}
    void Group(IWidget* group) {
      this->handle->set_group(group->RadioButtonGroup());
    }
    void Text(const string& text) override {this->handle->set_label(text.c_str());}
  };
}

intptr Native::RadioButtonApi::Create(const System::Windows::Forms::RadioButton& radioButton) {
  Native::RadioButton* handle = new Native::RadioButton();
  handle->Move(radioButton.Location().X, radioButton.Location().Y);
  handle->Text(radioButton.Text);
  handle->Visible(true);
  return (intptr)handle;
}

System::Drawing::Size Native::RadioButtonApi::GetDefaultSize() {
  return System::Drawing::Size(104, 24);
}

void Native::RadioButtonApi::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  ((Native::RadioButton*)radioButton.Handle())->Checked(radioButton.Checked);
}

void Native::RadioButtonApi::SetGroup(const System::Windows::Forms::RadioButton& radioButton) {
  ((Native::RadioButton*)radioButton.Handle())->ResetGroup();
  if (radioButton.Parent != null)
    ((Native::RadioButton*)radioButton.Handle())->Group((Native::IWidget*)radioButton.Parent()().Handle());
}

#endif
