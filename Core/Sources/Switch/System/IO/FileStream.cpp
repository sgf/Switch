#include <cstring>

#include "../../../../Includes/Switch/System/ObjectClosedException.hpp"
#include "../../../../Includes/Switch/System/IO/Directory.hpp"
#include "../../../../Includes/Switch/System/IO/DirectoryNotFoundException.hpp"
#include "../../../../Includes/Switch/System/IO/FileStream.hpp"
#include "../../../../Includes/Switch/System/IO/File.hpp"
#include "../../../../Includes/Switch/System/IO/FileNotFoundException.hpp"
#include "../../../../Includes/Switch/System/IO/Path.hpp"

using namespace System;
using namespace System::IO;

FileStream::FileStream(const string& path, FileMode mode, FileAccess access, FileShare share) {
  if (path.IsEmpty() || path.IndexOfAny(Path::GetInvalidPathChars()) != -1)
    throw ArgumentException(_current_information);
  
  this->data->fullPath = Path::GetFullPath(path);
  this->data->fileMode = mode;
  this->data->fileAccess = access;
  
  if (access == FileAccess::Read && (mode == FileMode::Create || mode == FileMode::CreateNew))
      throw ArgumentException(_current_information);
  
  if (mode == FileMode::Append && access != FileAccess::Write)
    throw ArgumentException(_current_information);
  
  if (File::Exists(this->data->fullPath)) {
    if (access == FileAccess::Read && mode == FileMode::Truncate)
      throw ArgumentException(_current_information);
    
    if (mode == FileMode::CreateNew)
      throw IOException(_current_information);
    
  } else {
    if (mode == FileMode::Open ||  mode == FileMode::Truncate)
      throw FileNotFoundException(_current_information);
    
    if ((mode == FileMode::Create || mode == FileMode::CreateNew || mode == FileMode::OpenOrCreate)) {
      std::fstream fs(path.Data(), std::fstream::out);
      fs.close();
    }
  }
  
  if (!Directory::Exists(Path::GetDirectoryName(this->data->fullPath)))
    throw DirectoryNotFoundException(_current_information);
  
  this->data->openMode = std::ios_base::binary;
  if (access == FileAccess::Read || access == FileAccess::ReadWrite)
    this->data->openMode |= std::ios_base::in;
  
  // if open + write, .NET does not erase the existing file, we simulate it by forcing read mode (internally
  if ((mode == FileMode::Open || mode == FileMode::OpenOrCreate) && access == FileAccess::Write)
    this->data->openMode |= std::ios_base::in;
  
  if (access == FileAccess::Write || access == FileAccess::ReadWrite)
    this->data->openMode |= std::ios_base::out;
  
  if (mode == FileMode::Append)
    this->data->openMode |= std::ios_base::app;
  
  this->data->stream.open(path.ToCCharArray().Data(), this->data->openMode);
  if (this->data->stream.fail())
    throw IOException(_current_information);
}

int64 FileStream::GetLength() const {
  int64 position = this->GetPosition();
  int64 fileSize = const_cast<std::fstream&>(this->data->stream).seekg(0, std::ios::end).tellg();
  const_cast<FileStream&>(*this).SetPosition(position);
  return fileSize;
}

int64 FileStream::GetPosition() const {
  return const_cast<FileStream*>(this)->Seek(0, SeekOrigin::Current);
}

void FileStream::SetLength(int64 length) {
  if (IsClosed() == true)
    throw ObjectClosedException(_current_information);

  if (length < 0)
    throw ArgumentOutOfRangeException(_current_information);

  // todo (?)
  throw NotSupportedException(_current_information);
}

bool FileStream::GetIsClosed() const {
  return !this->data->stream.is_open();
}

void FileStream::Close() {
  if (IsClosed()) 
    return;
  this->data->stream.close();
}

void FileStream::Flush() {
  this->data->stream.flush();
}

int32 FileStream::Read(Array<byte>& buffer, int32 offset, int32 count) {
  if (count < 0 || offset < 0)
    throw ArgumentOutOfRangeException(_current_information);
  if (offset + count > buffer.Length)
    throw ArgumentException(_current_information);
  if (IsClosed())
    throw ObjectClosedException(_current_information);
  if (!CanRead())
    throw NotSupportedException(_current_information);

  this->data->stream.read((char*)&const_cast<byte*>(buffer.Data())[offset],count);
  std::fstream::pos_type nbRead = this->data->stream.gcount();
  return int32(nbRead);
}

int32 FileStream::ReadByte() {
  if (IsClosed())
    throw ObjectClosedException(_current_information);
  if (!CanRead())
    throw NotSupportedException(_current_information);
  
  return this->data->stream.get();
}

int64 FileStream::Seek(int64 offset, SeekOrigin origin) {
  if (this->data->fileAccess == FileAccess::Read)
    return this->data->stream.seekg(static_cast<std::fstream::off_type>(offset), static_cast<std::ios::seekdir>(origin)).tellg();
  
  if (this->data->fileAccess == FileAccess::Write)
    return this->data->stream.seekp(static_cast<std::fstream::off_type>(offset), static_cast<std::ios::seekdir>(origin)).tellp();
  
  this->data->stream.seekg(static_cast<std::fstream::off_type>(offset), static_cast<std::ios::seekdir>(origin)).tellg();
  return this->data->stream.seekp(static_cast<std::fstream::off_type>(offset), static_cast<std::ios::seekdir>(origin)).tellp();
}

void FileStream::Write(const Array<byte>& buffer, int32 offset, int32 count) {
  if (count < 0 || offset < 0)
    throw ArgumentOutOfRangeException(_current_information);
  if (offset + count > buffer.Length)
    throw ArgumentException(_current_information);
  if (IsClosed())
    throw ObjectClosedException(_current_information);
  if (!CanWrite())
    throw NotSupportedException(_current_information);

  this->data->stream.write((const char*)&buffer.Data()[offset],count);
  if (this->data->stream.fail())
    throw IOException(_current_information);
}

int32 FileStream::Peek() {
  if (!CanRead())
    throw NotSupportedException(_current_information);
  return this->data->stream.peek();
}
