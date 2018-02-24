#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/RadioButton.hpp>
#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/System/Windows/Forms/GroupBox.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      Application::EnableVisualStyles();

      RadioButton radioButton1;
      radioButton1.Location = System::Drawing::Point(10, 30);
      radioButton1.Text = "Radio 1";

      RadioButton radioButton2;
      radioButton2.Location = System::Drawing::Point(10, 60);
      radioButton2.Text = "Radio 2";
      radioButton2.Checked = true;

      RadioButton radioButton3;
      radioButton3.Location = System::Drawing::Point(10, 90);
      radioButton3.Text = "Radio 3";

      GroupBox groupBox;
      groupBox.Location = System::Drawing::Point(10, 10);
      groupBox.Text = "GroupBox";
      groupBox.Width = 120;
      groupBox.Height = 120;
      groupBox.Controls().AddRange({radioButton1, radioButton2, radioButton3});

      Form mainForm;
      mainForm.BackColor = System::Drawing::Color::LightGreen;
      mainForm.Controls().Add(groupBox);
      mainForm.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
