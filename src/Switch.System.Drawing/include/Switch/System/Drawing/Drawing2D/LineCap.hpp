/// @file
/// @brief Contains Switch::System::Drawing::Drawin2D::LineCap enum.
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
        /// @brief Specifies the available cap styles with which a Pen object can end a line.
        /// @par Library
        /// Switch.System.Drawing
        /// @remarks You can draw the start or end of a line in one of several shapes called line caps. GDI+ supports several line caps, such as round, square, diamond, and arrowhead. The following illustration shows a line with a round cap and an arrow cap.
        /// @image LineCap.gif
        /// @par Examples
        /// The following example draws a line with an arrowhead at one end and a round cap at the other end. To run this example, Create a Windows Form and handle the form's Paint event. Paste the example code into the Paint event handler passing e as PaintEventArgs.
        /// @code
        /// Pen pen(Color::FromArgb(255, 0, 0, 255), 8);
        /// pen.StartCap = LineCap::ArrowAnchor;
        /// pen.EndCap = LineCap::RoundAnchor;
        /// e.Graphics().DrawLine(pen, 20, 175, 300, 175);
        /// @endcode
        enum class LineCap {
          /// @brief Specifies a flat line cap.
          Flat = 0,
          /// @brief Specifies a square line cap.
          Square = 1,
          /// @brief Specifies a round line cap.
          Round  = 2,
          /// @brief Specifies a triangular line cap.
          Triangle  = 3,
          /// @brief Specifies no anchor.
          NoAnchor = 0x10,
          /// @brief Specifies a square anchor line cap.
          SquareAnchor = 0x11,
          /// @brief Specifies a round anchor cap.
          RoundAnchor = 0x12,
          /// @brief Specifies a diamond anchor cap.
          DiamondAnchor = 0x13,
          /// @brief Specifies an arrow-shaped anchor cap.
          ArrowAnchor = 0x14,
          /// @brief Specifies a custom line cap.
          Custom = 0xFF,
          /// @brief Specifies a mask used to check whether a line cap is an anchor cap.
          AnchorMask = 0xF0
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Drawing::Drawing2D::LineCap> : public TrueType {};

template<>
struct EnumRegister<System::Drawing::Drawing2D::LineCap> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::Drawing2D::LineCap, string>& values, bool& flags) {
    values[System::Drawing::Drawing2D::LineCap::Flat] = "Flat";
    values[System::Drawing::Drawing2D::LineCap::Square] = "Square";
    values[System::Drawing::Drawing2D::LineCap::Round] = "Round";
    values[System::Drawing::Drawing2D::LineCap::Triangle] = "Triangle";
    values[System::Drawing::Drawing2D::LineCap::NoAnchor] = "NoAnchor";
    values[System::Drawing::Drawing2D::LineCap::SquareAnchor] = "SquareAnchor";
    values[System::Drawing::Drawing2D::LineCap::RoundAnchor] = "RoundAnchor";
    values[System::Drawing::Drawing2D::LineCap::DiamondAnchor] = "DiamondAnchor";
    values[System::Drawing::Drawing2D::LineCap::ArrowAnchor] = "ArrowAnchor";
    values[System::Drawing::Drawing2D::LineCap::Custom] = "Custom";
    values[System::Drawing::Drawing2D::LineCap::AnchorMask] = "AnchorMask";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
