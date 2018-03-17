#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace FormExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->button.Text = "colors";
      this->button.Location = System::Drawing::Point(10, 10);
      this->button.Click += delegate_(const object & sender, const EventArgs & e) {
        ColorDialog colorDialog;
        colorDialog.Color = this->BackColor;
        if (colorDialog.ShowDialog() == DialogResult::OK)
          this->BackColor = colorDialog.Color;
      };

      this->Text = "ColorDialog example";
      this->Controls().Add(this->button);
    }

  private:
    Button button;
  };
}

startup_(FormExample::Form1);
