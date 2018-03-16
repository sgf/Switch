/// @file
/// @brief Contains Switch::System::Windows::Forms::CloseReason enum.
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
        /// @brief Specifies the reason that a form was closed.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The FormClosing and FormClosed events are raised when a Form is closed, either through user action or programmatically. Handlers for these events receive parameters of type FormClosingEventArgs and FormClosedEventArgs, respectively. Both of these event argument classes use the CloseReason enumeration.
        enum class CloseReason {
          /// @brief The cause of the closure was not defined or could not be determined.
          None = 0,
          /// @brief The operating system is closing all applications before shutting down.
          WindowsShutDown = 1,
          /// @brief The parent form of this multiple document interface (MDI) form is closing.
          MdiFormClosing = 2,
          /// @brief The user is closing the form through the user interface (UI), for example by clicking the Close button on the form window, selecting Close from the window's control menu, or pressing ALT+F4.
          UserClosing = 3,
          /// @brief The Microsoft Windows Task Manager is closing the application.
          TaskManagerClosing = 4,
          /// @brief The owner form is closing.
          FormOwnerClosing = 5,
          /// @brief The Exit method of the Application class was invoked.
          ApplicationExitCall = 6
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::CloseReason> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::CloseReason, string>& values, bool& flags) {
    values[System::Windows::Forms::CloseReason::None] = "None";
    values[System::Windows::Forms::CloseReason::WindowsShutDown] = "WindowsShutDown";
    values[System::Windows::Forms::CloseReason::MdiFormClosing] = "MdiFormClosing";
    values[System::Windows::Forms::CloseReason::UserClosing] = "UserClosing";
    values[System::Windows::Forms::CloseReason::TaskManagerClosing] = "TaskManagerClosing";
    values[System::Windows::Forms::CloseReason::FormOwnerClosing] = "FormOwnerClosing";
    values[System::Windows::Forms::CloseReason::ApplicationExitCall] = "ApplicationExitCall";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
