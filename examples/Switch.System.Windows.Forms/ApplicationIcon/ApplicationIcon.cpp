#include <Switch/Switch>

namespace Examples {
  class Form1 : public System::Windows::Forms::Form {
  public:
    static void Main() {
      System::Windows::Forms::Application::Run(Form1());
    }

    Form1() {
      this->Text = "Form1";
      this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    }
  };
}

startup_(Examples::Form1);
