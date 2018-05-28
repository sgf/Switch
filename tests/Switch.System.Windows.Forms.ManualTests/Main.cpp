#include <Switch/Switch.System.Windows.Forms.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

int main(int argc, char* argv[]) {
  Environment::SetCommandLineArgs(argv, argc);
  Application::EnableVisualStyles();

  CheckBox checkBox1;
  checkBox1.BackColor = Color::Green;
  checkBox1.Text = "checkBox";
  //checkBox1.Height = 18;

  Form form1;
  //form1.BackColor = Color::YellowGreen;
  form1.ClientSize = Drawing::Size {390, 270};
  form1.Controls().Add(checkBox1);
  form1.Name = "form1";
  form1.StartPosition = FormStartPosition::CenterScreen;
  form1.Text = "ManualTests application";

  Application::Run(form1);
}
