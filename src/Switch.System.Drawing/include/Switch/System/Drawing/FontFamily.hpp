/// @file
/// @brief Contains Switch::System::Drawing::FontFamily class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemDrawingExport.hpp"
#include "FontStyle.hpp"
#include "Text/GenericFontFamilies.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @cond
      namespace Text {
        class FontCollection;
      }
      /// @endcond

      /// @brief Defines a group of type faces having a similar basic design and certain variations in styles. This class cannot be inherited.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ FontFamily final : public object {
      public:
        /// @brief Initializes a new FontFamily from the specified generic font family.
        /// @param genericFamily The GenericFontFamilies from which to create the new FontFamily.
        explicit FontFamily(System::Drawing::Text::GenericFontFamilies genericFamily);

        /// @brief Initializes a new FontFamily with the specified name.
        /// @brief name The name of the new FontFamily.
        /// @exception ArgumentException name is an empty string ("").  -or-  name specifies a font that is not installed on the computer running the application.  -or-  name specifies a font that is not a TrueType font.
        /// @remarks Passing empty string ("") for the name parameter causes an exception.
        /// @remarks Passing empty string ("") for the name parameter causes an exception.
        explicit FontFamily(const string& name);

        /// @brief Initializes a new FontFamily in the specified FontCollection with the specified name.
        /// @param name A String that represents the name of the new FontFamily.
        /// @param fontCollection The FontCollection that contains this FontFamily.
        /// @exception ArgumentException name is an empty string ("").  -or-  name specifies a font that is not installed on the computer running the application.  -or-  name specifies a font that is not a TrueType font.
        /// @warning Always throw NotImplementedExeption.
        FontFamily(const string& name, const System::Drawing::Text::FontCollection& fontCollection);

        /// @cond
        FontFamily() = default;
        explicit FontFamily(intptr handle) { this->data().handle = handle; }
        FontFamily(const FontFamily& fontFamily) : data(fontFamily.data) {}
        FontFamily& operator=(const FontFamily&) = default;
        ~FontFamily();
        /// @endcond

        /// @brief Returns an array that contains all the FontFamily objects associated with the current graphics context.
        /// @return Array<FontFamily> An array of FontFamily objects associated with the current graphics context.
        /// @par Examples
        /// The following code example shows all the font families in the Families property of the FontFamily class. This example is designed to be used with a Windows Form. To run this example, add a ListBox named listBox1 to a form and call the PopulateListBoxWithFonts method from the form's constructor.
        /// @code
        /// void PopulateListBoxWithFonts() {
        ///   listBox1.Width = 200;
        ///   listBox1.Location = Point(40, 120);
        ///   for (FontFamily oneFontFamily : FontFamily::Families()) {
        ///     listBox1.Items().Add(oneFontFamily.Name);
        ///   }
        /// }
        /// @endcode
        static property_<Array<FontFamily>, readonly_> Families;

        /// @brief Gets a generic monospace FontFamily.
        /// @return FontFamily A FontFamily that represents a generic monospace font.
        static property_<FontFamily, readonly_> GenericMonospace;

        /// @brief Gets a generic sans serif FontFamily.
        /// @return FontFamily A FontFamily that represents a generic sans serif font.
        static property_<FontFamily, readonly_> GenericSansSerif;

        /// @brief Gets a generic serif FontFamily.
        /// @return FontFamily A FontFamily that represents a generic serif font.
        static property_<FontFamily, readonly_> GenericSerif;

        /// @brief Gets the name of this FontFamily.
        /// @return string A String that represents the name of this FontFamily.
        /// @par Examples
        /// The following code example shows all the font families in the Families property of the FontFamily class. This example is designed to be used with a Windows Form. To run this example, add a ListBox named listBox1 to a form and call the PopulateListBoxWithFonts method from the form's constructor.
        /// @code
        /// void PopulateListBoxWithFonts() {
        ///   listBox1.Width = 200;
        ///   listBox1.Location = Point(40, 120);
        ///   for (FontFamily oneFontFamily : FontFamily::Families()) {
        ///     listBox1.Items().Add(oneFontFamily.Name);
        ///   }
        /// }
        /// @endcode
        property_<string, readonly_> Name{
          get_ {return this->GetName();}
        };

        /// @brief Indicates whether the specified object is a FontFamily and is identical to this FontFamily.
        /// @param obj The object to test.
        /// @return true if obj is a FontFamily and is identical to this FontFamily; otherwise, false.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Creates two Font objects.
        /// * Tests whether they are equivalent.
        /// * Displays the result of the test in a message box.
        /// @code
        /// void Equals_Example(PaintEventArgs& e) {
        ///   // Create two FontFamily objects.
        ///   FontFamily firstFontFamily("Arial");
        ///   FontFamily secondFontFamily("Times New Roman");
        ///
        ///   // Check to see if the two font families are equivalent.
        ///   bool equalFonts = firstFontFamily.Equals(secondFontFamily);
        ///
        ///   // Display the result of the test in a message box.
        ///   MessageBox::Show(Boolean(equalFonts).ToString());
        /// }
        /// @endcode
        bool Equals(const object& obj) const override {return is<FontFamily>(obj) && this->Name == as<FontFamily>(obj).Name;}

        /// @brief Returns the cell ascent, in design units, of the FontFamily of the specified style.
        /// @param style A FontStyle that contains style information for the font.
        /// @return int32 The cell ascent for this FontFamily that uses the specified FontStyle.
        /// @warning Always throw NotImplementedExeption.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Creates a FontFamily.
        /// * Gets the cell ascent for that font family.
        /// * Draws the value of the cell ascent to the screen as text.
        /// @code
        /// void GetCellAscent_Example(PaintEventArgs& e) {
        ///   // Create a FontFamily object.
        ///   FontFamily ascentFontFamily("arial");
        ///
        ///   // Get the cell ascent of the font family in design units.
        ///   int cellAscent = ascentFontFamily.GetCellAscent(FontStyle::Regular);
        ///
        ///   // Draw the result as a string to the screen.
        ///   e.Graphics().DrawString(string::Format("ascentFontFamily.GetCellAscent() returns {0}.", cellAscent), Font(ascentFontFamily, 16), Brushes::Black, PointF(0, 0));
        /// }
        /// @endcode
        int32 GetCellAscent(FontStyle style);

        /// @brief Returns the cell descent, in design units, of the FontFamily of the specified style.
        /// @param style A FontStyle that contains style information for the font.
        /// @return int32 The cell descent for this FontFamily that uses the specified FontStyle.
        /// @warning Always throw NotImplementedExeption.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Creates a FontFamily.
        /// * Gets the cell descent for that font family.
        /// * Draws the value of the cell descent to the screen as text.
        /// @code
        /// void GetCellAscent_Example(PaintEventArgs& e) {
        ///   // Create a FontFamily object.
        ///   FontFamily descentFontFamily("arial");
        ///
        ///   // Get the cell ascent of the font family in design units.
        ///   int cellDescent = descentFontFamily.GetCellAscent(FontStyle::Regular);
        ///
        ///   // Draw the result as a string to the screen.
        ///   e.Graphics().DrawString(string::Format("descentFontFamily.GetCellDescent() returns {0}.", cellDescent), Font(descentFontFamily, 16), Brushes::Black, PointF(0, 0));
        /// }
        /// @endcode
        int32 GetCellDescent(FontStyle style);

        /// @brief Indicates whether the specified FontStyle enumeration is available.
        /// @param style The FontStyle to test.
        /// @return true if the specified FontStyle is available; otherwise, false.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code performs the following actions:
        /// * Creates a FontFamily.
        /// * Tests whether the font family is available in an italic font.
        /// * If it is, draws text to the screen.
        /// @code
        /// void IsStyleAvailable_Example(PaintEventArgs& e) {
        ///   // Create a FontFamily object.
        ///   FontFamily myFontFamily("Arial");
        ///
        ///   // Test whether myFontFamily is available in Italic.
        ///   if (myFontFamily.IsStyleAvailable(FontStyle::Italic)) {
        ///     // Create a Font object using myFontFamily.
        ///     Font familyFont(myFontFamily, 16, FontStyle::Italic);
        ///
        ///     // Use familyFont to draw text to the screen.
        ///     e.Graphics.DrawString(myFontFamily.Name + " is available in Italic", familyFont, Brushes::Black, PointF(0, 0));
        ///   }
        /// }
        /// @endcode
        bool IsStyleAvailable(FontStyle style) const;

        /// @brief Converts this FontFamily to a human-readable string representation.
        /// @return string The string that represents this FontFamily.
        /// @par Examples
        /// The following code example is designed for use with Windows Forms, and it requires PaintEventArgse, which is a parameter of the Paint event handler. The code creates a FontFamily and draws a string representation of the font family to the screen.
        /// @code
        /// void ToString_Example(PaintEventArgs& e) {
        ///   // Create a FontFamily object.
        ///   FontFamily myFontFamily("Arial");
        ///
        ///   // Draw a string representation of myFontFamily to the screen.
        ///   e.Graphics.DrawString(myFontFamily.ToString(), Font(myFontFamily, 16), Brushes::Black, PointF(0, 0));
        /// }
        /// @endcode
        String ToString() const override {return string::Format("[{0}: Name={1}]", this->GetType().Name, this->Name);}

      private:
        string GetName() const;
        struct FontFamilyData {
          intptr handle = 0;
        };
        $<FontFamilyData> data = new_<FontFamilyData>();
      };
    }
  }
}
