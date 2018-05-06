#include <Switch/Switch>

using namespace System::Windows::Forms;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Application::Run(Form());
    }
  };
}

// startup_(Examples::Program);
// You can write following lines instead "startup_(Examples::Program);" helper call :

// The main entry point for the application.
int32 main(int argc, char* argv[]) {
  System::Environment::SetCommandLineArgs(argv, argc);
  Examples::Program::Main();
  return System::Environment::ExitCode;
}

// The main entry point for the Microsoft Windows application (this mathod has not effect on other Operating System).
int __stdcall WinMain(HINSTANCE instance, HINSTANCE previousInstance, char* commandLine, int commandShow) {
  return main(__argc, __argv);
}
