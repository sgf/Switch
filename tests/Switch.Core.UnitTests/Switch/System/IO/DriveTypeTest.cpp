#include <Switch/System/Enum.hpp>
#include <Switch/System/IO/DriveType.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(DriveTypeTest, Unknown) {
    ASSERT_EQ(0, (int32)System::IO::DriveType::Unknown);
    ASSERT_EQ("Unknown", Enum<System::IO::DriveType>(System::IO::DriveType::Unknown).ToString());
  }

  TEST(DriveTypeTest, NoRootDirectory) {
    ASSERT_EQ(1, (int32)System::IO::DriveType::NoRootDirectory);
    ASSERT_EQ("NoRootDirectory", Enum<System::IO::DriveType>(System::IO::DriveType::NoRootDirectory).ToString());
  }

  TEST(DriveTypeTest, Removable) {
    ASSERT_EQ(2, (int32)System::IO::DriveType::Removable);
    ASSERT_EQ("Removable", Enum<System::IO::DriveType>(System::IO::DriveType::Removable).ToString());
  }

  TEST(DriveTypeTest, Fixed) {
    ASSERT_EQ(3, (int32)System::IO::DriveType::Fixed);
    ASSERT_EQ("Fixed", Enum<System::IO::DriveType>(System::IO::DriveType::Fixed).ToString());
  }

  TEST(DriveTypeTest, Network) {
    ASSERT_EQ(4, (int32)System::IO::DriveType::Network);
    ASSERT_EQ("Network", Enum<System::IO::DriveType>(System::IO::DriveType::Network).ToString());
  }

  TEST(DriveTypeTest, CDRom) {
    ASSERT_EQ(5, (int32)System::IO::DriveType::CDRom);
    ASSERT_EQ("CDRom", Enum<System::IO::DriveType>(System::IO::DriveType::CDRom).ToString());
  }

  TEST(DriveTypeTest, Ram) {
    ASSERT_EQ(6, (int32)System::IO::DriveType::Ram);
    ASSERT_EQ("Ram", Enum<System::IO::DriveType>(System::IO::DriveType::Ram).ToString());
  }
}
