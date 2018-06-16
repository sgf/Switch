#include <Switch/Switch>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Drawing;
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
      /*
      Array<MenuItem> actionMenu = {
        {"Start", EventHandler(*this, &Form1::OnStartStopClick), Shortcut::CmdS},
        {"Pause", EventHandler(*this, &Form1::OnPauseResumeClick), Shortcut::CmdP},
        {"Reset", EventHandler(*this, &Form1::OnResetClick), Shortcut::CmdR}
      };

      this->mainMenu.MenuItems().Add(MenuItem("Action", actionMenu));
      this->Menu = this->mainMenu;
       */

      this->chrono.Parent = *this;
      this->chrono.BorderStyle = BorderStyle::Fixed3D;
      this->chrono.Bounds = Rectangle(20, 10, 235, 50);
      this->chrono.BackColor = System::Drawing::Color::LightGreen;
      this->chrono.ForeColor = System::Drawing::Color::DarkGreen;
      this->chrono.Font = System::Drawing::Font(System::Drawing::FontFamily::GenericMonospace, 22.0f);
      this->chrono.TextAlign = ContentAlignment::MiddleCenter;
      this->chrono.Text = "00:00:00.000";

      this->startStop.Parent = *this;
      this->startStop.Location = Point(10, 80);
      this->startStop.Text = "Start";
      this->startStop.Click += EventHandler(*this, &Form1::OnStartStopClick);

      this->pauseResume.Parent = *this;
      this->pauseResume.Location = Point(100, 80);
      this->pauseResume.Text = "Pause";
      this->pauseResume.Enabled = false;
      this->pauseResume.Click += EventHandler(*this, &Form1::OnPauseResumeClick);

      this->reset.Parent = *this;
      this->reset.Location = Point(190, 80);
      this->reset.Text = "Reset";
      this->reset.Enabled = false;
      this->reset.Click += EventHandler(*this, &Form1::OnResetClick);

      this->timer.Interval = 31;
      this->timer.Tick += EventHandler(*this, &Form1::OnTimerTick);

      this->Text = "Stopwatch";
      this->StartPosition = FormStartPosition::CenterScreen;
      this->ClientSize = System::Drawing::Size(275, 120);
      this->FormBorderStyle = FormBorderStyle::FixedSingle;
      this->MaximizeBox = false;
    }

  private:
    void OnStartStopClick(const object& sender, const EventArgs& e) {
      if (this->stopwatch.IsRunning)
        this->stopwatch.Stop();
      else
        this->stopwatch.Start();

      this->timer.Enabled = this->stopwatch.IsRunning;
      this->pauseResume.Enabled = this->timer.Enabled;
      this->startStop.Text = this->timer.Enabled ? "Stop" : "Start";
      this->reset.Enabled = !this->timer.Enabled || !this->stopwatch.IsRunning;
    }

    void OnPauseResumeClick(const object& sender, const EventArgs& e) {
      this->timer.Enabled = !this->timer.Enabled;
      this->pauseResume.Text = this->timer.Enabled ? "Pause" : "Resume";
      this->startStop.Enabled = this->timer.Enabled;
      this->reset.Enabled = !this->timer.Enabled || !this->stopwatch.IsRunning;
    }

    void OnResetClick(const object& sender, const EventArgs& e) {
      this->timer.Enabled = false;
      this->stopwatch.Reset();
      this->chrono.Text = "00:00:00.000";
      this->startStop.Enabled = true;
      this->pauseResume.Enabled = false;
      this->reset.Enabled = false;
      this->startStop.Text = "Start";
      this->pauseResume.Text = "Pause";
    }

    void OnTimerTick(const object& sender, const EventArgs& e) {
      TimeSpan ts = this->stopwatch.Elapsed;
      this->chrono.Text = String::Format("{0:D2}:{1:D2}:{2:D2}:{3:D3}", ts.Hours, ts.Minutes, ts.Seconds, ts.Milliseconds);
    }

    //MainMenu mainMenu;
    Stopwatch stopwatch;
    Label chrono;
    Button startStop;
    Button pauseResume;
    Button reset;
    Timer timer;
  };
}

startup_(Examples::Form1);
