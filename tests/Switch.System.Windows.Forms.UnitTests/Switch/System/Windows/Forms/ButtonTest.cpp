#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/Button.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(ButtonTest, DefaultConstructor) {
    Button button;

    ASSERT_EQ(Point(0, 0), button.Location);
    if (System::Environment::OSVersion().IsAppleFamilly)
      ASSERT_EQ(Size(91, 32), button.Size);
    else
      ASSERT_EQ(Size(75, 25), button.Size);
    ASSERT_EQ("", button.Text);
  }
}
