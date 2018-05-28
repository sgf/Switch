#if defined(__linux__)

#include <gtkmm.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/ProgressBar.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class ProgressBar : public Widget<Gtk::ProgressBar> {
  public:
    ProgressBar() {}
    void BackColor(const System::Drawing::Color& color) override {}
    void Marquee(bool marquee, int32 animationSpeed) {
      if (marquee) {
        this->isMarquee = true;
        this->marquee = g_timeout_add(animationSpeed, MarqueeProc, (gpointer)this);
      } else {
        if (this->isMarquee == true) {
          g_source_remove(this->marquee);
          this->isMarquee = false;
        }
      }
    }
    void Maximum(int32 maximum) {this->maximum = maximum;}
    void Minimum(int32 minimum) {this->minimum = minimum;}
    void Pulse() {this->handle->pulse();}
    void Text(const string& text) override {}
    void Value(int32 value) {this->handle->set_fraction((double)value / ((double)this->maximum - (double)this->minimum));}

  private:
    static int MarqueeProc(gpointer progressBar) {
      ((Native::ProgressBar*)progressBar)->Pulse();
      return 1;
    }

    guint marquee = 0;
    bool isMarquee = false;
    int32 maximum = 100;
    int32 minimum = 0;
  };
}

intptr Native::ProgressBarApi::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  Native::ProgressBar* handle = new Native::ProgressBar();
  handle->Move(progressBar.Location().X, progressBar.Location().Y);
  handle->Text(progressBar.Text);
  handle->Visible(true);
  return (intptr)handle;
}

System::Drawing::Size Native::ProgressBarApi::GetDefaultSize() {
  return System::Drawing::Size(100, 23);
}

void Native::ProgressBarApi::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Native::ProgressBar*)progressBar.Handle())->Maximum(progressBar.Maximum);
}

void Native::ProgressBarApi::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Native::ProgressBar*)progressBar.Handle())->Minimum(progressBar.Minimum);
}

void Native::ProgressBarApi::SetMarquee(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Native::ProgressBar*)progressBar.Handle())->Marquee(progressBar.Style == System::Windows::Forms::ProgressBarStyle::Marquee, progressBar.MarqueeAnimationSpeed);
}

void Native::ProgressBarApi::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Native::ProgressBar*)progressBar.Handle())->Value(progressBar.Value);
}

#endif
