/// @file
/// @brief Contains Switch::System::Drawing::Font class.
#pragma once

#include <Switch/System/Convert.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemDrawingExport.hpp"
#include "FontFamily.hpp"
#include "FontStyle.hpp"
#include "GraphicsUnit.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Defines a particular format for text, including font face, size, and style attributes. This class cannot be inherited.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ Font final : public object {
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
        /// @remarks The resulting font has its Style property set to FontStyle.Regular.
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
        /// @remarks The resulting font has its Style property set to FontStyle.Regular.
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

        /// @cond
        Font() = default;
        Font(const Switch::System::Drawing::Font& font) : data(font.data) {}
        Font& operator=(const Switch::System::Drawing::Font&) = default;
        ~Font();
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
        property_<float, readonly_> SizeInPoint {
          get_ {return this->GetSizeInPoint();}
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

        static System::Drawing::Font FromHdc(intptr hdc);

        static System::Drawing::Font FromHFont(intptr hfont);

        template<typename object>
        static System::Drawing::Font FromLogFont(const object& lf) { return FromLogFont(lf, 0); }

        template<typename object>
        static System::Drawing::Font FromLogFont(const object& lf, intptr hdc) { return FromLogFontHandle((intptr)&lf, hdc); }

        /// @brief Returns the line spacing, in pixels, of this font.
        /// @return float The line spacing, in pixels, of this font.
        /// @remarks The line spacing is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.
        /// @remarks If the Unit property of the font is set to anything other than GraphicsUnit.Pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. For a screen display that has a vertical resolution of 96 dots per inch, you can calculate the height as follows:
        /// @remarks 2355*(0.3/2048)*96 = 33.11719
        float GetHeight() const;

        bool IsStyleAvaible(const System::Drawing::FontStyle& style) const {
          if (style == System::Drawing::FontStyle::Regular)
            return true;
          return System::Drawing::FontStyle(int(this->data->style) & int(style)) == style;
        }

        intptr ToHFont() const {return this->data->hfont;}

        String ToString() const override { return string::Format("[{0}: Name={1}, Size={2}, Units={3}, GdiCharSet={4}, GdiVerticalFont={5}]", this->GetType().Name, this->data->fontFamily.Name, this->data->size, (int32)this->data->unit, this->data->gdiCharSet, this->data->gdiVerticalFont); }

      private:
        static System::Drawing::Font FromLogFontHandle(intptr lf, intptr hdc);
        float GetSizeInPoint() const;

        struct FontData {
          System::Drawing::FontFamily fontFamily;
          byte gdiCharSet = 1;
          bool gdiVerticalFont = false;
          intptr hfont = IntPtr::Zero;
          bool isSystemFont = false;
          string originalFontName;
          float size = .0f;
          string systemFontName;
          System::Drawing::FontStyle style = System::Drawing::FontStyle::Regular;
          System::Drawing::GraphicsUnit unit = System::Drawing::GraphicsUnit::Point;
        };
        $<FontData> data = new_<FontData>();
      };
    }
  }
}
