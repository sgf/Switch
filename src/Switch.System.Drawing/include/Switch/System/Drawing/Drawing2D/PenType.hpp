/// @file
/// @brief Contains Switch::System::Drawing::Drawin2D::PenType enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Specifies the alignment of a Pen object in relation to the theoretical, zero-width line.
      namespace Drawing2D {
        /// @brief Specifies the type of fill a Pen object uses to fill lines.
        /// @par Library
        /// Switch.System.Drawing
        /// @remarks The pen type is determined by the Brush property of the Pen object.
        enum class PenType {
          /// @brief Specifies a solid fill.
          SolidColor = 0,
          /// @brief Specifies a hatch fill.
          HatchFill = 1,
          /// @brief Specifies a bitmap texture fill.
          TextureFill = 2,
          /// @brief Specifies a path gradient fill.
          PathGradient = 3,
          /// @brief Specifies a linear gradient fill.
          LinearGradient = 4
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Drawing::Drawing2D::PenType> : public TrueType {};

template<>
struct EnumRegister<System::Drawing::Drawing2D::PenType> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::Drawing2D::PenType, string>& values, bool& flags) {
    values[System::Drawing::Drawing2D::PenType::SolidColor] = "SolidColor";
    values[System::Drawing::Drawing2D::PenType::HatchFill] = "HatchFill";
    values[System::Drawing::Drawing2D::PenType::TextureFill] = "TextureFill";
    values[System::Drawing::Drawing2D::PenType::PathGradient] = "PathGradient";
    values[System::Drawing::Drawing2D::PenType::LinearGradient] = "LinearGradient";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
