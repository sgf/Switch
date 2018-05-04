/// @file
/// @brief Contains Switch::System::Drawing::Color class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/IComparable.hpp>
#include <Switch/System/Math.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include "../../SystemDrawingExport.hpp"
#include "KnownColor.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Represents an ARGB (alpha, red, green, blue) color.
      /// @par Library
      /// Switch.System.Drawing
      /// @remarks Named colors are represented by using the properties of the Color structure. For more information about these colors, see Colors by Name.
      /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). Each of the four components is a number from 0 through 255, with 0 representing no intensity and 255 representing full intensity. The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. To determine the alpha, red, green, or blue component of a color, use the A, R, G, or B property, respectively. You can create a custom color by using one of the FromArgb methods
      /// @par Examples
      /// The following code example demonstrates the A, R, G, and B properties of a Color, and the Implicit(Size to SizeF) member.<br><br>
      /// This example is designed to be used with a Windows Form. Paste the code into the form and call the ShowPropertiesOfSlateBlue method from the form's Paint event-handling method, passing e as PaintEventArgs.
      /// @code
      /// void ShowPropertiesOfSlateBlue(PaintEventArgs& e) {
      ///   Color slateBlue = Color::FromName("SlateBlue");
      ///   byte g = slateBlue.G;
      ///   byte b = slateBlue.B;
      ///   byte r = slateBlue.R;
      ///   byte a = slateBlue.A;
      ///   string text = String::Format("Slate Blue has these ARGB values: Alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
      ///   e.Graphics().DrawString(text, Font(this->Font, FontStyle::Italic), SolidBrush(slateBlue), RectangleF(PointF(0.0F, 0.0F), this->Size));
      /// }
      /// @endcode
      struct system_drawing_export_ Color : public object, public IComparable {
      public:
        /// @brief Represents a color that is null.
        static property_<Color, readonly_> Empty;

        /// @brief Gets a system-defined color that has an ARGB value of 0x00FFFFFF. This field is constant.
        static property_<Color, readonly_> Transparent;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0F8FF. This field is constant.
        static property_<Color, readonly_> AliceBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAEBD7. This field is constant.
        static property_<Color, readonly_> AntiqueWhite;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FFFF. This field is constant.
        static property_<Color, readonly_> Aqua;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7FFFD4. This field is constant.
        static property_<Color, readonly_> Aquamarine;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0FFFF. This field is constant.
        static property_<Color, readonly_> Azure;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5F5DC. This field is constant.
        static property_<Color, readonly_> Beige;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4C4. This field is constant.
        static property_<Color, readonly_> Bisque;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static property_<Color, readonly_> Black;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFEBCD. This field is constant.
        static property_<Color, readonly_> BlanchedAlmond;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF0000FF. This field is constant.
        static property_<Color, readonly_> Blue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8A2BE2. This field is constant.
        static property_<Color, readonly_> BlueViolet;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFA52A2A. This field is constant.
        static property_<Color, readonly_> Brown;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDEB887. This field is constant.
        static property_<Color, readonly_> BurlyWood;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF5F9EA0. This field is constant.
        static property_<Color, readonly_> CadetBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7FFF00. This field is constant.
        static property_<Color, readonly_> Chartreuse;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD2691E. This field is constant.
        static property_<Color, readonly_> Chocolate;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF7F50. This field is constant.
        static property_<Color, readonly_> Coral;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF6495ED. This field is constant.
        static property_<Color, readonly_> CornflowerBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF8DC. This field is constant.
        static property_<Color, readonly_> Cornsilk;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDC143C. This field is constant.
        static property_<Color, readonly_> Crimson;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FFFF. This field is constant.
        static property_<Color, readonly_> Cyan;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00008B. This field is constant.
        static property_<Color, readonly_> DarkBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF008B8B. This field is constant.
        static property_<Color, readonly_> DarkCyan;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFB8860B. This field is constant.
        static property_<Color, readonly_> DarkGoldenrod;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFA9A9A9. This field is constant.
        static property_<Color, readonly_> DarkGray;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF006400. This field is constant.
        static property_<Color, readonly_> DarkGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFBDB76B. This field is constant.
        static property_<Color, readonly_> DarkKhaki;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B008B. This field is constant.
        static property_<Color, readonly_> DarkMagenta;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF556B2F. This field is constant.
        static property_<Color, readonly_> DarkOliveGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF8C00. This field is constant.
        static property_<Color, readonly_> DarkOrange;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9932CC. This field is constant.
        static property_<Color, readonly_> DarkOrchid;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B0000. This field is constant.
        static property_<Color, readonly_> DarkRed;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFE9967A. This field is constant.
        static property_<Color, readonly_> DarkSalmon;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8FBC8B. This field is constant.
        static property_<Color, readonly_> DarkSeaGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF483D8B. This field is constant.
        static property_<Color, readonly_> DarkSlateBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF2F4F4F. This field is constant.
        static property_<Color, readonly_> DarkSlateGray;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00CED1. This field is constant.
        static property_<Color, readonly_> DarkTurquoise;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9400D3. This field is constant.
        static property_<Color, readonly_> DarkViolet;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF1493. This field is constant.
        static property_<Color, readonly_> DeepPink;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00BFFF. This field is constant.
        static property_<Color, readonly_> DeepSkyBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF696969. This field is constant.
        static property_<Color, readonly_> DimGray;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF1E90FF. This field is constant.
        static property_<Color, readonly_> DodgerBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFB22222. This field is constant.
        static property_<Color, readonly_> Firebrick;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFAF0. This field is constant.
        static property_<Color, readonly_> FloralWhite;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF228B22. This field is constant.
        static property_<Color, readonly_> ForestGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF00FF. This field is constant.
        static property_<Color, readonly_> Fuchsia;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDCDCDC. This field is constant.
        static property_<Color, readonly_> Gainsboro;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF8F8FF. This field is constant.
        static property_<Color, readonly_> GhostWhite;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFD700. This field is constant.
        static property_<Color, readonly_> Gold;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDAA520. This field is constant.
        static property_<Color, readonly_> Goldenrod;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF808080. This field is constant.
        static property_<Color, readonly_> Gray;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF008000. This field is constant.
        static property_<Color, readonly_> Green;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFADFF2F. This field is constant.
        static property_<Color, readonly_> GreenYellow;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0FFF0. This field is constant.
        static property_<Color, readonly_> Honeydew;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF69B4. This field is constant.
        static property_<Color, readonly_> HotPink;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFCD5C5C. This field is constant.
        static property_<Color, readonly_> IndianRed;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF4B0082. This field is constant.
        static property_<Color, readonly_> Indigo;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFF0. This field is constant.
        static property_<Color, readonly_> Ivory;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0E68C. This field is constant.
        static property_<Color, readonly_> Khaki;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFE6E6FA. This field is constant.
        static property_<Color, readonly_> Lavender;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF0F5. This field is constant.
        static property_<Color, readonly_> LavenderBlush;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7CFC00. This field is constant.
        static property_<Color, readonly_> LawnGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFACD. This field is constant.
        static property_<Color, readonly_> LemonChiffon;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFADD8E6. This field is constant.
        static property_<Color, readonly_> LightBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF08080. This field is constant.
        static property_<Color, readonly_> LightCoral;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFE0FFFF. This field is constant.
        static property_<Color, readonly_> LightCyan;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAFAD2. This field is constant.
        static property_<Color, readonly_> LightGoldenrodYellow;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD3D3D3. This field is constant.
        static property_<Color, readonly_> LightGray;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF90EE90. This field is constant.
        static property_<Color, readonly_> LightGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFB6C1. This field is constant.
        static property_<Color, readonly_> LightPink;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFA07A. This field is constant.
        static property_<Color, readonly_> LightSalmon;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF20B2AA. This field is constant.
        static property_<Color, readonly_> LightSeaGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF87CEFA. This field is constant.
        static property_<Color, readonly_> LightSkyBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF778899. This field is constant.
        static property_<Color, readonly_> LightSlateGray;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFB0C4DE. This field is constant.
        static property_<Color, readonly_> LightSteelBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFE0. This field is constant.
        static property_<Color, readonly_> LightYellow;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FF00. This field is constant.
        static property_<Color, readonly_> Lime;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF32CD32. This field is constant.
        static property_<Color, readonly_> LimeGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAF0E6. This field is constant.
        static property_<Color, readonly_> Linen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF00FF. This field is constant.
        static property_<Color, readonly_> Magenta;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF800000. This field is constant.
        static property_<Color, readonly_> Maroon;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF66CDAA. This field is constant.
        static property_<Color, readonly_> MediumAquamarine;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF0000CD. This field is constant.
        static property_<Color, readonly_> MediumBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFBA55D3. This field is constant.
        static property_<Color, readonly_> MediumOrchid;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9370DB. This field is constant.
        static property_<Color, readonly_> MediumPurple;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF3CB371. This field is constant.
        static property_<Color, readonly_> MediumSeaGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7B68EE. This field is constant.
        static property_<Color, readonly_> MediumSlateBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FA9A. This field is constant.
        static property_<Color, readonly_> MediumSpringGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF48D1CC. This field is constant.
        static property_<Color, readonly_> MediumTurquoise;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFC71585. This field is constant.
        static property_<Color, readonly_> MediumVioletRed;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF191970. This field is constant.
        static property_<Color, readonly_> MidnightBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5FFFA. This field is constant.
        static property_<Color, readonly_> MintCream;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4E1. This field is constant.
        static property_<Color, readonly_> MistyRose;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4B5. This field is constant.
        static property_<Color, readonly_> Moccasin;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFDEAD. This field is constant.
        static property_<Color, readonly_> NavajoWhite;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000080. This field is constant.
        static property_<Color, readonly_> Navy;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFDF5E6. This field is constant.
        static property_<Color, readonly_> OldLace;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF808000. This field is constant.
        static property_<Color, readonly_> Olive;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF6B8E23. This field is constant.
        static property_<Color, readonly_> OliveDrab;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFA500. This field is constant.
        static property_<Color, readonly_> Orange;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF4500. This field is constant.
        static property_<Color, readonly_> OrangeRed;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDA70D6. This field is constant.
        static property_<Color, readonly_> Orchid;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFEEE8AA. This field is constant.
        static property_<Color, readonly_> PaleGoldenrod;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF98FB98. This field is constant.
        static property_<Color, readonly_> PaleGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFAFEEEE. This field is constant.
        static property_<Color, readonly_> PaleTurquoise;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDB7093. This field is constant.
        static property_<Color, readonly_> PaleVioletRed;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFEFD5. This field is constant.
        static property_<Color, readonly_> PapayaWhip;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFDAB9. This field is constant.
        static property_<Color, readonly_> PeachPuff;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFCD853F. This field is constant.
        static property_<Color, readonly_> Peru;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFC0CB. This field is constant.
        static property_<Color, readonly_> Pink;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDDA0DD. This field is constant.
        static property_<Color, readonly_> Plum;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFB0E0E6. This field is constant.
        static property_<Color, readonly_> PowderBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF800080. This field is constant.
        static property_<Color, readonly_> Purple;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF0000. This field is constant.
        static property_<Color, readonly_> Red;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFBC8F8F. This field is constant.
        static property_<Color, readonly_> RosyBrown;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF4169E1. This field is constant.
        static property_<Color, readonly_> RoyalBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B4513. This field is constant.
        static property_<Color, readonly_> SaddleBrown;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFA8072. This field is constant.
        static property_<Color, readonly_> Salmon;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF4A460. This field is constant.
        static property_<Color, readonly_> SandyBrown;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF2E8B57. This field is constant.
        static property_<Color, readonly_> SeaGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF5EE. This field is constant.
        static property_<Color, readonly_> SeaShell;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFA0522D. This field is constant.
        static property_<Color, readonly_> Sienna;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFC0C0C0. This field is constant.
        static property_<Color, readonly_> Silver;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF87CEEB. This field is constant.
        static property_<Color, readonly_> SkyBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF6A5ACD. This field is constant.
        static property_<Color, readonly_> SlateBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF708090. This field is constant.
        static property_<Color, readonly_> SlateGray;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFAFA. This field is constant.
        static property_<Color, readonly_> Snow;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FF7F. This field is constant.
        static property_<Color, readonly_> SpringGreen;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF4682B4. This field is constant.
        static property_<Color, readonly_> SteelBlue;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD2B48C. This field is constant.
        static property_<Color, readonly_> Tan;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF008080. This field is constant.
        static property_<Color, readonly_> Teal;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD8BFD8. This field is constant.
        static property_<Color, readonly_> Thistle;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF6347. This field is constant.
        static property_<Color, readonly_> Tomato;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF40E0D0. This field is constant.
        static property_<Color, readonly_> Turquoise;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFEE82EE. This field is constant.
        static property_<Color, readonly_> Violet;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5DEB3. This field is constant.
        static property_<Color, readonly_> Wheat;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static property_<Color, readonly_> White;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5F5F5. This field is constant.
        static property_<Color, readonly_> WhiteSmoke;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFF00. This field is constant.
        static property_<Color, readonly_> Yellow;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9ACD32. This field is constant.
        static property_<Color, readonly_> YellowGreen;

        /// @brief Create a new instance of class Color. The default value is Black.
        Color() = default;

        /// @cond
        Color(const Color& color) : argb(color.argb), knownColor(color.knownColor) {}
        Color& operator=(const Color& color) = default;
        /// @endcond

        /// @brief Gets the alpha component value of this Color class.
        /// @return byte The alpha component value of this Color.
        /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an A value of 255 represents an opaque color. An A value from 1 through 254 represents a semitransparent color. The color becomes more opaque as A approaches 255.
        /// @par Examples
        /// The following code example demonstrates the A, R, G, and B properties of a Color, and the Implicit(Size to SizeF) member.<br><br>
        /// This example is designed to be used with a Windows Form. Paste the code into the form and call the ShowPropertiesOfSlateBlue method from the form's Paint event-handling method, passing e as PaintEventArgs.
        /// @code
        /// void ShowPropertiesOfSlateBlue(PaintEventArgs& e) {
        ///   Color slateBlue = Color::FromName("SlateBlue");
        ///   byte g = slateBlue.G;
        ///   byte b = slateBlue.B;
        ///   byte r = slateBlue.R;
        ///   byte a = slateBlue.A;
        ///   string text = String::Format("Slate Blue has these ARGB values: Alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
        ///   e.Graphics().DrawString(text, Font(this->Font, FontStyle::Italic), SolidBrush(slateBlue), RectangleF(PointF(0.0F, 0.0F), this->Size));
        /// }
        /// @endcode
        property_<byte, readonly_> A {
          get_ {return byte((this->argb & 0xFF000000) >> 24);}
        };

        /// @brief Gets the blue component value of this Color class.
        /// @return byte The blue component value of this Color.
        /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an A value of 255 represents an opaque color. An A value from 1 through 254 represents a semitransparent color. The color becomes more opaque as A approaches 255.
        /// @par Examples
        /// The following code example demonstrates the A, R, G, and B properties of a Color, and the Implicit(Size to SizeF) member.<br><br>
        /// This example is designed to be used with a Windows Form. Paste the code into the form and call the ShowPropertiesOfSlateBlue method from the form's Paint event-handling method, passing e as PaintEventArgs.
        /// @code
        /// void ShowPropertiesOfSlateBlue(PaintEventArgs& e) {
        ///   Color slateBlue = Color::FromName("SlateBlue");
        ///   byte g = slateBlue.G;
        ///   byte b = slateBlue.B;
        ///   byte r = slateBlue.R;
        ///   byte a = slateBlue.A;
        ///   string text = String::Format("Slate Blue has these ARGB values: Alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
        ///   e.Graphics().DrawString(text, Font(this->Font, FontStyle::Italic), SolidBrush(slateBlue), RectangleF(PointF(0.0F, 0.0F), this->Size));
        /// }
        /// @endcode
        property_<byte, readonly_> B {
          get_ {return byte(this->argb & 0x000000FF);}
        };

        /// @brief Gets the green component value of this Color class.
        /// @return byte The green component value of this Color.
        /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an A value of 255 represents an opaque color. An A value from 1 through 254 represents a semitransparent color. The color becomes more opaque as A approaches 255.
        /// @par Examples
        /// The following code example demonstrates the A, R, G, and B properties of a Color, and the Implicit(Size to SizeF) member.<br><br>
        /// This example is designed to be used with a Windows Form. Paste the code into the form and call the ShowPropertiesOfSlateBlue method from the form's Paint event-handling method, passing e as PaintEventArgs.
        /// @code
        /// void ShowPropertiesOfSlateBlue(PaintEventArgs& e) {
        ///   Color slateBlue = Color::FromName("SlateBlue");
        ///   byte g = slateBlue.G;
        ///   byte b = slateBlue.B;
        ///   byte r = slateBlue.R;
        ///   byte a = slateBlue.A;
        ///   string text = String::Format("Slate Blue has these ARGB values: Alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
        ///   e.Graphics().DrawString(text, Font(this->Font, FontStyle::Italic), SolidBrush(slateBlue), RectangleF(PointF(0.0F, 0.0F), this->Size));
        /// }
        /// @endcode
        property_<byte, readonly_> G {
          get_ {return byte((this->argb & 0x0000FF00) >> 8);}
        };

        /// @brief Specifies whether this Color class is uninitialized.
        /// @return bool Returns true if this color is uninitialized; otherwise, false.
        property_<bool, readonly_> IsEmpty {
          get_ {return this->Equals(Empty);}
        };

        /// @brief Gets a value indicating whether this Color structure is a predefined color. Predefined colors are represented by the elements of the KnownColor enumeration.
        /// @return bool Returns true if this Color was created from a predefined color by using either the FromName method or the FromKnownColor method; otherwise, false.
        /// @remarks This property does not do a comparison of the ARGB values. Therefore, when the IsKnownColor property is applied to a Color structure that is created by using the FromArgb method, IsKnownColor returns false, even if the ARGB value matches the ARGB value of a predefined color.
        property_<bool, readonly_> IsKnownColor {
          get_ {return this->knownColor != (KnownColor)0;}
        };

        /// @brief Gets a value indicating whether this Color structure is a named color or a member of the KnownColor enumeration.
        /// @return bool Returns true if this Color was created by using either the FromName method or the FromKnownColor method; otherwise, false.
        property_<bool, readonly_> IsNamedColor {
          get_ {return this->knownColor != (KnownColor)0;}
        };

        /// @brief Gets a value indicating whether this Color structure is a system color. A system color is a color that is used in a Windows display element. System colors are represented by elements of the KnownColor enumeration.
        /// @return bool Returns true if this Color was created from a system color by using either the FromName method or the FromKnownColor method; otherwise, false.
        property_<bool, readonly_> IsSystemColor {
          get_ {return this->GetIsSystemColor();}
        };

        /// @brief Gets the name of this Color.
        /// @return string The name of this Color.
        property_<string, readonly_> Name {
          get_ {return this->GetName();}
        };

        /// @brief Gets the red component value of this Color class.
        /// @return byte The red component value of this Color.
        /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an A value of 255 represents an opaque color. An A value from 1 through 254 represents a semitransparent color. The color becomes more opaque as A approaches 255.
        /// @par Examples
        /// The following code example demonstrates the A, R, G, and B properties of a Color, and the Implicit(Size to SizeF) member.<br><br>
        /// This example is designed to be used with a Windows Form. Paste the code into the form and call the ShowPropertiesOfSlateBlue method from the form's Paint event-handling method, passing e as PaintEventArgs.
        /// @code
        /// void ShowPropertiesOfSlateBlue(PaintEventArgs& e) {
        ///   Color slateBlue = Color::FromName("SlateBlue");
        ///   byte g = slateBlue.G;
        ///   byte b = slateBlue.B;
        ///   byte r = slateBlue.R;
        ///   byte a = slateBlue.A;
        ///   string text = String::Format("Slate Blue has these ARGB values: Alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
        ///   e.Graphics().DrawString(text, Font(this->Font, FontStyle::Italic), SolidBrush(slateBlue), RectangleF(PointF(0.0F, 0.0F), this->Size));
        /// }
        /// @endcode
        property_<byte, readonly_> R {
          get_ {return byte((this->argb & 0x00FF0000) >> 16);}
        };

        /// @brief Compares the current instance with another object of the same type.
        /// @param obj An object to compare with this instance.
        /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
        /// | result            | Condition                                                   ,             |
        /// |-------------------|---------------------------------------------------------------------------|
        /// | Less than zero    | This instance is false and obj is true.                                   |
        /// | Zero              | This instance and obj are equal (either both are true or both are false). |
        /// | Greater than zero | This instance is true and obj is false.  -or- obj is null reference.      |
        int32 CompareTo(const IComparable& obj) const override {
          if (!is<Color>(obj)) return 1;
          return CompareTo(as<Color>(obj));
        }

        /// @brief Compares this instance to a specified Color object and returns an indication of their relative values.
        /// @param value An Color object to compare with this instance.
        /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
        /// | result            | Condition                                                                   |
        /// |-------------------|-----------------------------------------------------------------------------|
        /// | Less than zero    | This instance is false and value is true.                                   |
        /// | Zero              | This instance and value are equal (either both are true or both are false). |
        /// | Greater than zero | This instance is true and value is false.  -or- value is null reference.    |
        int32 CompareTo(const Color& color) const {return Int32(this->argb).CompareTo(color.argb);}

        /// @brief Determines whether this instance of Int32 and a specified object, which must also be a Int32 object, have the same value.
        /// @param value The Int32 to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        bool Equals(const Color& value) const;

        /// @brief Determines whether this instance of Int32 and a specified object, which must also be a Int32 object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override;

        /// @brief Creates a Color class from a 32-bit ARGB value.
        /// @param argb A value specifying the 32-bit ARGB value
        /// @return Color The Color structure that this method creates.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        static Color FromArgb(int32 argb) { return Color(argb); }

        /// @brief Creates a Color class from the specified Color structure, but with the new specified alpha value. Although this method allows a 32-bit value to be passed for the alpha value, the value is limited to 8 bits.
        /// @param alpha The alpha value for the new Color. Valid values are 0 through 255.
        /// @param baseColor The Color from which to create the new Color.
        /// @return Color The Color structure that this method creates.
        /// @exception ArgumentException alpha is less than 0 or greater than 255.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        static Color FromArgb(int32 alpha, const Color& baseColor);

        /// @brief Creates a Color class from the four ARGB component (alpha, red, green, and blue) values. Although this method allows a 32-bit value to be passed for each component, the value of each component is limited to 8 bits.
        /// @param alpha The alpha value for the new Color. Valid values are 0 through 255.
        /// @param red The red component. Valid values are 0 through 255.
        /// @param green The green component. Valid values are 0 through 255.
        /// @param blue The blue component. Valid values are 0 through 255.
        /// @return Color The Color structure that this method creates.
        /// @exception ArgumentException alpha, red, green or blue is less than 0 or greater than 255.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        static Color FromArgb(int32 alpha, int32 red, int32 green, int32 blue);

        /// @brief Creates a Color class from the three HSV component (hue, saturation, and brightness) values.
        /// @param hue The Color saturation. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
        /// @param saturation The Color saturation. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
        /// @param brightness The Color lightness. The lightness ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
        static Color FromHsb(float hue, float saturation, float brightness) {
          // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsv-to-rgb)
          if (saturation == 0)
            return Color::FromArgb(255, (byte)(brightness * 255.0f), (byte)(brightness * 255.0f), (byte)(brightness * 255.0f));

          hue = hue == 360 ? 0 : hue / 60;

          float f = hue - (float)Math::Truncate(hue);
          float p = brightness * (1.0f - saturation);
          float q = brightness * (1.0f - (saturation * f));
          float t = brightness * (1.0f - (saturation * (1.0f - f)));

          switch ((int)Math::Truncate(hue)) {
          case 0: return Color::FromArgb(255, (byte)(brightness * 255.0f), (byte)(t * 255.0f), (byte)(p * 255.0f));
          case 1: return Color::FromArgb(255, (byte)(q * 255.0f), (byte)(brightness * 255.0f), (byte)(p * 255.0f));
          case 2: return Color::FromArgb(255, (byte)(p * 255.0f), (byte)(brightness * 255.0f), (byte)(t * 255.0f));
          case 3: return Color::FromArgb(255, (byte)(p * 255.0f), (byte)(q * 255.0f), (byte)(brightness * 255.0f));
          case 4: return Color::FromArgb(255, (byte)(t * 255.0f), (byte)(p * 255.0f), (byte)(brightness * 255.0f));
          default: return Color::FromArgb(255, (byte)(brightness * 255.0f), (byte)(p * 255.0f), (byte)(q * 255.0f));
          }
        }

        /// @brief Creates a Color class from the four ARGB component (alpha, red, green, and blue) values. Although this method allows a 32-bit value to be passed for each component, the value of each component is limited to 8 bits.
        /// @param alpha The alpha value for the new Color. Valid values are 0 through 255.
        /// @param red The red component. Valid values are 0 through 255.
        /// @param green The green component. Valid values are 0 through 255.
        /// @param blue The blue component. Valid values are 0 through 255.
        /// @return Color The Color structure that this method creates.
        /// @exception ArgumentException alpha is less than 0 or greater than 255.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        static Color FromKnownColor(KnownColor color);

        /// @brief Creates a Color class from the specified name of a predefined color.
        /// @param name A string that is the name of a predefined color. Valid names are the same as the names of the elements of the KnownColor enumeration.
        /// @return Color The Color structure that this method creates.
        /// @remarks A predefined color is also called a known color and is represented by an element of the KnownColor enumeration. If the name parameter is not the valid name of a predefined color, the FromName method creates a Color structure that has an ARGB value of 0 (that is, all ARGB components are 0).
        static Color FromName(const string& name);

        /// @brief Gets the hue-saturation-brightness (HSB) brightness value for this Color structure.
        /// @return The lightness of this Color. The lightness ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Creates an instance of a Color structure, redShade, to be used for comparisons.
        /// * Iterates through the KnownColor enumeration elements to find all known colors that have the same lightness as redShade. The iterations are terminated when 15 matches are found or the value of the loop counter is greater than the last KnownColor element.
        /// * During each iteration, saves the KnownColor element—if it matches the criteria—in an array.
        /// * Uses a brush to paint rectangles.
        /// The first rectangle is painted the color represented by redShade. Each of the other rectangles is painted a KnownColor that matches the hue of the redShade.
        /// @code
        /// void KnownColorBrightnessExample2(PaintEventArgs& e) {
        ///   Graphics g = e.Graphics;
        ///
        ///   // Color structures. One is a variable used for temporary storage. The other
        ///   // is a constant used for comparisons.
        ///   Color someColor = Color::FromArgb(0);
        ///   Color redShade = Color::FromArgb(255, 200, 0, 100);
        ///
        ///   // Array to store KnownColor values that match the hue of the redShade
        ///   // color.
        ///   Array<KnownColor> colorMatches(15);
        ///
        ///   // Number of matches found.
        ///   int count = 0;
        ///
        ///   // Iterate through the KnownColor enums until 15 matches are found.
        ///   for (KnownColor enumValue = 0; enumValue <= KnownColor::YellowGreen && count < 15; enumValue++) {
        ///     someColor = Color::FromKnownColor(enumValue);
        ///     if (someColor.GetBrightness() == redShade.GetBrightness())
        ///       colorMatches[count++] = enumValue;
        ///   }
        ///
        ///   // Display the redShade color and its argb value.
        ///   SolidBrush  myBrush1(redShade);
        ///   Font myFont("Arial", 12);
        ///   int x = 20;
        ///   int y = 20;
        ///   someColor = redShade;
        ///   g.FillRectangle(myBrush1, x, y, 100, 30);
        ///   g.DrawString(someColor.ToString(), myFont, Brushes::Black, x + 120, y);
        ///
        ///   // Iterate through the matches that were found and display each color that
        ///   // corresponds with the enum value in the array. also display the name of
        ///   // the KnownColor.
        ///   for (int i = 0; i < count; i++) {
        ///     y += 40;
        ///     someColor = Color::FromKnownColor(colorMatches[i]);
        ///     myBrush1.Color = someColor;
        ///     g.FillRectangle(myBrush1, x, y, 100, 30);
        ///     g.DrawString(someColor.ToString(), myFont, Brushes::Black, x + 120, y);
        ///   }
        /// }
        /// @endcode
        float GetBrightness() const {
          // .net version (see https://referencesource.microsoft.com/#System.Drawing/commonui/System/Drawing/Color.cs,9103fd761ca562ae)
          //return ((float)Math::Max(Math::Max(this->R, this->G), this->B) + (float)Math::Min(Math::Min(this->R, this->G), this->B)) / 255.0 / 2.0;
          // algorithm  version (see https://www.programmingalgorithms.com/algorithm/rgb-to-hsv)
          return (float)Math::Max(Math::Max(this->R, this->G), this->B) / 255.0f;
        }

        /// @brief Serves as a hash function for a particular type.
        /// @return int32 A hash code for the current object.
        int32 GetHashCode() const override {return this->argb;}

        /// @brief Gets the hue-saturation-brightness (HSB) hue value, in degrees, for this Color structure.
        /// @return The hue, in degrees, of this Color. The hue is measured in degrees, ranging from 0.0 through 360.0, in HSL color space.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Creates an instance of a Color structure, redShade, to be used for comparisons.
        /// * Iterates through the KnownColor enumeration elements to find all known colors that have the same hue as redShade. The iterations are terminated when 15 matches are found or the value of the loop counter is greater than the last KnownColor element.
        /// * During each iteration, saves the KnownColor element—if it matches the criteria—in an array.
        /// * Uses a brush to paint rectangles.
        /// The first rectangle is painted the color represented by redShade. Each of the other rectangles is painted a KnownColor that matches the hue of the redShade.
        /// @code
        /// void GetHueExample(PaintEventArgs& e) {
        ///   Graphics g = e.Graphics;
        ///
        ///   // Color structures. One is a variable used for temporary storage. The other
        ///   // is a constant used for comparisons.
        ///   Color someColor = Color::FromArgb(0);
        ///   Color redShade = Color::FromArgb(255, 200, 0, 100);
        ///
        ///   // Array to store KnownColor values that match the hue of the redShade
        ///   // color.
        ///   Array<KnownColor> colorMatches(15);
        ///
        ///   // Number of matches found.
        ///   int count = 0;
        ///
        ///   // Iterate through the KnownColor enums until 15 matches are found.
        ///   for (KnownColor enumValue = 0; enumValue <= KnownColor::YellowGreen && count < 15; enumValue++) {
        ///     someColor = Color::FromKnownColor(enumValue);
        ///     if (someColor.GetHue() == redShade.GetHue())
        ///       colorMatches[count++] = enumValue;
        ///   }
        ///
        ///   // Display the redShade color and its argb value.
        ///   SolidBrush  myBrush1(redShade);
        ///   Font myFont("Arial", 12);
        ///   int x = 20;
        ///   int y = 20;
        ///   someColor = redShade;
        ///   g.FillRectangle(myBrush1, x, y, 100, 30);
        ///   g.DrawString(someColor.ToString(), myFont, Brushes::Black, x + 120, y);
        ///
        ///   // Iterate through the matches that were found and display each color that
        ///   // corresponds with the enum value in the array. also display the name of
        ///   // the KnownColor.
        ///   for (int i = 0; i < count; i++) {
        ///     y += 40;
        ///     someColor = Color::FromKnownColor(colorMatches[i]);
        ///     myBrush1.Color = someColor;
        ///     g.FillRectangle(myBrush1, x, y, 100, 30);
        ///     g.DrawString(someColor.ToString(), myFont, Brushes::Black, x + 120, y);
        ///   }
        /// }
        /// @endcode
        float GetHue() const {
          if (R == G && G == B)
            return 0.0;

          float r = (float)this->R() / 255.0f;
          float g = (float)this->G() / 255.0f;
          float b = (float)this->B() / 255.0f;

          float max = (float)Math::Max(Math::Max(r, g), b);
          float min = (float)Math::Min(Math::Min(r, g), b);

          float delta = max - min;

          float hue = 0.0;
          if (r == max) hue = (g - b) / delta;
          else if (g == max) hue = 2 + (b - r) / delta;
          else if (b == max) hue = 4 + (r - g) / delta;
          hue *= 60;

          if (hue < 0.0) hue += 360.0;
          return hue;
        }

        /// @brief Gets the hue-saturation-brightness (HSB) saturation value for this Color structure.
        /// @return The saturation of this Color. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Creates an instance of a Color structure, redShade, to be used for comparisons.
        /// * Iterates through the KnownColor enumeration elements to find all known colors that have the same saturation as redShade. The iterations are terminated when 15 matches are found or the value of the loop counter is greater than the last KnownColor element.
        /// * During each iteration, saves the KnownColor element—if it matches the criteria—in an array.
        /// * Uses a brush to paint rectangles.
        /// The first rectangle is painted the color represented by redShade. Each of the other rectangles is painted a KnownColor that matches the hue of the redShade.
        /// @code
        /// void GetSatExample(PaintEventArgs& e) {
        ///   Graphics g = e.Graphics;
        ///
        ///   // Color structures. One is a variable used for temporary storage. The other
        ///   // is a constant used for comparisons.
        ///   Color someColor = Color::FromArgb(0);
        ///   Color redShade = Color::FromArgb(255, 200, 0, 100);
        ///
        ///   // Array to store KnownColor values that match the hue of the redShade
        ///   // color.
        ///   Array<KnownColor> colorMatches(15);
        ///
        ///   // Number of matches found.
        ///   int count = 0;
        ///
        ///   // Iterate through the KnownColor enums until 15 matches are found.
        ///   for (KnownColor enumValue = 0; enumValue <= KnownColor::YellowGreen && count < 15; enumValue++) {
        ///     someColor = Color::FromKnownColor(enumValue);
        ///     if (someColor.GetSaturation() == redShade.GetSaturation())
        ///       colorMatches[count++] = enumValue;
        ///   }
        ///
        ///   // Display the redShade color and its argb value.
        ///   SolidBrush  myBrush1(redShade);
        ///   Font myFont("Arial", 12);
        ///   int x = 20;
        ///   int y = 20;
        ///   someColor = redShade;
        ///   g.FillRectangle(myBrush1, x, y, 100, 30);
        ///   g.DrawString(someColor.ToString(), myFont, Brushes::Black, x + 120, y);
        ///
        ///   // Iterate through the matches that were found and display each color that
        ///   // corresponds with the enum value in the array. also display the name of
        ///   // the KnownColor.
        ///   for (int i = 0; i < count; i++) {
        ///     y += 40;
        ///     someColor = Color::FromKnownColor(colorMatches[i]);
        ///     myBrush1.Color = someColor;
        ///     g.FillRectangle(myBrush1, x, y, 100, 30);
        ///     g.DrawString(someColor.ToString(), myFont, Brushes::Black, x + 120, y);
        ///   }
        /// }
        /// @endcode
        float GetSaturation() const {
          float max = (float)Math::Max(Math::Max(this->R, this->G), this->B) / 255.0f;
          float min = (float)Math::Min(Math::Min(this->R, this->G), this->B) / 255.0f;

          if (max == min) return 0.0f;

          return (max + min) <= 1.0f ? (max - min) / (max + min) : (max - min) / (2 - max - min);
        }

        /// @brief Gets the 32-bit ARGB value of this Color class.
        /// @return int32 The 32-bit ARGB value of this Color.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        int32 ToArgb() const { return this->argb; }

        /// @brief Gets the KnownColor value of this Color class.
        /// @return KnownColor An element of the KnownColor enumeration, if the Color is created from a predefined color by using either the FromName method or the FromKnownColor method; otherwise, 0.
        /// @remarks A predefined color is also called a known color and is represented by an element of the KnownColor enumeration. When the ToKnownColor method is applied to a Color structure that is created by using the FromArgb method, ToKnownColor returns 0, even if the ARGB value matches the ARGB value of a predefined color. ToKnownColor also returns 0 when it is applied to a Color structure that is created by using the FromName method with a string name that is not valid.
        KnownColor ToKnownColor() const { return this->knownColor; }

        /// @brief reates a human-readable string that represents this Size class.
        /// @return string A string that represents this Size.
        String ToString() const override;

      private :
        explicit Color(int32 argb) : argb(argb), knownColor((KnownColor)0) {}
        Color(int32 argb, const KnownColor& color) : argb(argb), knownColor(color) {}

        bool GetIsSystemColor() const;
        string GetName() const;

        int32 argb = 0;
        KnownColor knownColor = (KnownColor)0;
      };
    }
  }
}
