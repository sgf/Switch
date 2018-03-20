#include <Switch/System/Enum.hpp>
#include <Switch/Microsoft/Win32/RegistryValueKind.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(RegistryValueKindTest, None) {
    ASSERT_EQ(-1, (int32)Microsoft::Win32::RegistryValueKind::None);
    ASSERT_EQ("None", Enum<Microsoft::Win32::RegistryValueKind>(Microsoft::Win32::RegistryValueKind::None).ToString());
  }

  TEST(RegistryValueKindTest, Unknown) {
    ASSERT_EQ(0, (int32)Microsoft::Win32::RegistryValueKind::Unknown);
    ASSERT_EQ("Unknown", Enum<Microsoft::Win32::RegistryValueKind>(Microsoft::Win32::RegistryValueKind::Unknown).ToString());
  }

  TEST(RegistryValueKindTest, String) {
    ASSERT_EQ(1, (int32)Microsoft::Win32::RegistryValueKind::String);
    ASSERT_EQ("String", Enum<Microsoft::Win32::RegistryValueKind>(Microsoft::Win32::RegistryValueKind::String).ToString());
  }

  TEST(RegistryValueKindTest, ExpandString) {
    ASSERT_EQ(2, (int32)Microsoft::Win32::RegistryValueKind::ExpandString);
    ASSERT_EQ("ExpandString", Enum<Microsoft::Win32::RegistryValueKind>(Microsoft::Win32::RegistryValueKind::ExpandString).ToString());
  }

  TEST(RegistryValueKindTest, Binary) {
    ASSERT_EQ(3, (int32)Microsoft::Win32::RegistryValueKind::Binary);
    ASSERT_EQ("Binary", Enum<Microsoft::Win32::RegistryValueKind>(Microsoft::Win32::RegistryValueKind::Binary).ToString());
  }

  TEST(RegistryValueKindTest, DWord) {
    ASSERT_EQ(4, (int32)Microsoft::Win32::RegistryValueKind::DWord);
    ASSERT_EQ("DWord", Enum<Microsoft::Win32::RegistryValueKind>(Microsoft::Win32::RegistryValueKind::DWord).ToString());
  }

  TEST(RegistryValueKindTest, MultiString) {
    ASSERT_EQ(7, (int32)Microsoft::Win32::RegistryValueKind::MultiString);
    ASSERT_EQ("MultiString", Enum<Microsoft::Win32::RegistryValueKind>(Microsoft::Win32::RegistryValueKind::MultiString).ToString());
  }

  TEST(RegistryValueKindTest, QWord) {
    ASSERT_EQ(11, (int32)Microsoft::Win32::RegistryValueKind::QWord);
    ASSERT_EQ("QWord", Enum<Microsoft::Win32::RegistryValueKind>(Microsoft::Win32::RegistryValueKind::QWord).ToString());
  }
}
