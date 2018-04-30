#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace Examples {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::Run(Form1());
    }

    Form1() {
      Application::Idle += EventHandler(*this, &Form1::OnApplicationIdle);
    }

    void OnApplicationIdle(const object& sender, const EventArgs& e) {
      static int counter = 0;
      this->Text = string::Format("{0}", ++counter);
    }
  };
}

startup_(Examples::Form1);
