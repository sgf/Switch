/// @file
/// @brief Contains Switch::System::Windows::Forms::HelpEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Provides data for the HelpRequested event.
        /// @par Library
        /// Switch.System.Windows.Forms
        class system_windows_forms_export_ HelpEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the HelpEventArgs class.
          HelpEventArgs() : handled(false) {}
          /// @brief Initializes a new instance of the HelpEventArgs class.
          /// @param mousePos The coordinates of the mouse pointer.
          HelpEventArgs(const Switch::System::Drawing::Point& mousePos) : handled(false), mousePos(mousePos) {}

          /// @brief Gets a value indicating whether the help event was handled.
          /// @return true if the event is handled; otherwise, false. The default is false.
          bool Handled() const { return this->handled; }

          /// @brief Gets the screen coordinates of the mouse pointer.
          /// @return A Point representing the screen coordinates of the mouse pointer.
          const Switch::System::Drawing::Point& MousePos() const { return this->mousePos; }

          /// @brief Sets a value indicating whether the help event was handled.
          /// @param handled true if the event is handled; otherwise, false. The default is false.
          void Handled(bool handled) {
            this->handled = handled;
          }

        private:
          bool handled;
          Switch::System::Drawing::Point mousePos;
        };
      }
    }
  }
}
