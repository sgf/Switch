#include <Switch/System/Windows/Forms/DataFormats.hpp>
#include <gtest/gtest.h>

using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(DataFormatsFormatTest, DefaultConstructor) {
    DataFormats::Format format;
    
    ASSERT_EQ(0, format.Id);
    ASSERT_EQ("", format.Name);
  }
  
  TEST(DataFormatsFormatTest, Constructor) {
    DataFormats::Format format("Value", 42);
    
    ASSERT_EQ(42, format.Id);
    ASSERT_EQ("Value", format.Name);
  }
  
  TEST(DataFormatsFormatTest, CopyConstructor) {
    DataFormats::Format format = DataFormats::Format("Value", 42);
    
    ASSERT_EQ(42, format.Id);
    ASSERT_EQ("Value", format.Name);
  }
  
  TEST(DataFormatsFormatTest, CopyOperator) {
    DataFormats::Format format;
    format = DataFormats::Format("Value", 42);
    
    ASSERT_EQ(42, format.Id);
    ASSERT_EQ("Value", format.Name);
  }
}

