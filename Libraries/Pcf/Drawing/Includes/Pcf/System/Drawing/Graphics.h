/// @file
/// @brief Contains Pcf::System::Drawing::Graphics class.
#pragma once

#include <Pcf/System/Object.h>
#include <Pcf/System/String.h>
#include <Pcf/System/Convert.h>

#include "Brush.h"
#include "Color.h"
#include "Font.h"
#include "SolidBrush.h"
#include "Pen.h"
#include "Point.h"
#include "Rectangle.h"
#include "RectangleF.h"
#include "Size.h"
#include "SizeF.h"

namespace Pcf {
  namespace System {
    /// @cond
    namespace Windows {
      namespace Forms {
        class Control;
      }
    }
    /// @endcond
    
    namespace Drawing {
      enum class BoxType {
        Flat,
        Up,
        Down,
        ThinUp,
        ThinDown,
        Engraved,
        Embossed,
        Border,
        Shadow,
        Rounded,
        RoundedFlat,
        RoundedShadow,
        Oval,
        OvalFlat,
        OvalShadow,
        RoundUp,
        RoundDown,
        Diamond,
        DiamondUp,
        DiamondDown,
        PlasticUp,
        PlasticDown,
        PlasticThinUp,
        PlasticThinDown,
        PlasticRoundUp,
        PlasticRoundDown,
        GtkUp,
        GtkDown,
        GtkThinUp,
        GtkThinDown,
        GtkRoundUp,
        GtkRoundDown,
      };
      
      enum class FrameType {
        Up,
        Down,
        ThinUp,
        ThinDown,
        Engraved,
        Embossed,
        Border,
        Shadow,
        Rounded,
        Oval,
        PlasticUp,
        PlasticDown,
        GtkUp,
        GtkDown,
        GtkThinUp,
        GtkThinDown,
      };
      
      enum class StringAlignment {
        Near,
        Center,
        Far
      };
      
      class StringFormat {
      public:
        StringFormat() {}
        StringFormat(const StringFormat& stringFormat) : alignment(stringFormat.alignment), lineAlignment(stringFormat.lineAlignment) {}
        
        Property<StringAlignment> Alignment {
          pcf_get {return this->alignment;},
          pcf_set {this->alignment = value;}
        };
        
        Property<StringAlignment> LineAlignment {
          pcf_get {return this->lineAlignment;},
          pcf_set {this->lineAlignment = value;}
        };
        
      private:
        StringAlignment alignment = StringAlignment::Near;
        StringAlignment lineAlignment = StringAlignment::Near;
      };
      
      class Graphics : public Object {
      public:
        void Clear(const Color& color);

        void DrawArc(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle);

        void DrawArc(const Pen& pen, const Rectangle& rectangle, float startAngle, float sweepAngle) {this->DrawArc(pen, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height(), startAngle, sweepAngle);}

        void DrawBezier(const Pen& pen, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

        void DrawBezier(const Pen& pen, int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3, int32 x4, int32 y4) {this->DrawBezier(pen, Convert::ToDouble(x1), Convert::ToDouble(y1), Convert::ToDouble(x2), Convert::ToDouble(y2), Convert::ToDouble(x3), Convert::ToDouble(y3), Convert::ToDouble(x4), Convert::ToDouble(y4));}

        void DrawFrame(FrameType type, int32 x, int32 y, int32 w, int32 h);

        void DrawFrame(FrameType type, const Rectangle& r) {this->DrawFrame(type, r.Left(), r.Top(), r.Width(), r.Height());}
        
        void DrawEllipse(const Pen& pen, int32 x, int32 y, int32 w, int32 h) {this->DrawArc(pen, x, y, w, h, 0.0f, 360.0f);}

        void DrawEllipse(const Pen& pen, const Rectangle& rectangle) {this->DrawEllipse(pen, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height());}

        void DrawLine(const Pen& pen, Point p1, Point p2) {DrawLine(pen, p1.X, p1.Y, p2.X, p2.Y);}
        
        void DrawLine(const Pen& pen, int32 x1, int32 y1, int32 x2, int32 y2);
        
        void DrawPie(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle);

        void DrawPie(const Pen& pen, const Rectangle& rectangle, float startAngle, float sweepAngle) {this->DrawPie(pen, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height(), startAngle, sweepAngle);}

        void DrawRectangle(const Pen& pen, int32 x, int32 y, int32 w, int32 h);
        
        void DrawRectangle(const Pen& pen, const Rectangle& r) {this->DrawRectangle(pen, r.Left(), r.Top(), r.Width(), r.Height());}

        void FillEllipse(const Brush& brush, int32 x, int32 y, int32 w, int32 h) {this->FillPie(brush, x, y, w, h, 0.0f, 360.0f);}

        void FillEllipse(const Brush& brush, const Rectangle& rectangle) {this->DrawEllipse(brush, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height());}

        void DrawString(const string& str, const Font& font, const Brush& brush, const float x, float y) {
          SizeF size = MeasureString(str, font);
          DrawString(str, font, brush, RectangleF(x, y, size.Width, size.Height), StringFormat());
        }
        
        void DrawString(const string& str, const Font& font, const Brush& brush, const float x, float y, const StringFormat& format) {
          SizeF size = MeasureString(str, font);
          DrawString(str, font, brush, RectangleF(x, y, size.Width, size.Height), format);
        }
        
        void DrawString(const string& str, const Font& font, const Brush& brush, const RectangleF& layoutRectangle) {DrawString(str, font, brush, layoutRectangle, StringFormat());}
        
        void DrawString(const string& str, const Font& font, const Brush& brush, const RectangleF& layoutRectangle, const StringFormat& format);
        
        void FillBox(BoxType type, const Brush& brush, int32 x, int32 y, int32 w, int32 h);

        void FillBox(BoxType type, const Brush& brush, const Rectangle& r) {this->FillBox(type, brush, r.Left(), r.Top(), r.Width(), r.Height());}
        
        void FillPie(const Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle);

        void FillPie(const Brush& brush, const Rectangle& rectangle, float startAngle, float sweepAngle) {this->FillPie(brush, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height(), startAngle, sweepAngle);}

        void FillRectangle(const Brush& brush, int32 x, int32 y, int32 w, int32 h);

        void FillRectangle(const Brush& brush, const Rectangle& r) {this->FillRectangle(brush, r.Left(), r.Top(), r.Width(), r.Height());}

        SizeF MeasureString(const string& str, const Font& font) const;
        
      private:
        friend class Pcf::System::Windows::Forms::Control;
        Graphics() {}
        Graphics(const Graphics& graphics) : offset(graphics.offset), size(graphics.size) {}
        static void SetColor(const System::Drawing::Color& color);
        
        void Offset(const Point& offset) {
          this->offset = offset;
        }

        Point offset;
        Size size;
        /// @cond
        /// @endcond
      };
    }
  }
}
