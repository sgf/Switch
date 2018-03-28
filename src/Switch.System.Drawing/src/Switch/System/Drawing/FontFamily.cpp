#include <Switch/System/Collections/Generic/List.hpp>
#include "../../../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../../../include/Switch/System/Drawing/Text/InstalledFontCollection.hpp"
#include "../../../Native/Api.hpp"

System::Drawing::FontFamily::FontFamily(const string& name) {
  *this = Native::FontFamilyApi::GetFontFamilyFromName(name);
}

System::Drawing::FontFamily::FontFamily(System::Drawing::Text::GenericFontFamilies genericFamily) {
  if (genericFamily == System::Drawing::Text::GenericFontFamilies::Serif)
    *this = System::Drawing::FontFamily(Native::FontFamilyApi::GenericFontFamilySerifName());
  else if (genericFamily == System::Drawing::Text::GenericFontFamilies::SansSerif)
    *this = System::Drawing::FontFamily(Native::FontFamilyApi::GenericFontFamilySansSerifName());
  else
    *this = System::Drawing::FontFamily(Native::FontFamilyApi::GenericFontFamilyMonospaceName());
}

System::Drawing::FontFamily::~FontFamily() {
  if (this->data.IsUnique())
    Native::FontFamilyApi::ReleaseResource(this->data().handle);
}

property_<System::Array<System::Drawing::FontFamily>, readonly_> System::Drawing::FontFamily::Families {
  [] {return System::Drawing::Text::InstalledFontCollection().Families();}
};

property_<System::Drawing::FontFamily, readonly_> System::Drawing::FontFamily::GenericMonospace {
  [] {return FontFamily(System::Drawing::Text::GenericFontFamilies::Monospace);}
};

property_<System::Drawing::FontFamily, readonly_> System::Drawing::FontFamily::GenericSansSerif {
  [] {return FontFamily(System::Drawing::Text::GenericFontFamilies::SansSerif);}
};

property_<System::Drawing::FontFamily, readonly_> System::Drawing::FontFamily::GenericSerif {
  [] {return FontFamily(System::Drawing::Text::GenericFontFamilies::Serif);}
};

string System::Drawing::FontFamily::GetName() const {
  return Native::FontFamilyApi::GetName(this->data().handle);
}

bool System::Drawing::FontFamily::IsStyleAvailable(System::Drawing::FontStyle style) const {
  return Native::FontFamilyApi::IsStyleAvailable(this->data().handle, style);
}
