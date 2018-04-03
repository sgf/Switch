#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace TimerFormExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->Text = "Timer Example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 300);
      this->ClientSize = System::Drawing::Size(230, 130);

      this->label.Parent = *this;
      this->label.Text = string::Format("{0:N1}", as<double>(this->counter) / 10);
      this->label.Location = System::Drawing::Point(10, 10);
      this->label.Size = System::Drawing::Size(210, 70);
      //this->label.AutoSize = true;
      this->label.Font = System::Drawing::Font(this->label.Font().Name, 48, System::Drawing::FontStyle::Italic);
      this->label.ForeColor = System::Drawing::Color::DodgerBlue;

      this->timer.Interval = 100;
      this->timer.Tick += delegate_(const object & sender, const EventArgs & e) {
        if (this->counter == 73) return;
        this->label.Text = string::Format("{0:F1}", as<double>(++this->counter) / 10);
      };

      this->button.Parent = *this;
      this->button.Text = "Start";
      this->button.Location = System::Drawing::Point(10, 90);

      this->button.Click += delegate_(const object & sender, const EventArgs & e) {
        this->timer.Enabled = !this->timer.Enabled;
        this->button.Text = this->timer.Enabled ? "Stop" : "Start";
      };
    }

  private:
    Label label;
    Button button;
    Timer timer;
    int counter = 0;
  };
}

startup_(TimerFormExample::Form1);
