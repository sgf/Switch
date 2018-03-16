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
        /// @brief Specifies the orientation of controls or elements of controls.
        /// @par Library
        /// Switch.System.Windows.Forms
        enum class Orientation {
          /// @brief The control or element is oriented horizontally.
          Horizontal = 0,
          /// @brief The control or element is oriented vertically.
          Vertical = 1,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::Orientation> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::Orientation, string>& values, bool& flags) {
    values[System::Windows::Forms::Orientation::Horizontal] = "Horizontal";
    values[System::Windows::Forms::Orientation::Vertical] = "Vertical";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
