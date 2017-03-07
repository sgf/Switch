/// @file
/// @brief Contains Pcf::System::Windows::Forms::MessageBoxButtons enum.
#pragma once

#include <Pcf/System/Enum.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies options on a MessageBox.
        /// This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
        /// @remarks This enumeration is used by the MessageBox class.
        /// @remarks If you do not want to specify this parameter when calling methods on MessageBox, you can pass in 0 instead.
        enum class MessageBoxOptions {
          /// @brief The message box is displayed on the active desktop.
          DefaultDesktopOnly = 131072,
          /// @brief The message box text is right-aligned.
          RightAlign = 524288,
          /// @brief Specifies that the message box text is displayed with right to left reading order.
          RtlReading = 1048576,
          /// @brief The message box is displayed on the active desktop.
          ServiceNotification = 2097152
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::MessageBoxOptions> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::MessageBoxOptions::DefaultDesktopOnly, "DefaultDesktopOnly"}, {(int64)System::Windows::Forms::MessageBoxOptions::RightAlign, "RightAlign"}, {(int64)System::Windows::Forms::MessageBoxOptions::RtlReading, "RtlReading"}, {(int64)System::Windows::Forms::MessageBoxOptions::ServiceNotification, "ServiceNotification"}};
    flags = true;
  }
};
/// @endcond

using namespace Pcf;
