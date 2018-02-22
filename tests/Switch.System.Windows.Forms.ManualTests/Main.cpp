#include <Switch/System/Windows/Forms/Form.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      Form mainForm;
      mainForm.ShowDialog();
    }
  };
}

startup_(ManualTests::Program);
