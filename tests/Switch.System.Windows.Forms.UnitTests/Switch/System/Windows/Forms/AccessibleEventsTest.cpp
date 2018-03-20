#include <Switch/System/Windows/Forms/AccessibleEvents.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(AccessibleEventsTest, SystemSound) {
    ASSERT_EQ(1, (int32)AccessibleEvents::SystemSound);
    ASSERT_EQ("SystemSound", Enum<AccessibleEvents>(AccessibleEvents::SystemSound).ToString());
  }
}
