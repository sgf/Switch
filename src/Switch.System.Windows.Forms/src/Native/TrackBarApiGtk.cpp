#if defined(__linux__)

#include <gtkmm.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/TrackBar.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class TrackBar : public Widget<Gtk::Scale> {
  public:
    explicit TrackBar(Orientation orientation) {
      this->handle = new Gtk::Scale(orientation == Orientation::Horizontal ? Gtk::ORIENTATION_HORIZONTAL : Gtk::ORIENTATION_VERTICAL);
      this->handle->set_draw_value(false);
      this->RegisterEvent();
    }
    void AddMark(int32 value, Gtk::PositionType position) {this->handle->add_mark(value, position, "");}
    void ClearMarks() {this->handle->clear_marks();}
    void RegisterEvent() override {
      this->Widget<Gtk::Scale>::RegisterEvent();
      this->handle->signal_value_changed().connect(delegate_ {
        ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle((intptr)this);
        if (control == null) return;
        Message event = Message::Create((intptr)this, as<System::Windows::Forms::TrackBar>(control)().Orientation == Orientation::Vertical ? WM_VSCROLL : WM_HSCROLL, 0, (intptr)this, 0, 0);
        control().Parent()().WndProc(event);
      });
    }
    void Range(int32 minimum, int32 maximum) {this->handle->set_range(minimum, maximum);}
    void Text(const string& text) override {}
    int32 Value() {return this->handle->get_value();}
    void Value(int32 value) {this->handle->set_value(value);}
  };
}

intptr Native::TrackBarApi::Create(const System::Windows::Forms::TrackBar& trackBar) {
  Native::TrackBar* handle = new Native::TrackBar(trackBar.Orientation);
  handle->Move(trackBar.Location().X, trackBar.Location().Y);
  handle->Text(trackBar.Text);
  handle->Visible(true);
  return (intptr)handle;
}

void Native::TrackBarApi::SetLargeChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on Gtk
}

void Native::TrackBarApi::SetMaximum(const System::Windows::Forms::TrackBar& trackBar) {
  ((Native::TrackBar*)trackBar.Handle())->Range(trackBar.Minimum(), trackBar.Maximum());
}

void Native::TrackBarApi::SetMinimum(const System::Windows::Forms::TrackBar& trackBar) {
  ((Native::TrackBar*)trackBar.Handle())->Range(trackBar.Minimum(), trackBar.Maximum());
}

void Native::TrackBarApi::SetOrientation(const System::Windows::Forms::TrackBar& trackBar) {
  // if handle created recreate handle...
}

void Native::TrackBarApi::SetSmallChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on Gtk
}

void Native::TrackBarApi::SetTickFrequency(const System::Windows::Forms::TrackBar& trackBar) {
  if (trackBar.TickStyle == TickStyle::None)
    ((Native::TrackBar*)trackBar.Handle())->ClearMarks();
  else {
    Gtk::PositionType position = Gtk::POS_BOTTOM;
    if (trackBar.Orientation == Orientation::Horizontal)
      position = trackBar.TickStyle == TickStyle::TopLeft ? Gtk::POS_TOP : Gtk::POS_BOTTOM;
    else
      position = trackBar.TickStyle == TickStyle::TopLeft ? Gtk::POS_LEFT : Gtk::POS_RIGHT;

    for (int32 i = 0; i <= trackBar.Maximum - trackBar.Minimum; i +=  trackBar.TickFrequency)
      ((Native::TrackBar*)trackBar.Handle())->AddMark(i, position);
  }
}

void Native::TrackBarApi::SetTickStyle(const System::Windows::Forms::TrackBar& trackBar) {
  SetTickFrequency(trackBar);
}

int32 Native::TrackBarApi::GetValue(const System::Windows::Forms::TrackBar& trackBar) {
  return ((Native::TrackBar*)trackBar.Handle())->Value();
}

void Native::TrackBarApi::SetValue(const System::Windows::Forms::TrackBar& trackBar) {
  ((Native::TrackBar*)trackBar.Handle())->Value(trackBar.Value());
}

#endif
