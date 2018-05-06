#if defined(__linux__)

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/notebook.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/TabPage.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class TabPage : public Widget<Gtk::Frame> {
  public:
    TabPage() {
      this->handle = new Gtk::Frame();
      this->RegisterEvent();
      this->handle->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);

      this->handle->signal_show().connect(delegate_ {
        this->scrolledWindow.show();
        this->fixed.show();
      });
    }

    const Gtk::Container& Container() const override {return this->fixed;}

    Gtk::Container& Container() override {return this->fixed;}

    void Text(const string& text) override {}

  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };
}

intptr Native::TabPageApi::Create(const System::Windows::Forms::TabPage& tabPage) {
  Native::TabPage* handle = new Native::TabPage();
  return (intptr)handle;
}

void Native::TabPageApi::SetBorderStyle(const System::Windows::Forms::TabPage& tabPage) {
}

#endif
