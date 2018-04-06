#if defined(__APPLE__)
#include "Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

static const int32 CFTEXT = 1;
static const int32 CF_BITMAP = 2;
static const int32 CF_METAFILEPICT = 3;
static const int32 CF_SYLK = 4;
static const int32 CF_DIF = 5;
static const int32 CF_TIFF = 6;
static const int32 CF_OEMTEXT = 7;
static const int32 CF_DIB = 8;
static const int32 CF_PALETTE = 9;
static const int32 CF_PENDATA = 10;
static const int32 CF_RIFF = 11;
static const int32 CF_WAVE = 12;
static const int32 CF_UNICODETEXT = 13;
static const int32 CF_ENHMETAFILE = 14;
static const int32 CF_HDROP = 15;
static const int32 CF_LOCALE = 16;
static int32 idCounter = 17;

int32 Native::ClipboardApi::RegisterFormat(const Switch::string &format) {
  return idCounter++;
}

string Native::ClipboardApi::GetFormatName(Switch::int32 id) {
  return "";
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
