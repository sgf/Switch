/// @file
/// @brief Contains Switch::System::Drawing::FontStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief
      /// @par Library
      /// Switch.System.Drawing
      enum class StringAlignment {
        Near,
        Center,
        Far
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Drawing::StringAlignment> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::StringAlignment, string>& values, bool& flags) {
    values[System::Drawing::StringAlignment::Near] = "Near";
    values[System::Drawing::StringAlignment::Center] = "Center";
    values[System::Drawing::StringAlignment::Far] = "Far";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
