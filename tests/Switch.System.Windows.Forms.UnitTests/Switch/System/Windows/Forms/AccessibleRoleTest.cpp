#include <Switch/System/Windows/Forms/AccessibleRole.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(AccessibleRoleTest, Default) {
    ASSERT_EQ(-1, (int32)System::Windows::Forms::AccessibleRole::Default);
    ASSERT_EQ("Default", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Default).ToString());
  }

  TEST(AccessibleRoleTest, None) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::AccessibleRole::None);
    ASSERT_EQ("None", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::None).ToString());
  }

  TEST(AccessibleRoleTest, TitleBar) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::AccessibleRole::TitleBar);
    ASSERT_EQ("TitleBar", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::TitleBar).ToString());
  }

  TEST(AccessibleRoleTest, MenuBar) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::AccessibleRole::MenuBar);
    ASSERT_EQ("MenuBar", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::MenuBar).ToString());
  }

  TEST(AccessibleRoleTest, ScrollBar) {
    ASSERT_EQ(3, (int32)System::Windows::Forms::AccessibleRole::ScrollBar);
    ASSERT_EQ("ScrollBar", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ScrollBar).ToString());
  }

  TEST(AccessibleRoleTest, Grip) {
    ASSERT_EQ(4, (int32)System::Windows::Forms::AccessibleRole::Grip);
    ASSERT_EQ("Grip", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Grip).ToString());
  }

  TEST(AccessibleRoleTest, Sound) {
    ASSERT_EQ(5, (int32)System::Windows::Forms::AccessibleRole::Sound);
    ASSERT_EQ("Sound", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Sound).ToString());
  }

  TEST(AccessibleRoleTest, Cursor) {
    ASSERT_EQ(6, (int32)System::Windows::Forms::AccessibleRole::Cursor);
    ASSERT_EQ("Cursor", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Cursor).ToString());
  }

  TEST(AccessibleRoleTest, Caret) {
    ASSERT_EQ(7, (int32)System::Windows::Forms::AccessibleRole::Caret);
    ASSERT_EQ("Caret", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Caret).ToString());
  }

  TEST(AccessibleRoleTest, Alert) {
    ASSERT_EQ(8, (int32)System::Windows::Forms::AccessibleRole::Alert);
    ASSERT_EQ("Alert", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Alert).ToString());
  }

  TEST(AccessibleRoleTest, Window) {
    ASSERT_EQ(9, (int32)System::Windows::Forms::AccessibleRole::Window);
    ASSERT_EQ("Window", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Window).ToString());
  }

  TEST(AccessibleRoleTest, Client) {
    ASSERT_EQ(10, (int32)System::Windows::Forms::AccessibleRole::Client);
    ASSERT_EQ("Client", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Client).ToString());
  }

  TEST(AccessibleRoleTest, MenuPopup) {
    ASSERT_EQ(11, (int32)System::Windows::Forms::AccessibleRole::MenuPopup);
    ASSERT_EQ("MenuPopup", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::MenuPopup).ToString());
  }

  TEST(AccessibleRoleTest, MenuItem) {
    ASSERT_EQ(12, (int32)System::Windows::Forms::AccessibleRole::MenuItem);
    ASSERT_EQ("MenuItem", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::MenuItem).ToString());
  }

  TEST(AccessibleRoleTest, ToolTip) {
    ASSERT_EQ(13, (int32)System::Windows::Forms::AccessibleRole::ToolTip);
    ASSERT_EQ("ToolTip", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ToolTip).ToString());
  }

  TEST(AccessibleRoleTest, Application) {
    ASSERT_EQ(14, (int32)System::Windows::Forms::AccessibleRole::Application);
    ASSERT_EQ("Application", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Application).ToString());
  }

  TEST(AccessibleRoleTest, Document) {
    ASSERT_EQ(15, (int32)System::Windows::Forms::AccessibleRole::Document);
    ASSERT_EQ("Document", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Document).ToString());
  }

  TEST(AccessibleRoleTest, Pane) {
    ASSERT_EQ(16, (int32)System::Windows::Forms::AccessibleRole::Pane);
    ASSERT_EQ("Pane", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Pane).ToString());
  }

  TEST(AccessibleRoleTest, Chart) {
    ASSERT_EQ(17, (int32)System::Windows::Forms::AccessibleRole::Chart);
    ASSERT_EQ("Chart", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Chart).ToString());
  }

  TEST(AccessibleRoleTest, Dialog) {
    ASSERT_EQ(18, (int32)System::Windows::Forms::AccessibleRole::Dialog);
    ASSERT_EQ("Dialog", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Dialog).ToString());
  }

  TEST(AccessibleRoleTest, Border) {
    ASSERT_EQ(19, (int32)System::Windows::Forms::AccessibleRole::Border);
    ASSERT_EQ("Border", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Border).ToString());
  }

  TEST(AccessibleRoleTest, Grouping) {
    ASSERT_EQ(20, (int32)System::Windows::Forms::AccessibleRole::Grouping);
    ASSERT_EQ("Grouping", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Grouping).ToString());
  }

  TEST(AccessibleRoleTest, Separator) {
    ASSERT_EQ(21, (int32)System::Windows::Forms::AccessibleRole::Separator);
    ASSERT_EQ("Separator", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Separator).ToString());
  }

  TEST(AccessibleRoleTest, ToolBar) {
    ASSERT_EQ(22, (int32)System::Windows::Forms::AccessibleRole::ToolBar);
    ASSERT_EQ("ToolBar", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ToolBar).ToString());
  }

  TEST(AccessibleRoleTest, StatusBar) {
    ASSERT_EQ(23, (int32)System::Windows::Forms::AccessibleRole::StatusBar);
    ASSERT_EQ("StatusBar", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::StatusBar).ToString());
  }

  TEST(AccessibleRoleTest, Table) {
    ASSERT_EQ(24, (int32)System::Windows::Forms::AccessibleRole::Table);
    ASSERT_EQ("Table", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Table).ToString());
  }

  TEST(AccessibleRoleTest, ColumnHeader) {
    ASSERT_EQ(25, (int32)System::Windows::Forms::AccessibleRole::ColumnHeader);
    ASSERT_EQ("ColumnHeader", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ColumnHeader).ToString());
  }

  TEST(AccessibleRoleTest, RowHeader) {
    ASSERT_EQ(26, (int32)System::Windows::Forms::AccessibleRole::RowHeader);
    ASSERT_EQ("RowHeader", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::RowHeader).ToString());
  }

  TEST(AccessibleRoleTest, Column) {
    ASSERT_EQ(27, (int32)System::Windows::Forms::AccessibleRole::Column);
    ASSERT_EQ("Column", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Column).ToString());
  }

  TEST(AccessibleRoleTest, Row) {
    ASSERT_EQ(28, (int32)System::Windows::Forms::AccessibleRole::Row);
    ASSERT_EQ("Row", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Row).ToString());
  }

  TEST(AccessibleRoleTest, Cell) {
    ASSERT_EQ(29, (int32)System::Windows::Forms::AccessibleRole::Cell);
    ASSERT_EQ("Cell", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Cell).ToString());
  }

  TEST(AccessibleRoleTest, Link) {
    ASSERT_EQ(30, (int32)System::Windows::Forms::AccessibleRole::Link);
    ASSERT_EQ("Link", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Link).ToString());
  }

  TEST(AccessibleRoleTest, HelpBalloon) {
    ASSERT_EQ(31, (int32)System::Windows::Forms::AccessibleRole::HelpBalloon);
    ASSERT_EQ("HelpBalloon", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::HelpBalloon).ToString());
  }

  TEST(AccessibleRoleTest, Character) {
    ASSERT_EQ(32, (int32)System::Windows::Forms::AccessibleRole::Character);
    ASSERT_EQ("Character", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Character).ToString());
  }

  TEST(AccessibleRoleTest, List) {
    ASSERT_EQ(33, (int32)System::Windows::Forms::AccessibleRole::List);
    ASSERT_EQ("List", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::List).ToString());
  }

  TEST(AccessibleRoleTest, ListItem) {
    ASSERT_EQ(34, (int32)System::Windows::Forms::AccessibleRole::ListItem);
    ASSERT_EQ("ListItem", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ListItem).ToString());
  }

  TEST(AccessibleRoleTest, Outline) {
    ASSERT_EQ(35, (int32)System::Windows::Forms::AccessibleRole::Outline);
    ASSERT_EQ("Outline", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Outline).ToString());
  }

  TEST(AccessibleRoleTest, OutlineItem) {
    ASSERT_EQ(36, (int32)System::Windows::Forms::AccessibleRole::OutlineItem);
    ASSERT_EQ("OutlineItem", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::OutlineItem).ToString());
  }

  TEST(AccessibleRoleTest, PageTab) {
    ASSERT_EQ(37, (int32)System::Windows::Forms::AccessibleRole::PageTab);
    ASSERT_EQ("PageTab", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::PageTab).ToString());
  }

  TEST(AccessibleRoleTest, PropertyPage) {
    ASSERT_EQ(38, (int32)System::Windows::Forms::AccessibleRole::PropertyPage);
    ASSERT_EQ("PropertyPage", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::PropertyPage).ToString());
  }

  TEST(AccessibleRoleTest, Indicator) {
    ASSERT_EQ(39, (int32)System::Windows::Forms::AccessibleRole::Indicator);
    ASSERT_EQ("Indicator", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Indicator).ToString());
  }

  TEST(AccessibleRoleTest, Graphic) {
    ASSERT_EQ(40, (int32)System::Windows::Forms::AccessibleRole::Graphic);
    ASSERT_EQ("Graphic", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Graphic).ToString());
  }

  TEST(AccessibleRoleTest, StaticText) {
    ASSERT_EQ(41, (int32)System::Windows::Forms::AccessibleRole::StaticText);
    ASSERT_EQ("StaticText", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::StaticText).ToString());
  }

  TEST(AccessibleRoleTest, PushButton) {
    ASSERT_EQ(43, (int32)System::Windows::Forms::AccessibleRole::PushButton);
    ASSERT_EQ("PushButton", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::PushButton).ToString());
  }

  TEST(AccessibleRoleTest, CheckButton) {
    ASSERT_EQ(44, (int32)System::Windows::Forms::AccessibleRole::CheckButton);
    ASSERT_EQ("CheckButton", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::CheckButton).ToString());
  }

  TEST(AccessibleRoleTest, RadioButton) {
    ASSERT_EQ(45, (int32)System::Windows::Forms::AccessibleRole::RadioButton);
    ASSERT_EQ("RadioButton", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::RadioButton).ToString());
  }

  TEST(AccessibleRoleTest, ComboBox) {
    ASSERT_EQ(46, (int32)System::Windows::Forms::AccessibleRole::ComboBox);
    ASSERT_EQ("ComboBox", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ComboBox).ToString());
  }

  TEST(AccessibleRoleTest, DropList) {
    ASSERT_EQ(47, (int32)System::Windows::Forms::AccessibleRole::DropList);
    ASSERT_EQ("DropList", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::DropList).ToString());
  }

  TEST(AccessibleRoleTest, ProgressBar) {
    ASSERT_EQ(48, (int32)System::Windows::Forms::AccessibleRole::ProgressBar);
    ASSERT_EQ("ProgressBar", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ProgressBar).ToString());
  }

  TEST(AccessibleRoleTest, Dial) {
    ASSERT_EQ(49, (int32)System::Windows::Forms::AccessibleRole::Dial);
    ASSERT_EQ("Dial", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Dial).ToString());
  }

  TEST(AccessibleRoleTest, HotkeyField) {
    ASSERT_EQ(50, (int32)System::Windows::Forms::AccessibleRole::HotkeyField);
    ASSERT_EQ("HotkeyField", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::HotkeyField).ToString());
  }

  TEST(AccessibleRoleTest, Slider) {
    ASSERT_EQ(51, (int32)System::Windows::Forms::AccessibleRole::Slider);
    ASSERT_EQ("Slider", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Slider).ToString());
  }

  TEST(AccessibleRoleTest, SpinButton) {
    ASSERT_EQ(52, (int32)System::Windows::Forms::AccessibleRole::SpinButton);
    ASSERT_EQ("SpinButton", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::SpinButton).ToString());
  }

  TEST(AccessibleRoleTest, Diagram) {
    ASSERT_EQ(53, (int32)System::Windows::Forms::AccessibleRole::Diagram);
    ASSERT_EQ("Diagram", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Diagram).ToString());
  }

  TEST(AccessibleRoleTest, Animation) {
    ASSERT_EQ(54, (int32)System::Windows::Forms::AccessibleRole::Animation);
    ASSERT_EQ("Animation", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Animation).ToString());
  }

  TEST(AccessibleRoleTest, Equation) {
    ASSERT_EQ(55, (int32)System::Windows::Forms::AccessibleRole::Equation);
    ASSERT_EQ("Equation", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Equation).ToString());
  }

  TEST(AccessibleRoleTest, ButtonDropDown) {
    ASSERT_EQ(56, (int32)System::Windows::Forms::AccessibleRole::ButtonDropDown);
    ASSERT_EQ("ButtonDropDown", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ButtonDropDown).ToString());
  }

  TEST(AccessibleRoleTest, ButtonMenu) {
    ASSERT_EQ(57, (int32)System::Windows::Forms::AccessibleRole::ButtonMenu);
    ASSERT_EQ("ButtonMenu", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ButtonMenu).ToString());
  }

  TEST(AccessibleRoleTest, ButtonDropDownGrid) {
    ASSERT_EQ(58, (int32)System::Windows::Forms::AccessibleRole::ButtonDropDownGrid);
    ASSERT_EQ("ButtonDropDownGrid", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::ButtonDropDownGrid).ToString());
  }

  TEST(AccessibleRoleTest, WhiteSpace) {
    ASSERT_EQ(59, (int32)System::Windows::Forms::AccessibleRole::WhiteSpace);
    ASSERT_EQ("WhiteSpace", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::WhiteSpace).ToString());
  }

  TEST(AccessibleRoleTest, PageTabList) {
    ASSERT_EQ(60, (int32)System::Windows::Forms::AccessibleRole::PageTabList);
    ASSERT_EQ("PageTabList", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::PageTabList).ToString());
  }

  TEST(AccessibleRoleTest, Clock) {
    ASSERT_EQ(61, (int32)System::Windows::Forms::AccessibleRole::Clock);
    ASSERT_EQ("Clock", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::Clock).ToString());
  }

  TEST(AccessibleRoleTest, SplitButton) {
    ASSERT_EQ(62, (int32)System::Windows::Forms::AccessibleRole::SplitButton);
    ASSERT_EQ("SplitButton", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::SplitButton).ToString());
  }

  TEST(AccessibleRoleTest, IpAddress) {
    ASSERT_EQ(63, (int32)System::Windows::Forms::AccessibleRole::IpAddress);
    ASSERT_EQ("IpAddress", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::IpAddress).ToString());
  }

  TEST(AccessibleRoleTest, OutlineButton) {
    ASSERT_EQ(64, (int32)System::Windows::Forms::AccessibleRole::OutlineButton);
    ASSERT_EQ("OutlineButton", System::Enum<System::Windows::Forms::AccessibleRole>(System::Windows::Forms::AccessibleRole::OutlineButton).ToString());
  }
}
