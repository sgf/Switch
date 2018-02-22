#include <Switch/System/Diagnostics/ConsoleTraceListener.hpp>
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/System/Windows/Forms/Screen.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      for (Screen screen : Screen::AllScreens()) {
        Debug::WriteLine(string::Format("DeviceName = {0}", screen.DeviceName));
        Debug::WriteLine(string::Format("  Bounds = {0}", screen.Bounds));
        Debug::WriteLine(string::Format("  WorkingArea = {0}", screen.WorkingArea));
        Debug::WriteLine(string::Format("  Primary = {0}", screen.Primary));
        Debug::WriteLine(string::Format("  BitsPerPixel = {0}", screen.BitsPerPixel));
      }

      Button button;
      button.Text = "Create";
      button.Location = System::Drawing::Point(10, 10);

      Form mainForm;
      mainForm.Text = "ManualTests";
      mainForm.Controls().Add(button);

      System::Collections::Generic::List < $<Form >> forms;
      int number = 1;
      button.Click += delegate_(const object & sender, const EventArgs & e) {
        $<Form> form = new_<Form>();
        form->Text = string::Format("Form {0}", number++);
        form->Visible = true;
        forms.Add(form);
      };

      mainForm.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
