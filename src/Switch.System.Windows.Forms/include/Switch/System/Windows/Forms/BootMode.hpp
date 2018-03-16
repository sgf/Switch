/// @file
/// @brief Contains Switch::System::Windows::Forms::MouseButtons enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies the mode to start the computer in.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks This enumeration defines identifiers that represent the standard operating system startup modes.
        /// @remarks This enumeration is used by the BootMode property of the SystemInformation class.
        /// @remarks The Normal boot mode is the standard system startup mode. The FailSafe boot mode is also called safe mode. The FailSafeWithNetwork boot mode is also called safe mode with networking.
        enum class BootMode {
          /// @brief Starts the computer in standard mode.
          Normal = 0,
          /// @brief Starts the computer by using only the basic files and drivers.
          FailSafe = 1,
          /// @brief Starts the computer by using the basic files, drivers and the services and drivers necessary to start networking.
          FailSafeWithNetwork = 2,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::BootMode> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::BootMode, string>& values, bool& flags) {
    values[System::Windows::Forms::BootMode::Normal] = "Normal";
    values[System::Windows::Forms::BootMode::FailSafe] = "FailSafe";
    values[System::Windows::Forms::BootMode::FailSafeWithNetwork] = "FailSafeWithNetwork";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
