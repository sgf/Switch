#include <Pcf/Pcf>

using namespace System::Windows::FormsD;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::Run(Form());
    }
  };
};

pcf_startup (Examples::Program)