#include <Switch/System/Windows/Forms/DragDropEffects.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(DragDropEffectsTest, None) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::DragDropEffects::None);
    ASSERT_EQ("None", System::Enum<System::Windows::Forms::DragDropEffects>(System::Windows::Forms::DragDropEffects::None).ToString());
  }

  TEST(DragDropEffectsTest, Copy) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::DragDropEffects::Copy);
    ASSERT_EQ("Copy", System::Enum<System::Windows::Forms::DragDropEffects>(System::Windows::Forms::DragDropEffects::Copy).ToString());
  }

  TEST(DragDropEffectsTest, Link) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::DragDropEffects::Link);
    ASSERT_EQ("Link", System::Enum<System::Windows::Forms::DragDropEffects>(System::Windows::Forms::DragDropEffects::Link).ToString());
  }

  TEST(DragDropEffectsTest, Move) {
    ASSERT_EQ(16, (int32)System::Windows::Forms::DragDropEffects::Move);
    ASSERT_EQ("Move", System::Enum<System::Windows::Forms::DragDropEffects>(System::Windows::Forms::DragDropEffects::Move).ToString());
  }

  TEST(DragDropEffectsTest, Scroll) {
    ASSERT_EQ(32768, (int32)System::Windows::Forms::DragDropEffects::Scroll);
    ASSERT_EQ("Scroll", System::Enum<System::Windows::Forms::DragDropEffects>(System::Windows::Forms::DragDropEffects::Scroll).ToString());
  }

  TEST(DragDropEffectsTest, All) {
    ASSERT_EQ(32775, (int32)System::Windows::Forms::DragDropEffects::All);
    ASSERT_EQ("All", System::Enum<System::Windows::Forms::DragDropEffects>(System::Windows::Forms::DragDropEffects::All).ToString());
  }
}
