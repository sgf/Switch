#include <Switch/Switch.System.Windows.Forms.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

int main(int argc, char* argv[]) {
  Environment::SetCommandLineArgs(argv, argc);
  Application::EnableVisualStyles();

  Button button1;
  //button1.BackColor = Color::Green;
  button1.Text = "Click";
  button1.Height = 60;

  Form form1;
  form1.BackColor = Color::YellowGreen;
  form1.ClientSize = Drawing::Size {390, 270};
  form1.Controls().Add(button1);
  form1.Name = "form1";
  form1.StartPosition = FormStartPosition::CenterScreen;
  form1.Text = "ManualTests application";

  Application::Run(form1);
}
