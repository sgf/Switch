#include <Switch/System/Enum.hpp>
#include <Switch/System/IO/FileAccess.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(FileAccessTest, Read) {
    ASSERT_EQ(0, (int32)System::IO::FileAccess::Read);
    ASSERT_EQ("Read", Enum<System::IO::FileAccess>(System::IO::FileAccess::Read).ToString());
  }

  TEST(FileAccessTest, Write) {
    ASSERT_EQ(1, (int32)System::IO::FileAccess::Write);
    ASSERT_EQ("Write", Enum<System::IO::FileAccess>(System::IO::FileAccess::Write).ToString());
  }

  TEST(FileAccessTest, ReadWrite) {
    ASSERT_EQ(2, (int32)System::IO::FileAccess::ReadWrite);
    ASSERT_EQ("ReadWrite", Enum<System::IO::FileAccess>(System::IO::FileAccess::ReadWrite).ToString());
  }
}
