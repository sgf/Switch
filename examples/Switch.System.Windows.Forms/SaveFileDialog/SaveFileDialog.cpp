#include <Switch/Switch>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace Examples {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->button.Text = "Save...";
      this->button.Location = System::Drawing::Point(10, 10);
      this->button.Click += delegate_(const object & sender, const EventArgs & e) {
        SaveFileDialog saveFileDialog;
        saveFileDialog.InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
        saveFileDialog.FileName = "MyFile.txt";
        saveFileDialog.Filter = "Text Files (*.txt)|*.txt;*.md|All Files (*.*)|*.*";
        if (saveFileDialog.ShowDialog() == DialogResult::OK)
          this->label.Text = string::Format("File = {0}", saveFileDialog.FileName);
      };

      this->label.Text = "File = ";
      this->label.Location = System::Drawing::Point(10, 40);
      this->label.Width = 340;

      this->Text = "SaveFileDialog example";
      this->Controls().AddRange({this->button, this->label});
    }

  private:
    Button button;
    Label label;
  };
}

startup_(Examples::Form1);
