#include <Switch/System/Enum.hpp>
#include <Switch/Microsoft/Win32/RegistryValueOptions.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace Microsoft::Win32;
using namespace System;

namespace SwitchUnitTests {
  TEST(RegistryValueOptionsTest, None) {
    ASSERT_EQ(0, (int32)RegistryValueOptions::None);
    ASSERT_EQ("None", Enum<RegistryValueOptions>(RegistryValueOptions::None).ToString());
  }

  TEST(RegistryValueOptionsTest, DoNotExpandEnvironmentNames) {
    ASSERT_EQ(1, (int32)RegistryValueOptions::DoNotExpandEnvironmentNames);
    ASSERT_EQ("DoNotExpandEnvironmentNames", Enum<RegistryValueOptions>(RegistryValueOptions::DoNotExpandEnvironmentNames).ToString());
  }
}
