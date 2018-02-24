#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Program {
public:
  // The main entry point for the application.
  static void Main() {
    Application::EnableVisualStyles();

    System::Collections::Generic::List < $<Form >> forms;
    KnownColor formColor = KnownColor::AliceBlue;

    Button button;
    button.Text = "Create";
    button.Location = System::Drawing::Point(10, 10);
    button.Click += delegate_(const object & sender, const EventArgs & e) {
      $<Form> form = new_<Form>();
      form->BackColor = Color::FromKnownColor(formColor);
      form->Text = string::Format("{0}", formColor);
      form->Visible = true;
      forms.Add(form);
      formColor = formColor != KnownColor::YellowGreen ? (KnownColor)((int)formColor + 1) : KnownColor::AliceBlue;
    };

    Form mainForm;
    mainForm.Text = "Main Form";
    mainForm.StartPosition = FormStartPosition::Manual;
    mainForm.Location = System::Drawing::Point(Screen::AllScreens()[0].WorkingArea().Width - mainForm.Width, 0);
    mainForm.Controls().Add(button);
    mainForm.ShowDialog();
  }
};

startup_(Program);
