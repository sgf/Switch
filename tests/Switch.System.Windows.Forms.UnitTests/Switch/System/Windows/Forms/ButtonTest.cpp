#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/Button.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(ButtonTest, DefaultConstructor) {
    Button button;

    ASSERT_FALSE(button.IsDefault);
    ASSERT_EQ(Point(0, 0), button.Location);
    ASSERT_EQ(Size(75, 25), button.Size);
    ASSERT_EQ("", button.Text);
  }

  TEST(ButtonTest, IsDefault) {
    Button button;

    button.IsDefault = true;

    ASSERT_TRUE(button.IsDefault);
  }
}

