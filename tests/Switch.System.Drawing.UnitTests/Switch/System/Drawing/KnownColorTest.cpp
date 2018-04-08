#include <Switch/System/Drawing/KnownColor.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(KnownColorTest, ActiveBorder) {
    ASSERT_EQ(1, (int32)System::Drawing::KnownColor::ActiveBorder);
    ASSERT_EQ("ActiveBorder", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ActiveBorder).ToString());
  }

  TEST(KnownColorTest, ActiveCaption) {
    ASSERT_EQ(2, (int32)System::Drawing::KnownColor::ActiveCaption);
    ASSERT_EQ("ActiveCaption", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ActiveCaption).ToString());
  }

  TEST(KnownColorTest, ActiveCaptionText) {
    ASSERT_EQ(3, (int32)System::Drawing::KnownColor::ActiveCaptionText);
    ASSERT_EQ("ActiveCaptionText", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ActiveCaptionText).ToString());
  }

  TEST(KnownColorTest, AppWorkspace) {
    ASSERT_EQ(4, (int32)System::Drawing::KnownColor::AppWorkspace);
    ASSERT_EQ("AppWorkspace", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::AppWorkspace).ToString());
  }

  TEST(KnownColorTest, Control) {
    ASSERT_EQ(5, (int32)System::Drawing::KnownColor::Control);
    ASSERT_EQ("Control", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Control).ToString());
  }

  TEST(KnownColorTest, ControlDark) {
    ASSERT_EQ(6, (int32)System::Drawing::KnownColor::ControlDark);
    ASSERT_EQ("ControlDark", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ControlDark).ToString());
  }

  TEST(KnownColorTest, ControlDarkDark) {
    ASSERT_EQ(7, (int32)System::Drawing::KnownColor::ControlDarkDark);
    ASSERT_EQ("ControlDarkDark", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ControlDarkDark).ToString());
  }

  TEST(KnownColorTest, ControlLight) {
    ASSERT_EQ(8, (int32)System::Drawing::KnownColor::ControlLight);
    ASSERT_EQ("ControlLight", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ControlLight).ToString());
  }

  TEST(KnownColorTest, ControlLightLight) {
    ASSERT_EQ(9, (int32)System::Drawing::KnownColor::ControlLightLight);
    ASSERT_EQ("ControlLightLight", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ControlLightLight).ToString());
  }

  TEST(KnownColorTest, ControlText) {
    ASSERT_EQ(10, (int32)System::Drawing::KnownColor::ControlText);
    ASSERT_EQ("ControlText", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ControlText).ToString());
  }

  TEST(KnownColorTest, Desktop) {
    ASSERT_EQ(11, (int32)System::Drawing::KnownColor::Desktop);
    ASSERT_EQ("Desktop", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Desktop).ToString());
  }

  TEST(KnownColorTest, GrayText) {
    ASSERT_EQ(12, (int32)System::Drawing::KnownColor::GrayText);
    ASSERT_EQ("GrayText", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::GrayText).ToString());
  }

  TEST(KnownColorTest, Highlight) {
    ASSERT_EQ(13, (int32)System::Drawing::KnownColor::Highlight);
    ASSERT_EQ("Highlight", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Highlight).ToString());
  }

  TEST(KnownColorTest, HighlightText) {
    ASSERT_EQ(14, (int32)System::Drawing::KnownColor::HighlightText);
    ASSERT_EQ("HighlightText", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::HighlightText).ToString());
  }

  TEST(KnownColorTest, HotTrack) {
    ASSERT_EQ(15, (int32)System::Drawing::KnownColor::HotTrack);
    ASSERT_EQ("HotTrack", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::HotTrack).ToString());
  }

  TEST(KnownColorTest, InactiveBorder) {
    ASSERT_EQ(16, (int32)System::Drawing::KnownColor::InactiveBorder);
    ASSERT_EQ("InactiveBorder", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::InactiveBorder).ToString());
  }

  TEST(KnownColorTest, InactiveCaption) {
    ASSERT_EQ(17, (int32)System::Drawing::KnownColor::InactiveCaption);
    ASSERT_EQ("InactiveCaption", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::InactiveCaption).ToString());
  }

  TEST(KnownColorTest, InactiveCaptionText) {
    ASSERT_EQ(18, (int32)System::Drawing::KnownColor::InactiveCaptionText);
    ASSERT_EQ("InactiveCaptionText", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::InactiveCaptionText).ToString());
  }

  TEST(KnownColorTest, Info) {
    ASSERT_EQ(19, (int32)System::Drawing::KnownColor::Info);
    ASSERT_EQ("Info", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Info).ToString());
  }

  TEST(KnownColorTest, InfoText) {
    ASSERT_EQ(20, (int32)System::Drawing::KnownColor::InfoText);
    ASSERT_EQ("InfoText", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::InfoText).ToString());
  }

  TEST(KnownColorTest, Menu) {
    ASSERT_EQ(21, (int32)System::Drawing::KnownColor::Menu);
    ASSERT_EQ("Menu", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Menu).ToString());
  }

  TEST(KnownColorTest, MenuText) {
    ASSERT_EQ(22, (int32)System::Drawing::KnownColor::MenuText);
    ASSERT_EQ("MenuText", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MenuText).ToString());
  }

  TEST(KnownColorTest, ScrollBar) {
    ASSERT_EQ(23, (int32)System::Drawing::KnownColor::ScrollBar);
    ASSERT_EQ("ScrollBar", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ScrollBar).ToString());
  }

  TEST(KnownColorTest, Window) {
    ASSERT_EQ(24, (int32)System::Drawing::KnownColor::Window);
    ASSERT_EQ("Window", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Window).ToString());
  }

  TEST(KnownColorTest, WindowFrame) {
    ASSERT_EQ(25, (int32)System::Drawing::KnownColor::WindowFrame);
    ASSERT_EQ("WindowFrame", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::WindowFrame).ToString());
  }

  TEST(KnownColorTest, WindowText) {
    ASSERT_EQ(26, (int32)System::Drawing::KnownColor::WindowText);
    ASSERT_EQ("WindowText", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::WindowText).ToString());
  }

  TEST(KnownColorTest, Transparent) {
    ASSERT_EQ(27, (int32)System::Drawing::KnownColor::Transparent);
    ASSERT_EQ("Transparent", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Transparent).ToString());
  }

  TEST(KnownColorTest, AliceBlue) {
    ASSERT_EQ(28, (int32)System::Drawing::KnownColor::AliceBlue);
    ASSERT_EQ("AliceBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::AliceBlue).ToString());
  }

  TEST(KnownColorTest, AntiqueWhite) {
    ASSERT_EQ(29, (int32)System::Drawing::KnownColor::AntiqueWhite);
    ASSERT_EQ("AntiqueWhite", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::AntiqueWhite).ToString());
  }

  TEST(KnownColorTest, Aqua) {
    ASSERT_EQ(30, (int32)System::Drawing::KnownColor::Aqua);
    ASSERT_EQ("Aqua", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Aqua).ToString());
  }

  TEST(KnownColorTest, Aquamarine) {
    ASSERT_EQ(31, (int32)System::Drawing::KnownColor::Aquamarine);
    ASSERT_EQ("Aquamarine", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Aquamarine).ToString());
  }

  TEST(KnownColorTest, Azure) {
    ASSERT_EQ(32, (int32)System::Drawing::KnownColor::Azure);
    ASSERT_EQ("Azure", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Azure).ToString());
  }

  TEST(KnownColorTest, Beige) {
    ASSERT_EQ(33, (int32)System::Drawing::KnownColor::Beige);
    ASSERT_EQ("Beige", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Beige).ToString());
  }

  TEST(KnownColorTest, Bisque) {
    ASSERT_EQ(34, (int32)System::Drawing::KnownColor::Bisque);
    ASSERT_EQ("Bisque", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Bisque).ToString());
  }

  TEST(KnownColorTest, Black) {
    ASSERT_EQ(35, (int32)System::Drawing::KnownColor::Black);
    ASSERT_EQ("Black", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Black).ToString());
  }

  TEST(KnownColorTest, BlanchedAlmond) {
    ASSERT_EQ(36, (int32)System::Drawing::KnownColor::BlanchedAlmond);
    ASSERT_EQ("BlanchedAlmond", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::BlanchedAlmond).ToString());
  }

  TEST(KnownColorTest, Blue) {
    ASSERT_EQ(37, (int32)System::Drawing::KnownColor::Blue);
    ASSERT_EQ("Blue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Blue).ToString());
  }

  TEST(KnownColorTest, BlueViolet) {
    ASSERT_EQ(38, (int32)System::Drawing::KnownColor::BlueViolet);
    ASSERT_EQ("BlueViolet", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::BlueViolet).ToString());
  }

  TEST(KnownColorTest, Brown) {
    ASSERT_EQ(39, (int32)System::Drawing::KnownColor::Brown);
    ASSERT_EQ("Brown", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Brown).ToString());
  }

  TEST(KnownColorTest, BurlyWood) {
    ASSERT_EQ(40, (int32)System::Drawing::KnownColor::BurlyWood);
    ASSERT_EQ("BurlyWood", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::BurlyWood).ToString());
  }

  TEST(KnownColorTest, CadetBlue) {
    ASSERT_EQ(41, (int32)System::Drawing::KnownColor::CadetBlue);
    ASSERT_EQ("CadetBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::CadetBlue).ToString());
  }

  TEST(KnownColorTest, Chartreuse) {
    ASSERT_EQ(42, (int32)System::Drawing::KnownColor::Chartreuse);
    ASSERT_EQ("Chartreuse", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Chartreuse).ToString());
  }

  TEST(KnownColorTest, Chocolate) {
    ASSERT_EQ(43, (int32)System::Drawing::KnownColor::Chocolate);
    ASSERT_EQ("Chocolate", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Chocolate).ToString());
  }

  TEST(KnownColorTest, Coral) {
    ASSERT_EQ(44, (int32)System::Drawing::KnownColor::Coral);
    ASSERT_EQ("Coral", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Coral).ToString());
  }

  TEST(KnownColorTest, CornflowerBlue) {
    ASSERT_EQ(45, (int32)System::Drawing::KnownColor::CornflowerBlue);
    ASSERT_EQ("CornflowerBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::CornflowerBlue).ToString());
  }

  TEST(KnownColorTest, Cornsilk) {
    ASSERT_EQ(46, (int32)System::Drawing::KnownColor::Cornsilk);
    ASSERT_EQ("Cornsilk", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Cornsilk).ToString());
  }

  TEST(KnownColorTest, Crimson) {
    ASSERT_EQ(47, (int32)System::Drawing::KnownColor::Crimson);
    ASSERT_EQ("Crimson", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Crimson).ToString());
  }

  TEST(KnownColorTest, Cyan) {
    ASSERT_EQ(48, (int32)System::Drawing::KnownColor::Cyan);
    ASSERT_EQ("Cyan", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Cyan).ToString());
  }

  TEST(KnownColorTest, DarkBlue) {
    ASSERT_EQ(49, (int32)System::Drawing::KnownColor::DarkBlue);
    ASSERT_EQ("DarkBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkBlue).ToString());
  }

  TEST(KnownColorTest, DarkCyan) {
    ASSERT_EQ(50, (int32)System::Drawing::KnownColor::DarkCyan);
    ASSERT_EQ("DarkCyan", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkCyan).ToString());
  }

  TEST(KnownColorTest, DarkGoldenrod) {
    ASSERT_EQ(51, (int32)System::Drawing::KnownColor::DarkGoldenrod);
    ASSERT_EQ("DarkGoldenrod", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkGoldenrod).ToString());
  }

  TEST(KnownColorTest, DarkGray) {
    ASSERT_EQ(52, (int32)System::Drawing::KnownColor::DarkGray);
    ASSERT_EQ("DarkGray", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkGray).ToString());
  }

  TEST(KnownColorTest, DarkGreen) {
    ASSERT_EQ(53, (int32)System::Drawing::KnownColor::DarkGreen);
    ASSERT_EQ("DarkGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkGreen).ToString());
  }

  TEST(KnownColorTest, DarkKhaki) {
    ASSERT_EQ(54, (int32)System::Drawing::KnownColor::DarkKhaki);
    ASSERT_EQ("DarkKhaki", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkKhaki).ToString());
  }

  TEST(KnownColorTest, DarkMagenta) {
    ASSERT_EQ(55, (int32)System::Drawing::KnownColor::DarkMagenta);
    ASSERT_EQ("DarkMagenta", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkMagenta).ToString());
  }

  TEST(KnownColorTest, DarkOliveGreen) {
    ASSERT_EQ(56, (int32)System::Drawing::KnownColor::DarkOliveGreen);
    ASSERT_EQ("DarkOliveGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkOliveGreen).ToString());
  }

  TEST(KnownColorTest, DarkOrange) {
    ASSERT_EQ(57, (int32)System::Drawing::KnownColor::DarkOrange);
    ASSERT_EQ("DarkOrange", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkOrange).ToString());
  }

  TEST(KnownColorTest, DarkOrchid) {
    ASSERT_EQ(58, (int32)System::Drawing::KnownColor::DarkOrchid);
    ASSERT_EQ("DarkOrchid", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkOrchid).ToString());
  }

  TEST(KnownColorTest, DarkRed) {
    ASSERT_EQ(59, (int32)System::Drawing::KnownColor::DarkRed);
    ASSERT_EQ("DarkRed", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkRed).ToString());
  }

  TEST(KnownColorTest, DarkSalmon) {
    ASSERT_EQ(60, (int32)System::Drawing::KnownColor::DarkSalmon);
    ASSERT_EQ("DarkSalmon", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkSalmon).ToString());
  }

  TEST(KnownColorTest, DarkSeaGreen) {
    ASSERT_EQ(61, (int32)System::Drawing::KnownColor::DarkSeaGreen);
    ASSERT_EQ("DarkSeaGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkSeaGreen).ToString());
  }

  TEST(KnownColorTest, DarkSlateBlue) {
    ASSERT_EQ(62, (int32)System::Drawing::KnownColor::DarkSlateBlue);
    ASSERT_EQ("DarkSlateBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkSlateBlue).ToString());
  }

  TEST(KnownColorTest, DarkSlateGray) {
    ASSERT_EQ(63, (int32)System::Drawing::KnownColor::DarkSlateGray);
    ASSERT_EQ("DarkSlateGray", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkSlateGray).ToString());
  }

  TEST(KnownColorTest, DarkTurquoise) {
    ASSERT_EQ(64, (int32)System::Drawing::KnownColor::DarkTurquoise);
    ASSERT_EQ("DarkTurquoise", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkTurquoise).ToString());
  }

  TEST(KnownColorTest, DarkViolet) {
    ASSERT_EQ(65, (int32)System::Drawing::KnownColor::DarkViolet);
    ASSERT_EQ("DarkViolet", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DarkViolet).ToString());
  }

  TEST(KnownColorTest, DeepPink) {
    ASSERT_EQ(66, (int32)System::Drawing::KnownColor::DeepPink);
    ASSERT_EQ("DeepPink", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DeepPink).ToString());
  }

  TEST(KnownColorTest, DeepSkyBlue) {
    ASSERT_EQ(67, (int32)System::Drawing::KnownColor::DeepSkyBlue);
    ASSERT_EQ("DeepSkyBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DeepSkyBlue).ToString());
  }

  TEST(KnownColorTest, DimGray) {
    ASSERT_EQ(68, (int32)System::Drawing::KnownColor::DimGray);
    ASSERT_EQ("DimGray", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DimGray).ToString());
  }

  TEST(KnownColorTest, DodgerBlue) {
    ASSERT_EQ(69, (int32)System::Drawing::KnownColor::DodgerBlue);
    ASSERT_EQ("DodgerBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::DodgerBlue).ToString());
  }

  TEST(KnownColorTest, Firebrick) {
    ASSERT_EQ(70, (int32)System::Drawing::KnownColor::Firebrick);
    ASSERT_EQ("Firebrick", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Firebrick).ToString());
  }

  TEST(KnownColorTest, FloralWhite) {
    ASSERT_EQ(71, (int32)System::Drawing::KnownColor::FloralWhite);
    ASSERT_EQ("FloralWhite", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::FloralWhite).ToString());
  }

  TEST(KnownColorTest, ForestGreen) {
    ASSERT_EQ(72, (int32)System::Drawing::KnownColor::ForestGreen);
    ASSERT_EQ("ForestGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ForestGreen).ToString());
  }

  TEST(KnownColorTest, Fuchsia) {
    ASSERT_EQ(73, (int32)System::Drawing::KnownColor::Fuchsia);
    ASSERT_EQ("Fuchsia", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Fuchsia).ToString());
  }

  TEST(KnownColorTest, Gainsboro) {
    ASSERT_EQ(74, (int32)System::Drawing::KnownColor::Gainsboro);
    ASSERT_EQ("Gainsboro", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Gainsboro).ToString());
  }

  TEST(KnownColorTest, GhostWhite) {
    ASSERT_EQ(75, (int32)System::Drawing::KnownColor::GhostWhite);
    ASSERT_EQ("GhostWhite", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::GhostWhite).ToString());
  }

  TEST(KnownColorTest, Gold) {
    ASSERT_EQ(76, (int32)System::Drawing::KnownColor::Gold);
    ASSERT_EQ("Gold", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Gold).ToString());
  }

  TEST(KnownColorTest, Goldenrod) {
    ASSERT_EQ(77, (int32)System::Drawing::KnownColor::Goldenrod);
    ASSERT_EQ("Goldenrod", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Goldenrod).ToString());
  }

  TEST(KnownColorTest, Gray) {
    ASSERT_EQ(78, (int32)System::Drawing::KnownColor::Gray);
    ASSERT_EQ("Gray", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Gray).ToString());
  }

  TEST(KnownColorTest, Green) {
    ASSERT_EQ(79, (int32)System::Drawing::KnownColor::Green);
    ASSERT_EQ("Green", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Green).ToString());
  }

  TEST(KnownColorTest, GreenYellow) {
    ASSERT_EQ(80, (int32)System::Drawing::KnownColor::GreenYellow);
    ASSERT_EQ("GreenYellow", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::GreenYellow).ToString());
  }

  TEST(KnownColorTest, Honeydew) {
    ASSERT_EQ(81, (int32)System::Drawing::KnownColor::Honeydew);
    ASSERT_EQ("Honeydew", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Honeydew).ToString());
  }

  TEST(KnownColorTest, HotPink) {
    ASSERT_EQ(82, (int32)System::Drawing::KnownColor::HotPink);
    ASSERT_EQ("HotPink", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::HotPink).ToString());
  }

  TEST(KnownColorTest, IndianRed) {
    ASSERT_EQ(83, (int32)System::Drawing::KnownColor::IndianRed);
    ASSERT_EQ("IndianRed", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::IndianRed).ToString());
  }

  TEST(KnownColorTest, Indigo) {
    ASSERT_EQ(84, (int32)System::Drawing::KnownColor::Indigo);
    ASSERT_EQ("Indigo", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Indigo).ToString());
  }

  TEST(KnownColorTest, Ivory) {
    ASSERT_EQ(85, (int32)System::Drawing::KnownColor::Ivory);
    ASSERT_EQ("Ivory", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Ivory).ToString());
  }

  TEST(KnownColorTest, Khaki) {
    ASSERT_EQ(86, (int32)System::Drawing::KnownColor::Khaki);
    ASSERT_EQ("Khaki", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Khaki).ToString());
  }

  TEST(KnownColorTest, Lavender) {
    ASSERT_EQ(87, (int32)System::Drawing::KnownColor::Lavender);
    ASSERT_EQ("Lavender", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Lavender).ToString());
  }

  TEST(KnownColorTest, LavenderBlush) {
    ASSERT_EQ(88, (int32)System::Drawing::KnownColor::LavenderBlush);
    ASSERT_EQ("LavenderBlush", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LavenderBlush).ToString());
  }

  TEST(KnownColorTest, LawnGreen) {
    ASSERT_EQ(89, (int32)System::Drawing::KnownColor::LawnGreen);
    ASSERT_EQ("LawnGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LawnGreen).ToString());
  }

  TEST(KnownColorTest, LemonChiffon) {
    ASSERT_EQ(90, (int32)System::Drawing::KnownColor::LemonChiffon);
    ASSERT_EQ("LemonChiffon", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LemonChiffon).ToString());
  }

  TEST(KnownColorTest, LightBlue) {
    ASSERT_EQ(91, (int32)System::Drawing::KnownColor::LightBlue);
    ASSERT_EQ("LightBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightBlue).ToString());
  }

  TEST(KnownColorTest, LightCoral) {
    ASSERT_EQ(92, (int32)System::Drawing::KnownColor::LightCoral);
    ASSERT_EQ("LightCoral", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightCoral).ToString());
  }

  TEST(KnownColorTest, LightCyan) {
    ASSERT_EQ(93, (int32)System::Drawing::KnownColor::LightCyan);
    ASSERT_EQ("LightCyan", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightCyan).ToString());
  }

  TEST(KnownColorTest, LightGoldenrodYellow) {
    ASSERT_EQ(94, (int32)System::Drawing::KnownColor::LightGoldenrodYellow);
    ASSERT_EQ("LightGoldenrodYellow", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightGoldenrodYellow).ToString());
  }

  TEST(KnownColorTest, LightGray) {
    ASSERT_EQ(95, (int32)System::Drawing::KnownColor::LightGray);
    ASSERT_EQ("LightGray", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightGray).ToString());
  }

  TEST(KnownColorTest, LightGreen) {
    ASSERT_EQ(96, (int32)System::Drawing::KnownColor::LightGreen);
    ASSERT_EQ("LightGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightGreen).ToString());
  }

  TEST(KnownColorTest, LightPink) {
    ASSERT_EQ(97, (int32)System::Drawing::KnownColor::LightPink);
    ASSERT_EQ("LightPink", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightPink).ToString());
  }

  TEST(KnownColorTest, LightSalmon) {
    ASSERT_EQ(98, (int32)System::Drawing::KnownColor::LightSalmon);
    ASSERT_EQ("LightSalmon", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightSalmon).ToString());
  }

  TEST(KnownColorTest, LightSeaGreen) {
    ASSERT_EQ(99, (int32)System::Drawing::KnownColor::LightSeaGreen);
    ASSERT_EQ("LightSeaGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightSeaGreen).ToString());
  }

  TEST(KnownColorTest, LightSkyBlue) {
    ASSERT_EQ(100, (int32)System::Drawing::KnownColor::LightSkyBlue);
    ASSERT_EQ("LightSkyBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightSkyBlue).ToString());
  }

  TEST(KnownColorTest, LightSlateGray) {
    ASSERT_EQ(101, (int32)System::Drawing::KnownColor::LightSlateGray);
    ASSERT_EQ("LightSlateGray", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightSlateGray).ToString());
  }

  TEST(KnownColorTest, LightSteelBlue) {
    ASSERT_EQ(102, (int32)System::Drawing::KnownColor::LightSteelBlue);
    ASSERT_EQ("LightSteelBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightSteelBlue).ToString());
  }

  TEST(KnownColorTest, LightYellow) {
    ASSERT_EQ(103, (int32)System::Drawing::KnownColor::LightYellow);
    ASSERT_EQ("LightYellow", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LightYellow).ToString());
  }

  TEST(KnownColorTest, Lime) {
    ASSERT_EQ(104, (int32)System::Drawing::KnownColor::Lime);
    ASSERT_EQ("Lime", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Lime).ToString());
  }

  TEST(KnownColorTest, LimeGreen) {
    ASSERT_EQ(105, (int32)System::Drawing::KnownColor::LimeGreen);
    ASSERT_EQ("LimeGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::LimeGreen).ToString());
  }

  TEST(KnownColorTest, Linen) {
    ASSERT_EQ(106, (int32)System::Drawing::KnownColor::Linen);
    ASSERT_EQ("Linen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Linen).ToString());
  }

  TEST(KnownColorTest, Magenta) {
    ASSERT_EQ(107, (int32)System::Drawing::KnownColor::Magenta);
    ASSERT_EQ("Magenta", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Magenta).ToString());
  }

  TEST(KnownColorTest, Maroon) {
    ASSERT_EQ(108, (int32)System::Drawing::KnownColor::Maroon);
    ASSERT_EQ("Maroon", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Maroon).ToString());
  }

  TEST(KnownColorTest, MediumAquamarine) {
    ASSERT_EQ(109, (int32)System::Drawing::KnownColor::MediumAquamarine);
    ASSERT_EQ("MediumAquamarine", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MediumAquamarine).ToString());
  }

  TEST(KnownColorTest, MediumBlue) {
    ASSERT_EQ(110, (int32)System::Drawing::KnownColor::MediumBlue);
    ASSERT_EQ("MediumBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MediumBlue).ToString());
  }

  TEST(KnownColorTest, MediumOrchid) {
    ASSERT_EQ(111, (int32)System::Drawing::KnownColor::MediumOrchid);
    ASSERT_EQ("MediumOrchid", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MediumOrchid).ToString());
  }

  TEST(KnownColorTest, MediumPurple) {
    ASSERT_EQ(112, (int32)System::Drawing::KnownColor::MediumPurple);
    ASSERT_EQ("MediumPurple", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MediumPurple).ToString());
  }

  TEST(KnownColorTest, MediumSeaGreen) {
    ASSERT_EQ(113, (int32)System::Drawing::KnownColor::MediumSeaGreen);
    ASSERT_EQ("MediumSeaGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MediumSeaGreen).ToString());
  }

  TEST(KnownColorTest, MediumSlateBlue) {
    ASSERT_EQ(114, (int32)System::Drawing::KnownColor::MediumSlateBlue);
    ASSERT_EQ("MediumSlateBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MediumSlateBlue).ToString());
  }

  TEST(KnownColorTest, MediumSpringGreen) {
    ASSERT_EQ(115, (int32)System::Drawing::KnownColor::MediumSpringGreen);
    ASSERT_EQ("MediumSpringGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MediumSpringGreen).ToString());
  }

  TEST(KnownColorTest, MediumTurquoise) {
    ASSERT_EQ(116, (int32)System::Drawing::KnownColor::MediumTurquoise);
    ASSERT_EQ("MediumTurquoise", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MediumTurquoise).ToString());
  }

  TEST(KnownColorTest, MediumVioletRed) {
    ASSERT_EQ(117, (int32)System::Drawing::KnownColor::MediumVioletRed);
    ASSERT_EQ("MediumVioletRed", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MediumVioletRed).ToString());
  }

  TEST(KnownColorTest, MidnightBlue) {
    ASSERT_EQ(118, (int32)System::Drawing::KnownColor::MidnightBlue);
    ASSERT_EQ("MidnightBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MidnightBlue).ToString());
  }

  TEST(KnownColorTest, MintCream) {
    ASSERT_EQ(119, (int32)System::Drawing::KnownColor::MintCream);
    ASSERT_EQ("MintCream", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MintCream).ToString());
  }

  TEST(KnownColorTest, MistyRose) {
    ASSERT_EQ(120, (int32)System::Drawing::KnownColor::MistyRose);
    ASSERT_EQ("MistyRose", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MistyRose).ToString());
  }

  TEST(KnownColorTest, Moccasin) {
    ASSERT_EQ(121, (int32)System::Drawing::KnownColor::Moccasin);
    ASSERT_EQ("Moccasin", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Moccasin).ToString());
  }

  TEST(KnownColorTest, NavajoWhite) {
    ASSERT_EQ(122, (int32)System::Drawing::KnownColor::NavajoWhite);
    ASSERT_EQ("NavajoWhite", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::NavajoWhite).ToString());
  }

  TEST(KnownColorTest, Navy) {
    ASSERT_EQ(123, (int32)System::Drawing::KnownColor::Navy);
    ASSERT_EQ("Navy", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Navy).ToString());
  }

  TEST(KnownColorTest, OldLace) {
    ASSERT_EQ(124, (int32)System::Drawing::KnownColor::OldLace);
    ASSERT_EQ("OldLace", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::OldLace).ToString());
  }

  TEST(KnownColorTest, Olive) {
    ASSERT_EQ(125, (int32)System::Drawing::KnownColor::Olive);
    ASSERT_EQ("Olive", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Olive).ToString());
  }

  TEST(KnownColorTest, OliveDrab) {
    ASSERT_EQ(126, (int32)System::Drawing::KnownColor::OliveDrab);
    ASSERT_EQ("OliveDrab", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::OliveDrab).ToString());
  }

  TEST(KnownColorTest, Orange) {
    ASSERT_EQ(127, (int32)System::Drawing::KnownColor::Orange);
    ASSERT_EQ("Orange", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Orange).ToString());
  }

  TEST(KnownColorTest, OrangeRed) {
    ASSERT_EQ(128, (int32)System::Drawing::KnownColor::OrangeRed);
    ASSERT_EQ("OrangeRed", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::OrangeRed).ToString());
  }

  TEST(KnownColorTest, Orchid) {
    ASSERT_EQ(129, (int32)System::Drawing::KnownColor::Orchid);
    ASSERT_EQ("Orchid", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Orchid).ToString());
  }

  TEST(KnownColorTest, PaleGoldenrod) {
    ASSERT_EQ(130, (int32)System::Drawing::KnownColor::PaleGoldenrod);
    ASSERT_EQ("PaleGoldenrod", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::PaleGoldenrod).ToString());
  }

  TEST(KnownColorTest, PaleGreen) {
    ASSERT_EQ(131, (int32)System::Drawing::KnownColor::PaleGreen);
    ASSERT_EQ("PaleGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::PaleGreen).ToString());
  }

  TEST(KnownColorTest, PaleTurquoise) {
    ASSERT_EQ(132, (int32)System::Drawing::KnownColor::PaleTurquoise);
    ASSERT_EQ("PaleTurquoise", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::PaleTurquoise).ToString());
  }

  TEST(KnownColorTest, PaleVioletRed) {
    ASSERT_EQ(133, (int32)System::Drawing::KnownColor::PaleVioletRed);
    ASSERT_EQ("PaleVioletRed", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::PaleVioletRed).ToString());
  }

  TEST(KnownColorTest, PapayaWhip) {
    ASSERT_EQ(134, (int32)System::Drawing::KnownColor::PapayaWhip);
    ASSERT_EQ("PapayaWhip", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::PapayaWhip).ToString());
  }

  TEST(KnownColorTest, PeachPuff) {
    ASSERT_EQ(135, (int32)System::Drawing::KnownColor::PeachPuff);
    ASSERT_EQ("PeachPuff", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::PeachPuff).ToString());
  }

  TEST(KnownColorTest, Peru) {
    ASSERT_EQ(136, (int32)System::Drawing::KnownColor::Peru);
    ASSERT_EQ("Peru", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Peru).ToString());
  }

  TEST(KnownColorTest, Pink) {
    ASSERT_EQ(137, (int32)System::Drawing::KnownColor::Pink);
    ASSERT_EQ("Pink", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Pink).ToString());
  }

  TEST(KnownColorTest, Plum) {
    ASSERT_EQ(138, (int32)System::Drawing::KnownColor::Plum);
    ASSERT_EQ("Plum", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Plum).ToString());
  }

  TEST(KnownColorTest, PowderBlue) {
    ASSERT_EQ(139, (int32)System::Drawing::KnownColor::PowderBlue);
    ASSERT_EQ("PowderBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::PowderBlue).ToString());
  }

  TEST(KnownColorTest, Purple) {
    ASSERT_EQ(140, (int32)System::Drawing::KnownColor::Purple);
    ASSERT_EQ("Purple", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Purple).ToString());
  }

  TEST(KnownColorTest, Red) {
    ASSERT_EQ(141, (int32)System::Drawing::KnownColor::Red);
    ASSERT_EQ("Red", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Red).ToString());
  }

  TEST(KnownColorTest, RosyBrown) {
    ASSERT_EQ(142, (int32)System::Drawing::KnownColor::RosyBrown);
    ASSERT_EQ("RosyBrown", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::RosyBrown).ToString());
  }

  TEST(KnownColorTest, RoyalBlue) {
    ASSERT_EQ(143, (int32)System::Drawing::KnownColor::RoyalBlue);
    ASSERT_EQ("RoyalBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::RoyalBlue).ToString());
  }

  TEST(KnownColorTest, SaddleBrown) {
    ASSERT_EQ(144, (int32)System::Drawing::KnownColor::SaddleBrown);
    ASSERT_EQ("SaddleBrown", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::SaddleBrown).ToString());
  }

  TEST(KnownColorTest, Salmon) {
    ASSERT_EQ(145, (int32)System::Drawing::KnownColor::Salmon);
    ASSERT_EQ("Salmon", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Salmon).ToString());
  }

  TEST(KnownColorTest, SandyBrown) {
    ASSERT_EQ(146, (int32)System::Drawing::KnownColor::SandyBrown);
    ASSERT_EQ("SandyBrown", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::SandyBrown).ToString());
  }

  TEST(KnownColorTest, SeaGreen) {
    ASSERT_EQ(147, (int32)System::Drawing::KnownColor::SeaGreen);
    ASSERT_EQ("SeaGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::SeaGreen).ToString());
  }

  TEST(KnownColorTest, SeaShell) {
    ASSERT_EQ(148, (int32)System::Drawing::KnownColor::SeaShell);
    ASSERT_EQ("SeaShell", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::SeaShell).ToString());
  }

  TEST(KnownColorTest, Sienna) {
    ASSERT_EQ(149, (int32)System::Drawing::KnownColor::Sienna);
    ASSERT_EQ("Sienna", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Sienna).ToString());
  }

  TEST(KnownColorTest, Silver) {
    ASSERT_EQ(150, (int32)System::Drawing::KnownColor::Silver);
    ASSERT_EQ("Silver", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Silver).ToString());
  }

  TEST(KnownColorTest, SkyBlue) {
    ASSERT_EQ(151, (int32)System::Drawing::KnownColor::SkyBlue);
    ASSERT_EQ("SkyBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::SkyBlue).ToString());
  }

  TEST(KnownColorTest, SlateBlue) {
    ASSERT_EQ(152, (int32)System::Drawing::KnownColor::SlateBlue);
    ASSERT_EQ("SlateBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::SlateBlue).ToString());
  }

  TEST(KnownColorTest, SlateGray) {
    ASSERT_EQ(153, (int32)System::Drawing::KnownColor::SlateGray);
    ASSERT_EQ("SlateGray", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::SlateGray).ToString());
  }

  TEST(KnownColorTest, Snow) {
    ASSERT_EQ(154, (int32)System::Drawing::KnownColor::Snow);
    ASSERT_EQ("Snow", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Snow).ToString());
  }

  TEST(KnownColorTest, SpringGreen) {
    ASSERT_EQ(155, (int32)System::Drawing::KnownColor::SpringGreen);
    ASSERT_EQ("SpringGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::SpringGreen).ToString());
  }

  TEST(KnownColorTest, SteelBlue) {
    ASSERT_EQ(156, (int32)System::Drawing::KnownColor::SteelBlue);
    ASSERT_EQ("SteelBlue", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::SteelBlue).ToString());
  }

  TEST(KnownColorTest, Tan) {
    ASSERT_EQ(157, (int32)System::Drawing::KnownColor::Tan);
    ASSERT_EQ("Tan", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Tan).ToString());
  }

  TEST(KnownColorTest, Teal) {
    ASSERT_EQ(158, (int32)System::Drawing::KnownColor::Teal);
    ASSERT_EQ("Teal", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Teal).ToString());
  }

  TEST(KnownColorTest, Thistle) {
    ASSERT_EQ(159, (int32)System::Drawing::KnownColor::Thistle);
    ASSERT_EQ("Thistle", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Thistle).ToString());
  }

  TEST(KnownColorTest, Tomato) {
    ASSERT_EQ(160, (int32)System::Drawing::KnownColor::Tomato);
    ASSERT_EQ("Tomato", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Tomato).ToString());
  }

  TEST(KnownColorTest, Turquoise) {
    ASSERT_EQ(161, (int32)System::Drawing::KnownColor::Turquoise);
    ASSERT_EQ("Turquoise", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Turquoise).ToString());
  }

  TEST(KnownColorTest, Violet) {
    ASSERT_EQ(162, (int32)System::Drawing::KnownColor::Violet);
    ASSERT_EQ("Violet", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Violet).ToString());
  }

  TEST(KnownColorTest, Wheat) {
    ASSERT_EQ(163, (int32)System::Drawing::KnownColor::Wheat);
    ASSERT_EQ("Wheat", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Wheat).ToString());
  }

  TEST(KnownColorTest, White) {
    ASSERT_EQ(164, (int32)System::Drawing::KnownColor::White);
    ASSERT_EQ("White", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::White).ToString());
  }

  TEST(KnownColorTest, WhiteSmoke) {
    ASSERT_EQ(165, (int32)System::Drawing::KnownColor::WhiteSmoke);
    ASSERT_EQ("WhiteSmoke", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::WhiteSmoke).ToString());
  }

  TEST(KnownColorTest, Yellow) {
    ASSERT_EQ(166, (int32)System::Drawing::KnownColor::Yellow);
    ASSERT_EQ("Yellow", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::Yellow).ToString());
  }

  TEST(KnownColorTest, YellowGreen) {
    ASSERT_EQ(167, (int32)System::Drawing::KnownColor::YellowGreen);
    ASSERT_EQ("YellowGreen", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::YellowGreen).ToString());
  }

  TEST(KnownColorTest, ButtonFace) {
    ASSERT_EQ(168, (int32)System::Drawing::KnownColor::ButtonFace);
    ASSERT_EQ("ButtonFace", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ButtonFace).ToString());
  }

  TEST(KnownColorTest, ButtonHighlight) {
    ASSERT_EQ(169, (int32)System::Drawing::KnownColor::ButtonHighlight);
    ASSERT_EQ("ButtonHighlight", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ButtonHighlight).ToString());
  }

  TEST(KnownColorTest, ButtonShadow) {
    ASSERT_EQ(170, (int32)System::Drawing::KnownColor::ButtonShadow);
    ASSERT_EQ("ButtonShadow", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::ButtonShadow).ToString());
  }

  TEST(KnownColorTest, GradientActiveCaption) {
    ASSERT_EQ(171, (int32)System::Drawing::KnownColor::GradientActiveCaption);
    ASSERT_EQ("GradientActiveCaption", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::GradientActiveCaption).ToString());
  }

  TEST(KnownColorTest, GradientInactiveCaption) {
    ASSERT_EQ(172, (int32)System::Drawing::KnownColor::GradientInactiveCaption);
    ASSERT_EQ("GradientInactiveCaption", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::GradientInactiveCaption).ToString());
  }

  TEST(KnownColorTest, MenuBar) {
    ASSERT_EQ(173, (int32)System::Drawing::KnownColor::MenuBar);
    ASSERT_EQ("MenuBar", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MenuBar).ToString());
  }

  TEST(KnownColorTest, MenuHighlight) {
    ASSERT_EQ(174, (int32)System::Drawing::KnownColor::MenuHighlight);
    ASSERT_EQ("MenuHighlight", System::Enum<System::Drawing::KnownColor>(System::Drawing::KnownColor::MenuHighlight).ToString());
  }
}
