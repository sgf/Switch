#include <Switch/System/Windows/Forms/AccessibleNavigation.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(AccessibleNavigationTest, Up) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::AccessibleNavigation::Up);
    ASSERT_EQ("Up", System::Enum<System::Windows::Forms::AccessibleNavigation>(System::Windows::Forms::AccessibleNavigation::Up).ToString());
  }

  TEST(AccessibleNavigationTest, Down) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::AccessibleNavigation::Down);
    ASSERT_EQ("Down", System::Enum<System::Windows::Forms::AccessibleNavigation>(System::Windows::Forms::AccessibleNavigation::Down).ToString());
  }

  TEST(AccessibleNavigationTest, Left) {
    ASSERT_EQ(3, (int32)System::Windows::Forms::AccessibleNavigation::Left);
    ASSERT_EQ("Left", System::Enum<System::Windows::Forms::AccessibleNavigation>(System::Windows::Forms::AccessibleNavigation::Left).ToString());
  }

  TEST(AccessibleNavigationTest, Right) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::AccessibleNavigation::Right);
    ASSERT_EQ("Right", System::Enum<System::Windows::Forms::AccessibleNavigation>(System::Windows::Forms::AccessibleNavigation::Right).ToString());
  }

  TEST(AccessibleNavigationTest, Next) {
    ASSERT_EQ(5, (int32)System::Windows::Forms::AccessibleNavigation::Next);
    ASSERT_EQ("Next", System::Enum<System::Windows::Forms::AccessibleNavigation>(System::Windows::Forms::AccessibleNavigation::Next).ToString());
  }

  TEST(AccessibleNavigationTest, Previous) {
    ASSERT_EQ(6, (int32)System::Windows::Forms::AccessibleNavigation::Previous);
    ASSERT_EQ("Previous", System::Enum<System::Windows::Forms::AccessibleNavigation>(System::Windows::Forms::AccessibleNavigation::Previous).ToString());
  }

  TEST(AccessibleNavigationTest, FirstChild) {
    ASSERT_EQ(7, (int32)System::Windows::Forms::AccessibleNavigation::FirstChild);
    ASSERT_EQ("FirstChild", System::Enum<System::Windows::Forms::AccessibleNavigation>(System::Windows::Forms::AccessibleNavigation::FirstChild).ToString());
  }

  TEST(AccessibleNavigationTest, LastChild) {
    ASSERT_EQ(8, (int32)System::Windows::Forms::AccessibleNavigation::LastChild);
    ASSERT_EQ("LastChild", System::Enum<System::Windows::Forms::AccessibleNavigation>(System::Windows::Forms::AccessibleNavigation::LastChild).ToString());
  }
}
