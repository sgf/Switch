#include <Switch/Switch>

using namespace System::Windows::Forms;

namespace VStyles {
  class Form1 : public System::Windows::Forms::Form {
  private:
    System::Windows::Forms::Button button1;

  public:
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->button1.Location = System::Drawing::Point(24, 16);
      this->button1.Size = System::Drawing::Size(120, 100);
      this->button1.Text = "I am themed.";

      // Sets up how the form should be displayed and adds the controls to the form.
      this->ClientSize = System::Drawing::Size(300, 286);
      this->Controls().Add(this->button1);

      this->Text = "Application.EnableVisualStyles Example";
    }
  };
}

startup_(VStyles::Form1);
