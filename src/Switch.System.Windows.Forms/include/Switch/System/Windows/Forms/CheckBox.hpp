/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "ButtonBase.hpp"
#include "CheckState.hpp"

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
        class system_windows_forms_export_ CheckBox : public ButtonBase {
        public:
          /// @brief Initializes a new instance of the CheckBox class.
          /// @brief By default, when a new CheckBox is instantiated, AutoCheck is set to true, Checked is set to false, and Appearance is set to Normal.
          /// @par Example
          /// The following code example demonstrate the use of CheckBox control.
          /// @include CheckBox.cpp
          CheckBox() : ButtonBase("", 0, 0, 104, 24) { this->SetStyle(ControlStyles::UserPaint, false); }

          /// @brief Gets or set a value indicating whether the Checked or CheckState values and the CheckBox's appearance are automatically changed when the CheckBox is clicked.
          /// @return bool true if the Checked value or CheckState value and the appearance of the control are automatically changed on the Click event; otherwise, false. The default value is true.
          /// @remarks If AutoCheck is set to false, you will need to add code to update the Checked or CheckState values in the Click event handler.
          property_<bool> AutoCheck {
            get_{ return this->autoCheck; },
            set_{ this->SetAutoCheck(value); }
          };

          /// @brief Gets or sets a value indicating whether the CheckBox is in the checked state.
          /// @return bool true if the CheckBox is in the checked state; otherwise, false. The default value is false.
          /// @note If the ThreeState property is set to true, the Checked property will return true for either a Checked or IndeterminateCheckState.
          /// @remarks When the value is true, the CheckBox portion of the control displays a check mark. If the Appearance property is set to Button, the control will appear sunken when Checked is true and raised like a standard button when false.
          property_<bool> Checked {
            get_ {return this->CheckState != System::Windows::Forms::CheckState::Unchecked;},
            set_ {
              if (this->Checked != value)
                this->CheckState = value ? System::Windows::Forms::CheckState::Checked : System::Windows::Forms::CheckState::Unchecked;
            }
          };

          /// @brief Gets or sets the state of the CheckBox.
          /// @return Switch::System::Windows::Forms::CheckState One of the CheckState enumeration values. The default value is Switch::System::Windows::Forms::CheckState::Unchecked.
          /// @remarks f the ThreeState property is set to false, the CheckState property value can only be set to CheckState.Indeterminate in code and not by user interaction.
          /// @remarks The following table describes the System.Windows.Forms.Appearance of the CheckBox control in its different states for the Normal and Button style control CheckBox.Appearance.
          /// | CheckState    | Appearance::Normal                                | Appearance::Button          |
          /// |---------------|---------------------------------------------------|-----------------------------|
          /// | Checked       | The CheckBox displays a check mark.               | The control appears sunken. |
          /// | Unchecked     | The CheckBox is empty.                            | The control appears raised. |
          /// | Indeterminate | The CheckBox displays a check mark and is shaded. | The control appears flat.   |
          property_<System::Windows::Forms::CheckState> CheckState {
            get_ {return this->checkState;},
            set_ {this->SetCheckState(value);}
          };

          /// @brief Occurs when the value of the Checked property changes.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Example
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the CheckedChanged event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          ///
          /// To run the example code, paste it into a project that contains an instance of type CheckBox named CheckBox1. Then ensure that the event handler is associated with the CheckedChanged event.
          /// @code
          /// void CheckBox1_CheckedChanged(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the CheckBox.CheckedChanged event.");
          /// }
          /// @endcode
          EventHandler CheckedChanged;

          /// @brief Occurs when the value of the CheckState property changes.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Example
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the CheckStateChanged event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          ///
          /// To run the example code, paste it into a project that contains an instance of type CheckBox named CheckBox1. Then ensure that the event handler is associated with the CheckStateChanged event.
          /// @code
          /// void CheckBox1_CheckStateChanged(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the CheckBox.CheckStateChanged event.");
          /// }
          /// @endcode
          EventHandler CheckStateChanged;

        protected:
          /// @brief Creates a handle for the control
          /// @remarks You typically should not call the CreateHandle method directly. The preferred method is to call the CreateControl method, which forces a handle to be created for the control and its child controls when the control is created.
          /// @par Notes to Inheritors
          /// When overriding CreateHandle in a derived class, be sure to call the base class's CreateHandle method to ensure that the handle is created.
          void CreateHandle() override;

          /// @brief Sets a value indicating whether the Checked or CheckState values and the CheckBox's appearance are automatically changed when the CheckBox is clicked.
          /// @param autocheck true if the Checked value or CheckState value and the appearance of the control are automatically changed on the Click event; otherwise, false. The default value is true.
          /// @remarks If AutoCheck is set to false, you will need to add code to update the Checked or CheckState values in the Click event handler.
          void SetAutoCheck(bool autoCheck);

          /// @brief Sets the state of the CheckBox.
          /// @param checkState One of the CheckState enumeration values. The default value is Switch::System::Windows::Forms::CheckState::Unchecked.
          /// @remarks f the ThreeState property is set to false, the CheckState property value can only be set to CheckState.Indeterminate in code and not by user interaction.
          /// @remarks The following table describes the System.Windows.Forms.Appearance of the CheckBox control in its different states for the Normal and Button style control CheckBox.Appearance.
          /// | CheckState    | Appearance::Normal                                | Appearance::Button          |
          /// |---------------|---------------------------------------------------|-----------------------------|
          /// | Checked       | The CheckBox displays a check mark.               | The control appears sunken. |
          /// | Unchecked     | The CheckBox is empty.                            | The control appears raised. |
          /// | Indeterminate | The CheckBox displays a check mark and is shaded. | The control appears flat.   |
          void SetCheckState(System::Windows::Forms::CheckState checkState);

          /// @brief Gets the default size of the control.
          /// @return Switch::System::Drawing::Size The default Size of the control.
          System::Drawing::Size GetDefaultSize() const override {return System::Drawing::Size(104, 24);}

          /// @brief Raises the CheckedChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnCheckedChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnCheckedChanged in a derived class, be sure to call the base class's OnCheckedChanged method so that registered delegates receive the event.
          virtual void OnCheckedChanged(const EventArgs& e) {this->CheckedChanged(*this, e);}

          /// @brief Raises the CheckStateChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnCheckStateChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnCheckStateChanged in a derived class, be sure to call the base class's OnCheckStateChanged method so that registered delegates receive the event.
          virtual void OnCheckStateChanged(const EventArgs& e) {this->CheckedChanged(*this, e);}

          /// @brief Raises the Click event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks The OnClick method changes the CheckState property. If the ThreeState property is set to true, subsequent clicks of the CheckBox will result in OnClick cycling through all the values of the CheckState enumeration. Otherwise, OnClick switches between Checked and Unchecked.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnClick method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnClick in a derived class, be sure to call the base class’s OnClick method so that registered delegates receive the event.
          void OnClick(const EventArgs& e) override {
            if (this->AutoCheck)
              this->Checked = !this->Checked;
            this->Control::OnClick(e);
          }

          /// @cond
          bool autoCheck = true;
          System::Windows::Forms::CheckState checkState = System::Windows::Forms::CheckState::Unchecked;
          /// @endcond
        };
      }
    }
  }
}
