/// @file
/// @brief Contains Switch::System::Windows::Forms::DragEventArgs class.
#pragma once

#include <Switch/System/Collections/Generic/List.hpp>

#include "../../../System/Windows/Forms/FileDialogCustomPlace.hpp"
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a collection of Windows Vista custom places for the FileDialog class.
        /// @par Library
        /// Switch.System.Windows.Forms
        using FileDialogCustomPlacesCollection = System::Collections::Generic::List<FileDialogCustomPlace>;
      }
    }
  }
}
