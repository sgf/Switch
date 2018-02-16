#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"
#include "../../include/Switch/System/Collections/Generic/List.hpp"

bool Native::DriveApi::GetAvailableFreeSpace(const string& rootPathName, int64& freeBytes, int64& totalNumberOfBytes, int64& totalNumberOfFreeBytes) {
  return GetDiskFreeSpaceEx(rootPathName.w_str().c_str(), (PULARGE_INTEGER)&freeBytes, (PULARGE_INTEGER)&totalNumberOfBytes, (PULARGE_INTEGER)&totalNumberOfFreeBytes) != FALSE;
}

System::IO::DriveType Native::DriveApi::GetDriveType(const string& rootPathName) {
  return (System::IO::DriveType)::GetDriveTypeW(rootPathName.w_str().c_str());
}

System::Array<string> Native::DriveApi::GetDrives() {
  char buffer[MAX_PATH];
  int32 bufferLenght = MAX_PATH;
  if (::GetLogicalDriveStringsA(bufferLenght, buffer) <= 0)
    return {};
  System::Collections::Generic::List<string> drives;
  for (const char* drive = buffer; drive[0] != 0; drive += strlen(drive) + 1)
    drives.Add(drive);
  return drives.ToArray();
}

bool Native::DriveApi::GetVolumeInformation(const string& rootPathName, string& volumeName, string& fileSystemName) {
  DWORD fileSystemFlags = 0;
  wchar volume[MAX_PATH];
  wchar fileSystem[MAX_PATH];
  if (::GetVolumeInformationW(rootPathName.w_str().c_str(), volume, MAX_PATH, null, null, &fileSystemFlags, fileSystem, MAX_PATH) == FALSE)
    return false;

  volumeName = volume;
  fileSystemName = fileSystem;

  return true;
}

bool Native::DriveApi::SetVolumeLabel(const string& rootPathName, const string& volumeName) {
  return SetVolumeLabelW(rootPathName.w_str().c_str(), volumeName.w_str().c_str()) > 0;
}

#endif
