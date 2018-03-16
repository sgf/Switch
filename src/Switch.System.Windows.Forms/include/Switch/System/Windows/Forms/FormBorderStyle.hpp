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
        /// @brief Specifies the border styles for a form.
        /// @par Library
        /// Switch.System.Windows.Forms
        enum class FormBorderStyle {
          /// @brief No border.
          None,
          /// @brief A fixed, single-line border.
          FixedSingle,
          /// @brief A fixed, three-dimensional border.
          Fixed3D,
          /// @brief A thick, fixed dialog-style border.
          FixedDialog = 3,
          /// @brief A resizable border.
          Sizable = 4,
          /// @brief A tool window border
          FixedToolWindow = 5,
          /// @brief A resizable tool window border.
          SizableToolWindow = 6,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::FormBorderStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::FormBorderStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::FormBorderStyle::None] = "None";
    values[System::Windows::Forms::FormBorderStyle::FixedSingle] = "FixedSingle";
    values[System::Windows::Forms::FormBorderStyle::Fixed3D] = "Fixed3D";
    values[System::Windows::Forms::FormBorderStyle::FixedDialog] = "FixedDialog";
    values[System::Windows::Forms::FormBorderStyle::Sizable] = "Sizable";
    values[System::Windows::Forms::FormBorderStyle::FixedToolWindow] = "FixedToolWindow";
    values[System::Windows::Forms::FormBorderStyle::Fixed3D] = "SizableToolWindow";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
