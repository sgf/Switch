#include <Switch/System/Enum.hpp>
#include <Switch/System/IO/SeekOrigin.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(SeekOriginTest, Begin) {
    ASSERT_EQ(0, (int32)System::IO::SeekOrigin::Begin);
    ASSERT_EQ("Begin", Enum<System::IO::SeekOrigin>(System::IO::SeekOrigin::Begin).ToString());
  }

  TEST(SeekOriginTest, Current) {
    ASSERT_EQ(1, (int32)System::IO::SeekOrigin::Current);
    ASSERT_EQ("Current", Enum<System::IO::SeekOrigin>(System::IO::SeekOrigin::Current).ToString());
  }

  TEST(SeekOriginTest, End) {
    ASSERT_EQ(2, (int32)System::IO::SeekOrigin::End);
    ASSERT_EQ("End", Enum<System::IO::SeekOrigin>(System::IO::SeekOrigin::End).ToString());
  }
}
