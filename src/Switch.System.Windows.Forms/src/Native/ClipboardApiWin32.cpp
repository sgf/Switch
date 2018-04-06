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

string Native::ClipboardApi::GetFormatName(Switch::int32 id) {
  wchar name[128];
  if (!GetClipboardFormatName(id, name, 128)) return "";
  return name;
}

int32 Native::ClipboardApi::GetIdBitmap() {
  return CF_BITMAP;
}

int32 Native::ClipboardApi::GetIdDib() {
  return CF_DIB;
}

int32 Native::ClipboardApi::GetIdDif() {
  return CF_DIF;
}

int32 Native::ClipboardApi::GetIdEnhancedMetafile() {
  return CF_ENHMETAFILE;
}

int32 Native::ClipboardApi::GetIdFileDrop() {
  return CF_HDROP;
}

int32 Native::ClipboardApi::GetIdLocale() {
  return CF_LOCALE;
}

int32 Native::ClipboardApi::GetIdMetafilePict() {
  return CF_METAFILEPICT;
}

int32 Native::ClipboardApi::GetIdOemText() {
  return CF_OEMTEXT;
}

int32 Native::ClipboardApi::GetIdPalette() {
  return CF_PALETTE;
}

int32 Native::ClipboardApi::GetIdPenData() {
  return CF_PENDATA;
}

int32 Native::ClipboardApi::GetIdRiff() {
  return CF_RIFF;
}

int32 Native::ClipboardApi::GetIdSymbolicLink() {
  return CF_SYLK;
}

int32 Native::ClipboardApi::GetIdText() {
  return CFTEXT;
}

int32 Native::ClipboardApi::GetIdTiff() {
  return CF_TIFF;
}

int32 Native::ClipboardApi::GetIdUnicodeText() {
  return CF_UNICODETEXT;
}

int32 Native::ClipboardApi::GetIdWaveAudio() {
  return CF_WAVE;
}

#endif
