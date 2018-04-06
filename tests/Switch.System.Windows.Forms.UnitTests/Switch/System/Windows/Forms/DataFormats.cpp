#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/DataFormats.hpp>

using namespace System;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(DataformatsTest, Bmp) {
    ASSERT_EQ("Bitmap", DataFormats::Bitmap);
  }

  TEST(DataformatsTest, CommaSeparatedValue) {
    ASSERT_EQ("Csv", DataFormats::CommaSeparatedValue);
  }

  TEST(DataformatsTest, Dib) {
    ASSERT_EQ("DeviceIndependentBitmap", DataFormats::Dib);
  }

  TEST(DataformatsTest, Dif) {
    ASSERT_EQ("DataInterchangeFormat", DataFormats::Dif);
  }

  TEST(DataformatsTest, EnhancedMetafile) {
    ASSERT_EQ("EnhancedMetafile", DataFormats::EnhancedMetafile);
  }

  TEST(DataformatsTest, FileDrop) {
    ASSERT_EQ("FileDrop", DataFormats::FileDrop);
  }

  TEST(DataformatsTest, Html) {
    ASSERT_EQ("HTML Format", DataFormats::Html);
  }

  TEST(DataformatsTest, Locale) {
    ASSERT_EQ("Locale", DataFormats::Locale);
  }

  TEST(DataformatsTest, MetafilePict) {
    ASSERT_EQ("MetaFilePict", DataFormats::MetafilePict);
  }

  TEST(DataformatsTest, OemText) {
    ASSERT_EQ("OEMText", DataFormats::OemText);
  }

  TEST(DataformatsTest, Palette) {
    ASSERT_EQ("Palette", DataFormats::Palette);
  }

  TEST(DataformatsTest, PenData) {
    ASSERT_EQ("PenData", DataFormats::PenData);
  }

  TEST(DataformatsTest, Riff) {
    ASSERT_EQ("RiffAudio", DataFormats::Riff);
  }

  TEST(DataformatsTest, Serializable) {
    ASSERT_EQ("WindowsForms10PersistentObject", DataFormats::Serializable);
  }

  TEST(DataformatsTest, StringFormat) {
    ASSERT_EQ("System::String", DataFormats::StringFormat);
  }

  TEST(DataformatsTest, SymbolicLink) {
    ASSERT_EQ("SymbolicLink", DataFormats::SymbolicLink);
  }

  TEST(DataformatsTest, Text) {
    ASSERT_EQ("Text", DataFormats::Text);
  }

  TEST(DataformatsTest, Tiff) {
    ASSERT_EQ("TaggedImageFileFormat", DataFormats::Tiff);
  }

  TEST(DataformatsTest, UnicodeText) {
    ASSERT_EQ("UnicodeText", DataFormats::UnicodeText);
  }

  TEST(DataformatsTest, WaveAudio) {
    ASSERT_EQ("WaveAudio", DataFormats::WaveAudio);
  }

  TEST(DataFormatsTest, GetFormatById1) {
    DataFormats::Format format = DataFormats::GetFormat(1);

    ASSERT_EQ(1, format.Id);
    ASSERT_EQ(DataFormats::Text, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById2) {
    DataFormats::Format format = DataFormats::GetFormat(2);

    ASSERT_EQ(2, format.Id);
    ASSERT_EQ(DataFormats::Bitmap, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById3) {
    DataFormats::Format format = DataFormats::GetFormat(3);

    ASSERT_EQ(3, format.Id);
    ASSERT_EQ(DataFormats::MetafilePict, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById4) {
    DataFormats::Format format = DataFormats::GetFormat(4);

    ASSERT_EQ(4, format.Id);
    ASSERT_EQ(DataFormats::SymbolicLink, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById5) {
    DataFormats::Format format = DataFormats::GetFormat(5);

    ASSERT_EQ(5, format.Id);
    ASSERT_EQ(DataFormats::Dif, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById6) {
    DataFormats::Format format = DataFormats::GetFormat(6);

    ASSERT_EQ(6, format.Id);
    ASSERT_EQ(DataFormats::Tiff, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById7) {
    DataFormats::Format format = DataFormats::GetFormat(7);

    ASSERT_EQ(7, format.Id);
    ASSERT_EQ(DataFormats::OemText, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById8) {
    DataFormats::Format format = DataFormats::GetFormat(8);

    ASSERT_EQ(8, format.Id);
    ASSERT_EQ(DataFormats::Dib, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById9) {
    DataFormats::Format format = DataFormats::GetFormat(9);

    ASSERT_EQ(9, format.Id);
    ASSERT_EQ(DataFormats::Palette, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById10) {
    DataFormats::Format format = DataFormats::GetFormat(10);

    ASSERT_EQ(10, format.Id);
    ASSERT_EQ(DataFormats::PenData, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById11) {
    DataFormats::Format format = DataFormats::GetFormat(11);

    ASSERT_EQ(11, format.Id);
    ASSERT_EQ(DataFormats::Riff, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById12) {
    DataFormats::Format format = DataFormats::GetFormat(12);

    ASSERT_EQ(12, format.Id);
    ASSERT_EQ(DataFormats::WaveAudio, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById13) {
    DataFormats::Format format = DataFormats::GetFormat(13);

    ASSERT_EQ(13, format.Id);
    ASSERT_EQ(DataFormats::UnicodeText, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById14) {
    DataFormats::Format format = DataFormats::GetFormat(14);

    ASSERT_EQ(14, format.Id);
    ASSERT_EQ(DataFormats::EnhancedMetafile, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById15) {
    DataFormats::Format format = DataFormats::GetFormat(15);

    ASSERT_EQ(15, format.Id);
    ASSERT_EQ(DataFormats::FileDrop, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById16) {
    DataFormats::Format format = DataFormats::GetFormat(16);

    ASSERT_EQ(16, format.Id);
    ASSERT_EQ(DataFormats::Locale, format.Name);
  }

  TEST(DataFormatsTest, GetFormatById4356) {
    DataFormats::Format format = DataFormats::GetFormat(4356);

    ASSERT_EQ(4356, format.Id);
    ASSERT_EQ("Format4356", format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameText) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::Text);

    ASSERT_EQ(1, format.Id);
    ASSERT_EQ(DataFormats::Text, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameBitmap) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::Bitmap);

    ASSERT_EQ(2, format.Id);
    ASSERT_EQ(DataFormats::Bitmap, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameMetafilePict) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::MetafilePict);

    ASSERT_EQ(3, format.Id);
    ASSERT_EQ(DataFormats::MetafilePict, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameSymbolicLink) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::SymbolicLink);

    ASSERT_EQ(4, format.Id);
    ASSERT_EQ(DataFormats::SymbolicLink, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameDif) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::Dif);

    ASSERT_EQ(5, format.Id);
    ASSERT_EQ(DataFormats::Dif, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameTiff) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::Tiff);

    ASSERT_EQ(6, format.Id);
    ASSERT_EQ(DataFormats::Tiff, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByName7) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::OemText);

    ASSERT_EQ(7, format.Id);
    ASSERT_EQ(DataFormats::OemText, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameDib) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::Dib);

    ASSERT_EQ(8, format.Id);
    ASSERT_EQ(DataFormats::Dib, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNamePalette) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::Palette);

    ASSERT_EQ(9, format.Id);
    ASSERT_EQ(DataFormats::Palette, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNamePenData) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::PenData);

    ASSERT_EQ(10, format.Id);
    ASSERT_EQ(DataFormats::PenData, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameRiff) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::Riff);

    ASSERT_EQ(11, format.Id);
    ASSERT_EQ(DataFormats::Riff, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameWaveAudio) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::WaveAudio);

    ASSERT_EQ(12, format.Id);
    ASSERT_EQ(DataFormats::WaveAudio, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameUnicodeText) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::UnicodeText);

    ASSERT_EQ(13, format.Id);
    ASSERT_EQ(DataFormats::UnicodeText, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameEnhancedMetafile) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::EnhancedMetafile);

    ASSERT_EQ(14, format.Id);
    ASSERT_EQ(DataFormats::EnhancedMetafile, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameFileDrop) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::FileDrop);

    ASSERT_EQ(15, format.Id);
    ASSERT_EQ(DataFormats::FileDrop, format.Name);
  }

  TEST(DataFormatsTest, GetFormatByNameLocale) {
    DataFormats::Format format = DataFormats::GetFormat(DataFormats::Locale);

    ASSERT_EQ(16, format.Id);
    ASSERT_EQ(DataFormats::Locale, format.Name);
  }
}
