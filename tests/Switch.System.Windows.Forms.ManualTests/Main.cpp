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
      this->label1.Text = "label1";
      this->label1.BorderStyle = BorderStyle::Fixed3D;
      this->label1.Location = System::Drawing::Point(10, 10);
      this->label1.ForeColor = System::Drawing::Color::Red;

      this->greenLine.BackColor = System::Drawing::Color::Green;
      this->greenLine.Location = System::Drawing::Point(10, 30);
      this->greenLine.Size = System::Drawing::Size(240, 2);

      this->button1.Text = "button1";
      this->button1.Location = System::Drawing::Point(10, 40);

      this->button2.Text = "button2";
      this->button2.Location = System::Drawing::Point(10, 70);
      this->button2.Enabled = false;

      this->checkBox1.Text = "checkBox1";
      this->checkBox1.Location = System::Drawing::Point(10, 100);
      this->checkBox1.CheckState = CheckState::Indeterminate;

      this->checkBox2.Text = "checkBox2";
      this->checkBox2.Location = System::Drawing::Point(10, 130);
      this->checkBox2.Checked = true;
      this->checkBox2.Enabled = false;

      this->trackBar1.Location = System::Drawing::Point(10, 160);
      this->trackBar1.Value = 5;

      this->radioButton1.Text = "radioButton1";
      this->radioButton1.Location = System::Drawing::Point(10, 10);

      this->radioButton2.Text = "radioButton2";
      this->radioButton2.Checked = true;
      this->radioButton2.Location = System::Drawing::Point(10, 40);

      this->radioButton3.Text = "radioButton3";
      this->radioButton3.Enabled = false;
      this->radioButton3.Location = System::Drawing::Point(10, 70);

      this->progressBar1.Location = System::Drawing::Point(10, 10);

      this->progressBar2.Location = System::Drawing::Point(10, 40);
      this->progressBar2.Value = 50;

      this->progressBar3.Location = System::Drawing::Point(10, 70);
      this->progressBar3.Style = ProgressBarStyle::Marquee;

      this->tabPage1.Text = "tabPage1";
      this->tabPage1.Controls().AddRange({this->label1, this->greenLine, this->button1, this->button2, this->checkBox1, this->checkBox2, this->trackBar1});

      this->tabPage2.Text = "tabPage2";
      this->tabPage2.Controls().AddRange({this->radioButton1, this->radioButton2, this->radioButton3});

      this->tabPage3.Text = "tabPage3";
      this->tabPage3.Controls().AddRange({this->progressBar1, this->progressBar2, this->progressBar3});

      this->tabControl1.Location = System::Drawing::Point(10, 10);
      this->tabControl1.Size = System::Drawing::Size(280, 280);
      this->tabControl1.TabPages().AddRange({this->tabPage1, this->tabPage2, this->tabPage3});

      this->Text = "Manual Test application";
      this->Controls().AddRange({this->tabControl1});
    }

  private:
    Label label1;
    Panel greenLine;
    Button button1;
    Button button2;
    CheckBox checkBox1;
    CheckBox checkBox2;
    TrackBar trackBar1;
    RadioButton radioButton1;
    RadioButton radioButton2;
    RadioButton radioButton3;
    ProgressBar progressBar1;
    ProgressBar progressBar2;
    ProgressBar progressBar3;
    TabControl tabControl1;
    TabPage tabPage1;
    TabPage tabPage2;
    TabPage tabPage3;
  };
}

startup_(ManualTests::Form1);
