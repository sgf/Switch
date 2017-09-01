#include "../../../Includes/Switch/System/UIntPtr.hpp"
#include "../../../Includes/Switch/System/Array.hpp"
#include "../../../Includes/Switch/System/Int32.hpp"
#include "../../../Includes/Switch/System/OverflowException.hpp"
#include "../../../Includes/Switch/System/UInt32.hpp"
#include "../../../Includes/Switch/System/UInt64.hpp"

using namespace System;

Property<uintptr, ReadOnly> UIntPtr::Zero {
  [] {return 0;}
};

Property<int32, ReadOnly> UIntPtr::Size {
  [] {return static_cast<int32>(sizeof(void*));}
};

UIntPtr::UIntPtr(const UInt32& value) {
  this->value = (uint32)value;
}

UIntPtr::UIntPtr(const UInt64& value) {
  if (Size == 4 && value > UInt32::MaxValue)
    throw OverflowException(_current_information);

  this->value = (uint64)value;
}

UIntPtr::UIntPtr(uintptr value) {
  this->value = value;
}

bool UIntPtr::Equals(const UIntPtr& value) const {
  return this->value == value.value;
}

bool UIntPtr::Equals(const object& obj) const {
  return is<UIntPtr>(obj) && Equals(static_cast<const UIntPtr&>(obj));
}

int32 UIntPtr::GetHashCode() const {
  uint64 handleValue = this->value;
  int32 hash = 0;

  hash = static_cast<int32>(handleValue & 0x00000000FFFFFFFF);
  hash = hash ^ static_cast<int32>((handleValue>>32) & 0x00000000FFFFFFFF);

  return hash;
}

int32 UIntPtr::CompareTo(const UIntPtr& value) const {
  return static_cast<int32>(this->value - value.value);
}

int32 UIntPtr::CompareTo(const IComparable& obj) const {
  if (!is<UIntPtr>(obj))
    return 1;

  return CompareTo(static_cast<const UIntPtr&>(obj));
}

uint32 UIntPtr::ToUInt32() const {
  if (Size == 8 && this->value > UInt32::MaxValue)
    throw OverflowException(_current_information);

  return *((uint32*)&this->value);
}

uint64 UIntPtr::ToUInt64() const {
  if (UIntPtr::Size == 4)
    return *((int32*)&this->value);
  return this->value;
}

void* UIntPtr::ToPointer() const {
  return (void*)this->value;
}

string UIntPtr::ToString() const {
  return UInt64(ToUInt64()).ToString();
}

string UIntPtr::ToString(const string& format) const {
  return UInt64(ToUInt64()).ToString(format);
}

string UIntPtr::ToString(const string& format, const IFormatProvider& formatProvider) const {
  return UInt64(ToUInt64()).ToString(format);
}

UIntPtr::operator uintptr() const {
  return this->value;
}

UIntPtr& UIntPtr::operator =(const UIntPtr& value) {
  this->value = value.value;
  return *this;
}

