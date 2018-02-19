#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/Windows/Forms/Application.hpp>
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

      TabPage tabPage1;
      tabPage1.Text = "tabPage1";

      TabPage tabPage2;
      tabPage2.Text = "tabPage2";

      TabControl tabControl;
      tabControl.Location = Point(10, 10);
      //tabControl.TabPages().AddRange({tabPage1, tabPage2});

      Form form;
      form.Text = "ManualTests";
      //form.Controls().Add(tabControl);
      form.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
