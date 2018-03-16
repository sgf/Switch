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
        /// @brief Specifies the location of tick marks in a TrackBar control.
        /// @par Library
        /// Switch.System.Windows.Forms
        enum class TickStyle {
          /// @brief No tick marks appear in the control.
          None = 0,
          /// @brief Tick marks are located on the top of horizontal control or on the left of a vertical control.
          TopLeft = 1,
          /// @brief Tick marks are located on the bottom of a horizontal control or on the right side of a vertical control.
          BottomRight = 2,
          /// @brief Tick marks are located on both sides of the control.
          Both = 3,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::TickStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::TickStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::TickStyle::None] = "None";
    values[System::Windows::Forms::TickStyle::TopLeft] = "TopLeft";
    values[System::Windows::Forms::TickStyle::BottomRight] = "BottomRight";
    values[System::Windows::Forms::TickStyle::Both] = "Both";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
