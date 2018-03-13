/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the border style for a control.
        /// @remarks Use the members of this enumeration to set the border style for controls that have a changeable border.
        enum class BorderStyle {
          /// @brief No border.
          None = 0,
          /// @brief A single-line border.
          FixedSingle = 1,
          /// @brief A three-dimensional border.
          Fixed3D = 2,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::BorderStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::BorderStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::BorderStyle::None] = "None";
    values[System::Windows::Forms::BorderStyle::FixedSingle] = "FixedSingle";
    values[System::Windows::Forms::BorderStyle::Fixed3D] = "Fixed3D";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
