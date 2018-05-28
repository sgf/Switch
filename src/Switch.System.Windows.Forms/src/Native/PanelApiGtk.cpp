#if defined(__linux__)

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/Panel.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class Panel : public Widget<Gtk::Frame> {
  public:
    Panel() {
      this->handle->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);

      this->handle->signal_show().connect(delegate_ {
        this->scrolledWindow.show();
        this->fixed.show();
      });
    }

    void BorderStyle(System::Windows::Forms::BorderStyle borderStyle) {
      switch (borderStyle) {
      case System::Windows::Forms::BorderStyle::None: this->handle->set_shadow_type(Gtk::SHADOW_NONE); break;
      case System::Windows::Forms::BorderStyle::FixedSingle: this->handle->set_shadow_type(Gtk::SHADOW_IN); break;
      case System::Windows::Forms::BorderStyle::Fixed3D: this->handle->set_shadow_type(Gtk::SHADOW_ETCHED_IN); break;
      }
    }

    const Gtk::Container& Container() const override {return this->fixed;}

    Gtk::Container& Container() override {return this->fixed;}

    void Text(const string& text) override {}

  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };
}

intptr Native::PanelApi::Create(const System::Windows::Forms::Panel& panel) {
  Native::Panel* handle = new Native::Panel();
  handle->Move(panel.Location().X, panel.Location().Y);
  handle->Text(panel.Text);
  handle->Visible(true);
  return (intptr)handle;
}

System::Drawing::Size Native::PanelApi::GetDefaultSize() {
  return System::Drawing::Size(200, 100);
}

void Native::PanelApi::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  ((Native::Panel*)panel.Handle())->BorderStyle(panel.BorderStyle);
}

#endif
