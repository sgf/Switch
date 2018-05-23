#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace ColoredTabPagesExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->tabPageRed.Text = "Red";
      this->tabPageRed.BackColor = System::Drawing::Color::Red;
      
      this->tabPageGreen.Text = "Green";
      this->tabPageGreen.BackColor = System::Drawing::Color::Green;
      
      this->tabPageBlue.Text = "Blue";
      this->tabPageBlue.BackColor = System::Drawing::Color::Blue;
      
      this->tabPageYellow.Text = "Yellow";
      this->tabPageYellow.BackColor = System::Drawing::Color::Yellow;
      
      this->tabControl1.Location = System::Drawing::Point(10, 10);
      this->tabControl1.Size = System::Drawing::Size(370, 250);
      this->tabControl1.TabPages().AddRange({this->tabPageRed, this->tabPageGreen, this->tabPageBlue, this->tabPageYellow});

      this->ClientSize = System::Drawing::Size(390, 270);
      this->Text = "Colored TabPages example";
      this->Controls().Add(this->tabControl1);
    }

  private:
    TabControl tabControl1;
    TabPage tabPageRed;
    TabPage tabPageGreen;
    TabPage tabPageBlue;
    TabPage tabPageYellow;
  };
}

startup_(ColoredTabPagesExample::Form1);
