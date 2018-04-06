#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/CheckBox.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(CheckBoxTest, DefaultConstructor) {
    CheckBox checkBox;

    ASSERT_EQ(Point(0, 0), checkBox.Location);
    ASSERT_EQ(Size(104, 24), checkBox.Size);
    ASSERT_EQ("", checkBox.Text);

    ASSERT_TRUE(checkBox.AutoCheck);
    ASSERT_FALSE(checkBox.Checked);
    ASSERT_EQ(CheckState::Unchecked, checkBox.CheckState);
  }

  TEST(CheckBoxTest, AutoCheck) {
    CheckBox checkBox;
    checkBox.AutoCheck = false;

    ASSERT_FALSE(checkBox.AutoCheck);
  }

  TEST(CheckBoxTest, Checked) {
    CheckBox checkBox;
    int32 result = 1;
    checkBox.CheckedChanged += delegate_(const object & sender, const EventArgs & e) {
      ASSERT_TRUE(object::ReferenceEquals(sender, checkBox));
      result += 2;
    };
    checkBox.CheckStateChanged += delegate_(const object & sender, const EventArgs & e) {
      ASSERT_TRUE(object::ReferenceEquals(sender, checkBox));
      result += 3;
    };

    checkBox.Checked = true;

    ASSERT_TRUE(checkBox.Checked);
    ASSERT_EQ(CheckState::Checked, checkBox.CheckState);
    ASSERT_EQ(6, result);
  }

  TEST(CheckBoxTest, CheckState) {
    CheckBox checkBox;
    int32 result = 1;
    checkBox.CheckedChanged += delegate_(const object & sender, const EventArgs & e) {
      ASSERT_TRUE(object::ReferenceEquals(sender, checkBox));
      result += 2;
    };
    checkBox.CheckStateChanged += delegate_(const object & sender, const EventArgs & e) {
      ASSERT_TRUE(object::ReferenceEquals(sender, checkBox));
      result += 3;
    };

    checkBox.CheckState = CheckState::Checked;

    ASSERT_EQ(CheckState::Checked, checkBox.CheckState);
    ASSERT_TRUE(checkBox.Checked);
    ASSERT_EQ(6, result);
  }

  TEST(CheckBoxTest, CheckStateWithBadValue) {
    CheckBox checkBox;

    ASSERT_THROW(checkBox.CheckState = (CheckState)42, System::ComponentModel::InvalidEnumArgumentException);
  }
}
