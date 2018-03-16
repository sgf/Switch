/// @file
/// @brief Contains Switch::System::Windows::Forms::KeyPressEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "Keys.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        /// @par Library
        /// Switch.System.Windows.Forms
        class system_windows_forms_export_ KeyPressEventArgs : public EventArgs {
        public:
          KeyPressEventArgs() = default;
          explicit KeyPressEventArgs(char32 keyChar) : keyChar(keyChar), handled(false) {}

          /// @cond
          KeyPressEventArgs(const KeyPressEventArgs& keyPressEventArgs): keyChar(keyPressEventArgs.keyChar), handled(keyPressEventArgs.handled) {}
          KeyPressEventArgs& operator =(const KeyPressEventArgs&) = default;
          /// @endcond

          property_<bool> Handled {
            get_ {return this->handled;},
            set_ {this->handled = value;}
          };

          property_<char32, readonly_> KeyChar {
            get_ {return this->keyChar;}
          };

        private:
          char32 keyChar = 0;
          bool handled = false;
        };
      }
    }
  }
}
