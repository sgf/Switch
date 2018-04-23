#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace TrackBarExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->Text = "TrackBar Example";

      this->trackBar.Parent = *this;
      this->trackBar.Location = System::Drawing::Point(20, 50);
      this->trackBar.Maximum = 200;
      this->trackBar.Value = 100;
      this->trackBar.Width = 200;
      this->trackBar.TickStyle = TickStyle::None;
      this->trackBar.ValueChanged += delegate_(const object & sender, const EventArgs & e) {
        this->progressBar.Value = this->trackBar.Value;
        this->label.Text = string::Format("{0}", this->trackBar.Value);
      };

      this->progressBar.Parent = *this;
      this->progressBar.Location = System::Drawing::Point(20, 100);
      this->progressBar.Maximum = 200;
      this->progressBar.Value = this->trackBar.Value;
      this->progressBar.Width = 200;

      this->label.Parent = *this;
      this->label.Text = string::Format("{0}", this->trackBar.Value);
      this->label.Location = System::Drawing::Point(20, 150);
    }

  private:
    TrackBar trackBar;
    ProgressBar progressBar;
    Label label;
  };
}

startup_(TrackBarExample::Form1);
