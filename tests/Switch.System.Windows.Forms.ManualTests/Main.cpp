#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/CheckBox.hpp>
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

      CheckBox checkBox;
      checkBox.Location = System::Drawing::Point(10, 10);
      checkBox.Text = "Validate";
      checkBox.CheckState = CheckState::Indeterminate;

      GroupBox groupBox;
      groupBox.Location = System::Drawing::Point(10, 10);
      groupBox.Text = "GroupBox";
      groupBox.Controls().Add(checkBox);
      
      Form mainForm;
      mainForm.Controls().Add(groupBox);
      mainForm.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
