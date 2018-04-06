/// @file
/// @brief Contains Switch::System::Drawing::CharacterRange class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/Property.hpp>
#include "../../SystemDrawingExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Specifies a range of character positions within a string.
      /// @par Library
      /// Switch.System.Drawing
      /// @par Examples
      /// The following code example demonstrates how to create a CharacterRange and use it to highlight part of a string. This example is designed to be used with Windows Forms. Paste the example into a form and call the HighlightACharacterRange method when handling the form's Paint event, passing e as PaintEventArgs.
      /// @code
      /// void HighlightACharacterRange(PaintEventArgs& e) {
      ///   // Declare the string to draw.
      ///   string message = "This is the string to highlight a word in.";
      ///
      ///   // Declare the word to highlight.
      ///   string searchWord = "string";
      ///
      ///   // Create a CharacterRange array with the searchWord
      ///   // location and length.
      ///   Array<CharacterRange> ranges = {CharacterRange(message.IndexOf(searchWord), searchWord.Length)};
      ///
      ///   // Construct a StringFormat object.
      ///   StringFormat stringFormat1;
      ///
      ///   // Set the ranges on the StringFormat object.
      ///   stringFormat1.SetMeasurableCharacterRanges(ranges);
      ///
      ///   // Declare the font to write the message in.
      ///   Font largeFont(FontFamily::GenericSansSerif, 16.0f, GraphicsUnit::Pixel);
      ///
      ///   // Construct a new Rectangle.
      ///   Rectangle displayRectangle(20, 20, 200, 100);
      ///
      ///   // Convert the Rectangle to a RectangleF.
      ///   RectangleF displayRectangleF = displayRectangle;
      ///
      ///   // Get the Region to highlight by calling the
      ///   // MeasureCharacterRanges method.
      ///   Array<Region> charRegion = e.Graphics().MeasureCharacterRanges(message, largeFont, displayRectangleF, stringFormat1);
      ///
      ///   // Draw the message string on the form.
      ///   e.Graphics().DrawString(message, largeFont, Brushes.Blue, displayRectangleF);
      ///
      ///   // Fill in the region using a semi-transparent color.
      ///   e.Graphics().FillRegion(new SolidBrush(Color::FromArgb(50, Color.Fuchsia)), charRegion[0]);
      /// }
      /// @endcode
      struct system_drawing_export_ CharacterRange : public object {
      public:
        /// @brief Initializes a new instance of the CharacterRange structure, specifying a range of character positions within a string.
        /// @param first The position of the first character in the range. For example, if First is set to 0, the first position of the range is position 0 in the string.
        /// @param length The number of positions in the range.
        /// @par Examples
        /// The following code example demonstrates how to create a CharacterRange and use it to highlight part of a string. This example is designed to be used with Windows Forms. Paste the example into a form and call the HighlightACharacterRange method when handling the form's Paint event, passing e as PaintEventArgs.
        /// @code
        /// void HighlightACharacterRange(PaintEventArgs& e) {
        ///   // Declare the string to draw.
        ///   string message = "This is the string to highlight a word in.";
        ///
        ///   // Declare the word to highlight.
        ///   string searchWord = "string";
        ///
        ///   // Create a CharacterRange array with the searchWord
        ///   // location and length.
        ///   Array<CharacterRange> ranges = {CharacterRange(message.IndexOf(searchWord), searchWord.Length)};
        ///
        ///   // Construct a StringFormat object.
        ///   StringFormat stringFormat1;
        ///
        ///   // Set the ranges on the StringFormat object.
        ///   stringFormat1.SetMeasurableCharacterRanges(ranges);
        ///
        ///   // Declare the font to write the message in.
        ///   Font largeFont(FontFamily::GenericSansSerif, 16.0f, GraphicsUnit::Pixel);
        ///
        ///   // Construct a new Rectangle.
        ///   Rectangle displayRectangle(20, 20, 200, 100);
        ///
        ///   // Convert the Rectangle to a RectangleF.
        ///   RectangleF displayRectangleF = displayRectangle;
        ///
        ///   // Get the Region to highlight by calling the
        ///   // MeasureCharacterRanges method.
        ///   Array<Region> charRegion = e.Graphics().MeasureCharacterRanges(message, largeFont, displayRectangleF, stringFormat1);
        ///
        ///   // Draw the message string on the form.
        ///   e.Graphics().DrawString(message, largeFont, Brushes.Blue, displayRectangleF);
        ///
        ///   // Fill in the region using a semi-transparent color.
        ///   e.Graphics().FillRegion(new SolidBrush(Color::FromArgb(50, Color.Fuchsia)), charRegion[0]);
        /// }
        /// @endcode
        CharacterRange(int32 first, int32 length) : first(first), length(length) {}

        /// @cond
        CharacterRange() {}
        CharacterRange(const CharacterRange& characterRange) : first(characterRange.first), length(characterRange.length) {}
        CharacterRange& operator =(const CharacterRange& characterRange) = default;
        /// @endcond

        /// @brief Gets or sets the position in the string of the first character of this CharacterRange.
        /// @return The first position of this CharacterRange.
        property_<int32> First {
          get_ {return this->first;},
          set_ {this->first = value;}
        };

        /// @brief Gets or sets the number of positions in this CharacterRange.
        /// @return The number of positions in this CharacterRange.
        property_<int32> Length {
          get_ {return this->length;},
          set_ {this->length = value;}
        };

        /// @brief Determines whether this instance of CharacterRange and a specified object, which must also be a CharacterRange object, have the same value.
        /// @param obj The CharacterRange to compare with the current object.
        /// @return bool true if the specified obj is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override {return is<CharacterRange>(obj) && Equals(as<CharacterRange>(obj));}

        /// @brief Determines whether this instance of CharacterRange and a specified object, which must also be a CharacterRange object, have the same value.
        /// @param value The CharacterRange to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        virtual bool Equals(const CharacterRange& value) const {return this->first == value.first && this->length == value.length;}

      private:
        int32 first = 0;
        int32 length = 0;
      };
    }
  }
}
