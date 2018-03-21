#include <gtest/gtest.h>
#include <Switch/System/String.hpp>

using namespace System;

namespace SwitchUnitTests {
  // Method in src/Switch.Core/src/Native/DirectoryApiGcc.cpp and src/Switch.System.Windows.Forms/src/Native/CommonDialogApiCocoa.mm
  static bool PatternCompare(const string& fileName, const string& pattern) {
    if (string::IsNullOrEmpty(pattern))
      return string::IsNullOrEmpty(fileName);

    if (string::IsNullOrEmpty(fileName))
      return false;

    if (pattern == "*" || pattern == "*.*")
      return true;

    if (pattern[0] == '*')
      return PatternCompare(fileName, pattern.Substring(1)) || PatternCompare(fileName.Substring(1), pattern);

    return ((pattern[0] == '?') || (fileName[0] == pattern[0])) && PatternCompare(fileName.Substring(1), pattern.Substring(1));
  }

  TEST(PatternCompareTest, Pattern_all) {
    ASSERT_TRUE(PatternCompare("MyFile.txt", "*"));
    ASSERT_TRUE(PatternCompare("MyFile1.txte", "*"));
    ASSERT_TRUE(PatternCompare("MyFile1.tx", "*"));
    ASSERT_TRUE(PatternCompare("MyFile1.TXT", "*"));
    ASSERT_TRUE(PatternCompare("MyFile", "*"));
    ASSERT_TRUE(PatternCompare(".MyFile", "*"));
  }

  TEST(PatternCompareTest, Pattern_all_all) {
    ASSERT_TRUE(PatternCompare("MyFile.txt", "*.*"));
    ASSERT_TRUE(PatternCompare("MyFile1.txte", "*.*"));
    ASSERT_TRUE(PatternCompare("MyFile1.tx", "*.*"));
    ASSERT_TRUE(PatternCompare("MyFile1.TXT", "*.*"));
    ASSERT_TRUE(PatternCompare("MyFile", "*.*"));
    ASSERT_TRUE(PatternCompare(".MyFile", "*.*"));
  }

  TEST(PatternCompareTest, Pattern_all_txt) {
    ASSERT_TRUE(PatternCompare("MyFile.txt", "*.txt"));
    ASSERT_FALSE(PatternCompare("MyFile1.txte", "*.txt"));
    ASSERT_FALSE(PatternCompare("MyFile1.tx", "*.txt"));
    ASSERT_FALSE(PatternCompare("MyFile.TXT", "*.txt"));
    ASSERT_FALSE(PatternCompare("MyFile", "*.txt"));
    ASSERT_FALSE(PatternCompare(".MyFile", "*.txt"));
  }

  TEST(PatternCompareTest, Pattern_all_TXT) {
    ASSERT_FALSE(PatternCompare("MyFile.txt", "*.TXT"));
    ASSERT_FALSE(PatternCompare("MyFile1.txte", "*.TXT"));
    ASSERT_FALSE(PatternCompare("MyFile1.tx", "*.TXT"));
    ASSERT_TRUE(PatternCompare("MyFile.TXT", "*.TXT"));
    ASSERT_FALSE(PatternCompare("MyFile", "*.TXT"));
    ASSERT_FALSE(PatternCompare(".MyFile", "*.TXT"));
  }

  TEST(PatternCompareTest, Pattern_all_tx) {
    ASSERT_FALSE(PatternCompare("MyFile.txt", "*.tx"));
    ASSERT_FALSE(PatternCompare("MyFile1.txte", "*.tx"));
    ASSERT_TRUE(PatternCompare("MyFile1.tx", "*.tx"));
    ASSERT_FALSE(PatternCompare("MyFile.TXT", "*.tx"));
    ASSERT_FALSE(PatternCompare("MyFile1", "*.tx"));
    ASSERT_FALSE(PatternCompare(".MyFile", "*.tx"));
  }

  TEST(PatternCompareTest, Pattern_all_txte) {
    ASSERT_FALSE(PatternCompare("MyFile.txt", "*.txte"));
    ASSERT_TRUE(PatternCompare("MyFile1.txte", "*.txte"));
    ASSERT_FALSE(PatternCompare("MyFile.TXT", "*.txte"));
    ASSERT_FALSE(PatternCompare("MyFile1", "*.txte"));
    ASSERT_FALSE(PatternCompare(".MyFile", "*.txte"));
  }

  TEST(PatternCompareTest, Pattern_all_$xt) {
    ASSERT_TRUE(PatternCompare("MyFile.txt", "*.?xt"));
    ASSERT_FALSE(PatternCompare("MyFile1.txte", "*.?xt"));
    ASSERT_FALSE(PatternCompare("MyFile1.tx", "*.?xt"));
    ASSERT_FALSE(PatternCompare("MyFile.TXT", "*.?xt"));
    ASSERT_FALSE(PatternCompare("MyFile1", "*.?xt"));
    ASSERT_FALSE(PatternCompare(".MyFile", "*.?xt"));
  }

  TEST(PatternCompareTest, PatternT_all_t$t) {
    ASSERT_TRUE(PatternCompare("MyFile.txt", "*.t?t"));
    ASSERT_FALSE(PatternCompare("MyFile1.txte", "*.t?t"));
    ASSERT_FALSE(PatternCompare("MyFile1.tx", "*.t?t"));
    ASSERT_FALSE(PatternCompare("MyFile.TXT", "*.t?t"));
    ASSERT_FALSE(PatternCompare("MyFile1", "*.t?t"));
    ASSERT_FALSE(PatternCompare(".MyFile", "*.t?t"));
  }

  TEST(PatternCompareTest, Pattern_all_tx$) {
    ASSERT_TRUE(PatternCompare("MyFile.txt", "*.tx?"));
    ASSERT_FALSE(PatternCompare("MyFile1.txte", "*.tx?"));
    ASSERT_FALSE(PatternCompare("MyFile1.tx", "*.tx?"));
    ASSERT_FALSE(PatternCompare("MyFile.TXT", "*.tx?"));
    ASSERT_FALSE(PatternCompare("MyFile1", "*.tx?"));
    ASSERT_FALSE(PatternCompare(".MyFile", "*.tx?"));
  }

  TEST(PatternCompareTest, Pattern_all_$$$) {
    ASSERT_TRUE(PatternCompare("MyFile.txt", "*.???"));
    ASSERT_FALSE(PatternCompare("MyFile1.txte", "*.???"));
    ASSERT_FALSE(PatternCompare("MyFile1.tx", "*.???"));
    ASSERT_TRUE(PatternCompare("MyFile.TXT", "*.???"));
    ASSERT_FALSE(PatternCompare("MyFile1", "*.???"));
    ASSERT_FALSE(PatternCompare(".MyFile", "*.???"));
  }

  TEST(PatternCompareTest, Pattern_all_$all) {
    ASSERT_TRUE(PatternCompare("MyFile.txt", "*.?*"));
    ASSERT_TRUE(PatternCompare("MyFile1.txte", "*.?*"));
    ASSERT_TRUE(PatternCompare("MyFile1.tx", "*.?*"));
    ASSERT_TRUE(PatternCompare("MyFile.TXT", "*.?*"));
    ASSERT_FALSE(PatternCompare("MyFile1", "*.?*"));
    ASSERT_TRUE(PatternCompare(".MyFile", "*.?*"));
  }

  TEST(PatternCompareTest, Pattern_alle_all) {
    ASSERT_TRUE(PatternCompare("MyFile.txt", "*e.*"));
    ASSERT_FALSE(PatternCompare("MyFile1.txte", "*e.*"));
    ASSERT_FALSE(PatternCompare("MyFile1.tx", "*e.*"));
    ASSERT_TRUE(PatternCompare("MyFile.TXT", "*e.*"));
    ASSERT_FALSE(PatternCompare("MyFile1", "*e.*"));
    ASSERT_FALSE(PatternCompare(".MyFile", "*e.*"));
  }

  TEST(PatternCompareTest, Pattern_all_alle) {
    ASSERT_FALSE(PatternCompare("MyFile.txt", "*.*e"));
    ASSERT_TRUE(PatternCompare("MyFile1.txte", "*.*e"));
    ASSERT_FALSE(PatternCompare("MyFile1.tx", "*.*e"));
    ASSERT_FALSE(PatternCompare("MyFile.TXT", "*.*e"));
    ASSERT_FALSE(PatternCompare("MyFile1", "*.*e"));
    ASSERT_TRUE(PatternCompare(".MyFile", "*.*e"));
  }
}

