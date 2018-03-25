/// @file
/// @brief Contains Switch::System::Windows::Forms::MessageBox class.
#pragma once

#include <Switch/Any.hpp>
#include <Switch/Static.hpp>
#include <Switch/System/String.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "DialogResult.hpp"
#include "IWin32Window.hpp"
#include "HelpNavigator.hpp"
#include "MessageBoxButtons.hpp"
#include "MessageBoxDefaultButton.hpp"
#include "MessageBoxIcon.hpp"
#include "MessageBoxOptions.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A MessageBox can contain text, buttons, and symbols that inform and instruct the user.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks You cannot create a new instance of the MessageBox class. To display a message box, call the static method MessageBox.Show. The title, text, buttons, and icons displayed in the message box are determined by parameters that you pass to this method.
        /// @par Examples
        /// The following code example demonstrate the use of MessageBox control.
        /// @include MessageBox.cpp
        class system_windows_forms_export_ MessageBox static_ {
        public:
          /// @brief Displays a message box in front of the specified object and with the specified text.
          /// @param owner An implementation of IWin32Window that will own the modal dialog box.
          /// @param text The text to display in the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks By default, the message box displays an OK button. The message box does not contain a caption in the title.
          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text) {return MessageBox::Show(owner, text, "", MessageBoxButtons::OK, MessageBoxIcon::None, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, "");}

          /// @brief Displays a message box in front of the specified object and with the specified text and caption.
          /// @param owner An implementation of IWin32Window that will own the modal dialog box.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks By default, the message box displays an OK button.
          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text, const string& caption) {return Show(owner, text, caption, MessageBoxButtons::OK, MessageBoxIcon::None, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, "");}

          /// @brief Displays a message box in front of the specified object and with the specified text, caption, and buttons.
          /// @param owner An implementation of IWin32Window that will own the modal dialog box.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks You can have a maximum of three buttons on the message box.
          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons) {return Show(owner, text, caption, buttons, MessageBoxIcon::None, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, "");}

          /// @brief Displays a message box in front of the specified object and with the specified text, caption, buttons, and icon.
          /// @param owner An implementation of IWin32Window that will own the modal dialog box.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @param icon One of the MessageBoxIcon values that specifies which icon to display in the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @exception InvalidEnumException buttons is not a member of MessageBoxButtons.  -or-  icon is not a member of MessageBoxIcon.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks You can have a maximum of three buttons on the message box.
          /// @par Examples
          /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
          /// @code
          /// void validateUserEntry() {
          ///   // Checks the value of the text.
          ///   if (serverName.Text().Length == 0) {
          ///     // Initializes the variables to pass to the MessageBox.Show method.
          ///     string message = "You did not enter a server name. Cancel this operation?";
          ///     string caption = "No Server Name Specified";
          ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
          ///
          ///     // Displays the MessageBox.
          ///     DialogResult result = MessageBox.Show(*this, message, caption, buttons, MessageBoxIcon::Question);
          ///
          ///     if (result == DialogResult.Yes) {
          ///       // Closes the parent form.
          ///       this->Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon) {return Show(owner, text, caption, buttons, icon, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, "");}

          /// @brief Displays a message box in front of the specified object and with the specified text, caption, buttons, icon, and default button.
          /// @param owner An implementation of IWin32Window that will own the modal dialog box.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @param icon One of the MessageBoxIcon values that specifies which icon to display in the message box.
          /// @param defaultButton One of the MessageBoxDefaultButton values that specifies the default button for the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @exception InvalidEnumException buttons is not a member of MessageBoxButtons.  -or-  icon is not a member of MessageBoxIcon.  -or-  defaultButton is not a member of MessageBoxDefaultButton.
          /// @exception InvalidOperationException An attempt was made to display the MessageBox in a process that is not running in User Interactive mode. This is specified by the SystemInformation.UserInteractive property.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks You can have a maximum of three buttons on the message box.
          /// @par Examples
          /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
          /// @code
          /// void validateUserEntry() {
          ///   // Checks the value of the text.
          ///   if (serverName.Text().Length == 0) {
          ///     // Initializes the variables to pass to the MessageBox.Show method.
          ///     string message = "You did not enter a server name. Cancel this operation?";
          ///     string caption = "No Server Name Specified";
          ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
          ///
          ///     // Displays the MessageBox.
          ///     DialogResult result = MessageBox.Show(*this, message, caption, buttons, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1);
          ///
          ///     if (result == DialogResult.Yes) {
          ///       // Closes the parent form.
          ///       this->Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton) {return Show(owner, text, caption, buttons, icon, defaultButton, (MessageBoxOptions)0, "");}

          /// @brief Displays a message box in front of the specified object and with the specified text, caption, buttons, icon, and default button.
          /// @param owner An implementation of IWin32Window that will own the modal dialog box.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @param icon One of the MessageBoxIcon values that specifies which icon to display in the message box.
          /// @param defaultButton One of the MessageBoxDefaultButton values that specifies the default button for the message box.
          /// @param options One of the MessageBoxOptions values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
          /// @return DialogResult One of the DialogResult values.
          /// @exception InvalidEnumException buttons is not a member of MessageBoxButtons.  -or-  icon is not a member of MessageBoxIcon.  -or-  defaultButton is not a member of MessageBoxDefaultButton.
          /// @exception InvalidOperationException An attempt was made to display the MessageBox in a process that is not running in User Interactive mode. This is specified by the SystemInformation.UserInteractive property.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks You can have a maximum of three buttons on the message box.
          /// @par Examples
          /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
          /// @code
          /// void validateUserEntry() {
          ///   // Checks the value of the text.
          ///   if (serverName.Text().Length == 0) {
          ///     // Initializes the variables to pass to the MessageBox.Show method.
          ///     string message = "You did not enter a server name. Cancel this operation?";
          ///     string caption = "No Server Name Specified";
          ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
          ///
          ///     // Displays the MessageBox.
          ///     DialogResult result = MessageBox.Show(*this, message, caption, buttons, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1, MessageBoxOptions::RightAlign);
          ///
          ///     if (result == DialogResult.Yes) {
          ///       // Closes the parent form.
          ///       this->Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options) {return Show(owner, text, caption, buttons, icon, defaultButton, options, "");}

          /// @brief Displays a message box in front of the specified object and with the specified text, caption, buttons, icon, and default button.
          /// @param owner An implementation of IWin32Window that will own the modal dialog box.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @param icon One of the MessageBoxIcon values that specifies which icon to display in the message box.
          /// @param defaultButton One of the MessageBoxDefaultButton values that specifies the default button for the message box.
          /// @param options One of the MessageBoxOptions values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
          /// @param displayHelpButton true to show the Help button; otherwise, false. The default is false.
          /// @return DialogResult One of the DialogResult values.
          /// @exception InvalidEnumException buttons is not a member of MessageBoxButtons.  -or-  icon is not a member of MessageBoxIcon.  -or-  defaultButton is not a member of MessageBoxDefaultButton.
          /// @exception InvalidOperationException An attempt was made to display the MessageBox in a process that is not running in User Interactive mode. This is specified by the SystemInformation.UserInteractive property.
          /// @exception ArgumentException options specified both DefaultDesktopOnly and ServiceNotification.  -or-  buttons specified an invalid combination of MessageBoxButtons.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks When the user clicks the Help button, the form that owns the message box (or the active form) receives the HelpRequested event. Handle the HelpRequested event to perform custom Help actions.
          /// @par Examples
          /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
          /// @code
          /// void validateUserEntry() {
          ///   // Checks the value of the text.
          ///   if (serverName.Text().Length == 0) {
          ///     // Initializes the variables to pass to the MessageBox.Show method.
          ///     string message = "You did not enter a server name. Cancel this operation?";
          ///     string caption = "No Server Name Specified";
          ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
          ///
          ///     // Displays the MessageBox.
          ///     DialogResult result = MessageBox.Show(*this, message, caption, buttons, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1, MessageBoxOptions::RightAlign, true);
          ///
          ///     if (result == DialogResult.Yes) {
          ///       // Closes the parent form.
          ///       this->Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton);

          /*
          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath);

          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath, HelpNavigator navigator);

          static System::Windows::Forms::DialogResult Show(const IWin32Window& owner, const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath, HelpNavigator navigator, any param);
           */

          /// @brief Displays a message box with specified text.
          /// @param text The text to display in the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @remarks By default, the message box displays an OK button. The message box does not contain a caption in the title.
          /// @par Examples
          /// The following code example displays a simple message box.
          /// @code
          /// void DisplayMessageBoxText() {
          ///   MessageBox::Show("Hello, world.");
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const string& text) {return MessageBox::Show(text, "", MessageBoxButtons::OK, MessageBoxIcon::None, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, false);}

          /// @brief Displays a message box with specified text and caption.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @remarks By default, the message box displays an OK button.
          static System::Windows::Forms::DialogResult Show(const string& text, const string& caption) {return Show(text, caption, MessageBoxButtons::OK, MessageBoxIcon::None, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, false);}

          /// @brief Displays a message box with specified text, caption, and buttons.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @exception InvalidEnumArgumentException The buttons parameter specified is not a member of MessageBoxButtons.
          /// @exception InvalidOperationException An attempt was made to display the MessageBox in a process that is not running in User Interactive mode. This is specified by the SystemInformation.UserInteractive property.
          /// @remarks You can have a maximum of three buttons on the message box.
          /// @par Examples
          /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
          /// @code
          /// void validateUserEntry() {
          ///   // Checks the value of the text.
          ///   if (serverName.Text().Length == 0) {
          ///     // Initializes the variables to pass to the MessageBox.Show method.
          ///     string message = "You did not enter a server name. Cancel this operation?";
          ///     string caption = "No Server Name Specified";
          ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
          ///
          ///     // Displays the MessageBox.
          ///     DialogResult result = MessageBox.Show(message, caption, buttons);
          ///
          ///     if (result == DialogResult.Yes) {
          ///       // Closes the parent form.
          ///       this->Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const string& text, const string& caption, MessageBoxButtons buttons) {return Show(text, caption, buttons, MessageBoxIcon::None, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, false);}

          /// @brief Displays a message box with specified text, caption, buttons, and icon.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @param icon One of the MessageBoxIcon values that specifies which icon to display in the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @exception InvalidEnumException buttons is not a member of MessageBoxButtons.  -or-  icon is not a member of MessageBoxIcon.
          /// @exception InvalidOperationException An attempt was made to display the MessageBox in a process that is not running in User Interactive mode. This is specified by the SystemInformation.UserInteractive property.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks You can have a maximum of three buttons on the message box.
          /// @par Examples
          /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
          /// @code
          /// void validateUserEntry() {
          ///   // Checks the value of the text.
          ///   if (serverName.Text().Length == 0) {
          ///     // Initializes the variables to pass to the MessageBox.Show method.
          ///     string message = "You did not enter a server name. Cancel this operation?";
          ///     string caption = "No Server Name Specified";
          ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
          ///
          ///     // Displays the MessageBox.
          ///     DialogResult result = MessageBox.Show(message, caption, buttons, MessageBoxIcon::Question);
          ///
          ///     if (result == DialogResult.Yes) {
          ///       // Closes the parent form.
          ///       this->Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon) {return Show(text, caption, buttons, icon, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, false);}

          /// @brief Displays a message box with the specified text, caption, buttons, icon, and default button.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @param icon One of the MessageBoxIcon values that specifies which icon to display in the message box.
          /// @param defaultButton One of the MessageBoxDefaultButton values that specifies the default button for the message box.
          /// @return DialogResult One of the DialogResult values.
          /// @exception InvalidEnumException buttons is not a member of MessageBoxButtons.  -or-  icon is not a member of MessageBoxIcon.  -or-  defaultButton is not a member of MessageBoxDefaultButton.
          /// @exception InvalidOperationException An attempt was made to display the MessageBox in a process that is not running in User Interactive mode. This is specified by the SystemInformation.UserInteractive property.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks You can have a maximum of three buttons on the message box.
          /// @par Examples
          /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
          /// @code
          /// void validateUserEntry() {
          ///   // Checks the value of the text.
          ///   if (serverName.Text().Length == 0) {
          ///     // Initializes the variables to pass to the MessageBox.Show method.
          ///     string message = "You did not enter a server name. Cancel this operation?";
          ///     string caption = "No Server Name Specified";
          ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
          ///
          ///     // Displays the MessageBox.
          ///     DialogResult result = MessageBox.Show(*this, message, caption, buttons, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1);
          ///
          ///     if (result == DialogResult.Yes) {
          ///       // Closes the parent form.
          ///       this->Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton) {return Show(text, caption, buttons, icon, defaultButton, (MessageBoxOptions)0, false);}

          /// @brief Displays a message box with the specified text, caption, buttons, icon, and default button.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @param icon One of the MessageBoxIcon values that specifies which icon to display in the message box.
          /// @param defaultButton One of the MessageBoxDefaultButton values that specifies the default button for the message box.
          /// @param options One of the MessageBoxOptions values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
          /// @return DialogResult One of the DialogResult values.
          /// @exception InvalidEnumException buttons is not a member of MessageBoxButtons.  -or-  icon is not a member of MessageBoxIcon.  -or-  defaultButton is not a member of MessageBoxDefaultButton.
          /// @exception InvalidOperationException An attempt was made to display the MessageBox in a process that is not running in User Interactive mode. This is specified by the SystemInformation.UserInteractive property.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks You can have a maximum of three buttons on the message box.
          /// @par Examples
          /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
          /// @code
          /// void validateUserEntry() {
          ///   // Checks the value of the text.
          ///   if (serverName.Text().Length == 0) {
          ///     // Initializes the variables to pass to the MessageBox.Show method.
          ///     string message = "You did not enter a server name. Cancel this operation?";
          ///     string caption = "No Server Name Specified";
          ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
          ///
          ///     // Displays the MessageBox.
          ///     DialogResult result = MessageBox.Show(message, caption, buttons, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1, MessageBoxOptions::RightAlign);
          ///
          ///     if (result == DialogResult.Yes) {
          ///       // Closes the parent form.
          ///       this->Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options) {return Show(text, caption, buttons, icon, defaultButton, options, false);}

          /// @brief Displays a message box with the specified text, caption, buttons, icon, and default button.
          /// @param text The text to display in the message box.
          /// @param caption The text to display in the title bar of the message box.
          /// @param buttons One of the MessageBoxButtons values that specifies which buttons to display in the message box.
          /// @param icon One of the MessageBoxIcon values that specifies which icon to display in the message box.
          /// @param defaultButton One of the MessageBoxDefaultButton values that specifies the default button for the message box.
          /// @param options One of the MessageBoxOptions values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
          /// @param displayHelpButton true to show the Help button; otherwise, false. The default is false.
          /// @return DialogResult One of the DialogResult values.
          /// @exception InvalidEnumException buttons is not a member of MessageBoxButtons.  -or-  icon is not a member of MessageBoxIcon.  -or-  defaultButton is not a member of MessageBoxDefaultButton.
          /// @exception InvalidOperationException An attempt was made to display the MessageBox in a process that is not running in User Interactive mode. This is specified by the SystemInformation.UserInteractive property.
          /// @exception ArgumentException options specified both DefaultDesktopOnly and ServiceNotification.  -or-  buttons specified an invalid combination of MessageBoxButtons.
          /// @remarks You can use the owner parameter to specify a particular object, which implements the IWin32Window interface, that will serve as the dialog box's top-level window and owner. A message box is a modal dialog box, which means no input (keyboard or mouse click) can occur except to objects on the modal form. The program must hide or close a modal form (typically in response to some user action) before input to another form can occur.
          /// @remarks When the user clicks the Help button, the form that owns the message box (or the active form) receives the HelpRequested event. Handle the HelpRequested event to perform custom Help actions.
          /// @par Examples
          /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
          /// @code
          /// void validateUserEntry() {
          ///   // Checks the value of the text.
          ///   if (serverName.Text().Length == 0) {
          ///     // Initializes the variables to pass to the MessageBox.Show method.
          ///     string message = "You did not enter a server name. Cancel this operation?";
          ///     string caption = "No Server Name Specified";
          ///     MessageBoxButtons buttons = MessageBoxButtons::YesNo;
          ///
          ///     // Displays the MessageBox.
          ///     DialogResult result = MessageBox.Show(message, caption, buttons, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1, MessageBoxOptions::RightAlign, true);
          ///
          ///     if (result == DialogResult.Yes) {
          ///       // Closes the parent form.
          ///       this->Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          static System::Windows::Forms::DialogResult Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton);

          /*
          static System::Windows::Forms::DialogResult Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath);

          static System::Windows::Forms::DialogResult Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath, HelpNavigator navigator);

          static System::Windows::Forms::DialogResult Show(const string& text, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, const string& helpFilePath, HelpNavigator navigator, any param);
           */
        };
      }
    }
  }
}
