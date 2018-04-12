#include <Switch/Switch.System.Windows.Forms.hpp>

using namespace System;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Form1 : public Form {
  public:
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      System::Diagnostics::Debug::WriteLine(string::Format("DefaultFont = {0}", Control::DefaultFont));
      this->buttonMessage.Text = "Message...";
      this->buttonMessage.Width = 110;
      this->buttonMessage.Location = System::Drawing::Point(10, 10);
      this->buttonMessage.Click += delegate_(const object & sender, const EventArgs & e) {
        MessageBox::Show("This is an example on MessageBox.", "Demo message", MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation);
      };

      this->buttonColor.Text = "Color...";
      this->buttonColor.Width = 110;
      this->buttonColor.Location = System::Drawing::Point(10, 50);
      this->buttonColor.Click += delegate_(const object & sender, const EventArgs & e) {
        ColorDialog colorDialog;
        colorDialog.Color = this->BackColor;
        System::Windows::Forms::DialogResult result = colorDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK)
          this->BackColor = colorDialog.Color;
      };

      this->buttonOpen.Text = "Open...";
      this->buttonOpen.Width = 110;
      this->buttonOpen.Location = System::Drawing::Point(10, 90);
      this->buttonOpen.Click += delegate_(const object & sender, const EventArgs & e) {
        OpenFileDialog openFileDialog;
        openFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
        openFileDialog.InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
        openFileDialog.Multiselect = true;
        System::Windows::Forms::DialogResult result = openFileDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK) {
          System::Diagnostics::Debug::WriteLine(string::Format("File = {0}", openFileDialog.FileName));
          System::Diagnostics::Debug::WriteLine(string::Format("Files = {0}", string::Join(Environment::NewLine, openFileDialog.FileNames)));
        }
      };

      this->buttonSave.Text = "Save...";
      this->buttonSave.Width = 110;
      this->buttonSave.Location = System::Drawing::Point(10, 130);
      this->buttonSave.Click += delegate_(const object & sender, const EventArgs & e) {
        SaveFileDialog saveFileDialog;
        saveFileDialog.FileName = "Gammasoft.txt";
        saveFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
        saveFileDialog.InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
        System::Windows::Forms::DialogResult result = saveFileDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK)
          System::Diagnostics::Debug::WriteLine(string::Format("File = {0}", saveFileDialog.FileName));
      };

      this->buttonFolder.Text = "Folder...";
      this->buttonFolder.Width = 110;
      this->buttonFolder.Location = System::Drawing::Point(10, 170);
      this->buttonFolder.Click += delegate_(const object & sender, const EventArgs & e) {
        FolderBrowserDialog folderBrowserDialog;
        folderBrowserDialog.RootFolder = Environment::SpecialFolder::Desktop;
        folderBrowserDialog.ShowHiddenFolders = true;
        System::Windows::Forms::DialogResult result = folderBrowserDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK)
          System::Diagnostics::Debug::WriteLine(string::Format("Path = {0}", folderBrowserDialog.SelectedPath));
      };

      this->buttonFont.Text = "Font...";
      this->buttonFont.Width = 110;
      this->buttonFont.Location = System::Drawing::Point(10, 210);
      this->buttonFont.Click += delegate_(const object & sender, const EventArgs & e) {
        FontDialog fontDialog;
        System::Windows::Forms::DialogResult result = fontDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK) {
          System::Diagnostics::Debug::WriteLine(string::Format("Font = {0}", fontDialog.Font));
          System::Diagnostics::Debug::WriteLine(string::Format("Color = {0}", fontDialog.Color));
        }
      };

      this->Text = "Dialogs";
      this->Controls().AddRange({this->buttonMessage, this->buttonColor, this->buttonOpen, this->buttonSave, this->buttonFolder, this->buttonFont});
    }

  private:
    Button buttonMessage;
    Button buttonColor;
    Button buttonOpen;
    Button buttonSave;
    Button buttonFolder;
    Button buttonFont;
  };
}

startup_(ManualTests::Form1);
