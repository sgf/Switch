#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/System/Windows/Forms/Screen.hpp>
#include <Switch/System/Windows/Forms/TabControl.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      Application::EnableVisualStyles();

     TabPage tabPage3;
      tabPage3.Text = "tabPage3";

      TabControl tabControl;
      tabControl.Location = Point(10, 10);
      tabControl.TabPages().Add("tabPage1");
      tabControl.TabPages().Add("tabPage2", "tabPage2");
      tabControl.TabPages().Add(tabPage3);

      for(ref<TabPage> tabPage : tabControl.TabPages())
        tabPage().UseVisualStyleBackColor = true;
      tabControl.TabPages()[0]().BackColor = Color::LightBlue;
      tabControl.TabPages()[1]().BackColor = Color::LightGreen;
      tabControl.TabPages()[2]().BackColor = Color::LightPink;

      Form mainForm;
      mainForm.Text = "Main Form";
      mainForm.Controls().Add(tabControl);
      mainForm.ShowDialog();
    }
  };
}

 startup_(ManualTests::Program);
