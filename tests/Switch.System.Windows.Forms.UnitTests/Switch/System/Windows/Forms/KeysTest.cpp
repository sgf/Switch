#include <Switch/System/Windows/Forms/Keys.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(KeysTest, None) {
    ASSERT_EQ(0, (int32)System::Windows::Forms::Keys::None);
    ASSERT_EQ("None", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::None).ToString());
  }

  TEST(KeysTest, LButton) {
    ASSERT_EQ(1, (int32)System::Windows::Forms::Keys::LButton);
    ASSERT_EQ("LButton", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LButton).ToString());
  }

  TEST(KeysTest, RButton) {
    ASSERT_EQ(2, (int32)System::Windows::Forms::Keys::RButton);
    ASSERT_EQ("RButton", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::RButton).ToString());
  }

  TEST(KeysTest, Cancel) {
    ASSERT_EQ(3, (int32)System::Windows::Forms::Keys::Cancel);
    ASSERT_EQ("Cancel", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Cancel).ToString());
  }

  TEST(KeysTest, XButton1) {
    ASSERT_EQ(5, (int32)System::Windows::Forms::Keys::XButton1);
    ASSERT_EQ("XButton1", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::XButton1).ToString());
  }

  TEST(KeysTest, XButton2) {
    ASSERT_EQ(6, (int32)System::Windows::Forms::Keys::XButton2);
    ASSERT_EQ("XButton2", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::XButton2).ToString());
  }

  TEST(KeysTest, Back) {
    ASSERT_EQ(8, (int32)System::Windows::Forms::Keys::Back);
    ASSERT_EQ("Back", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Back).ToString());
  }

  TEST(KeysTest, Tab) {
    ASSERT_EQ(9, (int32)System::Windows::Forms::Keys::Tab);
    ASSERT_EQ("Tab", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Tab).ToString());
  }

  TEST(KeysTest, LineFeed) {
    ASSERT_EQ(10, (int32)System::Windows::Forms::Keys::LineFeed);
    ASSERT_EQ("LineFeed", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LineFeed).ToString());
  }

  TEST(KeysTest, Clear) {
    ASSERT_EQ(12, (int32)System::Windows::Forms::Keys::Clear);
    ASSERT_EQ("Clear", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Clear).ToString());
  }

  TEST(KeysTest, Return) {
    ASSERT_EQ(13, (int32)System::Windows::Forms::Keys::Return);
    ASSERT_EQ("Return", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Return).ToString());
  }

  TEST(KeysTest, ShiftKey) {
    ASSERT_EQ(16, (int32)System::Windows::Forms::Keys::ShiftKey);
    ASSERT_EQ("ShiftKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::ShiftKey).ToString());
  }

  TEST(KeysTest, ControlKey) {
    ASSERT_EQ(17, (int32)System::Windows::Forms::Keys::ControlKey);
    ASSERT_EQ("ControlKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::ControlKey).ToString());
  }

  TEST(KeysTest, Menu) {
    ASSERT_EQ(18, (int32)System::Windows::Forms::Keys::Menu);
    ASSERT_EQ("Menu", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Menu).ToString());
  }

  TEST(KeysTest, Pause) {
    ASSERT_EQ(19, (int32)System::Windows::Forms::Keys::Pause);
    ASSERT_EQ("Pause", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Pause).ToString());
  }

  TEST(KeysTest, CapsLock) {
    ASSERT_EQ(20, (int32)System::Windows::Forms::Keys::CapsLock);
    ASSERT_EQ("CapsLock", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::CapsLock).ToString());
  }

  TEST(KeysTest, KanaMode) {
    ASSERT_EQ(21, (int32)System::Windows::Forms::Keys::KanaMode);
    ASSERT_EQ("KanaMode", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::KanaMode).ToString());
  }

  TEST(KeysTest, JunjaMode) {
    ASSERT_EQ(23, (int32)System::Windows::Forms::Keys::JunjaMode);
    ASSERT_EQ("JunjaMode", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::JunjaMode).ToString());
  }

  TEST(KeysTest, FinalMode) {
    ASSERT_EQ(24, (int32)System::Windows::Forms::Keys::FinalMode);
    ASSERT_EQ("FinalMode", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::FinalMode).ToString());
  }

  TEST(KeysTest, KanjiMode) {
    ASSERT_EQ(25, (int32)System::Windows::Forms::Keys::KanjiMode);
    ASSERT_EQ("KanjiMode", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::KanjiMode).ToString());
  }

  TEST(KeysTest, Escape) {
    ASSERT_EQ(27, (int32)System::Windows::Forms::Keys::Escape);
    ASSERT_EQ("Escape", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Escape).ToString());
  }

  TEST(KeysTest, IMEConvert) {
    ASSERT_EQ(28, (int32)System::Windows::Forms::Keys::IMEConvert);
    ASSERT_EQ("IMEConvert", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::IMEConvert).ToString());
  }

  TEST(KeysTest, IMENonconvert) {
    ASSERT_EQ(29, (int32)System::Windows::Forms::Keys::IMENonconvert);
    ASSERT_EQ("IMENonconvert", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::IMENonconvert).ToString());
  }

  TEST(KeysTest, IMEAccept) {
    ASSERT_EQ(30, (int32)System::Windows::Forms::Keys::IMEAccept);
    ASSERT_EQ("IMEAccept", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::IMEAccept).ToString());
  }

  TEST(KeysTest, IMEModeChange) {
    ASSERT_EQ(31, (int32)System::Windows::Forms::Keys::IMEModeChange);
    ASSERT_EQ("IMEModeChange", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::IMEModeChange).ToString());
  }

  TEST(KeysTest, Space) {
    ASSERT_EQ(32, (int32)System::Windows::Forms::Keys::Space);
    ASSERT_EQ("Space", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Space).ToString());
  }

  TEST(KeysTest, PageUp) {
    ASSERT_EQ(33, (int32)System::Windows::Forms::Keys::PageUp);
    ASSERT_EQ("PageUp", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::PageUp).ToString());
  }

  TEST(KeysTest, PageDown) {
    ASSERT_EQ(34, (int32)System::Windows::Forms::Keys::PageDown);
    ASSERT_EQ("PageDown", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::PageDown).ToString());
  }

  TEST(KeysTest, End) {
    ASSERT_EQ(35, (int32)System::Windows::Forms::Keys::End);
    ASSERT_EQ("End", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::End).ToString());
  }

  TEST(KeysTest, Home) {
    ASSERT_EQ(36, (int32)System::Windows::Forms::Keys::Home);
    ASSERT_EQ("Home", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Home).ToString());
  }

  TEST(KeysTest, Left) {
    ASSERT_EQ(37, (int32)System::Windows::Forms::Keys::Left);
    ASSERT_EQ("Left", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Left).ToString());
  }

  TEST(KeysTest, Up) {
    ASSERT_EQ(38, (int32)System::Windows::Forms::Keys::Up);
    ASSERT_EQ("Up", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Up).ToString());
  }

  TEST(KeysTest, Right) {
    ASSERT_EQ(39, (int32)System::Windows::Forms::Keys::Right);
    ASSERT_EQ("Right", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Right).ToString());
  }

  TEST(KeysTest, Down) {
    ASSERT_EQ(40, (int32)System::Windows::Forms::Keys::Down);
    ASSERT_EQ("Down", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Down).ToString());
  }

  TEST(KeysTest, Select) {
    ASSERT_EQ(41, (int32)System::Windows::Forms::Keys::Select);
    ASSERT_EQ("Select", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Select).ToString());
  }

  TEST(KeysTest, Print) {
    ASSERT_EQ(42, (int32)System::Windows::Forms::Keys::Print);
    ASSERT_EQ("Print", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Print).ToString());
  }

  TEST(KeysTest, Execute) {
    ASSERT_EQ(43, (int32)System::Windows::Forms::Keys::Execute);
    ASSERT_EQ("Execute", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Execute).ToString());
  }

  TEST(KeysTest, PrintScreen) {
    ASSERT_EQ(44, (int32)System::Windows::Forms::Keys::PrintScreen);
    ASSERT_EQ("PrintScreen", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::PrintScreen).ToString());
  }

  TEST(KeysTest, Insert) {
    ASSERT_EQ(45, (int32)System::Windows::Forms::Keys::Insert);
    ASSERT_EQ("Insert", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Insert).ToString());
  }

  TEST(KeysTest, Delete) {
    ASSERT_EQ(46, (int32)System::Windows::Forms::Keys::Delete);
    ASSERT_EQ("Delete", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Delete).ToString());
  }

  TEST(KeysTest, Help) {
    ASSERT_EQ(47, (int32)System::Windows::Forms::Keys::Help);
    ASSERT_EQ("Help", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Help).ToString());
  }

  TEST(KeysTest, D0) {
    ASSERT_EQ(48, (int32)System::Windows::Forms::Keys::D0);
    ASSERT_EQ("D0", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D0).ToString());
  }

  TEST(KeysTest, D1) {
    ASSERT_EQ(49, (int32)System::Windows::Forms::Keys::D1);
    ASSERT_EQ("D1", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D1).ToString());
  }

  TEST(KeysTest, D2) {
    ASSERT_EQ(50, (int32)System::Windows::Forms::Keys::D2);
    ASSERT_EQ("D2", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D2).ToString());
  }

  TEST(KeysTest, D3) {
    ASSERT_EQ(51, (int32)System::Windows::Forms::Keys::D3);
    ASSERT_EQ("D3", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D3).ToString());
  }

  TEST(KeysTest, D4) {
    ASSERT_EQ(52, (int32)System::Windows::Forms::Keys::D4);
    ASSERT_EQ("D4", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D4).ToString());
  }

  TEST(KeysTest, D5) {
    ASSERT_EQ(53, (int32)System::Windows::Forms::Keys::D5);
    ASSERT_EQ("D5", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D5).ToString());
  }

  TEST(KeysTest, D6) {
    ASSERT_EQ(54, (int32)System::Windows::Forms::Keys::D6);
    ASSERT_EQ("D6", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D6).ToString());
  }

  TEST(KeysTest, D7) {
    ASSERT_EQ(55, (int32)System::Windows::Forms::Keys::D7);
    ASSERT_EQ("D7", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D7).ToString());
  }

  TEST(KeysTest, D8) {
    ASSERT_EQ(56, (int32)System::Windows::Forms::Keys::D8);
    ASSERT_EQ("D8", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D8).ToString());
  }

  TEST(KeysTest, D9) {
    ASSERT_EQ(57, (int32)System::Windows::Forms::Keys::D9);
    ASSERT_EQ("D9", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D9).ToString());
  }

  TEST(KeysTest, A) {
    ASSERT_EQ(65, (int32)System::Windows::Forms::Keys::A);
    ASSERT_EQ("A", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::A).ToString());
  }

  TEST(KeysTest, B) {
    ASSERT_EQ(66, (int32)System::Windows::Forms::Keys::B);
    ASSERT_EQ("B", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::B).ToString());
  }

  TEST(KeysTest, C) {
    ASSERT_EQ(67, (int32)System::Windows::Forms::Keys::C);
    ASSERT_EQ("C", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::C).ToString());
  }

  TEST(KeysTest, D) {
    ASSERT_EQ(68, (int32)System::Windows::Forms::Keys::D);
    ASSERT_EQ("D", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::D).ToString());
  }

  TEST(KeysTest, E) {
    ASSERT_EQ(69, (int32)System::Windows::Forms::Keys::E);
    ASSERT_EQ("E", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::E).ToString());
  }

  TEST(KeysTest, F) {
    ASSERT_EQ(70, (int32)System::Windows::Forms::Keys::F);
    ASSERT_EQ("F", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F).ToString());
  }

  TEST(KeysTest, G) {
    ASSERT_EQ(71, (int32)System::Windows::Forms::Keys::G);
    ASSERT_EQ("G", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::G).ToString());
  }

  TEST(KeysTest, H) {
    ASSERT_EQ(72, (int32)System::Windows::Forms::Keys::H);
    ASSERT_EQ("H", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::H).ToString());
  }

  TEST(KeysTest, I) {
    ASSERT_EQ(73, (int32)System::Windows::Forms::Keys::I);
    ASSERT_EQ("I", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::I).ToString());
  }

  TEST(KeysTest, J) {
    ASSERT_EQ(74, (int32)System::Windows::Forms::Keys::J);
    ASSERT_EQ("J", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::J).ToString());
  }

  TEST(KeysTest, K) {
    ASSERT_EQ(75, (int32)System::Windows::Forms::Keys::K);
    ASSERT_EQ("K", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::K).ToString());
  }

  TEST(KeysTest, L) {
    ASSERT_EQ(76, (int32)System::Windows::Forms::Keys::L);
    ASSERT_EQ("L", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::L).ToString());
  }

  TEST(KeysTest, M) {
    ASSERT_EQ(77, (int32)System::Windows::Forms::Keys::M);
    ASSERT_EQ("M", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::M).ToString());
  }

  TEST(KeysTest, N) {
    ASSERT_EQ(78, (int32)System::Windows::Forms::Keys::N);
    ASSERT_EQ("N", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::N).ToString());
  }

  TEST(KeysTest, O) {
    ASSERT_EQ(79, (int32)System::Windows::Forms::Keys::O);
    ASSERT_EQ("O", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::O).ToString());
  }

  TEST(KeysTest, P) {
    ASSERT_EQ(80, (int32)System::Windows::Forms::Keys::P);
    ASSERT_EQ("P", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::P).ToString());
  }

  TEST(KeysTest, Q) {
    ASSERT_EQ(81, (int32)System::Windows::Forms::Keys::Q);
    ASSERT_EQ("Q", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Q).ToString());
  }

  TEST(KeysTest, R) {
    ASSERT_EQ(82, (int32)System::Windows::Forms::Keys::R);
    ASSERT_EQ("R", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::R).ToString());
  }

  TEST(KeysTest, S) {
    ASSERT_EQ(83, (int32)System::Windows::Forms::Keys::S);
    ASSERT_EQ("S", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::S).ToString());
  }

  TEST(KeysTest, T) {
    ASSERT_EQ(84, (int32)System::Windows::Forms::Keys::T);
    ASSERT_EQ("T", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::T).ToString());
  }

  TEST(KeysTest, U) {
    ASSERT_EQ(85, (int32)System::Windows::Forms::Keys::U);
    ASSERT_EQ("U", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::U).ToString());
  }

  TEST(KeysTest, V) {
    ASSERT_EQ(86, (int32)System::Windows::Forms::Keys::V);
    ASSERT_EQ("V", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::V).ToString());
  }

  TEST(KeysTest, W) {
    ASSERT_EQ(87, (int32)System::Windows::Forms::Keys::W);
    ASSERT_EQ("W", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::W).ToString());
  }

  TEST(KeysTest, X) {
    ASSERT_EQ(88, (int32)System::Windows::Forms::Keys::X);
    ASSERT_EQ("X", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::X).ToString());
  }

  TEST(KeysTest, Y) {
    ASSERT_EQ(89, (int32)System::Windows::Forms::Keys::Y);
    ASSERT_EQ("Y", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Y).ToString());
  }

  TEST(KeysTest, Z) {
    ASSERT_EQ(90, (int32)System::Windows::Forms::Keys::Z);
    ASSERT_EQ("Z", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Z).ToString());
  }

  TEST(KeysTest, LWin) {
    ASSERT_EQ(91, (int32)System::Windows::Forms::Keys::LWin);
    ASSERT_EQ("LWin", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LWin).ToString());
  }

  TEST(KeysTest, RWin) {
    ASSERT_EQ(92, (int32)System::Windows::Forms::Keys::RWin);
    ASSERT_EQ("RWin", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::RWin).ToString());
  }

  TEST(KeysTest, Apps) {
    ASSERT_EQ(93, (int32)System::Windows::Forms::Keys::Apps);
    ASSERT_EQ("Apps", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Apps).ToString());
  }

  TEST(KeysTest, Sleep) {
    ASSERT_EQ(95, (int32)System::Windows::Forms::Keys::Sleep);
    ASSERT_EQ("Sleep", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Sleep).ToString());
  }

  TEST(KeysTest, NumPad0) {
    ASSERT_EQ(96, (int32)System::Windows::Forms::Keys::NumPad0);
    ASSERT_EQ("NumPad0", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad0).ToString());
  }

  TEST(KeysTest, NumPad1) {
    ASSERT_EQ(97, (int32)System::Windows::Forms::Keys::NumPad1);
    ASSERT_EQ("NumPad1", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad1).ToString());
  }

  TEST(KeysTest, NumPad2) {
    ASSERT_EQ(98, (int32)System::Windows::Forms::Keys::NumPad2);
    ASSERT_EQ("NumPad2", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad2).ToString());
  }

  TEST(KeysTest, NumPad3) {
    ASSERT_EQ(99, (int32)System::Windows::Forms::Keys::NumPad3);
    ASSERT_EQ("NumPad3", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad3).ToString());
  }

  TEST(KeysTest, NumPad4) {
    ASSERT_EQ(100, (int32)System::Windows::Forms::Keys::NumPad4);
    ASSERT_EQ("NumPad4", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad4).ToString());
  }

  TEST(KeysTest, NumPad5) {
    ASSERT_EQ(101, (int32)System::Windows::Forms::Keys::NumPad5);
    ASSERT_EQ("NumPad5", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad5).ToString());
  }

  TEST(KeysTest, NumPad6) {
    ASSERT_EQ(102, (int32)System::Windows::Forms::Keys::NumPad6);
    ASSERT_EQ("NumPad6", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad6).ToString());
  }

  TEST(KeysTest, NumPad7) {
    ASSERT_EQ(103, (int32)System::Windows::Forms::Keys::NumPad7);
    ASSERT_EQ("NumPad7", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad7).ToString());
  }

  TEST(KeysTest, NumPad8) {
    ASSERT_EQ(104, (int32)System::Windows::Forms::Keys::NumPad8);
    ASSERT_EQ("NumPad8", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad8).ToString());
  }

  TEST(KeysTest, NumPad9) {
    ASSERT_EQ(105, (int32)System::Windows::Forms::Keys::NumPad9);
    ASSERT_EQ("NumPad9", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumPad9).ToString());
  }

  TEST(KeysTest, Multiply) {
    ASSERT_EQ(106, (int32)System::Windows::Forms::Keys::Multiply);
    ASSERT_EQ("Multiply", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Multiply).ToString());
  }

  TEST(KeysTest, Add) {
    ASSERT_EQ(107, (int32)System::Windows::Forms::Keys::Add);
    ASSERT_EQ("Add", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Add).ToString());
  }

  TEST(KeysTest, Separator) {
    ASSERT_EQ(108, (int32)System::Windows::Forms::Keys::Separator);
    ASSERT_EQ("Separator", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Separator).ToString());
  }

  TEST(KeysTest, Subtract) {
    ASSERT_EQ(109, (int32)System::Windows::Forms::Keys::Subtract);
    ASSERT_EQ("Subtract", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Subtract).ToString());
  }

  TEST(KeysTest, Decimal) {
    ASSERT_EQ(110, (int32)System::Windows::Forms::Keys::Decimal);
    ASSERT_EQ("Decimal", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Decimal).ToString());
  }

  TEST(KeysTest, Divide) {
    ASSERT_EQ(111, (int32)System::Windows::Forms::Keys::Divide);
    ASSERT_EQ("Divide", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Divide).ToString());
  }

  TEST(KeysTest, F1) {
    ASSERT_EQ(112, (int32)System::Windows::Forms::Keys::F1);
    ASSERT_EQ("F1", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F1).ToString());
  }

  TEST(KeysTest, F2) {
    ASSERT_EQ(113, (int32)System::Windows::Forms::Keys::F2);
    ASSERT_EQ("F2", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F2).ToString());
  }

  TEST(KeysTest, F3) {
    ASSERT_EQ(114, (int32)System::Windows::Forms::Keys::F3);
    ASSERT_EQ("F3", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F3).ToString());
  }

  TEST(KeysTest, F4) {
    ASSERT_EQ(115, (int32)System::Windows::Forms::Keys::F4);
    ASSERT_EQ("F4", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F4).ToString());
  }

  TEST(KeysTest, F5) {
    ASSERT_EQ(116, (int32)System::Windows::Forms::Keys::F5);
    ASSERT_EQ("F5", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F5).ToString());
  }

  TEST(KeysTest, F6) {
    ASSERT_EQ(117, (int32)System::Windows::Forms::Keys::F6);
    ASSERT_EQ("F6", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F6).ToString());
  }

  TEST(KeysTest, F7) {
    ASSERT_EQ(118, (int32)System::Windows::Forms::Keys::F7);
    ASSERT_EQ("F7", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F7).ToString());
  }

  TEST(KeysTest, F8) {
    ASSERT_EQ(119, (int32)System::Windows::Forms::Keys::F8);
    ASSERT_EQ("F8", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F8).ToString());
  }

  TEST(KeysTest, F9) {
    ASSERT_EQ(120, (int32)System::Windows::Forms::Keys::F9);
    ASSERT_EQ("F9", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F9).ToString());
  }

  TEST(KeysTest, F10) {
    ASSERT_EQ(121, (int32)System::Windows::Forms::Keys::F10);
    ASSERT_EQ("F10", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F10).ToString());
  }

  TEST(KeysTest, F11) {
    ASSERT_EQ(122, (int32)System::Windows::Forms::Keys::F11);
    ASSERT_EQ("F11", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F11).ToString());
  }

  TEST(KeysTest, F12) {
    ASSERT_EQ(123, (int32)System::Windows::Forms::Keys::F12);
    ASSERT_EQ("F12", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F12).ToString());
  }

  TEST(KeysTest, F13) {
    ASSERT_EQ(124, (int32)System::Windows::Forms::Keys::F13);
    ASSERT_EQ("F13", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F13).ToString());
  }

  TEST(KeysTest, F14) {
    ASSERT_EQ(125, (int32)System::Windows::Forms::Keys::F14);
    ASSERT_EQ("F14", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F14).ToString());
  }

  TEST(KeysTest, F15) {
    ASSERT_EQ(126, (int32)System::Windows::Forms::Keys::F15);
    ASSERT_EQ("F15", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F15).ToString());
  }

  TEST(KeysTest, F16) {
    ASSERT_EQ(127, (int32)System::Windows::Forms::Keys::F16);
    ASSERT_EQ("F16", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F16).ToString());
  }

  TEST(KeysTest, F17) {
    ASSERT_EQ(128, (int32)System::Windows::Forms::Keys::F17);
    ASSERT_EQ("F17", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F17).ToString());
  }

  TEST(KeysTest, F18) {
    ASSERT_EQ(129, (int32)System::Windows::Forms::Keys::F18);
    ASSERT_EQ("F18", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F18).ToString());
  }

  TEST(KeysTest, F19) {
    ASSERT_EQ(130, (int32)System::Windows::Forms::Keys::F19);
    ASSERT_EQ("F19", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F19).ToString());
  }

  TEST(KeysTest, F20) {
    ASSERT_EQ(131, (int32)System::Windows::Forms::Keys::F20);
    ASSERT_EQ("F20", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F20).ToString());
  }

  TEST(KeysTest, F21) {
    ASSERT_EQ(132, (int32)System::Windows::Forms::Keys::F21);
    ASSERT_EQ("F21", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F21).ToString());
  }

  TEST(KeysTest, F22) {
    ASSERT_EQ(133, (int32)System::Windows::Forms::Keys::F22);
    ASSERT_EQ("F22", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F22).ToString());
  }

  TEST(KeysTest, F23) {
    ASSERT_EQ(134, (int32)System::Windows::Forms::Keys::F23);
    ASSERT_EQ("F23", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F23).ToString());
  }

  TEST(KeysTest, F24) {
    ASSERT_EQ(135, (int32)System::Windows::Forms::Keys::F24);
    ASSERT_EQ("F24", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::F24).ToString());
  }

  TEST(KeysTest, NumLock) {
    ASSERT_EQ(144, (int32)System::Windows::Forms::Keys::NumLock);
    ASSERT_EQ("NumLock", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NumLock).ToString());
  }

  TEST(KeysTest, Scroll) {
    ASSERT_EQ(145, (int32)System::Windows::Forms::Keys::Scroll);
    ASSERT_EQ("Scroll", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Scroll).ToString());
  }

  TEST(KeysTest, LShiftKey) {
    ASSERT_EQ(160, (int32)System::Windows::Forms::Keys::LShiftKey);
    ASSERT_EQ("LShiftKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LShiftKey).ToString());
  }

  TEST(KeysTest, RShiftKey) {
    ASSERT_EQ(161, (int32)System::Windows::Forms::Keys::RShiftKey);
    ASSERT_EQ("RShiftKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::RShiftKey).ToString());
  }

  TEST(KeysTest, LControlKey) {
    ASSERT_EQ(162, (int32)System::Windows::Forms::Keys::LControlKey);
    ASSERT_EQ("LControlKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LControlKey).ToString());
  }

  TEST(KeysTest, RControlKey) {
    ASSERT_EQ(163, (int32)System::Windows::Forms::Keys::RControlKey);
    ASSERT_EQ("RControlKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::RControlKey).ToString());
  }

  TEST(KeysTest, LMenu) {
    ASSERT_EQ(164, (int32)System::Windows::Forms::Keys::LMenu);
    ASSERT_EQ("LMenu", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LMenu).ToString());
  }

  TEST(KeysTest, RMenu) {
    ASSERT_EQ(165, (int32)System::Windows::Forms::Keys::RMenu);
    ASSERT_EQ("RMenu", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::RMenu).ToString());
  }

  TEST(KeysTest, BrowserBack) {
    ASSERT_EQ(166, (int32)System::Windows::Forms::Keys::BrowserBack);
    ASSERT_EQ("BrowserBack", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::BrowserBack).ToString());
  }

  TEST(KeysTest, BrowserForward) {
    ASSERT_EQ(167, (int32)System::Windows::Forms::Keys::BrowserForward);
    ASSERT_EQ("BrowserForward", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::BrowserForward).ToString());
  }

  TEST(KeysTest, BrowserRefresh) {
    ASSERT_EQ(168, (int32)System::Windows::Forms::Keys::BrowserRefresh);
    ASSERT_EQ("BrowserRefresh", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::BrowserRefresh).ToString());
  }

  TEST(KeysTest, BrowserStop) {
    ASSERT_EQ(169, (int32)System::Windows::Forms::Keys::BrowserStop);
    ASSERT_EQ("BrowserStop", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::BrowserStop).ToString());
  }

  TEST(KeysTest, BrowserSearch) {
    ASSERT_EQ(170, (int32)System::Windows::Forms::Keys::BrowserSearch);
    ASSERT_EQ("BrowserSearch", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::BrowserSearch).ToString());
  }

  TEST(KeysTest, BrowserFavorites) {
    ASSERT_EQ(171, (int32)System::Windows::Forms::Keys::BrowserFavorites);
    ASSERT_EQ("BrowserFavorites", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::BrowserFavorites).ToString());
  }

  TEST(KeysTest, BrowserHome) {
    ASSERT_EQ(172, (int32)System::Windows::Forms::Keys::BrowserHome);
    ASSERT_EQ("BrowserHome", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::BrowserHome).ToString());
  }

  TEST(KeysTest, VolumeMute) {
    ASSERT_EQ(173, (int32)System::Windows::Forms::Keys::VolumeMute);
    ASSERT_EQ("VolumeMute", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::VolumeMute).ToString());
  }

  TEST(KeysTest, VolumeDown) {
    ASSERT_EQ(174, (int32)System::Windows::Forms::Keys::VolumeDown);
    ASSERT_EQ("VolumeDown", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::VolumeDown).ToString());
  }

  TEST(KeysTest, VolumeUp) {
    ASSERT_EQ(175, (int32)System::Windows::Forms::Keys::VolumeUp);
    ASSERT_EQ("VolumeUp", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::VolumeUp).ToString());
  }

  TEST(KeysTest, MediaNextTrack) {
    ASSERT_EQ(176, (int32)System::Windows::Forms::Keys::MediaNextTrack);
    ASSERT_EQ("MediaNextTrack", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::MediaNextTrack).ToString());
  }

  TEST(KeysTest, MediaPreviousTrack) {
    ASSERT_EQ(177, (int32)System::Windows::Forms::Keys::MediaPreviousTrack);
    ASSERT_EQ("MediaPreviousTrack", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::MediaPreviousTrack).ToString());
  }

  TEST(KeysTest, MediaStop) {
    ASSERT_EQ(178, (int32)System::Windows::Forms::Keys::MediaStop);
    ASSERT_EQ("MediaStop", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::MediaStop).ToString());
  }

  TEST(KeysTest, MediaPlayPause) {
    ASSERT_EQ(179, (int32)System::Windows::Forms::Keys::MediaPlayPause);
    ASSERT_EQ("MediaPlayPause", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::MediaPlayPause).ToString());
  }

  TEST(KeysTest, LaunchMail) {
    ASSERT_EQ(180, (int32)System::Windows::Forms::Keys::LaunchMail);
    ASSERT_EQ("LaunchMail", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LaunchMail).ToString());
  }

  TEST(KeysTest, SelectMedia) {
    ASSERT_EQ(181, (int32)System::Windows::Forms::Keys::SelectMedia);
    ASSERT_EQ("SelectMedia", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::SelectMedia).ToString());
  }

  TEST(KeysTest, LaunchApplication1) {
    ASSERT_EQ(182, (int32)System::Windows::Forms::Keys::LaunchApplication1);
    ASSERT_EQ("LaunchApplication1", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LaunchApplication1).ToString());
  }

  TEST(KeysTest, LaunchApplication2) {
    ASSERT_EQ(183, (int32)System::Windows::Forms::Keys::LaunchApplication2);
    ASSERT_EQ("LaunchApplication2", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LaunchApplication2).ToString());
  }

  TEST(KeysTest, Oem1) {
    ASSERT_EQ(186, (int32)System::Windows::Forms::Keys::Oem1);
    ASSERT_EQ("Oem1", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Oem1).ToString());
  }

  TEST(KeysTest, Oemplus) {
    ASSERT_EQ(187, (int32)System::Windows::Forms::Keys::Oemplus);
    ASSERT_EQ("Oemplus", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Oemplus).ToString());
  }

  TEST(KeysTest, Oemcomma) {
    ASSERT_EQ(188, (int32)System::Windows::Forms::Keys::Oemcomma);
    ASSERT_EQ("Oemcomma", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Oemcomma).ToString());
  }

  TEST(KeysTest, OemMinus) {
    ASSERT_EQ(189, (int32)System::Windows::Forms::Keys::OemMinus);
    ASSERT_EQ("OemMinus", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::OemMinus).ToString());
  }

  TEST(KeysTest, OemPeriod) {
    ASSERT_EQ(190, (int32)System::Windows::Forms::Keys::OemPeriod);
    ASSERT_EQ("OemPeriod", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::OemPeriod).ToString());
  }

  TEST(KeysTest, OemQuestion) {
    ASSERT_EQ(191, (int32)System::Windows::Forms::Keys::OemQuestion);
    ASSERT_EQ("OemQuestion", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::OemQuestion).ToString());
  }

  TEST(KeysTest, Oemtilde) {
    ASSERT_EQ(192, (int32)System::Windows::Forms::Keys::Oemtilde);
    ASSERT_EQ("Oemtilde", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Oemtilde).ToString());
  }

  TEST(KeysTest, OemOpenBrackets) {
    ASSERT_EQ(219, (int32)System::Windows::Forms::Keys::OemOpenBrackets);
    ASSERT_EQ("OemOpenBrackets", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::OemOpenBrackets).ToString());
  }

  TEST(KeysTest, OemPipe) {
    ASSERT_EQ(220, (int32)System::Windows::Forms::Keys::OemPipe);
    ASSERT_EQ("OemPipe", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::OemPipe).ToString());
  }

  TEST(KeysTest, OemCloseBrackets) {
    ASSERT_EQ(221, (int32)System::Windows::Forms::Keys::OemCloseBrackets);
    ASSERT_EQ("OemCloseBrackets", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::OemCloseBrackets).ToString());
  }

  TEST(KeysTest, OemQuotes) {
    ASSERT_EQ(222, (int32)System::Windows::Forms::Keys::OemQuotes);
    ASSERT_EQ("OemQuotes", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::OemQuotes).ToString());
  }

  TEST(KeysTest, Oem8) {
    ASSERT_EQ(223, (int32)System::Windows::Forms::Keys::Oem8);
    ASSERT_EQ("Oem8", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Oem8).ToString());
  }

  TEST(KeysTest, OemBackslash) {
    ASSERT_EQ(226, (int32)System::Windows::Forms::Keys::OemBackslash);
    ASSERT_EQ("OemBackslash", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::OemBackslash).ToString());
  }

  TEST(KeysTest, ProcessKey) {
    ASSERT_EQ(229, (int32)System::Windows::Forms::Keys::ProcessKey);
    ASSERT_EQ("ProcessKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::ProcessKey).ToString());
  }

  TEST(KeysTest, Packet) {
    ASSERT_EQ(231, (int32)System::Windows::Forms::Keys::Packet);
    ASSERT_EQ("Packet", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Packet).ToString());
  }

  TEST(KeysTest, Attn) {
    ASSERT_EQ(246, (int32)System::Windows::Forms::Keys::Attn);
    ASSERT_EQ("Attn", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Attn).ToString());
  }

  TEST(KeysTest, Crsel) {
    ASSERT_EQ(247, (int32)System::Windows::Forms::Keys::Crsel);
    ASSERT_EQ("Crsel", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Crsel).ToString());
  }

  TEST(KeysTest, Exsel) {
    ASSERT_EQ(248, (int32)System::Windows::Forms::Keys::Exsel);
    ASSERT_EQ("Exsel", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Exsel).ToString());
  }

  TEST(KeysTest, EraseEof) {
    ASSERT_EQ(249, (int32)System::Windows::Forms::Keys::EraseEof);
    ASSERT_EQ("EraseEof", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::EraseEof).ToString());
  }

  TEST(KeysTest, Play) {
    ASSERT_EQ(250, (int32)System::Windows::Forms::Keys::Play);
    ASSERT_EQ("Play", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Play).ToString());
  }

  TEST(KeysTest, Zoom) {
    ASSERT_EQ(251, (int32)System::Windows::Forms::Keys::Zoom);
    ASSERT_EQ("Zoom", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Zoom).ToString());
  }

  TEST(KeysTest, NoName) {
    ASSERT_EQ(252, (int32)System::Windows::Forms::Keys::NoName);
    ASSERT_EQ("NoName", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::NoName).ToString());
  }

  TEST(KeysTest, Pa1) {
    ASSERT_EQ(253, (int32)System::Windows::Forms::Keys::Pa1);
    ASSERT_EQ("Pa1", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Pa1).ToString());
  }

  TEST(KeysTest, OemClear) {
    ASSERT_EQ(254, (int32)System::Windows::Forms::Keys::OemClear);
    ASSERT_EQ("OemClear", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::OemClear).ToString());
  }

  TEST(KeysTest, CommandKey) {
    ASSERT_EQ(255, (int32)System::Windows::Forms::Keys::CommandKey);
    ASSERT_EQ("CommandKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::CommandKey).ToString());
  }

  TEST(KeysTest, LCommandKey) {
    ASSERT_EQ(256, (int32)System::Windows::Forms::Keys::LCommandKey);
    ASSERT_EQ("LCommandKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::LCommandKey).ToString());
  }

  TEST(KeysTest, RCommandKey) {
    ASSERT_EQ(257, (int32)System::Windows::Forms::Keys::RCommandKey);
    ASSERT_EQ("RCommandKey", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::RCommandKey).ToString());
  }

  TEST(KeysTest, KeyCode) {
    ASSERT_EQ(65535, (int32)System::Windows::Forms::Keys::KeyCode);
    ASSERT_EQ("KeyCode", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::KeyCode).ToString());
  }

  TEST(KeysTest, Shift) {
    ASSERT_EQ(65536, (int32)System::Windows::Forms::Keys::Shift);
    ASSERT_EQ("Shift", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Shift).ToString());
  }

  TEST(KeysTest, Control) {
    ASSERT_EQ(131072, (int32)System::Windows::Forms::Keys::Control);
    ASSERT_EQ("Control", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Control).ToString());
  }

  TEST(KeysTest, Alt) {
    ASSERT_EQ(262144, (int32)System::Windows::Forms::Keys::Alt);
    ASSERT_EQ("Alt", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Alt).ToString());
  }

  TEST(KeysTest, Command) {
    ASSERT_EQ(524288, (int32)System::Windows::Forms::Keys::Command);
    ASSERT_EQ("Command", System::Enum<System::Windows::Forms::Keys>(System::Windows::Forms::Keys::Command).ToString());
  }
}
