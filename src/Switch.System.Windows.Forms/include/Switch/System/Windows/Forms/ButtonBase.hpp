/// @file
/// @brief Contains Switch::System::Windows::Forms::ButtonBase class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "Control.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Implements the basic functionality common to button controls.
        /// @remarks You do not typically inherit from ButtonBase. To create your own button class, inherit from the Button, CheckBox, or RadioButton class.
        /// @remarks To have the derived button control display an image, set the Image property or the ImageList and ImageIndex properties. The image can be aligned on the button control by setting the ImageAlign property. Likewise, to align the Text displayed on the button control, set the TextAlign property.
        /// @remarks The FlatStyle property determines the style and appearance of the control. If the FlatStyle property is set to FlatStyle.System, the user's operating system determines the appearance of the control.
        class system_windows_forms_export_ ButtonBase : public Control {
        public:
          /// @brief Initializes a new instance of the ButtonBase class.
          ButtonBase() {}

          /// @cond
          ButtonBase(const string& text, int32 left, int32 top, int32 height, int32 width) : Control(text, left, top, height, width) {}
          /// @endcond

          /// @brief Gets or sets a value indicating whether the ellipsis character (...) appears at the right edge of the control, denoting that the control text extends beyond the specified length of the control.
          /// @return bool true if the additional label text is to be indicated by an ellipsis; otherwise, false. The default is true.
          /// @remarks Set AutoEllipsis to true to display text that extends beyond the width of the control when the user passes over the control with the mouse. You must set the control's AutoSize property to false if you want AutoEllipsis to be true. If AutoSize is true, the control will grow to fit the text and an ellipsis will not appear.
          property_<bool> AutoElispis {
            get_ {return this->autoElipsis;},
            set_ {this->autoElipsis = value;}
          };

          /// @cond
          bool autoElipsis = false;
          /// @endcond
        };
      }
    }
  }
}
