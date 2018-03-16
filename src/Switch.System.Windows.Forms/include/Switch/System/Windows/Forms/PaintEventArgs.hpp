/// @file
/// @brief Contains Switch::System::Windows::Forms::PaintEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/Graphics.hpp>
#include <Switch/System/Drawing/Rectangle.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "Keys.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        /// @par Library
        /// Switch.System.Windows.Forms
        class system_windows_forms_export_ PaintEventArgs : public EventArgs {
        public:
          PaintEventArgs() {}
          PaintEventArgs(const System::Drawing::Rectangle& clipRectangle, System::Drawing::Graphics& graphics) : clipRectangle(clipRectangle), graphics(&graphics) {}
          /// @cond
          PaintEventArgs(const PaintEventArgs& paintEventArgs) : clipRectangle(paintEventArgs.clipRectangle), graphics(paintEventArgs.graphics) {}
          PaintEventArgs& operator =(const PaintEventArgs& paintEventArgs) {
            this->clipRectangle = paintEventArgs.clipRectangle;
            this->graphics = paintEventArgs.graphics;
            return *this;
          }
          /// @endcond

          property_<const System::Drawing::Rectangle&, readonly_> ClipRectangle {
            get_->const System::Drawing::Rectangle& {return this->clipRectangle;}
          };

          property_<System::Drawing::Graphics&, readonly_> Graphics {
            get_->System::Drawing::Graphics& {return *this->graphics;}
          };

        private:
          System::Drawing::Rectangle clipRectangle;
          System::Drawing::Graphics* graphics = null;
        };
      }
    }
  }
}
