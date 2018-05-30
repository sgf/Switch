/// @file
/// @brief Contains Switch::System::Drawing::Drawing2D::PenAlignment enum.
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
        /// @brief Specifies the style of dashed lines drawn with a System::Drawing::Pen object.
        /// @par Library
        /// Switch.System.Drawing
        /// @remarks A Pen object has width. The center point of this pen width is aligned relative to the line being drawn depending on the alignment value. A Pen object can be positioned to draw inside of a line or centered over the line.
        enum class PenAlignment {
          /// @brief Specifies that the Pen object is centered over the theoretical line.
          Center = 0,
          /// @brief Specifies that the Pen is positioned on the inside of the theoretical line.
          Inset = 1,
          /// @brief Specifies the Pen is positioned on the outside of the theoretical line.
          Outset = 2,
          /// @brief Specifies the Pen is positioned to the left of the theoretical line.
          Left = 3,
          /// @brief Specifies the Pen is positioned to the right of the theoretical line.
          Right = 4,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Drawing::Drawing2D::PenAlignment> : public TrueType {};

template<>
struct EnumRegister<System::Drawing::Drawing2D::PenAlignment> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::Drawing2D::PenAlignment, string>& values, bool& flags) {
    values[System::Drawing::Drawing2D::PenAlignment::Center] = "Center";
    values[System::Drawing::Drawing2D::PenAlignment::Inset] = "Inset";
    values[System::Drawing::Drawing2D::PenAlignment::Outset] = "Outset";
    values[System::Drawing::Drawing2D::PenAlignment::Left] = "Left";
    values[System::Drawing::Drawing2D::PenAlignment::Right] = "Right";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
