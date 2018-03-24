#include "EncodingUT.hpp"
#include <Switch/System/Text/ANSIEncoding.hpp>
#include <Switch/System/Text/ASCIIEncoding.hpp>
#include <Switch/System/Text/UnicodeEncoding.hpp>
#include <Switch/System/Text/UTF8Encoding.hpp>
#include <Switch/System/Text/UTF32Encoding.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(Unicode_EncodingTest, GetBytes_Exceptions) {
    Text::UnicodeEncoding u16LE(false);
    Text::UnicodeEncoding u16BE(true);

    EncodingUT::CheckErrorsGetBytes(u16LE);
    EncodingUT::CheckErrorsGetBytes(u16BE);
  }

  TEST(Unicode_EncodingTest, GetByteCount_Exceptions) {
    Text::UnicodeEncoding u16LE(false);
    Text::UnicodeEncoding u16BE(true);

    EncodingUT::CheckErrorsGetByteCount(u16LE);
    EncodingUT::CheckErrorsString(u16BE);
  }

  TEST(Unicode_EncodingTest, GetCharCount_Exceptions) {
    Text::UnicodeEncoding u16LE(false);
    Text::UnicodeEncoding u16BE(true);

    EncodingUT::CheckErrorsGetCharCount(u16LE);
    EncodingUT::CheckErrorsString(u16BE);
  }

  TEST(Unicode_EncodingTest, GetChars_Exceptions) {
    Text::UnicodeEncoding u16LE(false);
    Text::UnicodeEncoding u16BE(true);

    EncodingUT::CheckErrorsGetChars(u16LE);
    EncodingUT::CheckErrorsString(u16BE);
  }

  TEST(Unicode_EncodingTest, String_Exceptions) {
    Text::UnicodeEncoding u16LE(false);
    Text::UnicodeEncoding u16BE(true);

    EncodingUT::CheckErrorsString(u16LE);
    EncodingUT::CheckErrorsString(u16BE);
  }

  TEST(Unicode_EncodingTest, Equals) {
    // Create a Text::UnicodeEncoding without parameters.
    $<Text::UnicodeEncoding> unicode = new Text::UnicodeEncoding();
    ASSERT_EQ(1200, unicode->GetCodePage());

    // Create a Text::UnicodeEncoding to support little-endian byte ordering
    // and include the Unicode byte order mark.
    $<Text::UnicodeEncoding> unicodeLittleEndianBOM = new Text::UnicodeEncoding(false, true);
    // Compare this Text::UnicodeEncoding to the Text::UnicodeEncoding without parameters.
    ASSERT_TRUE(unicode->Equals(*unicodeLittleEndianBOM));
    ASSERT_EQ(1200, unicodeLittleEndianBOM->GetCodePage());

    // Create a Text::UnicodeEncoding to support little-endian byte ordering
    // and not include the Unicode byte order mark.
    $<Text::UnicodeEncoding> unicodeLittleEndianNoBOM = new Text::UnicodeEncoding(false, false);
    // Compare this Text::UnicodeEncoding to the Text::UnicodeEncoding without parameters.
    ASSERT_FALSE(unicode->Equals(*unicodeLittleEndianNoBOM));
    ASSERT_EQ(1200, unicodeLittleEndianNoBOM->GetCodePage());

    // Create a Text::UnicodeEncoding to support big-endian byte ordering
    // and include the Unicode byte order mark.
    $<Text::UnicodeEncoding> unicodeBigEndianBOM = new Text::UnicodeEncoding(true, true);
    // Compare this Text::UnicodeEncoding to the Text::UnicodeEncoding without parameters.
    ASSERT_FALSE(unicode->Equals(*unicodeBigEndianBOM));
    ASSERT_EQ(1201, unicodeBigEndianBOM->GetCodePage());

    // Create a Text::UnicodeEncoding to support big-endian byte ordering
    // and not include the Unicode byte order mark.
    $<Text::UnicodeEncoding> unicodeBigEndianNoBOM = new Text::UnicodeEncoding(true, false);
    // Compare this Text::UnicodeEncoding to the Text::UnicodeEncoding without parameters.
    ASSERT_FALSE(unicode->Equals(*unicodeBigEndianNoBOM));
    ASSERT_EQ(1201, unicodeBigEndianNoBOM->GetCodePage());
  }

  TEST(Unicode_EncodingTest, Encode) {
    // The encoding, UTF16 little endian, BOM
    Text::UnicodeEncoding unicode;
    Text::UnicodeEncoding encoding(false);
    ASSERT_EQ(1200, unicode.GetCodePage());
    ASSERT_TRUE(encoding.Equals(unicode));
    string s = unicode.GetEncodingName();
    ASSERT_TRUE(unicode.GetEncodingName().Equals("utf-16"));
    ASSERT_TRUE(unicode.IsReadOnly());
    EncodingUT::Bytes preamble = unicode.GetPreamble();
    ASSERT_EQ(2, preamble.Length);
    ASSERT_EQ(0xFF, preamble.GetValue(0));
    ASSERT_EQ(0xFE, preamble.GetValue(1));

    string unicodeString("This unicode string contains two characters "
      "with codes outside the ASCII code range, "
      "Pi (" + Char(928) + "), Sigma (" + Char(931) + ") and KOALA (" + Char(128040) + ").");

    byte reference[] = {
      84,   0, 104,   0, 105,   0, 115,   0,  32,   0, 117,   0, 110,   0, 105,   0,
      99,   0, 111,   0, 100,   0, 101,   0,  32,   0, 115,   0, 116,   0, 114,   0,
      105,   0, 110,   0, 103,   0,  32,   0,  99,   0, 111,   0, 110,   0, 116,   0,
      97,   0, 105,   0, 110,   0, 115,   0,  32,   0, 116,   0, 119,   0, 111,   0,
      32,   0,  99,   0, 104,   0,  97,   0, 114,   0,  97,   0,  99,   0, 116,   0,
      101,   0, 114,   0, 115,   0,  32,   0, 119,   0, 105,   0, 116,   0, 104,   0,
      32,   0,  99,   0, 111,   0, 100,   0, 101,   0, 115,   0,  32,   0, 111,   0,
      117,   0, 116,   0, 115,   0, 105,   0, 100,   0, 101,   0,  32,   0, 116,   0,
      104,   0, 101,   0,  32,   0,  65,   0,  83,   0,  67,   0,  73,   0,  73,   0,
      32,   0,  99,   0, 111,   0, 100,   0, 101,   0,  32,   0, 114,   0,  97,   0,
      110,   0, 103,   0, 101,   0,  44,   0,  32,   0,  80,   0, 105,   0,  32,   0,
      40,   0, 160,   3,  41,   0,  44,   0,  32,   0,  83,   0, 105,   0, 103,   0,
      109,   0,  97,   0,  32,   0,  40,   0, 163,   3,  41,   0,  32,   0,  97,   0,
      110,   0, 100,   0,  32,   0,  75,   0,  79,   0,  65,   0,  76,   0,  65,   0,
      32,   0,  40,   0,  61, 216,  40, 220,  41,   0,  46,   0
    };

    // Encode the string.
    EncodingUT::Bytes encodedBytes = unicode.GetBytes(unicodeString);
    int index = 0;
    for (byte b : encodedBytes)
      ASSERT_EQ(reference[index++], b);

    ASSERT_EQ(unicodeString.Length(), unicode.GetCharCount(encodedBytes.Data, encodedBytes.Length, 0, encodedBytes.Length));

    // Decode bytes back to string.
    // Notice Pi and Sigma characters are still present.
    string decodedString = unicode.GetString(encodedBytes.Data, encodedBytes.Length);
    ASSERT_TRUE(decodedString.Equals(unicodeString));
  }

  TEST(Unicode_EncodingTest, EncodeBigEndian) {
    // The encoding, utf16 big endian, BOM.
    Text::UnicodeEncoding unicode(true);
    Text::UnicodeEncoding encoding(true);
    ASSERT_EQ(1201, unicode.GetCodePage());
    ASSERT_TRUE(encoding.Equals(unicode));
    string s = unicode.GetEncodingName();
    ASSERT_TRUE(unicode.GetEncodingName().Equals("unicodeFFFE"));
    ASSERT_TRUE(unicode.IsReadOnly());
    EncodingUT::Bytes preamble = unicode.GetPreamble();
    ASSERT_EQ(2, preamble.Length);
    ASSERT_EQ(0xFE, preamble.GetValue(0));
    ASSERT_EQ(0xFF, preamble.GetValue(1));

    // Create a string that contains Unicode characters.
    string unicodeString("This unicode string contains two characters "
      "with codes outside the ASCII code range, "
      "Pi (" + Char(928) + "), Sigma (" + Char(931) + ") and KOALA (" + Char(128040) + ").");

    byte reference[] = { 0, 84, 0, 104, 0, 105, 0, 115, 0, 32, 0, 117, 0, 110, 0,
        105, 0, 99, 0, 111, 0, 100, 0, 101, 0, 32, 0, 115, 0, 116, 0, 114, 0, 105,
        0, 110, 0, 103, 0, 32, 0, 99, 0, 111, 0, 110, 0, 116, 0, 97, 0, 105, 0,
        110, 0, 115, 0, 32, 0, 116, 0, 119, 0, 111, 0, 32, 0, 99, 0, 104, 0, 97, 0,
        114, 0, 97, 0, 99, 0, 116, 0, 101, 0, 114, 0, 115, 0, 32, 0, 119, 0, 105, 0,
        116, 0, 104, 0, 32, 0, 99, 0, 111, 0, 100, 0, 101, 0, 115, 0, 32, 0, 111,
        0, 117, 0, 116, 0, 115, 0, 105, 0, 100, 0, 101, 0, 32, 0, 116, 0, 104, 0,
        101, 0, 32, 0, 65, 0, 83, 0, 67, 0, 73, 0, 73, 0, 32, 0, 99, 0, 111, 0,
        100, 0, 101, 0, 32, 0, 114, 0, 97, 0, 110, 0, 103, 0, 101, 0, 44, 0, 32, 0,
        80, 0, 105, 0, 32, 0, 40, 3, 160, 0, 41, 0, 44, 0, 32, 0, 83, 0, 105, 0,
        103, 0, 109, 0, 97, 0, 32, 0, 40, 3, 163, 0, 41, 0, 32, 0, 97, 0, 110, 0,
        100, 0, 32, 0, 75, 0, 79, 0, 65, 0, 76, 0, 65, 0, 32, 0, 40, 216, 61, 220,
        40, 0, 41, 0, 46
      };

    // Encode the string.
    EncodingUT::Bytes encodedBytes = unicode.GetBytes(unicodeString);
    int index = 0;
    for (byte b : encodedBytes)
      ASSERT_EQ(reference[index++], b);

    ASSERT_EQ(unicodeString.Length(), unicode.GetCharCount(encodedBytes.Data, encodedBytes.Length, 0, encodedBytes.Length));

    // Decode bytes back to string.
    // Notice Pi and Sigma characters are still present.
    string decodedString = unicode.GetString(encodedBytes.Data, encodedBytes.Length);
    ASSERT_TRUE(decodedString.Equals(unicodeString));
  }

  TEST(Unicode_EncodingTest, GetByteCount) {
    EncodingUT::GetByteCountTest(new Text::UnicodeEncoding(false), 2, 2, 2, 4);
  }

  TEST(Unicode_EncodingTest, GetByteCounBigEndian) {
    EncodingUT::GetByteCountTest(new Text::UnicodeEncoding(true), 2, 2, 2, 4);
  }

  TEST(Unicode_EncodingTest, GetBytes) {
    EncodingUT::GetBytesTest(new Text::UnicodeEncoding(false), 2, 2, 2, 4,
      "80, 0, 105, 0, 32, 0, 160, 3, 32, 0, 83, 0, 105, 0, 103, 0, 109, 0, 97, 0, 32, 0, 163, 3, 32, 0, 75, 0, 79, 0, 65, 0, 76, 0, 65, 0, 32, 0, 61, 216, 40, 220",
      "97, 0", "160, 3", "61, 216, 40, 220");
  }

  TEST(Unicode_EncodingTest, GetBytesBigEndian) {
    EncodingUT::GetBytesTest(new Text::UnicodeEncoding(true), 2, 2, 2, 4,
      "0, 80, 0, 105, 0, 32, 3, 160, 0, 32, 0, 83, 0, 105, 0, 103, 0, 109, 0, 97, 0, 32, 3, 163, 0, 32, 0, 75, 0, 79, 0, 65, 0, 76, 0, 65, 0, 32, 216, 61, 220, 40",
      "0, 97", "3, 160", "216, 61, 220, 40");
  }

  TEST(Unicode_EncodingTest, GetCharCount_byte_array_null) {
    Text::UnicodeEncoding encoding(false);
    ASSERT_EQ(0, encoding.GetCharCount(null, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 1), ArgumentNullException);
  }

  TEST(Unicode_EncodingTest, GetCharCount_byte_array_index_count_null) {
    Text::UnicodeEncoding encoding(false);
    ASSERT_EQ(0, encoding.GetCharCount(null, 0, 0, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
  }

  TEST(Unicode_EncodingTest, GetCharCount_byte_array_null_BigEndian) {
    Text::UnicodeEncoding encoding(true);
    ASSERT_EQ(0, encoding.GetCharCount(null, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 1), ArgumentNullException);
  }

  TEST(Unicode_EncodingTest, GetCharCount_byte_array_index_count_null_BigEndian) {
    Text::UnicodeEncoding encoding(true);
    ASSERT_EQ(0, encoding.GetCharCount(null, 0, 0, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
  }

  /*
  TEST(Unicode_EncodingTest, GetCharCount_and_GetChars) {
  byte unicodeBytesUTF16[] = {80, 0, 105, 0, 32, 0, 160, 3, 32, 0, 83, 0, 105,
    0, 103, 0, 109, 0, 97, 0, 32, 0, 163, 3, 32, 0, 75, 0, 79, 0, 65, 0, 76, 0,
    65, 0, 32, 0, 61, 216, 40, 220 };
  EncodingUT::Bytes charBytes = {97, 0};
  EncodingUT::Bytes piBytes = {160, 3};
  EncodingUT::Bytes koalaBytes = {61, 216, 40, 220};

  GetCharCountTest(new Text::UnicodeEncoding(false), 2, 2, 2, 4, new EncodingUT::Bytes(unicodeBytesUTF16),
    charBytes, piBytes, koalaBytes);

  GetCharsTest(new Text::UnicodeEncoding(false), 2, 2, 2, 4, new EncodingUT::Bytes(unicodeBytesUTF16),
    charBytes, piBytes, koalaBytes);
  }

  TEST(Unicode_EncodingTest, GetCharCount_and_GetChars_BigEndian) {
  byte unicodeBytesUTF16BE[] = { 0, 80, 0, 105, 0, 32, 3, 160, 0, 32, 0, 83, 0,
    105, 0, 103, 0, 109, 0, 97, 0, 32, 3, 163, 0, 32, 0, 75, 0, 79, 0, 65, 0,
    76, 0, 65, 0, 32, 216, 61, 220, 40 };
  EncodingUT::Bytes charBytes = {0, 97};
  EncodingUT::Bytes piBytes = {3, 160};
  EncodingUT::Bytes koalaBytes = {216, 61, 220, 40};

  GetCharCountTest(new Text::UnicodeEncoding(true), 2, 2, 2, 4, new EncodingUT::Bytes(unicodeBytesUTF16BE),
    charBytes, piBytes, koalaBytes);

  GetCharsTest(new Text::UnicodeEncoding(true), 2, 2, 2, 4, new EncodingUT::Bytes(unicodeBytesUTF16BE),
    charBytes, piBytes, koalaBytes);
  }*/

}
