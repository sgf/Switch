#include "../../../../../include/Switch/System/Windows/Forms/Screen.hpp"
#include "../../../../Native/Api.hpp"
#include <Switch/System/Collections/Generic/List.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

property_<System::Array<System::Windows::Forms::Screen>, readonly_> System::Windows::Forms::Screen::AllScreens {
  [] {return Native::ScreenApi::GetScreens();}
};

