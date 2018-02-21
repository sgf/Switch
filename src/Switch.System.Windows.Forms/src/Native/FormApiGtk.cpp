#if defined(__linux__)

#include <gtkmm/fixed.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/window.h>

#include "WidgetGtk.hpp"
#include <Switch/System/Random.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class Form : public Widget, public Gtk::Window {
  public:
    Form() {
      this->RegisterEvent();
      this->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);

      this->signal_show().connect(delegate_ {
        this->scrolledWindow.show();
        this->fixed.show();
      });

      this->signal_hide().connect(delegate_ {
        System::Windows::Forms::Control::FromHandle((intptr)this)().Visible = false;
      });
    }

    const Gtk::Container& Container() const override {return this->fixed;}

    Gtk::Container& Container() override {return this->fixed;}

    void Move(int32 x, int32 y) override {
      this->Gtk::Window::move(x, y);
    }

    void Text(const string& text) override {this->set_title(text.c_str());}

  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };
}

void Native::FormApi::Close(System::Windows::Forms::Form& form) {
  ((Native::Form*)form.Handle())->close();
}

intptr Native::FormApi::Create(System::Windows::Forms::Form& form) {
  static Microsoft::Win32::RegistryKey key = Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Gammasoft71\\Switch\\Forms");
  static int location = as<Int32>(key.GetValue("DefaultLocation", 20));

  System::Drawing::Rectangle bounds = form.Bounds;
  switch (form.StartPosition) {
  case FormStartPosition::Manual: bounds = form.Bounds; break;
  case FormStartPosition::WindowsDefaultBounds: bounds = System::Drawing::Rectangle(location, location, 800, 600); break;
  case FormStartPosition::WindowsDefaultLocation: bounds = System::Drawing::Rectangle(location, location, form.Width, form.Height); break;
  default: break;
  }
  form.Location = System::Drawing::Point(bounds.Left, bounds.Top);
  form.Size = System::Drawing::Size(bounds.Width, bounds.Height);

  if (form.StartPosition == FormStartPosition::WindowsDefaultBounds || form.StartPosition == FormStartPosition::WindowsDefaultLocation) {
    location = location < 300 ? location + 20 : 20;
    key.SetValue("DefaultLocation", location, Microsoft::Win32::RegistryValueKind::DWord);
  }

  Native::Form* handle = new Native::Form();
  handle->Text(form.Text);
  return (intptr)handle;
}

#endif
