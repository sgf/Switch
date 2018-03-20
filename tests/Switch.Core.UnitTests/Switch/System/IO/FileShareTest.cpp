#include <Switch/System/Enum.hpp>
#include <Switch/System/IO/FileShare.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(FileShareTest, None) {
    ASSERT_EQ(0, (int32)System::IO::FileShare::None);
    ASSERT_EQ("None", Enum<System::IO::FileShare>(System::IO::FileShare::None).ToString());
  }

  TEST(FileShareTest, Read) {
    ASSERT_EQ(1, (int32)System::IO::FileShare::Read);
    ASSERT_EQ("Read", Enum<System::IO::FileShare>(System::IO::FileShare::Read).ToString());
  }

  TEST(FileShareTest, Write) {
    ASSERT_EQ(2, (int32)System::IO::FileShare::Write);
    ASSERT_EQ("Write", Enum<System::IO::FileShare>(System::IO::FileShare::Write).ToString());
  }

  TEST(FileShareTest, ReadWrite) {
    ASSERT_EQ(3, (int32)System::IO::FileShare::ReadWrite);
    ASSERT_EQ("ReadWrite", Enum<System::IO::FileShare>(System::IO::FileShare::ReadWrite).ToString());
  }

  TEST(FileShareTest, Delete) {
    ASSERT_EQ(4, (int32)System::IO::FileShare::Delete);
    ASSERT_EQ("Delete", Enum<System::IO::FileShare>(System::IO::FileShare::Delete).ToString());
  }

  TEST(FileShareTest, Inheritable) {
    ASSERT_EQ(16, (int32)System::IO::FileShare::Inheritable);
    ASSERT_EQ("Inheritable", Enum<System::IO::FileShare>(System::IO::FileShare::Inheritable).ToString());
  }
}
