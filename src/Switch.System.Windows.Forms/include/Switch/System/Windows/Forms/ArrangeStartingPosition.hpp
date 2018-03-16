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
        /// @brief Specifies the starting position that the system uses to arrange minimized windows.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
        /// @remarks This enumeration is used by the ArrangeStartingPosition property of the SystemInformation class.
        enum class ArrangeStartingPosition {
          /// @brief Starts at the lower-left corner of the screen, which is the default position.
          BottomLeft = 0,
          /// @brief Starts at the lower-right corner of the screen.
          BottomRight = 1,
          /// @brief Starts at the upper-left corner of the screen.
          TopLeft = 2,
          /// @brief Starts at the upper-right corner of the screen.
          TopRight = 3,
          /// @brief Hides minimized windows by moving them off the visible area of the screen.
          Hide = 8
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::ArrangeStartingPosition> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::ArrangeStartingPosition> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::ArrangeStartingPosition, string>& values, bool& flags) {
    values[System::Windows::Forms::ArrangeStartingPosition::BottomLeft] = "BottomLeft";
    values[System::Windows::Forms::ArrangeStartingPosition::BottomRight] = "BottomRight";
    values[System::Windows::Forms::ArrangeStartingPosition::TopLeft] = "TopLeft";
    values[System::Windows::Forms::ArrangeStartingPosition::TopRight] = "TopRight";
    values[System::Windows::Forms::ArrangeStartingPosition::Hide] = "Hide";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
