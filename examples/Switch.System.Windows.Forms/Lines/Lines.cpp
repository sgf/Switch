#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace PanelExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->lineSeparator.BorderStyle = BorderStyle::Fixed3D;
      this->lineSeparator.Bounds = System::Drawing::Rectangle(10, 10, 280, 2);

      this->lineRed.BackColor = System::Drawing::Color::Red;
      this->lineRed.Bounds = System::Drawing::Rectangle(10, 20, 1, 250);

      this->lineGreen.BackColor = System::Drawing::Color::Green;
      this->lineGreen.Bounds = System::Drawing::Rectangle(150, 20, 1, 250);

      this->lineBlue.BackColor = System::Drawing::Color::Blue;
      this->lineBlue.Bounds = System::Drawing::Rectangle(290, 20, 1, 250);

      this->lineSeparator2.BorderStyle = BorderStyle::FixedSingle;
      this->lineSeparator2.Bounds = System::Drawing::Rectangle(10, 280, 280, 1);

      this->ClientSize = System::Drawing::Size(300, 300);
      this->Text = "Lines example";
      this->Controls().AddRange({this->lineSeparator, this->lineRed, this->lineGreen, this->lineBlue, lineSeparator2});
    }

  private:
    Label lineSeparator;
    Label lineRed;
    Label lineGreen;
    Label lineBlue;
    Label lineSeparator2;
  };
}

startup_(PanelExample::Form1);
