#include <Switch/System/Enum.hpp>
#include <Switch/Microsoft/Win32/RegistryKeyPermissionCheck.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(RegistryKeyPermissionCheckTest, Default) {
    ASSERT_EQ(0, (int32)Microsoft::Win32::RegistryKeyPermissionCheck::Default);
    ASSERT_EQ("Default", Enum<Microsoft::Win32::RegistryKeyPermissionCheck>(Microsoft::Win32::RegistryKeyPermissionCheck::Default).ToString());
  }

  TEST(RegistryKeyPermissionCheckTest, ReadSubTree) {
    ASSERT_EQ(1, (int32)Microsoft::Win32::RegistryKeyPermissionCheck::ReadSubTree);
    ASSERT_EQ("ReadSubTree", Enum<Microsoft::Win32::RegistryKeyPermissionCheck>(Microsoft::Win32::RegistryKeyPermissionCheck::ReadSubTree).ToString());
  }

  TEST(RegistryKeyPermissionCheckTest, ReadWriteSubTree) {
    ASSERT_EQ(2, (int32)Microsoft::Win32::RegistryKeyPermissionCheck::ReadWriteSubTree);
    ASSERT_EQ("ReadWriteSubTree", Enum<Microsoft::Win32::RegistryKeyPermissionCheck>(Microsoft::Win32::RegistryKeyPermissionCheck::ReadWriteSubTree).ToString());
  }
}
