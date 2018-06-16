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
      this->button.Text = "Folder...";
      this->button.Location = System::Drawing::Point(10, 10);
      this->button.Click += delegate_(const object & sender, const EventArgs & e) {
        FolderBrowserDialog folderBrowserDialog;
        folderBrowserDialog.SelectedPath = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
        if (folderBrowserDialog.ShowDialog() == DialogResult::OK)
          this->label.Text = string::Format("Path = {0}", folderBrowserDialog.SelectedPath);
      };

      this->label.Text = "Path = ";
      this->label.Location = System::Drawing::Point(10, 40);
      this->label.Width = 340;

      this->Text = "FolderBrowserDialog example";
      this->Controls().AddRange({this->button, this->label});
    }

  private:
    Button button;
    Label label;
  };
}

startup_(Examples::Form1);
