/// @file
/// @brief Contains Switch::System::Windows::Forms::DialogResult class.
#pragma once

#include <Switch/System/Enum.hpp>

#include "Control.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        enum class DialogResult {
          None = 0,
          OK = 1,
          Cancel = 2,
          Abort = 3,
          Retry = 4,
          Ignore = 5,
          Yes = 6,
          No = 7
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::DialogResult> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::DialogResult::None, "None"}, {(int64)System::Windows::Forms::DialogResult::OK, "OK"}, {(int64)System::Windows::Forms::DialogResult::Cancel, "Cancel"}, {(int64)System::Windows::Forms::DialogResult::Abort, "Abort"}, {(int64)System::Windows::Forms::DialogResult::Retry, "Retry"}, {(int64)System::Windows::Forms::DialogResult::Ignore, "Ignore"}, {(int64)System::Windows::Forms::DialogResult::Yes, "Yes"}, {(int64)System::Windows::Forms::DialogResult::No, "No"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;