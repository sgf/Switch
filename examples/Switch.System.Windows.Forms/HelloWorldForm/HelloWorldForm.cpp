#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace Examples {
  class MainForm : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(MainForm());
    }

    MainForm() {
      this->label.Text = "Hello, World!";
      this->label.Font = System::Drawing::Font("Arial", 34, System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic);
      this->label.ForeColor = System::Drawing::Color::Green;
      this->label.Location = System::Drawing::Point(5, 100);
      this->label.Size = System::Drawing::Size(290, 100);

      this->Text = "My first application";
      this->StartPosition = FormStartPosition::CenterScreen;
      this->ClientSize = System::Drawing::Size(300, 300);
      this->Controls().Add(this->label);
    }

  private:
    Label label;
  };
}

startup_(Examples::MainForm);
