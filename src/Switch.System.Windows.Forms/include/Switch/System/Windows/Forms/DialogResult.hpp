/// @file
/// @brief Contains Switch::System::Windows::Forms::DialogResult class.
#pragma once

#include <Switch/System/Enum.hpp>

#include "Control.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies identifiers to indicate the return value of a dialog box.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The Button.DialogResult property and the Form.ShowDialog method use this enumeration.
        /// @par Examples
        /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
        /// @code
        /// void validateUserEntry5() {
        ///   // Checks the value of the text.
        ///   if (serverName.Text().Length == 0) {
        ///     // Initializes the variables to pass to the MessageBox.Show method.
        ///     string message = "You did not enter a server name. Cancel this operation?";
        ///     string caption = "No Server Name Specified";
        ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
        ///     DialogResult result;
        ///
        ///     // Displays the MessageBox.
        ///     result = MessageBox::Show(*this, message, caption, buttons);
        ///     if (result == DialogResult::Yes) {
        ///       // Closes the parent form.
        ///       this->Close();
        ///     }
        ///   }
        /// }
        /// @endcode
        enum class DialogResult {
          /// @brief Nothing is returned from the dialog box. This means that the modal dialog continues running.
          None = 0,
          /// @brief The dialog box return value is OK (usually sent from a button labeled OK).
          OK = 1,
          /// @brief The dialog box return value is Cancel (usually sent from a button labeled Cancel).
          Cancel = 2,
          /// @brief The dialog box return value is Abort (usually sent from a button labeled Abort).
          Abort = 3,
          /// @brief The dialog box return value is Retry (usually sent from a button labeled Retry).
          Retry = 4,
          /// @brief The dialog box return value is Ignore (usually sent from a button labeled Ignore).
          Ignore = 5,
          /// @brief The dialog box return value is Yes (usually sent from a button labeled Yes).
          Yes = 6,
          /// @brief The dialog box return value is No (usually sent from a button labeled No).
          No = 7
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::DialogResult> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::DialogResult, string>& values, bool& flags) {
    values[System::Windows::Forms::DialogResult::None] = "None";
    values[System::Windows::Forms::DialogResult::OK] = "OK";
    values[System::Windows::Forms::DialogResult::Cancel] = "Cancel";
    values[System::Windows::Forms::DialogResult::Abort] = "Abort";
    values[System::Windows::Forms::DialogResult::Retry] = "Retry";
    values[System::Windows::Forms::DialogResult::Ignore] = "Ignore";
    values[System::Windows::Forms::DialogResult::Yes] = "Yes";
    values[System::Windows::Forms::DialogResult::No] = "No";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
