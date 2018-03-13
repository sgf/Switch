/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

#include <Switch/System/Environment.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "ButtonBase.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a Windows button control.
        /// @remarks A Button can be clicked by using the mouse, ENTER key, or SPACEBAR if the button has focus.
        /// @remarks Set the AcceptButton or CancelButton property of a Form to allow users to click a button by pressing the ENTER or ESC keys even if the button does not have focus. This gives the form the behavior of a dialog box.
        /// @remarks When you display a form using the ShowDialog method, you can use the DialogResult property of a button to specify the return value of ShowDialog.
        /// @remarks You can change the button's appearance. For example, to make it appear flat for a Web look, set the FlatStyle property to FlatStyle.Flat. The FlatStyle property can also be set to FlatStyle.Popup, which appears flat until the mouse pointer passes over the button; then the button takes on the standard Windows button appearance.
        /// @note If the control that has focus accepts and processes the ENTER key press, the Button does not process it. For example, if a multiline TextBox or another button has focus, that control processes the ENTER key press instead of the accept button.
        /// @par Example
        /// The following code example demonstrate the use of Button control.
        /// @include Button.cpp
        class system_windows_forms_export_ Button : public ButtonBase {
        public:
          /// @brief Initializes a new instance of the Button class.
          /// @remarks By default the Button displays no caption. To specify the caption text, set the Text property.
          Button() : ButtonBase("", 0, 0, 75, 25) {
            this->SetStyle(ControlStyles::UserPaint, false);
          }

          /// @brief Gets or sets a value indicating whether the button control is the default button.(Inherited from ButtonBase.)
          /// @return bool true if the button control is the default button; otherwise, false.
          /// @remarks When the IsDefault property is set to true, the button is the default button for the Form. This means that the button is clicked when the ENTER key is pressed if no other button or any other control that captures the ENTER key has focus.
          /// @remarks To specify the default button of a form, set the AcceptButton property of the form to the desired button.
          property_<bool> IsDefault {
            get_ {return this->isDefault;},
            set_ {this->SetIsDefault(value);}
          };

        protected:
          /// @brief Creates a handle for the control
          /// @remarks You typically should not call the CreateHandle method directly. The preferred method is to call the CreateControl method, which forces a handle to be created for the control and its child controls when the control is created.
          /// @par Notes to Inheritors
          /// When overriding CreateHandle in a derived class, be sure to call the base class's CreateHandle method to ensure that the handle is created.
          void CreateHandle() override;

          /// @brief Gets the default size of the control.
          /// @return Switch::System::Drawing::Size The default Size of the control.
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(75, 25); }

          /// @cond
          void SetIsDefault(bool isDefault);

          bool isDefault = false;
          /// @endcond
        };
      }
    }
  }
}
