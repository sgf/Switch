#include "../../../../include/Switch/Types.hpp"
#include "../../../../include/Switch/System/IO/FileInfo.hpp"
#include "../../../../include/Switch/System/Security/SecurityException.hpp"
#include "../../../../include/Switch/System/IO/DirectoryInfo.hpp"
#include "../../../../include/Switch/System/IO/File.hpp"
#include "../../../../include/Switch/System/IO/FileNotFoundException.hpp"
#include "../../../../include/Switch/System/IO/Path.hpp"
#include "../../../Native/CoreApi.hpp"

using namespace System;
using namespace System::IO;

_property<FileInfo, _readonly> FileInfo::Empty {
  [] {return FileInfo();}
};

FileInfo::FileInfo() : Directory(_delegate {return this->GetDirectory();}) {
}

FileInfo::FileInfo(const string& fileName) : Directory(_delegate {return this->GetDirectory();}) {
  this->fullPath = Path::GetFullPath(fileName);
}

FileInfo::FileInfo(const FileInfo& fileInfo) : FileSystemInfo(fileInfo), Directory(_delegate {return this->GetDirectory();}) { }

bool FileInfo::GetExists() const {
  System::IO::FileAttributes fileAttributes = (System::IO::FileAttributes)0;
  return (Native::CoreApi::Directory::GetFileAttributes(this->fullPath.ToCCharArray().Data(), fileAttributes) == 0 && !Enum<FileAttributes>(fileAttributes).HasFlag(FileAttributes::Directory));
}

DirectoryInfo FileInfo::GetDirectory() const {
  return DirectoryInfo(DirectoryName());
}

string FileInfo::GetDirectoryName() const {
  return Path::Combine(Path::GetPathRoot(this->fullPath), Path::GetDirectoryName(this->fullPath));
}

string FileInfo::GetName() const {
  return Path::GetFileName(this->fullPath);
}

void FileInfo::Delete() {
  if (Native::CoreApi::Directory::RemoveFile(this->fullPath.ToCCharArray().Data()) != 0)
    throw System::Security::SecurityException(_caller);
}

FileInfo FileInfo::CopyTo(const string& destFileName) {
  if (!Exists())
    throw FileNotFoundException(_caller);
  
  if (File::Exists(destFileName))
    throw IOException(_caller);
  
  string fullPathDestFileName = Path::GetFullPath(destFileName);
  
  FILE* source = fopen(this->fullPath.ToCCharArray().Data(), "rb");
  if (source == null)
    throw IOException(_caller);
  
  FILE* target = fopen(fullPathDestFileName.ToCCharArray().Data(), "wb");
  if (target == null) {
    fclose(source);
    throw IOException(_caller);
  }
  
  int32 count = 0;
  do {
    byte buffer[1024];
    count = Convert::ToInt32(fread(buffer, 1, 1024, source));
    if (count > 0)
      fwrite(buffer, 1, count, target);
  } while (count == 1024);
  
  fclose(source);
  fclose(target);
  
  return FileInfo(fullPathDestFileName);
}

FileInfo FileInfo::CopyTo(const string& destFileName, bool overwrite) {
  if (overwrite) {
    FileInfo DestFileInfo(destFileName);
    if (DestFileInfo.Exists())
      DestFileInfo.Delete();
  }
  return CopyTo(destFileName);
}

void FileInfo::MoveTo(const string& destFileName) {
  if (!Exists())
    throw FileNotFoundException(_caller);
  
  if (!Path::HasExtension(destFileName))
    throw ArgumentException(_caller);
  
  string fullPathDestFileName = Path::GetFullPath(destFileName);
  if (Native::CoreApi::Directory::RenameFile(this->fullPath, fullPathDestFileName) != 0)
    throw IOException(_caller);
  
  this->fullPath = fullPathDestFileName;
}

int64 FileInfo::GetLength() const {
  return Native::CoreApi::Directory::GetFileSize(this->fullPath);
}

FileStream FileInfo::Open(FileMode mode, FileAccess access) {
  return FileStream(this->fullPath, mode, access, FileShare(FileShare::None));
}

FileStream FileInfo::OpenRead() {
  return FileStream(this->fullPath, FileMode(FileMode::Open), FileAccess(FileAccess::Read), FileShare(FileShare::None));
}

FileStream FileInfo::OpenWrite() {
  return FileStream(this->fullPath, FileMode(FileMode::OpenOrCreate), FileAccess(FileAccess::Write), FileShare(FileShare::None));
}

bool FileInfo::Equals(const FileInfo& value) const {
  return this->fullPath.Equals(value.fullPath);
}

bool FileInfo::Equals(const object& obj) const {
  return is<FileInfo>(obj) && Equals((const FileInfo&)obj);
}

string FileInfo::ToString() const {
  return FullName();
}
