/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
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
        /// @brief Controls where the tabs will be located in a Tab Control.
        /// @par Library
        /// Switch.System.Windows.Forms
        enum class TabAlignment {
          /// @biref Tabs will be located across the top of the control.
          Top = 0,
          /// @brief Tabs will be located across the bottom of the control.
          Bottom = 1,
          /// @brief Tabs will be located along the left edge of the control.
          Left = 2,
          /// @brief Tabs will be located along the right edge of the control.
          Right = 3,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::TabAlignment> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::TabAlignment, string>& values, bool& flags) {
    values[System::Windows::Forms::TabAlignment::Top] = "Top";
    values[System::Windows::Forms::TabAlignment::Bottom] = "Bottom";
    values[System::Windows::Forms::TabAlignment::Left] = "Left";
    values[System::Windows::Forms::TabAlignment::Right] = "Right";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
