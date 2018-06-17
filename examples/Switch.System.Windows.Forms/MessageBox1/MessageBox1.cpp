#include <Switch/Switch>

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      System::Windows::Forms::MessageBox::Show("This is text message", "Title");
    }
  };
}

startup_(Examples::Program);
