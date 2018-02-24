#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/Button.hpp>
#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/System/Windows/Forms/Screen.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      Application::EnableVisualStyles();

      Form mainForm;
      mainForm.Text = "Main Form";
      mainForm.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
