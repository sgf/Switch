#include <Switch/System/Drawing/Pens.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(PensTest, AliceBlue) {
    Pen pen = Pens::AliceBlue;
    ASSERT_EQ(Color::AliceBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, AntiqueWhite) {
    Pen pen = Pens::AntiqueWhite;
    ASSERT_EQ(Color::AntiqueWhite, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Aqua) {
    Pen pen = Pens::Aqua;
    ASSERT_EQ(Color::Aqua, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Aquamarine) {
    Pen pen = Pens::Aquamarine;
    ASSERT_EQ(Color::Aquamarine, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Azure) {
    Pen pen = Pens::Azure;
    ASSERT_EQ(Color::Azure, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Beige) {
    Pen pen = Pens::Beige;
    ASSERT_EQ(Color::Beige, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Bisque) {
    Pen pen = Pens::Bisque;
    ASSERT_EQ(Color::Bisque, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Black) {
    Pen pen = Pens::Black;
    ASSERT_EQ(Color::Black, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, BlanchedAlmond) {
    Pen pen = Pens::BlanchedAlmond;
    ASSERT_EQ(Color::BlanchedAlmond, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Blue) {
    Pen pen = Pens::Blue;
    ASSERT_EQ(Color::Blue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, BlueViolet) {
    Pen pen = Pens::BlueViolet;
    ASSERT_EQ(Color::BlueViolet, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Brown) {
    Pen pen = Pens::Brown;
    ASSERT_EQ(Color::Brown, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, BurlyWood) {
    Pen pen = Pens::BurlyWood;
    ASSERT_EQ(Color::BurlyWood, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, CadetBlue) {
    Pen pen = Pens::CadetBlue;
    ASSERT_EQ(Color::CadetBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Chartreuse) {
    Pen pen = Pens::Chartreuse;
    ASSERT_EQ(Color::Chartreuse, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Chocolate) {
    Pen pen = Pens::Chocolate;
    ASSERT_EQ(Color::Chocolate, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Coral) {
    Pen pen = Pens::Coral;
    ASSERT_EQ(Color::Coral, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, CornflowerBlue) {
    Pen pen = Pens::CornflowerBlue;
    ASSERT_EQ(Color::CornflowerBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Cornsilk) {
    Pen pen = Pens::Cornsilk;
    ASSERT_EQ(Color::Cornsilk, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Crimson) {
    Pen pen = Pens::Crimson;
    ASSERT_EQ(Color::Crimson, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Cyan) {
    Pen pen = Pens::Cyan;
    ASSERT_EQ(Color::Cyan, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkBlue) {
    Pen pen = Pens::DarkBlue;
    ASSERT_EQ(Color::DarkBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkCyan) {
    Pen pen = Pens::DarkCyan;
    ASSERT_EQ(Color::DarkCyan, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkGoldenrod) {
    Pen pen = Pens::DarkGoldenrod;
    ASSERT_EQ(Color::DarkGoldenrod, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkGray) {
    Pen pen = Pens::DarkGray;
    ASSERT_EQ(Color::DarkGray, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkGreen) {
    Pen pen = Pens::DarkGreen;
    ASSERT_EQ(Color::DarkGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkKhaki) {
    Pen pen = Pens::DarkKhaki;
    ASSERT_EQ(Color::DarkKhaki, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkMagenta) {
    Pen pen = Pens::DarkMagenta;
    ASSERT_EQ(Color::DarkMagenta, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkOliveGreen) {
    Pen pen = Pens::DarkOliveGreen;
    ASSERT_EQ(Color::DarkOliveGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkOrange) {
    Pen pen = Pens::DarkOrange;
    ASSERT_EQ(Color::DarkOrange, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkOrchid) {
    Pen pen = Pens::DarkOrchid;
    ASSERT_EQ(Color::DarkOrchid, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkRed) {
    Pen pen = Pens::DarkRed;
    ASSERT_EQ(Color::DarkRed, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkSalmon) {
    Pen pen = Pens::DarkSalmon;
    ASSERT_EQ(Color::DarkSalmon, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkSeaGreen) {
    Pen pen = Pens::DarkSeaGreen;
    ASSERT_EQ(Color::DarkSeaGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkSlateBlue) {
    Pen pen = Pens::DarkSlateBlue;
    ASSERT_EQ(Color::DarkSlateBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkSlateGray) {
    Pen pen = Pens::DarkSlateGray;
    ASSERT_EQ(Color::DarkSlateGray, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkTurquoise) {
    Pen pen = Pens::DarkTurquoise;
    ASSERT_EQ(Color::DarkTurquoise, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DarkViolet) {
    Pen pen = Pens::DarkViolet;
    ASSERT_EQ(Color::DarkViolet, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DeepPink) {
    Pen pen = Pens::DeepPink;
    ASSERT_EQ(Color::DeepPink, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DeepSkyBlue) {
    Pen pen = Pens::DeepSkyBlue;
    ASSERT_EQ(Color::DeepSkyBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DimGray) {
    Pen pen = Pens::DimGray;
    ASSERT_EQ(Color::DimGray, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, DodgerBlue) {
    Pen pen = Pens::DodgerBlue;
    ASSERT_EQ(Color::DodgerBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Firebrick) {
    Pen pen = Pens::Firebrick;
    ASSERT_EQ(Color::Firebrick, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, FloralWhite) {
    Pen pen = Pens::FloralWhite;
    ASSERT_EQ(Color::FloralWhite, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, ForestGreen) {
    Pen pen = Pens::ForestGreen;
    ASSERT_EQ(Color::ForestGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Fuchsia) {
    Pen pen = Pens::Fuchsia;
    ASSERT_EQ(Color::Fuchsia, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Gainsboro) {
    Pen pen = Pens::Gainsboro;
    ASSERT_EQ(Color::Gainsboro, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, GhostWhite) {
    Pen pen = Pens::GhostWhite;
    ASSERT_EQ(Color::GhostWhite, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Gold) {
    Pen pen = Pens::Gold;
    ASSERT_EQ(Color::Gold, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Goldenrod) {
    Pen pen = Pens::Goldenrod;
    ASSERT_EQ(Color::Goldenrod, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Gray) {
    Pen pen = Pens::Gray;
    ASSERT_EQ(Color::Gray, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Green) {
    Pen pen = Pens::Green;
    ASSERT_EQ(Color::Green, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, GreenYellow) {
    Pen pen = Pens::GreenYellow;
    ASSERT_EQ(Color::GreenYellow, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Honeydew) {
    Pen pen = Pens::Honeydew;
    ASSERT_EQ(Color::Honeydew, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, HotPink) {
    Pen pen = Pens::HotPink;
    ASSERT_EQ(Color::HotPink, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, IndianRed) {
    Pen pen = Pens::IndianRed;
    ASSERT_EQ(Color::IndianRed, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Indigo) {
    Pen pen = Pens::Indigo;
    ASSERT_EQ(Color::Indigo, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Ivory) {
    Pen pen = Pens::Ivory;
    ASSERT_EQ(Color::Ivory, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Khaki) {
    Pen pen = Pens::Khaki;
    ASSERT_EQ(Color::Khaki, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Lavender) {
    Pen pen = Pens::Lavender;
    ASSERT_EQ(Color::Lavender, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LavenderBlush) {
    Pen pen = Pens::LavenderBlush;
    ASSERT_EQ(Color::LavenderBlush, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LawnGreen) {
    Pen pen = Pens::LawnGreen;
    ASSERT_EQ(Color::LawnGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LemonChiffon) {
    Pen pen = Pens::LemonChiffon;
    ASSERT_EQ(Color::LemonChiffon, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightBlue) {
    Pen pen = Pens::LightBlue;
    ASSERT_EQ(Color::LightBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightCoral) {
    Pen pen = Pens::LightCoral;
    ASSERT_EQ(Color::LightCoral, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightCyan) {
    Pen pen = Pens::LightCyan;
    ASSERT_EQ(Color::LightCyan, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightGoldenrodYellow) {
    Pen pen = Pens::LightGoldenrodYellow;
    ASSERT_EQ(Color::LightGoldenrodYellow, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightGray) {
    Pen pen = Pens::LightGray;
    ASSERT_EQ(Color::LightGray, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightGreen) {
    Pen pen = Pens::LightGreen;
    ASSERT_EQ(Color::LightGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightPink) {
    Pen pen = Pens::LightPink;
    ASSERT_EQ(Color::LightPink, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightSalmon) {
    Pen pen = Pens::LightSalmon;
    ASSERT_EQ(Color::LightSalmon, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightSeaGreen) {
    Pen pen = Pens::LightSeaGreen;
    ASSERT_EQ(Color::LightSeaGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightSkyBlue) {
    Pen pen = Pens::LightSkyBlue;
    ASSERT_EQ(Color::LightSkyBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightSlateGray) {
    Pen pen = Pens::LightSlateGray;
    ASSERT_EQ(Color::LightSlateGray, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightSteelBlue) {
    Pen pen = Pens::LightSteelBlue;
    ASSERT_EQ(Color::LightSteelBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LightYellow) {
    Pen pen = Pens::LightYellow;
    ASSERT_EQ(Color::LightYellow, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Lime) {
    Pen pen = Pens::Lime;
    ASSERT_EQ(Color::Lime, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, LimeGreen) {
    Pen pen = Pens::LimeGreen;
    ASSERT_EQ(Color::LimeGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Linen) {
    Pen pen = Pens::Linen;
    ASSERT_EQ(Color::Linen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Magenta) {
    Pen pen = Pens::Magenta;
    ASSERT_EQ(Color::Magenta, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Maroon) {
    Pen pen = Pens::Maroon;
    ASSERT_EQ(Color::Maroon, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MediumAquamarine) {
    Pen pen = Pens::MediumAquamarine;
    ASSERT_EQ(Color::MediumAquamarine, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MediumBlue) {
    Pen pen = Pens::MediumBlue;
    ASSERT_EQ(Color::MediumBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MediumOrchid) {
    Pen pen = Pens::MediumOrchid;
    ASSERT_EQ(Color::MediumOrchid, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MediumPurple) {
    Pen pen = Pens::MediumPurple;
    ASSERT_EQ(Color::MediumPurple, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MediumSeaGreen) {
    Pen pen = Pens::MediumSeaGreen;
    ASSERT_EQ(Color::MediumSeaGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MediumSlateBlue) {
    Pen pen = Pens::MediumSlateBlue;
    ASSERT_EQ(Color::MediumSlateBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MediumSpringGreen) {
    Pen pen = Pens::MediumSpringGreen;
    ASSERT_EQ(Color::MediumSpringGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MediumTurquoise) {
    Pen pen = Pens::MediumTurquoise;
    ASSERT_EQ(Color::MediumTurquoise, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MediumVioletRed) {
    Pen pen = Pens::MediumVioletRed;
    ASSERT_EQ(Color::MediumVioletRed, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MidnightBlue) {
    Pen pen = Pens::MidnightBlue;
    ASSERT_EQ(Color::MidnightBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MintCream) {
    Pen pen = Pens::MintCream;
    ASSERT_EQ(Color::MintCream, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, MistyRose) {
    Pen pen = Pens::MistyRose;
    ASSERT_EQ(Color::MistyRose, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Moccasin) {
    Pen pen = Pens::Moccasin;
    ASSERT_EQ(Color::Moccasin, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, NavajoWhite) {
    Pen pen = Pens::NavajoWhite;
    ASSERT_EQ(Color::NavajoWhite, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Navy) {
    Pen pen = Pens::Navy;
    ASSERT_EQ(Color::Navy, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, OldLace) {
    Pen pen = Pens::OldLace;
    ASSERT_EQ(Color::OldLace, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Olive) {
    Pen pen = Pens::Olive;
    ASSERT_EQ(Color::Olive, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, OliveDrab) {
    Pen pen = Pens::OliveDrab;
    ASSERT_EQ(Color::OliveDrab, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Orange) {
    Pen pen = Pens::Orange;
    ASSERT_EQ(Color::Orange, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, OrangeRed) {
    Pen pen = Pens::OrangeRed;
    ASSERT_EQ(Color::OrangeRed, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Orchid) {
    Pen pen = Pens::Orchid;
    ASSERT_EQ(Color::Orchid, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, PaleGoldenrod) {
    Pen pen = Pens::PaleGoldenrod;
    ASSERT_EQ(Color::PaleGoldenrod, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, PaleGreen) {
    Pen pen = Pens::PaleGreen;
    ASSERT_EQ(Color::PaleGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, PaleTurquoise) {
    Pen pen = Pens::PaleTurquoise;
    ASSERT_EQ(Color::PaleTurquoise, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, PaleVioletRed) {
    Pen pen = Pens::PaleVioletRed;
    ASSERT_EQ(Color::PaleVioletRed, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, PapayaWhip) {
    Pen pen = Pens::PapayaWhip;
    ASSERT_EQ(Color::PapayaWhip, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, PeachPuff) {
    Pen pen = Pens::PeachPuff;
    ASSERT_EQ(Color::PeachPuff, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Peru) {
    Pen pen = Pens::Peru;
    ASSERT_EQ(Color::Peru, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Pink) {
    Pen pen = Pens::Pink;
    ASSERT_EQ(Color::Pink, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Plum) {
    Pen pen = Pens::Plum;
    ASSERT_EQ(Color::Plum, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, PowderBlue) {
    Pen pen = Pens::PowderBlue;
    ASSERT_EQ(Color::PowderBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Purple) {
    Pen pen = Pens::Purple;
    ASSERT_EQ(Color::Purple, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Red) {
    Pen pen = Pens::Red;
    ASSERT_EQ(Color::Red, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, RosyBrown) {
    Pen pen = Pens::RosyBrown;
    ASSERT_EQ(Color::RosyBrown, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, RoyalBlue) {
    Pen pen = Pens::RoyalBlue;
    ASSERT_EQ(Color::RoyalBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, SaddleBrown) {
    Pen pen = Pens::SaddleBrown;
    ASSERT_EQ(Color::SaddleBrown, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Salmon) {
    Pen pen = Pens::Salmon;
    ASSERT_EQ(Color::Salmon, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, SandyBrown) {
    Pen pen = Pens::SandyBrown;
    ASSERT_EQ(Color::SandyBrown, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, SeaGreen) {
    Pen pen = Pens::SeaGreen;
    ASSERT_EQ(Color::SeaGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, SeaShell) {
    Pen pen = Pens::SeaShell;
    ASSERT_EQ(Color::SeaShell, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Sienna) {
    Pen pen = Pens::Sienna;
    ASSERT_EQ(Color::Sienna, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Silver) {
    Pen pen = Pens::Silver;
    ASSERT_EQ(Color::Silver, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, SkyBlue) {
    Pen pen = Pens::SkyBlue;
    ASSERT_EQ(Color::SkyBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, SlateBlue) {
    Pen pen = Pens::SlateBlue;
    ASSERT_EQ(Color::SlateBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, SlateGray) {
    Pen pen = Pens::SlateGray;
    ASSERT_EQ(Color::SlateGray, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Snow) {
    Pen pen = Pens::Snow;
    ASSERT_EQ(Color::Snow, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, SpringGreen) {
    Pen pen = Pens::SpringGreen;
    ASSERT_EQ(Color::SpringGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, SteelBlue) {
    Pen pen = Pens::SteelBlue;
    ASSERT_EQ(Color::SteelBlue, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Tan) {
    Pen pen = Pens::Tan;
    ASSERT_EQ(Color::Tan, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Teal) {
    Pen pen = Pens::Teal;
    ASSERT_EQ(Color::Teal, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Thistle) {
    Pen pen = Pens::Thistle;
    ASSERT_EQ(Color::Thistle, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Tomato) {
    Pen pen = Pens::Tomato;
    ASSERT_EQ(Color::Tomato, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Transparent) {
    Pen pen = Pens::Transparent;
    ASSERT_EQ(Color::Transparent, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Turquoise) {
    Pen pen = Pens::Turquoise;
    ASSERT_EQ(Color::Turquoise, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Violet) {
    Pen pen = Pens::Violet;
    ASSERT_EQ(Color::Violet, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Wheat) {
    Pen pen = Pens::Wheat;
    ASSERT_EQ(Color::Wheat, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, White) {
    Pen pen = Pens::White;
    ASSERT_EQ(Color::White, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, WhiteSmoke) {
    Pen pen = Pens::WhiteSmoke;
    ASSERT_EQ(Color::WhiteSmoke, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, Yellow) {
    Pen pen = Pens::Yellow;
    ASSERT_EQ(Color::Yellow, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }

  TEST(PensTest, YellowGreen) {
    Pen pen = Pens::YellowGreen;
    ASSERT_EQ(Color::YellowGreen, pen.Color);
    ASSERT_EQ(1.0f, pen.Width);
  }
}
