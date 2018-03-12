#include <Switch/Switch>

using namespace System::Windows::Forms;

class MainForm : public Form {
public:
  MainForm() {
    this->Text = "Icon";
    this->Size = System::Drawing::Size(250, 200);
    //this->Icon = System::Drawing::Icon("Switch.ico");
    this->StartPosition = FormStartPosition::CenterScreen;
  }

  static void Main() {
    Application::Run(MainForm());
  }
};

startup_(MainForm);
