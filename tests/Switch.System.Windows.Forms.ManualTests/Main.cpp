#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      Form mainForm;
<<<<<<< HEAD
=======
      mainForm.Text = "ManualTests";
      mainForm.StartPosition = FormStartPosition::Manual;
      mainForm.Location = System::Drawing::Point(600, 0);
      mainForm.Controls().Add(button);

      System::Collections::Generic::List < $<Form >> forms;
      int number = 1;
      button.Click += delegate_(const object & sender, const EventArgs & e) {
        $<Form> form = new_<Form>();
        form->Text = string::Format("Form {0}", number++);
        form->StartPosition = FormStartPosition::WindowsDefaultBounds;
        form->Visible = true;
        forms.Add(form);
      };

>>>>>>> 2ed3364bb627edf4ab72f91f35f273b8da659650
      mainForm.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
