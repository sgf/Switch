#include <Switch/Switch.System.Windows.Forms.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Form1 : public Form {
  public:
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->label.Text = "Hello, World!";
      this->label.Location = Point {10, 10};
      this->label.BackColor = System::Drawing::Color::White;
      this->label.BorderStyle = BorderStyle::Fixed3D;
      this->label.ForeColor = System::Drawing::Color::Black;
      this->label.TextAlign = ContentAlignment::MiddleCenter;
      this->label.Height = 80;
      this->label.Width = 200;
      this->Cursor = Cursors::AppStarting;
      this->Text = "Manual Test application";
      this->StartPosition = FormStartPosition::CenterScreen;
      this->ClientSize = Drawing::Size {800, 100};
      //this->MaximizeBox = false;
      //this->MinimizeBox = false;
      //this->FormBorderStyle = FormBorderStyle::None;
      this->Controls().Add(this->label);
    }

  private:
    Label label;
  };
}

startup_(ManualTests::Form1);
