#include <Switch/System/Drawing/Color.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(ColorTest, DefaultConstructor) {
    Color color;
    ASSERT_EQ(0x00, color.A());
    ASSERT_EQ(0x00, color.R());
    ASSERT_EQ(0x00, color.G());
    ASSERT_EQ(0x00, color.B());
    ASSERT_TRUE(color.IsEmpty());
    ASSERT_FALSE(color.IsKnownColor());
    ASSERT_FALSE(color.IsNamedColor);
    ASSERT_FALSE(color.IsSystemColor());
    ASSERT_EQ("0", color.Name());
    ASSERT_EQ("Color [Empty]", color.ToString());
  }

  TEST(ColorTest, CopyConstructor) {
    Color color1 = Color::FromArgb(0xFF00FF00);

    Color color2 = color1;

    ASSERT_EQ(0xFF00FF00, color2.ToArgb());
  }

  TEST(ColorTest, CopyOperator) {
    Color color1 = Color::FromArgb(0xFF00FF00);

    Color color2;
    color2 = color1;

    ASSERT_EQ(0xFF00FF00, color2.ToArgb());
  }

  TEST(ColorTest, FromKnownColor) {
    ASSERT_EQ(0xFF, Color::FromKnownColor(KnownColor::Black).A());
    ASSERT_EQ(0x00, Color::FromKnownColor(KnownColor::Black).R());
    ASSERT_EQ(0x00, Color::FromKnownColor(KnownColor::Black).G());
    ASSERT_EQ(0x00, Color::FromKnownColor(KnownColor::Black).B());
    ASSERT_FALSE(Color::FromKnownColor(KnownColor::Black).IsEmpty());
    ASSERT_TRUE(Color::FromKnownColor(KnownColor::Black).IsKnownColor());
    ASSERT_TRUE(Color::FromKnownColor(KnownColor::Black).IsNamedColor());
    ASSERT_FALSE(Color::FromKnownColor(KnownColor::Black).IsSystemColor());
    ASSERT_EQ("Black", Color::FromKnownColor(KnownColor::Black).Name());
    ASSERT_EQ("Color [Black]", Color::FromKnownColor(KnownColor::Black).ToString());

    ASSERT_THROW(Color::FromKnownColor((KnownColor)34544), ArgumentException);
  }

  TEST(ColorTest, FromArgb) {
    ASSERT_EQ(0x12, Color::FromArgb(0x12345678).A());
    ASSERT_EQ(0x34, Color::FromArgb(0x12345678).R());
    ASSERT_EQ(0x56, Color::FromArgb(0x12345678).G());
    ASSERT_EQ(0x78, Color::FromArgb(0x12345678).B());
    ASSERT_FALSE(Color::FromArgb(0x12345678).IsEmpty());
    ASSERT_FALSE(Color::FromArgb(0x12345678).IsKnownColor());
    ASSERT_FALSE(Color::FromArgb(0x12345678).IsNamedColor());
    ASSERT_FALSE(Color::FromArgb(0x12345678).IsSystemColor());
    ASSERT_EQ("12345678", Color::FromArgb(0x12345678).Name());
    ASSERT_EQ("Color [A=18, R=52, G=86, B=120]", Color::FromArgb(0x12345678).ToString());
  }

  TEST(ColorTest, FromName) {
    Color colorAliceBlue = Color::FromName("AliceBlue");
    ASSERT_EQ(0xFF, colorAliceBlue.A());
    ASSERT_EQ(0xF0, colorAliceBlue.R());
    ASSERT_EQ(0xF8, colorAliceBlue.G());
    ASSERT_EQ(0xFF, colorAliceBlue.B());
    ASSERT_FALSE(colorAliceBlue.IsEmpty());
    ASSERT_TRUE(colorAliceBlue.IsKnownColor());
    ASSERT_TRUE(colorAliceBlue.IsNamedColor());
    ASSERT_FALSE(colorAliceBlue.IsSystemColor());
    ASSERT_EQ("AliceBlue", colorAliceBlue.Name());
    ASSERT_EQ("Color [AliceBlue]", colorAliceBlue.ToString());
  }

  TEST(ColorTest, Transparent) {
    ASSERT_EQ(0x00FFFFFF, Color::Transparent().ToArgb());
    ASSERT_FALSE(Color::Transparent().IsEmpty());
    ASSERT_TRUE(Color::Transparent().IsKnownColor());
    ASSERT_TRUE(Color::Transparent().IsNamedColor());
    ASSERT_FALSE(Color::Transparent().IsSystemColor());
    ASSERT_EQ("Transparent", Color::Transparent().Name());
    ASSERT_EQ("Color [Transparent]", Color::Transparent().ToString());
  }

  TEST(ColorTest, AliceBlue) {
    ASSERT_EQ(0xFFF0F8FFu, (unsigned)Color::AliceBlue().ToArgb());
    ASSERT_FALSE(Color::AliceBlue().IsEmpty());
    ASSERT_TRUE(Color::AliceBlue().IsKnownColor());
    ASSERT_TRUE(Color::AliceBlue().IsNamedColor());
    ASSERT_FALSE(Color::AliceBlue().IsSystemColor());
    ASSERT_EQ("AliceBlue", Color::AliceBlue().Name());
    ASSERT_EQ("Color [AliceBlue]", Color::AliceBlue().ToString());
  }

  TEST(ColorTest, AntiqueWhite) {
    ASSERT_EQ(0xFFFAEBD7u, (unsigned)Color::AntiqueWhite().ToArgb());
    ASSERT_FALSE(Color::AntiqueWhite().IsEmpty());
    ASSERT_TRUE(Color::AntiqueWhite().IsKnownColor());
    ASSERT_TRUE(Color::AntiqueWhite().IsNamedColor());
    ASSERT_FALSE(Color::AntiqueWhite().IsSystemColor());
    ASSERT_EQ("AntiqueWhite", Color::AntiqueWhite().Name());
    ASSERT_EQ("Color [AntiqueWhite]", Color::AntiqueWhite().ToString());
  }

  TEST(ColorTest, Aqua) {
    ASSERT_EQ(0xFF00FFFFu, (unsigned)Color::Aqua().ToArgb());
    ASSERT_FALSE(Color::Aqua().IsEmpty());
    ASSERT_TRUE(Color::Aqua().IsKnownColor());
    ASSERT_TRUE(Color::Aqua().IsNamedColor());
    ASSERT_FALSE(Color::Aqua().IsSystemColor());
    ASSERT_EQ("Aqua", Color::Aqua().Name());
    ASSERT_EQ("Color [Aqua]", Color::Aqua().ToString());
  }

  TEST(ColorTest, Aquamarine) {
    ASSERT_EQ(0xFF7FFFD4u, (unsigned)Color::Aquamarine().ToArgb());
    ASSERT_FALSE(Color::Aquamarine().IsEmpty());
    ASSERT_TRUE(Color::Aquamarine().IsKnownColor());
    ASSERT_TRUE(Color::Aquamarine().IsNamedColor());
    ASSERT_FALSE(Color::Aquamarine().IsSystemColor());
    ASSERT_EQ("Aquamarine", Color::Aquamarine().Name());
    ASSERT_EQ("Color [Aquamarine]", Color::Aquamarine().ToString());
  }

  TEST(ColorTest, Azure) {
    ASSERT_EQ(0xFFF0FFFFu, (unsigned)Color::Azure().ToArgb());
    ASSERT_FALSE(Color::Azure().IsEmpty());
    ASSERT_TRUE(Color::Azure().IsKnownColor());
    ASSERT_TRUE(Color::Azure().IsNamedColor());
    ASSERT_FALSE(Color::Azure().IsSystemColor());
    ASSERT_EQ("Azure", Color::Azure().Name());
    ASSERT_EQ("Color [Azure]", Color::Azure().ToString());
  }

  TEST(ColorTest, Beige) {
    ASSERT_EQ(0xFFF5F5DCu, (unsigned)Color::Beige().ToArgb());
    ASSERT_FALSE(Color::Beige().IsEmpty());
    ASSERT_TRUE(Color::Beige().IsKnownColor());
    ASSERT_TRUE(Color::Beige().IsNamedColor());
    ASSERT_FALSE(Color::Beige().IsSystemColor());
    ASSERT_EQ("Beige", Color::Beige().Name());
    ASSERT_EQ("Color [Beige]", Color::Beige().ToString());
  }

  TEST(ColorTest, Bisque) {
    ASSERT_EQ(0xFFFFE4C4u, (unsigned)Color::Bisque().ToArgb());
    ASSERT_FALSE(Color::Bisque().IsEmpty());
    ASSERT_TRUE(Color::Bisque().IsKnownColor());
    ASSERT_TRUE(Color::Bisque().IsNamedColor());
    ASSERT_FALSE(Color::Bisque().IsSystemColor());
    ASSERT_EQ("Bisque", Color::Bisque().Name());
    ASSERT_EQ("Color [Bisque]", Color::Bisque().ToString());
  }

  TEST(ColorTest, Black) {
    ASSERT_EQ(0xFF000000u, (unsigned)Color::Black().ToArgb());
    ASSERT_FALSE(Color::Black().IsEmpty());
    ASSERT_TRUE(Color::Black().IsKnownColor());
    ASSERT_TRUE(Color::Black().IsNamedColor());
    ASSERT_FALSE(Color::Black().IsSystemColor());
    ASSERT_EQ("Black", Color::Black().Name());
    ASSERT_EQ("Color [Black]", Color::Black().ToString());
  }

  TEST(ColorTest, BlanchedAlmond) {
    ASSERT_EQ(0xFFFFEBCDu, (unsigned)Color::BlanchedAlmond().ToArgb());
    ASSERT_FALSE(Color::BlanchedAlmond().IsEmpty());
    ASSERT_TRUE(Color::BlanchedAlmond().IsKnownColor());
    ASSERT_TRUE(Color::BlanchedAlmond().IsNamedColor());
    ASSERT_FALSE(Color::BlanchedAlmond().IsSystemColor());
    ASSERT_EQ("BlanchedAlmond", Color::BlanchedAlmond().Name());
    ASSERT_EQ("Color [BlanchedAlmond]", Color::BlanchedAlmond().ToString());
  }

  TEST(ColorTest, Blue) {
    ASSERT_EQ(0xFF0000FFu, (unsigned)Color::Blue().ToArgb());
    ASSERT_FALSE(Color::Blue().IsEmpty());
    ASSERT_TRUE(Color::Blue().IsKnownColor());
    ASSERT_TRUE(Color::Blue().IsNamedColor());
    ASSERT_FALSE(Color::Blue().IsSystemColor());
    ASSERT_EQ("Blue", Color::Blue().Name());
    ASSERT_EQ("Color [Blue]", Color::Blue().ToString());
  }

  TEST(ColorTest, BlueViolet) {
    ASSERT_EQ(0xFF8A2BE2u, (unsigned)Color::BlueViolet().ToArgb());
    ASSERT_FALSE(Color::BlueViolet().IsEmpty());
    ASSERT_TRUE(Color::BlueViolet().IsKnownColor());
    ASSERT_TRUE(Color::BlueViolet().IsNamedColor());
    ASSERT_FALSE(Color::BlueViolet().IsSystemColor());
    ASSERT_EQ("BlueViolet", Color::BlueViolet().Name());
    ASSERT_EQ("Color [BlueViolet]", Color::BlueViolet().ToString());
  }

  TEST(ColorTest, Brown) {
    ASSERT_EQ(0xFFA52A2Au, (unsigned)Color::Brown().ToArgb());
    ASSERT_FALSE(Color::Brown().IsEmpty());
    ASSERT_TRUE(Color::Brown().IsKnownColor());
    ASSERT_TRUE(Color::Brown().IsNamedColor());
    ASSERT_FALSE(Color::Brown().IsSystemColor());
    ASSERT_EQ("Brown", Color::Brown().Name());
    ASSERT_EQ("Color [Brown]", Color::Brown().ToString());
  }

  TEST(ColorTest, BurlyWood) {
    ASSERT_EQ(0xFFDEB887u, (unsigned)Color::BurlyWood().ToArgb());
    ASSERT_FALSE(Color::BurlyWood().IsEmpty());
    ASSERT_TRUE(Color::BurlyWood().IsKnownColor());
    ASSERT_TRUE(Color::BurlyWood().IsNamedColor());
    ASSERT_FALSE(Color::BurlyWood().IsSystemColor());
    ASSERT_EQ("BurlyWood", Color::BurlyWood().Name());
    ASSERT_EQ("Color [BurlyWood]", Color::BurlyWood().ToString());
  }

  TEST(ColorTest, CadetBlue) {
    ASSERT_EQ(0xFF5F9EA0u, (unsigned)Color::CadetBlue().ToArgb());
    ASSERT_FALSE(Color::CadetBlue().IsEmpty());
    ASSERT_TRUE(Color::CadetBlue().IsKnownColor());
    ASSERT_TRUE(Color::CadetBlue().IsNamedColor());
    ASSERT_FALSE(Color::CadetBlue().IsSystemColor());
    ASSERT_EQ("CadetBlue", Color::CadetBlue().Name());
    ASSERT_EQ("Color [CadetBlue]", Color::CadetBlue().ToString());
  }

  TEST(ColorTest, Chartreuse) {
    ASSERT_EQ(0xFF7FFF00u, (unsigned)Color::Chartreuse().ToArgb());
    ASSERT_FALSE(Color::Chartreuse().IsEmpty());
    ASSERT_TRUE(Color::Chartreuse().IsKnownColor());
    ASSERT_TRUE(Color::Chartreuse().IsNamedColor());
    ASSERT_FALSE(Color::Chartreuse().IsSystemColor());
    ASSERT_EQ("Chartreuse", Color::Chartreuse().Name());
    ASSERT_EQ("Color [Chartreuse]", Color::Chartreuse().ToString());
  }

  TEST(ColorTest, Chocolate) {
    ASSERT_EQ(0xFFD2691Eu, (unsigned)Color::Chocolate().ToArgb());
    ASSERT_FALSE(Color::Chocolate().IsEmpty());
    ASSERT_TRUE(Color::Chocolate().IsKnownColor());
    ASSERT_TRUE(Color::Chocolate().IsNamedColor());
    ASSERT_FALSE(Color::Chocolate().IsSystemColor());
    ASSERT_EQ("Chocolate", Color::Chocolate().Name());
    ASSERT_EQ("Color [Chocolate]", Color::Chocolate().ToString());
  }

  TEST(ColorTest, Coral) {
    ASSERT_EQ(0xFFFF7F50u, (unsigned)Color::Coral().ToArgb());
    ASSERT_FALSE(Color::Coral().IsEmpty());
    ASSERT_TRUE(Color::Coral().IsKnownColor());
    ASSERT_TRUE(Color::Coral().IsNamedColor());
    ASSERT_FALSE(Color::Coral().IsSystemColor());
    ASSERT_EQ("Coral", Color::Coral().Name());
    ASSERT_EQ("Color [Coral]", Color::Coral().ToString());
  }

  TEST(ColorTest, CornflowerBlue) {
    ASSERT_EQ(0xFF6495EDu, (unsigned)Color::CornflowerBlue().ToArgb());
    ASSERT_FALSE(Color::CornflowerBlue().IsEmpty());
    ASSERT_TRUE(Color::CornflowerBlue().IsKnownColor());
    ASSERT_TRUE(Color::CornflowerBlue().IsNamedColor());
    ASSERT_FALSE(Color::CornflowerBlue().IsSystemColor());
    ASSERT_EQ("CornflowerBlue", Color::CornflowerBlue().Name());
    ASSERT_EQ("Color [CornflowerBlue]", Color::CornflowerBlue().ToString());
  }

  TEST(ColorTest, Cornsilk) {
    ASSERT_EQ(0xFFFFF8DCu, (unsigned)Color::Cornsilk().ToArgb());
    ASSERT_FALSE(Color::Cornsilk().IsEmpty());
    ASSERT_TRUE(Color::Cornsilk().IsKnownColor());
    ASSERT_TRUE(Color::Cornsilk().IsNamedColor());
    ASSERT_FALSE(Color::Cornsilk().IsSystemColor());
    ASSERT_EQ("Cornsilk", Color::Cornsilk().Name());
    ASSERT_EQ("Color [Cornsilk]", Color::Cornsilk().ToString());
  }

  TEST(ColorTest, Crimson) {
    ASSERT_EQ(0xFFDC143Cu, (unsigned)Color::Crimson().ToArgb());
    ASSERT_FALSE(Color::Crimson().IsEmpty());
    ASSERT_TRUE(Color::Crimson().IsKnownColor());
    ASSERT_TRUE(Color::Crimson().IsNamedColor());
    ASSERT_FALSE(Color::Crimson().IsSystemColor());
    ASSERT_EQ("Crimson", Color::Crimson().Name());
    ASSERT_EQ("Color [Crimson]", Color::Crimson().ToString());
  }

  TEST(ColorTest, Cyan) {
    ASSERT_EQ(0xFF00FFFFu, (unsigned)Color::Cyan().ToArgb());
    ASSERT_FALSE(Color::Cyan().IsEmpty());
    ASSERT_TRUE(Color::Cyan().IsKnownColor());
    ASSERT_TRUE(Color::Cyan().IsNamedColor());
    ASSERT_FALSE(Color::Cyan().IsSystemColor());
    ASSERT_EQ("Cyan", Color::Cyan().Name());
    ASSERT_EQ("Color [Cyan]", Color::Cyan().ToString());
  }

  TEST(ColorTest, DarkBlue) {
    ASSERT_EQ(0xFF00008Bu, (unsigned)Color::DarkBlue().ToArgb());
    ASSERT_FALSE(Color::DarkBlue().IsEmpty());
    ASSERT_TRUE(Color::DarkBlue().IsKnownColor());
    ASSERT_TRUE(Color::DarkBlue().IsNamedColor());
    ASSERT_FALSE(Color::DarkBlue().IsSystemColor());
    ASSERT_EQ("DarkBlue", Color::DarkBlue().Name());
    ASSERT_EQ("Color [DarkBlue]", Color::DarkBlue().ToString());
  }

  TEST(ColorTest, DarkCyan) {
    ASSERT_EQ(0xFF008B8Bu, (unsigned)Color::DarkCyan().ToArgb());
    ASSERT_FALSE(Color::DarkCyan().IsEmpty());
    ASSERT_TRUE(Color::DarkCyan().IsKnownColor());
    ASSERT_TRUE(Color::DarkCyan().IsNamedColor());
    ASSERT_FALSE(Color::DarkCyan().IsSystemColor());
    ASSERT_EQ("DarkCyan", Color::DarkCyan().Name());
    ASSERT_EQ("Color [DarkCyan]", Color::DarkCyan().ToString());
  }

  TEST(ColorTest, DarkGoldenrod) {
    ASSERT_EQ(0xFFB8860Bu, (unsigned)Color::DarkGoldenrod().ToArgb());
    ASSERT_FALSE(Color::DarkGoldenrod().IsEmpty());
    ASSERT_TRUE(Color::DarkGoldenrod().IsKnownColor());
    ASSERT_TRUE(Color::DarkGoldenrod().IsNamedColor());
    ASSERT_FALSE(Color::DarkGoldenrod().IsSystemColor());
    ASSERT_EQ("DarkGoldenrod", Color::DarkGoldenrod().Name());
    ASSERT_EQ("Color [DarkGoldenrod]", Color::DarkGoldenrod().ToString());
  }

  TEST(ColorTest, DarkGray) {
    ASSERT_EQ(0xFFA9A9A9u, (unsigned)Color::DarkGray().ToArgb());
    ASSERT_FALSE(Color::DarkGray().IsEmpty());
    ASSERT_TRUE(Color::DarkGray().IsKnownColor());
    ASSERT_TRUE(Color::DarkGray().IsNamedColor());
    ASSERT_FALSE(Color::DarkGray().IsSystemColor());
    ASSERT_EQ("DarkGray", Color::DarkGray().Name());
    ASSERT_EQ("Color [DarkGray]", Color::DarkGray().ToString());
  }

  TEST(ColorTest, DarkGreen) {
    ASSERT_EQ(0xFF006400u, (unsigned)Color::DarkGreen().ToArgb());
    ASSERT_FALSE(Color::DarkGreen().IsEmpty());
    ASSERT_TRUE(Color::DarkGreen().IsKnownColor());
    ASSERT_TRUE(Color::DarkGreen().IsNamedColor());
    ASSERT_FALSE(Color::DarkGreen().IsSystemColor());
    ASSERT_EQ("DarkGreen", Color::DarkGreen().Name());
    ASSERT_EQ("Color [DarkGreen]", Color::DarkGreen().ToString());
  }

  TEST(ColorTest, DarkKhaki) {
    ASSERT_EQ(0xFFBDB76Bu, (unsigned)Color::DarkKhaki().ToArgb());
    ASSERT_FALSE(Color::DarkKhaki().IsEmpty());
    ASSERT_TRUE(Color::DarkKhaki().IsKnownColor());
    ASSERT_TRUE(Color::DarkKhaki().IsNamedColor());
    ASSERT_FALSE(Color::DarkKhaki().IsSystemColor());
    ASSERT_EQ("DarkKhaki", Color::DarkKhaki().Name());
    ASSERT_EQ("Color [DarkKhaki]", Color::DarkKhaki().ToString());
  }

  TEST(ColorTest, DarkMagenta) {
    ASSERT_EQ(0xFF8B008Bu, (unsigned)Color::DarkMagenta().ToArgb());
    ASSERT_FALSE(Color::DarkMagenta().IsEmpty());
    ASSERT_TRUE(Color::DarkMagenta().IsKnownColor());
    ASSERT_TRUE(Color::DarkMagenta().IsNamedColor());
    ASSERT_FALSE(Color::DarkMagenta().IsSystemColor());
    ASSERT_EQ("DarkMagenta", Color::DarkMagenta().Name());
    ASSERT_EQ("Color [DarkMagenta]", Color::DarkMagenta().ToString());
  }

  TEST(ColorTest, DarkOliveGreen) {
    ASSERT_EQ(0xFF556B2Fu, (unsigned)Color::DarkOliveGreen().ToArgb());
    ASSERT_FALSE(Color::DarkOliveGreen().IsEmpty());
    ASSERT_TRUE(Color::DarkOliveGreen().IsKnownColor());
    ASSERT_TRUE(Color::DarkOliveGreen().IsNamedColor());
    ASSERT_FALSE(Color::DarkOliveGreen().IsSystemColor());
    ASSERT_EQ("DarkOliveGreen", Color::DarkOliveGreen().Name());
    ASSERT_EQ("Color [DarkOliveGreen]", Color::DarkOliveGreen().ToString());
  }

  TEST(ColorTest, DarkOrange) {
    ASSERT_EQ(0xFFFF8C00u, (unsigned)Color::DarkOrange().ToArgb());
    ASSERT_FALSE(Color::DarkOrange().IsEmpty());
    ASSERT_TRUE(Color::DarkOrange().IsKnownColor());
    ASSERT_TRUE(Color::DarkOrange().IsNamedColor());
    ASSERT_FALSE(Color::DarkOrange().IsSystemColor());
    ASSERT_EQ("DarkOrange", Color::DarkOrange().Name());
    ASSERT_EQ("Color [DarkOrange]", Color::DarkOrange().ToString());
  }

  TEST(ColorTest, DarkOrchid) {
    ASSERT_EQ(0xFF9932CCu, (unsigned)Color::DarkOrchid().ToArgb());
    ASSERT_FALSE(Color::DarkOrchid().IsEmpty());
    ASSERT_TRUE(Color::DarkOrchid().IsKnownColor());
    ASSERT_TRUE(Color::DarkOrchid().IsNamedColor());
    ASSERT_FALSE(Color::DarkOrchid().IsSystemColor());
    ASSERT_EQ("DarkOrchid", Color::DarkOrchid().Name());
    ASSERT_EQ("Color [DarkOrchid]", Color::DarkOrchid().ToString());
  }

  TEST(ColorTest, DarkRed) {
    ASSERT_EQ(0xFF8B0000u, (unsigned)Color::DarkRed().ToArgb());
    ASSERT_FALSE(Color::DarkRed().IsEmpty());
    ASSERT_TRUE(Color::DarkRed().IsKnownColor());
    ASSERT_TRUE(Color::DarkRed().IsNamedColor());
    ASSERT_FALSE(Color::DarkRed().IsSystemColor());
    ASSERT_EQ("DarkRed", Color::DarkRed().Name());
    ASSERT_EQ("Color [DarkRed]", Color::DarkRed().ToString());
  }

  TEST(ColorTest, DarkSalmon) {
    ASSERT_EQ(0xFFE9967Au, (unsigned)Color::DarkSalmon().ToArgb());
    ASSERT_FALSE(Color::DarkSalmon().IsEmpty());
    ASSERT_TRUE(Color::DarkSalmon().IsKnownColor());
    ASSERT_TRUE(Color::DarkSalmon().IsNamedColor());
    ASSERT_FALSE(Color::DarkSalmon().IsSystemColor());
    ASSERT_EQ("DarkSalmon", Color::DarkSalmon().Name());
    ASSERT_EQ("Color [DarkSalmon]", Color::DarkSalmon().ToString());
  }

  TEST(ColorTest, DarkSeaGreen) {
    ASSERT_EQ(0xFF8FBC8Bu, (unsigned)Color::DarkSeaGreen().ToArgb());
    ASSERT_FALSE(Color::DarkSeaGreen().IsEmpty());
    ASSERT_TRUE(Color::DarkSeaGreen().IsKnownColor());
    ASSERT_TRUE(Color::DarkSeaGreen().IsNamedColor());
    ASSERT_FALSE(Color::DarkSeaGreen().IsSystemColor());
    ASSERT_EQ("DarkSeaGreen", Color::DarkSeaGreen().Name());
    ASSERT_EQ("Color [DarkSeaGreen]", Color::DarkSeaGreen().ToString());
  }

  TEST(ColorTest, DarkSlateBlue) {
    ASSERT_EQ(0xFF483D8Bu, (unsigned)Color::DarkSlateBlue().ToArgb());
    ASSERT_FALSE(Color::DarkSlateBlue().IsEmpty());
    ASSERT_TRUE(Color::DarkSlateBlue().IsKnownColor());
    ASSERT_TRUE(Color::DarkSlateBlue().IsNamedColor());
    ASSERT_FALSE(Color::DarkSlateBlue().IsSystemColor());
    ASSERT_EQ("DarkSlateBlue", Color::DarkSlateBlue().Name());
    ASSERT_EQ("Color [DarkSlateBlue]", Color::DarkSlateBlue().ToString());
  }

  TEST(ColorTest, DarkSlateGray) {
    ASSERT_EQ(0xFF2F4F4Fu, (unsigned)Color::DarkSlateGray().ToArgb());
    ASSERT_FALSE(Color::DarkSlateGray().IsEmpty());
    ASSERT_TRUE(Color::DarkSlateGray().IsKnownColor());
    ASSERT_TRUE(Color::DarkSlateGray().IsNamedColor());
    ASSERT_FALSE(Color::DarkSlateGray().IsSystemColor());
    ASSERT_EQ("DarkSlateGray", Color::DarkSlateGray().Name());
    ASSERT_EQ("Color [DarkSlateGray]", Color::DarkSlateGray().ToString());
  }

  TEST(ColorTest, DarkTurquoise) {
    ASSERT_EQ(0xFF00CED1u, (unsigned)Color::DarkTurquoise().ToArgb());
    ASSERT_FALSE(Color::DarkTurquoise().IsEmpty());
    ASSERT_TRUE(Color::DarkTurquoise().IsKnownColor());
    ASSERT_TRUE(Color::DarkTurquoise().IsNamedColor());
    ASSERT_FALSE(Color::DarkTurquoise().IsSystemColor());
    ASSERT_EQ("DarkTurquoise", Color::DarkTurquoise().Name());
    ASSERT_EQ("Color [DarkTurquoise]", Color::DarkTurquoise().ToString());
  }

  TEST(ColorTest, DarkViolet) {
    ASSERT_EQ(0xFF9400D3u, (unsigned)Color::DarkViolet().ToArgb());
    ASSERT_FALSE(Color::DarkViolet().IsEmpty());
    ASSERT_TRUE(Color::DarkViolet().IsKnownColor());
    ASSERT_TRUE(Color::DarkViolet().IsNamedColor());
    ASSERT_FALSE(Color::DarkViolet().IsSystemColor());
    ASSERT_EQ("DarkViolet", Color::DarkViolet().Name());
    ASSERT_EQ("Color [DarkViolet]", Color::DarkViolet().ToString());
  }

  TEST(ColorTest, DeepPink) {
    ASSERT_EQ(0xFFFF1493u, (unsigned)Color::DeepPink().ToArgb());
    ASSERT_FALSE(Color::DeepPink().IsEmpty());
    ASSERT_TRUE(Color::DeepPink().IsKnownColor());
    ASSERT_TRUE(Color::DeepPink().IsNamedColor());
    ASSERT_FALSE(Color::DeepPink().IsSystemColor());
    ASSERT_EQ("DeepPink", Color::DeepPink().Name());
    ASSERT_EQ("Color [DeepPink]", Color::DeepPink().ToString());
  }

  TEST(ColorTest, DeepSkyBlue) {
    ASSERT_EQ(0xFF00BFFFu, (unsigned)Color::DeepSkyBlue().ToArgb());
    ASSERT_FALSE(Color::DeepSkyBlue().IsEmpty());
    ASSERT_TRUE(Color::DeepSkyBlue().IsKnownColor());
    ASSERT_TRUE(Color::DeepSkyBlue().IsNamedColor());
    ASSERT_FALSE(Color::DeepSkyBlue().IsSystemColor());
    ASSERT_EQ("DeepSkyBlue", Color::DeepSkyBlue().Name());
    ASSERT_EQ("Color [DeepSkyBlue]", Color::DeepSkyBlue().ToString());
  }

  TEST(ColorTest, DimGray) {
    ASSERT_EQ(0xFF696969u, (unsigned)Color::DimGray().ToArgb());
    ASSERT_FALSE(Color::DimGray().IsEmpty());
    ASSERT_TRUE(Color::DimGray().IsKnownColor());
    ASSERT_TRUE(Color::DimGray().IsNamedColor());
    ASSERT_FALSE(Color::DimGray().IsSystemColor());
    ASSERT_EQ("DimGray", Color::DimGray().Name());
    ASSERT_EQ("Color [DimGray]", Color::DimGray().ToString());
  }

  TEST(ColorTest, DodgerBlue) {
    ASSERT_EQ(0xFF1E90FFu, (unsigned)Color::DodgerBlue().ToArgb());
    ASSERT_FALSE(Color::DodgerBlue().IsEmpty());
    ASSERT_TRUE(Color::DodgerBlue().IsKnownColor());
    ASSERT_TRUE(Color::DodgerBlue().IsNamedColor());
    ASSERT_FALSE(Color::DodgerBlue().IsSystemColor());
    ASSERT_EQ("DodgerBlue", Color::DodgerBlue().Name());
    ASSERT_EQ("Color [DodgerBlue]", Color::DodgerBlue().ToString());
  }

  TEST(ColorTest, Firebrick) {
    ASSERT_EQ(0xFFB22222u, (unsigned)Color::Firebrick().ToArgb());
    ASSERT_FALSE(Color::Firebrick().IsEmpty());
    ASSERT_TRUE(Color::Firebrick().IsKnownColor());
    ASSERT_TRUE(Color::Firebrick().IsNamedColor());
    ASSERT_FALSE(Color::Firebrick().IsSystemColor());
    ASSERT_EQ("Firebrick", Color::Firebrick().Name());
    ASSERT_EQ("Color [Firebrick]", Color::Firebrick().ToString());
  }

  TEST(ColorTest, FloralWhite) {
    ASSERT_EQ(0xFFFFFAF0u, (unsigned)Color::FloralWhite().ToArgb());
    ASSERT_FALSE(Color::FloralWhite().IsEmpty());
    ASSERT_TRUE(Color::FloralWhite().IsKnownColor());
    ASSERT_TRUE(Color::FloralWhite().IsNamedColor());
    ASSERT_FALSE(Color::FloralWhite().IsSystemColor());
    ASSERT_EQ("FloralWhite", Color::FloralWhite().Name());
    ASSERT_EQ("Color [FloralWhite]", Color::FloralWhite().ToString());
  }

  TEST(ColorTest, ForestGreen) {
    ASSERT_EQ(0xFF228B22u, (unsigned)Color::ForestGreen().ToArgb());
    ASSERT_FALSE(Color::ForestGreen().IsEmpty());
    ASSERT_TRUE(Color::ForestGreen().IsKnownColor());
    ASSERT_TRUE(Color::ForestGreen().IsNamedColor());
    ASSERT_FALSE(Color::ForestGreen().IsSystemColor());
    ASSERT_EQ("ForestGreen", Color::ForestGreen().Name());
    ASSERT_EQ("Color [ForestGreen]", Color::ForestGreen().ToString());
  }

  TEST(ColorTest, Fuchsia) {
    ASSERT_EQ(0xFFFF00FFu, (unsigned)Color::Fuchsia().ToArgb());
    ASSERT_FALSE(Color::Fuchsia().IsEmpty());
    ASSERT_TRUE(Color::Fuchsia().IsKnownColor());
    ASSERT_TRUE(Color::Fuchsia().IsNamedColor());
    ASSERT_FALSE(Color::Fuchsia().IsSystemColor());
    ASSERT_EQ("Fuchsia", Color::Fuchsia().Name());
    ASSERT_EQ("Color [Fuchsia]", Color::Fuchsia().ToString());
  }

  TEST(ColorTest, Gainsboro) {
    ASSERT_EQ(0xFFDCDCDCu, (unsigned)Color::Gainsboro().ToArgb());
    ASSERT_FALSE(Color::Gainsboro().IsEmpty());
    ASSERT_TRUE(Color::Gainsboro().IsKnownColor());
    ASSERT_TRUE(Color::Gainsboro().IsNamedColor());
    ASSERT_FALSE(Color::Gainsboro().IsSystemColor());
    ASSERT_EQ("Gainsboro", Color::Gainsboro().Name());
    ASSERT_EQ("Color [Gainsboro]", Color::Gainsboro().ToString());
  }

  TEST(ColorTest, GhostWhite) {
    ASSERT_EQ(0xFFF8F8FFu, (unsigned)Color::GhostWhite().ToArgb());
    ASSERT_FALSE(Color::GhostWhite().IsEmpty());
    ASSERT_TRUE(Color::GhostWhite().IsKnownColor());
    ASSERT_TRUE(Color::GhostWhite().IsNamedColor());
    ASSERT_FALSE(Color::GhostWhite().IsSystemColor());
    ASSERT_EQ("GhostWhite", Color::GhostWhite().Name());
    ASSERT_EQ("Color [GhostWhite]", Color::GhostWhite().ToString());
  }

  TEST(ColorTest, Gold) {
    ASSERT_EQ(0xFFFFD700u, (unsigned)Color::Gold().ToArgb());
    ASSERT_FALSE(Color::Gold().IsEmpty());
    ASSERT_TRUE(Color::Gold().IsKnownColor());
    ASSERT_TRUE(Color::Gold().IsNamedColor());
    ASSERT_FALSE(Color::Gold().IsSystemColor());
    ASSERT_EQ("Gold", Color::Gold().Name());
    ASSERT_EQ("Color [Gold]", Color::Gold().ToString());
  }

  TEST(ColorTest, Goldenrod) {
    ASSERT_EQ(0xFFDAA520u, (unsigned)Color::Goldenrod().ToArgb());
    ASSERT_FALSE(Color::Goldenrod().IsEmpty());
    ASSERT_TRUE(Color::Goldenrod().IsKnownColor());
    ASSERT_TRUE(Color::Goldenrod().IsNamedColor());
    ASSERT_FALSE(Color::Goldenrod().IsSystemColor());
    ASSERT_EQ("Goldenrod", Color::Goldenrod().Name());
    ASSERT_EQ("Color [Goldenrod]", Color::Goldenrod().ToString());
  }

  TEST(ColorTest, Gray) {
    ASSERT_EQ(0xFF808080u, (unsigned)Color::Gray().ToArgb());
    ASSERT_FALSE(Color::Gray().IsEmpty());
    ASSERT_TRUE(Color::Gray().IsKnownColor());
    ASSERT_TRUE(Color::Gray().IsNamedColor());
    ASSERT_FALSE(Color::Gray().IsSystemColor());
    ASSERT_EQ("Gray", Color::Gray().Name());
    ASSERT_EQ("Color [Gray]", Color::Gray().ToString());
  }

  TEST(ColorTest, Green) {
    ASSERT_EQ(0xFF008000u, (unsigned)Color::Green().ToArgb());
    ASSERT_FALSE(Color::Green().IsEmpty());
    ASSERT_TRUE(Color::Green().IsKnownColor());
    ASSERT_TRUE(Color::Green().IsNamedColor());
    ASSERT_FALSE(Color::Green().IsSystemColor());
    ASSERT_EQ("Green", Color::Green().Name());
    ASSERT_EQ("Color [Green]", Color::Green().ToString());
  }

  TEST(ColorTest, GreenYellow) {
    ASSERT_EQ(0xFFADFF2Fu, (unsigned)Color::GreenYellow().ToArgb());
    ASSERT_FALSE(Color::GreenYellow().IsEmpty());
    ASSERT_TRUE(Color::GreenYellow().IsKnownColor());
    ASSERT_TRUE(Color::GreenYellow().IsNamedColor());
    ASSERT_FALSE(Color::GreenYellow().IsSystemColor());
    ASSERT_EQ("GreenYellow", Color::GreenYellow().Name());
    ASSERT_EQ("Color [GreenYellow]", Color::GreenYellow().ToString());
  }

  TEST(ColorTest, Honeydew) {
    ASSERT_EQ(0xFFF0FFF0u, (unsigned)Color::Honeydew().ToArgb());
    ASSERT_FALSE(Color::Honeydew().IsEmpty());
    ASSERT_TRUE(Color::Honeydew().IsKnownColor());
    ASSERT_TRUE(Color::Honeydew().IsNamedColor());
    ASSERT_FALSE(Color::Honeydew().IsSystemColor());
    ASSERT_EQ("Honeydew", Color::Honeydew().Name());
    ASSERT_EQ("Color [Honeydew]", Color::Honeydew().ToString());
  }

  TEST(ColorTest, HotPink) {
    ASSERT_EQ(0xFFFF69B4u, (unsigned)Color::HotPink().ToArgb());
    ASSERT_FALSE(Color::HotPink().IsEmpty());
    ASSERT_TRUE(Color::HotPink().IsKnownColor());
    ASSERT_TRUE(Color::HotPink().IsNamedColor());
    ASSERT_FALSE(Color::HotPink().IsSystemColor());
    ASSERT_EQ("HotPink", Color::HotPink().Name());
    ASSERT_EQ("Color [HotPink]", Color::HotPink().ToString());
  }

  TEST(ColorTest, IndianRed) {
    ASSERT_EQ(0xFFCD5C5Cu, (unsigned)Color::IndianRed().ToArgb());
    ASSERT_FALSE(Color::IndianRed().IsEmpty());
    ASSERT_TRUE(Color::IndianRed().IsKnownColor());
    ASSERT_TRUE(Color::IndianRed().IsNamedColor());
    ASSERT_FALSE(Color::IndianRed().IsSystemColor());
    ASSERT_EQ("IndianRed", Color::IndianRed().Name());
    ASSERT_EQ("Color [IndianRed]", Color::IndianRed().ToString());
  }

  TEST(ColorTest, Indigo) {
    ASSERT_EQ(0xFF4B0082u, (unsigned)Color::Indigo().ToArgb());
    ASSERT_FALSE(Color::Indigo().IsEmpty());
    ASSERT_TRUE(Color::Indigo().IsKnownColor());
    ASSERT_TRUE(Color::Indigo().IsNamedColor());
    ASSERT_FALSE(Color::Indigo().IsSystemColor());
    ASSERT_EQ("Indigo", Color::Indigo().Name());
    ASSERT_EQ("Color [Indigo]", Color::Indigo().ToString());
  }

  TEST(ColorTest, Ivory) {
    ASSERT_EQ(0xFFFFFFF0u, (unsigned)Color::Ivory().ToArgb());
    ASSERT_FALSE(Color::Ivory().IsEmpty());
    ASSERT_TRUE(Color::Ivory().IsKnownColor());
    ASSERT_TRUE(Color::Ivory().IsNamedColor());
    ASSERT_FALSE(Color::Ivory().IsSystemColor());
    ASSERT_EQ("Ivory", Color::Ivory().Name());
    ASSERT_EQ("Color [Ivory]", Color::Ivory().ToString());
  }

  TEST(ColorTest, Khaki) {
    ASSERT_EQ(0xFFF0E68Cu, (unsigned)Color::Khaki().ToArgb());
    ASSERT_FALSE(Color::Khaki().IsEmpty());
    ASSERT_TRUE(Color::Khaki().IsKnownColor());
    ASSERT_TRUE(Color::Khaki().IsNamedColor());
    ASSERT_FALSE(Color::Khaki().IsSystemColor());
    ASSERT_EQ("Khaki", Color::Khaki().Name());
    ASSERT_EQ("Color [Khaki]", Color::Khaki().ToString());
  }

  TEST(ColorTest, Lavender) {
    ASSERT_EQ(0xFFE6E6FAu, (unsigned)Color::Lavender().ToArgb());
    ASSERT_FALSE(Color::Lavender().IsEmpty());
    ASSERT_TRUE(Color::Lavender().IsKnownColor());
    ASSERT_TRUE(Color::Lavender().IsNamedColor());
    ASSERT_FALSE(Color::Lavender().IsSystemColor());
    ASSERT_EQ("Lavender", Color::Lavender().Name());
    ASSERT_EQ("Color [Lavender]", Color::Lavender().ToString());
  }

  TEST(ColorTest, LavenderBlush) {
    ASSERT_EQ(0xFFFFF0F5u, (unsigned)Color::LavenderBlush().ToArgb());
    ASSERT_FALSE(Color::LavenderBlush().IsEmpty());
    ASSERT_TRUE(Color::LavenderBlush().IsKnownColor());
    ASSERT_TRUE(Color::LavenderBlush().IsNamedColor());
    ASSERT_FALSE(Color::LavenderBlush().IsSystemColor());
    ASSERT_EQ("LavenderBlush", Color::LavenderBlush().Name());
    ASSERT_EQ("Color [LavenderBlush]", Color::LavenderBlush().ToString());
  }

  TEST(ColorTest, LawnGreen) {
    ASSERT_EQ(0xFF7CFC00u, (unsigned)Color::LawnGreen().ToArgb());
    ASSERT_FALSE(Color::LawnGreen().IsEmpty());
    ASSERT_TRUE(Color::LawnGreen().IsKnownColor());
    ASSERT_TRUE(Color::LawnGreen().IsNamedColor());
    ASSERT_FALSE(Color::LawnGreen().IsSystemColor());
    ASSERT_EQ("LawnGreen", Color::LawnGreen().Name());
    ASSERT_EQ("Color [LawnGreen]", Color::LawnGreen().ToString());
  }

  TEST(ColorTest, LemonChiffon) {
    ASSERT_EQ(0xFFFFFACDu, (unsigned)Color::LemonChiffon().ToArgb());
    ASSERT_FALSE(Color::LemonChiffon().IsEmpty());
    ASSERT_TRUE(Color::LemonChiffon().IsKnownColor());
    ASSERT_TRUE(Color::LemonChiffon().IsNamedColor());
    ASSERT_FALSE(Color::LemonChiffon().IsSystemColor());
    ASSERT_EQ("LemonChiffon", Color::LemonChiffon().Name());
    ASSERT_EQ("Color [LemonChiffon]", Color::LemonChiffon().ToString());
  }

  TEST(ColorTest, LightBlue) {
    ASSERT_EQ(0xFFADD8E6u, (unsigned)Color::LightBlue().ToArgb());
    ASSERT_FALSE(Color::LightBlue().IsEmpty());
    ASSERT_TRUE(Color::LightBlue().IsKnownColor());
    ASSERT_TRUE(Color::LightBlue().IsNamedColor());
    ASSERT_FALSE(Color::LightBlue().IsSystemColor());
    ASSERT_EQ("LightBlue", Color::LightBlue().Name());
    ASSERT_EQ("Color [LightBlue]", Color::LightBlue().ToString());
  }

  TEST(ColorTest, LightCoral) {
    ASSERT_EQ(0xFFF08080u, (unsigned)Color::LightCoral().ToArgb());
    ASSERT_FALSE(Color::LightCoral().IsEmpty());
    ASSERT_TRUE(Color::LightCoral().IsKnownColor());
    ASSERT_TRUE(Color::LightCoral().IsNamedColor());
    ASSERT_FALSE(Color::LightCoral().IsSystemColor());
    ASSERT_EQ("LightCoral", Color::LightCoral().Name());
    ASSERT_EQ("Color [LightCoral]", Color::LightCoral().ToString());
  }

  TEST(ColorTest, LightCyan) {
    ASSERT_EQ(0xFFE0FFFFu, (unsigned)Color::LightCyan().ToArgb());
    ASSERT_FALSE(Color::LightCyan().IsEmpty());
    ASSERT_TRUE(Color::LightCyan().IsKnownColor());
    ASSERT_TRUE(Color::LightCyan().IsNamedColor());
    ASSERT_FALSE(Color::LightCyan().IsSystemColor());
    ASSERT_EQ("LightCyan", Color::LightCyan().Name());
    ASSERT_EQ("Color [LightCyan]", Color::LightCyan().ToString());
  }

  TEST(ColorTest, LightGoldenrodYellow) {
    ASSERT_EQ(0xFFFAFAD2u, (unsigned)Color::LightGoldenrodYellow().ToArgb());
    ASSERT_FALSE(Color::LightGoldenrodYellow().IsEmpty());
    ASSERT_TRUE(Color::LightGoldenrodYellow().IsKnownColor());
    ASSERT_TRUE(Color::LightGoldenrodYellow().IsNamedColor());
    ASSERT_FALSE(Color::LightGoldenrodYellow().IsSystemColor());
    ASSERT_EQ("LightGoldenrodYellow", Color::LightGoldenrodYellow().Name());
    ASSERT_EQ("Color [LightGoldenrodYellow]", Color::LightGoldenrodYellow().ToString());
  }

  TEST(ColorTest, LightGray) {
    ASSERT_EQ(0xFFD3D3D3u, (unsigned)Color::LightGray().ToArgb());
    ASSERT_FALSE(Color::LightGray().IsEmpty());
    ASSERT_TRUE(Color::LightGray().IsKnownColor());
    ASSERT_TRUE(Color::LightGray().IsNamedColor());
    ASSERT_FALSE(Color::LightGray().IsSystemColor());
    ASSERT_EQ("LightGray", Color::LightGray().Name());
    ASSERT_EQ("Color [LightGray]", Color::LightGray().ToString());
  }

  TEST(ColorTest, LightGreen) {
    ASSERT_EQ(0xFF90EE90u, (unsigned)Color::LightGreen().ToArgb());
    ASSERT_FALSE(Color::LightGreen().IsEmpty());
    ASSERT_TRUE(Color::LightGreen().IsKnownColor());
    ASSERT_TRUE(Color::LightGreen().IsNamedColor());
    ASSERT_FALSE(Color::LightGreen().IsSystemColor());
    ASSERT_EQ("LightGreen", Color::LightGreen().Name());
    ASSERT_EQ("Color [LightGreen]", Color::LightGreen().ToString());
  }

  TEST(ColorTest, LightPink) {
    ASSERT_EQ(0xFFFFB6C1u, (unsigned)Color::LightPink().ToArgb());
    ASSERT_FALSE(Color::LightPink().IsEmpty());
    ASSERT_TRUE(Color::LightPink().IsKnownColor());
    ASSERT_TRUE(Color::LightPink().IsNamedColor());
    ASSERT_FALSE(Color::LightPink().IsSystemColor());
    ASSERT_EQ("LightPink", Color::LightPink().Name());
    ASSERT_EQ("Color [LightPink]", Color::LightPink().ToString());
  }

  TEST(ColorTest, LightSalmon) {
    ASSERT_EQ(0xFFFFA07Au, (unsigned)Color::LightSalmon().ToArgb());
    ASSERT_FALSE(Color::LightSalmon().IsEmpty());
    ASSERT_TRUE(Color::LightSalmon().IsKnownColor());
    ASSERT_TRUE(Color::LightSalmon().IsNamedColor());
    ASSERT_FALSE(Color::LightSalmon().IsSystemColor());
    ASSERT_EQ("LightSalmon", Color::LightSalmon().Name());
    ASSERT_EQ("Color [LightSalmon]", Color::LightSalmon().ToString());
  }

  TEST(ColorTest, LightSeaGreen) {
    ASSERT_EQ(0xFF20B2AAu, (unsigned)Color::LightSeaGreen().ToArgb());
    ASSERT_FALSE(Color::LightSeaGreen().IsEmpty());
    ASSERT_TRUE(Color::LightSeaGreen().IsKnownColor());
    ASSERT_TRUE(Color::LightSeaGreen().IsNamedColor());
    ASSERT_FALSE(Color::LightSeaGreen().IsSystemColor());
    ASSERT_EQ("LightSeaGreen", Color::LightSeaGreen().Name());
    ASSERT_EQ("Color [LightSeaGreen]", Color::LightSeaGreen().ToString());
  }

  TEST(ColorTest, LightSkyBlue) {
    ASSERT_EQ(0xFF87CEFAu, (unsigned)Color::LightSkyBlue().ToArgb());
    ASSERT_FALSE(Color::LightSkyBlue().IsEmpty());
    ASSERT_TRUE(Color::LightSkyBlue().IsKnownColor());
    ASSERT_TRUE(Color::LightSkyBlue().IsNamedColor());
    ASSERT_FALSE(Color::LightSkyBlue().IsSystemColor());
    ASSERT_EQ("LightSkyBlue", Color::LightSkyBlue().Name());
    ASSERT_EQ("Color [LightSkyBlue]", Color::LightSkyBlue().ToString());
  }

  TEST(ColorTest, LightSlateGray) {
    ASSERT_EQ(0xFF778899u, (unsigned)Color::LightSlateGray().ToArgb());
    ASSERT_FALSE(Color::LightSlateGray().IsEmpty());
    ASSERT_TRUE(Color::LightSlateGray().IsKnownColor());
    ASSERT_TRUE(Color::LightSlateGray().IsNamedColor());
    ASSERT_FALSE(Color::LightSlateGray().IsSystemColor());
    ASSERT_EQ("LightSlateGray", Color::LightSlateGray().Name());
    ASSERT_EQ("Color [LightSlateGray]", Color::LightSlateGray().ToString());
  }

  TEST(ColorTest, LightSteelBlue) {
    ASSERT_EQ(0xFFB0C4DEu, (unsigned)Color::LightSteelBlue().ToArgb());
    ASSERT_FALSE(Color::LightSteelBlue().IsEmpty());
    ASSERT_TRUE(Color::LightSteelBlue().IsKnownColor());
    ASSERT_TRUE(Color::LightSteelBlue().IsNamedColor());
    ASSERT_FALSE(Color::LightSteelBlue().IsSystemColor());
    ASSERT_EQ("LightSteelBlue", Color::LightSteelBlue().Name());
    ASSERT_EQ("Color [LightSteelBlue]", Color::LightSteelBlue().ToString());
  }

  TEST(ColorTest, LightYellow) {
    ASSERT_EQ(0xFFFFFFE0u, (unsigned)Color::LightYellow().ToArgb());
    ASSERT_FALSE(Color::LightYellow().IsEmpty());
    ASSERT_TRUE(Color::LightYellow().IsKnownColor());
    ASSERT_TRUE(Color::LightYellow().IsNamedColor());
    ASSERT_FALSE(Color::LightYellow().IsSystemColor());
    ASSERT_EQ("LightYellow", Color::LightYellow().Name());
    ASSERT_EQ("Color [LightYellow]", Color::LightYellow().ToString());
  }

  TEST(ColorTest, Lime) {
    ASSERT_EQ(0xFF00FF00u, (unsigned)Color::Lime().ToArgb());
    ASSERT_FALSE(Color::Lime().IsEmpty());
    ASSERT_TRUE(Color::Lime().IsKnownColor());
    ASSERT_TRUE(Color::Lime().IsNamedColor());
    ASSERT_FALSE(Color::Lime().IsSystemColor());
    ASSERT_EQ("Lime", Color::Lime().Name());
    ASSERT_EQ("Color [Lime]", Color::Lime().ToString());
  }

  TEST(ColorTest, LimeGreen) {
    ASSERT_EQ(0xFF32CD32u, (unsigned)Color::LimeGreen().ToArgb());
    ASSERT_FALSE(Color::LimeGreen().IsEmpty());
    ASSERT_TRUE(Color::LimeGreen().IsKnownColor());
    ASSERT_TRUE(Color::LimeGreen().IsNamedColor());
    ASSERT_FALSE(Color::LimeGreen().IsSystemColor());
    ASSERT_EQ("LimeGreen", Color::LimeGreen().Name());
    ASSERT_EQ("Color [LimeGreen]", Color::LimeGreen().ToString());
  }

  TEST(ColorTest, Linen) {
    ASSERT_EQ(0xFFFAF0E6u, (unsigned)Color::Linen().ToArgb());
    ASSERT_FALSE(Color::Linen().IsEmpty());
    ASSERT_TRUE(Color::Linen().IsKnownColor());
    ASSERT_TRUE(Color::Linen().IsNamedColor());
    ASSERT_FALSE(Color::Linen().IsSystemColor());
    ASSERT_EQ("Linen", Color::Linen().Name());
    ASSERT_EQ("Color [Linen]", Color::Linen().ToString());
  }

  TEST(ColorTest, Magenta) {
    ASSERT_EQ(0xFFFF00FFu, (unsigned)Color::Magenta().ToArgb());
    ASSERT_FALSE(Color::Magenta().IsEmpty());
    ASSERT_TRUE(Color::Magenta().IsKnownColor());
    ASSERT_TRUE(Color::Magenta().IsNamedColor());
    ASSERT_FALSE(Color::Magenta().IsSystemColor());
    ASSERT_EQ("Magenta", Color::Magenta().Name());
    ASSERT_EQ("Color [Magenta]", Color::Magenta().ToString());
  }

  TEST(ColorTest, Maroon) {
    ASSERT_EQ(0xFF800000u, (unsigned)Color::Maroon().ToArgb());
    ASSERT_FALSE(Color::Maroon().IsEmpty());
    ASSERT_TRUE(Color::Maroon().IsKnownColor());
    ASSERT_TRUE(Color::Maroon().IsNamedColor());
    ASSERT_FALSE(Color::Maroon().IsSystemColor());
    ASSERT_EQ("Maroon", Color::Maroon().Name());
    ASSERT_EQ("Color [Maroon]", Color::Maroon().ToString());
  }

  TEST(ColorTest, MediumAquamarine) {
    ASSERT_EQ(0xFF66CDAAu, (unsigned)Color::MediumAquamarine().ToArgb());
    ASSERT_FALSE(Color::MediumAquamarine().IsEmpty());
    ASSERT_TRUE(Color::MediumAquamarine().IsKnownColor());
    ASSERT_TRUE(Color::MediumAquamarine().IsNamedColor());
    ASSERT_FALSE(Color::MediumAquamarine().IsSystemColor());
    ASSERT_EQ("MediumAquamarine", Color::MediumAquamarine().Name());
    ASSERT_EQ("Color [MediumAquamarine]", Color::MediumAquamarine().ToString());
  }

  TEST(ColorTest, MediumBlue) {
    ASSERT_EQ(0xFF0000CDu, (unsigned)Color::MediumBlue().ToArgb());
    ASSERT_FALSE(Color::MediumBlue().IsEmpty());
    ASSERT_TRUE(Color::MediumBlue().IsKnownColor());
    ASSERT_TRUE(Color::MediumBlue().IsNamedColor());
    ASSERT_FALSE(Color::MediumBlue().IsSystemColor());
    ASSERT_EQ("MediumBlue", Color::MediumBlue().Name());
    ASSERT_EQ("Color [MediumBlue]", Color::MediumBlue().ToString());
  }

  TEST(ColorTest, MediumOrchid) {
    ASSERT_EQ(0xFFBA55D3u, (unsigned)Color::MediumOrchid().ToArgb());
    ASSERT_FALSE(Color::MediumOrchid().IsEmpty());
    ASSERT_TRUE(Color::MediumOrchid().IsKnownColor());
    ASSERT_TRUE(Color::MediumOrchid().IsNamedColor());
    ASSERT_FALSE(Color::MediumOrchid().IsSystemColor());
    ASSERT_EQ("MediumOrchid", Color::MediumOrchid().Name());
    ASSERT_EQ("Color [MediumOrchid]", Color::MediumOrchid().ToString());
  }

  TEST(ColorTest, MediumPurple) {
    ASSERT_EQ(0xFF9370DBu, (unsigned)Color::MediumPurple().ToArgb());
    ASSERT_FALSE(Color::MediumPurple().IsEmpty());
    ASSERT_TRUE(Color::MediumPurple().IsKnownColor());
    ASSERT_TRUE(Color::MediumPurple().IsNamedColor());
    ASSERT_FALSE(Color::MediumPurple().IsSystemColor());
    ASSERT_EQ("MediumPurple", Color::MediumPurple().Name());
    ASSERT_EQ("Color [MediumPurple]", Color::MediumPurple().ToString());
  }

  TEST(ColorTest, MediumSeaGreen) {
    ASSERT_EQ(0xFF3CB371u, (unsigned)Color::MediumSeaGreen().ToArgb());
    ASSERT_FALSE(Color::MediumSeaGreen().IsEmpty());
    ASSERT_TRUE(Color::MediumSeaGreen().IsKnownColor());
    ASSERT_TRUE(Color::MediumSeaGreen().IsNamedColor());
    ASSERT_FALSE(Color::MediumSeaGreen().IsSystemColor());
    ASSERT_EQ("MediumSeaGreen", Color::MediumSeaGreen().Name());
    ASSERT_EQ("Color [MediumSeaGreen]", Color::MediumSeaGreen().ToString());
  }

  TEST(ColorTest, MediumSlateBlue) {
    ASSERT_EQ(0xFF7B68EEu, (unsigned)Color::MediumSlateBlue().ToArgb());
    ASSERT_FALSE(Color::MediumSlateBlue().IsEmpty());
    ASSERT_TRUE(Color::MediumSlateBlue().IsKnownColor());
    ASSERT_TRUE(Color::MediumSlateBlue().IsNamedColor());
    ASSERT_FALSE(Color::MediumSlateBlue().IsSystemColor());
    ASSERT_EQ("MediumSlateBlue", Color::MediumSlateBlue().Name());
    ASSERT_EQ("Color [MediumSlateBlue]", Color::MediumSlateBlue().ToString());
  }

  TEST(ColorTest, MediumSpringGreen) {
    ASSERT_EQ(0xFF00FA9Au, (unsigned)Color::MediumSpringGreen().ToArgb());
    ASSERT_FALSE(Color::MediumSpringGreen().IsEmpty());
    ASSERT_TRUE(Color::MediumSpringGreen().IsKnownColor());
    ASSERT_TRUE(Color::MediumSpringGreen().IsNamedColor());
    ASSERT_FALSE(Color::MediumSpringGreen().IsSystemColor());
    ASSERT_EQ("MediumSpringGreen", Color::MediumSpringGreen().Name());
    ASSERT_EQ("Color [MediumSpringGreen]", Color::MediumSpringGreen().ToString());
  }

  TEST(ColorTest, MediumTurquoise) {
    ASSERT_EQ(0xFF48D1CCu, (unsigned)Color::MediumTurquoise().ToArgb());
    ASSERT_FALSE(Color::MediumTurquoise().IsEmpty());
    ASSERT_TRUE(Color::MediumTurquoise().IsKnownColor());
    ASSERT_TRUE(Color::MediumTurquoise().IsNamedColor());
    ASSERT_FALSE(Color::MediumTurquoise().IsSystemColor());
    ASSERT_EQ("MediumTurquoise", Color::MediumTurquoise().Name());
    ASSERT_EQ("Color [MediumTurquoise]", Color::MediumTurquoise().ToString());
  }

  TEST(ColorTest, MediumVioletRed) {
    ASSERT_EQ(0xFFC71585u, (unsigned)Color::MediumVioletRed().ToArgb());
    ASSERT_FALSE(Color::MediumVioletRed().IsEmpty());
    ASSERT_TRUE(Color::MediumVioletRed().IsKnownColor());
    ASSERT_TRUE(Color::MediumVioletRed().IsNamedColor());
    ASSERT_FALSE(Color::MediumVioletRed().IsSystemColor());
    ASSERT_EQ("MediumVioletRed", Color::MediumVioletRed().Name());
    ASSERT_EQ("Color [MediumVioletRed]", Color::MediumVioletRed().ToString());
  }

  TEST(ColorTest, MidnightBlue) {
    ASSERT_EQ(0xFF191970u, (unsigned)Color::MidnightBlue().ToArgb());
    ASSERT_FALSE(Color::MidnightBlue().IsEmpty());
    ASSERT_TRUE(Color::MidnightBlue().IsKnownColor());
    ASSERT_TRUE(Color::MidnightBlue().IsNamedColor());
    ASSERT_FALSE(Color::MidnightBlue().IsSystemColor());
    ASSERT_EQ("MidnightBlue", Color::MidnightBlue().Name());
    ASSERT_EQ("Color [MidnightBlue]", Color::MidnightBlue().ToString());
  }

  TEST(ColorTest, MintCream) {
    ASSERT_EQ(0xFFF5FFFAu, (unsigned)Color::MintCream().ToArgb());
    ASSERT_FALSE(Color::MintCream().IsEmpty());
    ASSERT_TRUE(Color::MintCream().IsKnownColor());
    ASSERT_TRUE(Color::MintCream().IsNamedColor());
    ASSERT_FALSE(Color::MintCream().IsSystemColor());
    ASSERT_EQ("MintCream", Color::MintCream().Name());
    ASSERT_EQ("Color [MintCream]", Color::MintCream().ToString());
  }

  TEST(ColorTest, MistyRose) {
    ASSERT_EQ(0xFFFFE4E1u, (unsigned)Color::MistyRose().ToArgb());
    ASSERT_FALSE(Color::MistyRose().IsEmpty());
    ASSERT_TRUE(Color::MistyRose().IsKnownColor());
    ASSERT_TRUE(Color::MistyRose().IsNamedColor());
    ASSERT_FALSE(Color::MistyRose().IsSystemColor());
    ASSERT_EQ("MistyRose", Color::MistyRose().Name());
    ASSERT_EQ("Color [MistyRose]", Color::MistyRose().ToString());
  }

  TEST(ColorTest, Moccasin) {
    ASSERT_EQ(0xFFFFE4B5u, (unsigned)Color::Moccasin().ToArgb());
    ASSERT_FALSE(Color::Moccasin().IsEmpty());
    ASSERT_TRUE(Color::Moccasin().IsKnownColor());
    ASSERT_TRUE(Color::Moccasin().IsNamedColor());
    ASSERT_FALSE(Color::Moccasin().IsSystemColor());
    ASSERT_EQ("Moccasin", Color::Moccasin().Name());
    ASSERT_EQ("Color [Moccasin]", Color::Moccasin().ToString());
  }

  TEST(ColorTest, NavajoWhite) {
    ASSERT_EQ(0xFFFFDEADu, (unsigned)Color::NavajoWhite().ToArgb());
    ASSERT_FALSE(Color::NavajoWhite().IsEmpty());
    ASSERT_TRUE(Color::NavajoWhite().IsKnownColor());
    ASSERT_TRUE(Color::NavajoWhite().IsNamedColor());
    ASSERT_FALSE(Color::NavajoWhite().IsSystemColor());
    ASSERT_EQ("NavajoWhite", Color::NavajoWhite().Name());
    ASSERT_EQ("Color [NavajoWhite]", Color::NavajoWhite().ToString());
  }

  TEST(ColorTest, Navy) {
    ASSERT_EQ(0xFF000080u, (unsigned)Color::Navy().ToArgb());
    ASSERT_FALSE(Color::Navy().IsEmpty());
    ASSERT_TRUE(Color::Navy().IsKnownColor());
    ASSERT_TRUE(Color::Navy().IsNamedColor());
    ASSERT_FALSE(Color::Navy().IsSystemColor());
    ASSERT_EQ("Navy", Color::Navy().Name());
    ASSERT_EQ("Color [Navy]", Color::Navy().ToString());
  }

  TEST(ColorTest, OldLace) {
    ASSERT_EQ(0xFFFDF5E6u, (unsigned)Color::OldLace().ToArgb());
    ASSERT_FALSE(Color::OldLace().IsEmpty());
    ASSERT_TRUE(Color::OldLace().IsKnownColor());
    ASSERT_TRUE(Color::OldLace().IsNamedColor());
    ASSERT_FALSE(Color::OldLace().IsSystemColor());
    ASSERT_EQ("OldLace", Color::OldLace().Name());
    ASSERT_EQ("Color [OldLace]", Color::OldLace().ToString());
  }

  TEST(ColorTest, Olive) {
    ASSERT_EQ(0xFF808000u, (unsigned)Color::Olive().ToArgb());
    ASSERT_FALSE(Color::Olive().IsEmpty());
    ASSERT_TRUE(Color::Olive().IsKnownColor());
    ASSERT_TRUE(Color::Olive().IsNamedColor());
    ASSERT_FALSE(Color::Olive().IsSystemColor());
    ASSERT_EQ("Olive", Color::Olive().Name());
    ASSERT_EQ("Color [Olive]", Color::Olive().ToString());
  }

  TEST(ColorTest, OliveDrab) {
    ASSERT_EQ(0xFF6B8E23u, (unsigned)Color::OliveDrab().ToArgb());
    ASSERT_FALSE(Color::OliveDrab().IsEmpty());
    ASSERT_TRUE(Color::OliveDrab().IsKnownColor());
    ASSERT_TRUE(Color::OliveDrab().IsNamedColor());
    ASSERT_FALSE(Color::OliveDrab().IsSystemColor());
    ASSERT_EQ("OliveDrab", Color::OliveDrab().Name());
    ASSERT_EQ("Color [OliveDrab]", Color::OliveDrab().ToString());
  }

  TEST(ColorTest, Orange) {
    ASSERT_EQ(0xFFFFA500u, (unsigned)Color::Orange().ToArgb());
    ASSERT_FALSE(Color::Orange().IsEmpty());
    ASSERT_TRUE(Color::Orange().IsKnownColor());
    ASSERT_TRUE(Color::Orange().IsNamedColor());
    ASSERT_FALSE(Color::Orange().IsSystemColor());
    ASSERT_EQ("Orange", Color::Orange().Name());
    ASSERT_EQ("Color [Orange]", Color::Orange().ToString());
  }

  TEST(ColorTest, OrangeRed) {
    ASSERT_EQ(0xFFFF4500u, (unsigned)Color::OrangeRed().ToArgb());
    ASSERT_FALSE(Color::OrangeRed().IsEmpty());
    ASSERT_TRUE(Color::OrangeRed().IsKnownColor());
    ASSERT_TRUE(Color::OrangeRed().IsNamedColor());
    ASSERT_FALSE(Color::OrangeRed().IsSystemColor());
    ASSERT_EQ("OrangeRed", Color::OrangeRed().Name());
    ASSERT_EQ("Color [OrangeRed]", Color::OrangeRed().ToString());
  }

  TEST(ColorTest, Orchid) {
    ASSERT_EQ(0xFFDA70D6u, (unsigned)Color::Orchid().ToArgb());
    ASSERT_FALSE(Color::Orchid().IsEmpty());
    ASSERT_TRUE(Color::Orchid().IsKnownColor());
    ASSERT_TRUE(Color::Orchid().IsNamedColor());
    ASSERT_FALSE(Color::Orchid().IsSystemColor());
    ASSERT_EQ("Orchid", Color::Orchid().Name());
    ASSERT_EQ("Color [Orchid]", Color::Orchid().ToString());
  }

  TEST(ColorTest, PaleGoldenrod) {
    ASSERT_EQ(0xFFEEE8AAu, (unsigned)Color::PaleGoldenrod().ToArgb());
    ASSERT_FALSE(Color::PaleGoldenrod().IsEmpty());
    ASSERT_TRUE(Color::PaleGoldenrod().IsKnownColor());
    ASSERT_TRUE(Color::PaleGoldenrod().IsNamedColor());
    ASSERT_FALSE(Color::PaleGoldenrod().IsSystemColor());
    ASSERT_EQ("PaleGoldenrod", Color::PaleGoldenrod().Name());
    ASSERT_EQ("Color [PaleGoldenrod]", Color::PaleGoldenrod().ToString());
  }

  TEST(ColorTest, PaleGreen) {
    ASSERT_EQ(0xFF98FB98u, (unsigned)Color::PaleGreen().ToArgb());
    ASSERT_FALSE(Color::PaleGreen().IsEmpty());
    ASSERT_TRUE(Color::PaleGreen().IsKnownColor());
    ASSERT_TRUE(Color::PaleGreen().IsNamedColor());
    ASSERT_FALSE(Color::PaleGreen().IsSystemColor());
    ASSERT_EQ("PaleGreen", Color::PaleGreen().Name());
    ASSERT_EQ("Color [PaleGreen]", Color::PaleGreen().ToString());
  }

  TEST(ColorTest, PaleTurquoise) {
    ASSERT_EQ(0xFFAFEEEEu, (unsigned)Color::PaleTurquoise().ToArgb());
    ASSERT_FALSE(Color::PaleTurquoise().IsEmpty());
    ASSERT_TRUE(Color::PaleTurquoise().IsKnownColor());
    ASSERT_TRUE(Color::PaleTurquoise().IsNamedColor());
    ASSERT_FALSE(Color::PaleTurquoise().IsSystemColor());
    ASSERT_EQ("PaleTurquoise", Color::PaleTurquoise().Name());
    ASSERT_EQ("Color [PaleTurquoise]", Color::PaleTurquoise().ToString());
  }

  TEST(ColorTest, PaleVioletRed) {
    ASSERT_EQ(0xFFDB7093u, (unsigned)Color::PaleVioletRed().ToArgb());
    ASSERT_FALSE(Color::PaleVioletRed().IsEmpty());
    ASSERT_TRUE(Color::PaleVioletRed().IsKnownColor());
    ASSERT_TRUE(Color::PaleVioletRed().IsNamedColor());
    ASSERT_FALSE(Color::PaleVioletRed().IsSystemColor());
    ASSERT_EQ("PaleVioletRed", Color::PaleVioletRed().Name());
    ASSERT_EQ("Color [PaleVioletRed]", Color::PaleVioletRed().ToString());
  }

  TEST(ColorTest, PapayaWhip) {
    ASSERT_EQ(0xFFFFEFD5u, (unsigned)Color::PapayaWhip().ToArgb());
    ASSERT_FALSE(Color::PapayaWhip().IsEmpty());
    ASSERT_TRUE(Color::PapayaWhip().IsKnownColor());
    ASSERT_TRUE(Color::PapayaWhip().IsNamedColor());
    ASSERT_FALSE(Color::PapayaWhip().IsSystemColor());
    ASSERT_EQ("PapayaWhip", Color::PapayaWhip().Name());
    ASSERT_EQ("Color [PapayaWhip]", Color::PapayaWhip().ToString());
  }

  TEST(ColorTest, PeachPuff) {
    ASSERT_EQ(0xFFFFDAB9u, (unsigned)Color::PeachPuff().ToArgb());
    ASSERT_FALSE(Color::PeachPuff().IsEmpty());
    ASSERT_TRUE(Color::PeachPuff().IsKnownColor());
    ASSERT_TRUE(Color::PeachPuff().IsNamedColor());
    ASSERT_FALSE(Color::PeachPuff().IsSystemColor());
    ASSERT_EQ("PeachPuff", Color::PeachPuff().Name());
    ASSERT_EQ("Color [PeachPuff]", Color::PeachPuff().ToString());
  }

  TEST(ColorTest, Peru) {
    ASSERT_EQ(0xFFCD853Fu, (unsigned)Color::Peru().ToArgb());
    ASSERT_FALSE(Color::Peru().IsEmpty());
    ASSERT_TRUE(Color::Peru().IsKnownColor());
    ASSERT_TRUE(Color::Peru().IsNamedColor());
    ASSERT_FALSE(Color::Peru().IsSystemColor());
    ASSERT_EQ("Peru", Color::Peru().Name());
    ASSERT_EQ("Color [Peru]", Color::Peru().ToString());
  }

  TEST(ColorTest, Pink) {
    ASSERT_EQ(0xFFFFC0CBu, (unsigned)Color::Pink().ToArgb());
    ASSERT_FALSE(Color::Pink().IsEmpty());
    ASSERT_TRUE(Color::Pink().IsKnownColor());
    ASSERT_TRUE(Color::Pink().IsNamedColor());
    ASSERT_FALSE(Color::Pink().IsSystemColor());
    ASSERT_EQ("Pink", Color::Pink().Name());
    ASSERT_EQ("Color [Pink]", Color::Pink().ToString());
  }

  TEST(ColorTest, Plum) {
    ASSERT_EQ(0xFFDDA0DDu, (unsigned)Color::Plum().ToArgb());
    ASSERT_FALSE(Color::Plum().IsEmpty());
    ASSERT_TRUE(Color::Plum().IsKnownColor());
    ASSERT_TRUE(Color::Plum().IsNamedColor());
    ASSERT_FALSE(Color::Plum().IsSystemColor());
    ASSERT_EQ("Plum", Color::Plum().Name());
    ASSERT_EQ("Color [Plum]", Color::Plum().ToString());
  }

  TEST(ColorTest, PowderBlue) {
    ASSERT_EQ(0xFFB0E0E6u, (unsigned)Color::PowderBlue().ToArgb());
    ASSERT_FALSE(Color::PowderBlue().IsEmpty());
    ASSERT_TRUE(Color::PowderBlue().IsKnownColor());
    ASSERT_TRUE(Color::PowderBlue().IsNamedColor());
    ASSERT_FALSE(Color::PowderBlue().IsSystemColor());
    ASSERT_EQ("PowderBlue", Color::PowderBlue().Name());
    ASSERT_EQ("Color [PowderBlue]", Color::PowderBlue().ToString());
  }

  TEST(ColorTest, Purple) {
    ASSERT_EQ(0xFF800080u, (unsigned)Color::Purple().ToArgb());
    ASSERT_FALSE(Color::Purple().IsEmpty());
    ASSERT_TRUE(Color::Purple().IsKnownColor());
    ASSERT_TRUE(Color::Purple().IsNamedColor());
    ASSERT_FALSE(Color::Purple().IsSystemColor());
    ASSERT_EQ("Purple", Color::Purple().Name());
    ASSERT_EQ("Color [Purple]", Color::Purple().ToString());
  }

  TEST(ColorTest, Red) {
    ASSERT_EQ(0xFFFF0000u, (unsigned)Color::Red().ToArgb());
    ASSERT_FALSE(Color::Red().IsEmpty());
    ASSERT_TRUE(Color::Red().IsKnownColor());
    ASSERT_TRUE(Color::Red().IsNamedColor());
    ASSERT_FALSE(Color::Red().IsSystemColor());
    ASSERT_EQ("Red", Color::Red().Name());
    ASSERT_EQ("Color [Red]", Color::Red().ToString());
  }

  TEST(ColorTest, RosyBrown) {
    ASSERT_EQ(0xFFBC8F8Fu, (unsigned)Color::RosyBrown().ToArgb());
    ASSERT_FALSE(Color::RosyBrown().IsEmpty());
    ASSERT_TRUE(Color::RosyBrown().IsKnownColor());
    ASSERT_TRUE(Color::RosyBrown().IsNamedColor());
    ASSERT_FALSE(Color::RosyBrown().IsSystemColor());
    ASSERT_EQ("RosyBrown", Color::RosyBrown().Name());
    ASSERT_EQ("Color [RosyBrown]", Color::RosyBrown().ToString());
  }

  TEST(ColorTest, RoyalBlue) {
    ASSERT_EQ(0xFF4169E1u, (unsigned)Color::RoyalBlue().ToArgb());
    ASSERT_FALSE(Color::RoyalBlue().IsEmpty());
    ASSERT_TRUE(Color::RoyalBlue().IsKnownColor());
    ASSERT_TRUE(Color::RoyalBlue().IsNamedColor());
    ASSERT_FALSE(Color::RoyalBlue().IsSystemColor());
    ASSERT_EQ("RoyalBlue", Color::RoyalBlue().Name());
    ASSERT_EQ("Color [RoyalBlue]", Color::RoyalBlue().ToString());
  }

  TEST(ColorTest, SaddleBrown) {
    ASSERT_EQ(0xFF8B4513u, (unsigned)Color::SaddleBrown().ToArgb());
    ASSERT_FALSE(Color::SaddleBrown().IsEmpty());
    ASSERT_TRUE(Color::SaddleBrown().IsKnownColor());
    ASSERT_TRUE(Color::SaddleBrown().IsNamedColor());
    ASSERT_FALSE(Color::SaddleBrown().IsSystemColor());
    ASSERT_EQ("SaddleBrown", Color::SaddleBrown().Name());
    ASSERT_EQ("Color [SaddleBrown]", Color::SaddleBrown().ToString());
  }

  TEST(ColorTest, Salmon) {
    ASSERT_EQ(0xFFFA8072u, (unsigned)Color::Salmon().ToArgb());
    ASSERT_FALSE(Color::Salmon().IsEmpty());
    ASSERT_TRUE(Color::Salmon().IsKnownColor());
    ASSERT_TRUE(Color::Salmon().IsNamedColor());
    ASSERT_FALSE(Color::Salmon().IsSystemColor());
    ASSERT_EQ("Salmon", Color::Salmon().Name());
    ASSERT_EQ("Color [Salmon]", Color::Salmon().ToString());
  }

  TEST(ColorTest, SandyBrown) {
    ASSERT_EQ(0xFFF4A460u, (unsigned)Color::SandyBrown().ToArgb());
    ASSERT_FALSE(Color::SandyBrown().IsEmpty());
    ASSERT_TRUE(Color::SandyBrown().IsKnownColor());
    ASSERT_TRUE(Color::SandyBrown().IsNamedColor());
    ASSERT_FALSE(Color::SandyBrown().IsSystemColor());
    ASSERT_EQ("SandyBrown", Color::SandyBrown().Name());
    ASSERT_EQ("Color [SandyBrown]", Color::SandyBrown().ToString());
  }

  TEST(ColorTest, SeaGreen) {
    ASSERT_EQ(0xFF2E8B57u, (unsigned)Color::SeaGreen().ToArgb());
    ASSERT_FALSE(Color::SeaGreen().IsEmpty());
    ASSERT_TRUE(Color::SeaGreen().IsKnownColor());
    ASSERT_TRUE(Color::SeaGreen().IsNamedColor());
    ASSERT_FALSE(Color::SeaGreen().IsSystemColor());
    ASSERT_EQ("SeaGreen", Color::SeaGreen().Name());
    ASSERT_EQ("Color [SeaGreen]", Color::SeaGreen().ToString());
  }

  TEST(ColorTest, SeaShell) {
    ASSERT_EQ(0xFFFFF5EEu, (unsigned)Color::SeaShell().ToArgb());
    ASSERT_FALSE(Color::SeaShell().IsEmpty());
    ASSERT_TRUE(Color::SeaShell().IsKnownColor());
    ASSERT_TRUE(Color::SeaShell().IsNamedColor());
    ASSERT_FALSE(Color::SeaShell().IsSystemColor());
    ASSERT_EQ("SeaShell", Color::SeaShell().Name());
    ASSERT_EQ("Color [SeaShell]", Color::SeaShell().ToString());
  }

  TEST(ColorTest, Sienna) {
    ASSERT_EQ(0xFFA0522Du, (unsigned)Color::Sienna().ToArgb());
    ASSERT_FALSE(Color::Sienna().IsEmpty());
    ASSERT_TRUE(Color::Sienna().IsKnownColor());
    ASSERT_TRUE(Color::Sienna().IsNamedColor());
    ASSERT_FALSE(Color::Sienna().IsSystemColor());
    ASSERT_EQ("Sienna", Color::Sienna().Name());
    ASSERT_EQ("Color [Sienna]", Color::Sienna().ToString());
  }

  TEST(ColorTest, Silver) {
    ASSERT_EQ(0xFFC0C0C0u, (unsigned)Color::Silver().ToArgb());
    ASSERT_FALSE(Color::Silver().IsEmpty());
    ASSERT_TRUE(Color::Silver().IsKnownColor());
    ASSERT_TRUE(Color::Silver().IsNamedColor());
    ASSERT_FALSE(Color::Silver().IsSystemColor());
    ASSERT_EQ("Silver", Color::Silver().Name());
    ASSERT_EQ("Color [Silver]", Color::Silver().ToString());
  }

  TEST(ColorTest, SkyBlue) {
    ASSERT_EQ(0xFF87CEEBu, (unsigned)Color::SkyBlue().ToArgb());
    ASSERT_FALSE(Color::SkyBlue().IsEmpty());
    ASSERT_TRUE(Color::SkyBlue().IsKnownColor());
    ASSERT_TRUE(Color::SkyBlue().IsNamedColor());
    ASSERT_FALSE(Color::SkyBlue().IsSystemColor());
    ASSERT_EQ("SkyBlue", Color::SkyBlue().Name());
    ASSERT_EQ("Color [SkyBlue]", Color::SkyBlue().ToString());
  }

  TEST(ColorTest, SlateBlue) {
    ASSERT_EQ(0xFF6A5ACDu, (unsigned)Color::SlateBlue().ToArgb());
    ASSERT_FALSE(Color::SlateBlue().IsEmpty());
    ASSERT_TRUE(Color::SlateBlue().IsKnownColor());
    ASSERT_TRUE(Color::SlateBlue().IsNamedColor());
    ASSERT_FALSE(Color::SlateBlue().IsSystemColor());
    ASSERT_EQ("SlateBlue", Color::SlateBlue().Name());
    ASSERT_EQ("Color [SlateBlue]", Color::SlateBlue().ToString());
  }

  TEST(ColorTest, SlateGray) {
    ASSERT_EQ(0xFF708090u, (unsigned)Color::SlateGray().ToArgb());
    ASSERT_FALSE(Color::SlateGray().IsEmpty());
    ASSERT_TRUE(Color::SlateGray().IsKnownColor());
    ASSERT_TRUE(Color::SlateGray().IsNamedColor());
    ASSERT_FALSE(Color::SlateGray().IsSystemColor());
    ASSERT_EQ("SlateGray", Color::SlateGray().Name());
    ASSERT_EQ("Color [SlateGray]", Color::SlateGray().ToString());
  }

  TEST(ColorTest, Snow) {
    ASSERT_EQ(0xFFFFFAFAu, (unsigned)Color::Snow().ToArgb());
    ASSERT_FALSE(Color::Snow().IsEmpty());
    ASSERT_TRUE(Color::Snow().IsKnownColor());
    ASSERT_TRUE(Color::Snow().IsNamedColor());
    ASSERT_FALSE(Color::Snow().IsSystemColor());
    ASSERT_EQ("Snow", Color::Snow().Name());
    ASSERT_EQ("Color [Snow]", Color::Snow().ToString());
  }

  TEST(ColorTest, SpringGreen) {
    ASSERT_EQ(0xFF00FF7Fu, (unsigned)Color::SpringGreen().ToArgb());
    ASSERT_FALSE(Color::SpringGreen().IsEmpty());
    ASSERT_TRUE(Color::SpringGreen().IsKnownColor());
    ASSERT_TRUE(Color::SpringGreen().IsNamedColor());
    ASSERT_FALSE(Color::SpringGreen().IsSystemColor());
    ASSERT_EQ("SpringGreen", Color::SpringGreen().Name());
    ASSERT_EQ("Color [SpringGreen]", Color::SpringGreen().ToString());
  }

  TEST(ColorTest, SteelBlue) {
    ASSERT_EQ(0xFF4682B4u, (unsigned)Color::SteelBlue().ToArgb());
    ASSERT_FALSE(Color::SteelBlue().IsEmpty());
    ASSERT_TRUE(Color::SteelBlue().IsKnownColor());
    ASSERT_TRUE(Color::SteelBlue().IsNamedColor());
    ASSERT_FALSE(Color::SteelBlue().IsSystemColor());
    ASSERT_EQ("SteelBlue", Color::SteelBlue().Name());
    ASSERT_EQ("Color [SteelBlue]", Color::SteelBlue().ToString());
  }

  TEST(ColorTest, Tan) {
    ASSERT_EQ(0xFFD2B48Cu, (unsigned)Color::Tan().ToArgb());
    ASSERT_FALSE(Color::Tan().IsEmpty());
    ASSERT_TRUE(Color::Tan().IsKnownColor());
    ASSERT_TRUE(Color::Tan().IsNamedColor());
    ASSERT_FALSE(Color::Tan().IsSystemColor());
    ASSERT_EQ("Tan", Color::Tan().Name());
    ASSERT_EQ("Color [Tan]", Color::Tan().ToString());
  }

  TEST(ColorTest, Teal) {
    ASSERT_EQ(0xFF008080u, (unsigned)Color::Teal().ToArgb());
    ASSERT_FALSE(Color::Teal().IsEmpty());
    ASSERT_TRUE(Color::Teal().IsKnownColor());
    ASSERT_TRUE(Color::Teal().IsNamedColor());
    ASSERT_FALSE(Color::Teal().IsSystemColor());
    ASSERT_EQ("Teal", Color::Teal().Name());
    ASSERT_EQ("Color [Teal]", Color::Teal().ToString());
  }

  TEST(ColorTest, Thistle) {
    ASSERT_EQ(0xFFD8BFD8u, (unsigned)Color::Thistle().ToArgb());
    ASSERT_FALSE(Color::Thistle().IsEmpty());
    ASSERT_TRUE(Color::Thistle().IsKnownColor());
    ASSERT_TRUE(Color::Thistle().IsNamedColor());
    ASSERT_FALSE(Color::Thistle().IsSystemColor());
    ASSERT_EQ("Thistle", Color::Thistle().Name());
    ASSERT_EQ("Color [Thistle]", Color::Thistle().ToString());
  }

  TEST(ColorTest, Tomato) {
    ASSERT_EQ(0xFFFF6347u, (unsigned)Color::Tomato().ToArgb());
    ASSERT_FALSE(Color::Tomato().IsEmpty());
    ASSERT_TRUE(Color::Tomato().IsKnownColor());
    ASSERT_TRUE(Color::Tomato().IsNamedColor());
    ASSERT_FALSE(Color::Tomato().IsSystemColor());
    ASSERT_EQ("Tomato", Color::Tomato().Name());
    ASSERT_EQ("Color [Tomato]", Color::Tomato().ToString());
  }

  TEST(ColorTest, Turquoise) {
    ASSERT_EQ(0xFF40E0D0u, (unsigned)Color::Turquoise().ToArgb());
    ASSERT_FALSE(Color::Turquoise().IsEmpty());
    ASSERT_TRUE(Color::Turquoise().IsKnownColor());
    ASSERT_TRUE(Color::Turquoise().IsNamedColor());
    ASSERT_FALSE(Color::Turquoise().IsSystemColor());
    ASSERT_EQ("Turquoise", Color::Turquoise().Name());
    ASSERT_EQ("Color [Turquoise]", Color::Turquoise().ToString());
  }

  TEST(ColorTest, Violet) {
    ASSERT_EQ(0xFFEE82EEu, (unsigned)Color::Violet().ToArgb());
    ASSERT_FALSE(Color::Violet().IsEmpty());
    ASSERT_TRUE(Color::Violet().IsKnownColor());
    ASSERT_TRUE(Color::Violet().IsNamedColor());
    ASSERT_FALSE(Color::Violet().IsSystemColor());
    ASSERT_EQ("Violet", Color::Violet().Name());
    ASSERT_EQ("Color [Violet]", Color::Violet().ToString());
  }

  TEST(ColorTest, Wheat) {
    ASSERT_EQ(0xFFF5DEB3u, (unsigned)Color::Wheat().ToArgb());
    ASSERT_FALSE(Color::Wheat().IsEmpty());
    ASSERT_TRUE(Color::Wheat().IsKnownColor());
    ASSERT_TRUE(Color::Wheat().IsNamedColor());
    ASSERT_FALSE(Color::Wheat().IsSystemColor());
    ASSERT_EQ("Wheat", Color::Wheat().Name());
    ASSERT_EQ("Color [Wheat]", Color::Wheat().ToString());
  }

  TEST(ColorTest, White) {
    ASSERT_EQ(0xFFFFFFFFu, (unsigned)Color::White().ToArgb());
    ASSERT_FALSE(Color::White().IsEmpty());
    ASSERT_TRUE(Color::White().IsKnownColor());
    ASSERT_TRUE(Color::White().IsNamedColor());
    ASSERT_FALSE(Color::White().IsSystemColor());
    ASSERT_EQ("White", Color::White().Name());
    ASSERT_EQ("Color [White]", Color::White().ToString());
  }

  TEST(ColorTest, WhiteSmoke) {
    ASSERT_EQ(0xFFF5F5F5u, (unsigned)Color::WhiteSmoke().ToArgb());
    ASSERT_FALSE(Color::WhiteSmoke().IsEmpty());
    ASSERT_TRUE(Color::WhiteSmoke().IsKnownColor());
    ASSERT_TRUE(Color::WhiteSmoke().IsNamedColor());
    ASSERT_FALSE(Color::WhiteSmoke().IsSystemColor());
    ASSERT_EQ("WhiteSmoke", Color::WhiteSmoke().Name());
    ASSERT_EQ("Color [WhiteSmoke]", Color::WhiteSmoke().ToString());
  }

  TEST(ColorTest, Yellow) {
    ASSERT_EQ(0xFFFFFF00u, (unsigned)Color::Yellow().ToArgb());
    ASSERT_FALSE(Color::Yellow().IsEmpty());
    ASSERT_TRUE(Color::Yellow().IsKnownColor());
    ASSERT_TRUE(Color::Yellow().IsNamedColor());
    ASSERT_FALSE(Color::Yellow().IsSystemColor());
    ASSERT_EQ("Yellow", Color::Yellow().Name());
    ASSERT_EQ("Color [Yellow]", Color::Yellow().ToString());
  }

  TEST(ColorTest, YellowGreen) {
    ASSERT_EQ(0xFF9ACD32u, (unsigned)Color::YellowGreen().ToArgb());
    ASSERT_FALSE(Color::YellowGreen().IsEmpty());
    ASSERT_TRUE(Color::YellowGreen().IsKnownColor());
    ASSERT_TRUE(Color::YellowGreen().IsNamedColor());
    ASSERT_FALSE(Color::YellowGreen().IsSystemColor());
    ASSERT_EQ("YellowGreen", Color::YellowGreen().Name());
    ASSERT_EQ("Color [YellowGreen]", Color::YellowGreen().ToString());
  }
}

