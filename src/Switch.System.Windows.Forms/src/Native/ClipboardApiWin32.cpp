#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Switch/Undef.hpp>
#include "Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

int32 Native::ClipboardApi::RegisterFormat(const Switch::string& format) {
  return RegisterClipboardFormat(format.w_str().c_str());
}

int32 Native::ClipboardApi::GetIdBitmap() {
  return CF_BITMAP;
}

#endif
