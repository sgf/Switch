#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace LabelExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->Text = "Label example";

      this->label1.Parent = *this;
      this->label1.Text = "https://gammasoft71.wixsite.com/gammasoft";
      this->label1.Location = System::Drawing::Point(10, 10);
      this->label1.Width = 260;

      this->label1.MouseEnter += delegate_(const object & sender, const EventArgs & e) {
        this->label1.ForeColor = System::Drawing::Color::Blue;
      };

      this->label1.Click += delegate_(const object & sender, const EventArgs & e) {
        MessageBox::Show(string::Format("The label \"{0}\" was clicked", this->label1.Text), "Message", MessageBoxButtons::OK);
      };

      this->label1.MouseLeave += delegate_(const object & sender, const EventArgs & e) {
        this->label1.ForeColor = System::Drawing::Color::Black;
      };
    }

  private:
    Label label1;
  };
}

startup_(LabelExample::Form1);
