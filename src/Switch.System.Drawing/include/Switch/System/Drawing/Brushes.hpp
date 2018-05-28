/// @file
/// @brief Contains Switch::System::Drawing::Brush class.
#pragma once

#include "SolidBrush.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Brushes for all the standard colors. This class cannot be inherited.
      /// @par Library
      /// Switch.System.Drawing
      /// @remarks The Brushes class contains static read-only properties that return a Brush object of the color indicated by the property name.
      /// @remarks You typically do not have to explicitly dispose of the brush returned by a property in this class, unless it is used to construct a new brush. For more information about the colors represented by the brushes in this class, see Colors by Name.
      /// @par Examples
      /// The following code example demonstrates the how to use a member of the Brushes class to fill a Rectangle. This example should be used with a Windows Form. Paste this code into a form and call this method when handling the form's Paint event, passing e as PaintEventArgs.
      /// @code
      /// InstanceRectangleIntersection(PaintEventArgs& e) {
      ///   Rectangle rectangle1(50, 50, 200, 100);
      ///   Rectangle rectangle2(70, 20, 100, 200);
      ///
      ///   e.Graphics().DrawRectangle(Pens.Black, rectangle1);
      ///   e.Graphics().DrawRectangle(Pens.Red, rectangle2);
      ///
      ///   if (rectangle1.IntersectsWith(rectangle2)) {
      ///     rectangle1.Intersect(rectangle2);
      ///     if (!rectangle1.IsEmpty) {
      ///       e.Graphics().FillRectangle(Brushes::Green, rectangle1);
      ///     }
      ///   }
      /// }
      /// @endcode
      class system_drawing_export_ Brushes static_ {
      public:
        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> AliceBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> AntiqueWhite;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Aqua;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Aquamarine;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Azure;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Beige;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Bisque;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Black;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> BlanchedAlmond;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Blue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> BlueViolet;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Brown;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> BurlyWood;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> CadetBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Chartreuse;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Chocolate;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Coral;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> CornflowerBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Cornsilk;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Crimson;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Cyan;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkCyan;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkGoldenrod;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkGray;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkKhaki;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkMagenta;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkOliveGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkOrange;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkOrchid;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkRed;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkSalmon;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkSeaGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkSlateBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkSlateGray;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkTurquoise;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DarkViolet;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DeepPink;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DeepSkyBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DimGray;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> DodgerBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Firebrick;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> FloralWhite;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> ForestGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Fuchsia;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Gainsboro;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> GhostWhite;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Gold;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Goldenrod;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Gray;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Green;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> GreenYellow;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Honeydew;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> HotPink;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> IndianRed;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Indigo;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Ivory;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Khaki;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Lavender;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LavenderBlush;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LawnGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LemonChiffon;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightCoral;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightCyan;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightGoldenrodYellow;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightGray;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightPink;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightSalmon;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightSeaGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightSkyBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightSlateGray;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightSteelBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LightYellow;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Lime;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> LimeGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Linen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Magenta;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Maroon;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MediumAquamarine;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MediumBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MediumOrchid;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MediumPurple;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MediumSeaGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MediumSlateBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MediumSpringGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MediumTurquoise;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MediumVioletRed;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MidnightBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MintCream;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> MistyRose;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Moccasin;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> NavajoWhite;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Navy;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> OldLace;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Olive;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> OliveDrab;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Orange;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> OrangeRed;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Orchid;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> PaleGoldenrod;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> PaleGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> PaleTurquoise;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> PaleVioletRed;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> PapayaWhip;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> PeachPuff;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Peru;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Pink;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Plum;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> PowderBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Purple;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Red;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> RosyBrown;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> RoyalBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> SaddleBrown;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Salmon;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> SandyBrown;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> SeaGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> SeaShell;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Sienna;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Silver;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> SkyBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> SlateBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> SlateGray;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Snow;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> SpringGreen;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> SteelBlue;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Tan;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Teal;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Thistle;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Tomato;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Transparent;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Turquoise;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Violet;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Wheat;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> White;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> WhiteSmoke;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> Yellow;

        /// @brief Gets a system-defined SolidBrush object.
        /// @return A SolidBrush object set to a system-defined color.
        /// @remarks To see the color represented by this brush and other brushes in this class, see Colors by Name.
        static property_<SolidBrush, readonly_> YellowGreen;
      };
    }
  }
}
