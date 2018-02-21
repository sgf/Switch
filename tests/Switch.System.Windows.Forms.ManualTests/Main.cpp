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
