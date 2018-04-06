#include <Switch/System/Windows/Forms/DialogResult.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(DialogResultTest, None) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::DialogResult::None);
    ASSERT_EQ("None", System::Enum<System::Windows::Forms::DialogResult>(System::Windows::Forms::DialogResult::None).ToString());
  }
  
  TEST(DialogResultTest, OK) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::DialogResult::OK);
    ASSERT_EQ("OK", System::Enum<System::Windows::Forms::DialogResult>(System::Windows::Forms::DialogResult::OK).ToString());
  }
  
  TEST(DialogResultTest, Cancel) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::DialogResult::Cancel);
    ASSERT_EQ("Cancel", System::Enum<System::Windows::Forms::DialogResult>(System::Windows::Forms::DialogResult::Cancel).ToString());
  }
  
  TEST(DialogResultTest, Abort) {
    ASSERT_EQ(3, (int32)System::Windows::Forms::DialogResult::Abort);
    ASSERT_EQ("Abort", System::Enum<System::Windows::Forms::DialogResult>(System::Windows::Forms::DialogResult::Abort).ToString());
  }
  
  TEST(DialogResultTest, Retry) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::DialogResult::Retry);
    ASSERT_EQ("Retry", System::Enum<System::Windows::Forms::DialogResult>(System::Windows::Forms::DialogResult::Retry).ToString());
  }
  
  TEST(DialogResultTest, Ignore) {
    ASSERT_EQ(5, (int32)System::Windows::Forms::DialogResult::Ignore);
    ASSERT_EQ("Ignore", System::Enum<System::Windows::Forms::DialogResult>(System::Windows::Forms::DialogResult::Ignore).ToString());
  }
  
  TEST(DialogResultTest, Yes) {
    ASSERT_EQ(6, (int32)System::Windows::Forms::DialogResult::Yes);
    ASSERT_EQ("Yes", System::Enum<System::Windows::Forms::DialogResult>(System::Windows::Forms::DialogResult::Yes).ToString());
  }
  
  TEST(DialogResultTest, No) {
    ASSERT_EQ(7, (int32)System::Windows::Forms::DialogResult::No);
    ASSERT_EQ("No", System::Enum<System::Windows::Forms::DialogResult>(System::Windows::Forms::DialogResult::No).ToString());
  }
}
