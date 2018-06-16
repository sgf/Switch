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
      this->button.Text = "Close";
      this->button.Location = System::Drawing::Point(10, 10);
      this->button.Click += delegate_(const object & sender, const EventArgs & e) {
        this->Close();
      };

      this->Text = "Form example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->Size = System::Drawing::Size(640, 480);
      this->Controls().Add(this->button);
      this->FormClosing += delegate_(const object & sender, FormClosingEventArgs & e) {
        e.Cancel = MessageBox::Show("Are you sure you want exit?", "Close Form", MessageBoxButtons::YesNo, MessageBoxIcon::Question) ==  DialogResult::No;
      };
    }

  private:
    Button button;
  };
}

startup_(Examples::Form1);
