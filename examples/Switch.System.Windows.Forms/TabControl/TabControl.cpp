#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace TabControlExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->tabPage3.Text = "tabPage3";

      this->tabControl1.Location = System::Drawing::Point(10, 10);
      this->tabControl1.Size = System::Drawing::Size(370, 250);
      this->tabControl1.TabPages().Add("tabPage1");
      this->tabControl1.TabPages().Add("tabPage2", "tabPage2");
      this->tabControl1.TabPages().Add(this->tabPage3);

      for (ref<TabPage> tabPage : this->tabControl1.TabPages())
        tabPage().UseVisualStyleBackColor = true;

      this->ClientSize = System::Drawing::Size(390, 270);
      this->Text = "TabControl example";
      this->Controls().Add(this->tabControl1);
    }

  private:
    TabControl tabControl1;
    TabPage tabPage3;
  };
}

startup_(TabControlExample::Form1);
