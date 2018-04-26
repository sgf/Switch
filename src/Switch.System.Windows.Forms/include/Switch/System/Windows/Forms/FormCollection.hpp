/// @file
/// @brief Contains Switch::System::Windows::Forms::Form class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "Form.hpp"
#include <Switch/System/Collections/Generic/List.hpp>
#include "DialogResult.hpp"
#include "FormBorderStyle.hpp"
#include "FormClosedEventHandler.hpp"
#include "FormClosingEventHandler.hpp"
#include "FormStartPosition.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a collection of Form objects.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks FormCollection is used by the Application object to list the currently open forms in an application through the OpenForms property.
        using FormCollection = System::Collections::Generic::List<ref<System::Windows::Forms::Form>>;
      }
    }
  }
}
