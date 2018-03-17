#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/ColorDialog.hpp>
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

      Button button;
      button.Text = "button";
      button.Location = Point(10, 10);
      button.Click += delegate_(const object & sender, const EventArgs & e) {
        ColorDialog colorDialog;
        colorDialog.Color = System::Drawing::Color::Green;
        System::Diagnostics::Debug::WriteLine(string::Format("Result = {0}", colorDialog.ShowDialog()));
        System::Diagnostics::Debug::WriteLine(string::Format("Color = {0}", colorDialog.Color));
      };

      Form mainForm;
      mainForm.Text = "Main Form";
      mainForm.Controls().Add(button);
      mainForm.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
