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
        /// @brief Specifies the direction the system uses to arrange minimized windows.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
        /// @remarks This enumeration is used by the ArrangeDirection property of the SystemInformation class.
        enum class ArrangeDirection {
          /// @brief Arranges vertically, from top to bottom.
          Down = 0x0004,
          /// @brief Arranges horizontally, from left to right.
          Left = 0x0000,
          /// @brief Arranges horizontally, from right to left.
          Right = 0x0000,
          /// @brief Arranges vertically, from bottom to top.
          Up = 0x0004,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::ArrangeDirection> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::ArrangeDirection> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::ArrangeDirection, string>& values, bool& flags) {
    // values[System::Windows::Forms::ArrangeDirection::Down] = "Down";
    values[System::Windows::Forms::ArrangeDirection::Left] = "Left";
    // values[System::Windows::Forms::ArrangeDirection::Right] = "Right";
    values[System::Windows::Forms::ArrangeDirection::Up] = "Up";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
