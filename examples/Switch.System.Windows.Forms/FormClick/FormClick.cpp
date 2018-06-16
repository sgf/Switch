#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace Examples {
  class FormClick {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Form form;
      form.Click += delegate_(const object & sender, const EventArgs & e) {
        MessageBox::Show("The form is clicked", "FormClick", MessageBoxButtons::OK);
      };
      Application::Run(form);
    }
  };
}

startup_(Examples::FormClick);

