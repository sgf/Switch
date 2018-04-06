#include <Switch/System/Drawing/CharacterRange.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(CharacterRangeTest, DefaultConstructor) {
    CharacterRange characterRange;

    ASSERT_EQ(0, characterRange.First);
    ASSERT_EQ(0, characterRange.Length);
  }

  TEST(CharacterRangeTest, Constructor) {
    CharacterRange characterRange(1, 2);

    ASSERT_EQ(1, characterRange.First);
    ASSERT_EQ(2, characterRange.Length);
  }

  TEST(CharacterRangeTest, CopyConstructor) {
    CharacterRange characterRange1(1, 2);

    CharacterRange characterRange2 = characterRange1;

    ASSERT_EQ(1, characterRange2.First);
    ASSERT_EQ(2, characterRange2.Length);
  }

  TEST(CharacterRangeTest, CopyOperator) {
    CharacterRange characterRange1(1, 2);
    CharacterRange characterRange2;

    characterRange2 = characterRange1;

    ASSERT_EQ(1, characterRange2.First);
    ASSERT_EQ(2, characterRange2.Length);
  }

  TEST(CharacterRangeTest, Equals) {
    CharacterRange characterRange1(1, 2);
    CharacterRange characterRange2;

    characterRange2 = characterRange1;

    ASSERT_TRUE(characterRange1.Equals(characterRange2));
  }

  TEST(CharacterRangeTest, Inequals) {
    CharacterRange characterRange1(1, 2);
    CharacterRange characterRange2;

    characterRange2 = characterRange1;
    characterRange2.Length = 3;

    ASSERT_FALSE(characterRange1.Equals(characterRange2));
  }
}
