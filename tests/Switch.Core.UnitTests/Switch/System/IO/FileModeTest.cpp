#include <Switch/System/Enum.hpp>
#include <Switch/System/IO/FileMode.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(FileModeTest, CreateNew) {
    ASSERT_EQ(1, (int32)System::IO::FileMode::CreateNew);
    ASSERT_EQ("CreateNew", Enum<System::IO::FileMode>(System::IO::FileMode::CreateNew).ToString());
  }

  TEST(FileModeTest, Create) {
    ASSERT_EQ(2, (int32)System::IO::FileMode::Create);
    ASSERT_EQ("Create", Enum<System::IO::FileMode>(System::IO::FileMode::Create).ToString());
  }

  TEST(FileModeTest, Open) {
    ASSERT_EQ(3, (int32)System::IO::FileMode::Open);
    ASSERT_EQ("Open", Enum<System::IO::FileMode>(System::IO::FileMode::Open).ToString());
  }

  TEST(FileModeTest, OpenOrCreate) {
    ASSERT_EQ(4, (int32)System::IO::FileMode::OpenOrCreate);
    ASSERT_EQ("OpenOrCreate", Enum<System::IO::FileMode>(System::IO::FileMode::OpenOrCreate).ToString());
  }

  TEST(FileModeTest, Truncate) {
    ASSERT_EQ(5, (int32)System::IO::FileMode::Truncate);
    ASSERT_EQ("Truncate", Enum<System::IO::FileMode>(System::IO::FileMode::Truncate).ToString());
  }

  TEST(FileModeTest, Append) {
    ASSERT_EQ(6, (int32)System::IO::FileMode::Append);
    ASSERT_EQ("Append", Enum<System::IO::FileMode>(System::IO::FileMode::Append).ToString());
  }
}
