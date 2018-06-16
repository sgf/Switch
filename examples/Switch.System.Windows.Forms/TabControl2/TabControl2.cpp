#include <Switch/Switch>

using namespace System;
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
      this->button1.Text = "button1";
      this->button1.Location = System::Drawing::Point(40, 20);

      this->label1.Text = "label1";
      this->label1.Location = System::Drawing::Point(100, 80);

      this->trackBar1.Value = 3;
      this->trackBar1.Location = System::Drawing::Point(10, 10);

      this->tabControl1.Location = System::Drawing::Point(10, 10);
      this->tabControl1.Size = System::Drawing::Size(370, 250);
      this->tabControl1.TabPages().Add("page1");
      this->tabControl1.TabPages().Add("page2");
      this->tabControl1.TabPages().Add("page3");
      this->tabControl1.TabPages().Add("page4");

      this->tabControl1.TabPages()[0]->Controls().Add(this->button1);
      this->tabControl1.TabPages()[1]->Controls().Add(this->label1);
      this->tabControl1.TabPages()[3]->Controls().Add(this->trackBar1);

      for (ref<TabPage> tabPage : this->tabControl1.TabPages())
        tabPage().UseVisualStyleBackColor = true;

      this->ClientSize = System::Drawing::Size(390, 270);
      this->Text = "TabControl example";
      this->Controls().Add(this->tabControl1);
    }

  private:
    Button button1;
    Label label1;
    TrackBar trackBar1;
    TabControl tabControl1;
  };
}

startup_(Examples::Form1);
