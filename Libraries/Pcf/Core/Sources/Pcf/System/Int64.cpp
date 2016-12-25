#include <limits>
#include "../../../Includes/Pcf/System/Int64.h"
#include "../../../Includes/Pcf/System/Convert.h"
#include "../../../Includes/Pcf/System/DivideByZeroException.h"
#include "../../../Includes/Pcf/System/NumericalFormat.h"
#include "../../../Includes/Pcf/System/NumericalParsing.h"

using namespace System;

Property<int64, ReadOnly> Int64::MaxValue{
  [] {return std::numeric_limits<int64>::max();}
};

Property<int64, ReadOnly> Int64::MinValue{
  [] {return std::numeric_limits<int64>::min();}
};

int64 Int64::Parse(const string& value) {
  return Parse(value,10);
}

int64 Int64::Parse(const string& str, int32 base) {
  return NumericalParsing::ParseSigned(str, base, 64);
}

bool Int64::TryParse(const string& str, int64& value) {
  return TryParse(str, 10, value);
}

bool Int64::TryParse(const string& str, Int64& value) {
  return TryParse(str, 10, value.value);
}

bool Int64::TryParse(const string& str, int32 base, int64& value) {
  try {
    value = Parse(str,base);
  } catch(const Exception&) {
    return false;
  }
  return true;
}

bool Int64::TryParse(const string& str, int32 base, Int64& value) {
  return TryParse(str, base, value.value);
}

int32 Int64::GetHashCode() const {
  return (int32)(this->value & 0x00000000FFFFFFFF) ^ (int32)((this->value>>32) & 0x00000000FFFFFFFF);
}

string Int64::ToString() const {
  return ToString("d", Reference<IFormatProvider>::Null());
}

string Int64::ToString(const string& format) const {
  return ToString(format, Reference<IFormatProvider>::Null());
}

string Int64::ToString(const string& format, const IFormatProvider&) const {
  int64 arg = this->value;
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch(type) {
    case 0:   return NumericalFormat::Format_Custom(arg,format);
    case 'b': return NumericalFormat::Format_B(arg, precision, 64);
    case 'd': return NumericalFormat::Format_D(arg, precision);
    case 'f': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_F(arg, precision);
    case 'g':
    case 'G': {
      if (precision == 0) precision = 19;
      return NumericalFormat::Format_G(arg, precision, type == 'G');
    }
    case 'n': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_N(arg, precision);
    case 'p': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_P(arg, precision);
    case 'x': return NumericalFormat::Format_X(arg, precision, false, 16);
    case 'X': return NumericalFormat::Format_X(arg, precision, true,  16);
  }
  return format;
}

int32 Int64::CompareTo(const Int64& value) const {
  if (this->value < value.value) return -1;
  if (this->value == value.value) return 0;
  return 1;
}

int32 Int64::CompareTo(const IComparable& obj) const {
  if (!is<Int64>(obj))
    return 1;
  return CompareTo(static_cast<const Int64&>(obj));
}

TypeCode Int64::GetTypeCode() const {
  return TypeCode::Int64;
}

bool Int64::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte Int64::ToByte(const IFormatProvider&) const {
  if (this->value < Byte::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > Byte::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (sbyte)this->value;
}

char32 Int64::ToChar(const IFormatProvider&) const {
  if (this->value < 0 || this->value > static_cast<int64>(Char::MaxValue))
    throw OverflowException(pcf_current_information);
  
  return (char)this->value;
}

DateTime Int64::ToDateTime(const IFormatProvider&) const {
  return DateTime((int64)this->value);
}

double Int64::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 Int64::ToInt16(const IFormatProvider&) const {
  if (this->value < Int16::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > Int16::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (int16)this->value;
}

int32 Int64::ToInt32(const IFormatProvider&) const {
  if (this->value < Int32::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > Int32::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (int32)this->value;
}

int64 Int64::ToInt64(const IFormatProvider&) const {
  return this->value;
}

uint16 Int64::ToUInt16(const IFormatProvider&) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > UInt16::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (uint16)this->value;
}

uint32 Int64::ToUInt32(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(pcf_current_information);
  
  if (this->value > UInt32::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (uint32)this->value;
}

uint64 Int64::ToUInt64(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(pcf_current_information);
  
  if ((uint64)this->value > UInt64::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (uint64)this->value;
}

sbyte Int64::ToSByte(const IFormatProvider&) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > SByte::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (sbyte)this->value;
}

float Int64::ToSingle(const IFormatProvider&) const {
  return (float)this->value;
}

string Int64::ToString(const IFormatProvider&) const {
  return ToString();
}

Int64::operator int64() const {
  return this->value;
}

Int64& Int64::operator =(const Int64& value) {
  this->value = value.value;
  return *this;
}

Int64& Int64::operator +=(const Int64& value) {
  this->value += value.value;
  return *this;
}

Int64& Int64::operator -=(const Int64& value) {
  this->value -= value.value;
  return *this;
}

Int64& Int64::operator *=(const Int64& value)  {
  this->value *= value.value;
  return *this;
}

Int64& Int64::operator /=(const Int64& value) {
  if (value == 0)
    throw DivideByZeroException(pcf_current_information);

  this->value /= value.value;
  return *this;
}

Int64& Int64::operator %=(const Int64& value) {
  if (value == 0)
    throw DivideByZeroException(pcf_current_information);

  this->value %= value;
  return *this;
}

Int64& Int64::operator &=(const Int64& value) {
   this->value &= value.value;
   return *this;
}

Int64& Int64::operator |=(const Int64& value) {
   this->value |= value.value;
   return *this;
}

Int64& Int64::operator ^=(const Int64& value) {
   this->value ^= value.value;
   return *this;
}

Int64& Int64::operator <<=(const Int64& value) {
   this->value <<= value.value;
   return *this;
}

Int64& Int64::operator >>=(const Int64& value) {
   this->value >>= value.value;
   return *this;
}

Int64& Int64::operator ++() {
  ++this->value;
  return *this;
}

const Int64 Int64::operator ++(int) {
  return this->value++;
}

Int64& Int64::operator --() {
  --this->value;
  return *this;
}

const Int64 Int64::operator --(int) {
  return this->value--;
}

