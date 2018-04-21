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
      this->radioButton1.Text = "radioButton1";
      this->radioButton1.Location = System::Drawing::Point(10, 10);

      this->radioButton2.Text = "radioButton2";
      this->radioButton2.Checked = true;
      this->radioButton2.Location = System::Drawing::Point(10, 40);

      this->control.Location = System::Drawing::Point(10, 70);
      this->control.Size = System::Drawing::Size(100, 30);
      this->control.Cursor = Cursors::Hand;

      this->tabPage1.Text = "page 1";
      this->tabPage1.Controls().AddRange({this->radioButton1, this->radioButton2, this->control});

      this->tabPage2.Text = "page 2";

      this->tabControl.Location = System::Drawing::Point(10, 10);
      this->tabControl.Size = System::Drawing::Size(280, 280);
      this->tabControl.TabPages().AddRange({this->tabPage1, this->tabPage2});

      this->Text = "Manual Test application";
      this->Controls().AddRange({this->tabControl});
      this->BackColor = System::Drawing::Color::LightBlue;
    }

  private:
    RadioButton radioButton1;
    RadioButton radioButton2;
    Control control;
    TabControl tabControl;
    TabPage tabPage1;
    TabPage tabPage2;
  };
}

startup_(ManualTests::Form1);
