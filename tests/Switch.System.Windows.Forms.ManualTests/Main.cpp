#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      Button button;
      button.Text = "Close";
      button.Location = System::Drawing::Point(10, 10);
      button.Click += delegate_(const object & sender, const EventArgs & e) {
        Application::Exit();
      };

      Form form;
      form.Text = "ManualTests";
      form.Controls().Add(button);
      form.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
