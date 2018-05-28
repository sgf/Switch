/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

#include <Switch/System/ComponentModel/InvalidEnumArgumentException.hpp>
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
        /// @brief Represents a Windows CheckBox.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks Use a CheckBox to give the user an option, such as true/false or yes/no. The CheckBox control can display an image or text or both.
        /// @remarks CheckBox and RadioButton controls have a similar function: they allow the user to choose from a list of options. CheckBox controls let the user pick a combination of options. In contrast, RadioButton controls allow a user to choose from mutually exclusive options.
        /// @remarks The Appearance property determines whether the CheckBox appears as a typical CheckBox or as a button.
        /// @remarks The ThreeState property determines whether the control supports two or three states. Use the Checked property to get or set the value of a two-state CheckBox control and use the CheckState property to get or set the value of a three-state CheckBox control.
        /// @note If the ThreeState property is set to true, the Checked property will return true for either a checked or indeterminate state.
        /// @remarks The FlatStyle property determines the style and appearance of the control. If the FlatStyle property is set to FlatStyle.System, the user's operating system determines the appearance of the control.
        /// @note When the FlatStyle property is set to FlatStyle.System, the CheckAlign property is ignored and the control is displayed using the ContentAlignment.MiddleLeft or ContentAlignment.MiddleRight alignment. If the CheckAlign property is set to one of the right alignments, the control is displayed using the ContentAlignment.MiddleRight alignment; otherwise, it is displayed using the ContentAlignment.MiddleLeft alignment.
        /// @remarks The following describes an indeterminate state: You have a CheckBox that determines if the selected text in a RichTextBox is bold. When you select text you can click the CheckBox to bold the selection. Likewise, when you select some text, the CheckBox displays whether the selected text is bold. If your selected text contains text that is bold and normal, the CheckBox will have an indeterminate state.
        /// @par Example
        /// The following code example demonstrate the use of CheckBox control.
        /// @include CheckBox.cpp
        class system_windows_forms_export_ CheckBox : public ButtonBase {
        public:
          /// @brief Initializes a new instance of the CheckBox class.
          /// @brief By default, when a new CheckBox is instantiated, AutoCheck is set to true, Checked is set to false, and Appearance is set to Normal.
          /// @par Example
          /// The following code example creates and initializes a CheckBox, gives it the appearance of a toggle button, sets AutoCheck to false, and adds it to a Form.
          /// @code
          /// // Create and initialize a CheckBox.
          /// CheckBox checkBox1;
          ///
          /// void InstantiateMyCheckBox() {
          ///   // Make the check box control appear as a toggle button.
          ///   this->checkBox1.Appearance = Appearance::Button;
          ///
          ///   // Turn off the update of the display on the click of the control.
          ///   this->checkBox1.AutoCheck = false;
          ///
          ///   // Add the check box control to the form.
          ///   this->Controls().Add(this->checkBox1);
          /// }
          /// @endcode
          CheckBox() { this->SetStyle(ControlStyles::UserPaint, false); }

          /// @brief Gets or set a value indicating whether the Checked or CheckState values and the CheckBox's appearance are automatically changed when the CheckBox is clicked.
          /// @return bool true if the Checked value or CheckState value and the appearance of the control are automatically changed on the Click event; otherwise, false. The default value is true.
          /// @remarks If AutoCheck is set to false, you will need to add code to update the Checked or CheckState values in the Click event handler.
          /// @par Example
          /// The following code example creates and initializes a CheckBox, gives it the appearance of a toggle button, sets AutoCheck to false, and adds it to a Form.
          /// @code
          /// // Create and initialize a CheckBox.
          /// CheckBox checkBox1;
          ///
          /// void InstantiateMyCheckBox() {
          ///   // Make the check box control appear as a toggle button.
          ///   this->checkBox1.Appearance = Appearance::Button;
          ///
          ///   // Turn off the update of the display on the click of the control.
          ///   this->checkBox1.AutoCheck = false;
          ///
          ///   // Add the check box control to the form.
          ///   this->Controls().Add(this->checkBox1);
          /// }
          /// @endcode
          property_<bool> AutoCheck {
            get_{ return this->autoCheck; },
            set_{ this->SetAutoCheck(value); }
          };

          /// @brief Gets or sets a value indicating whether the CheckBox is in the checked state.
          /// @return bool true if the CheckBox is in the checked state; otherwise, false. The default value is false.
          /// @note If the ThreeState property is set to true, the Checked property will return true for either a Checked or IndeterminateCheckState.
          /// @remarks When the value is true, the CheckBox portion of the control displays a check mark. If the Appearance property is set to Button, the control will appear sunken when Checked is true and raised like a standard button when false.
          /// @par Examples
          /// The following code example displays the values of three properties in a label. The ThreeState property alternates between true and false with alternating clicks of the control and the CheckAlign alternates between a ContentAlignment value of MiddleRight and MiddleLeft. This example shows how the property values change as the ThreeState property changes and the control is checked. This example requires that a CheckBox, Label and Button have all been instantiated on a form and that the label is large enough to display three lines of text, as well as a reference to the System.Drawing namespace. This code should be called in the Click event handler of the control.
          /// @code
          /// void AdjustMyCheckBoxProperties() {
          ///   // Change the ThreeState and CheckAlign properties on every other click.
          ///   if (!checkBox1.ThreeState) {
          ///     checkBox1.ThreeState = true;
          ///     checkBox1.CheckAlign = ContentAlignment::MiddleRight;
          ///   } else {
          ///     checkBox1.ThreeState = false;
          ///     checkBox1.CheckAlign = ContentAlignment::MiddleLeft;
          ///   }
          ///
          ///   // Concatenate the property values together on three lines.
          ///   label1.Text = "ThreeState: " + Boolean(checkBox1.ThreeState).ToString() + "\n" +
          ///                 "Checked: " + Boolean(checkBox1.Checked).ToString() + "\n" +
          ///                 "CheckState: " + Enum<CheckState>(checkBox1.CheckState).ToString();
          /// }
          /// @endcode
          property_<bool> Checked {
            get_ {return this->CheckState != System::Windows::Forms::CheckState::Unchecked;},
            set_ {
              if (this->Checked != value)
                this->CheckState = value ? System::Windows::Forms::CheckState::Checked : System::Windows::Forms::CheckState::Unchecked;
            }
          };

          /// @brief Gets or sets the state of the CheckBox.
          /// @return Switch::System::Windows::Forms::CheckState One of the CheckState enumeration values. The default value is Switch::System::Windows::Forms::CheckState::Unchecked.
          /// @exception InvalidEnumArgumentException The value assigned is not one of the CheckState enumeration values.
          /// @remarks If the ThreeState property is set to false, the CheckState property value can only be set to CheckState.Indeterminate in code and not by user interaction.
          /// @remarks The following table describes the System.Windows.Forms.Appearance of the CheckBox control in its different states for the Normal and Button style control CheckBox.Appearance.
          /// | CheckState    | Appearance::Normal                                | Appearance::Button          |
          /// |---------------|---------------------------------------------------|-----------------------------|
          /// | Checked       | The CheckBox displays a check mark.               | The control appears sunken. |
          /// | Unchecked     | The CheckBox is empty.                            | The control appears raised. |
          /// | Indeterminate | The CheckBox displays a check mark and is shaded. | The control appears flat.   |
          /// @par Examples
          /// The following code example displays the values of three properties in a label. The ThreeState property alternates between true and false with alternating clicks of the control and the CheckAlign alternates between a ContentAlignment value of MiddleRight and MiddleLeft. This example shows how the property values change as the ThreeState property changes and the control is checked. This example requires that a CheckBox, Label and Button have all been instantiated on a form and that the label is large enough to display three lines of text, as well as a reference to the System.Drawing namespace. This code should be called in the Click event handler of the control.
          /// @code
          /// void AdjustMyCheckBoxProperties() {
          ///   // Change the ThreeState and CheckAlign properties on every other click.
          ///   if (!checkBox1.ThreeState) {
          ///     checkBox1.ThreeState = true;
          ///     checkBox1.CheckAlign = ContentAlignment::MiddleRight;
          ///   } else {
          ///     checkBox1.ThreeState = false;
          ///     checkBox1.CheckAlign = ContentAlignment::MiddleLeft;
          ///   }
          ///
          ///   // Concatenate the property values together on three lines.
          ///   label1.Text = "ThreeState: " + Boolean(checkBox1.ThreeState).ToString() + "\n" +
          ///                 "Checked: " + Boolean(checkBox1.Checked).ToString() + "\n" +
          ///                 "CheckState: " + Enum<CheckState>(checkBox1.CheckState).ToString();
          /// }
          /// @endcode
          property_<System::Windows::Forms::CheckState> CheckState {
            get_ {return this->checkState;},
            set_ {
              if (value != System::Windows::Forms::CheckState::Checked && value != System::Windows::Forms::CheckState::Indeterminate && value != System::Windows::Forms::CheckState::Unchecked)
                throw System::ComponentModel::InvalidEnumArgumentException(caller_);
              this->SetCheckState(value);}
          };

          /// @brief Occurs when the value of the Checked property changes.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Example
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the CheckedChanged event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
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
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the CheckStateChanged event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
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
          /// @par Example
          /// The following code example creates and initializes a CheckBox, gives it the appearance of a toggle button, sets AutoCheck to false, and adds it to a Form.
          /// @code
          /// // Create and initialize a CheckBox.
          /// CheckBox checkBox1;
          ///
          /// void InstantiateMyCheckBox() {
          ///   // Make the check box control appear as a toggle button.
          ///   this->checkBox1.Appearance = Appearance::Button;
          ///
          ///   // Turn off the update of the display on the click of the control.
          ///   this->checkBox1.AutoCheck = false;
          ///
          ///   // Add the check box control to the form.
          ///   this->Controls().Add(this->checkBox1);
          /// }
          /// @endcode
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
          /// @par Examples
          /// The following code example displays the values of three properties in a label. The ThreeState property alternates between true and false with alternating clicks of the control and the CheckAlign alternates between a ContentAlignment value of MiddleRight and MiddleLeft. This example shows how the property values change as the ThreeState property changes and the control is checked. This example requires that a CheckBox, Label and Button have all been instantiated on a form and that the label is large enough to display three lines of text, as well as a reference to the System.Drawing namespace. This code should be called in the Click event handler of the control.
          /// @code
          /// void AdjustMyCheckBoxProperties() {
          ///   // Change the ThreeState and CheckAlign properties on every other click.
          ///   if (!checkBox1.ThreeState) {
          ///     checkBox1.ThreeState = true;
          ///     checkBox1.CheckAlign = ContentAlignment::MiddleRight;
          ///   } else {
          ///     checkBox1.ThreeState = false;
          ///     checkBox1.CheckAlign = ContentAlignment::MiddleLeft;
          ///   }
          ///
          ///   // Concatenate the property values together on three lines.
          ///   label1.Text = "ThreeState: " + Boolean(checkBox1.ThreeState).ToString() + "\n" +
          ///                 "Checked: " + Boolean(checkBox1.Checked).ToString() + "\n" +
          ///                 "CheckState: " + Enum<CheckState>(checkBox1.CheckState).ToString();
          /// }
          /// @endcode
          void SetCheckState(System::Windows::Forms::CheckState checkState);

          /// @brief Gets the default size of the control.
          /// @return System::Drawing::Size The default Size of the control.
          /// @remarks The DefaultSize property represents the Size of the control when it is initially created. You can adjust the size of the control by setting its Size property value.
          /// @note To maintain better performance, do not set the Size of a control in its constructor. The preferred method is to override the DefaultSize property.
          /// @par Notes to Inheritors
          /// Override GetDefaultsize() method used by DefaultSize property.
          System::Drawing::Size GetDefaultSize() const override;

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
          virtual void OnCheckStateChanged(const EventArgs& e) {this->CheckStateChanged(*this, e);}

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
