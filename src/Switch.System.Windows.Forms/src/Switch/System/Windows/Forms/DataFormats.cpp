#include "../../../../../include/Switch/System/Windows/Forms/DataFormats.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

property_<string, readonly_> DataFormats::Bitmap {
  [] {return "Bitmap"; }
};

property_<string, readonly_> DataFormats::CommaSeparatedValue {
  [] {return "Csv"; }
};

property_<string, readonly_> DataFormats::Dib {
  [] {return "DeviceIndependentBitmap"; }
};

property_<string, readonly_> DataFormats::Dif {
  [] {return "DataInterchangeFormat"; }
};

property_<string, readonly_> DataFormats::EnhancedMetafile {
  [] {return "EnhancedMetafile"; }
};

property_<string, readonly_> DataFormats::FileDrop {
  [] {return "FileDrop"; }
};

property_<string, readonly_> DataFormats::Html {
  [] {return "HTML Format"; }
};

property_<string, readonly_> DataFormats::Locale {
  [] {return "Locale"; }
};

property_<string, readonly_> DataFormats::MetafilePict {
  [] {return "MetaFilePict"; }
};

property_<string, readonly_> DataFormats::OemText {
  [] {return "OEMText"; }
};

property_<string, readonly_> DataFormats::Palette {
  [] {return "Palette"; }
};

property_<string, readonly_> DataFormats::PenData {
  [] {return "PenData"; }
};

property_<string, readonly_> DataFormats::Riff {
  [] {return "RiffAudio"; }
};

property_<string, readonly_> DataFormats::Rtf {
  [] {return "Rich Text Format"; }
};

property_<string, readonly_> DataFormats::Serializable {
  [] {return "WindowsForms10PersistentObject"; }
};

property_<string, readonly_> DataFormats::StringFormat {
  [] {return "System::String"; }
};

property_<string, readonly_> DataFormats::SymbolicLink {
  [] {return "SymbolicLink"; }
};

property_<string, readonly_> DataFormats::Text {
  [] {return "Text"; }
};

property_<string, readonly_> DataFormats::Tiff {
  [] {return "TaggedImageFileFormat"; }
};

property_<string, readonly_> DataFormats::UnicodeText {
  [] {return "UnicodeText"; }
};

property_<string, readonly_> DataFormats::WaveAudio {
  [] {return "WaveAudio"; }
};

System::Collections::Generic::List<DataFormats::Format> DataFormats::formats = {
  {Bitmap, Native::ClipboardApi::GetIdBitmap()},
};

DataFormats::Format DataFormats::GetFormat(const string& name) {
  for (auto format : formats)
    if (name.Equals(format.Name))
      return format;

  for (auto format : formats)
    if (name.Equals(format.Name, true))
      return format;

  return Format(name, Native::ClipboardApi::RegisterFormat(name));
}
