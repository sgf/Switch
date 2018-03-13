#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Windows::Forms;

class Form1 : public Form {
private:
  RadioButton radioButton1;
  RadioButton radioButton2;

public:
  Form1() {
    InitializeComponent();
  }

  static void Main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(Form1());
  }

private:
  void InitializeComponent() {
    this->SuspendLayout();
    //
    // radioButton1
    //
    this->radioButton1.Location = System::Drawing::Point(0, 0);
    this->radioButton1.Name = "radioButton1";
    this->radioButton1.Size = System::Drawing::Size(100, 17);    //this->radioButton1.TabIndex = 0;
    this->radioButton1.TabStop = true;
    this->radioButton1.Text = "Button1";
    this->radioButton1.EnabledChanged += {*this, &Form1::radioButton1_EnabledChanged};
    //
    // radioButton2
    //
    this->radioButton2.Location = System::Drawing::Point(0, 39);
    this->radioButton2.Name = "radioButton2";
    this->radioButton2.Size = System::Drawing::Size(150, 17);
    this->radioButton2.TabStop = true;
    this->radioButton2.Text = "Disable Button1";
    this->radioButton2.CheckedChanged += {*this, &Form1::radioButton2_CheckedChanged};
    //
    // Form1
    //
    this->ClientSize = System::Drawing::Size(292, 273);
    this->Controls().Add(this->radioButton2);
    this->Controls().Add(this->radioButton1);
    this->Name = "Form1";
    this->ResumeLayout(false);
    this->PerformLayout();
  }

  void radioButton2_CheckedChanged(const object& sender, const EventArgs& e) {
    radioButton1.Enabled = false;
  }

  void radioButton1_EnabledChanged(const object& sender, const EventArgs& e) {
    MessageBox::Show("This button has been disabled.");
  }
};

startup_(Form1);
