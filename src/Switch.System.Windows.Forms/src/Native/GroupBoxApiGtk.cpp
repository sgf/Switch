#if defined(__linux__)

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/GroupBox.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class GroupBox : public Widget<Gtk::Frame> {
  public:
    GroupBox() {
      this->handle->set_shadow_type(Gtk::SHADOW_IN);
      this->handle->add(this->fixed);

      this->handle->signal_show().connect(delegate_ {
        this->fixed.show();
      });
    }

    const Gtk::Container& Container() const override {return this->fixed;}

    Gtk::Container& Container() override {return this->fixed;}

    void Text(const string& text) override {this->handle->set_label(text.c_str());}

  private:
    Gtk::Fixed fixed;
  };
}

intptr Native::GroupBoxApi::Create(const System::Windows::Forms::GroupBox& groupBox) {
  Native::GroupBox* handle = new Native::GroupBox();
  handle->Move(groupBox.Location().X, groupBox.Location().Y);
  handle->Text(groupBox.Text);
  handle->Visible(true);
  return (intptr)handle;
}

System::Drawing::Size Native::GroupBoxApi::GetDefaultSize() {
  return System::Drawing::Size(200, 100);
}

#endif
