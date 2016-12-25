#include "../../../Includes/Pcf/System/NumericalParsing.h"
#include "../../../Includes/Pcf/System/Convert.h"
#include "../../../Includes/Pcf/System/NumberRepresentationBase.h"
#include "../../../Includes/Pcf/System/SafeMath.h"
#include "../../../Includes/Pcf/System/SystemException.h"

using namespace System;

namespace Pcf {
  namespace System {
    
    static inline uint32 ToDigit(char32 c) {
      if (c >= '0' && c <= '9')
        return c - '0';
      if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
      if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
      return '?';
    }
    
    static inline bool IsDigit(char32 c, uint32 base) {
      uint32 digit = ToDigit(c);
      return digit != '?' && digit < base;
    }
    
    static void IgnoreSpaces(string::const_reverse_iterator& it, string::const_reverse_iterator end, char32& c) {
      do {
        c = *it;
        if (c != ' ')
          return;
        ++it;
      } while (it != end);
    }
    
    static void IgnoreValidPrefix(string::const_reverse_iterator& it, string::const_reverse_iterator end, char32& c, int32 base) {
      c = *it;
      if (base == (int32)NumberRepresentationBase::Hexadecimal) {
        if (c == 'x' || c == 'X') {
          ++it;
          if (it == end) throw FormatException(pcf_current_information);
          c = *it;
          if (c != '0') throw FormatException(pcf_current_information);
          it++;
        }
      }
      if (base == (int32)NumberRepresentationBase::Binary) {
        if (c == 'b' || c == 'B') {
          if (it == end)
            throw FormatException(pcf_current_information);
          c = *it;
          if (c != '0')
            throw FormatException(pcf_current_information);
          ++it;
        }
      }
    }
    
    static void IgnoreValidSuffix(string::const_reverse_iterator& it, string::const_reverse_iterator end, char32& c, int32 base) {
      c = *it;
      if (c == 'b' || c == 'B') {
        if (base == (int32)NumberRepresentationBase::Binary)
          ++it;
      }
    }
    
    static char ReadSign(string::const_reverse_iterator& it, string::const_reverse_iterator end, char32& c) {
      char sign = 0;
      do {
        c = *it;
        if (sign == 0) {
          if (c == '+' || c == '-') {
            sign = static_cast<char>(c);
            ++it;
            continue; }
        }
        if (c == ' ')
          return sign;
        throw FormatException(pcf_current_information);
      } while (it != end);
      return sign;
    }
    
    static int64 Sign(string::const_reverse_iterator& it, string::const_reverse_iterator end, char32& c, uint64 value) {
      char sign = ReadSign(it, end, c);
      if (sign == '+') {
        ++it;
      }
      if (sign == '-') {
        ++it;
        if (value > 9223372036854775808ULL)
          throw OverflowException(pcf_current_information);
        if (value == 9223372036854775808ULL)
          return Int64::MinValue;
        return -Convert::ToInt64(value);
      }
      return Convert::ToInt64(value);
    }
    
    static uint64 ReadInteger(string::const_reverse_iterator& it, string::const_reverse_iterator end, char32& c, uint32 base) {
      bool oneDigitSeen = false;
      uint64 value = 0;
      uint32 power = 0;
      do {
        c = *it;
        if (!IsDigit(c, base)) {
          if (oneDigitSeen) return value;
          throw FormatException(pcf_current_information);
        } else {
          uint32 curDigit = ToDigit(c);
          oneDigitSeen = true;
          if (curDigit != 0)
            value = SafeMath::Add(value, SafeMath::Mul(SafeMath::PositivePower(base, power),curDigit));
          power += 1;
        }
        ++it;
      } while (it != end);
      return value;
    }
    
    static int64 HandleComplement(uint64 value, int32 base, int32 nbBits) {
      if (base == 2 || base == 8 || base == 16) {
        uint64 mask = 1;
        mask = mask  << (nbBits-1);
        
        if (nbBits == 64) return static_cast<int64>(value);
        
        uint64 maxValue = (mask << 1);
        if (value >= maxValue)
          return Convert::ToInt64(value);
        
        if ((value & mask) != 0) // bit sign on
          return value - maxValue;
      }
      return Convert::ToInt64(value);
    }
    
    int64 NumericalParsing::ParseSigned(const string& str, int32 base, int32 nbBits) {
      if (base <2 || base > 32)
        throw ArgumentException(pcf_current_information);
      
      string::const_reverse_iterator it = str.rbegin();
      if (it == str.rend())
        throw FormatException(pcf_current_information);
      char32 c;
      
      // trim
      IgnoreSpaces(it, str.rend(), c);
      if (it == str.rend())
        throw FormatException(pcf_current_information);
      
      // suffix
      IgnoreValidSuffix(it, str.rend(), c, base);
      if (it == str.rend())
        throw FormatException(pcf_current_information);
      
      // digits
      uint64 value = ReadInteger(it, str.rend(), c, base);
      if (it == str.rend()) {
        return HandleComplement(value, base, nbBits);
      }
      
      // prefix
      IgnoreValidPrefix(it, str.rend(), c, base);
      if (it == str.rend()) {
        return HandleComplement(value, base, nbBits);
      }
      
      //sign
      value = Sign(it, str.rend(), c, value);
      if (it == str.rend())
        return value;
      
      //trim out
      IgnoreSpaces(it, str.rend(),c);
      if (it != str.rend())
        throw FormatException(pcf_current_information);
      else return value;
    }
    
    static void CheckSign(string::const_reverse_iterator& it, string::const_reverse_iterator end, char32& c, uint64 value) {
      char sign = ReadSign(it, end, c);
      if (sign == '+' || (sign == '-' && value == 0)) {
        ++it;
        return;
      }
      if (sign == '-')
        throw OverflowException(pcf_current_information);
    }
    
    uint64 NumericalParsing::ParseUnsigned(const string& str, int32 base) {
      if (base <2 || base > 32)
        throw ArgumentException(pcf_current_information);
      
      string::const_reverse_iterator it = str.rbegin();
      if (it == str.rend())
        throw FormatException(pcf_current_information);
      char32 c;
      
      // trim
      IgnoreSpaces(it, str.rend(), c);
      if (it == str.rend())
         throw FormatException(pcf_current_information);
      
      // suffix
      IgnoreValidSuffix(it, str.rend(), c, base);
      if (it == str.rend())
        throw FormatException(pcf_current_information);
      
      // digits
      uint64 value = ReadInteger(it, str.rend(), c, base);
      if (it == str.rend())
        return value;
      
      // prefix
      IgnoreValidPrefix(it, str.rend(), c, base);
      if (it == str.rend())
        return value;
      
      //sign
      CheckSign(it, str.rend(), c, value);
      if (it == str.rend())
        return value;
      
      //trim out
      IgnoreSpaces(it, str.rend(), c);
      if (it != str.rend())
        throw FormatException(pcf_current_information);
      else return value;
    }
    
  } // System
} // Pcf