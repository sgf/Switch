#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Windows::Forms;

namespace Examples {
  class Form1 : public Form {
  private:
    StatusStrip statusStrip1;

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
      // statusStrip1
      //
      this->statusStrip1.Location = System::Drawing::Point(0, 251);
      this->statusStrip1.Name = "statusStrip1";
      this->statusStrip1.Size = System::Drawing::Size(292, 22);
      this->statusStrip1.Text = "statusStrip1";
      this->statusStrip1.LocationChanged += System::EventHandler(*this, &Form1::statusStrip1_LocationChanged);
      //
      // Form1
      //
      this->ClientSize = System::Drawing::Size(292, 273);
      this->Controls().Add(this->statusStrip1);
      this->Name = "Form1";
      this->ResumeLayout(false);
      this->PerformLayout();

    }

    void statusStrip1_LocationChanged(const object& sender, const EventArgs& e) {
      MessageBox::Show("The form has been resized.");
    }
  };
}

startup_(Examples::Form1);
