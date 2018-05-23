#include <Switch/Switch.System.Windows.Forms.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

int main(int argc, char* argv[]) {
  Environment::SetCommandLineArgs(argv, argc);
  Application::EnableVisualStyles();

  Label label1;
  label1.Location = Point {10, 10};
  label1.BackColor = System::Drawing::Color::White;
  label1.BorderStyle = BorderStyle::Fixed3D;
  label1.ForeColor = System::Drawing::Color::Black;
  label1.Name = "label1";
  label1.Text = "Hello, World!";
  label1.TextAlign = ContentAlignment::MiddleCenter;
  label1.Height = 80;
  label1.Width = 200;
  
  Form form1;
  form1.ClientSize = Drawing::Size {800, 100};
  form1.Controls().Add(label1);
  form1.Name = "form1";
  form1.StartPosition = FormStartPosition::CenterScreen;
  form1.Text = "ManualTests application";

  Application::Run(form1);
}
