#include "../../../../include/Switch/System/Drawing/SystemFonts.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;

property_<Font, readonly_> SystemFonts::CaptionFont {
  [] {return Native::FontApi::GetCaptionFont();}
};

property_<Font, readonly_> SystemFonts::DefaultFont {
  [] {return Native::FontApi::GetDefaultFont();}
};

property_<Font, readonly_> SystemFonts::DialogFont {
  [] {return Native::FontApi::GetDialogFont();}
};

property_<Font, readonly_> SystemFonts::IconTitleFont {
  [] {return Native::FontApi::GetIconTitleFont();}
};

property_<Font, readonly_> SystemFonts::MenuFont {
  [] {return Native::FontApi::GetMenuFont();}
};

property_<Font, readonly_> SystemFonts::MessageBoxFont {
  [] {return Native::FontApi::GetMessageBoxFont();}
};

property_<Font, readonly_> SystemFonts::SmallCaptionFont {
  [] {return Native::FontApi::GetSmallCaptionFont();}
};

property_<Font, readonly_> SystemFonts::StatusFont {
  [] {return Native::FontApi::GetStatusFont();}
};
