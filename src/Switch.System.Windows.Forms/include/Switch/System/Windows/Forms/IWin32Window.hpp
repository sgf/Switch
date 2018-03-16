/// @file
/// @brief Contains Switch::System::Windows::Forms::IDataObject interface.
#pragma once

#include <Switch/Interface.hpp>
#include <Switch/Property.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @interface IWin32Window
        /// @brief Provides an interface to expose Win32 HWND handles.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks This interface is implemented on objects that expose Win32 HWND handles. The resultant handle can be used with Win32 API calls.
        class system_windows_forms_export_ IWin32Window interface_ {
        public:
          /// @brief Gets the handle to the window represented by the implementer.
          property_<intptr, readonly_> Handle {
            get_ {return this->GetHandle();}
          };

        protected:
          virtual intptr GetHandle() = 0;
        };
      }
    }
  }
}
