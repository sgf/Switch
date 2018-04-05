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
}
