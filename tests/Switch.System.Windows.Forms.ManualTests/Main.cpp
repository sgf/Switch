#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/ColorDialog.hpp>
#include <Switch/System/Windows/Forms/OpenFileDialog.hpp>
#include <Switch/System/Windows/Forms/SaveFileDialog.hpp>
#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/System/Windows/Forms/Screen.hpp>
#include <Switch/System/Windows/Forms/TabControl.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      Application::EnableVisualStyles();

      Button buttonColor;
      buttonColor.Text = "Color...";
      buttonColor.Location = Point(10, 10);
      buttonColor.Click += delegate_(const object & sender, const EventArgs & e) {
        ColorDialog colorDialog;
        DialogResult result = colorDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK)
          System::Diagnostics::Debug::WriteLine(string::Format("Color = {0}", colorDialog.Color));
      };

      Button buttonOpen;
      buttonOpen.Text = "Open...";
      buttonOpen.Location = Point(10, 50);
      buttonOpen.Click += delegate_(const object & sender, const EventArgs & e) {
        OpenFileDialog openFileDialog;
        openFileDialog.InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
        openFileDialog.Multiselect = true;
        openFileDialog.ShowHiddenFiles = true;
        DialogResult result = openFileDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK && !openFileDialog.Multiselect)
          System::Diagnostics::Debug::WriteLine(string::Format("File = {0}", openFileDialog.FileName));
        if (result == DialogResult::OK && openFileDialog.Multiselect)
          System::Diagnostics::Debug::WriteLine(string::Format("File = {0}", string::Join(Environment::NewLine, openFileDialog.FileNames)));
      };

      Button buttonSave;
      buttonSave.Text = "Save...";
      buttonSave.Location = Point(10, 90);
      buttonSave.Click += delegate_(const object & sender, const EventArgs & e) {
        SaveFileDialog saveFileDialog;
        saveFileDialog.FileName = "Gammasoft.txt";
        DialogResult result = saveFileDialog.ShowDialog();
        System::Diagnostics::Debug::WriteLine(string::Format("result = {0}", result));
        if (result == DialogResult::OK)
          System::Diagnostics::Debug::WriteLine(string::Format("File = {0}", saveFileDialog.FileName));
      };

      Form mainForm;
      mainForm.Text = "Main Form";
      mainForm.Controls().AddRange({buttonColor, buttonOpen, buttonSave});
      mainForm.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
