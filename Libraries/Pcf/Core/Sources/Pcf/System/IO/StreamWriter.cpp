#include "../../../../Includes/Pcf/System/ObjectClosedException.h"
#include "../../../../Includes/Pcf/System/IO/StreamWriter.h"
#include "../../../../Includes/Pcf/System/IO/File.h"
#include "../../../../Includes/Pcf/System/IO/FileStream.h"
#include "../../../../Includes/Pcf/System/Text/UTF8Encoding.h"

using namespace System;
using namespace System::IO;

namespace {
  Text::UTF8Encoding utf8Encoding(false);
}

const StreamWriter StreamWriter::Null;

StreamWriter::StreamWriter() : TextWriter(utf8Encoding) {
  this->data->stream = new NullStream();
}

StreamWriter::StreamWriter(const string& path) : TextWriter(utf8Encoding) {
  this->data->stream = new FileStream(path, FileMode::Create, FileAccess::Write, FileShare::Read);
}

StreamWriter::StreamWriter(const string& path, bool append, Text::Encoding& encoding) : TextWriter(encoding) {
  this->data->stream = new FileStream(path, (append && File::Exists(path)) ? FileMode::Append : FileMode::Create, FileAccess(FileAccess::Write), FileShare(FileShare::Read));
}

StreamWriter::StreamWriter(const string& path, bool append) : TextWriter(utf8Encoding) {
  this->data->stream = new FileStream(path, (append && File::Exists(path)) ? FileMode::Append : FileMode::Create, FileAccess(FileAccess::Write), FileShare(FileShare::Read));
}

bool StreamWriter::GetAutoFlush() const {
  return this->data->autoFlush;
}

void StreamWriter::SetAutoFlush(bool autoFlush) {
  this->data->autoFlush = autoFlush;
}

Stream& StreamWriter::GetBaseStream() {
  return *this->data->stream;
}

void StreamWriter::Close() {
  this->data->stream->Close();
}

void StreamWriter::Flush() {
    this->data->stream->Flush();
}

void StreamWriter::Write(const string& value) {
  Array<byte> bytes = Encoding().GetBytes(value);
  int32 length = bytes.Length;
  if (length != 0)
    this->data->stream->Write(bytes, 0, length);
  
  if (this->data->autoFlush)
    Flush();
}

