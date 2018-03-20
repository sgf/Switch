#include <Switch/System/Enum.hpp>
#include <Switch/System/DayOfWeek.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(DayOfWeekTest, Sunday) {
    ASSERT_EQ(0, (int32)DayOfWeek::Sunday);
    ASSERT_EQ("Sunday", Enum<DayOfWeek>(DayOfWeek::Sunday).ToString());
  }

  TEST(DayOfWeekTest, Monday) {
    ASSERT_EQ(1, (int32)DayOfWeek::Monday);
    ASSERT_EQ("Monday", Enum<DayOfWeek>(DayOfWeek::Monday).ToString());
  }

  TEST(DayOfWeekTest, Tuesday) {
    ASSERT_EQ(2, (int32)DayOfWeek::Tuesday);
    ASSERT_EQ("Tuesday", Enum<DayOfWeek>(DayOfWeek::Tuesday).ToString());
  }

  TEST(DayOfWeekTest, Wednesday) {
    ASSERT_EQ(3, (int32)DayOfWeek::Wednesday);
    ASSERT_EQ("Wednesday", Enum<DayOfWeek>(DayOfWeek::Wednesday).ToString());
  }

  TEST(DayOfWeekTest, Thursday) {
    ASSERT_EQ(4, (int32)DayOfWeek::Thursday);
    ASSERT_EQ("Thursday", Enum<DayOfWeek>(DayOfWeek::Thursday).ToString());
  }

  TEST(DayOfWeekTest, Friday) {
    ASSERT_EQ(5, (int32)DayOfWeek::Friday);
    ASSERT_EQ("Friday", Enum<DayOfWeek>(DayOfWeek::Friday).ToString());
  }

  TEST(DayOfWeekTest, Saturday) {
    ASSERT_EQ(6, (int32)DayOfWeek::Saturday);
    ASSERT_EQ("Saturday", Enum<DayOfWeek>(DayOfWeek::Saturday).ToString());
  }
}
