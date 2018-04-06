/// @file
/// @brief Contains Switch::System::Drawing::Brush class.
#pragma once

#include <Switch/System/IntPtr.hpp>
#include <Switch/System/Object.hpp>
#include "../../SystemDrawingExport.hpp"

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
      /// @brief Defines objects used to fill the interiors of graphical shapes such as rectangles, ellipses, pies, polygons, and paths.
      /// @par Library
      /// Switch.System.Drawing
      /// @remarks This is an abstract base class and cannot be instantiated. To create a brush object, use classes derived from Brush, such as SolidBrush, TextureBrush, and LinearGradientBrush.
      /// @par Notes to Inheritors
      /// When you inherit from the Brush class, you must override the Clone method.
      class system_drawing_export_ Brush : public object, public ICloneable {
      public:
        /// @cond
        Brush(const Brush& brush) = default;
        Brush& operator=(const Brush& brush) = default;
        /// @endcond

        /// @brief When overridden in a derived class, creates an exact copy of this Brush.
        /// @return The new Brush that this method creates.
        virtual $<Object> Clone() const = 0;

      protected:
        /// @brief Initializes a new instance of the Brush class.
        Brush() {}

        /// @brief In a derived class, sets a reference to a GDI+ brush object.
        /// @param brush A pointer to the GDI+ brush object.
        void SetNativeBrush(intptr brush) {*this->brush = brush;}

        /// @cond
        friend class Native::GdiApi;
        friend class Windows::Forms::Control;

        intptr GetNativeBrush() const { return *this->brush; }

        $<intptr> brush = new_<intptr>();
        /// @endcond
      };
    }
  }
}
