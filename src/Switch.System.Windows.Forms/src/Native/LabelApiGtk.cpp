#if defined(__linux__)

#include <gtkmm/label.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/Label.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class Label : public Widget<Gtk::Label> {
  public:
    Label() {}
    void Text(const string& text) override {this->handle->set_label(text.c_str());}

    void TextAlign(System::Drawing::ContentAlignment contentAlignment) {
      switch (contentAlignment) {
      case System::Drawing::ContentAlignment::BottomCenter : this->handle->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_END); break;
      case System::Drawing::ContentAlignment::BottomLeft : this->handle->set_alignment(Gtk::ALIGN_START, Gtk::ALIGN_END); break;
      case System::Drawing::ContentAlignment::BottomRight : this->handle->set_alignment(Gtk::ALIGN_END, Gtk::ALIGN_END); break;
      case System::Drawing::ContentAlignment::MiddleCenter : this->handle->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER); break;
      case System::Drawing::ContentAlignment::MiddleLeft : this->handle->set_alignment(Gtk::ALIGN_START, Gtk::ALIGN_CENTER); break;
      case System::Drawing::ContentAlignment::MiddleRight : this->handle->set_alignment(Gtk::ALIGN_END, Gtk::ALIGN_CENTER); break;
      case System::Drawing::ContentAlignment::TopCenter : this->handle->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_START); break;
      case System::Drawing::ContentAlignment::TopLeft : this->handle->set_alignment(Gtk::ALIGN_START, Gtk::ALIGN_START); break;
      case System::Drawing::ContentAlignment::TopRight : this->handle->set_alignment(Gtk::ALIGN_END, Gtk::ALIGN_START); break;
      }

    }
  };
}

intptr Native::LabelApi::Create(const System::Windows::Forms::Label& label) {
  Native::Label* handle = new Native::Label();
  handle->Move(label.Location().X, label.Location().Y);
  handle->Text(label.Text);
  handle->Visible(true);
  return (intptr)handle;
}

void Native::LabelApi::SetBorderStyle(const System::Windows::Forms::Label& label) {
}

void Native::LabelApi::SetTextAlign(const System::Windows::Forms::Label& label) {
  ((Native::Label*)label.Handle())->TextAlign(label.TextAlign);
}

#endif
