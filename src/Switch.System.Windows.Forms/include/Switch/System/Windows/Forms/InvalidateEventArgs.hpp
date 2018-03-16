/// @file
/// @brief Contains Switch::System::Windows::Forms::InvalidateEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/Rectangle.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Provides data for the Invalidated event.
        /// @par Library
        /// Switch.System.Windows.Forms
        class system_windows_forms_export_ InvalidateEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the InvalidateEventArgs class.
          /// @param invalidRect The Rectangle that contains the invalidated window area.
          explicit InvalidateEventArgs(const Switch::System::Drawing::Rectangle& invalidRect) : invalidRect(invalidRect) {}

          /// @brief Gets the Rectangle that contains the invalidated window area.
          /// @return The invalidated window area.
          const Switch::System::Drawing::Rectangle& InvalidRect() const { return this->invalidRect; }

        private:
          Switch::System::Drawing::Rectangle invalidRect;
        };
      }
    }
  }
}
