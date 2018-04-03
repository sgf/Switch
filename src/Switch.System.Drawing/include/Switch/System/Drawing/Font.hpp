/// @file
/// @brief Contains Switch::System::Drawing::Font class.
#pragma once

#include <Switch/System/ComponentModel/Win32Exception.hpp>
#include <Switch/System/Convert.hpp>
#include <Switch/System/ICloneable.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemDrawingExport.hpp"
#include "FontFamily.hpp"
#include "FontStyle.hpp"
#include "GraphicsUnit.hpp"

/// @cond
struct __system_drawing_font_accessor__;
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @cond
      class Graphics;
      /// @endcond

      /// @brief Defines a particular format for text, including font face, size, and style attributes. This class cannot be inherited.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ Font final : public ICloneable, public object {
      public:
        /// @brief Initializes a new Font that uses the specified existing Font and FontStyle enumeration.
        /// @param prototype The existing Font from which to create the new Font.
        /// @param newStyle The FontStyle to apply to the new Font. Multiple values of the FontStyle enumeration can be combined with the OR operator.
        /// @par Examples
        /// The following code example demonstrates the Inequality operator, the Font constructor, and the Bold property. This example is designed to be used with a Windows Form that contains a button named Button2. Paste the following code into your form and associate the Button2_Click method with the button's Click event.
        /// @code
        /// void Button2_Click(const System::Object& sender, const System::EventArgs& e) {
        ///   if (this->BackColor != SystemColors::ControlDark) {
        ///     this->BackColor = SystemColors::ControlDark;
        ///   }
        ///   if (!(this->Font().Bold)) {
        ///     this->Font = System::Drawing::Font(this->Font, FontStyle::Bold);
        ///   }
        /// }
        /// @endcode
        Font(const Switch::System::Drawing::Font& prototype, System::Drawing::FontStyle newStyle);

        /// @brief Initializes a new Font using a specified size.
        /// @param family The FontFamily of the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The resulting font has its Style property set to Regular and its Unit property set to Point.
        Font(const System::Drawing::FontFamily& family, float emSize);

        /// @brief Initializes a new Font using a specified size and style.
        /// @param family The FontFamily of the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param style The FontStyle of the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The resulting font has its Unit property set to Point.
        /// @par Examples
        /// The following code example demonstrates how to set the Font property of a button to a new, bold-style Font. This example is designed to be used with a Windows Form that contains a button named Button1. Paste the following code into your form and associate the Button1_Click method with the button's Click event.
        /// @code
        ///  void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
        ///    if (this->button1.Font().Style != FontStyle::Bold)
        ///      this->button1.Font = System::Drawing:Font(FontFamily::GenericSansSerif, 12.0F, FontStyle::Bold);
        ///  }
        /// @endcode
        Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style);

        /// @brief Initializes a new Font using a specified size and unit. Sets the style to FontStyle::Regular.
        /// @param family The FontFamily of the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param style The FontStyle of the new font.
        /// @param unit The GraphicsUnit of the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The resulting font has its Style property set to FontStyle::Regular.
        Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit);

        /// @brief Initializes a new Font using a specified size, style, unit, and character set.
        /// @param family The FontFamily of the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param style The FontStyle of the new font.
        /// @param unit The GraphicsUnit of the new font.
        /// @param gdiCharSet GDI character set to use for the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h.
        Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet);

        /// @brief Initializes a new Font using a specified size, style, unit, and character set.
        /// @param family The FontFamily of the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param style The FontStyle of the new font.
        /// @param unit The GraphicsUnit of the new font.
        /// @param gdiCharSet GDI character set to use for the new font.
        /// @param gdiVerticalFont A Boolean value indicating whether the new font is derived from a GDI vertical font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h.
        Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet, bool gdiVerticalFont);

        /// @brief Initializes a new Font using a specified size and unit. Sets the style to FontStyle::Regular.
        /// @param family The FontFamily of the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param unit The GraphicsUnit of the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The resulting font has its Style property set to FontStyle::Regular.
        Font(const System::Drawing::FontFamily& family, float emSize, System::Drawing::GraphicsUnit unit);

        /// @brief Initializes a new Font using a specified size.
        /// @param familyName A string representation of the FontFamily for the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The resulting font has its Style property set to Regular and its Unit property set to Point.
        Font(const string& familyName, float emSize);

        /// @brief Initializes a new Font using a specified size and style.
        /// @param familyName A string representation of the FontFamily for the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param style The FontStyle of the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The resulting font has its Unit property set to Point.
        /// @par Examples
        /// The following code example demonstrates how to use the Font constructor and the Size, SizeInPoints, Name, Style, and Unit properties. This example is designed to be used with a Windows Form that contains a ComboBox named ComboBox1 that is populated with the strings "Bigger" and "Smaller". Paste the following code into the form and associate the ComboBox1_SelectedIndexChanged method with the SelectedIndexChanged event of the ComboBox control.
        /// @code
        /// void ComboBox1_SelectedIndexChanged(const System::Object& sender, const System::EventArgs& e) {
        ///   // Cast the sender object back to a ComboBox.
        ///   const ComboBox& comboBox1 = as<ComboBox>(sender);
        ///
        ///   // Retrieve the selected item.
        ///   string selectedString = as<string>(comboBox1.SelectedItem);
        ///
        ///   // Convert it to lowercase.
        ///   selectedString = selectedString.ToLower();
        ///
        ///   // Declare the current size.
        ///   float currentSize;
        ///
        ///   // If Bigger is selected, get the current size from the
        ///   // Size property and increase it. Reset the font to the
        ///   //  new size, using the current unit.
        ///   if (selectedString == "bigger") {
        ///     currentSize = label1.Font().Size;
        ///     currentSize += 2.0F;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style, label1.Font().Unit);
        ///
        ///     // If Smaller is selected, get the current size, in points,
        ///     // and decrease it by 1.  Reset the font with the new size
        ///     // in points.
        ///   } else if (selectedString == "smaller") {
        ///     currentSize = label1.Font().SizeInPoints;
        ///     currentSize -= 1;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style);
        ///   }
        /// }
        /// @endcode
        Font(const string& familyName, float emSize, System::Drawing::FontStyle style);

        /// @brief Initializes a new Font using a specified size and unit. Sets the style to FontStyle::Regular.
        /// @param familyName A string representation of the FontFamily for the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param style The FontStyle of the new font.
        /// @param unit The GraphicsUnit of the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The resulting font has its Style property set to FontStyle::Regular.
        /// @par Examples
        /// The following code example demonstrates how to use the Font constructor and the Size, SizeInPoints, Name, Style, and Unit properties. This example is designed to be used with a Windows Form that contains a ComboBox named ComboBox1 that is populated with the strings "Bigger" and "Smaller". Paste the following code into the form and associate the ComboBox1_SelectedIndexChanged method with the SelectedIndexChanged event of the ComboBox control.
        /// @code
        /// void ComboBox1_SelectedIndexChanged(const System::Object& sender, const System::EventArgs& e) {
        ///   // Cast the sender object back to a ComboBox.
        ///   const ComboBox& comboBox1 = as<ComboBox>(sender);
        ///
        ///   // Retrieve the selected item.
        ///   string selectedString = as<string>(comboBox1.SelectedItem);
        ///
        ///   // Convert it to lowercase.
        ///   selectedString = selectedString.ToLower();
        ///
        ///   // Declare the current size.
        ///   float currentSize;
        ///
        ///   // If Bigger is selected, get the current size from the
        ///   // Size property and increase it. Reset the font to the
        ///   //  new size, using the current unit.
        ///   if (selectedString == "bigger") {
        ///     currentSize = label1.Font().Size;
        ///     currentSize += 2.0F;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style, label1.Font().Unit);
        ///
        ///     // If Smaller is selected, get the current size, in points,
        ///     // and decrease it by 1.  Reset the font with the new size
        ///     // in points.
        ///   } else if (selectedString == "smaller") {
        ///     currentSize = label1.Font().SizeInPoints;
        ///     currentSize -= 1;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style);
        ///   }
        /// }
        /// @endcode
        Font(const string& familyName, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit);

        /// @brief Initializes a new Font using a specified size, style, unit, and character set.
        /// @param familyName A string representation of the FontFamily for the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param style The FontStyle of the new font.
        /// @param unit The GraphicsUnit of the new font.
        /// @param gdiCharSet GDI character set to use for the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h.
        Font(const string& familyName, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet);

        /// @brief Initializes a new Font using a specified size, style, unit, and character set.
        /// @param familyName A string representation of the FontFamily for the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param style The FontStyle of the new font.
        /// @param unit The GraphicsUnit of the new font.
        /// @param gdiCharSet GDI character set to use for the new font.
        /// @param gdiVerticalFont A Boolean value indicating whether the new font is derived from a GDI vertical font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h.
        Font(const string& familyName, float emSize, System::Drawing::FontStyle style, System::Drawing::GraphicsUnit unit, byte gdiCharSet, bool gdiVerticalFont);

        /// @brief Initializes a new Font using a specified size and unit. Sets the style to FontStyle::Regular.
        /// @param familyName A string representation of the FontFamily for the new Font.
        /// @param emSize The em-size, in points, of the new font.
        /// @param unit The GraphicsUnit of the new font.
        /// @exception ArgumentException emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
        /// @remarks The resulting font has its Style property set to FontStyle::Regular.
        Font(const string& familyName, float emSize, System::Drawing::GraphicsUnit unit);

        /// @cond
        Font() = default;
        Font(const Switch::System::Drawing::Font& font) : data(font.data) {}
        Font& operator=(const Switch::System::Drawing::Font&) = default;
        ~Font();
        bool operator<(const Font& font) const {return this->Name() < font.Name();}
        bool operator>(const Font& font) const {return this->Name() > font.Name();}
        /// @endcond

        /// @brief Gets a value that indicates whether this Font is bold.
        /// @return bool true if this Font is bold; otherwise, false.
        /// @par Examples
        /// The following code example demonstrates the Inequality operator, the Font constructor, and the Bold property. This example is designed to be used with a Windows Form that contains a button named Button2. Paste the following code into your form and associate the Button2_Click method with the button's Click event.
        /// @code
        /// void Button2_Click(const System::Object& sender, const System::EventArgs& e) {
        ///   if (this->BackColor != SystemColors::ControlDark) {
        ///     this->BackColor = SystemColors::ControlDark;
        ///   }
        ///   if (!(this->Font().Bold)) {
        ///     this->Font = System::Drawing::Font(this->Font, FontStyle::Bold);
        ///   }
        /// }
        /// @endcode
        property_<bool, readonly_> Bold {
          get_ {return (this->data->style & System::Drawing::FontStyle::Bold) == System::Drawing::FontStyle::Bold;}
        };

        /// @brief Gets the FontFamily associated with this Font.
        /// @return FontFamily The FontFamily associated with this Font.
        /// @remarks A FontFamily represents a group of fonts that have a similar font face, but may have different sizes and styles (for example, Arial, Times New Roman, and Verdana).
        property_<System::Drawing::FontFamily, readonly_> FontFamily {
          get_ {return this->data->fontFamily;}
        };

        /// @brief Gets a byte value that specifies the GDI character set that this Font uses.
        /// @return byte A byte value that specifies the GDI character set that this Font uses. The default is 1.
        /// @remarks This property returns 1, unless a different character set is specified in the Font(String, Single, FontStyle, GraphicsUnit, Byte) constructor. This property takes a value from the list defined in the Windows SDK header file WinGDI.h. The character sets and byte values are listed in the following table.
        /// | Character set | alue |
        /// |---------------|------|
        /// | ANSI          | 0    |
        /// | DEFAULT       | 1    |
        /// | SYMBOL        | 2    |
        /// | SHIFTJIS      | 128  |
        /// | HANGEUL       | 129  |
        /// | HANGUL        | 129  |
        /// | GB2312        | 134  |
        /// | CHINESEBIG5   | 136  |
        /// | OEM           | 255  |
        /// | JOHAB         | 130  |
        /// | HEBREW        | 177  |
        /// | ARABIC        | 178  |
        /// | GREEK         | 161  |
        /// | TURKISH       | 162  |
        /// | VIETNAMESE    | 163  |
        /// | THAI          | 222  |
        /// | EASTEUROPE    | 238  |
        /// | RUSSIAN       | 204  |
        /// | MAC           | 77   |
        /// | BALTIC        | 186  |
        property_<byte, readonly_> GdiCharSet {
          get_ {return this->data->gdiCharSet;}
        };

        /// @brief Gets a Boolean value that indicates whether this Font is derived from a GDI vertical font.
        /// @return bool true if this Font is derived from a GDI vertical font; otherwise, false.
        /// @remarks Use this property to determine if a font is compatible with native Win32 controls on non-Unicode platforms.
        /// @remarks GdiVerticalFont only returns true if this font was created from a classic GDI font definition, like a LOGFONT or HFONT.
        property_<bool, readonly_> GdiVerticalFont {
          get_ {return this->data->gdiVerticalFont;}
        };

        /// @brief Gets the line spacing of this font.
        /// @return int32 The line spacing, in pixels, of this font.
        /// @remarks The line spacing is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.
        /// @remarks If the Unit property of the font is set to anything other than GraphicsUnit.Pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. For a screen display that has a vertical resolution of 96 dots per inch, you can calculate the height as follows:
        /// @remarks 2355*(0.3/2048)*96 = 33.11719
        /// @remarks The value returned by the GetHeight method would be 33.11719, and the value returned by the Height property would be 34. The Height property is the value returned by GetHeight, rounded up to the nearest integer.
        property_<int32, readonly_> Height {
          get_ {return Convert::ToInt32(this->GetHeight());}
        };

        /// @brief Gets a value indicating whether the font is a member of SystemFonts.
        /// @return bool true if the font is a member of SystemFonts; otherwise, false. The default is false.
        /// @remarks When the user changes the system font, the IsSystemFont property could return true, even if the font is not actually a system font. To avoid this situation, if you are using system fonts in your application, you should track user preference changes by handling the UserPreferenceChanging or UserPreferenceChanged event.
        property_<bool, readonly_> IsSystemFont {
          get_ {return this->data->isSystemFont;}
        };

        /// @brief Gets a value that indicates whether this font has the italic style applied.
        /// @return bool true to indicate this font has the italic style applied; otherwise, false.
        property_<bool, readonly_> Italic {
          get_ {return (this->data->style & System::Drawing::FontStyle::Italic) == System::Drawing::FontStyle::Italic;}
        };

        /// @brief Gets the face name of this Font.
        /// @return string A string representation of the face name of this Font.
        /// @par Examples
        /// The following code example demonstrates how to use the Font constructor and the Size, SizeInPoints, Name, Style, and Unit properties. This example is designed to be used with a Windows Form that contains a ComboBox named ComboBox1 that is populated with the strings "Bigger" and "Smaller". Paste the following code into the form and associate the ComboBox1_SelectedIndexChanged method with the SelectedIndexChanged event of the ComboBox control.
        /// @code
        /// void ComboBox1_SelectedIndexChanged(const System::Object& sender, const System::EventArgs& e) {
        ///   // Cast the sender object back to a ComboBox.
        ///   const ComboBox& comboBox1 = as<ComboBox>(sender);
        ///
        ///   // Retrieve the selected item.
        ///   string selectedString = as<string>(comboBox1.SelectedItem);
        ///
        ///   // Convert it to lowercase.
        ///   selectedString = selectedString.ToLower();
        ///
        ///   // Declare the current size.
        ///   float currentSize;
        ///
        ///   // If Bigger is selected, get the current size from the
        ///   // Size property and increase it. Reset the font to the
        ///   //  new size, using the current unit.
        ///   if (selectedString == "bigger") {
        ///     currentSize = label1.Font().Size;
        ///     currentSize += 2.0F;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style, label1.Font().Unit);
        ///
        ///     // If Smaller is selected, get the current size, in points,
        ///     // and decrease it by 1.  Reset the font with the new size
        ///     // in points.
        ///   } else if (selectedString == "smaller") {
        ///     currentSize = label1.Font().SizeInPoints;
        ///     currentSize -= 1;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style);
        ///   }
        /// }
        /// @endcode
        property_<string, readonly_> Name {
          get_ {return this->data->fontFamily.Name();}
        };

        /// @brief This API supports the product infrastructure and is not intended to be used directly from your code. Gets the name of the font originally specified.
        /// @return string The string representing the name of the font originally specified.
        /// @remarks The actual font name and original font name can be different. System requirements may cause the use of a font other than the font originally specified.
        property_<string, readonly_> OriginalFontName {
          get_ {return this->data->originalFontName;}
        };

        /// @brief Gets the em-size of this Font measured in the units specified by the Unit property.
        /// @return float The em-size of this Font.
        /// @par Examples
        /// The following code example demonstrates how to use the Font constructor and the Size, SizeInPoints, Name, Style, and Unit properties. This example is designed to be used with a Windows Form that contains a ComboBox named ComboBox1 that is populated with the strings "Bigger" and "Smaller". Paste the following code into the form and associate the ComboBox1_SelectedIndexChanged method with the SelectedIndexChanged event of the ComboBox control.
        /// @code
        /// void ComboBox1_SelectedIndexChanged(const System::Object& sender, const System::EventArgs& e) {
        ///   // Cast the sender object back to a ComboBox.
        ///   const ComboBox& comboBox1 = as<ComboBox>(sender);
        ///
        ///   // Retrieve the selected item.
        ///   string selectedString = as<string>(comboBox1.SelectedItem);
        ///
        ///   // Convert it to lowercase.
        ///   selectedString = selectedString.ToLower();
        ///
        ///   // Declare the current size.
        ///   float currentSize;
        ///
        ///   // If Bigger is selected, get the current size from the
        ///   // Size property and increase it. Reset the font to the
        ///   //  new size, using the current unit.
        ///   if (selectedString == "bigger") {
        ///     currentSize = label1.Font().Size;
        ///     currentSize += 2.0F;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style, label1.Font().Unit);
        ///
        ///     // If Smaller is selected, get the current size, in points,
        ///     // and decrease it by 1.  Reset the font with the new size
        ///     // in points.
        ///   } else if (selectedString == "smaller") {
        ///     currentSize = label1.Font().SizeInPoints;
        ///     currentSize -= 1;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style);
        ///   }
        /// }
        /// @endcode
        property_<float, readonly_> Size {
          get_ {return this->data->size;}
        };

        /// @brief Gets the em-size, in points, of this Font.
        /// @return float The em-size, in points, of this Font.
        /// @par Examples
        /// The following code example demonstrates how to use the Font constructor and the Size, SizeInPoints, Name, Style, and Unit properties. This example is designed to be used with a Windows Form that contains a ComboBox named ComboBox1 that is populated with the strings "Bigger" and "Smaller". Paste the following code into the form and associate the ComboBox1_SelectedIndexChanged method with the SelectedIndexChanged event of the ComboBox control.
        /// @code
        /// void ComboBox1_SelectedIndexChanged(const System::Object& sender, const System::EventArgs& e) {
        ///   // Cast the sender object back to a ComboBox.
        ///   const ComboBox& comboBox1 = as<ComboBox>(sender);
        ///
        ///   // Retrieve the selected item.
        ///   string selectedString = as<string>(comboBox1.SelectedItem);
        ///
        ///   // Convert it to lowercase.
        ///   selectedString = selectedString.ToLower();
        ///
        ///   // Declare the current size.
        ///   float currentSize;
        ///
        ///   // If Bigger is selected, get the current size from the
        ///   // Size property and increase it. Reset the font to the
        ///   //  new size, using the current unit.
        ///   if (selectedString == "bigger") {
        ///     currentSize = label1.Font().Size;
        ///     currentSize += 2.0F;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style, label1.Font().Unit);
        ///
        ///     // If Smaller is selected, get the current size, in points,
        ///     // and decrease it by 1.  Reset the font with the new size
        ///     // in points.
        ///   } else if (selectedString == "smaller") {
        ///     currentSize = label1.Font().SizeInPoints;
        ///     currentSize -= 1;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style);
        ///   }
        /// }
        /// @endcode
        property_<float, readonly_> SizeInPoints {
          get_ {return this->GetSizeInPoints();}
        };

        /// @brief Gets a value that indicates whether this Font specifies a horizontal line through the font.
        /// @return bool true if this Font has a horizontal line through it; otherwise, false.
        property_<bool, readonly_> Strikeout {
          get_ {return (this->data->style & System::Drawing::FontStyle::Strikeout) == System::Drawing::FontStyle::Strikeout;}
        };

        /// @brief Gets style information for this Font.
        /// @return FontStyle A FontStyle enumeration that contains style information for this Font.
        /// @par Examples
        /// The following code example demonstrates the Inequality operator, the Font constructor, and the Bold property. This example is designed to be used with a Windows Form that contains a button named Button2. Paste the following code into your form and associate the Button2_Click method with the button's Click event.
        /// @code
        /// void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
        ///   if ((this->button1.Font().Bold & FontStyle::Bold) != FontStyle::Bold) {
        ///     this->button1.Font().Font = System::Drawing::Font(FontFamily.GenericSansSerif, 12.0F, FontStyle::Bold);
        ///   }
        /// }
        /// @endcode
        property_<System::Drawing::FontStyle, readonly_> Style {
          get_ {return this->data->style;}
        };

        /// @brief Gets the name of the system font if the IsSystemFont property returns true.
        /// @return string The name of the system font, if IsSystemFont returns true; otherwise, an empty string ("").
        /// @remarks The name returned by the SystemFontName property will be one of the members of the SystemFonts, converted to a string.
        property_<string, readonly_> SystemFontName {
          get_ {return this->data->systemFontName;}
        };

        /// @brief Gets a value that indicates whether this Font is underlined.
        /// @return bool true if this Font is underlined; otherwise, false.
        property_<bool, readonly_> Underline {
          get_ {return (this->data->style & System::Drawing::FontStyle::Underline) == System::Drawing::FontStyle::Underline;}
        };

        /// @brief Gets the unit of measure for this Font.
        /// @return GraphicUnit A GraphicsUnit that represents the unit of measure for this Font.
        /// @par Examples
        /// The following code example demonstrates how to use the Font constructor and the Size, SizeInPoints, Name, Style, and Unit properties. This example is designed to be used with a Windows Form that contains a ComboBox named ComboBox1 that is populated with the strings "Bigger" and "Smaller". Paste the following code into the form and associate the ComboBox1_SelectedIndexChanged method with the SelectedIndexChanged event of the ComboBox control.
        /// @code
        /// void ComboBox1_SelectedIndexChanged(const System::Object& sender, const System::EventArgs& e) {
        ///   // Cast the sender object back to a ComboBox.
        ///   const ComboBox& comboBox1 = as<ComboBox>(sender);
        ///
        ///   // Retrieve the selected item.
        ///   string selectedString = as<string>(comboBox1.SelectedItem);
        ///
        ///   // Convert it to lowercase.
        ///   selectedString = selectedString.ToLower();
        ///
        ///   // Declare the current size.
        ///   float currentSize;
        ///
        ///   // If Bigger is selected, get the current size from the
        ///   // Size property and increase it. Reset the font to the
        ///   //  new size, using the current unit.
        ///   if (selectedString == "bigger") {
        ///     currentSize = label1.Font().Size;
        ///     currentSize += 2.0F;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style, label1.Font().Unit);
        ///
        ///     // If Smaller is selected, get the current size, in points,
        ///     // and decrease it by 1.  Reset the font with the new size
        ///     // in points.
        ///   } else if (selectedString == "smaller") {
        ///     currentSize = label1.Font().SizeInPoints;
        ///     currentSize -= 1;
        ///     label1.Font = Font(label1.Font().Name, currentSize, label1.Font().Style);
        ///   }
        /// }
        /// @endcode
        property_<GraphicsUnit, readonly_> Unit {
          get_ {return this->data->unit;}
        };

        /// @brief Creates an exact copy of this Font.
        /// @return $<objects> The Font this method creates, cast as an Object.
        /// @par Examples
        /// @code
        /// void Clone_Example(PaintEventArgs e) {
        ///   // Create a Font object.
        ///   Font myFontFont("Arial", 16);
        ///
        ///   // Create a copy of myFont.
        ///   $<Font> cloneFont = as<Font>(myFont.Clone());
        ///
        ///   // Use cloneFont to draw text to the screen.
        ///   e.Graphics().DrawString("This is a cloned font", *cloneFont, Brushes::Black, 0, 0);
        /// }
        /// @endcode
        $<object> Clone() const override {return this->MemberwiseClone<Font>();}

        /// @brief Indicates whether the specified object is a Font and has the same FontFamily, GdiVerticalFont, GdiCharSet, Style, Size, and Unit property values as this Font.
        /// @param obj The object to test.
        /// @return bool true if the obj parameter is a Font and has the same FontFamily, GdiVerticalFont, GdiCharSet, Style, Size, and Unit property values as this Font; otherwise, false.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code creates two Font objects and then tests whether they are equivalent.
        /// @code
        /// void Equals_Example(PaintEventArgs& e) {
        ///   // Create a Font object.
        ///   Font firstFont("Arial", 16);
        ///
        ///   // Create a second Font object.
        ///   Font secondFont(FontFamily("Arial"), 16);
        ///
        ///   // Test to see if firstFont is identical to secondFont.
        ///   bool fontTest = firstFont.Equals(secondFont);
        ///
        ///   // Display a message box with the result of the test.
        ///   MessageBox::Show(Boolean(fontTest).ToString());
        /// }
        /// @endcode
        bool Equals(const object& obj) const override {return is<Font>(obj) && this->data->fontFamily == as<Font>(obj).data->fontFamily && this->data->gdiCharSet == as<Font>(obj).data->gdiCharSet && this->data->gdiVerticalFont == as<Font>(obj).data->gdiVerticalFont && this->data->style == as<Font>(obj).data->style && this->data->size == as<Font>(obj).data->size && this->data->unit == as<Font>(obj).data->unit;}

        /// @brief Creates a Font from the specified Windows handle to a device context.
        /// @param hdc A handle to a device context.
        /// @return Font The Font this method creates.
        /// @exception ArgumentException The font for the specified device context is not a TrueType font.
        /// @remarks For this method to work, the hdc parameter must contain a handle to a device context in which a font is selected. This method will not work with an hdc handle acquired from a GDI+ Graphics object because the hdc handle does not have a font selected.
        /// @warning Always throw NotImplementedExeption.
        static System::Drawing::Font FromHdc(intptr hdc);

        /// @brief Creates a Font from the specified Windows handle.
        /// @param hfont A Windows handle to a GDI font.
        /// @return Font The Font this method creates.
        /// @remarks For this method to work, the hdc parameter must contain a handle to a device context in which a font is selected. This method will not work with an hdc handle acquired from a GDI+ Graphics object because the hdc handle does not have a font selected.
        /// @warning Always throw NotImplementedExeption.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Gets a handle to a GDI font.
        /// * Creates a Font from that handle.
        /// * Draws text to the screen, using the new Font.
        /// @code
        /// void FromHfont_Example(PaintEventArgs& e) {
        ///
        ///   // Get a handle for a GDI font.
        ///   intptr hFont = (intptr)GetStockObject(0); // Win32 api (included in Windows.h)
        ///
        ///   // Create a Font object from hFont.
        ///   Font hfontFont = Font::FromHfont(hFont);
        ///
        ///   // Use hfontFont to draw text to the screen.
        ///   e.Graphics().DrawString("This font is from a GDI HFONT", hfontFont, Brushes::Black, 0, 0)
        /// }
        /// @endcode
        static System::Drawing::Font FromHFont(intptr hfont);

        /// @brief Creates a Font from the specified GDI logical font (LOGFONT) structure.
        /// @param lf An Object that represents the GDI LOGFONT structure from which to create the Font.
        /// @return Font The Font that this method creates.
        /// @remarks A GDI LOGFONT, or logical font, is a structure that contains 14 properties that describe a particular font. For more information, see "The Logical Font" in the Windows Development documentation at http://msdn.microsoft.com/library.
        /// @warning Always throw NotImplementedExeption.
        template<typename object>
        static System::Drawing::Font FromLogFont(const object& lf) { return FromLogFont(lf, 0); }

        /// @brief Creates a Font from the specified GDI logical font (LOGFONT) structure.
        /// @param lf An Object that represents the GDI LOGFONT structure from which to create the Font.
        /// @param hdc A handle to a device context that contains additional information about the lf structure.
        /// @return Font The Font that this method creates.
        /// @exception ArgumentException The font is not a TrueType font.
        /// @remarks A GDI LOGFONT, or logical font, is a structure that contains 14 properties that describe a particular font. For more information, see "The Logical Font" in the Windows Development documentation at http://msdn.microsoft.com/library.
        /// @warning Always throw NotImplementedExeption.
        template<typename object>
        static System::Drawing::Font FromLogFont(const object& lf, intptr hdc) { return FromLogFontHandle((intptr)&lf, hdc); }

        /// @brief Returns the line spacing, in pixels, of this font.
        /// @return float The line spacing, in pixels, of this font.
        /// @remarks The line spacing is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.
        /// @remarks If the Unit property of the font is set to anything other than GraphicsUnit.Pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. For a screen display that has a vertical resolution of 96 dots per inch, you can calculate the height as follows:
        /// @remarks 2355*(0.3/2048)*96 = 33.11719
        float GetHeight() const;

        /// @brief Returns the line spacing, in the current unit of a specified Graphics, of this font.
        /// @param graphics A Graphics that holds the vertical resolution, in dots per inch, of the display device as well as settings for page unit and page scale.
        /// @return float The line spacing, in pixels, of this font.
        /// @remarks The line spacing of a Font is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.
        /// @remarks If the Unit property of the font is set to anything other than GraphicsUnit.Pixel, the height, in pixels, is calculated using the vertical resolution of the specified Graphics object. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. If the Graphics object has a Unit property value of GraphicsUnit.Pixel and a DpiY property value of 96 dots per inch, the height is calculated as follows:
        /// @remarks 2355*(0.3/2048)*96 = 33.1171875
        /// @remarks Continuing with the same example, suppose the Unit property of the Graphics object is set to GraphicsUnit.Millimeter rather than GraphicsUnit.Pixel. Then (using 1 inch = 25.4 millimeters) the height, in millimeters, is calculated as follows:
        /// @remarks 2355*(0.3/2048)*25.4 = 8.762256
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Creates a Font.
        /// * Draws a line of text to the screen, using the new Font.
        /// * Gets the height of the font.
        /// * Draws a second line of text directly below the first line.
        /// @code
        /// void GetHeight_Example(PaintEventArgs& e) {
        ///   // Create a Font object.
        ///   Font myFont("Arial", 16);
        ///
        ///   //Draw text to the screen with myFont.
        ///   e.Graphics().DrawString("This is the first line", myFont, Brushes::Black, PointF(0, 0));
        ///
        ///   //Get the height of myFont.
        ///   float height = myFont.GetHeight(e.Graphics);
        ///
        ///   //Draw text immediately below the first line of text.
        ///   e.Graphics.DrawString("This is the second line", myFont, Brushes::Black, PointF(0, height));
        /// }
        /// @endcode
        float GetHeight(const Graphics& graphics) const;

        /// @brief Returns the height, in pixels, of this Font when drawn to a device with the specified vertical resolution.
        /// @param dpi The vertical resolution, in dots per inch, used to calculate the height of the font.
        /// @return float The height, in pixels, of this Font.
        /// @remarks If the Unit property of the font is set to anything other than GraphicsUnit.Pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. If the specified vertical resolution is 96 dots per inch, the height is calculated as follows:
        /// @remarks 2355*(0.3/2048)*96 = 33.1171875
        float GetHeight(float dpi) const;

        /// @brief Returns a handle to this Font.
        /// @return intptr A Windows handle to this Font.
        /// @exception Win32Exception The operation was unsuccessful.
        /// @remarks When using this method, you must dispose of the resulting Hfont using the GDI DeleteObject method to ensure the resources are released.
        /// @par Examples
        /// The following code example creates a Font and then gets a handle to that Font. The example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler.
        /// @code
        /// void ToHfont_Example(PaintEventArgs& e) {
        ///   // Create a Font object.
        ///   Font myFont("Arial", 16);
        ///
        ///   // Get a handle to the Font object.
        ///   intptr hFont = myFont.ToHfont();
        ///
        ///   // Display a message box with the value of hFont.
        ///   MessageBox::Show(IntPtr(hFont).ToString());
        ///
        ///   //Dispose of the hFont.
        ///   DeleteObject(hFont); // Win32 api (included in Windows.h)
        /// }
        /// @endcode
        intptr ToHFont() const {return this->data->hfont;}

        /// @brief Returns a human-readable string representation of this Font.
        /// @return string A string that represents this Font.
        /// @remarks The returned string has the following format:
        /// @remarks [Font: Name=fontName, Size=size, Units=units, GDiCharSet=gdiCharSet, GdiVerticalFont=boolean]
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Creates a Font.
        /// * Gets a string that represents the font.
        /// * Displays the string in a message box.
        /// @code
        /// void ToString_Example(PaintEventArgs& e) {
        ///   // Create a Font object.
        ///   Font myFont("Arial", 16);
        ///
        ///   // Get a string that represents myFont.
        ///   string fontString = myFont.ToString();
        ///
        ///   // Display a message box with fontString.
        ///   MessageBox::Show(fontString);
        /// }
        /// @endcode
        String ToString() const override { return string::Format("[{0}: Name={1}, Size={2}, Units={3}, GdiCharSet={4}, GdiVerticalFont={5}]", this->GetType().Name, this->data->fontFamily.Name, this->data->size, (int32)this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont); }

      private:
        /// @cond
        friend struct ::__system_drawing_font_accessor__;
        /// @endcond
        static System::Drawing::Font FromLogFontHandle(intptr lf, intptr hdc);
        float GetSizeInPoints() const;

        struct FontData {
          System::Drawing::FontFamily fontFamily;
          byte gdiCharSet = 1;
          bool gdiVerticalFont = false;
          intptr hfont = IntPtr::Zero;
          bool isSystemFont = false;
          string originalFontName;
          float size = 8.25f;
          string systemFontName;
          System::Drawing::FontStyle style = System::Drawing::FontStyle::Regular;
          System::Drawing::GraphicsUnit unit = System::Drawing::GraphicsUnit::Point;
        };
        $<FontData> data = new_<FontData>();
      };
    }
  }
}
