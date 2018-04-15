/// @file
/// @brief Contains Switch::System::Windows::Forms::Form class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "Button.hpp"
#include "ContainerControl.hpp"
#include "DialogResult.hpp"
#include "FormBorderStyle.hpp"
#include "FormClosedEventHandler.hpp"
#include "FormClosingEventHandler.hpp"
#include "FormStartPosition.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a window or dialog box that makes up an application's user interface.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks A Form is a representation of any window displayed in your application. The Form class can be used to create standard, tool, borderless, and floating windows. You can also use the Form class to create modal windows such as a dialog box. A special kind of form, the multiple-document interface (MDI) form, can contain other forms called MDI child forms. An MDI form is created by setting the IsMdiContainer property to true. MDI child forms are created by setting the MdiParent property to the MDI parent form that will contain the child form.
        /// @remarks Using the properties available in the Form class, you can determine the appearance, size, color, and window management features of the window or dialog box you are creating. The Text property allows you to specify the caption of the window in the title bar. The Size and DesktopLocation properties allow you to define the size and position of the window when it is displayed. You can use the ForeColor color property to change the default foreground color of all controls placed on the form. The FormBorderStyle, MinimizeBox, and MaximizeBox properties allow you to control whether the form can be minimized, maximized, or resized at run time.
        /// @remarks In addition to properties, you can use the methods of the class to manipulate a form. For example, you can use the ShowDialog method to show a form as a modal dialog box. You can use the SetDesktopLocation method to position the form on the desktop.
        /// @remarks The events of the Form class allow you to respond to actions performed on the form. You can use the Activated event to perform operations such as updating the data displayed in the controls of the form when the form is activated.
        /// @remarks You can use a form as the starting class in your application by placing a method called Main in the class. In the Main method add code to create and show the form. You will also need to add the STAThread attribute to the Main method in order for the form to run. When the starting form is closed, the application is also closed.
        /// @remarks If you set the Enabled property to false before the Form is visible (for example, setting Enabled to false in the Microsoft Visual Studio designer), the minimize, maximize, close, and system buttons remain enabled. If you set Enabled to false after the Form is visible (for example, when the Load event occurs), the buttons are disabled.
        /// @par Example
        /// The following code example demonstrate the use of Form control.
        /// @code
        /// void CreateMyForm() {
        ///   // Create a new instance of the form.
        ///   Form form1;
        ///   // Create two buttons to use as the accept and cancel buttons.
        ///   Button button1;
        ///   Button button2;
        ///
        ///   // Set the text of button1 to "OK".
        ///   button1.Text = "OK";
        ///   // Set the position of the button on the form.
        ///   button1.Location = System::Drawing::Point(10, 10);
        ///   // Set the text of button2 to "Cancel".
        ///   button2.Text = "Cancel";
        ///   // Set the position of the button based on the location of button1.
        ///   button2.Location = System::Drawing::Point(button1.Left, button1.Height + button1.Top + 10);
        ///   // Set the caption bar text of the form.
        ///   form1.Text = "My Dialog Box";
        ///   // Display a help button on the form.
        ///   form1.HelpButton = true;
        ///
        ///   // Define the border style of the form to a dialog box.
        ///   form1.FormBorderStyle = FormBorderStyle::FixedDialog;
        ///   // Set the MaximizeBox to false to remove the maximize box.
        ///   form1.MaximizeBox = false;
        ///   // Set the MinimizeBox to false to remove the minimize box.
        ///   form1.MinimizeBox = false;
        ///   // Set the accept button of the form to button1.
        ///   form1.AcceptButton = button1;
        ///   // Set the cancel button of the form to button2.
        ///   form1.CancelButton = button2;
        ///   // Set the start position of the form to the center of the screen.
        ///   form1.StartPosition = FormStartPosition::CenterScreen;
        ///
        ///   // Add button1 to the form.
        ///   form1.Controls().Add(button1);
        ///   // Add button2 to the form.
        ///   form1.Controls().Add(button2);
        ///
        ///   // Display the form as a modal dialog box.
        ///   form1.ShowDialog();
        /// }
        /// @endcode
        class system_windows_forms_export_ Form : public ContainerControl {
        public:
          Form() : ContainerControl("", 0, 0, 300, 300) {
            this->visible = false;
            this->SetStyle(ControlStyles::UserPaint, false);
            //this->BackColor = System::Drawing::SystemColors::Window;
            this->cursor = DefaultCursor;
            this->font = DefaultFont;
          }

          /// @brief Gets or sets the button on the form that is clicked when the user presses the ENTER key.
          /// @return Button An IButtonControl that represents the button to use as the accept button for the form.
          property_<ref<System::Windows::Forms::Button>> AccpetButton {
            get_ {return this->acceptButton;},
            set_ {
              if (value != this->acceptButton) {
                if (this->acceptButton != null)
                  this->acceptButton().Click -= {*this, &Form::OnButtonAccecptClick};
                this->acceptButton = value;
                if (this->acceptButton != null)
                  this->acceptButton().Click += {*this, &Form::OnButtonAccecptClick};
              }
            }
          };

          property_<ref<System::Windows::Forms::Button>> CancelButton {
            get_ {return this->cancelButton;},
            set_ {
              if (value != this->cancelButton) {
                if (this->cancelButton != null)
                  this->cancelButton().Click -= {*this, &Form::OnButtonCancelClick};
                this->cancelButton = value;
                if (this->cancelButton != null)
                  this->cancelButton().Click += {*this, &Form::OnButtonCancelClick};
              }
            }
          };

          property_<System::Windows::Forms::FormBorderStyle> FormBorderStyle {
            get_{return this->formBorderStyle;},
            set_{this->formBorderStyle = value;}
          };

          property_<System::Windows::Forms::DialogResult> DialogResult {
            get_{return this->dialogResult;},
            set_{this->dialogResult = value;}
          };

          property_<bool> MaximizeBox {
            get_ {return this->maximizeBox;},
            set_ {this->maximizeBox = value;}
          };

          property_<bool> MinimizeBox {
            get_ {return this->minimizeBox;},
            set_ {this->minimizeBox = value;}
          };

          property_<FormStartPosition> StartPosition{
            get_{return this->startPosition;},
            set_{this->startPosition = value;}
          };

          void CenterToScreen();

          void Close() override;

          System::Windows::Forms::DialogResult ShowDialog() const;

          void WndProc(Message& message) override;

          FormClosedEventHandler FormClosed;

          FormClosingEventHandler FormClosing;

        protected:
          /// @brief Creates a handle for the control
          /// @remarks You typically should not call the CreateHandle method directly. The preferred method is to call the CreateControl method, which forces a handle to be created for the control and its child controls when the control is created.
          /// @par Notes to Inheritors
          /// When overriding CreateHandle in a derived class, be sure to call the base class's CreateHandle method to ensure that the handle is created.
          void CreateHandle() override;

          /// @brief Gets the default size of the control.
          /// @return Switch::System::Drawing::Size The default Size of the control.
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(300, 300); }

          virtual void OnFormClosed(const FormClosedEventArgs& e) {
            this->Visible = false;
            this->FormClosed(*this, e);
          }
          virtual void OnFormClosing(FormClosingEventArgs& e) { this->FormClosing(*this, e); }

          /// @cond
          System::Windows::Forms::FormBorderStyle formBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
          bool maximizeBox = true;
          bool minimizeBox = true;
          System::Windows::Forms::FormStartPosition startPosition = FormStartPosition::WindowsDefaultLocation;
          System::Collections::Generic::Dictionary<int32, Action<Message&>> messageActions;
          /// @endcond

        private:
          void OnButtonAccecptClick(const object& sender, const EventArgs& e) {
            this->dialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
          }

          void OnButtonCancelClick(const object& sender, const EventArgs& e) {
            this->dialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Close();
          }

          void WmClose(Message& message);
          System::Windows::Forms::DialogResult dialogResult = DialogResult::Cancel;
          ref<Button> acceptButton;
          ref<Button> cancelButton;
        };
      }
    }
  }
}
