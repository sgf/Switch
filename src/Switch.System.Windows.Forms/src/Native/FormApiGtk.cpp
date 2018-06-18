#if defined(__linux__)

#include <gtkmm/fixed.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/window.h>
#include "WidgetGtk.hpp"
#include <Switch/Microsoft/Win32/Registry.hpp>
#include "../../include/Switch/System/Windows/Forms/Form.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class Form : public Widget<Gtk::Window> {
  public:
    Form() {
      this->handle->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);

      this->handle->signal_show().connect(delegate_ {
        this->scrolledWindow.show();
        this->fixed.show();
      });

      this->handle->signal_hide().connect(delegate_ {
        System::Windows::Forms::Control::FromHandle((intptr)this)().Visible = false;
      });
    }

    void Close() {
      this->handle->close();
    }

    const Gtk::Container& Container() const override {return this->fixed;}

    Gtk::Container& Container() override {return this->fixed;}

    void Move(int32 x, int32 y) override {
      this->handle->move(x + Screen::AllScreens()[0].WorkingArea().X, y + Screen::AllScreens()[0].WorkingArea().Y);
    }

    void Text(const string& text) override {this->handle->set_title(text.c_str());}

  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };
}

void Native::FormApi::Close(System::Windows::Forms::Form& form) {
  ((Native::Form*)form.Handle())->Close();
}

intptr Native::FormApi::Create(System::Windows::Forms::Form& form, bool withClientsize) {
  static Microsoft::Win32::RegistryKey key = Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Gammasoft71").CreateSubKey("Switch").CreateSubKey("Forms");
  static int location = as<Int32>(key.GetValue("DefaultLocation", 20));
  static bool nextLocation = Convert::ToBoolean(as<Int32>(key.GetValue("NextLocation", 1))); // Strangely, on Windows the first location is used 2 times; this boolean simumate it.

  System::Drawing::Rectangle bounds = form.Bounds;
  if (withClientsize) bounds.Size = System::Drawing::Size::Add(form.ClientSize, {0, SystemInformationApi::GetCaptionHeight()});
  switch (form.StartPosition) {
  case FormStartPosition::CenterScreen: bounds = System::Drawing::Rectangle((Screen::AllScreens()[0].WorkingArea().Width + Screen::AllScreens()[0].WorkingArea().X - bounds.Width) / 2, (Screen::AllScreens()[0].WorkingArea().Height + Screen::AllScreens()[0].WorkingArea().Y - bounds.Height) / 2, bounds.Width, bounds.Height); break;
  case FormStartPosition::Manual: break;
  case FormStartPosition::WindowsDefaultBounds: bounds = System::Drawing::Rectangle(location, location, Screen::AllScreens()[0].WorkingArea().Width / 4 * 3, Screen::AllScreens()[0].WorkingArea().Height / 4 * 3); break;
  case FormStartPosition::CenterParent:
  case FormStartPosition::WindowsDefaultLocation: bounds = System::Drawing::Rectangle(location, location, bounds.Width, bounds.Height); break;
  default: break;
  }
  form.Location = System::Drawing::Point(bounds.Left, bounds.Top);
  if (withClientsize)
    form.Size = System::Drawing::Size::Subtract(bounds.Size, {0, SystemInformationApi::GetCaptionHeight()});
  else
    form.Size = System::Drawing::Size(bounds.Width, bounds.Height);

  if (form.StartPosition == FormStartPosition::WindowsDefaultBounds || form.StartPosition == FormStartPosition::CenterParent || form.StartPosition == FormStartPosition::WindowsDefaultLocation) {
    nextLocation = !(nextLocation == true && location == 20);
    if (nextLocation)
      location = location < 180 ? location + 20 : 20;
    key.SetValue("DefaultLocation", as<int32>(location), Microsoft::Win32::RegistryValueKind::DWord);
    key.SetValue("NextLocation", nextLocation, Microsoft::Win32::RegistryValueKind::DWord);
  }

  Native::Form* handle = new Native::Form();
  handle->Text(form.Text);
  return (intptr)handle;
}

System::Drawing::Size Native::FormApi::GetDefaultSize() {
  return System::Drawing::Size(300, 300);
}

#endif

