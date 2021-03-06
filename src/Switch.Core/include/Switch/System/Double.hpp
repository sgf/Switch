/// @file
/// @brief Contains Switch::System::Double struct.
#pragma once

#include <limits>
#include "../Property.hpp"
#include "Object.hpp"
#include "../Types.hpp"
#include "_String.hpp"
#include "IComparable.hpp"
#include "IConvertible.hpp"
#include "IFormattable.hpp"
#include "TypeCode.hpp"
#include "ValueType.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a double-precision floating-point number.
    /// @par Library
    /// Switch.Core
    struct core_export_ Double final : public ValueType, public IComparable, public IConvertible, public IFormattable {
    public:
      /// @brief Represents the smallest positive Double value greater than zero. This field is constant.
      static constexpr double Epsilon = 4.94066e-324;

      /// @brief Represents the largest possible value of an Double 1.7976931348623157E+308. This field is constant.
      static constexpr double MaxValue = std::numeric_limits<double>::max();

      /// @brief Represents the smallest possible value of Double -1.7976931348623157E+308. This field is constant.
      static constexpr double MinValue = -std::numeric_limits<double>::max();

      /// @brief Represents not a number (NaN). This field is constant.
      static constexpr double NaN = std::numeric_limits<double>::quiet_NaN();

      /// @brief Represents negative infinity. This field is constant.
      static constexpr double NegativeInfinity = -std::numeric_limits<double>::infinity();

      /// @brief Represents positive infinity. This field is constant.
      static constexpr double PositiveInfinity = std::numeric_limits<double>::infinity();

      /// @brief Create a new instance of struct Double
      Double() {}

      /// @brief Create a new instance of struct Double
      /// @param value Value for the Double.
      Double(double value) : value(value) {}

      /// @brief Converts the specified String representation of a logical value to its Represents a double-precision floating-point number equivalent.
      /// @param str A String containing the value to convert.
      /// @return A Represents a double-precision floating-point number equivalent to the number contained in str.
      /// @exception ArgumentnullException The parameters str is null.
      static double Parse(const String& str);

      /// @brief Returns a value indicating whether the specified number evaluates to negative or positive infinity.
      /// @param value A double-precision floating-point number.
      /// @return bool true if value evaluates to PositiveInfinity or NegativeInfinity; otherwise, false.
      static bool IsInfinity(double value) { return IsNegativeInfinity(value) || IsPositiveInfinity(value); }

      /// @brief Returns a value indicating whether the specified number evaluates to not a number.
      /// @param value A double-precision floating-point number.
      /// @return bool true if value evaluates to not a number; otherwise, false.
      static bool IsNaN(double value) { return value != value; }

      /// @brief Returns a value indicating whether the specified number evaluates to negative infinity.
      /// @param value A double-precision floating-point number.
      /// @return Boolean true if value evaluates to NegativeInfinity; otherwise, false.
      static bool IsNegativeInfinity(double value) { return (value <= NegativeInfinity); }

      /// @brief Returns a value indicating whether the specified number evaluates to positive infinity.
      /// @param value A double-precision floating-point number.
      /// @return bool true if value evaluates to PositiveInfinity; otherwise, false.
      static bool IsPositiveInfinity(double value) { return (value >= PositiveInfinity); }

      /// @brief Determines whether this instance of Double and a specified Object, which must also be a Double Object, have the same value.
      /// @param value The Double to compare with the current Object.
      /// @exception ArgumentNullException The parameters value is null.
      /// @return bool true if the specified value is equal to the current Object. otherwise, false.
      bool Equals(const Double& value) const;

      /// @brief Determines whether this instance of Double and a specified Object, which must also be a Double Object, have the same value.
      /// @param obj The Object to compare with the current Object.
      /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
      /// @exception ArgumentNullException The parameters obj is null.
      bool Equals(const Object& obj) const override;

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current Object.
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current Double.
      /// @return String A String that represents the current Double.
      String ToString() const override;
      String ToString(const String& format, const IFormatProvider& formatProvider) const override;

      /// @brief Returns a String that represents the current Double.
      /// @param format Format-control String.
      /// @return String A String that represents the current Double.
      String ToString(const String& format) const;

      /// @brief Compares this instance to a specified Double Object and returns an indication of their relative values.
      /// @param value An Double Object to compare with this instance.
      /// @return Double A 32-bit signed integer that indicates the relative order of the Objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      int32 CompareTo(const Double& value) const;

      /// @brief Compares the current instance with another Object of the same type.
      /// @param obj An Object to compare with this instance.
      /// @return Double A 32-bit signed integer that indicates the relative order of the Objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      /// -or-
      /// obj is nullNothingnullptra null reference.
      virtual int32 CompareTo(const IComparable& obj) const override;

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      /// @see TypeCode
      TypeCode GetTypeCode() const override;

    private:
      friend class Convert;

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

      double value = 0.0;

    public:
      /// @cond
      Double(const Double& value) : value(value.value) {}
      operator double() const;
      Double& operator =(const Double& value);
      Double& operator +=(const Double& value);
      Double& operator -=(const Double& value);
      Double& operator *=(const Double& value);
      Double& operator /=(const Double& value);
      Double& operator ++();
      const Double operator ++(int);
      Double& operator --();
      const Double operator --(int);
      /// @endcond
    };
  }
}

using namespace Switch;
