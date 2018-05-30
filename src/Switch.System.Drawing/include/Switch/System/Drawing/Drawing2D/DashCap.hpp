/// @file
/// @brief Contains Switch::System::Drawing::Drawing2D::Triangle enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System.Drawing::Drawing2D namespace provides advanced two-dimensional and vector graphics functionality.
      namespace Drawing2D {
        /// @brief Specifies the type of graphic shape to use on both ends of each dash in a dashed line.
        /// @par Library
        /// Switch.System.Drawing
        enum class DashCap {
          /// @brief Specifies a square cap that squares off both ends of each dash.
          Flat = 0,
          /// @brief Specifies a circular cap that rounds off both ends of each dash.
          Round = 2,
          /// @brief Specifies a triangular cap that points both ends of each dash.
          Triangle = 3,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Drawing::Drawing2D::DashCap> : public TrueType {};

template<>
struct EnumRegister<System::Drawing::Drawing2D::DashCap> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::Drawing2D::DashCap, string>& values, bool& flags) {
    values[System::Drawing::Drawing2D::DashCap::Flat] = "Flat";
    values[System::Drawing::Drawing2D::DashCap::Round] = "Round";
    values[System::Drawing::Drawing2D::DashCap::Triangle] = "Triangle";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
