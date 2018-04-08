/// @file
/// @brief Contains Switch::System::Drawing::ContentAlignment enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Specifies alignment of content on the drawing surface.
      /// @par Library
      /// Switch.System.Drawing
      /// @par Examples
      /// The following code example demonstrates how to use the Point.Point and Size constructors and the System.Drawing.ContentAlignment enumeration. To run this example paste this code into a Windows Form that contains a label named Label1 and call the IntializeLabel1 method in the form's constructor.
      /// @code
      /// void InitializeLabel1() {
      ///   // Set a border.
      ///   label1.BorderStyle = BorderStyle::FixedSingle;
      ///
      ///   // Set the size, constructing a size from two integers.
      ///   label1.Size = System::Drawing::Size(100, 50);
      ///
      ///   // Set the location, constructing a point from a 32-bit integer
      ///   // (using hexadecimal).
      ///   label1.Location = System::Drawing::Point(0x280028);
      ///
      ///   // Set and align the text on the lower-right side of the label.
      ///   label1.TextAlign = ContentAlignment::BottomRight;
      ///   label1.Text = "Bottom Right Alignment";
      /// }
      /// @endcode
      enum class ContentAlignment {
        /// @brief Content is vertically aligned at the top, and horizontally aligned on the left.
        TopLeft = 1,
        /// @brief Content is vertically aligned at the top, and horizontally aligned at the center.
        TopCenter = 2,
        /// @brief Content is vertically aligned at the top, and horizontally aligned on the right.
        TopRight = 4,
        /// @brief Content is vertically aligned in the middle, and horizontally aligned on the left.
        MiddleLeft = 16,
        /// @brief Content is vertically aligned in the middle, and horizontally aligned at the center.
        MiddleCenter = 32,
        /// @brief Content is vertically aligned in the middle, and horizontally aligned on the right.
        MiddleRight = 64,
        /// @brief Content is vertically aligned at the bottom, and horizontally aligned on the left.
        BottomLeft = 256,
        /// @brief Content is vertically aligned at the bottom, and horizontally aligned at the center.
        BottomCenter = 512,
        /// @brief Content is vertically aligned at the bottom, and horizontally aligned on the right.
        BottomRight = 1024
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Drawing::ContentAlignment> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::ContentAlignment, string>& values, bool& flags) {
    values[System::Drawing::ContentAlignment::TopLeft] = "TopLeft";
    values[System::Drawing::ContentAlignment::TopCenter] = "TopCenter";
    values[System::Drawing::ContentAlignment::TopRight] = "TopRight";
    values[System::Drawing::ContentAlignment::MiddleLeft] = "MiddleLeft";
    values[System::Drawing::ContentAlignment::MiddleCenter] = "MiddleCenter";
    values[System::Drawing::ContentAlignment::MiddleRight] = "MiddleRight";
    values[System::Drawing::ContentAlignment::BottomLeft] = "BottomLeft";
    values[System::Drawing::ContentAlignment::BottomCenter] = "BottomCenter";
    values[System::Drawing::ContentAlignment::BottomRight] = "BottomRight";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
