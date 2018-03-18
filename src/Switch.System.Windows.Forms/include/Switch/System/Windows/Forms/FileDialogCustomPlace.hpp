/// @file
/// @brief Contains Switch::System::Windows::Forms::DragEventArgs class.
#pragma once

#include <Switch/System/Guid.hpp>

#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents an entry in a FileDialog custom place collection for Windows Vista.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The default open and save dialog boxes on Windows Vista have an area on the left side of the dialog box titled Favorite Links. This area is called custom places. This class represents a custom place.
        /// @remarks On macOS, Linux, Windows XP and Windows Server 2003, this class does not have any effect.
        class system_windows_forms_export_ FileDialogCustomPlace : public object {
        public:
          /// @cond
          FileDialogCustomPlace() {}
          FileDialogCustomPlace(const FileDialogCustomPlace& fileDialogCustomPlace) : knownFolderGuid(fileDialogCustomPlace.knownFolderGuid), path(fileDialogCustomPlace.path) {}
          FileDialogCustomPlace& operator=(const FileDialogCustomPlace& fileDialogCustomPlace) = default;
          /// @endcond

          /// @brief Initializes a new instance of the FileDialogCustomPlace class with a custom place identified by a Windows Vista Known Folder GUID.
          /// @param knownFolderGuid A Guid that represents a Windows Vista Known Folder.
          explicit FileDialogCustomPlace(const Guid& knownFolderGuid) : knownFolderGuid(knownFolderGuid) {}

          /// @brief Initializes a new instance of the FileDialogCustomPlace class. with a specified folder path to a custom place.
          /// @param path A folder path to the custom place.
          explicit FileDialogCustomPlace(const string& path) : path(path) {}

          /// @brief Gets or sets the Windows Vista Known Folder GUID for the custom place.
          /// @return Guid A Guid that indicates the Windows Vista Known Folder for the custom place. If the custom place was specified with a folder path, then an empty GUID is returned. For a list of the available Windows Vista Known Folders, see Known Folder GUIDs for File Dialog Custom Places or the KnownFolders.h file in the Windows SDK.
          property_<Guid> KnownFolderGuid {
            get_ {return this->knownFolderGuid;},
            set_ {this->knownFolderGuid = value;}
          };

          /// @brief Gets or sets the folder path to the custom place.
          /// @return string A folder path to the custom place. If the custom place was specified with a Windows Vista Known Folder GUID, then an empty string is returned.
          property_<string> Path {
            get_ {return this->path;},
            set_ {this->path = value;}
          };

        private:
          Guid knownFolderGuid;
          string path;
        };
      }
    }
  }
}
