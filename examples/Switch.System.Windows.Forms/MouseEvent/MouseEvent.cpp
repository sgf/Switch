#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Examples {
  class Form1 : public System::Windows::Forms::Form {
  private:
    System::Windows::Forms::Panel panel1;
    System::Windows::Forms::Label label1;
    System::Windows::Forms::Label label2;
    System::Windows::Forms::Label label3;
    System::Windows::Forms::Label label4;
    System::Windows::Forms::Label label5;
    System::Windows::Forms::Label label6;
    System::Windows::Forms::Label label7;
    System::Windows::Forms::Label label8;
    System::Windows::Forms::Label label9;
    System::Windows::Forms::Button clearButton;
    //System::Drawing::Drawing2D::GraphicsPath mousePath;
    System::Windows::Forms::GroupBox groupBox1;

    int fontSize = 20;

  public:
    static void Main() {
      Application::Run(Form1());
    }

    Form1() {
      // Mouse Events Label
      this->label1.Location = System::Drawing::Point(24, 504);
      this->label1.Size = System::Drawing::Size(392, 23);
      // DoubleClickSize Label
      this->label2.AutoSize = true;
      this->label2.Location = System::Drawing::Point(24, 48);
      this->label2.Size = System::Drawing::Size(35, 13);
      // DoubleClickTime Label
      this->label3.AutoSize = true;
      this->label3.Location = System::Drawing::Point(24, 72);
      this->label3.Size = System::Drawing::Size(35, 13);
      // MousePresent Label
      this->label4.AutoSize = true;
      this->label4.Location = System::Drawing::Point(24, 96);
      this->label4.Size = System::Drawing::Size(35, 13);
      // MouseButtons Label
      this->label5.AutoSize = true;
      this->label5.Location = System::Drawing::Point(24, 120);
      this->label5.Size = System::Drawing::Size(35, 13);
      // MouseButtonsSwapped Label
      //this->label6.AutoSize = true;
      this->label6.Location = System::Drawing::Point(320, 48);
      this->label6.Size = System::Drawing::Size(35, 13);
      // MouseWheelPresent Label
      this->label7.AutoSize = true;
      this->label7.Location = System::Drawing::Point(320, 72);
      this->label7.Size = System::Drawing::Size(35, 13);
      // MouseWheelScrollLines Label
      this->label8.AutoSize = true;
      this->label8.Location = System::Drawing::Point(320, 96);
      this->label8.Size = System::Drawing::Size(35, 13);
      // NativeMouseWheelSupport Label
      this->label9.AutoSize = true;
      this->label9.Location = System::Drawing::Point(320, 120);
      this->label9.Size = System::Drawing::Size(35, 13);

      // Mouse Panel
      //this->panel1.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right;
      this->panel1.BackColor = System::Drawing::SystemColors::ControlDark;
      this->panel1.Location = System::Drawing::Point(16, 160);
      this->panel1.Size = System::Drawing::Size(664, 320);
      this->panel1.MouseUp += System::Windows::Forms::MouseEventHandler(*this, &Form1::panel1_MouseUp);
      this->panel1.Paint += System::Windows::Forms::PaintEventHandler(*this, &Form1::panel1_Paint);
      this->panel1.MouseEnter += System::EventHandler(*this, &Form1::panel1_MouseEnter);
      this->panel1.MouseHover += System::EventHandler(*this, &Form1::panel1_MouseHover);
      this->panel1.MouseMove += System::Windows::Forms::MouseEventHandler(*this, &Form1::panel1_MouseMove);
      this->panel1.MouseLeave += System::EventHandler(*this, &Form1::panel1_MouseLeave);
      this->panel1.MouseDown += System::Windows::Forms::MouseEventHandler(*this, &Form1::panel1_MouseDown);
      this->panel1.MouseWheel += System::Windows::Forms::MouseEventHandler(*this, &Form1::panel1_MouseWheel);

      // Clear Button
      this->clearButton.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
      this->clearButton.Location = System::Drawing::Point(592, 504);
      this->clearButton.TabIndex = 1;
      this->clearButton.Text = "Clear";
      this->clearButton.Click += System::EventHandler(*this, &Form1::clearButton_Click);

      // GroupBox
      this->groupBox1.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right;
      this->groupBox1.Location = System::Drawing::Point(16, 24);
      this->groupBox1.Size = System::Drawing::Size(664, 128);
      this->groupBox1.Text = "System::Windows::Forms::SystemInformation";

      // Set up how the form should be displayed and add the controls to the form.
      this->ClientSize = System::Drawing::Size(696, 534);
      this->Controls().AddRange(Array<ref<System::Windows::Forms::Control>> {
        this->label9, this->label8, this->label7, this->label6,
        this->label5, this->label4, this->label3, this->label2,
        this->clearButton, this->panel1, this->label1, this->groupBox1
      });
      this->Text = "Mouse Event Example";

      // Displays information about the system mouse.
      label2.Text = "SystemInformation::DoubleClickSize: "_s + SystemInformation::DoubleClickSize().ToString();
      label3.Text = "SystemInformation::DoubleClickTime: "_s + Int32(SystemInformation::DoubleClickTime).ToString();
      label4.Text = "SystemInformation::MousePresent: "_s + Boolean(SystemInformation::MousePresent).ToString();
      label5.Text = "SystemInformation::MouseButtons: "_s + Int32(SystemInformation::MouseButtons).ToString();
      label6.Text = "SystemInformation::MouseButtonsSwapped: "_s + Boolean(SystemInformation::MouseButtonsSwapped).ToString();
      label7.Text = "SystemInformation::MouseWheelPresent: "_s + Boolean(SystemInformation::MouseWheelPresent).ToString();
      label8.Text = "SystemInformation::MouseWheelScrollLines: "_s + Int32(SystemInformation::MouseWheelScrollLines).ToString();
      label9.Text = "SystemInformation::NativeMouseWheelSupport: "_s + Boolean(SystemInformation::NativeMouseWheelSupport).ToString();

    }

  private:
    void panel1_MouseDown(const object& sender, const System::Windows::Forms::MouseEventArgs& e) {
      // Update the mouse path with the mouse information
      Point mouseDownLocation(e.X, e.Y);

      string eventString;
      switch (e.Button) {
      case MouseButtons::Left:
        eventString = "L";
        break;
      case MouseButtons::Right:
        eventString = "R";
        break;
      case MouseButtons::Middle:
        eventString = "M";
        break;
      case MouseButtons::XButton1:
        eventString = "X1";
        break;
      case MouseButtons::XButton2:
        eventString = "X2";
        break;
      case MouseButtons::None:
      default:
        break;
      }

      if (!string::IsNullOrEmpty(eventString))
        mousePath.AddString(eventString, FontFamily::GenericSerif, (int)FontStyle::Bold, fontSize, mouseDownLocation, StringFormat::GenericDefault);
      else
        mousePath.AddLine(mouseDownLocation, mouseDownLocation);
      panel1.Focus();
      panel1.Invalidate();
    }

    void panel1_MouseEnter(const object& sender, const System::EventArgs& e) {
      // Update the mouse event label to indicate the MouseEnter event occurred.
      label1.Text = sender.GetType().ToString() + ": MouseEnter";
    }

    void panel1_MouseHover(const object& sender, const System::EventArgs& e) {
      // Update the mouse event label to indicate the MouseHover event occurred.
      label1.Text = sender.GetType().ToString() + ": MouseHover";
    }

    void panel1_MouseLeave(const object& sender, const System::EventArgs& e) {
      // Update the mouse event label to indicate the MouseLeave event occurred.
      label1.Text = sender.GetType().ToString() + ": MouseLeave";
    }

    void panel1_MouseMove(const object& sender, const System::Windows::Forms::MouseEventArgs& e) {
      // Update the mouse path that is drawn onto the Panel.
      int mouseX = e.X;
      int mouseY = e.Y;

      mousePath.AddLine(mouseX, mouseY, mouseX, mouseY);
    }

    void panel1_MouseWheel(const object& sender, const System::Windows::Forms::MouseEventArgs& e) {
      // Update the drawing based upon the mouse wheel scrolling.

      int numberOfTextLinesToMove = e.Delta * SystemInformation::MouseWheelScrollLines / 120;
      int numberOfPixelsToMove = numberOfTextLinesToMove * fontSize;

      if (numberOfPixelsToMove != 0) {
        System::Drawing::Drawing2D.Matrix translateMatrix;
        translateMatrix.Translate(0, numberOfPixelsToMove);
        mousePath.Transform(translateMatrix);
      }
      panel1.Invalidate();
    }

    void panel1_MouseUp(const object& sender, System::Windows::Forms::MouseEventArgs e) {
      Point mouseUpLocation(e.X, e.Y);

      // Show the number of clicks in the path graphic.
      int numberOfClicks = e.Clicks;
      mousePath.AddString("    " + numberOfClicks.ToString(), FontFamily::GenericSerif, (int)FontStyle::Bold, fontSize, mouseUpLocation, StringFormat::GenericDefault);

      panel1.Invalidate();
    }

    void panel1_Paint(const object& sender, System::Windows::Forms::PaintEventArgs e) {
      // Perform the painting of the Panel.
      e.Graphics.DrawPath(System::Drawing::Pens::DarkRed, mousePath);
    }

    void clearButton_Click(const object& sender, const System::EventArgs& e) {
      // Clear the Panel display.
      mousePath = System::Drawing::Drawing2D.GraphicsPath();
      panel1.Invalidate();
    }
  }
};

startup_(Examples::Form1);
