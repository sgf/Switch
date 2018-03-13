#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace WindowsApplication1 {
  class Form1 : public System::Windows::Forms::Form {
  private:
    // Constant value was found in the "windows.h" header file.
    static constexpr int WM_ACTIVATEAPP = 0x001C;
    bool appActive = true;

  public:
    static void Main() {
      Application::Run(Form1());
    }

    Form1() {
      this->Size = System::Drawing::Size(300, 300);
      this->Text = "Form1";
      //this->Font = System::Drawing::Font("Microsoft Sans Serif", 18F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, System::Byte(0));
    }

  protected:
    void OnPaint(PaintEventArgs& e) override {
      // Paint a string in different styles depending on whether the application is active.
      if (appActive) {
        e.Graphics().FillRectangle(SolidBrush(Color::LightBlue), 20, 29, 260, 60);
        //e.Graphics().FillRectangle(SystemBrushes::ActiveCaption, 20, 20, 260, 50);
        //e.Graphics().DrawString("Application is active", this->Font, SystemBrushes.ActiveCaptionText, 20, 20);
      } else {
        e.Graphics().FillRectangle(SolidBrush(Color::LightGray), 20, 20, 260, 60);
        //e.Graphics().FillRectangle(SystemBrushes::InactiveCaption,20,20,260,50);
        //e.Graphics().DrawString("Application is Inactive", this->Font, SystemBrushes::ActiveCaptionText, 20, 20);
      }
    }

    void WndProc(Message& m) override {
      // Listen for operating system messages.
      switch (m.Msg()) {
      // The WM_ACTIVATEAPP message occurs when the application becomes the active application or becomes inactive.
      case WM_ACTIVATEAPP:

        // The WParam value identifies what is occurring.
        appActive = (((int)m.WParam != 0));
        System::Diagnostics::Debug::Debug::WriteLine(string::Format("appActive = {}", appActive));
        // Invalidate to get new text painted.
        this->Invalidate();

        break;
      }
      this->System::Windows::Forms::Form::WndProc(m);
    }
  };
}

startup_(WindowsApplication1::Form1);

