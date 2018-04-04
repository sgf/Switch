#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace ColorDialogExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->label.Text = string::Format("The quick brown fox jumps over the lazy dog.\n"
          "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
          "0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
          "àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
          "{u0400}{u0401}{u0402}{u0403}{u0404}{u0405}{u0406}{u0407}{u0408}{u0409}{u040a}{u040b}{u040c}{u040d}{u040e}{u040f}\n"
          "{u0410}{u0411}{u0412}{u0413}{u0414}{u0415}{u0416}{u0417}{u0418}{u0419}{u041a}{u041b}{u041c}{u041d}{u041e}{u041f}\n"
          "{u4ea0}{u4ea1}{u4ea2}{u4ea3}{u4ea4}{u4ea5}{u4ea6}{u4ea7}{u4ea8}{u4ea9}{u4eaa}{u4eab}{u4eac}{u4ead}{u4eae}{u4eaf}\n"
          "{u4eb0}{u4eb1}{u4eb2}{u4eb3}{u4eb4}{u4eb5}{u4eb6}{u4eb7}{u4eb8}{u4eb9}{u4eba}{u4ebb}{u4ebc}{u4ebd}{u4ebe}{u4ebf}\n"
          "{U0001F428}");
      this->label.Location = System::Drawing::Point(10, 50);
      this->label.Size = System::Drawing::Size(380, 340);

      this->button.Text = "Font...";
      this->button.Location = System::Drawing::Point(10, 10);

      this->button.Click += delegate_(const object & sender, const EventArgs & e) {
        FontDialog fontDialog;
        fontDialog.ShowColor = true;
        fontDialog.Font = this->label.Font;
        fontDialog.Color = this->label.ForeColor;
        if (fontDialog.ShowDialog() == DialogResult::OK) {
          this->label.Font = fontDialog.Font;
          this->label.ForeColor = fontDialog.Color;
        }
      };

      this->Text = "Font Example";
      this->ClientSize = System::Drawing::Size(400, 400);
      this->Controls().AddRange({this->button, this->label});
    }

  private:
    Button button;
    Label label;
  };
}

startup_(ColorDialogExample::Form1);
