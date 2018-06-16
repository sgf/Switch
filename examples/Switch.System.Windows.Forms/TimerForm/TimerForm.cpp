#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace Examples {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->label.Text = string::Format("{0:F1}", as<double>(this->counter) / 10);
      this->label.Location = System::Drawing::Point(10, 10);
      this->label.Size = System::Drawing::Size(210, 70);
      this->label.Font = System::Drawing::Font(this->label.Font().Name, 48, System::Drawing::FontStyle::Italic);
      this->label.ForeColor = System::Drawing::Color::DodgerBlue;

      this->timer.Interval = 100;
      this->timer.Tick += delegate_(const object & sender, const EventArgs & e) {
        this->label.Text = string::Format("{0:F1}", as<double>(++this->counter) / 10);
      };

      this->button.Text = "Start";
      this->button.Location = System::Drawing::Point(10, 90);
      this->button.Click += delegate_(const object & sender, const EventArgs & e) {
        this->timer.Enabled = !this->timer.Enabled;
        this->button.Text = this->timer.Enabled ? "Stop" : "Start";
      };

      this->Text = "Timer Example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 300);
      this->ClientSize = System::Drawing::Size(230, 130);
      this->Controls().AddRange({this->label, this->button});
    }

  private:
    Label label;
    Button button;
    Timer timer;
    int counter = 0;
  };
}

startup_(Examples::Form1);
