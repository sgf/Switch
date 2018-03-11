#include <Switch/Switch>

using namespace System::Windows::Forms;

class Simple : public Form {
public:
  Simple() {
    this->Text = "Simple";
    this->Size = System::Drawing::Size(250, 200);
    this->CenterToScreen();
  }
  
  static void Main() {
    Application::Run(Simple());
  }
};

startup_(Simple);
