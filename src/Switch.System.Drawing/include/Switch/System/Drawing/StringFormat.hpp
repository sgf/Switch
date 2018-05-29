/// @file
/// @brief Contains Switch::System::Drawing::Graphics class.
#pragma once

#include <Switch/System/Object.hpp>
#include "StringAlignment.hpp"

namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ StringFormat : public Object {
      public:
        StringFormat() {}
        StringFormat(const StringFormat& stringFormat) : alignment(stringFormat.alignment), lineAlignment(stringFormat.lineAlignment) {}
        StringFormat& operator=(const StringFormat&) = default;

        property_<StringAlignment> Alignment {
          get_ {return this->alignment;},
          set_ {this->alignment = value;}
        };

        property_<StringAlignment> LineAlignment {
          get_ {return this->lineAlignment;},
          set_ {this->lineAlignment = value;}
        };

      private:
        StringAlignment alignment = StringAlignment::Near;
        StringAlignment lineAlignment = StringAlignment::Near;
      };
    }
  }
}
