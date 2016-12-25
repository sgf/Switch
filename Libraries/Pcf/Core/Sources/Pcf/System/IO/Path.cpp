#include <cstdio>
#include <cstring>

#include "../../../../Includes/Pcf/System/IO/Path.h"
#include "../../../../Includes/Pcf/System/IO/File.h"
#include "../../../../Includes/Pcf/System/IO/DriveInfo.h"
#include "../../../../Includes/Pcf/System/IO/FileAttributes.h"
#include "../../../../Includes/Pcf/System/Char.h"
#include "../../../../Includes/Pcf/System/Random.h"
#include "../../Os/Directory.h"

using namespace System;
using namespace System::IO;

const char32 Path::AltDirectorySeparatorChar = Os::Directory::AltDirectorySeparatorChar();

const char32 Path::DirectorySeparatorChar = Os::Directory::DirectorySeparatorChar();

const char32 Path::PathSeparator = Os::Directory::PathSeparator();

const char32 Path::VolumeSeparatorChar = Os::Directory::VolumeSeparator();

Array<char32> DirectorySeparatorChars = {'/', '\\'};

string Path::ChangeExtension(const string& path, const string& extension) {
  string pathWithoutExtension = Combine(GetDirectoryName(path), GetFileNameWithoutExtension(path));
  if (string::IsNullOrEmpty(pathWithoutExtension) && !string::IsNullOrEmpty(extension))
    return pathWithoutExtension;
  return string::Format("{0}{1}{2}", pathWithoutExtension, pathWithoutExtension.EndsWith('.')  || extension.StartsWith('.') ? "" : ".", extension);
}

string Path::GetDirectoryName(const string& path) {
  int32 index = path.LastIndexOfAny(DirectorySeparatorChars);
  if (index == -1 || index == path.Length)
    return "";
  string directory = path.Remove(index+1);
  return (directory.LastIndexOfAny(DirectorySeparatorChars) == directory.Length-1) ? directory.Remove(directory.Length-1) : directory;
}

string Path::GetExtension(const string& path) {
  string file = GetFileName(path);
  int32 index = file.LastIndexOf('.');
  return (index == -1 || index == file.Length) ? "" : file.Substring(index);
}

String Path::GetFileName(const String& path) {
  int32 index = path.LastIndexOfAny(DirectorySeparatorChars);
  return (index == -1 || index == path.Length) ? path : path.Substring(index+1);
}

string Path::GetFileNameWithoutExtension(const string& path) {
  string file = GetFileName(path);
  int32 index = file.LastIndexOf('.');
  return (index == -1 || index == file.Length) ? file : file.Remove(index);
}

string Path::GetFullPath(const string& path) {
  if (path.IndexOfAny(GetInvalidPathChars()) != -1)
    throw ArgumentException(pcf_current_information);
  
  return Os::Directory::GetFullPath(path);
}

Array<char32> Path::GetInvalidPathChars() {
  return Array<char32>(Os::Directory::InvalidPathChars());
}

namespace {
  bool IsDrive(const string& path) {
    for (auto drive : DriveInfo::GetDrives())
      if (drive.Name == path)
        return true;
    return false;
  }

  static int32 GetIndexPathRooted(const String& path) {
    int32 index = path.IndexOfAny(DirectorySeparatorChars);
    return (index == -1 || index == path.Length || (index != 0 && !IsDrive(path.Substring(0, index+1)))) ? -1 : index;
  }
}

string Path::GetPathRoot(const string& path) {
  return IsPathRooted(path) ? path.Remove(GetIndexPathRooted(path)+1) : "";
}

string Path::GetRandomFileName() {
  static string validChars = "1234567890abcdefghijklmnopqrstuvwxyz";
  static Random rand;
  string randomFileName;
  
  for (int32 i = 0; i < 11; i++) {
    randomFileName += validChars[rand.Next(validChars.Length)];
    if (i == 7)
      randomFileName += '.';
  }
  
  return randomFileName;
}

string Path::GetTempPath() {
  return Os::Directory::GetTempPath();
}

string Path::GetTempFileName() {
  static string validChars = "1234567890abcdef";
  string tempFileName;
  do {
    static Random rand;
    tempFileName = "tmp";
    
    for (int32 i = 0; i < 8; i++) {
      if (i == 0)
        tempFileName += validChars[rand.Next(10)];
      else
        tempFileName += validChars[rand.Next(validChars.Length)];
    }
    tempFileName += ".tmp";
  } while (File::Exists(Combine(GetTempPath(), tempFileName)));

  FILE* file = fopen(Combine(GetTempPath(), tempFileName).Data(), "w");
  if (file != null)
    fclose(file);
  
  return Combine(GetTempPath(), tempFileName);
}

bool Path::IsPathRooted(const String& path) {
  return GetIndexPathRooted(path) != -1;
}

