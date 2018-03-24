#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/ColorDialog.hpp>
#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/System/Windows/Forms/MessageBox.hpp>
#include <Switch/System/Windows/Forms/OpenFileDialog.hpp>
#include <Switch/System/Windows/Forms/SaveFileDialog.hpp>
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/Startup.hpp>

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
      this->buttonMessage.Text = "Message...";
      this->buttonMessage.Location = System::Drawing::Point(10, 10);
      this->buttonMessage.Click += delegate_(const object & sender, const EventArgs & e) {
        MessageBox::Show("This is an example on MessageBox.", "Demo message", MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation);
      };

      this->buttonColor.Text = "Color...";
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
      this->buttonOpen.Location = System::Drawing::Point(10, 90);
      this->buttonOpen.Click += delegate_(const object & sender, const EventArgs & e) {
        OpenFileDialog openFileDialog;
        openFileDialog.InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
        openFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
        System::Windows::Forms::DialogResult result = openFileDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK && !openFileDialog.Multiselect)
          System::Diagnostics::Debug::WriteLine(string::Format("File = {0}", openFileDialog.FileName));
        if (result == DialogResult::OK && openFileDialog.Multiselect)
          System::Diagnostics::Debug::WriteLine(string::Format("File = {0}", string::Join(Environment::NewLine, openFileDialog.FileNames)));
      };

      this->buttonSave.Text = "Save...";
      this->buttonSave.Location = System::Drawing::Point(10, 130);
      this->buttonSave.Click += delegate_(const object & sender, const EventArgs & e) {
        SaveFileDialog saveFileDialog;
        saveFileDialog.FileName = "Gammasoft.txt";
        saveFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
        System::Windows::Forms::DialogResult result = saveFileDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK)
          System::Diagnostics::Debug::WriteLine(string::Format("File = {0}", saveFileDialog.FileName));
      };

      this->Text = "Main Form";
      this->Controls().AddRange({buttonMessage, buttonColor, buttonOpen, buttonSave});
    }

  private:
    Button buttonMessage;
    Button buttonColor;
    Button buttonOpen;
    Button buttonSave;
  };
}

startup_(ManualTests::Form1);
