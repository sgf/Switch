#include <Switch/System/Enum.hpp>
#include <Switch/Microsoft/Win32/RegistryHive.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(RegistryHiveTest, ClassesRoot) {
    ASSERT_EQ(0, (int32)Microsoft::Win32::RegistryHive::ClassesRoot);
    ASSERT_EQ("ClassesRoot", Enum<Microsoft::Win32::RegistryHive>(Microsoft::Win32::RegistryHive::ClassesRoot).ToString());
  }

  TEST(RegistryHiveTest, CurrentUser) {
    ASSERT_EQ(1, (int32)Microsoft::Win32::RegistryHive::CurrentUser);
    ASSERT_EQ("CurrentUser", Enum<Microsoft::Win32::RegistryHive>(Microsoft::Win32::RegistryHive::CurrentUser).ToString());
  }

  TEST(RegistryHiveTest, LocalMachine) {
    ASSERT_EQ(2, (int32)Microsoft::Win32::RegistryHive::LocalMachine);
    ASSERT_EQ("LocalMachine", Enum<Microsoft::Win32::RegistryHive>(Microsoft::Win32::RegistryHive::LocalMachine).ToString());
  }

  TEST(RegistryHiveTest, Users) {
    ASSERT_EQ(3, (int32)Microsoft::Win32::RegistryHive::Users);
    ASSERT_EQ("Users", Enum<Microsoft::Win32::RegistryHive>(Microsoft::Win32::RegistryHive::Users).ToString());
  }

  TEST(RegistryHiveTest, PerformanceData) {
    ASSERT_EQ(4, (int32)Microsoft::Win32::RegistryHive::PerformanceData);
    ASSERT_EQ("PerformanceData", Enum<Microsoft::Win32::RegistryHive>(Microsoft::Win32::RegistryHive::PerformanceData).ToString());
  }

  TEST(RegistryHiveTest, CurrentConfig) {
    ASSERT_EQ(5, (int32)Microsoft::Win32::RegistryHive::CurrentConfig);
    ASSERT_EQ("CurrentConfig", Enum<Microsoft::Win32::RegistryHive>(Microsoft::Win32::RegistryHive::CurrentConfig).ToString());
  }

  TEST(RegistryHiveTest, DynData) {
    ASSERT_EQ(6, (int32)Microsoft::Win32::RegistryHive::DynData);
    ASSERT_EQ("DynData", Enum<Microsoft::Win32::RegistryHive>(Microsoft::Win32::RegistryHive::DynData).ToString());
  }
}
