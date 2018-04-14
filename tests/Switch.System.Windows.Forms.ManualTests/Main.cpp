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
      this->button.Text = "Click";
      this->button.Location = System::Drawing::Point(10, 10);
      this->button.Click += delegate_(const object & sender, const EventArgs & e) {
        System::Windows::Forms::Cursor::Position = System::Drawing::Point(20, 20);
      };

      this->panel.Location = System::Drawing::Point(10, 50);
      this->panel.BackColor = System::Drawing::Color::White;
      this->panel.BorderStyle = BorderStyle::Fixed3D;
      this->panel.Cursor = Cursors::AppStarting;

      this->Controls().AddRange({this->button, this->panel});
    }

  private:
    Button button;
    Panel panel;
  };
}

startup_(ManualTests::Form1);
