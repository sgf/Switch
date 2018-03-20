#include <Switch/System/Enum.hpp>
#include <Switch/Microsoft/Win32/RegistryKeyPermissionCheck.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace Microsoft::Win32;
using namespace System;

namespace SwitchUnitTests {
  TEST(RegistryKeyPermissionCheckTest, Default) {
    ASSERT_EQ(0, (int32)RegistryKeyPermissionCheck::Default);
    ASSERT_EQ("Default", Enum<RegistryKeyPermissionCheck>(RegistryKeyPermissionCheck::Default).ToString());
  }

  TEST(RegistryKeyPermissionCheckTest, ReadSubTree) {
    ASSERT_EQ(1, (int32)RegistryKeyPermissionCheck::ReadSubTree);
    ASSERT_EQ("ReadSubTree", Enum<RegistryKeyPermissionCheck>(RegistryKeyPermissionCheck::ReadSubTree).ToString());
  }

  TEST(RegistryKeyPermissionCheckTest, ReadWriteSubTree) {
    ASSERT_EQ(2, (int32)RegistryKeyPermissionCheck::ReadWriteSubTree);
    ASSERT_EQ("ReadWriteSubTree", Enum<RegistryKeyPermissionCheck>(RegistryKeyPermissionCheck::ReadWriteSubTree).ToString());
  }
}
