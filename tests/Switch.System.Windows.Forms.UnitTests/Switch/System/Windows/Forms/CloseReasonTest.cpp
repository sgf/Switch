#include <Switch/System/Windows/Forms/CloseReason.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(CloseReasonTest, None) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::CloseReason::None);
    ASSERT_EQ("None", System::Enum<System::Windows::Forms::CloseReason>(System::Windows::Forms::CloseReason::None).ToString());
  }

  TEST(CloseReasonTest, WindowsShutDown) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::CloseReason::WindowsShutDown);
    ASSERT_EQ("WindowsShutDown", System::Enum<System::Windows::Forms::CloseReason>(System::Windows::Forms::CloseReason::WindowsShutDown).ToString());
  }

  TEST(CloseReasonTest, MdiFormClosing) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::CloseReason::MdiFormClosing);
    ASSERT_EQ("MdiFormClosing", System::Enum<System::Windows::Forms::CloseReason>(System::Windows::Forms::CloseReason::MdiFormClosing).ToString());
  }

  TEST(CloseReasonTest, UserClosing) {
    ASSERT_EQ(3, (int32)System::Windows::Forms::CloseReason::UserClosing);
    ASSERT_EQ("UserClosing", System::Enum<System::Windows::Forms::CloseReason>(System::Windows::Forms::CloseReason::UserClosing).ToString());
  }

  TEST(CloseReasonTest, TaskManagerClosing) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::CloseReason::TaskManagerClosing);
    ASSERT_EQ("TaskManagerClosing", System::Enum<System::Windows::Forms::CloseReason>(System::Windows::Forms::CloseReason::TaskManagerClosing).ToString());
  }

  TEST(CloseReasonTest, FormOwnerClosing) {
    ASSERT_EQ(5, (int32)System::Windows::Forms::CloseReason::FormOwnerClosing);
    ASSERT_EQ("FormOwnerClosing", System::Enum<System::Windows::Forms::CloseReason>(System::Windows::Forms::CloseReason::FormOwnerClosing).ToString());
  }

  TEST(CloseReasonTest, ApplicationExitCall) {
    ASSERT_EQ(6, (int32)System::Windows::Forms::CloseReason::ApplicationExitCall);
    ASSERT_EQ("ApplicationExitCall", System::Enum<System::Windows::Forms::CloseReason>(System::Windows::Forms::CloseReason::ApplicationExitCall).ToString());
  }
}
