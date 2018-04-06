/// @file
/// @brief Contains Switch::System::Drawing::SolidBrush class.
#pragma once

#include "../../SystemDrawingExport.hpp"
#include "Brush.hpp"
#include "Color.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Defines a brush of a single color. Brushes are used to fill graphics shapes, such as rectangles, ellipses, pies, polygons, and paths. This class cannot be inherited.
      /// @par Library
      /// Switch.System.Drawing
      /// @remarks This class inherits from the Brush class.
      /// @par Examples
      /// * The following code example adds a shadow to a ListBox using a SolidBrush.
      /// <br>This example is designed to be used with a Windows Form. To run this example, paste this code into a form and call the AddShadow method when handling the form's Paint event. Make sure the form contains a ListBox named listBox1.
      /// @code
      /// void AddShadow(PaintEventArgs& e) {
      ///   // Create two SizeF objects.
      ///   SizeF shadowSize = listBox1.Size;
      ///   SizeF addSize(10.5F, 20.8F);
      ///
      ///   // Add them together and save the result in shadowSize.
      ///   shadowSize = shadowSize + addSize;
      ///
      ///   // Get the location of the ListBox and convert it to a PointF.
      ///   PointF shadowLocation = listBox1.Location;
      ///
      ///   // Add two points to get a new location.
      ///   shadowLocation = shadowLocation + Size(5, 5);
      ///
      ///   // Create a rectangleF.
      ///   RectangleF rectFToFill(shadowLocation, shadowSize);
      ///
      ///   // Create a custom brush using a semi-transparent color, and
      ///   // then fill in the rectangle.
      ///   Color customColor = Color::FromArgb(50, Color.Gray);
      ///   SolidBrush shadowBrush(customColor);
      ///   e.Graphics().FillRectangles(shadowBrush, Array<RectangleF> {rectFToFill});
      /// }
      /// @endcode
      class system_drawing_export_ SolidBrush final : public Brush {
      public:
        /// @brief Initializes a new SolidBrush object of the specified color.
        /// @param color A Color structure that represents the color of this brush.
        /// @par Examples
        /// * The following code example adds a shadow to a ListBox using a SolidBrush.
        /// <br>This example is designed to be used with a Windows Form. To run this example, paste this code into a form and call the AddShadow method when handling the form's Paint event. Make sure the form contains a ListBox named listBox1.
        /// @code
        /// void AddShadow(PaintEventArgs& e) {
        ///   // Create two SizeF objects.
        ///   SizeF shadowSize = listBox1.Size;
        ///   SizeF addSize(10.5F, 20.8F);
        ///
        ///   // Add them together and save the result in shadowSize.
        ///   shadowSize = shadowSize + addSize;
        ///
        ///   // Get the location of the ListBox and convert it to a PointF.
        ///   PointF shadowLocation = listBox1.Location;
        ///
        ///   // Add two points to get a new location.
        ///   shadowLocation = shadowLocation + Size(5, 5);
        ///
        ///   // Create a rectangleF.
        ///   RectangleF rectFToFill(shadowLocation, shadowSize);
        ///
        ///   // Create a custom brush using a semi-transparent color, and
        ///   // then fill in the rectangle.
        ///   Color customColor = Color::FromArgb(50, Color.Gray);
        ///   SolidBrush shadowBrush(customColor);
        ///   e.Graphics().FillRectangles(shadowBrush, Array<RectangleF> {rectFToFill});
        /// }
        /// @endcode
        explicit SolidBrush(const System::Drawing::Color& color);

        /// @cond
        SolidBrush(const SolidBrush& brush) : color(brush.color) {}
        SolidBrush& operator=(const SolidBrush& brush) = default;
        ~SolidBrush();
        /// @endcond

        /// @brief Gets or sets the color of this SolidBrush object.
        /// @return A Color structure that represents the color of this brush.
        /// @exception ArgumentEception The Color property is set on an immutable SolidBrush.
        property_<System::Drawing::Color> Color {
          get_ {return *this->color;},
          set_ {this->SetColor(value);}
        };

        /// @brief Creates an exact copy of this SolidBrush object.
        /// @return The SolidBrush object that this method creates.
        $<object> Clone() const override {return new_<SolidBrush>(*this->color);}

      private:
        void SetColor(const System::Drawing::Color& color);
        $<System::Drawing::Color> color = new_<System::Drawing::Color>(System::Drawing::Color::Black);
      };
    }
  }
}
