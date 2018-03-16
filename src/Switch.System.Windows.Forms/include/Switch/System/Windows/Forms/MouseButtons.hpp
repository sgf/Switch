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
        /// @par Library
        /// Switch.System.Windows.Forms
        enum class MouseButtons {
          None = 0,
          Left = 0x100000,
          Right = 0x200000,
          Middle = 0x400000,
          XButton1 = 0x800000,
          XButton2 = 0x1000000
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::MouseButtons> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::MouseButtons> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::MouseButtons, string>& values, bool& flags) {
    values[System::Windows::Forms::MouseButtons::None] = "None";
    values[System::Windows::Forms::MouseButtons::Left] = "Left";
    values[System::Windows::Forms::MouseButtons::Right] = "Right";
    values[System::Windows::Forms::MouseButtons::Middle] = "Middle";
    values[System::Windows::Forms::MouseButtons::XButton1] = "XButton1";
    values[System::Windows::Forms::MouseButtons::XButton2] = "XButton2";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
