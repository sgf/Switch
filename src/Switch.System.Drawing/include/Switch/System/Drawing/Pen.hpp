/// @file
/// @brief Contains Switch::System::Drawing::Pen class.
#pragma once

#include <Switch/System/Object.hpp>
#include "../../SystemDrawingExport.hpp"
#include "Drawing2D/DashStyle.hpp"
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
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ Pen : public object, public ICloneable {
      public:
        Pen() {}

        /// @cond
        ~Pen() { this->Destroy(); }
        Pen(const Pen& pen) : data(pen.data) { }
        Pen& operator=(const Pen&) = default;
        /// @endcond

        explicit Pen(const Brush& brush) {
          this->data->brush = as<System::Drawing::Brush>(brush.Clone());
          this->Create();
        }

        Pen(const Brush& brush, float width) {
          this->data->brush = as<System::Drawing::Brush>(brush.Clone());
          this->data->width = width;
          this->Create();
        }

        explicit Pen(System::Drawing::Color color) {
          this->data->brush = new_<SolidBrush>(color);
          this->Create();
        }

        Pen(System::Drawing::Color color, float width) {
          this->data->brush = new_<SolidBrush>(color);
          this->data->width = width;
          this->Create();
        }

        property_<const System::Drawing::Brush&> Brush{
          get_->const System::Drawing::Brush& { return *this->data->brush; },
          set_ {*this->data->brush = value; }
        };

        property_<System::Drawing::Color, readonly_> Color{
          get_{ return as<SolidBrush>(this->data->brush)->Color(); }
        };

        property_<System::Drawing::Drawing2D::DashStyle> DashStyle {
          get_ {return this->data->dashStyle;},
          set_ {
            if (this->data->dashStyle != value) {
              this->data->dashStyle = value;
              this->Create();
            }
          }
        };

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
          $<System::Drawing::Brush> brush  = as<System::Drawing::Brush>(new_<SolidBrush>(System::Drawing::Color::Black()));
          System::Drawing::Drawing2D::DashStyle dashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
          float width = 1.0f;
          intptr pen = IntPtr::Zero;
        };
        $<Data> data = new_<Data>();
      };
    }
  }
}
