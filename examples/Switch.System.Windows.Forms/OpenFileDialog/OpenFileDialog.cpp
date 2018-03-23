#include <Switch/Switch>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace OpenFileDialogExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->button.Text = "Open...";
      this->button.Location = System::Drawing::Point(10, 10);
      this->button.Click += delegate_(const object & sender, const EventArgs & e) {
        OpenFileDialog openFileDialog;
        openFileDialog.Title = "My open file";
        openFileDialog.InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
        openFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
        if (openFileDialog.ShowDialog() == DialogResult::OK)
          this->label.Text = string::Format("File = {0}", openFileDialog.FileName);
      };

      this->label.Text = "File = ";
      this->label.Location = System::Drawing::Point(10, 40);
      this->label.Width = 340;

      this->Text = "OpenFileDialog example";
      this->Controls().AddRange({this->button, this->label});
    }

  private:
    Button button;
    Label label;
  };
}

startup_(OpenFileDialogExample::Form1);
