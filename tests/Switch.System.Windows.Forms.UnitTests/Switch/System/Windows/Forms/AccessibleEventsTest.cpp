#include <Switch/System/Windows/Forms/AccessibleEvents.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(AccessibleEventsTest, SystemSound) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::AccessibleEvents::SystemSound);
    ASSERT_EQ("SystemSound", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemSound).ToString());
  }

  TEST(AccessibleEventsTest, SystemAlert) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::AccessibleEvents::SystemAlert);
    ASSERT_EQ("SystemAlert", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemAlert).ToString());
  }

  TEST(AccessibleEventsTest, SystemForeground) {
    ASSERT_EQ(3, (int32)System::Windows::Forms::AccessibleEvents::SystemForeground);
    ASSERT_EQ("SystemForeground", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemForeground).ToString());
  }

  TEST(AccessibleEventsTest, SystemMenuStart) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::AccessibleEvents::SystemMenuStart);
    ASSERT_EQ("SystemMenuStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemMenuStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemMenuEnd) {
    ASSERT_EQ(5, (int32)System::Windows::Forms::AccessibleEvents::SystemMenuEnd);
    ASSERT_EQ("SystemMenuEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemMenuEnd).ToString());
  }

  TEST(AccessibleEventsTest, SystemMenuPopupStart) {
    ASSERT_EQ(6, (int32)System::Windows::Forms::AccessibleEvents::SystemMenuPopupStart);
    ASSERT_EQ("SystemMenuPopupStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemMenuPopupStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemMenuPopupEnd) {
    ASSERT_EQ(7, (int32)System::Windows::Forms::AccessibleEvents::SystemMenuPopupEnd);
    ASSERT_EQ("SystemMenuPopupEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemMenuPopupEnd).ToString());
  }

  TEST(AccessibleEventsTest, SystemCaptureStart) {
    ASSERT_EQ(8, (int32)System::Windows::Forms::AccessibleEvents::SystemCaptureStart);
    ASSERT_EQ("SystemCaptureStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemCaptureStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemCaptureEnd) {
    ASSERT_EQ(9, (int32)System::Windows::Forms::AccessibleEvents::SystemCaptureEnd);
    ASSERT_EQ("SystemCaptureEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemCaptureEnd).ToString());
  }

  TEST(AccessibleEventsTest, SystemMoveSizeStart) {
    ASSERT_EQ(10, (int32)System::Windows::Forms::AccessibleEvents::SystemMoveSizeStart);
    ASSERT_EQ("SystemMoveSizeStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemMoveSizeStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemMoveSizeEnd) {
    ASSERT_EQ(11, (int32)System::Windows::Forms::AccessibleEvents::SystemMoveSizeEnd);
    ASSERT_EQ("SystemMoveSizeEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemMoveSizeEnd).ToString());
  }

  TEST(AccessibleEventsTest, SystemContextHelpStart) {
    ASSERT_EQ(12, (int32)System::Windows::Forms::AccessibleEvents::SystemContextHelpStart);
    ASSERT_EQ("SystemContextHelpStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemContextHelpStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemContextHelpEnd) {
    ASSERT_EQ(13, (int32)System::Windows::Forms::AccessibleEvents::SystemContextHelpEnd);
    ASSERT_EQ("SystemContextHelpEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemContextHelpEnd).ToString());
  }

  TEST(AccessibleEventsTest, SystemDragDropStart) {
    ASSERT_EQ(14, (int32)System::Windows::Forms::AccessibleEvents::SystemDragDropStart);
    ASSERT_EQ("SystemDragDropStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemDragDropStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemDragDropEnd) {
    ASSERT_EQ(15, (int32)System::Windows::Forms::AccessibleEvents::SystemDragDropEnd);
    ASSERT_EQ("SystemDragDropEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemDragDropEnd).ToString());
  }

  TEST(AccessibleEventsTest, SystemDialogStart) {
    ASSERT_EQ(16, (int32)System::Windows::Forms::AccessibleEvents::SystemDialogStart);
    ASSERT_EQ("SystemDialogStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemDialogStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemDialogEnd) {
    ASSERT_EQ(17, (int32)System::Windows::Forms::AccessibleEvents::SystemDialogEnd);
    ASSERT_EQ("SystemDialogEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemDialogEnd).ToString());
  }

  TEST(AccessibleEventsTest, SystemScrollingStart) {
    ASSERT_EQ(18, (int32)System::Windows::Forms::AccessibleEvents::SystemScrollingStart);
    ASSERT_EQ("SystemScrollingStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemScrollingStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemScrollingEnd) {
    ASSERT_EQ(19, (int32)System::Windows::Forms::AccessibleEvents::SystemScrollingEnd);
    ASSERT_EQ("SystemScrollingEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemScrollingEnd).ToString());
  }

  TEST(AccessibleEventsTest, SystemSwitchStart) {
    ASSERT_EQ(20, (int32)System::Windows::Forms::AccessibleEvents::SystemSwitchStart);
    ASSERT_EQ("SystemSwitchStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemSwitchStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemSwitchEnd) {
    ASSERT_EQ(21, (int32)System::Windows::Forms::AccessibleEvents::SystemSwitchEnd);
    ASSERT_EQ("SystemSwitchEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemSwitchEnd).ToString());
  }

  TEST(AccessibleEventsTest, SystemMinimizeStart) {
    ASSERT_EQ(22, (int32)System::Windows::Forms::AccessibleEvents::SystemMinimizeStart);
    ASSERT_EQ("SystemMinimizeStart", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemMinimizeStart).ToString());
  }

  TEST(AccessibleEventsTest, SystemMinimizeEnd) {
    ASSERT_EQ(23, (int32)System::Windows::Forms::AccessibleEvents::SystemMinimizeEnd);
    ASSERT_EQ("SystemMinimizeEnd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SystemMinimizeEnd).ToString());
  }

  TEST(AccessibleEventsTest, Create) {
    ASSERT_EQ(32768, (int32)System::Windows::Forms::AccessibleEvents::Create);
    ASSERT_EQ("Create", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::Create).ToString());
  }

  TEST(AccessibleEventsTest, Destroy) {
    ASSERT_EQ(32769, (int32)System::Windows::Forms::AccessibleEvents::Destroy);
    ASSERT_EQ("Destroy", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::Destroy).ToString());
  }

  TEST(AccessibleEventsTest, Show) {
    ASSERT_EQ(32770, (int32)System::Windows::Forms::AccessibleEvents::Show);
    ASSERT_EQ("Show", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::Show).ToString());
  }

  TEST(AccessibleEventsTest, Hide) {
    ASSERT_EQ(32771, (int32)System::Windows::Forms::AccessibleEvents::Hide);
    ASSERT_EQ("Hide", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::Hide).ToString());
  }

  TEST(AccessibleEventsTest, Reorder) {
    ASSERT_EQ(32772, (int32)System::Windows::Forms::AccessibleEvents::Reorder);
    ASSERT_EQ("Reorder", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::Reorder).ToString());
  }

  TEST(AccessibleEventsTest, Focus) {
    ASSERT_EQ(32773, (int32)System::Windows::Forms::AccessibleEvents::Focus);
    ASSERT_EQ("Focus", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::Focus).ToString());
  }

  TEST(AccessibleEventsTest, Selection) {
    ASSERT_EQ(32774, (int32)System::Windows::Forms::AccessibleEvents::Selection);
    ASSERT_EQ("Selection", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::Selection).ToString());
  }

  TEST(AccessibleEventsTest, SelectionAdd) {
    ASSERT_EQ(32775, (int32)System::Windows::Forms::AccessibleEvents::SelectionAdd);
    ASSERT_EQ("SelectionAdd", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SelectionAdd).ToString());
  }

  TEST(AccessibleEventsTest, SelectionRemove) {
    ASSERT_EQ(32776, (int32)System::Windows::Forms::AccessibleEvents::SelectionRemove);
    ASSERT_EQ("SelectionRemove", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SelectionRemove).ToString());
  }

  TEST(AccessibleEventsTest, SelectionWithin) {
    ASSERT_EQ(32777, (int32)System::Windows::Forms::AccessibleEvents::SelectionWithin);
    ASSERT_EQ("SelectionWithin", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::SelectionWithin).ToString());
  }

  TEST(AccessibleEventsTest, StateChange) {
    ASSERT_EQ(32778, (int32)System::Windows::Forms::AccessibleEvents::StateChange);
    ASSERT_EQ("StateChange", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::StateChange).ToString());
  }

  TEST(AccessibleEventsTest, LocationChange) {
    ASSERT_EQ(32779, (int32)System::Windows::Forms::AccessibleEvents::LocationChange);
    ASSERT_EQ("LocationChange", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::LocationChange).ToString());
  }

  TEST(AccessibleEventsTest, NameChange) {
    ASSERT_EQ(32780, (int32)System::Windows::Forms::AccessibleEvents::NameChange);
    ASSERT_EQ("NameChange", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::NameChange).ToString());
  }

  TEST(AccessibleEventsTest, DescriptionChange) {
    ASSERT_EQ(32781, (int32)System::Windows::Forms::AccessibleEvents::DescriptionChange);
    ASSERT_EQ("DescriptionChange", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::DescriptionChange).ToString());
  }

  TEST(AccessibleEventsTest, ValueChange) {
    ASSERT_EQ(32782, (int32)System::Windows::Forms::AccessibleEvents::ValueChange);
    ASSERT_EQ("ValueChange", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::ValueChange).ToString());
  }

  TEST(AccessibleEventsTest, ParentChange) {
    ASSERT_EQ(32783, (int32)System::Windows::Forms::AccessibleEvents::ParentChange);
    ASSERT_EQ("ParentChange", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::ParentChange).ToString());
  }

  TEST(AccessibleEventsTest, HelpChange) {
    ASSERT_EQ(32784, (int32)System::Windows::Forms::AccessibleEvents::HelpChange);
    ASSERT_EQ("HelpChange", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::HelpChange).ToString());
  }

  TEST(AccessibleEventsTest, DefaultActionChange) {
    ASSERT_EQ(32785, (int32)System::Windows::Forms::AccessibleEvents::DefaultActionChange);
    ASSERT_EQ("DefaultActionChange", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::DefaultActionChange).ToString());
  }

  TEST(AccessibleEventsTest, AcceleratorChange) {
    ASSERT_EQ(32786, (int32)System::Windows::Forms::AccessibleEvents::AcceleratorChange);
    ASSERT_EQ("AcceleratorChange", System::Enum<System::Windows::Forms::AccessibleEvents>(System::Windows::Forms::AccessibleEvents::AcceleratorChange).ToString());
  }
}
