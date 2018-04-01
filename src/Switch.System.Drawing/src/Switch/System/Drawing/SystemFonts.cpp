#include "../../../../include/Switch/System/Drawing/SystemFonts.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;

property_<Font, readonly_> SystemFonts::CaptionFont {
  [] {return Native::SystemFontsApi::GetCaptionFont();}
};

property_<Font, readonly_> SystemFonts::DefaultFont {
  [] {return Native::SystemFontsApi::GetDefaultFont();}
};

property_<Font, readonly_> SystemFonts::DialogFont {
  [] {return Native::SystemFontsApi::GetDialogFont();}
};

property_<Font, readonly_> SystemFonts::IconTitleFont {
  [] {return Native::SystemFontsApi::GetIconTitleFont();}
};

property_<Font, readonly_> SystemFonts::MenuFont {
  [] {return Native::SystemFontsApi::GetMenuFont();}
};

property_<Font, readonly_> SystemFonts::MessageBoxFont {
  [] {return Native::SystemFontsApi::GetMessageBoxFont();}
};

property_<Font, readonly_> SystemFonts::SmallCaptionFont {
  [] {return Native::SystemFontsApi::GetSmallCaptionFont();}
};

property_<Font, readonly_> SystemFonts::StatusFont {
  [] {return Native::SystemFontsApi::GetStatusFont();}
};
