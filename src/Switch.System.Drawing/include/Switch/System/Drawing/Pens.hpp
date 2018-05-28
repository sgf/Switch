/// @file
/// @brief Contains Switch::System::Drawing::Pen class.
#pragma once

#include "Pen.hpp"

/// @cond
namespace Native {
  class GdiApi;
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Pens for all the standard colors. This class cannot be inherited.
      /// @par Library
      /// Switch.System.Drawing
      /// @remarks The Pen objects returned by this class are immutable, meaning their properties cannot be changed. To see the colors represented by pens in this class, see Colors by Name.
      /// @par Examples
      /// The following method demonstrates how to use the Pens class. This example is designed to be used with Windows Forms. Paste the code into a form and call the UsePensClass method when handling the form's Paint event, passing e as PaintEventArgs.
      /// @code
      /// void UsePensClass(PaintEventArgs& e) {
      ///   e.Graphics().DrawEllipse(Pens::SlateBlue, Rectangle(40, 40, 140, 140));
      /// }
      /// @endcode
      class system_drawing_export_ Pens static_ {
      public:
        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> AliceBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> AntiqueWhite;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Aqua;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Aquamarine;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Azure;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Beige;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Bisque;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Black;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> BlanchedAlmond;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Blue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> BlueViolet;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Brown;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> BurlyWood;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> CadetBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Chartreuse;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Chocolate;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Coral;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> CornflowerBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Cornsilk;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Crimson;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Cyan;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkCyan;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkGoldenrod;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkGray;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkKhaki;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkMagenta;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkOliveGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkOrange;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkOrchid;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkRed;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkSalmon;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkSeaGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkSlateBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkSlateGray;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkTurquoise;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DarkViolet;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DeepPink;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DeepSkyBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DimGray;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> DodgerBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Firebrick;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> FloralWhite;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> ForestGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Fuchsia;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Gainsboro;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> GhostWhite;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Gold;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Goldenrod;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Gray;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Green;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> GreenYellow;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Honeydew;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> HotPink;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> IndianRed;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Indigo;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Ivory;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Khaki;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Lavender;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LavenderBlush;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LawnGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LemonChiffon;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightCoral;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightCyan;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightGoldenrodYellow;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightGray;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightPink;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightSalmon;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightSeaGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightSkyBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightSlateGray;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightSteelBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LightYellow;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Lime;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> LimeGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Linen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Magenta;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Maroon;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MediumAquamarine;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MediumBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MediumOrchid;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MediumPurple;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MediumSeaGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MediumSlateBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MediumSpringGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MediumTurquoise;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MediumVioletRed;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MidnightBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MintCream;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> MistyRose;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Moccasin;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> NavajoWhite;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Navy;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> OldLace;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Olive;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> OliveDrab;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Orange;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> OrangeRed;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Orchid;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> PaleGoldenrod;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> PaleGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> PaleTurquoise;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> PaleVioletRed;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> PapayaWhip;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> PeachPuff;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Peru;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Pink;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Plum;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> PowderBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Purple;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Red;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> RosyBrown;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> RoyalBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> SaddleBrown;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Salmon;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> SandyBrown;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> SeaGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> SeaShell;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Sienna;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Silver;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> SkyBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> SlateBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> SlateGray;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Snow;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> SpringGreen;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> SteelBlue;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Tan;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Teal;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Thistle;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Tomato;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Transparent;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Turquoise;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Violet;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Wheat;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> White;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> WhiteSmoke;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> Yellow;

        /// @brief A system-defined Pen object with a width of 1.
        /// @return A Pen object set to a system-defined color.
        /// @remarks To see the color represented by this pen and other pens in this class, see Colors by Name.
        static property_<Pen, readonly_> YellowGreen;
      };
    }
  }
}
