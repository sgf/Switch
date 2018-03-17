/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include <Switch/Abstract.hpp>
#include <Switch/Static.hpp>
#include <Switch/System/ComponentModel/Component.hpp>
#include <Switch/System/EventHandler.hpp>
#include "../../../System/Windows/Forms/DialogResult.hpp"
#include "../../../System/Windows/Forms/IWin32Window.hpp"
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies the base class used for displaying dialog boxes on the screen.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks Inherited classes are required to implement RunDialog by invoking ShowDialog to create a specific common dialog box. Inherited classes can optionally override HookProc to implement specific dialog box hook functionality.
        /// @par Examples
        /// The following code example uses the ColorDialog implementation of CommonDialog and illustrates creating and showing a dialog box. This example requires that the method is called from within an existing form, which has a TextBox and Button placed on it.
        /// @code
        /// void button1_Click(const object& sender, const System::EventArgs& e) {
        ///   ColorDialog MyDialog;
        ///   // Keeps the user from selecting a custom color.
        ///   MyDialog.AllowFullOpen = false ;
        ///   // Allows the user to get help. (The default is false.)
        ///   MyDialog.ShowHelp = true ;
        ///   // Sets the initial color select to the current text color.
        ///   MyDialog.Color = textBox1.ForeColor ;
        ///
        ///   // Update the text box color if the user clicks OK
        ///   if (MyDialog.ShowDialog() == DialogResult::OK)
        ///     textBox1.ForeColor =  MyDialog.Color;
        /// }
        /// @endcode
        class system_windows_forms_export_ CommonDialog : public System::ComponentModel::Component {
        public:
          /// @brief Initializes a new instance of the CommonDialog class.
          CommonDialog() {}

          /// @brief Gets or sets an object that contains data about the control.
          /// @return object The object that contains data about the CommonDialog.
          /// @remarks Use this property to store arbitrary information about the control.
          property_ < ref<object >> Tag {
            get_ {return this->tag;},
            set_ {this->tag = value;}
          };

          /// @brief Occurs when the user clicks the Help button on a common dialog box.
          /// @remarks For information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates initializing a ColorDialog object setting the AnyColor, AllowFullOpen properties. The ColorDialog object does not allow the user to set a custom color, but it allows the full set of basic colors to be displayed. By setting the SolidColorOnly property to false, it allows the display of colors that are combinations of other colors on systems with 256 or less colors. The example also shows setting the ShowHelp property and handling a HelpRequest event for a dialog box. To run the example, paste the following code in a form and call the InitializeColorDialog method in the form's constructor or Load method. This example requires that the Click event of the button is connected to the event handler defined in the example.
          /// @code
          /// ColorDialog colorDialog1;
          ///
          /// // This method initializes ColorDialog1 to allow any colors,
          /// // and combination colors on systems with 256 colors or less,
          /// // but will not allow the user to set custom colors.  The
          /// // dialog will contain the help button.
          /// void InitializeColorDialog() {
          ///   this->colorDialog1.AllowFullOpen = false;
          ///   this->colorDialog1.AnyColor = true;
          ///   this->colorDialog1.SolidColorOnly = false;
          ///   this->colorDialog1.ShowHelp = true;
          ///
          ///   // Associate the event-handling method with
          ///   // the HelpRequest event.
          ///   this->colorDialog1.HelpRequest += System::EventHandler(*this, &Form1::ColorDialog1_HelpRequest);
          /// }
          ///
          /// // This method opens the dialog and checks the DialogResult value.
          /// // If the result is OK, the text box's background color will be changed
          /// // to the user-selected color.
          /// void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
          ///   DialogResult result = this->colorDialog1.ShowDialog();
          ///   if (result == DialogResult::OK) {
          ///     TextBox1.BackColor = this->colorDialog1.Color;
          ///   }
          /// }
          ///
          /// // This method is called when the HelpRequest event is raised,
          /// // which occurs when the user clicks the Help button on the ColorDialog object.
          /// void ColorDialog1_HelpRequest(const object& sender, const System::EventArgs& e) {
          ///   MessageBox::Show("Please select a color by clicking it. This will change the BackColor property of the TextBox.");
          /// }
          /// @endcode
          EventHandler HelpRequest;

          /// @brief When overridden in a derived class, resets the properties of a common dialog box to their default values.
          /// @par Notes to Inheritors
          /// Inheriting classes can override this method to reset their properties.
          virtual void Reset() = 0;

          /// @brief When overridden in a derived class, specifies a common dialog box.
          /// @param hwndOwner A value that represents the window handle of the owner window for the common dialog box.
          /// @return bool true if the dialog box was successfully run; otherwise, false.
          /// @remarks This method is invoked when the user of a common dialog box calls ShowDialog, and it must be overridden by inherited classes of CommonDialog to implement a specific common dialog box.
          virtual bool RunDialog(intptr hwndOwner) = 0;

          /// @brief Runs a common dialog box with a default owner.
          /// @return DialogResult DialogResult::OK if the user clicks OK in the dialog box; otherwise, DialogResult::Cancel.
          /// @remarks This method implements RunDialog.
          DialogResult ShowDialog();

          /// @brief Runs a common dialog box with the specified owner.
          /// @param owner Any object that implements IWin32Window that represents the top-level window that will own the modal dialog box.
          /// @return DialogResult DialogResult::OK if the user clicks OK in the dialog box; otherwise, DialogResult::Cancel.
          /// @remarks This version of the ShowDialog method allows you to specify a specific form or control that will own the dialog box that is shown. If you use the version of this method that has no parameters, the dialog box being shown would be owned automatically by the currently active window of your application.
          DialogResult ShowDialog(const IWin32Window& owner);

        protected:
          /// @brief Defines the common dialog box hook procedure that is overridden to add specific functionality to a common dialog box.
          /// @param hwnd The handle to the dialog box window.
          /// @param msg The message being received.
          /// @param wparam Additional information about the message.
          /// @param lparam Additional information about the message.
          /// @return intptr A zero value if the default dialog box procedure processes the message; a nonzero value if the default dialog box procedure ignores the message.
          /// @remarks A hook procedure is a mechanism by which a function can intercept events before they reach an application. When you override the HookProc method for a CommonDialog class, the operating system invokes your override of the function to post operating system messages to the window.
          /// @par Notes to Inheritors
          /// Inheriting classes can override this method to add specific functionality to a common dialog box. When overriding HookProc in a derived class, be sure to call the base class's HookProc method.
          /// @par Examples
          /// @code
          /// // Defines the constants for Windows messages.
          /// static const int WM_SETFOCUS = 0x0007;
          /// static const int WM_INITDIALOG = 0x0110;
          /// static const int WM_LBUTTONDOWN = 0x0201;
          /// static const int WM_RBUTTONDOWN = 0x0204;
          /// static const int WM_MOVE = 0x0003;
          ///
          /// // Overrides the base class hook procedure...
          /// intptr HookProc(intptr hWnd, int msg, intptr wParam, intptr lParam) override {
          ///   // Evaluates the message parameter to determine the user action.
          ///   switch(msg) {
          ///     case WM_INITDIALOG:
          ///       System::Diagnostics::Trace::Write("The WM_INITDIALOG message was received.");
          ///       break;
          ///     case WM_SETFOCUS:
          ///       System::Diagnostics::Trace::Write("The WM_SETFOCUS message was received.");
          ///       break;
          ///     case WM_LBUTTONDOWN:
          ///       System::Diagnostics::Trace::Write("The WM_LBUTTONDOWN message was received.");
          ///       break;
          ///     case WM_RBUTTONDOWN:
          ///       System::Diagnostics::Trace::Write("The WM_RBUTTONDOWN message was received.");
          ///       break;
          ///     case WM_MOVE:
          ///       System::Diagnostics::Trace::Write("The WM_MOVE message was received.");
          ///       break;
          ///   }
          ///
          ///   // Always call the base class hook procedure.
          ///   return this->CommonDialog::HookProc(hWnd, msg, wParam, lParam);
          /// }
          /// @endcode
          virtual intptr HookProc(intptr hWnd, int32 msg, intptr wparam, intptr lparam);

          /// @brief Raises the HelpRequest event.
          /// @param e An HelpEventArgs that provides the event data.
          /// @remarks This method is invoked when the Help button is clicked. Inheriting classes can override this method to handle the event.
          virtual void OnHelpRequest(const EventArgs& e);

          /// @brief Defines the owner window procedure that is overridden to add specific functionality to a common dialog box.
          /// @param hWnd The window handle of the message to send.
          /// @param msg The Win32 message to send.
          /// @param wparam The wparam to send with the message.
          /// @param lparam The lparam to send with the message.
          /// @return intptr The result of the message processing, which is dependent on the message sent.
          /// @remarks Control is transferred here when messages are sent to the owner window of the common dialog box. Inheriting classes can override this method to add specific functionality to a common dialog box.
          virtual intptr OwnerWndProc(intptr hWnd, int32 msg, intptr wparam, intptr lparam);

          /// @cond
          ref<object> tag;
          /// @endcond
        };
      }
    }
  }
}
