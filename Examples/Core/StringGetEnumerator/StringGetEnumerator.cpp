#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
    static void EnumerateAndDisplay(const string& phrase) {
      Console::WriteLine("The characters in the string \"{0}\" are:", phrase);
      
      int charCount = 0;
      int controlChars = 0;
      int alphanumeric = 0;
      int punctuation = 0;
      
      for (char32 ch : phrase) {
        Console::Write("'{0}' ", (! Char::IsControl(ch) ? Char(ch).ToString() : "0x" + UInt16(Convert::ToUInt16(ch)).ToString("%04X")));
        if (Char::IsLetterOrDigit(ch))
          alphanumeric++;
        else if (Char::IsControl(ch))
          controlChars++;
        else if (Char::IsPunctuation(ch))
          punctuation++;
        charCount++;
      }
      
      Console::WriteLine("\n   Total characters:        {0,3}", charCount);
      Console::WriteLine("   Alphanumeric characters: {0,3}", alphanumeric);
      Console::WriteLine("   Punctuation characters:  {0,3}", punctuation);
      Console::WriteLine("   Control Characters:      {0,3}\n", controlChars);
    }
    
  public:
    // The main entry point for the application.
    static void Main() {
      EnumerateAndDisplay("Test Case");
      EnumerateAndDisplay("This is a sentence.");
      EnumerateAndDisplay("Has\ttwo\ttabs" );
      EnumerateAndDisplay("Two\nnew\nlines");
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// The characters in the string "Test Case" are:
// 'T' 'e' 's' 't' ' ' 'C' 'a' 's' 'e'
//    Total characters:          9
//    Alphanumeric characters:   8
//    Punctuation characters:    0
//    Control Characters:        0
//
// The characters in the string "This is a sentence." are:
// 'T' 'h' 'i' 's' ' ' 'i' 's' ' ' 'a' ' ' 's' 'e' 'n' 't' 'e' 'n' 'c' 'e' '.'
//    Total characters:         19
//    Alphanumeric characters:  15
//    Punctuation characters:    1
//    Control Characters:        0
//
// The characters in the string "Has	two	tabs" are:
// 'H' 'a' 's' '0x0009' 't' 'w' 'o' '0x0009' 't' 'a' 'b' 's'
//    Total characters:         12
//    Alphanumeric characters:  10
//    Punctuation characters:    0
//    Control Characters:        2
//
// The characters in the string "Two
// new
// lines" are:
// 'T' 'w' 'o' '0x000A' 'n' 'e' 'w' '0x000A' 'l' 'i' 'n' 'e' 's'
//    Total characters:         13
//    Alphanumeric characters:  11
//    Punctuation characters:    0
//    Control Characters:        2