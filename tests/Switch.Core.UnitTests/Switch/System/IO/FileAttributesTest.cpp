#include <Switch/System/Enum.hpp>
#include <Switch/System/IO/FileAttributes.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(FileAttributesTest, ReadOnly) {
    ASSERT_EQ(1, (int32)System::IO::FileAttributes::ReadOnly);
    ASSERT_EQ("ReadOnly", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::ReadOnly).ToString());
  }

  TEST(FileAttributesTest, Hidden) {
    ASSERT_EQ(2, (int32)System::IO::FileAttributes::Hidden);
    ASSERT_EQ("Hidden", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::Hidden).ToString());
  }

  TEST(FileAttributesTest, System) {
    ASSERT_EQ(4, (int32)System::IO::FileAttributes::System);
    ASSERT_EQ("System", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::System).ToString());
  }

  TEST(FileAttributesTest, Directory) {
    ASSERT_EQ(16, (int32)System::IO::FileAttributes::Directory);
    ASSERT_EQ("Directory", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::Directory).ToString());
  }

  TEST(FileAttributesTest, Archive) {
    ASSERT_EQ(32, (int32)System::IO::FileAttributes::Archive);
    ASSERT_EQ("Archive", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::Archive).ToString());
  }

  TEST(FileAttributesTest, Device) {
    ASSERT_EQ(64, (int32)System::IO::FileAttributes::Device);
    ASSERT_EQ("Device", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::Device).ToString());
  }

  TEST(FileAttributesTest, Normal) {
    ASSERT_EQ(128, (int32)System::IO::FileAttributes::Normal);
    ASSERT_EQ("Normal", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::Normal).ToString());
  }

  TEST(FileAttributesTest, Temporary) {
    ASSERT_EQ(256, (int32)System::IO::FileAttributes::Temporary);
    ASSERT_EQ("Temporary", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::Temporary).ToString());
  }

  TEST(FileAttributesTest, SparseFile) {
    ASSERT_EQ(512, (int32)System::IO::FileAttributes::SparseFile);
    ASSERT_EQ("SparseFile", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::SparseFile).ToString());
  }

  TEST(FileAttributesTest, ReparsePoint) {
    ASSERT_EQ(1024, (int32)System::IO::FileAttributes::ReparsePoint);
    ASSERT_EQ("ReparsePoint", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::ReparsePoint).ToString());
  }

  TEST(FileAttributesTest, Compressed) {
    ASSERT_EQ(2048, (int32)System::IO::FileAttributes::Compressed);
    ASSERT_EQ("Compressed", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::Compressed).ToString());
  }

  TEST(FileAttributesTest, Offline) {
    ASSERT_EQ(4096, (int32)System::IO::FileAttributes::Offline);
    ASSERT_EQ("Offline", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::Offline).ToString());
  }

  TEST(FileAttributesTest, NotContentIndexed) {
    ASSERT_EQ(8192, (int32)System::IO::FileAttributes::NotContentIndexed);
    ASSERT_EQ("NotContentIndexed", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::NotContentIndexed).ToString());
  }

  TEST(FileAttributesTest, Encrypted) {
    ASSERT_EQ(16384, (int32)System::IO::FileAttributes::Encrypted);
    ASSERT_EQ("Encrypted", Enum<System::IO::FileAttributes>(System::IO::FileAttributes::Encrypted).ToString());
  }
}
