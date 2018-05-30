/// @file
/// @brief Contains Switch::System::Drawing::Pen class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/ComponentModel/InvalidEnumArgumentException.hpp>
#include "../../SystemDrawingExport.hpp"
#include "Drawing2D/DashCap.hpp"
#include "Drawing2D/DashStyle.hpp"
#include "Drawing2D/LineCap.hpp"
#include "Drawing2D/PenAlignment.hpp"
#include "Drawing2D/PenType.hpp"
#include "Brush.hpp"
#include "SolidBrush.hpp"
#include "Color.hpp"

/// @cond
namespace Native {
  class GdiApi;
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    namespace Windows {
      namespace Forms {
        class Control;
      }
    }
    /// @endcond

    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
      /// @par Library
      /// Switch.System.Drawing
      /// @remarks A Pen draws a line of specified width and style. Use the DashStyle property to draw several varieties of dashed lines. The line drawn by a Pen can be filled in a variety of fill styles, including solid colors and textures. The fill style depends on brush or texture that is used as the fill object.
      /// @par Examples
      /// The following code example demonstrates constructing a Pen with a Brush and the effects of setting the LineJoin property on a Pen.<br><br>
      /// This example is designed to be used with Windows Forms. Paste the code into a form and call the ShowLineJoin method when handling the form's Paint event, passing e as PaintEventArgs.
      /// @code
      /// void ShowLineJoin(PaintEventArgs& e) {
      ///   // Create a new pen.
      ///   Pen skyBluePen(Brushes::DeepSkyBlue);
      ///
      ///   // Set the pen's width.
      ///   skyBluePen.Width = 8.0f;
      ///
      ///   // Set the LineJoin property.
      ///   skyBluePen.LineJoin = System::Drawing::Drawing2D::LineJoin::Bevel;
      ///
      ///   // Draw a rectangle.
      ///   e.Graphics().DrawRectangle(skyBluePen, Rectangle(40, 40, 150, 200));
      /// }
      /// @endcode
      class system_drawing_export_ Pen final : public ICloneable, public object {
      public:
        /// @cond
        Pen() {}
        ~Pen() {
          if (this->data.IsUnique())
            this->Destroy();
        }
        Pen(const Pen& pen) : data(pen.data) { }
        Pen& operator=(const Pen&) = default;
        /// @endcond

        /// @brief Initializes a new instance of the Pen class with the specified Brush.
        /// @param brush A Brush that determines the fill properties of this Pen.
        /// @remarks The Brush property determines how the Pen draws lines. Lines are drawn as if they are filled rectangles, with the characteristics of the specified Brush.
        /// @remarks The Width property of the new Pen is set to 1 (the default).
        /// @par Examples
        /// The following code example demonstrates constructing a Pen with a Brush and the effects of setting the LineJoin property on a Pen.<br><br>
        /// This example is designed to be used with Windows Forms. Paste the code into a form and call the ShowLineJoin method when handling the form's Paint event, passing e as PaintEventArgs.
        /// @code
        /// void ShowLineJoin(PaintEventArgs& e) {
        ///   // Create a new pen.
        ///   Pen skyBluePen(Brushes::DeepSkyBlue);
        ///
        ///   // Set the pen's width.
        ///   skyBluePen.Width = 8.0f;
        ///
        ///   // Set the LineJoin property.
        ///   skyBluePen.LineJoin = System::Drawing::Drawing2D::LineJoin::Bevel;
        ///
        ///   // Draw a rectangle.
        ///   e.Graphics().DrawRectangle(skyBluePen, Rectangle(40, 40, 150, 200));
        /// }
        /// @endcode
        explicit Pen(const System::Drawing::Brush& brush) {
          this->data->brush = as<System::Drawing::Brush>(brush.Clone());
          this->Create();
        }

        /// @brief Initializes a new instance of the Pen class with the specified Brush and Width.
        /// @param brush A Brush that determines the characteristics of this Pen.
        /// @param width The width of the new Pen.
        /// @remarks The Brush is set to the color specified in the brush parameter, the Width property is set to the value specified in the width parameter, and the units are set to World.
        /// @remarks Note that the brush parameter also specifies the Color property of this Pen.
        /// @remarks A width of 0 will result in the Pen drawing as if the width were 1.
        /// @par Examples
        /// The following code example creates a Pen and demonstrates the effects of setting the StartCap and EndCap properties on a Pen.<br><br>
        /// This example is designed to be used with Windows Forms. Paste the code into a form and call the ShowStartAndEndCaps method when handling the form's Paint event, passing e as PaintEventArgs.
        /// @code
        /// void Button3_Click(const System::Object& sender, const System::EventArgs& e) {
        ///
        ///   Graphics buttonGraphics = button3.CreateGraphics();
        ///   Pen myPen(Color::ForestGreen, 4.0f);
        ///   myPen.DashStyle = System::Drawing::Drawing2D.DashStyle::DashDotDot;
        ///
        ///   Rectangle theRectangle = button3.ClientRectangle;
        ///   theRectangle.Inflate(-2, -2);
        ///   buttonGraphics.DrawRectangle(myPen, theRectangle);
        /// }
        /// @endcode
        Pen(const System::Drawing::Brush& brush, float width) {
          this->data->brush = as<System::Drawing::Brush>(brush.Clone());
          this->data->width = width;
          this->Create();
        }

        /// @brief Initializes a new instance of the Pen class with the specified color.
        /// @param color A Color structure that indicates the color of this Pen.
        /// @remarks The Color property is set to the color specified by the color parameter. The Width property is set to 1 (the default).
        explicit Pen(System::Drawing::Color color) {
          this->data->brush = new_<SolidBrush>(color);
          this->Create();
        }

        /// @brief Initializes a new instance of the Pen class with the specified Color and Width properties.
        /// @param color A Color structure that indicates the color of this Pen.
        /// @param width A value indicating the width of this Pen.
        /// @remarks The Color property is set to the color specified by the color parameter. The Width property is set to the value specified in the width parameter. A width of 0 will result in the Pen drawing as if the width were 1.
        /// @par Examples
        /// The following code example demonstrates creating a Pen and the effects of setting the DashCap, DashPattern, and SmoothingMode properties.<br><br>
        /// This example is designed to be used with Windows Forms. Paste the code into a form and call the ShowPensAndSmoothingMode method when handling the form's Paint event, passing e as PaintEventArgs.
        /// @code
        /// void ShowPensAndSmoothingMode(PaintEventArgs& e) {
        ///   // Set the SmoothingMode property to smooth the line.
        ///   e.Graphics().SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
        ///
        ///   // Create a new Pen object.
        ///   Pen greenPen(Color.Green);
        ///
        ///   // Set the width to 6.
        ///   greenPen.Width = 6.0f;
        ///
        ///   // Set the DashCap to round.
        ///   greenPen.DashCap = System::Drawing::Drawing2D::DashCap::Round;
        ///
        ///   // Create a custom dash pattern.
        ///   greenPen.DashPattern = {4.0f, 2.0f, 1.0f, 3.0f};
        ///
        ///   // Draw a line.
        ///   e.Graphics().DrawLine(greenPen, 20.0f, 20.0f, 100.0f, 240.0f);
        ///
        ///   // Change the SmoothingMode to none.
        ///   e.Graphics().SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::None;
        ///
        ///   // Draw another line.
        ///   e.Graphics().DrawLine(greenPen, 100.0f, 240.0f, 160.0f, 20.0f);
        /// }
        /// @endcode
        Pen(System::Drawing::Color color, float width) {
          this->data->brush = new_<SolidBrush>(color);
          this->data->width = width;
          this->Create();
        }

        /// @brief Gets or sets the alignment for this Pen.
        /// @return A PenAlignment that represents the alignment for this Pen.
        /// @exception InvalidEnumArgumentException The specified value is not a member of PenAlignment.
        /// @remarks This property determines how the Pen draws closed curves and polygons. The PenAlignment enumeration specifies five values; however, only two values—Center and Inset—will change the appearance of a drawn line. Center is the default value for this property and specifies that the width of the pen is centered on the outline of the curve or polygon. A value of Inset for this property specifies that the width of the pen is inside the outline of the curve or polygon. The other three values, Right, Left, and Outset, will result in a pen that is centered.
        /// @remarks A Pen that has its alignment set to Inset will yield unreliable results, sometimes drawing in the inset position and sometimes in the centered position. Also, an inset pen cannot be used to draw compound lines and cannot draw dashed lines with Triangle dash caps.
        property_<System::Drawing::Drawing2D::PenAlignment> Alignment {
          get_ {return this->data->alignment;},
          set_ {
            if (!Enum<>::IsDefined<System::Drawing::Drawing2D::PenAlignment>(value))
              throw System::ComponentModel::InvalidEnumArgumentException(caller_);
            if (this->data->alignment != value) {
              this->data->alignment = value;
              this->Create();
            }
          }
        };

        /// @brief Gets or sets the Brush that determines attributes of this Pen.
        /// @return A Brush that determines attributes of this Pen.
        /// @remarks Assigning this property causes the pen to draw filled lines and curves. It overrides the Color property of the Pen.
        property_<const System::Drawing::Brush&> Brush{
          get_->const System::Drawing::Brush& { return *this->data->brush; },
          set_ {
            this->data->brush = as<System::Drawing::Brush>(value.Clone());}
        };

        /// @brief Gets or sets the color of this Pen.
        /// @return A Color structure that represents the color of this Pen.
        property_<System::Drawing::Color> Color{
          get_ {return as<SolidBrush>(this->data->brush)->Color();},
          set_ {this->data->brush = new_<SolidBrush>(value);}
        };

        /// @brief Gets or sets an array of values that specifies a compound pen. A compound pen draws a compound line made up of parallel lines and spaces.
        /// @return An array of real numbers that specifies the compound array. The elements in the array must be in increasing order, not less than 0, and not greater than 1.
        /// @remarks A compound line is made up of alternating parallel lines and spaces of varying widths. The values in the array specify the starting points of each component of the compound line relative to the pen's width. The first value in the array specifies where the first component (a line) begins as a fraction of the distance across the width of the pen. The second value in the array specifies the beginning of the next component (a space) as a fraction of the distance across the width of the pen. The final value in the array specifies where the last component ends.
        /// @remarks Suppose you want a pen to draw two parallel lines where the width of the first line is 20 percent of the pen's width, the width of the space that separates the two lines is 50 percent of the pen' s width, and the width of the second line is 30 percent of the pen's width. Start by creating a Pen and an array of real numbers. Set the compound array by passing the array with the values 0.0, 0.2, 0.7, and 1.0 to this property.
        /// @remakers Do not set this property if the Pen has its Alignment property set to Inset.
        property_<Array<float>> CompoundArray {
          get_ {return this->data->compoundArray;},
          set_ {this->data->compoundArray = value;}
        };

        /// @brief Gets or sets the cap style used at the end of the dashes that make up dashed lines drawn with this Pen.
        /// @return One of the DashCap values that represents the cap style used at the beginning and end of the dashes that make up dashed lines drawn with this Pen.
        /// @exception InvalidEnumArgumentException The specified value is not a member of DashCap.
        /// @remarks Do not set this property to Triangle if the Pen has its Alignment property set to Inset.
        /// @par Examples
        /// The following code example demonstrates creating a Pen and the effects of setting the DashCap, DashPattern, and SmoothingMode properties.<br><br>
        /// This example is designed to be used with Windows Forms. Paste the code into a form and call the ShowPensAndSmoothingMode method when handling the form's Paint event, passing e as PaintEventArgs.
        /// @code
        /// void ShowPensAndSmoothingMode(PaintEventArgs& e) {
        ///   // Set the SmoothingMode property to smooth the line.
        ///   e.Graphics().SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
        ///
        ///   // Create a new Pen object.
        ///   Pen greenPe(Color.Green);
        ///
        ///   // Set the width to 6.
        ///   greenPen.Width = 6.0f;
        ///
        ///   // Set the DashCap to round.
        ///   greenPen.DashCap = System::Drawing::Drawing2D::DashCap::Round;
        ///
        ///   // Create a custom dash pattern.
        ///   greenPen.DashPattern = {4.0f, 2.0f, 1.0f, 3.0f};
        ///
        ///   // Draw a line.
        ///   e.Graphics().DrawLine(greenPen, 20.0f, 20.0f, 100.0f, 240.0f);
        ///
        ///   // Change the SmoothingMode to none.
        ///   e.Graphics().SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::None;
        ///
        ///   // Draw another line.
        ///   e.Graphics().DrawLine(greenPen, 100.0f, 240.0f, 160.0f, 20.0f);
        /// }
        /// @endcode
        property_<System::Drawing::Drawing2D::DashCap> DashCap {
          get_ {return this->data->dashCap;},
          set_ {
            if (!Enum<>::IsDefined<System::Drawing::Drawing2D::DashCap>(value))
              throw System::ComponentModel::InvalidEnumArgumentException(caller_);
            this->data->dashCap = value;
          }
        };

        /// @brief Gets or sets the distance from the start of a line to the beginning of a dash pattern.
        /// @return The distance from the start of a line to the beginning of a dash pattern.
        property_<float> DashOffset {
          get_ {return this->data->dashOffset;},
          set_ {this->data->dashOffset = value;}
        };

        /// @brief Gets or sets an array of custom dashes and spaces.
        /// @return An array of real numbers that specifies the lengths of alternating dashes and spaces in dashed lines.
        /// @remarks Assigning a value other than empty to this property will set the DashStyle property for this Pen to Custom.
        /// @remarks The elements in the dashArray array set the length of each dash and space in the dash pattern. The first element sets the length of a dash, the second element sets the length of a space, the third element sets the length of a dash, and so on. Consequently, each element should be a non-zero positive number.
        /// @remarks The length of each dash and space in the dash pattern is the product of the element value in the array and the width of the Pen.
        /// @par Examples
        /// The following code example demonstrates creating a Pen and the effects of setting the DashCap, DashPattern, and SmoothingMode properties.<br><br>
        /// This example is designed to be used with Windows Forms. Paste the code into a form and call the ShowPensAndSmoothingMode method when handling the form's Paint event, passing e as PaintEventArgs.
        /// @code
        /// void ShowPensAndSmoothingMode(PaintEventArgs& e) {
        ///   // Set the SmoothingMode property to smooth the line.
        ///   e.Graphics().SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
        ///
        ///   // Create a new Pen object.
        ///   Pen greenPe(Color.Green);
        ///
        ///   // Set the width to 6.
        ///   greenPen.Width = 6.0f;
        ///
        ///   // Set the DashCap to round.
        ///   greenPen.DashCap = System::Drawing::Drawing2D::DashCap::Round;
        ///
        ///   // Create a custom dash pattern.
        ///   greenPen.DashPattern = {4.0f, 2.0f, 1.0f, 3.0f};
        ///
        ///   // Draw a line.
        ///   e.Graphics().DrawLine(greenPen, 20.0f, 20.0f, 100.0f, 240.0f);
        ///
        ///   // Change the SmoothingMode to none.
        ///   e.Graphics().SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::None;
        ///
        ///   // Draw another line.
        ///   e.Graphics().DrawLine(greenPen, 100.0f, 240.0f, 160.0f, 20.0f);
        /// }
        /// @endcode
        property_<Array<float>> DashPattern {
          get_ {return this->data->dashPattern;},
          set_ {this->data->dashPattern = value;}
        };

        /// @brief Gets or sets the style used for dashed lines drawn with this Pen.
        /// @return A DashStyle that represents the style used for dashed lines drawn with this Pen.
        /// @remarks A value of Custom for this property specifies that a custom pattern of dashes and spaces, defined by the DashPattern property, makes up lines drawn with this Pen. If the value of this property is Custom and the value of the DashPattern property is null, the pen draws solid lines.
        property_<System::Drawing::Drawing2D::DashStyle> DashStyle {
          get_ {return this->data->dashStyle;},
          set_ {
            if (!Enum<>::IsDefined<System::Drawing::Drawing2D::DashStyle>(value))
              throw System::ComponentModel::InvalidEnumArgumentException(caller_);
            if (this->data->dashStyle != value) {
              this->data->dashStyle = value;
              this->Create();
            }
          }
        };

        /// @brief Gets or sets the cap style used at the end of lines drawn with this Pen.
        /// @return One of the LineCap values that represents the cap style used at the end of lines drawn with this Pen.
        /// @exception InvalidEnumArgumentException The specified value is not a member of LineCap.
        /// @par Examples
        /// The following code example demonstrates the effects of setting the StartCap and EndCap properties on a Pen.<br><br>
        /// This example is designed to be used with Windows Forms. Paste the code into a form and call the ShowStartAndEndCaps method when handling the form's Paint event, passing e as PaintEventArgs.
        /// @code
        /// void ShowStartAndEndCaps(PaintEventArgs& e) {
        ///   // Create a new custom pen.
        ///   Pen redPen(Brushes.Red, 6.0f);
        ///
        ///   // Set the StartCap property.
        ///   redPen.StartCap = System::Drawing::Drawing2D::LineCap::RoundAnchor;
        ///
        ///   // Set the EndCap property.
        ///   redPen.EndCap = System.Drawing::Drawing2D::LineCap::ArrowAnchor;
        ///
        ///   // Draw a line.
        ///   e.Graphics().DrawLine(redPen, 40.0f, 40.0f, 145.0f, 185.0f);
        /// }
        /// @endcode
        property_<System::Drawing::Drawing2D::LineCap> EndCap {
          get_ {return this->data->endCap;},
          set_ {
            if (!Enum<>::IsDefined<System::Drawing::Drawing2D::LineCap>(value))
              throw System::ComponentModel::InvalidEnumArgumentException(caller_);
            if (this->data->endCap != value)
              this->data->endCap = value;
          }
        };

        /// @brief Gets the style of lines drawn with this Pen.
        /// @return A PenType enumeration that specifies the style of lines drawn with this Pen.
        /// @remarks A Pen can draw solid lines, filled lines, or textured lines, depending on the style specified by a member of the PenType enumeration.
        property_<System::Drawing::Drawing2D::PenType, readonly_> PenType {
          get_ {
            if (is<SolidBrush>(this->data->brush)) return System::Drawing::Drawing2D::PenType::SolidColor;
            return System::Drawing::Drawing2D::PenType::SolidColor;
          }
        };

        /// @brief Gets or sets the cap style used at the beginning of lines drawn with this Pen.
        /// @return One of the LineCap values that represents the cap style used at the end of lines drawn with this Pen.
        /// @exception InvalidEnumArgumentException The specified value is not a member of LineCap.
        /// @par Examples
        /// The following code example demonstrates the effects of setting the StartCap and EndCap properties on a Pen.<br><br>
        /// This example is designed to be used with Windows Forms. Paste the code into a form and call the ShowStartAndEndCaps method when handling the form's Paint event, passing e as PaintEventArgs.
        /// @code
        /// void ShowStartAndEndCaps(PaintEventArgs& e) {
        ///   // Create a new custom pen.
        ///   Pen redPen(Brushes.Red, 6.0f);
        ///
        ///   // Set the StartCap property.
        ///   redPen.StartCap = System::Drawing::Drawing2D::LineCap::RoundAnchor;
        ///
        ///   // Set the EndCap property.
        ///   redPen.EndCap = System.Drawing::Drawing2D::LineCap::ArrowAnchor;
        ///
        ///   // Draw a line.
        ///   e.Graphics().DrawLine(redPen, 40.0f, 40.0f, 145.0f, 185.0f);
        /// }
        /// @endcode
        property_<System::Drawing::Drawing2D::LineCap> StartCap {
          get_ {return this->data->startCap;},
          set_ {
            if (!Enum<>::IsDefined<System::Drawing::Drawing2D::LineCap>(value))
              throw System::ComponentModel::InvalidEnumArgumentException(caller_);
            if (this->data->startCap != value)
              this->data->startCap = value;
          }
        };

        /// @brief Gets or sets the width of this Pen, in units of the Graphics object used for drawing.
        /// @return The width of this Pen.
        /// @remarks You can access the unit of measure of the Graphics object using its PageUnit property. The unit of measure is typically pixels. A Width of 0 will result in the Pen drawing as if the Width were 1.
        /// @par Examples
        /// The following code example demonstrates constructing a Pen with a Brush and the effects of setting the LineJoin property on a Pen.<br><br>
        /// This example is designed to be used with Windows Forms. Paste the code into a form and call the ShowLineJoin method when handling the form's Paint event, passing e as PaintEventArgs.
        /// @code
        /// void ShowLineJoin(PaintEventArgs& e) {
        ///   // Create a new pen.
        ///   Pen skyBluePen(Brushes::DeepSkyBlue);
        ///
        ///   // Set the pen's width.
        ///   skyBluePen.Width = 8.0f;
        ///
        ///   // Set the LineJoin property.
        ///   skyBluePen.LineJoin = System::Drawing::Drawing2D::LineJoin::Bevel;
        ///
        ///   // Draw a rectangle.
        ///   e.Graphics().DrawRectangle(skyBluePen, Rectangle(40, 40, 150, 200));
        /// }
        /// @endcode
        property_<float> Width{
          get_ {return this->data->width;},
          set_ {this->data->width = value;}
        };

        /// @brief Creates an exact copy of this Pen object.
        /// @return The Pen object that this method creates.
        $<object> Clone() const override {return new_<Pen>(*this->data->brush, this->data->width);}

      private:
        friend class Native::GdiApi;
        friend class Windows::Forms::Control;
        intptr GetNativePen() const { return this->data->pen; }
        void Create();
        void Destroy();
        struct Data {
          System::Drawing::Drawing2D::PenAlignment alignment = System::Drawing::Drawing2D::PenAlignment::Center;
          $<System::Drawing::Brush> brush = as<System::Drawing::Brush>(new_<SolidBrush>(System::Drawing::Color::Black()));
          Array<float> compoundArray;
          System::Drawing::Drawing2D::DashCap dashCap = System::Drawing::Drawing2D::DashCap::Flat;
          float dashOffset = 0.0f;
          Array<float> dashPattern;
          System::Drawing::Drawing2D::DashStyle dashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
          System::Drawing::Drawing2D::LineCap endCap = System::Drawing::Drawing2D::LineCap::Flat;
          System::Drawing::Drawing2D::LineCap startCap = System::Drawing::Drawing2D::LineCap::Flat;
          float width = 1.0f;
          intptr pen = IntPtr::Zero;
        };
        $<Data> data = new_<Data>();
      };
    }
  }
}
