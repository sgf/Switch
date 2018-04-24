#include <Switch/Switch.System.Windows.Forms.hpp>

using namespace System;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Form1 : public Form {
  public:
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->Text = "Manual Test application";
      this->StartPosition = FormStartPosition::CenterScreen;
      this->ClientSize = Drawing::Size {800, 100};
      //this->MaximizeBox = false;
      //this->MinimizeBox = false;
      this->FormBorderStyle = FormBorderStyle::None;
    }

  private:
  };
}

startup_(ManualTests::Form1);
