#if defined(__APPLE__)
#include "Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

static const int32 CF_BITMAP = 2;

int32 Native::ClipboardApi::RegisterFormat(const Switch::string &format) {
  return 0;
}

int32 Native::ClipboardApi::GetIdBitmap() {
  return CF_BITMAP;
}

#endif
