#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"

void Native::DebuggerApi::Log(int32 level, const string& category, const string& message) {
  if (string::IsNullOrEmpty(category))
    OutputDebugString(message.w_str().c_str());
  else {
    OutputDebugString(category.w_str().c_str());
    OutputDebugString(L": ");
    OutputDebugString(message.w_str().c_str());
  }
}

#endif
