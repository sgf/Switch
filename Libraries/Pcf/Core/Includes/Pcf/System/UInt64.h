/// @file
/// @brief Contains Pcf::System::UInt64 struct.
#pragma once

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

    /// @brief Represents a 64-bit unsigned integer.
    struct UInt64 : public ValueType, public IComparable, public IConvertible, public IFormattable {
    public:
      /// @brief Represents the largest possible value of an UInt64 18446744073709551615 (0xFFFFFFFFFFFFFFFF). This field is constant.
      static Property<uint64, ReadOnly> MaxValue;

      /// @brief Represents the smallest possible value of UInt64 0 (0x0000000000000000). This field is constant.
      static Property<uint64, ReadOnly> MinValue;

      /// @brief Create a new instance of struct UInt64
      /// @remarks UInt64 is initialized with default value 0.
      UInt64() {}

      /// @brief Create a new instance of struct UInt64
      /// @param value Value for the UInt64.
      UInt64(uint64 value) : value(value) {}

      /// @brief Converts the specified String representation of a logical value to its 64-bit unsigned integer equivalent.
      /// @param str A String containing the value to convert.
      /// @return  A 64-bit unsigned integer equivalent to the number contained in str.
      /// @exception ArgumentNullException The parameters str is null.
      static uint64 Parse(const String& str);

      /// @brief Converts the specified String representation of a logical value to its 64-bit unsigned integer equivalent.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @return  A 64-bit unsigned integer equivalent to the number contained in str.
      /// @exception ArgumentNullException The parameters str is null.
      static uint64 Parse(const String& str, const int32 base);

      /// @brief Converts the specified String representation of a logical value to its 64-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param value When this method returns, contains the 64-bit unsigned integer value equivalent to the number contained in value, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, uint64& value);

      /// @brief Converts the specified String representation of a logical value to its 64-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param value When this method returns, contains the 64-bit unsigned integer value equivalent to the number contained in value, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, UInt64& value);

      /// @brief Converts the specified String representation of a logical value to its 64-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param value When this method returns, contains the 64-bit unsigned integer value equivalent to the number contained in value, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32 base, uint64& value);

      /// @brief Converts the specified String representation of a logical value to its 64-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param value When this method returns, contains the 64-bit unsigned integer value equivalent to the number contained in value, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32 base, UInt64& value);

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current UInt64.
      /// @return String A String that represents the current UInt64.
      String ToString() const override;

      /// @brief Returns a String that represents the current UInt64.
      /// @param format Format-control String.
      /// @param formatProvider an IFormatProvider for specifie the format.
      /// @return String A String that represents the current UInt64.
      String ToString(const String& format, const IFormatProvider& formatProvider) const override;

      /// @brief Returns a String that represents the current UInt64.
      /// @param format Format-control String.
      /// @return String A String that represents the current UInt64.
      String ToString(const String& format) const;

      /// @brief Compares this instance to a specified UInt64 object and returns an indication of their relative values.
      /// @param value An UInt64 object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero        This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      int32 CompareTo(const UInt64& value) const;

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      This instance is less than value.
      /// @return Zero                This instance is equal to value.
      /// @return Greater than zero   This instance is greater than value.
      /// -or-
      /// @return obj is nullNothingnullptra null reference.
      int32 CompareTo(const IComparable& obj) const override;

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      /// @return @see TypeCode
      TypeCode GetTypeCode() const override;

    private:
      /// @cond
      friend class Convert;
      friend class System::Threading::Interlocked;
      /// @endcond
      uint64 value = 0;

      bool IsSigned() const override { return false; }

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

    public:
      /// @cond
      UInt64(const UInt64& value) : value(value.value) {}
      operator uint64() const;
      UInt64& operator =(const UInt64& value);
      UInt64& operator +=(const UInt64& value);
      UInt64& operator -=(const UInt64& value);
      UInt64& operator *=(const UInt64& value);
      UInt64& operator /=(const UInt64& value);
      UInt64& operator %=(const UInt64& value);
      UInt64& operator &=(const UInt64& value);
      UInt64& operator |=(const UInt64& value);
      UInt64& operator ^=(const UInt64& value);
      UInt64& operator <<=(const UInt64& value);
      UInt64& operator >>=(const UInt64& value);
      UInt64& operator ++();
      const UInt64 operator ++(int);
      UInt64& operator --();
      const UInt64 operator --(int);
      /// @endcond
    };
  }
}

using namespace Pcf;
