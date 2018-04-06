#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/ButtonBase.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  class ButtonBase1 : public ButtonBase {
  public:
    ButtonBase1() {}
    ButtonBase1(const string& text, int32 left, int32 top, int32 height, int32 width) : ButtonBase(text, left, top, height, width) {}
  };

  TEST(ButtonBaseTest, DefaultConstructor) {
    ButtonBase1 buttonBase1;

    ASSERT_EQ(Point(0, 0), buttonBase1.Location);
    ASSERT_EQ(Size(0, 0), buttonBase1.Size);
    ASSERT_EQ("", buttonBase1.Text);

    ASSERT_FALSE(buttonBase1.IsDefault);
  }

  TEST(ButtonBaseTest, ConstructorWithNameLeftTopHeightWidth) {
    ButtonBase1 buttonBase1("button", 1, 2, 3, 4);

    ASSERT_EQ(Point(1, 2), buttonBase1.Location);
    ASSERT_EQ(Size(3, 4), buttonBase1.Size);
    ASSERT_EQ("button", buttonBase1.Text);

    ASSERT_FALSE(buttonBase1.IsDefault);
  }

  TEST(ButtonBaseTest, IsDefault) {
    ButtonBase1 buttonBase1;

    buttonBase1.IsDefault = true;

    ASSERT_TRUE(buttonBase1.IsDefault);
  }
}
