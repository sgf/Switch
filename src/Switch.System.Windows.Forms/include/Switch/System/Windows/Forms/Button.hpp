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
        /// @par Library
        /// Switch.System.Windows.Forms
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
          /// @par Examples
          /// The following code example creates a Button, sets its DialogResult property to the OK value of DialogResult, and adds it to a Form.
          /// @code
          /// $<Button> button1;
          ///
          /// void InitializeMyButton() {
          ///   // Create and initialize a Button.
          ///   this->button1 = new_<Button>();
          ///
          ///   // Set the button to return a value of OK when clicked.
          ///   this->button1->DialogResult = DialogResult::OK;
          ///
          ///   // Add the button to the form.
          ///   this->Controls().Add(*this->button1);
          /// }
          /// @endcode
          Button() : ButtonBase("", 0, 0, 75, 25) {
            this->SetStyle(ControlStyles::UserPaint, false);
          }

        protected:
          /// @brief Creates a handle for the control
          /// @remarks You typically should not call the CreateHandle method directly. The preferred method is to call the CreateControl method, which forces a handle to be created for the control and its child controls when the control is created.
          /// @par Notes to Inheritors
          /// When overriding CreateHandle in a derived class, be sure to call the base class's CreateHandle method to ensure that the handle is created.
          void CreateHandle() override;

          /// @brief Gets the default size of the control.
          /// @return System::Drawing::Size The default Size of the control.
          /// @remarks The DefaultSize property represents the Size of the control when it is initially created. You can adjust the size of the control by setting its Size property value.
          /// @note To maintain better performance, do not set the Size of a control in its constructor. The preferred method is to override the DefaultSize property.
          /// @par Notes to Inheritors
          /// Override GetDefaultsize() method used by DefaultSize property.
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(75, 25); }

          /// @cond
          /// @endcond
        };
      }
    }
  }
}
