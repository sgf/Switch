#include <Switch/System/Windows/Forms/ControlStyles.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(ControlStylesTest, ContainerControl) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::ControlStyles::ContainerControl);
    ASSERT_EQ("ContainerControl", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::ContainerControl).ToString());
  }
  
  TEST(ControlStylesTest, UserPaint) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::ControlStyles::UserPaint);
    ASSERT_EQ("UserPaint", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::UserPaint).ToString());
  }
  
  TEST(ControlStylesTest, Opaque) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::ControlStyles::Opaque);
    ASSERT_EQ("Opaque", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::Opaque).ToString());
  }
  
  TEST(ControlStylesTest, ResizeRedraw) {
    ASSERT_EQ(16, (int32)System::Windows::Forms::ControlStyles::ResizeRedraw);
    ASSERT_EQ("ResizeRedraw", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::ResizeRedraw).ToString());
  }
  
  TEST(ControlStylesTest, FixedWidth) {
    ASSERT_EQ(32, (int32)System::Windows::Forms::ControlStyles::FixedWidth);
    ASSERT_EQ("FixedWidth", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::FixedWidth).ToString());
  }
  
  TEST(ControlStylesTest, FixedHeight) {
    ASSERT_EQ(64, (int32)System::Windows::Forms::ControlStyles::FixedHeight);
    ASSERT_EQ("FixedHeight", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::FixedHeight).ToString());
  }
  
  TEST(ControlStylesTest, StandardClick) {
    ASSERT_EQ(256, (int32)System::Windows::Forms::ControlStyles::StandardClick);
    ASSERT_EQ("StandardClick", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::StandardClick).ToString());
  }
  
  TEST(ControlStylesTest, Selectable) {
    ASSERT_EQ(512, (int32)System::Windows::Forms::ControlStyles::Selectable);
    ASSERT_EQ("Selectable", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::Selectable).ToString());
  }
  
  TEST(ControlStylesTest, UserMouse) {
    ASSERT_EQ(1024, (int32)System::Windows::Forms::ControlStyles::UserMouse);
    ASSERT_EQ("UserMouse", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::UserMouse).ToString());
  }
  
  TEST(ControlStylesTest, SupportsTransparentBackColor) {
    ASSERT_EQ(2048, (int32)System::Windows::Forms::ControlStyles::SupportsTransparentBackColor);
    ASSERT_EQ("SupportsTransparentBackColor", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::SupportsTransparentBackColor).ToString());
  }
  
  TEST(ControlStylesTest, StandardDoubleClick) {
    ASSERT_EQ(4096, (int32)System::Windows::Forms::ControlStyles::StandardDoubleClick);
    ASSERT_EQ("StandardDoubleClick", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::StandardDoubleClick).ToString());
  }
  
  TEST(ControlStylesTest, AllPaintingInWmPaint) {
    ASSERT_EQ(8192, (int32)System::Windows::Forms::ControlStyles::AllPaintingInWmPaint);
    ASSERT_EQ("AllPaintingInWmPaint", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::AllPaintingInWmPaint).ToString());
  }
  
  TEST(ControlStylesTest, CacheText) {
    ASSERT_EQ(16384, (int32)System::Windows::Forms::ControlStyles::CacheText);
    ASSERT_EQ("CacheText", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::CacheText).ToString());
  }
  
  TEST(ControlStylesTest, EnableNotifyMessage) {
    ASSERT_EQ(32768, (int32)System::Windows::Forms::ControlStyles::EnableNotifyMessage);
    ASSERT_EQ("EnableNotifyMessage", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::EnableNotifyMessage).ToString());
  }
  
  TEST(ControlStylesTest, DoubleBuffer) {
    ASSERT_EQ(65536, (int32)System::Windows::Forms::ControlStyles::DoubleBuffer);
    ASSERT_EQ("DoubleBuffer", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::DoubleBuffer).ToString());
  }
  
  TEST(ControlStylesTest, OptimizedDoubleBuffer) {
    ASSERT_EQ(131072, (int32)System::Windows::Forms::ControlStyles::OptimizedDoubleBuffer);
    ASSERT_EQ("OptimizedDoubleBuffer", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::OptimizedDoubleBuffer).ToString());
  }
  
  TEST(ControlStylesTest, UseTextForAccessibility) {
    ASSERT_EQ(262144, (int32)System::Windows::Forms::ControlStyles::UseTextForAccessibility);
    ASSERT_EQ("UseTextForAccessibility", System::Enum<System::Windows::Forms::ControlStyles>(System::Windows::Forms::ControlStyles::UseTextForAccessibility).ToString());
  }
}
