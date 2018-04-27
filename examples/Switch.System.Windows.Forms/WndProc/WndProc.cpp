#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace WindowsApplication1 {
  class Form1 : public System::Windows::Forms::Form {
  private:
    // Constant value was found in the "windows.h" header file.
    static constexpr int WM_ACTIVATEAPP = 0x001C;

  public:
    static void Main() {
      Application::Run(Form1());
    }

    Form1() {
      this->label.Bounds = Rectangle(20, 20, 260, 60);
      this->label.BorderStyle = BorderStyle::Fixed3D;

      this->ClientSize = System::Drawing::Size(300, 300);
      this->Text = "Form1";
      this->Font = System::Drawing::Font("Microsoft Sans Serif", 18.0f, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, System::Byte(0));
      this->Controls().Add(label);
    }

  protected:
    void WndProc(Message& m) override {
      // Listen for operating system messages.
      switch (m.Msg()) {
      // The WM_ACTIVATEAPP message occurs when the application becomes the active application or becomes inactive.
      case WM_ACTIVATEAPP:
        // The WParam value identifies what is occurring.
        bool appActive = (((int)m.WParam != 0));
        System::Diagnostics::Debug::Debug::WriteLine(string::Format("appActive = {0}", appActive));
        this->label.BackColor =  appActive ? System::Drawing::Color::LightBlue : System::Drawing::Color::LightGray;
        this->label.ForeColor =  appActive ? System::Drawing::SystemColors::ActiveCaptionText : System::Drawing::SystemColors::InactiveCaptionText;
        this->label.Text = appActive ? "Application is active" : "Application is inactive";
        break;
      }
      this->System::Windows::Forms::Form::WndProc(m);
    }

  private:
    Label label;
  };
}

startup_(WindowsApplication1::Form1);


