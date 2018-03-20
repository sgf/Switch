#include <Switch/System/Enum.hpp>
#include <Switch/Microsoft/Win32/RegistryOptions.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace Microsoft::Win32;
using namespace System;

namespace SwitchUnitTests {
  TEST(RegistryOptionsTest, None) {
    ASSERT_EQ(0, (int32)RegistryOptions::None);
    ASSERT_EQ("None", Enum<RegistryOptions>(RegistryOptions::None).ToString());
  }

  TEST(RegistryOptionsTest, Volatile) {
    ASSERT_EQ(1, (int32)RegistryOptions::Volatile);
    ASSERT_EQ("Volatile", Enum<RegistryOptions>(RegistryOptions::Volatile).ToString());
  }
}
