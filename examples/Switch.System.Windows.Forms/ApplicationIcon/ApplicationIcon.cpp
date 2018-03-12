#include <Switch/Switch>

namespace Program {
  class Form1 : public System::Windows::Forms::Form {
  public:
    Form1() {
      this->Text = "Form1";
    }

    static void Main() {
      System::Windows::Forms::Application::Run(Form1());
    }
  };
}

startup_(Program::Form1);
