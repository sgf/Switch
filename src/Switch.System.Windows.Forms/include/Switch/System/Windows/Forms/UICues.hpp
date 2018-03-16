/// @file
/// @brief Contains Switch::System::Windows::Forms::UICues enum.
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
        /// @brief Specifies the state of the user interface.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks This enumeration is used by members such as the constructor for System::Windows::Forms::UICuesEventArgs.
        /// @remarks This enumeration is used to specify which user interface cues will be displayed or changed. For example, when the user presses the ALT key, the keyboard shortcuts on the menu are displayed by underlining the appropriate character. The bitwise combination of System::Windows::Forms::UICues for this example would be UICues::ShowKeyboard and UICues::ChangeKeyboard.
        enum class UICues {
          /// @brief No change was made.
          None = 0,
          /// @brief Focus rectangles are displayed after the change.
          ShowFocus = 1,
          /// @brief Keyboard cues are underlined after the change.
          ShowKeyboard = 2,
          /// @brief Focus rectangles are displayed and keyboard cues are underlined after the change.
          Shown = 3,
          /// @brief The state of the focus cues has changed.
          ChangeFocus = 4,
          /// @brief The state of the keyboard cues has changed.
          ChangeKeyboard = 8,
          /// @brief The state of the focus cues and keyboard cues has changed.
          Changed = 12
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::UICues> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::UICues> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::UICues, string>& values, bool& flags) {
    values[System::Windows::Forms::UICues::None] = "None";
    values[System::Windows::Forms::UICues::ShowFocus] = "ShowFocus";
    values[System::Windows::Forms::UICues::ShowKeyboard] = "ShowKeyboard";
    values[System::Windows::Forms::UICues::Shown] = "Shown";
    values[System::Windows::Forms::UICues::ChangeFocus] = "ChangeFocus";
    values[System::Windows::Forms::UICues::ChangeKeyboard] = "ChangeKeyboard";
    values[System::Windows::Forms::UICues::Changed] = "Changed";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
