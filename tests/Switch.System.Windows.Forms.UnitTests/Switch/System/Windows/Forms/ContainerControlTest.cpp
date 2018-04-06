#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/ContainerControl.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(ContainerControlTest, DefaultConstructor) {
    ContainerControl containerControl;

    ASSERT_EQ(Point(0, 0), containerControl.Location);
    ASSERT_EQ(Size(0, 0), containerControl.Size);
    ASSERT_EQ("", containerControl.Text);
  }

  TEST(ContainerControlTest, ConstructorWithNameLeftTopHeightWidth) {
    ContainerControl containerControl("containerControl", 1, 2, 3, 4);

    ASSERT_EQ(Point(1, 2), containerControl.Location);
    ASSERT_EQ(Size(3, 4), containerControl.Size);
    ASSERT_EQ("containerControl", containerControl.Text);
  }
}
