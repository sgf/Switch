/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include <Switch/System/Drawing/ContentAlignment.hpp>
#include "Control.hpp"
#include "BorderStyle.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a standard Windows label.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks Label controls are typically used to provide descriptive text for a control. For example, you can use a Label to add descriptive text for a TextBox control to inform the user about the type of data expected in the control. Label controls can also be used to add descriptive text to a Form to provide the user with helpful information. For example, you can add a Label to the top of a Form that provides instructions to the user on how to input data in the controls on the form. Label controls can be also used to display run time information on the status of an application. For example, you can add a Label control to a form to display the status of each file as a list of files is processed.
        /// @remarks A Label participates in the tab order of a form, but does not receive focus (the next control in the tab order receives focus). For example, if the UseMnemonic property is set to true, and a mnemonic character�the first character after an ampersand (&)�is specified in the Text property of the control, when a user presses ALT+ the mnemonic key, focus moves to the next control in the tab order. This feature provides keyboard navigation for a form. In addition to displaying text, the Label control can also display an image using the Image property, or a combination of the ImageIndex and ImageList properties.
        /// @note A Label can be made transparent by setting its BackColor property to Color.Transparent. When you use a transparent label, use only the current device coordinate system to draw on the container, or the Label background might paint improperly.
        /// @par Example
        /// The following code example demonstrate the use of Label control.
        /// @include Label.cpp
        class system_windows_forms_export_ Label : public Control {
        public:
          Label() {
            this->SetStyle(ControlStyles::UserPaint, false);
            this->TabStop = false;
          }

          property_<System::Windows::Forms::BorderStyle> BorderStyle {
            get_{return this->borderStyle;},
            set_{this->SetBorderStyle(value);}
          };

          property_<System::Drawing::ContentAlignment> TextAlign {
            get_{return this->textAlign;},
            set_{this->SetTextAlign(value);}
          };

        protected:
          /// @brief Creates a handle for the control
          /// @remarks You typically should not call the CreateHandle method directly. The preferred method is to call the CreateControl method, which forces a handle to be created for the control and its child controls when the control is created.
          /// @par Notes to Inheritors
          /// When overriding CreateHandle in a derived class, be sure to call the base class's CreateHandle method to ensure that the handle is created.
          void CreateHandle() override;

          /// @brief Gets the default size of the control.
          /// @return Switch::System::Drawing::Size The default Size of the control.
          System::Drawing::Size GetDefaultSize() const override;

          virtual void SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle);
          virtual void SetTextAlign(System::Drawing::ContentAlignment textAlign);

          /// @cond
          System::Windows::Forms::BorderStyle borderStyle = System::Windows::Forms::BorderStyle::None;
          System::Drawing::ContentAlignment textAlign = System::Drawing::ContentAlignment::TopLeft;
          /// @endcond
        };
      }
    }
  }
}
