#include <Switch/Microsoft/Win32/Registry.hpp>
#include <Switch/System/IO/Directory.hpp>
#include <Switch/System/IO/Path.hpp>
#include <Switch/System/ArgumentException.hpp>
#include <Switch/System/Reflection/AssemblyAttribute.hpp>
#include "../../../../Native/Api.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"

using namespace System;
using namespace System::Reflection;
using namespace System::Windows::Forms;

static bool messageLoop = false;
static FormCollection openForms;

property_<bool, readonly_> Application::AllowQuit {
  [] {return true;}
};

property_<string, readonly_> Application::CommonAppDataPath {
  [] {
    string commonAppDataPath = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::CommonApplicationData), CompanyName, ProductName, ProductVersion);
    if (!System::IO::Directory::Exists(commonAppDataPath))
      System::IO::Directory::CreateDirectory(commonAppDataPath);
    return commonAppDataPath;
  }
};

property_<Microsoft::Win32::RegistryKey, readonly_> Application::CommonAppDataRegistry {
  [] {return Microsoft::Win32::Registry::LocalMachine().CreateSubKey("Software").CreateSubKey(CompanyName).CreateSubKey(ProductName).CreateSubKey(ProductVersion);}
};

property_<string, readonly_> Application::CompanyName {
  [] {
    if (!__assembly_company_attribute__() || __assembly_company_attribute__().ToObject() == "")
      return System::IO::Path::GetFileNameWithoutExtension(ExecutablePath);
    return __assembly_company_attribute__().ToObject();
  }
};

property_<string, readonly_> Application::ExecutablePath {
  [] {return Environment::GetCommandLineArgs()[0];}
};

property_<string, readonly_> Application::LocalUserAppDataPath {
  [] {
    string localUserAppDataPath = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::LocalApplicationData), CompanyName, ProductName, ProductVersion);
    if (!System::IO::Directory::Exists(localUserAppDataPath))
      System::IO::Directory::CreateDirectory(localUserAppDataPath);
    return localUserAppDataPath;
  }
};

property_<bool, readonly_> Application::MessageLoop {
  [] {return messageLoop;}
};

property_<FormCollection, readonly_> Application::OpenForms {
  [] {return openForms;}
};

property_<string, readonly_> Application::ProductName {
  [] {
    if (!__assembly_product_attribute__() || __assembly_company_attribute__().ToObject() == "")
      return System::IO::Path::GetFileNameWithoutExtension(ExecutablePath);
    return __assembly_product_attribute__().ToObject();
  }
};

property_<string, readonly_> Application::ProductVersion {
  [] {
    if (!__assembly_version_attribute__() || __assembly_version_attribute__().ToObject() == "")
      return Version(0, 0, 0).ToString();
    return __assembly_version_attribute__().ToObject();
  }
};

ref<Form> Application::mainForm;
EventHandler Application::ApplicationExit;
EventHandler Application::EnterThreadModal;
EventHandler Application::Idle;
EventHandler Application::LeaveThreadModal;
System::Threading::ThreadExceptionEventHandler Application::ThreadException;
EventHandler Application::ThreadExit;

void Application::EnableVisualStyles() {
  Native::ApplicationApi::EnableVisualStyles();
}

void Application::Exit() {
  ExitThread();
}

void Application::ExitThread() {
  Native::ApplicationApi::Exit();
}

void Application::OnThreadException(const Exception& exception) {
  ThreadException(object(), System::Threading::ThreadExceptionEventArgs(exception));
}

void Application::Init() {
  static bool runOnce = true;
  if (runOnce) {
    runOnce = false;
    Native::ApplicationApi::Start();
  }
}

void Application::Run() {
  Init();
  RunMessageLoop();
}

void Application::Run(ref<System::Windows::Forms::Form> form) {
  openForms.Add(form);
  form->ShowDialog();
  openForms.Remove(form);
}

void Application::RunMessageLoop() {
  messageLoop = true;
  EnterThreadModal(object(), EventArgs::Empty);
  try {
    Native::ApplicationApi::MessageLoop(mainForm(), Idle);
  } catch (const Exception& exception) {
    OnThreadException(exception);
  }
  LeaveThreadModal(object(), EventArgs::Empty);
  Idle = EventHandler();
  Native::ApplicationApi::Stop();
  ThreadExit(object(), EventArgs::Empty);
  ApplicationExit(object(), EventArgs::Empty);
  messageLoop = false;
}

void Application::SetCompatibleTextRenderingDefault(bool rendering) {

}
