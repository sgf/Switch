#include <Switch/Switch>

// The main entry point for the application.
int32 main(int argc, char* argv[]) {
  System::Environment::SetCommandLineArgs(argv, argc);
  System::Windows::Forms::Application::Run(System::Windows::Forms::Form());
}
