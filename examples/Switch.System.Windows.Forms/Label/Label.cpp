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

      this->label1.Text = "label1";
      this->label1.Location = System::Drawing::Point(10, 10);
      this->label1.Parent = *this;
    }

  private:
    Label label1;
  };
}

startup_(LabelExample::Form1);
