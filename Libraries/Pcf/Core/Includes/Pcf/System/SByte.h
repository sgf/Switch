/// @file
/// @brief Contains Pcf::System::SByte struct.
#pragma once

#include <limits>

#include "../Property.h"
#include "Object.h"
#include "../Types.h"
#include "_String.h"
#include "IComparable.h"
#include "IConvertible.h"
#include "IFormattable.h"
#include "ValueType.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    namespace Threading {
      class Interlocked;
    }
    /// @endcond
    
    /// @brief Represents a 8-bit signed integer.
    struct SByte : public ValueType, public IComparable, public IConvertible, public IFormattable {
    public:
      #undef max
      /// @brief Represents the largest possible value of an SByte 127 (0x7F). This field is constant.
      constexpr static sbyte MaxValue = std::numeric_limits<sbyte>::max();

      #undef min
      /// @brief Represents the smallest possible value of SByte -128 (0x80). This field is constant.
      constexpr static sbyte MinValue = std::numeric_limits<sbyte>::min();

      /// @brief Create a new instance of struct SByte
      /// @remarks SByte is initialized with default value 0.
      SByte() {}

      /// @brief Create a new instance of struct SByte
      /// @param value Value for the SByte.
      SByte(sbyte value) : value(value) {}

      /// @brief Converts the specified String representation of a logical value to its 8-bit signed integer equivalent.
      /// @param str A String containing the value to convert.
      /// @return A 8-bit signed integer equivalent to the number contained in str.
      /// @exception ArgumentNullException The parameters str is null.
      static sbyte Parse(const String& str);

      /// @brief Converts the specified String representation of a logical value to its 8-bit signed integer equivalent.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @return A 8-bit signed integer equivalent to the number contained in str.
      /// @exception ArgumentNullException The parameters str is null.
      static sbyte Parse(const String& str, const int32 base);

      /// @brief Converts the specified String representation of a logical value to its 8-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param value When this method returns, contains the 8-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, sbyte& value);

      /// @brief Converts the specified String representation of a logical value to its 8-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param value When this method returns, contains the 8-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, SByte& value);

      /// @brief Converts the specified String representation of a logical value to its 8-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param value When this method returns, contains the 8-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32 base, sbyte& value);

      /// @brief Converts the specified String representation of a logical value to its 8-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param value When this method returns, contains the 8-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32 base, SByte& value);

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current SByte.
      /// @return String A String that represents the current SByte.
      String ToString() const override;

      /// @brief Returns a String that represents the current SByte.
      /// @param format Format-control String.
      /// @param formatProvider an IFormatProvider for specifie the format.
      /// @return String A String that represents the current SByte.
      String ToString(const String& format, const IFormatProvider& formatProvider) const override;

      /// @brief Returns a String that represents the current SByte.
      /// @param format Format-control String.
      /// @return String A String that represents the current SByte.
      String ToString(const String& format) const;

      /// @brief Compares this instance to a specified SByte object and returns an indication of their relative values.
      /// @param value An SByte object to compare with this instance.
      /// @return SByte A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      int32 CompareTo(const SByte& value) const;

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      /// -or-
      /// obj is nullNothingnullptra null reference.
      int32 CompareTo(const IComparable& obj) const override;

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      TypeCode GetTypeCode() const override;

    private:
      /// @cond
      friend class Convert;
      friend class System::Threading::Interlocked;
      /// @endcond

      bool IsSigned() const override { return true; }

      bool ToBoolean(const IFormatProvider& provider) const override;
      byte ToByte(const IFormatProvider& provider) const override;
      char32 ToChar(const IFormatProvider& provider) const override;
      DateTime ToDateTime(const IFormatProvider& provider) const override;
      double ToDouble(const IFormatProvider& provider) const override;
      int16 ToInt16(const IFormatProvider& provider) const override;
      int32 ToInt32(const IFormatProvider& provider) const override;
      int64 ToInt64(const IFormatProvider& provider) const override;
      uint16 ToUInt16(const IFormatProvider& provider) const override;
      uint32 ToUInt32(const IFormatProvider& provider) const override;
      uint64 ToUInt64(const IFormatProvider& provider) const override;
      sbyte ToSByte(const IFormatProvider& provider) const override;
      float ToSingle(const IFormatProvider& provider) const override;
      String ToString(const IFormatProvider& provider) const override;

      sbyte value = 0;

    public:
      /// @cond
      SByte(const SByte& value) : value(value.value) {}
      operator sbyte() const;
      SByte& operator =(const SByte& value);
      SByte& operator +=(const SByte& value);
      SByte& operator -=(const SByte& value);
      SByte& operator *=(const SByte& value);
      SByte& operator /=(const SByte& value);
      SByte& operator %=(const SByte& value);
      SByte& operator &=(const SByte& value);
      SByte& operator |=(const SByte& value);
      SByte& operator ^=(const SByte& value);
      SByte& operator <<=(const SByte& value);
      SByte& operator >>=(const SByte& value);
      SByte& operator ++();
      const SByte operator ++(int);
      SByte& operator --();
      const SByte operator --(int);
      /// @endcond
   };
  }
}

using namespace Pcf;
