/// @file
/// @brief Contains Switch::System::Windows::Forms::Control class.
#pragma once

#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Drawing/Color.hpp>
#include <Switch/System/Drawing/SolidBrush.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>
#include <Switch/System/Drawing/Font.hpp>
#include <Switch/System/Nullable.hpp>
#include <Switch/System/ComponentModel/Component.hpp>
#include <Switch/System/ComponentModel/EventHandlerList.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "ControlStyles.hpp"
#include "InvalidateEventHandler.hpp"
#include "IWin32Window.hpp"
#include "KeyEventHandler.hpp"
#include "KeyPressEventHandler.hpp"
#include "Message.hpp"
#include "MouseEventHandler.hpp"
#include "PaintEventHandler.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating System::
      namespace Forms {
        /// @cond
        class Form;
        /// @endcond

        /// @brief Defines the base class for controls, which are components with visual representation.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks To create your own control class, inherit from the UserControl, Control classes, or from the other Windows Forms provided controls. For more information about authoring custom controls, see Developing Custom Windows Forms Controls with the .NET Framework.
        /// @remarks The Control class implements very basic functionality required by classes that display information to the user. It handles user input through the keyboard and pointing devices. It handles message routing and security. It defines the bounds of a control (its position and size), although it does not implement painting. It provides a window handle (hWnd).
        /// @remarks Windows Forms controls use ambient properties so child controls can appear like their surrounding environment. An ambient property is a control property that, if not set, is retrieved from the parent control. If the control does not have a Parent, and the property is not set, the control attempts to determine the value of the ambient property through the Site property. If the control is not sited, if the site does not support ambient properties, or if the property is not set on the AmbientProperties, the control uses its own default values. Typically, an ambient property represents a characteristic of a control, such as BackColor, that is communicated to a child control. For example, a Button will have the same BackColor as its parent Form by default. Ambient properties provided by the Control class include: Cursor, Font, BackColor, ForeColor, and RightToLeft.
        /// @note To make your Windows Forms application support visual styles, be sure to set the FlatStyle property to System and include a manifest with your executable. A manifest is an XML file that is included either as a resource within your application executable or as a separate file that resides in the same directory as the executable file. For an example of a manifest, see the Example section of the FlatStyle enumeration. For more information about using visual styles, see Visual Styles.
        /// @remarks Windows Forms has accessibility support built in, and provides information about your application that enables it to work with accessibility client applications such as screen enlarger and reviewer utilities, voice input utilities, on-screen keyboards, alternative input devices, and keyboard enhancement utilities. Sometimes you will want to provide additional information to accessibility client applications. There are two ways of providing this additional information. You can set the AccessibleName, AccessibleDescription, AccessibleDefaultActionDescription, and AccessibleRole property values, which will be reported to accessibility client applications. This method is typically used to provide limited accessibility information for existing controls. Alternatively, you can write your own class deriving from the AccessibleObject or Control.ControlAccessibleObject classes, providing as much accessibility information as needed.
        /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to override the DefaultSize property.
        /// @note Do not add data bindings for a Control in its constructor. Doing so will cause errors in code generation and can cause unwanted behavior.
        /// @remarks The majority of the controls in the System::Windows::Forms namespace use the underlying Windows common control as a base to build on. For more information about the Windows common controls, see General Control Reference.
        /// @remarks To identify Windows Forms controls from a separate process, use a standard SendMessage call to pass the WM_GETCONTROLNAME message. WM_GETCONTROLNAME is independent of the language and Windows hierarchy. For more information, see the "Recommended Solution for Windows Forms" topic in Automating Windows Forms::
        /// @remarks Use the InvokeRequired property to synchronize access to the control from multiple threads. For more information about multithreaded Windows Forms controls, see How to: Make Thread-Safe Calls to Windows Forms Controls
        class system_windows_forms_export_ Control : public IWin32Window, public System::ComponentModel::Component {
          enum class State;
        public:
          /// @brief Represents a collection of Control objects.
          /// @remarks The Add, Remove, and RemoveAt methods enable you to add and remove individual controls from the collection. You can also use the AddRange or Clear methods to add or remove all the controls from the collection.
          /// @remarks You can determine if a Control is a member of the collection by passing the control into the Contains method. To get the index value of the location of a Control in the collection, pass the control into the IndexOf method. The collection can be copied into an array by calling the CopyTo method.
          /// @par examples
          /// @code
          /// // Remove the RadioButton control if it exists.
          /// void RemoveButtonClick(const object& sender, const System::EventArgs& e) {
          ///   if (panel1.Controls().Contains(removeButton)) {
          ///     panel1.Controls().Remove(removeButton);
          ///   }
          /// }
          /// @endcode
          class ControlCollection : public System::Collections::Generic::List<ref<Control>> {
          public:
            /// @cond
            ~ControlCollection() { this->Clear(); }
            /// @endcond

            /// @brief Adds the specified control to the control collection.
            /// @exception Exception The specified control is a top-level control, or a circular control reference would result if this control were added to the control collection.
            /// @exception ArgumentException The object assigned to the value parameter is not a Control.
            /// @remarks The Add method allows you to add Control objects to the end of the control collection.
            /// @remarks You can also add new Control objects to the collection by using the AddRange method.
            /// @remarks To remove a Control that you previously added, use the Remove, RemoveAt, or Clear methods.
            /// @note A Control can only be assigned to one Control.ControlCollection at a time. If the Control is already a child of another control it is removed from that control before it is added to another control.
            /// @par Notes to Inheritors
            /// When overriding Add in a derived class, be sure to call the base class's Add method to ensure that the control is added to the collection.
            /// @par examples
            /// The following code example adds a Control to the Control.ControlCollection of the derived class Panel. The example requires that you have created a Panel control and a Button control on a Form. When the button is clicked, a TextBox control is added to the panel's Control.ControlCollection.
            /// @code
            /// // Create a TextBox to add to the Panel.
            /// TextBox textBox1;
            ///
            /// // Add controls to the Panel using the Add method.
            /// void addButton_Click(const object& sender, const System::EventArgs& e) {
            ///   panel1.Controls().Add(textBox1);
            /// }
            /// @endcode
            void Add(const ref<Control>& value) override {
              ChangeParent(value);
              this->System::Collections::Generic::List<ref<Control>>::Add(value);
            }

            /// @brief Removes the specified control from the control collection.
            /// @param value The Control to remove from the Control.ControlCollection.
            /// @remarks When a Control is removed from the control collection, all subsequent controls are moved up one position in the collection.
            /// @remarks You can also remove a Control by using the RemoveAt method, or remove all controls by using the Clear method.
            /// @remarks To add new Control objects to the collection, use the Add or AddRange methods.
            /// @par Notes to Inheritors
            /// When overriding Remove in a derived class, be sure to call the base class's Remove method to ensure that the control is removed from the collection.
            /// @par examples
            /// The following code example removes a Control from the Control.ControlCollection of the derived class Panel if it is a member of the collection. The example requires that you have created a Panel, a Button, and one or more RadioButton controls on a Form. The RadioButton controls are added to the Panel control, and the Panel control is added to the Form. When the button is clicked, the radio button named radioButton2 is removed from the Control.ControlCollection.
            /// @code
            /// // Remove the RadioButton control if it exists.
            /// void removeButton_Click(const object& sender, const System::EventArgs& e) {
            ///   if(panel1.Controls().Contains(removeButton)) {
            ///     panel1.Controls().Remove(removeButton);
            ///   }
            /// }
            /// @endcode
            bool Remove(const ref<Control>& value) override {
              RemoveParent(value);
              return this->System::Collections::Generic::List<ref<Control>>::Remove(value);
            }

            /// @brief Removes a control from the control collection at the specified indexed location.
            /// @param index The index value of the Control to remove.
            /// @remarks When a Control is removed from the control collection, all subsequent controls are moved up one position in the collection.
            /// @remarks You can also remove a Control that you previously added by using the Remove or Clear methods.
            /// @remarks To add new Control objects to the collection, use the Add or AddRange methods.
            /// @par examples
            /// The following code example removes the first Control in the Control.ControlCollection of the derived class Panel if the count of the collection is greater than zero. The example requires that you have created a Panel, a Button, and at least one other control on a Form. The other controls are added to the Panel control, and the Panel control added to the Form. When the button is clicked, the first control contained in the panel is removed from the Control.ControlCollection.
            /// @code
            /// // Remove the first control in the collection.
            /// void removeAtButton_Click(const object& sender, const System::EventArgs& e) {
            ///   if (panel1.Controls().Count > 0) {
            ///     panel1.Controls().RemoveAt(0);
            ///   }
            /// }
            /// @endcode
            void RemoveAt(int32 index) override {
              RemoveParent((*this)[index]);
              this->System::Collections::Generic::List<ref<Control>>::RemoveAt(index);
            }

          private:
            void Insert(int32 index, const ref<Control>& value) override {}

            friend Control;
            explicit ControlCollection(ref<Control> controlContainer) : controlContainer(controlContainer) {}

            void ChangeParent(ref<Control> value);

            void RemoveParent(ref<Control> value);
            ref<Control> controlContainer;
          };

          /// @brief Initializes a new instance of the Control class with default settings.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          Control();

          /// @brief Initializes a new instance of the Control class as a child control, with specific text.
          /// @param parent The Control to be the parent of the control.
          /// @param text The text displayed by the control.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The constructor also adds the control to the parent control's Control::ControlCollection.
          Control(const Control& parent, const string& text) : Control() {
            this->Parent = parent;
            this->Text = text;
            this->size = GetDefaultSize();
          }

          /// @brief Initializes a new instance of the Control class with specific text, size, and location.
          /// @param text The text displayed by the control.
          /// @param left The X position of the control, in pixels, from the left edge of the control's container. The value is assigned to the Left property.
          /// @param top The Y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the Top property.
          /// @param width The height of the control, in pixels. The value is assigned to the Height property.
          /// @param height The width of the control, in pixels. The value is assigned to the Width property.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The initial Size and Location of the control are determined by the left, top, width and height parameter values.
          /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to virtual the DefaultSize property.
          Control(const string& text, int32 left, int32 top, int32 width, int32 height) : Control() {
            this->Text = text;
            this->location = {left, top};
            this->size = {width, height};
          }

          /// @brief Initializes a new instance of the Control class as a child control, with specific text, size, and location.
          /// @param parent The Control to be the parent of the control.
          /// @param text The text displayed by the control.
          /// @param left The X position of the control, in pixels, from the left edge of the control's container. The value is assigned to the Left property.
          /// @param top The Y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the Top property.
          /// @param width The height of the control, in pixels. The value is assigned to the Height property.
          /// @param height The width of the control, in pixels. The value is assigned to the Width property.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The constructor also adds the control to the parent control's Control.ControlCollection. The initial Size and Location of the control are determined by the left, top, width and height parameter values.
          /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to virtual the DefaultSize property.
          Control(const Control& parent, const string& text, int32 left, int32 top, int32 width, int32 height) : Control() {
            this->Parent = parent;
            this->Text = text;
          }

          /// @cond
          Control(const Control& control) = delete;
          ~Control() {
            if (this->Parent() != null)
              this->Parent()().controls.Remove(*this);
            if (this->IsHandleCreated)
              this->DestroyHandle();
          }
          /// @endcond

          /// @brief Gets or sets the background color for the control.
          /// @param color A Color that represents the background color of the control. The default is the value of the DefaultBackColor property.
          /// @remarks The BackColor property does not support transparent colors unless the SupportsTransparentBackColor value of System::Windows::Forms::ControlStyles is set to true.
          /// @remarks The BackColor property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a Button will have the same BackColor as its parent Form by default. For more information about ambient properties, see the AmbientProperties class or the Control class overview.
          /// @par Notes to Inheritors
          /// When overriding the BackColor property in a derived class, use the base class's BackColor property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and setaccessors of the BackColor property; you can override only one if needed.
          /// @par examples
          /// The following code example sets the BackColor and ForeColor of the controls to the default system colors. The code recursively calls itself if the control has any child controls. This code example requires that you have a Form with at least one child control; however, a child container control, like a Panel or GroupBox, with its own child control(s) would better demonstrate the recursion.
          /// @code
          /// // Reset all the controls to the user's default Control color.
          /// void ResetAllControlsBackColor(ref<Control> control) {
          ///   control.BackColor = SystemColors::Control;
          ///   control.ForeColor = SystemColors::ControlText;
          ///   if(control.HasChildren) {
          ///     // Recursively call this method for each child control.
          ///     for(ref<Control> childControl : control.Controls()) {
          ///       ResetAllControlsBackColor(childControl);
          ///     }
          ///   }
          /// }
          /// @endcode
          property_<System::Drawing::Color> BackColor {
            get_ { return (!this->backColor.HasValue && this->parent != null) ? this->parent().BackColor : this->backColor.GetValueOrDefault(DefaultBackColor); },
            set_ {
              if (this->backColor != value) {
                this->backColor = value;
                this->OnBackColorChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
          /// @param value An Int32 representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
          /// @remarks The value of this property is equal to the sum of the Top property value, and the Height property value.
          /// @remarks he Bottom property is a read-only property. You can manipulate this property value by changing the value of the Top or Height properties or calling the SetBounds, SetBoundsCore, UpdateBounds, or SetClientSizeCore methods.
          /// @par examples
          /// The following code example uses the Bottom property to define the lower limit of a TextBox control relative to the client area of the container.
          /// @code
          /// // This example demonstrates how to use the KeyUp event with the Help class to display
          /// // pop-up style help to the user of the application. When the user presses F1, the Help
          /// // class displays a pop-up window, similar to a ToolTip, near the control. This example assumes
          /// // that a TextBox control, named textBox1, has been added to the form and its KeyUp
          /// // event has been contected to this event handler method.
          /// void textBox1_KeyUp(const object& sender, const System::Windows::Forms::KeyEventArgs& e) {
          ///   // Determine whether the key entered is the F1 key. Display help if it is.
          ///   if(e.KeyCode == Keys::F1) {
          ///     // Display a pop-up help topic to assist the user.
          ///     Help::ShowPopup(this->textBox1, "Enter your first name", Point(this->textBox1.Right, this->textBox1.Bottom));
          ///   }
          /// }
          /// @endcode
          property_<int32, readonly_> Bottom {
            get_{ return this->location.Y() + this->size.Height(); }
          };

          /// @brief Gets or sets the size and location of the control including its nonclient elements, in pixels, relative to the parent control.
          /// @param value A Rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
          /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus. The SetBoundsCore method is called to set the Bounds property. The Bounds property is not always changed through its set method so you should override the SetBoundsCore method to ensure that your code is executed when the Bounds property is set.
          /// @par examples
          /// The following code example creates three Button controls on a form and sets their size and location by using the various size-related and location-related properties. This example requires that you have a Form that has a width and height of at least 300 pixels.
          /// @code
          /// // Create three buttons and place them on a form using
          /// // several size and location related properties.
          /// void AddOKCancelButtons() {
          ///   // Set the button size and location using
          ///   // the Size and Location properties.
          ///   Button buttonOK;
          ///   buttonOK.Location = Point(136,248);
          ///   buttonOK.Size = System::Drawing::Size(75,25);
          ///   // Set the Text property and make the
          ///   // button the form's default button.
          ///   buttonOK.Text = "&OK";
          ///   this.AcceptButton = buttonOK;
          ///
          ///   // Set the button size and location using the Top,
          ///   // Left, Width, and Height properties.
          ///   Button buttonCancel;
          ///   buttonCancel.Top = buttonOK.Top;
          ///   buttonCancel.Left = buttonOK.Right + 5;
          ///   buttonCancel.Width = buttonOK.Width;
          ///   buttonCancel.Height = buttonOK.Height;
          ///   // Set the Text property and make the
          ///   // button the form's cancel button.
          ///   buttonCancel.Text = "&Cancel";
          ///   this.CancelButton = buttonCancel;
          ///
          ///   // Set the button size and location using
          ///   // the Bounds property.
          ///   Button buttonHelp;
          ///   buttonHelp.Bounds = Rectangle(10,10, 75, 25);
          ///   // Set the Text property of the button.
          ///   buttonHelp.Text = "&Help";
          ///
          ///   // Add the buttons to the form.
          ///   this->Controls().AddRange({buttonOK, buttonCancel, buttonHelp});
          /// }
          /// @endcode
          property_<System::Drawing::Rectangle> Bounds {
            get_ { return Drawing::Rectangle(this->Location(), this->Size()); },
            set_ {
              this->Location(value.Location());
              this->Size(value.Size());
            }
          };

          /// @brief Gets the rectangle that represents the client area of the control.
          /// @return A Rectangle that represents the client area of the control.
          /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus.
          /// @remarks Because client coordinates are relative to the upper-left corner of the client area of the control, the coordinates of the upper-left corner of the rectangle returned by this property are (0,0). You can use this property to obtain the size and coordinates of the client area of the control for tasks such as drawing on the surface of the control.
          /// @remarks For more information about drawing on controls, see Rendering a Windows Forms Control.
          /// @par examples
          /// The following code example enables auto-scrolling for a form, resizes the form, and ensures that a button remains visible after the form is resized. This example requires that you have a Form with a Button named button2 on it.
          /// @code
          /// void ResizeForm() {
          ///   // Enable auto-scrolling for the form.
          ///   this->AutoScroll = true;
          ///
          ///   // Resize the form.
          ///   Rectangle r = this->ClientRectangle;
          ///   // Subtract 100 pixels from each side of the Rectangle.
          ///   r.Inflate(-100, -100);
          ///   this->Bounds = this->RectangleToScreen(r);
          ///
          ///   // Make sure button2 is visible.
          ///   this->ScrollControlIntoView(button2);
          /// }
          /// @endcode
          property_<System::Drawing::Rectangle, readonly_> ClientRectangle {
            get_{ return System::Drawing::Rectangle({0, 0}, this->clientSize); }
          };

          /// @brief Gets or sets the height and width of the client area of the control.
          /// @return A Size that represents the dimensions of the client area of the control.
          /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus. The SetClientSizeCore method is called to set the ClientSizeproperty. The ClientSize property is not always changed through its set method so you should override the SetClientSizeCore method to ensure that your code is executed when the ClientSize property is set.
          /// @remarks The Size.Width and Size.Height properties represent the width and height of the client area of the control. You can use this property to obtain the size of the client area of the control for tasks such as drawing on the surface of the control.
          /// @remarks For more information about drawing on controls, see Rendering a Windows Forms Control.
          /// @note You cannot bind application settings to this property. For more information on application settings, see Application Settings Overview.
          /// @par examples
          /// The following code example resizes the specified control so the control will accommodate its formatted text. The formatted text is the Text property with the control's assigned Font applied to the text. The AutoSizeControl method in this example also has a textPadding parameter that represents the padding to apply to all edges of the control. To make the padding appear equal, align the text with the ContentAlignment.MiddleCenter value, if your control supports it.
          /// @code
          /// void AutoSizeControl(Control& control, int textPadding) {
          ///   // Create a Graphics object for the Control.
          ///   Graphics g = control.CreateGraphics();
          ///
          ///   // Get the Size needed to accommodate the formatted Text.
          ///   Size preferredSize = g.MeasureString(control.Text, control.Font).ToSize();
          ///
          ///   // Pad the text and resize the control.
          ///   control.ClientSize = Size(preferredSize.Width + (textPadding * 2), preferredSize.Height+(textPadding * 2));
          /// }
          /// @endcode
          property_<System::Drawing::Size> ClientSize {
            get_{ return this->clientSize; },
            set_{
              if (this->clientSize != value) {
                this->clientSize = value;
                this->OnClientSizeChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets the collection of controls contained within the control.
          /// @param controls A Control.ControlCollection representing the collection of controls contained within the control.
          /// @remarks A Control can act as a parent to a collection of controls. For example, when several controls are added to a Form, each of the controls is a member of the Control.ControlCollection assigned to the Controls property of the form, which is derived from the Control class.
          /// @remarks You can manipulate the controls in the Control.ControlCollection assigned to the Controls property by using the methods available in the Control.ControlCollection class.
          /// @remarks When adding several controls to a parent control, it is recommended that you call the SuspendLayout method before initializing the controls to be added. After adding the controls to the parent control, call the ResumeLayout method. Doing so will increase the performance of applications with many controls.
          /// @remarks Use the Controls property to iterate through all controls of a form, including nested controls. Use the GetNextControl method to retrieve the previous or next child control in the tab order. Use the ActiveControl property to get or set the active control of a container control.
          /// @par examples
          /// The following code example removes a Control from the Control.ControlCollection of the derived class Panel if it is a member of the collection. The example requires that you have created a Panel, a Button, and at least one RadioButton control on a Form. The RadioButton control(s) are added to the Panel control, and the Panel control added to the Form. When the button is clicked, the radio button named removeButton is removed from the Control.ControlCollection.
          /// @code
          /// // Remove the RadioButton control if it exists.
          /// void removeButton_Click(const object& sender, const System::EventArgs& e) {
          ///   if(panel1.Controls().Contains(removeButton)) {
          ///     panel1.Controls().Remove(removeButton);
          ///   }
          /// }
          /// @endcode
          property_<ControlCollection&, readonly_> Controls {
            get_->ControlCollection& {return this->controls; }
          };

          /// @brief Gets the default background color of the control.
          /// @return System::Drawing::Color The default background Color of the control. The default is SystemColors::Control.
          /// @remarks This is the default BackColor property value of a generic top-level control. Derived classes can have different defaults.
          /// @par examples
          /// The following code example demonstrates how to use the DefaultBackColor, DefaultFont, and DefaultForeColor members. To run the example, paste the following code in a form containing a ListBox called ListBox1. Call the Populate_ListBox method in the form's constructor or Load event-handling method.
          /// @code
          /// // The following method displays the default font,
          /// // background color and foreground color values for the ListBox
          /// // control. The values are displayed in the ListBox, itself.
          ///
          /// void Populate_ListBox() {
          ///   listBox1.Dock = DockStyle::Bottom;
          ///
          ///   // Display the values in the read-only properties
          ///   // DefaultBackColor, DefaultFont, DefaultForecolor.
          ///   listBox1.Items().Add("Default BackColor: "_s + listBox.DefaultBackColor().ToString());
          ///   listBox1.Items().Add("Default Font: "_s + listBox.DefaultFont().ToString());
          ///   listBox1.Items().Add("Default ForeColor:"_s + listBox.DefaultForeColor().ToString());
          /// }
          /// @endcode
          static property_<System::Drawing::Color, readonly_> DefaultBackColor;

          /// @brief Gets the default foreground color of the control.
          /// @return System::Drawing::Color The default foreground Color of the control. The default is SystemColors::ControlText.
          /// @remarks This is the default ForeColor property value of a nonparented control. Derived classes can have different defaults.
          /// @par examples
          /// The following code example demonstrates how to use the DefaultBackColor, DefaultFont, and DefaultForeColor members. To run the example, paste the following code in a form containing a ListBox called ListBox1. Call the Populate_ListBox method in the form's constructor or Load event-handling method.
          /// @code
          /// // The following method displays the default font,
          /// // background color and foreground color values for the ListBox
          /// // control. The values are displayed in the ListBox, itself.
          ///
          /// void Populate_ListBox() {
          ///   listBox1.Dock = DockStyle::Bottom;
          ///
          ///   // Display the values in the read-only properties
          ///   // DefaultBackColor, DefaultFont, DefaultForecolor.
          ///   listBox1.Items().Add("Default BackColor: "_s + listBox.DefaultBackColor().ToString());
          ///   listBox1.Items().Add("Default Font: "_s + listBox.DefaultFont().ToString());
          ///   listBox1.Items().Add("Default ForeColor:"_s + listBox.DefaultForeColor().ToString());
          /// }
          /// @endcode
          static property_<System::Drawing::Color, readonly_> DefaultForeColor;

          /// @brief Gets or sets a value indicating whether the control can respond to user interaction.
          /// @return bool true if the control can respond to user interaction; otherwise, false. The default is true.
          /// @remarks With the Enabled property, you can enable or disable controls at run time. For example, you can disable controls that do not apply to the current state of the application. You can also disable a control to restrict its use. For example, a button can be disabled to prevent the user from clicking it. If a control is disabled, it cannot be selected.
          /// @par Important
          /// Setting the Enabled property to false does not disable the application's control box or prevent the application window from receiving the focus.
          /// @remarks When a container control has its enabled property set to false, all its contained controls are disabled, as well. For example, if the user clicks on any of the controls contained in a disabled GroupBox control, no events are raised.
          /// @note When a scrollable control is disabled, the scroll bars are also disabled. For example, a disabled multiline textbox is unable to scroll to display all the lines of text.
          /// @par examples
          /// The following code example creates a GroupBox and sets some of its common properties. The example creates a TextBox and sets its Location within the group box. Next, it sets the Text property of the group box, and docks the group box to the top of the form. Lastly, it disables the group box by setting the Enabled property to false, which causes all controls contained within the group box to be disabled.
          /// @code
          /// // Add a GroupBox to a form and set some of its common properties.
          /// void AddMyGroupBox() {
          ///   // Create a GroupBox and add a TextBox to it.
          ///   GroupBox groupBox1;
          ///   TextBox textBox1;
          ///   textBox1.Location = Point(15, 15);
          ///   groupBox1.Controls().Add(textBox1);
          ///
          ///   // Set the Text and Dock properties of the GroupBox.
          ///   groupBox1.Text = "MyGroupBox";
          ///   groupBox1.Dock = DockStyle::Top;
          ///
          ///   // Disable the GroupBox (which disables all its child controls)
          ///   groupBox1.Enabled = false;
          ///
          ///   // Add the Groupbox to the form.
          ///   this.Controls().Add(groupBox1);
          /// }
          /// @endcode
          property_<bool> Enabled{
            get_ {return this->enabled; },
            set_ {
              if (this->enabled != value) {
                this->enabled = value;
                this->OnEnabledChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets or sets the foreground color of the control.
          /// @return System::Drawing::Color The foreground Color of the control. The default is the value of the DefaultForeColor property.
          /// @remarks The ForeColor property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a Button will have the same BackColor as its parent Form by default. For more information about ambient properties, see the AmbientProperties class or the Control class overview.
          /// @par Notes to Inheritors
          /// When overriding the ForeColor property in a derived class, use the base class's ForeColor property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both theget and setaccessors of the ForeColor property; you can override only one if needed.
          /// @par examples
          /// The following code example sets the BackColor and ForeColor of the controls to the default system colors. The code recursively calls itself if the control has any child controls. This code example requires that you have a Form with at least one child control; however, a child container control, like a Panel or GroupBox, with its own child control(s) would better demonstrate the recursion.
          /// @code
          /// // Reset all the controls to the user's default Control color.
          /// void ResetAllControlsBackColor(ref<Control> control) {
          ///   control.BackColor = SystemColors::Control;
          ///   control.ForeColor = SystemColors::ControlText;
          ///   if(control.HasChildren) {
          ///     // Recursively call this method for each child control.
          ///     for(ref<Control> childControl : control.Controls()) {
          ///       ResetAllControlsBackColor(childControl);
          ///     }
          ///   }
          /// }
          /// @endcode
          property_<System::Drawing::Color> ForeColor {
            get_{ return (!this->foreColor.HasValue && this->parent != null) ? this->parent().ForeColor : this->foreColor.GetValueOrDefault(DefaultForeColor); },
            set_ {
              if (this->foreColor != value) {
                this->foreColor = value;
                this->OnForeColorChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets a value indicating whether the control contains one or more child controls.
          /// @return bool true if the control contains one or more child controls; otherwise, false.
          /// @remarks If the Controls collection has a Count greater than zero, the HasChildren property will return true. Accessing the HasChildren property does not force the creation of a Control.ControlCollection if the control has no children, so referencing this property can provide a performance benefit when walking a tree of controls.
          /// @par examples
          /// The following code example sets the BackColor and ForeColor of the controls to the default system colors. The code recursively calls itself if the control has any child controls. This code example requires that you have a Form with at least one child control; however, a child container control, like a Panel or GroupBox, with its own child control(s) would better demonstrate the recursion.
          /// @code
          /// // Reset all the controls to the user's default Control color.
          /// void ResetAllControlsBackColor(ref<Control> control) {
          ///   control.BackColor = SystemColors::Control;
          ///   control.ForeColor = SystemColors::ControlText;
          ///   if(control.HasChildren) {
          ///     // Recursively call this method for each child control.
          ///     for(ref<Control> childControl : control.Controls()) {
          ///       ResetAllControlsBackColor(childControl);
          ///     }
          ///   }
          /// }
          /// @endcode
          property_<bool, readonly_> HasChildren {
            get_ {return this->Controls().Count != 0;}
          };

          /// @brief Gets or sets the height of the control.
          /// @return int32 The height of the control in pixels.
          /// @remarks Changes made to the Height and Top property values cause the Bottom property value of the control to change.
          /// @note The minimum height for the derived control Splitter is one pixel. The default height for the Splitter control is three pixels. Setting the height of the Splitter control to a value less than one will reset the property value to the default height.
          /// @par examples
          /// The following code example creates three Button controls on a form and sets their size and location by using the various size-related and location-related properties. This example requires that you have a Form that has a width and height of at least 300 pixels.
          /// @code
          /// // Create three buttons and place them on a form using
          /// // several size and location related properties.
          /// void AddOKCancelButtons() {
          ///   // Set the button size and location using
          ///   // the Size and Location properties.
          ///   Button buttonOK;
          ///   buttonOK.Location = Point(136,248);
          ///   buttonOK.Size = System::Drawing::Size(75,25);
          ///   // Set the Text property and make the
          ///   // button the form's default button.
          ///   buttonOK.Text = "&OK";
          ///   this.AcceptButton = buttonOK;
          ///
          ///   // Set the button size and location using the Top,
          ///   // Left, Width, and Height properties.
          ///   Button buttonCancel;
          ///   buttonCancel.Top = buttonOK.Top;
          ///   buttonCancel.Left = buttonOK.Right + 5;
          ///   buttonCancel.Width = buttonOK.Width;
          ///   buttonCancel.Height = buttonOK.Height;
          ///   // Set the Text property and make the
          ///   // button the form's cancel button.
          ///   buttonCancel.Text = "&Cancel";
          ///   this.CancelButton = buttonCancel;
          ///
          ///   // Set the button size and location using
          ///   // the Bounds property.
          ///   Button buttonHelp;
          ///   buttonHelp.Bounds = Rectangle(10,10, 75, 25);
          ///   // Set the Text property of the button.
          ///   buttonHelp.Text = "&Help";
          ///
          ///   // Add the buttons to the form.
          ///   this->Controls().AddRange({buttonOK, buttonCancel, buttonHelp});
          /// }
          /// @endcode
          property_<int32> Height {
            get_ { return this->size.Height(); },
            set_ { this->Size(System::Drawing::Size(this->size.Width(), value)); }
          };

          /// @brief Gets a value indicating whether the control has a handle associated with it.
          /// @return bool true if a handle has been assigned to the control; otherwise, false.
          /// @remarks Use the IsHandleCreated property to determine whether CreateHandle has been called.
          property_<bool, readonly_> IsHandleCreated {
            get_ { return this->handle != 0; }
          };

          /// @brief Gets or sets the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
          /// @return int32 An Int32 representing the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
          /// @remarks The Left property value is equivalent to the Point.X property of the Location property value of the control.
          /// @remarks Changes made to the Width and Left property values cause the Right property value of the control to change.
          /// @par examples
          /// The following code example creates three Button controls on a form and sets their size and location by using the various size-related and location-related properties. This example requires that you have a Form that has a width and height of at least 300 pixels.
          /// @code
          /// // Create three buttons and place them on a form using
          /// // several size and location related properties.
          /// void AddOKCancelButtons() {
          ///   // Set the button size and location using
          ///   // the Size and Location properties.
          ///   Button buttonOK;
          ///   buttonOK.Location = Point(136,248);
          ///   buttonOK.Size = System::Drawing::Size(75,25);
          ///   // Set the Text property and make the
          ///   // button the form's default button.
          ///   buttonOK.Text = "&OK";
          ///   this.AcceptButton = buttonOK;
          ///
          ///   // Set the button size and location using the Top,
          ///   // Left, Width, and Height properties.
          ///   Button buttonCancel;
          ///   buttonCancel.Top = buttonOK.Top;
          ///   buttonCancel.Left = buttonOK.Right + 5;
          ///   buttonCancel.Width = buttonOK.Width;
          ///   buttonCancel.Height = buttonOK.Height;
          ///   // Set the Text property and make the
          ///   // button the form's cancel button.
          ///   buttonCancel.Text = "&Cancel";
          ///   this.CancelButton = buttonCancel;
          ///
          ///   // Set the button size and location using
          ///   // the Bounds property.
          ///   Button buttonHelp;
          ///   buttonHelp.Bounds = Rectangle(10,10, 75, 25);
          ///   // Set the Text property of the button.
          ///   buttonHelp.Text = "&Help";
          ///
          ///   // Add the buttons to the form.
          ///   this->Controls().AddRange({buttonOK, buttonCancel, buttonHelp});
          /// }
          /// @endcode
          property_<int32> Left {
            get_{ return this->location.X(); },
            set_{ this->Location(System::Drawing::Point(value, this->location.Y())); }
          };

          /// @brief Gets or sets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
          /// @return System::Drawing::Point The Point that represents the upper-left corner of the control relative to the upper-left corner of its container.
          /// @remarks Because the Point class is returned by value, meaning accessing the property returns a copy of the upper-left point of the control. So, adjusting the X or Y properties of the Point returned from this property will not affect the Left, Right, Top, or Bottom property values of the control. To adjust these properties set each property value individually, or set the Location property with a new Point.
          /// @remarks If the Control is a Form, the Location property value represents the upper-left corner of the Form in screen coordinates.
          /// @par examples
          /// The following code example creates a GroupBox and sets some of its common properties. The example creates a TextBox and sets its Location within the group box. Next, it sets the Text property of the group box, and docks the group box to the top of the form. Lastly, it disables the group box by setting the Enabled property to false, which causes all controls contained within the group box to be disabled.
          /// @code
          /// // Add a GroupBox to a form and set some of its common properties.
          /// void AddMyGroupBox() {
          ///   // Create a GroupBox and add a TextBox to it.
          ///   GroupBox groupBox1;
          ///   TextBox textBox1;
          ///   textBox1.Location = Point(15, 15);
          ///   groupBox1.Controls().Add(textBox1);
          ///
          ///   // Set the Text and Dock properties of the GroupBox.
          ///   groupBox1.Text = "MyGroupBox";
          ///   groupBox1.Dock = DockStyle::Top;
          ///
          ///   // Disable the GroupBox (which disables all its child controls)
          ///   groupBox1.Enabled = false;
          ///
          ///   // Add the Groupbox to the form.
          ///   this.Controls().Add(groupBox1);
          /// }
          /// @endcode
          property_<System::Drawing::Point> Location {
            get_ { return this->location; },
            set_ {
              if (this->location != value) {
                this->location = value;
                this->OnLocationChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets or sets the name of the control.
          /// @return string The name of the control. The default is an empty string ("").
          /// @remarks The Name property can be used at run time to evaluate the object by name rather than type and programmatic name.
          /// @par examples
          /// The following code example displays the Name of a control in a MessageBox when the control is added or removed from a form (Form1).
          /// @code
          /// // This example demonstrates the use of the ControlAdded and
          /// // ControlRemoved events. This example assumes that two Button controls
          /// // are added to the form and connected to the addControl_Click and
          /// // removeControl_Click event-handler methods.
          /// void Form1_Load(const object& sender, const System::EventArgs& e) {
          ///   // Connect the ControlRemoved and ControlAdded event handlers
          ///   // to the event-handler methods.
          ///   // ControlRemoved and ControlAdded are not available at design time.
          ///   this->ControlRemoved += System::Windows::Forms::ControlEventHandler(*this, &Form1::Control_Removed);
          ///   this.ControlAdded += System::Windows::Forms::ControlEventHandler(*this, &Form1::Control_Added);
          /// }
          ///
          /// void Control_Added(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
          ///   MessageBox::Show("The control named " + e.Control.Name + " has been added to the form.");
          /// }
          ///
          /// void Control_Removed(const object& sender, System::Windows::Forms::ControlEventArgs e) {
          ///   MessageBox.Show("The control named " + e.Control.Name + " has been removed from the form.");
          /// }
          ///
          /// // Click event handler for a Button control. Adds a TextBox to the form.
          /// void addControl_Click(const object& sender, const System::EventArgs& e) {
          ///   // Create a new TextBox control and add it to the form.
          ///   textBox1 = new_<TextBox>();
          ///   textBox1->Size = System::Drawing::Size(100,10);
          ///   textBox1->Location = Point(10,10);
          ///   // Name the control in order to remove it later. The name must be specified
          ///   // if a control is added at run time.
          ///   textBox1->Name = "textBox1";
          ///
          ///   // Add the control to the form's control collection.
          ///   this.Controls.Add(*textBox1);
          /// }
          ///
          /// // Click event handler for a Button control.
          /// // Removes the previously added TextBox from the form.
          /// void removeControl_Click(const object& sender, const System::EventArgs& e) {
          ///   // Loop through all controls in the form's control collection.
          ///   for (ref<Control> tempCtrl : this->Controls()) {
          ///     // Determine whether the control is textBox1,
          ///     // and if it is, remove it.
          ///     if (tempCtrl().Name == "textBox1") {
          ///       this.Controls().Remove(tempCtrl);
          ///     }
          ///   }
          /// }
          /// @endcode
          property_<string> Name {
            get_ { return this->name; },
            set_ {
              if (this->name != value)
                this->name = value;
            }
          };

          /// @brief Gets or sets the parent container of the control.
          /// @return Control A Control that represents the parent or container control of the control.
          /// @remarks Setting the Parent property value to null removes the control from the Control.ControlCollection of its current parent control.
          /// @par examples
          /// The following code example uses the Parent property and the FindForm method to set properties on the parent control of a button and its form.
          /// @code
          /// // This example uses the Parent property and the Find method of Control to set
          /// // properties on the parent control of a Button and its Form. The example assumes
          /// // that a Button control named button1 is located within a GroupBox control. The
          /// // example also assumes that the Click event of the Button control is connected to
          /// // the event handler method defined in the example.
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   // Get the control the Button control is located in. In this case a GroupBox.
          ///   ref<Control> control = button1.Parent;
          ///   // Set the text and backcolor of the parent control.
          ///   control.Text = "My Groupbox";
          ///   control.BackColor = Color::Blue;
          ///   // Get the form that the Button control is contained within.
          ///   ref<Form> myForm = button1.FindForm();
          ///   // Set the text and color of the form containing the Button.
          ///   myForm.Text = "The Form of My Control";
          ///   myForm.BackColor = Color::Red;
          /// }
          /// @endcode
          property_<ref<Control>> Parent {
            get_ {return this->parent;},
            set_ {this->SetParent(value);}
          };

          /// @brief Gets the distance, in pixels, between the right edge of the control and the left edge of its container's client area.
          /// @return int32 An Int32 representing the distance, in pixels, between the right edge of the control and the left edge of its container's client area.
          /// @remarks The value of the Right property is equal to the sum of the Left property value and the Width property value.
          /// @remarks The Right property is read-only. You can change this property value indirectly by changing the value of the Left or Width properties or calling the SetBounds, SetBoundsCore, UpdateBounds, or SetClientSizeCore methods.
          /// @par examples
          /// The following code example creates three Button controls on a form and sets their size and location by using the various size-related and location-related properties. This example requires that you have a Form that has a width and height of at least 300 pixels.
          /// @code
          /// // Create three buttons and place them on a form using
          /// // several size and location related properties.
          /// void AddOKCancelButtons() {
          ///   // Set the button size and location using
          ///   // the Size and Location properties.
          ///   Button buttonOK;
          ///   buttonOK.Location = Point(136,248);
          ///   buttonOK.Size = System::Drawing::Size(75,25);
          ///   // Set the Text property and make the
          ///   // button the form's default button.
          ///   buttonOK.Text = "&OK";
          ///   this.AcceptButton = buttonOK;
          ///
          ///   // Set the button size and location using the Top,
          ///   // Left, Width, and Height properties.
          ///   Button buttonCancel;
          ///   buttonCancel.Top = buttonOK.Top;
          ///   buttonCancel.Left = buttonOK.Right + 5;
          ///   buttonCancel.Width = buttonOK.Width;
          ///   buttonCancel.Height = buttonOK.Height;
          ///   // Set the Text property and make the
          ///   // button the form's cancel button.
          ///   buttonCancel.Text = "&Cancel";
          ///   this.CancelButton = buttonCancel;
          ///
          ///   // Set the button size and location using
          ///   // the Bounds property.
          ///   Button buttonHelp;
          ///   buttonHelp.Bounds = Rectangle(10,10, 75, 25);
          ///   // Set the Text property of the button.
          ///   buttonHelp.Text = "&Help";
          ///
          ///   // Add the buttons to the form.
          ///   this->Controls().AddRange({buttonOK, buttonCancel, buttonHelp});
          /// }
          /// @endcode
          property_<int32, readonly_> Right{
            get_{ return this->location.X() + this->size.Width(); }
          };

          /// @brief Gets or sets the height and width of the control.
          /// @return System::Drawing::Size The Size that represents the height and width of the control in pixels.
          /// @remarks Because the Size class is returned by value, meaning accessing the property returns a copy of the size of the control. So, adjusting the Width or Height properties of the Size returned from this property will not affect the Width or Height of the control. To adjust the Width or Height of the control, you must set the control's Width or Height property, or set the Size property with a new Size.
          /// @note To maintain better performance, do not set the Size of a control in its constructor. The preferred method is to override the DefaultSize property.
          /// @par examples
          /// The following code example adds a Button to a form and sets some of its common properties. The example anchors the button to the bottom-right corner of the form so it keeps its relative position as the form is resized. Next it sets the BackgroundImage and resizes the button to the same size as theImage. The example then sets the TabStop to true and sets the TabIndex property. Lastly, it adds an event handler to handle the Click event of the button. This example requires that you have an ImageList named imageList1.
          /// @code
          /// $<Button> button1;
          ///
          /// // Add a button to a form and set some of its common properties.
          /// void AddMyButton() {
          ///   // Create a button and add it to the form.
          ///   this->button1 = new_<Button>();
          ///
          ///   // Anchor the button to the bottom right corner of the form
          ///   this->button1->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
          ///
          ///   // Assign a background image.
          ///   this->button1->BackgroundImage = this->imageList1->Images()[0];
          ///
          ///   // Specify the layout style of the background image. Tile is the default.
          ///   this->button1->BackgroundImageLayout = ImageLayout::Center;
          ///
          ///   // Make the button the same size as the image.
          ///   this->button1->Size = this->button1->BackgroundImage().Size;
          ///
          ///   // Set the button's TabIndex and TabStop properties.
          ///   this->button1->TabIndex = 1;
          ///   this->button1->TabStop = true;
          ///
          ///   // Add a delegate to handle the Click event.
          ///   this->button1->Click += System::EventHandler(*this, &Form1::button1_Click);
          ///
          ///   // Add the button to the form.
          ///   this->Controls().Add(*this->button1);
          /// }
          /// @endcode
          property_<System::Drawing::Size> Size {
            get_ { return this->size; },
            set_ {
              if (this->size != value) {
                this->size = value;
                this->OnSizeChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets or sets a value indicating whether the user can give the focus to this control using the TAB key.
          /// @return bool true if the user can give the focus to the control using the TAB key; otherwise, false. The default is true.
          /// @note This property will always return true for an instance of the Form class.
          /// @remarks When the user presses the TAB key, the input focus is set to the next control in the tab order. Controls with the TabStop property value of false are not included in the collection of controls in the tab order. The tab order can be manipulated by setting the control's TabIndex property value.
          /// @par examples
          /// The following code example adds a Button to a form and sets some of its common properties. The example anchors the button to the bottom-right corner of the form so it keeps its relative position as the form is resized. Next it sets the BackgroundImage and resizes the button to the same size as theImage. The example then sets the TabStop to true and sets the TabIndex property. Lastly, it adds an event handler to handle the Click event of the button. This example requires that you have an ImageList named imageList1.
          /// @code
          /// $<Button> button1;
          ///
          /// // Add a button to a form and set some of its common properties.
          /// void AddMyButton() {
          ///   // Create a button and add it to the form.
          ///   this->button1 = new_<Button>();
          ///
          ///   // Anchor the button to the bottom right corner of the form
          ///   this->button1->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
          ///
          ///   // Assign a background image.
          ///   this->button1->BackgroundImage = this->imageList1->Images()[0];
          ///
          ///   // Specify the layout style of the background image. Tile is the default.
          ///   this->button1->BackgroundImageLayout = ImageLayout::Center;
          ///
          ///   // Make the button the same size as the image.
          ///   this->button1->Size = this->button1->BackgroundImage().Size;
          ///
          ///   // Set the button's TabIndex and TabStop properties.
          ///   this->button1->TabIndex = 1;
          ///   this->button1->TabStop = true;
          ///
          ///   // Add a delegate to handle the Click event.
          ///   this->button1->Click += System::EventHandler(*this, &Form1::button1_Click);
          ///
          ///   // Add the button to the form.
          ///   this->Controls().Add(*this->button1);
          /// }
          /// @endcode
          property_<bool> TabStop {
            get_ {return this->tabStop;},
            set_ {
              if (this->tabStop != value) {
                this->tabStop = value;
                this->OnTabStopChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets or sets the text associated with this control.
          /// @return string The text associated with this control.
          /// @remarks The Text property of the control is used differently by each derived class. For example the Text property of a Form is displayed in the title bar at the top of the form, is fairly small in character count, and usually displays the application or document name. However, the Text property of a RichTextBox can be large and can include numerous nonvisual characters used to format the text. For example, the text displayed in a RichTextBox can be formatted by adjusting the Font properties, or by the addition of spaces or tab characters to align the text.
          /// @par Notes to Inheritors
          /// When overriding the Text property in a derived class, use the base class's Text property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and setaccessors of the Text property; you can override only one if needed.
          /// @par examples
          /// The following code example creates a GroupBox and sets some of its common properties. The example creates a TextBox and sets its Location within the group box. Next, it sets the Text property of the group box, and docks the group box to the top of the form. Lastly, it disables the group box by setting the Enabled property to false, which causes all controls contained within the group box to be disabled.
          /// @code
          /// // Add a GroupBox to a form and set some of its common properties.
          /// void AddMyGroupBox() {
          ///   // Create a GroupBox and add a TextBox to it.
          ///   GroupBox groupBox1;
          ///   TextBox textBox1;
          ///   textBox1.Location = Point(15, 15);
          ///   groupBox1.Controls().Add(textBox1);
          ///
          ///   // Set the Text and Dock properties of the GroupBox.
          ///   groupBox1.Text = "MyGroupBox";
          ///   groupBox1.Dock = DockStyle::Top;
          ///
          ///   // Disable the GroupBox (which disables all its child controls)
          ///   groupBox1.Enabled = false;
          ///
          ///   // Add the Groupbox to the form.
          ///   this.Controls().Add(groupBox1);
          /// }
          /// @endcode
          property_<const string&> Text {
            get_->const string& { return this->text; },
            set_ {
              if (this->text != value) {
                this->text = value;
                this->OnTextChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets or sets the distance, in pixels, between the top edge of the control and the top edge of its container's client area.
          /// @return int32 An Int32 representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
          /// @remarks The Top property value is equivalent to the Point.Y property of the Location property value of the control.
          /// @remarks Changes made to the Height and Top property values cause the Bottom property value of the control to change.
          /// @par examples
          /// The following code example creates three Button controls on a form and sets their size and location by using the various size-related and location-related properties. This example requires that you have a Form that has a width and height of at least 300 pixels.
          /// @code
          /// // Create three buttons and place them on a form using
          /// // several size and location related properties.
          /// void AddOKCancelButtons() {
          ///   // Set the button size and location using
          ///   // the Size and Location properties.
          ///   Button buttonOK;
          ///   buttonOK.Location = Point(136,248);
          ///   buttonOK.Size = System::Drawing::Size(75,25);
          ///   // Set the Text property and make the
          ///   // button the form's default button.
          ///   buttonOK.Text = "&OK";
          ///   this.AcceptButton = buttonOK;
          ///
          ///   // Set the button size and location using the Top,
          ///   // Left, Width, and Height properties.
          ///   Button buttonCancel;
          ///   buttonCancel.Top = buttonOK.Top;
          ///   buttonCancel.Left = buttonOK.Right + 5;
          ///   buttonCancel.Width = buttonOK.Width;
          ///   buttonCancel.Height = buttonOK.Height;
          ///   // Set the Text property and make the
          ///   // button the form's cancel button.
          ///   buttonCancel.Text = "&Cancel";
          ///   this.CancelButton = buttonCancel;
          ///
          ///   // Set the button size and location using
          ///   // the Bounds property.
          ///   Button buttonHelp;
          ///   buttonHelp.Bounds = Rectangle(10,10, 75, 25);
          ///   // Set the Text property of the button.
          ///   buttonHelp.Text = "&Help";
          ///
          ///   // Add the buttons to the form.
          ///   this->Controls().AddRange({buttonOK, buttonCancel, buttonHelp});
          /// }
          /// @endcode
          property_<int32> Top {
            get_{ return this->location.Y(); },
            set_{ this->Location(System::Drawing::Point(this->location.X(), value)); }
          };

          /// @brief Gets or sets a value indicating whether the control and all its child controls are displayed.
          /// @return bool true if the control and all its child controls are displayed; otherwise, false. The default is true.
          /// @remarks Note that even if Visible is set to true, the control might not be visible to the user if it is obscured behind other controls.
          /// @par examples
          /// The following code example uses the derived classes VScrollBar and HScrollBar and sets their Visible property values, based on the size of an Image being displayed in a PictureBox control. This example requires that a PictureBox has been created on a form and that HScrollBar and VScrollBar controls have been created on the PictureBox. This code should be called when the image is loaded into the picture box and by the Resize event of the form.
          /// @code
          /// void DisplayScrollBars() {
          ///   // Display or hide the scroll bars based upon
          ///   // whether the image is larger than the PictureBox.
          ///   if (pictureBox1.Width > pictureBox1.Image().Width) {
          ///     hScrollBar1.Visible = false;
          ///   } else {
          ///     hScrollBar1.Visible = true;
          ///   }
          ///
          ///   if (pictureBox1.Height > pictureBox1.Image().Height) {
          ///     vScrollBar1.Visible = false;
          ///   } else {
          ///     vScrollBar1.Visible = true;
          ///   }
          /// }
          /// @endcode
          property_<bool> Visible {
            get_ { return this->visible; },
            set_ {
              if (this->visible != value) {
                this->visible = value;
                this->OnVisibleChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets or sets the width of the control.
          /// @return int32 The width of the control in pixels.
          /// @remarks Changes made to the Width and Left property values cause the Right property value of the control to change.
          /// @par examples
          /// The following code example creates three Button controls on a form and sets their size and location by using the various size-related and location-related properties. This example requires that you have a Form that has a width and height of at least 300 pixels.
          /// @code
          /// // Create three buttons and place them on a form using
          /// // several size and location related properties.
          /// void AddOKCancelButtons() {
          ///   // Set the button size and location using
          ///   // the Size and Location properties.
          ///   Button buttonOK;
          ///   buttonOK.Location = Point(136,248);
          ///   buttonOK.Size = System::Drawing::Size(75,25);
          ///   // Set the Text property and make the
          ///   // button the form's default button.
          ///   buttonOK.Text = "&OK";
          ///   this.AcceptButton = buttonOK;
          ///
          ///   // Set the button size and location using the Top,
          ///   // Left, Width, and Height properties.
          ///   Button buttonCancel;
          ///   buttonCancel.Top = buttonOK.Top;
          ///   buttonCancel.Left = buttonOK.Right + 5;
          ///   buttonCancel.Width = buttonOK.Width;
          ///   buttonCancel.Height = buttonOK.Height;
          ///   // Set the Text property and make the
          ///   // button the form's cancel button.
          ///   buttonCancel.Text = "&Cancel";
          ///   this.CancelButton = buttonCancel;
          ///
          ///   // Set the button size and location using
          ///   // the Bounds property.
          ///   Button buttonHelp;
          ///   buttonHelp.Bounds = Rectangle(10,10, 75, 25);
          ///   // Set the Text property of the button.
          ///   buttonHelp.Text = "&Help";
          ///
          ///   // Add the buttons to the form.
          ///   this->Controls().AddRange({buttonOK, buttonCancel, buttonHelp});
          /// }
          /// @endcode
          property_<int32> Width {
            get_ { return this->size.Width(); },
            set_ { this->Size(System::Drawing::Size(value, this->size.Height())); }
          };

          /// @brief Forces the creation of the visible control, including the creation of the handle and any visible child controls.
          /// @remarks The CreateControl method forces a handle to be created for the control and its child controls. This method is used when you need a handle immediately for manipulation of the control or its children; simply calling a control's constructor does not create the Handle.
          /// @remarks CreateControl does not create a control handle if the control's Visible property is false. You can either call the CreateHandle method or access the Handle property to create the control's handle regardless of the control's visibility, but in this case, no window handles are created for the control's children.
          void CreateControl();

          /// @brief Retrieves the form that the control is on.
          /// @return Form The Form that the control is on.
          /// @remarks The control's Parent property value might not be the same as the Form returned by FindForm method. For example, if a RadioButton control is contained within a GroupBox control, and the GroupBox is on a Form, the RadioButton control's Parent is the GroupBox and the GroupBox control's Parent is the Form.
          /// @par examples
          /// The following code example uses the Parent property and the FindForm method to set properties on the parent control of a button and its form.
          /// @code
          /// // This example uses the Parent property and the Find method of Control to set
          /// // properties on the parent control of a Button and its Form. The example assumes
          /// // that a Button control named button1 is located within a GroupBox control. The
          /// // example also assumes that the Click event of the Button control is connected to
          /// // the event handler method defined in the example.
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   // Get the control the Button control is located in. In this case a GroupBox.
          ///   ref<Control> control = button1.Parent;
          ///   // Set the text and backcolor of the parent control.
          ///   control.Text = "My Groupbox";
          ///   control.BackColor = Color::Blue;
          ///   // Get the form that the Button control is contained within.
          ///   ref<Form> myForm = button1.FindForm();
          ///   // Set the text and color of the form containing the Button.
          ///   myForm.Text = "The Form of My Control";
          ///   myForm.BackColor = Color::Red;
          /// }
          /// @endcode
          ref<Form> FindForm() const;

          /// @brief Sets input focus to the control.
          /// @return bool true if the input focus request was successful; otherwise, false.
          /// @remarks The Focus method returns true if the control successfully received input focus. The control can have the input focus while not displaying any visual cues of having the focus. This behavior is primarily observed by the nonselectable controls listed below, or any controls derived from them.
          /// @remarks A control can be selected and receive input focus if all the following are true: the Selectable value of ControlStyles is set to true, it is contained in another control, and all its parent controls are both visible and enabled.
          /// @remarks The Windows Forms controls in the following list are not selectable. Controls derived from these controls are also not selectable.
          /// * Panel
          /// * GroupBox
          /// * PictureBox
          /// * ProgressBar
          /// * Splitter
          /// * Label
          /// * LinkLabel (when there is no link present in the control)
          /// @note Focus is a low-level method intended primarily for custom control authors. Instead, application programmers should use the Select method or the ActiveControl property for child controls, or the Activate method for forms.
          /// @par examples
          /// The following code example sets focus to the specified Control, if it can receive focus.
          /// @code
          /// void ControlSetFocus(Control& control) {
          ///   // Set focus to the control, if it can receive focus.
          ///   if(control.CanFocus) {
          ///     control.Focus();
          ///   }
          /// }
          /// @endcode
          bool Focus();

          /// @brief Retrieves the control that contains the specified handle.
          /// @param handle The window handle (HWND) to search for.
          /// @return Control The Control that represents the control associated with the specified handle; returns null if no control with the specified handle is found.
          /// @remarks This method searches up the window handle parent chain until it finds a handle that is associated with a control. This method is more reliable than the FromHandle method, because it correctly returns controls that own more than one handle.
          static ref<Control> FromChildHandle(intptr handle) {
            try {
              return handles[handle]().Parent;
            } catch (...) {
              return ref<Control>::Null();
            }
          }

          /// @brief Returns the control that is currently associated with the specified handle.
          /// @param handle The window handle (HWND) to search for.
          /// @return Control A Control that represents the control associated with the specified handle; returns null if no control with the specified handle is found.
          /// @remarks Use the FromChildHandle method if you need to return controls that own more than one handle.
          static ref<Control> FromHandle(intptr handle) {
            try {
              return handles[handle];
            } catch (...) {
              return ref<Control>::Null();
            }
          }

          /// @brief Conceals the control from the user.
          /// @remarks Hiding the control is equivalent to setting the Visible property to false. After the Hide method is called, the Visible property returns a value of false until the Show method is called.
          /// @par examples
          /// The following code example hides a button if the CTRL key is pressed when the button is clicked. This example requires that you have a Button named button1 on a Form.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   /* If the CTRL key is pressed when the
          ///    * control is clicked, hide the control. */
          ///   if((this->button1.ModifierKeys == Keys::Control) {
          ///     this->button1.Hide();
          ///   }
          /// }
          /// @endcode
          void Hide();

          /// @brief Invalidates the entire surface of the control and causes the control to be redrawn.
          /// @remarks Calling the Invalidate method does not force a synchronous paint; to force a synchronous paint, call the Update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
          /// @par examples
          /// The following code example enables the user to drag an image or image file onto the form, and have it be displayed at the point on it is dropped. The OnPaint method is overridden to repaint the image each time the form is painted; otherwise the image would only persist until the next repainting. The DragEnter event-handling method determines the type of data being dragged into the form and provides the appropriate feedback. The DragDrop event-handling method displays the image on the form, if an Image can be created from the data. Because the DragEventArgs.X and DragEventArgs.Y values are screen coordinates, the example uses the PointToClient method to convert them to client coordinates.
          /// @code
          /// private:
          ///   $<Image> picture;
          ///   Point pictureLocation;
          ///
          /// public:
          ///   Form1() {
          ///     // Enable drag-and-drop operations and
          ///     // add handlers for DragEnter and DragDrop.
          ///     this->AllowDrop = true;
          ///     this->DragDrop += DragEventHandler(*this, &Form1::Form1_DragDrop);
          ///     this->DragEnter += DragEventHandler(*this, &Form1::Form1_DragEnter);
          ///   }
          ///
          /// protected:
          ///   void OnPaint(PaintEventArgs& e) override {
          ///     // If there is an image and it has a location,
          ///     // paint it when the Form is repainted.
          ///     this->Form::OnPaint(e);
          ///     if(this->picture != null && this->pictureLocation != Point::Empty) {
          ///       e.Graphics.DrawImage(*this->picture, this.pictureLocation);
          ///     }
          ///   }
          ///
          /// private:
          ///   void Form1_DragDrop(const object& sender, DragEventArgs& e) {
          ///     // Handle FileDrop data.
          ///     if (e.Data.GetDataPresent(DataFormats::FileDrop) ) {
          ///       // Assign the file names to a string array, in
          ///       // case the user has selected multiple files.
          ///       $<Array<string>> files = as<Array<string>>(e.Data.GetData(DataFormats::FileDrop));
          ///       try {
          ///         // Assign the first image to the picture variable.
          ///         this->picture = Image::FromFile((*files)[0]);
          ///         // Set the picture location equal to the drop point.
          ///         this->pictureLocation = this->PointToClient(Point(e.X, e.Y));
          ///       } catch(const Exception& ex) {
          ///         MessageBox::Show(ex.Message);
          ///         return;
          ///       }
          ///     }
          ///
          ///     // Handle Bitmap data.
          ///     if (e.Data.GetDataPresent(DataFormats::Bitmap) ) {
          ///       try {
          ///         // Create an Image and assign it to the picture variable.
          ///         this->picture = as<Image>(e.Data.GetData(DataFormats.Bitmap));
          ///         // Set the picture location equal to the drop point.
          ///         this->pictureLocation = this->PointToClient(Point(e.X, e.Y) );
          ///       } catch(const Exception& ex) {
          ///         MessageBox::Show(ex.Message);
          ///         return;
          ///       }
          ///     }
          ///     // Force the form to be redrawn with the image.
          ///     this->Invalidate();
          ///   }
          ///
          ///   void Form1_DragEnter(const object& sender, DragEventArgs& e) {
          ///     // If the data is a file or a bitmap, display the copy cursor.
          ///     if (e.Data.GetDataPresent(DataFormats::Bitmap) || e.Data.GetDataPresent(DataFormats::FileDrop) ) {
          ///       e.Effect = DragDropEffects::Copy;
          ///     } else {
          ///       e.Effect = DragDropEffects::None;
          ///     }
          ///   }
          /// @endcode
          void Invalidate() { Invalidate(false); }

          /// @brief Invalidates a specific region of the control and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
          /// @param invalidateChildren true to invalidate the control's child controls; otherwise, false.
          /// @remarks Calling the Invalidate method does not force a synchronous paint; to force a synchronous paint, call the Update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
          void Invalidate(bool invalidateChildren);

          /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control.
          /// @param rect A Rectangle that represents the region to invalidate.
          /// @remarks Calling the Invalidate method does not force a synchronous paint; to force a synchronous paint, call the Update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
          void Invalidate(const System::Drawing::Rectangle& rect) { Invalidate(rect, false); }

          /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
          /// @param rect A Rectangle that represents the region to invalidate.
          /// @param invalidateChildren true to invalidate the control's child controls; otherwise, false.
          /// @remarks Calling the Invalidate method does not force a synchronous paint; to force a synchronous paint, call the Update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
          void Invalidate(const System::Drawing::Rectangle& rect, bool invalidateChildren);

          /// @brief Forces the control to apply layout logic to all its child controls.
          /// @remarks If the SuspendLayout method was called before calling the PerformLayout method, the Layout event is suppressed.
          /// @remarks The AffectedControl and AffectedProperty properties of the LayoutEventArgs created are set to null if no values were provided when the PerformLayout method was called.
          /// @par Examples
          /// The following code example demonstrates how to use the PerformLayout method. It also demonstrates ways in which the Layout event is raised. In this example, the Click event handler for Button1 explicitly calls PerformLayout. The Click event handler for Button2 implicitly calls PerformLayout. PerformLayout is also called when the form is loaded. Button3 returns the control to the state it was in when loaded. In each case, the Layout event is raised.<br><br>
          /// This is a complete example. To run the example, paste the following code in a blank form.
          /// @include PerformLayout.cpp
          void PerformLayout() {

          }

          /// @brief Computes the location of the specified screen point into client coordinates.
          /// @param point The screen coordinate Point to convert.
          /// @return System::Drawing::Point A Point that represents the converted Point, p, in client coordinates.
          /// @par examples
          /// The following code example enables the user to drag an image or image file onto the form, and have it be displayed at the point on it is dropped. The OnPaint method is overridden to repaint the image each time the form is painted; otherwise the image would only persist until the next repainting. The DragEnter event-handling method determines the type of data being dragged into the form and provides the appropriate feedback. The DragDrop event-handling method displays the image on the form, if an Image can be created from the data. Because the DragEventArgs.X and DragEventArgs.Y values are screen coordinates, the example uses the PointToClient method to convert them to client coordinates.
          /// @code
          /// private:
          ///   $<Image> picture;
          ///   Point pictureLocation;
          ///
          /// public:
          ///   Form1() {
          ///     // Enable drag-and-drop operations and
          ///     // add handlers for DragEnter and DragDrop.
          ///     this->AllowDrop = true;
          ///     this->DragDrop += DragEventHandler(*this, &Form1::Form1_DragDrop);
          ///     this->DragEnter += DragEventHandler(*this, &Form1::Form1_DragEnter);
          ///   }
          ///
          /// protected:
          ///   void OnPaint(PaintEventArgs& e) override {
          ///     // If there is an image and it has a location,
          ///     // paint it when the Form is repainted.
          ///     this->Form::OnPaint(e);
          ///     if(this->picture != null && this->pictureLocation != Point::Empty) {
          ///       e.Graphics.DrawImage(*this->picture, this.pictureLocation);
          ///     }
          ///   }
          ///
          /// private:
          ///   void Form1_DragDrop(const object& sender, DragEventArgs& e) {
          ///     // Handle FileDrop data.
          ///     if (e.Data.GetDataPresent(DataFormats::FileDrop) ) {
          ///       // Assign the file names to a string array, in
          ///       // case the user has selected multiple files.
          ///       $<Array<string>> files = as<Array<string>>(e.Data.GetData(DataFormats::FileDrop));
          ///       try {
          ///         // Assign the first image to the picture variable.
          ///         this->picture = Image::FromFile((*files)[0]);
          ///         // Set the picture location equal to the drop point.
          ///         this->pictureLocation = this->PointToClient(Point(e.X, e.Y));
          ///       } catch(const Exception& ex) {
          ///         MessageBox::Show(ex.Message);
          ///         return;
          ///       }
          ///     }
          ///
          ///     // Handle Bitmap data.
          ///     if (e.Data.GetDataPresent(DataFormats::Bitmap) ) {
          ///       try {
          ///         // Create an Image and assign it to the picture variable.
          ///         this->picture = as<Image>(e.Data.GetData(DataFormats.Bitmap));
          ///         // Set the picture location equal to the drop point.
          ///         this->pictureLocation = this->PointToClient(Point(e.X, e.Y) );
          ///       } catch(const Exception& ex) {
          ///         MessageBox::Show(ex.Message);
          ///         return;
          ///       }
          ///     }
          ///     // Force the form to be redrawn with the image.
          ///     this->Invalidate();
          ///   }
          ///
          ///   void Form1_DragEnter(const object& sender, DragEventArgs& e) {
          ///     // If the data is a file or a bitmap, display the copy cursor.
          ///     if (e.Data.GetDataPresent(DataFormats::Bitmap) || e.Data.GetDataPresent(DataFormats::FileDrop) ) {
          ///       e.Effect = DragDropEffects::Copy;
          ///     } else {
          ///       e.Effect = DragDropEffects::None;
          ///     }
          ///   }
          /// @endcode
          System::Drawing::Point PointToClient(System::Drawing::Point point) const;

          /// @brief Computes the location of the specified client point into screen coordinates.
          /// @param point The client coordinate Point to convert.
          /// @return System::Drawing::Point A Point that represents the converted Point, p, in screen coordinates.
          /// @par examples
          /// The following code example demonstrates how to use the BackColor, RectangleToScreen, PointToScreen, MouseButtons, ControlPaint::DrawReversibleFrame, and Rectangle::IntersectsWith members. To run the example, paste the following code in a form called Form1 containing several controls. This example requires that the MouseDown, MouseMove, and MouseUp events are connected to the event handlers defined in the example.
          /// @code
          /// // The following three methods will draw a rectangle and allow
          /// // the user to use the mouse to resize the rectangle.  If the
          /// // rectangle intersects a control's client rectangle, the
          /// // control's color will change.
          ///
          /// bool isDrag = false;
          /// Rectangle theRectangle(Point(0, 0), Size(0, 0));
          /// Point startPoint;
          ///
          /// void Form1_MouseDown(const object& sender, const System::Windows::Forms::MouseEventArgs& e) {
          ///   // Set the isDrag variable to true and get the starting point by using the PointToScreen method
          ///   // to convert form coordinates to screen coordinates.
          ///   if (e.Button == MouseButtons::Left) {
          ///     isDrag = true;
          ///   }
          ///
          ///   // Calculate the startPoint by using the PointToScreen method.
          ///   startPoint = as<Control>(sender).PointToScreen(Point(e.X, e.Y));
          /// }
          ///
          /// void Form1_MouseMove(const object& sender, const System::Windows::Forms::MouseEventArgs& e) {
          ///   // If the mouse is being dragged, undraw and redraw the rectangle as the mouse moves.
          ///   if (isDrag) {
          ///     // Hide the previous rectangle by calling the DrawReversibleFrame method with the same parameters.
          ///     ControlPaint::DrawReversibleFrame(theRectangle, this->BackColor, FrameStyle::Dashed);
          ///
          ///     // Calculate the endpoint and dimensions for the new rectangle, again using the PointToScreen method.
          ///     Point endPoint = as<Control>(sender).PointToScreen(Point(e.X, e.Y));
          ///
          ///     int width = endPoint.X-startPoint.X;
          ///     int height = endPoint.Y-startPoint.Y;
          ///     theRectangle = Rectangle(startPoint.X, startPoint.Y, width, height);
          ///
          ///     // Draw the new rectangle by calling DrawReversibleFrame again.
          ///     ControlPaint::DrawReversibleFrame(theRectangle, this.BackColor, FrameStyle.Dashed);
          ///   }
          /// }
          ///
          /// void Form1_MouseUp(const object& sender, const System::Windows::Forms::MouseEventArgs& e) {
          ///   // If the MouseUp event occurs, the user is not dragging.
          ///   isDrag = false;
          ///
          ///   // Draw the rectangle to be evaluated. Set a dashed frame style using the FrameStyle enumeration.
          ///   ControlPaint::DrawReversibleFrame(theRectangle, this.BackColor, FrameStyle.Dashed);
          ///
          ///   // Find out which controls intersect the rectangle and change their color. The method uses the
          ///   // RectangleToScreen method to convert the Control's client coordinates to screen coordinates.
          ///   Rectangle controlRectangle;
          ///   for (int i = 0; i < Controls().Count; i++) {
          ///     controlRectangle = Controls()[i].RectangleToScreen(Controls()[i].ClientRectangle);
          ///     if (controlRectangle.IntersectsWith(theRectangle)) {
          ///       Controls()[i].BackColor = Color::BurlyWood;
          ///     }
          ///   }
          ///
          ///   // Reset the rectangle.
          ///   theRectangle = Rectangle(0, 0, 0, 0);
          /// }
          /// @endcode
          System::Drawing::Point PointToScreen(System::Drawing::Point point) const;

          /// @brief Preprocesses keyboard or input messages within the message loop before they are dispatched.
          /// @param msg A Message, passed by reference, that represents the message to process. The possible values are WM_KEYDOWN, WM_SYSKEYDOWN, WM_CHAR, and WM_SYSCHAR.
          /// @remarks PreProcessMessage is called by the application's message loop to preprocess input messages before they are dispatched. Possible values for the msg parameter are WM_KEYDOWN, WM_SYSKEYDOWN, WM_CHAR, and WM_SYSCHAR.
          /// @remarks When overriding PreProcessMessage, a control should return true to indicate that it has processed the message. For messages that are not processed by the control, the result of base.PreProcessMessage should be returned. Controls will typically override one of the more specialized methods such as IsInputChar, IsInputKey, ProcessCmdKey, ProcessDialogChar, or ProcessDialogKey instead of overriding PreProcessMessage.
          bool PreProcessMessage(const Message& msg);

          /// @brief Forces the control to invalidate its client area and immediately redraw itself and any child controls.
          /// @par Notes to Inheritors
          /// When overriding Refresh in a derived class, be sure to call the base class's Refresh method so the control and its child controls are invalidated and redrawn.
          virtual void Refresh() {
            this->Invalidate();
            this->Update();
          }

          /// @brief Resumes usual layout logic.
          /// @remarks Calling the ResumeLayout method forces an immediate layout if there are any pending layout requests.
          /// @remarks The SuspendLayout and ResumeLayout methods are used in tandem to suppress multiple Layout events while you adjust multiple attributes of the control. For example, you would typically call the SuspendLayout method, then set the Size, Location, Anchor, or Dock properties of the control, and then call the ResumeLayout method to enable the changes to take effect.
          /// @remarks There must be no pending calls to SuspendLayout for ResumeLayout to be successfully called.
          /// @par Examples
          /// The following code example adds two buttons to a form. The example transactions the addition of the buttons by using the SuspendLayout and ResumeLayout methods.
          /// @code
          /// void AddButtons() {
          ///   // Suspend the form layout and add two buttons.
          ///   this->SuspendLayout();
          ///   buttonOK.Location = Point(10, 10);
          ///   buttonOK.Size = System::Drawing::Size(75, 25);
          ///   buttonOK.Text = "OK";
          ///
          ///   buttonCancel.Location = Point(90, 10);
          ///   buttonCancel.Size = System::Drawing::Size(75, 25);
          ///   buttonCancel.Text = "Cancel";
          ///
          ///   this->Controls().AddRange({buttonOK, buttonCancel});
          ///   this->ResumeLayout();
          /// }
          /// @endcode
          void ResumeLayout() {
            this->suspendLayout = false;
          }

          /// @brief Resumes usual layout logic, optionally forcing an immediate layout of pending layout requests.
          /// @param performLayout true to execute pending layout requests; otherwise, false.
          /// @remarks Calling the ResumeLayout method forces an immediate layout if there are any pending layout requests. When the performLayout parameter is set to true, an immediate layout occurs if there are any pending layout requests.
          /// @remarks The SuspendLayout and ResumeLayout methods are used in tandem to suppress multiple Layout events while you adjust multiple attributes of the control. For example, you would typically call the SuspendLayout method, then set the Size, Location, Anchor, or Dock properties of the control, and then call the ResumeLayout method to enable the changes to take effect.
          /// @remarks There must be no pending calls to SuspendLayout for ResumeLayout to be successfully called.
          /// @note When adding several controls to a parent control, it is recommended that you call the SuspendLayout method before initializing the controls to be added. After adding the controls to the parent control, call the ResumeLayout method. This will increase the performance of applications with many controls.
          void ResumeLayout(bool performLayout) {
            this->ResumeLayout();
            if (performLayout)
              this->PerformLayout();
          }

          /// @brief Displays the control to the user.
          /// @remarks Showing the control is equivalent to setting the Visible property to true. After the Show method is called, the Visible property returns a value of true until the Hide method is called.
          /// @par Examples
          /// The following code example displays an about dialog box and temporarily draws a blue square on its surface. This example requires that you have defined a class that derives from Form named AboutDialog.
          /// @code
          /// void menuItemHelpAbout_Click(const object& sender, const EventArgs& e) {
          ///   // Create and display a modless about dialog box.
          ///   AboutDialog about;
          ///   about.Show();
          ///
          ///   // Draw a blue square on the form.
          ///   /* NOTE: This is not a persistent object, it will no longer be
          ///    * visible after the next call to OnPaint. To make it persistent,
          ///    * override the OnPaint method and draw the square there */
          ///   Graphics g = about.CreateGraphics();
          ///   g.FillRectangle(Brushes.Blue, 10, 10, 50, 50);
          /// }
          /// @endcode
          void Show();

          /// @brief Sets the bounds of the control to the specified location and size.
          /// @param x The new Left property value of the control.
          /// @param y The new Top property value of the control.
          /// @param width The new Width property value of the control.
          /// @param height The new Height property value of the control.
          void SetBounds(int32 x, int32 y, int32 width, int32 height) {
            this->Location = System::Drawing::Point(x, y);
            this->Size = System::Drawing::Size(width, height);
          }

          /// @brief Temporarily suspends the layout logic for the control.
          /// @remarks The layout logic of the control is suspended until the ResumeLayout method is called.
          /// @remarks The SuspendLayout and ResumeLayout methods are used in tandem to suppress multiple Layout events while you adjust multiple attributes of the control. For example, you would typically call the SuspendLayout method, then set the Size, Location, Anchor, or Dock properties of the control, and then call the ResumeLayout method to enable the changes to take effect.
          /// @remarks There must be no pending calls to SuspendLayout for ResumeLayout to be successfully called.
          /// @note When adding several controls to a parent control, it is recommended that you call the SuspendLayout method before initializing the controls to be added. After adding the controls to the parent control, call the ResumeLayout method. This will increase the performance of applications with many controls.
          /// @par Examples
          /// The following code example adds two buttons to a form. The example transactions the addition of the buttons by using the SuspendLayout and ResumeLayout methods.
          /// @code
          /// void AddButtons() {
          ///   // Suspend the form layout and add two buttons.
          ///   this->SuspendLayout();
          ///   buttonOK.Location = Point(10, 10);
          ///   buttonOK.Size = System::Drawing::Size(75, 25);
          ///   buttonOK.Text = "OK";
          ///
          ///   buttonCancel.Location = Point(90, 10);
          ///   buttonCancel.Size = System::Drawing::Size(75, 25);
          ///   buttonCancel.Text = "Cancel";
          ///
          ///   this->Controls().AddRange({buttonOK, buttonCancel});
          ///   this->ResumeLayout();
          /// }
          /// @endcode
          void SuspendLayout() {
            this->suspendLayout = true;
          }

          /// @brief Causes the control to redraw the invalidated regions within its client area.
          /// @remarks Executes any pending requests for painting.
          /// @remarks There are two ways to repaint a form and its contents:
          /// * You can use one of the overloads of the Invalidate method with the Update method.
          /// * You can call the Refresh method, which forces the control to redraw itself and all its children. This is equivalent to setting the Invalidate method to true and using it with Update.
          /// @remarks The Invalidate method governs what gets painted or repainted. The Update method governs when the painting or repainting occurs. If you use the Invalidate and Update methods together rather than calling Refresh, what gets repainted depends on which overload of Invalidate you use. The Update method just forces the control to be painted immediately, but the Invalidate method governs what gets painted when you call the Update method.
          /// @remarks For more information, see theWM_PAINTtopic.
          void Update() {

          }

          /// @brief Processes Windows messages.
          /// @param message The Windows Message to process.
          /// @remarks All messages are sent to the WndProc method after getting filtered through the PreProcessMessage method.
          /// @remarks The WndProc method corresponds exactly to the Windows WindowProc function. For more information about processing Windows messages, see the WindowProc function.
          /// @par Notes to Inheritors
          /// Inheriting controls should call the base class's WndProc method to process any messages that they do not handle.
          /// @par examples
          /// The following code example demonstrates overriding the WndProc method to handle operating system messages identified in the Message structure. TheWM_ACTIVATEAPPoperating system message is handled in this example to know when another application is becoming active. See the following topics to understand the available Message.Msg, Message.LParam, and Message.WParam values. Actual constant values can be found in the Windows.h header file.
          /// @include WndProc.cpp
          virtual void WndProc(Message& message);

          /// @brief Occurs when the value of the BackColor property changes.
          /// @remarks This event is raised if the BackColor property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par examples
          /// The following code example is an event handler that is executed when the Text property value changes. The Control class has several methods with the name pattern PropertyNameChanged that are raised when the corresponding PropertyName value changes (PropertyName represents the name of the corresponding property).<br><br>
          /// The following code example changes the ForeColor of a TextBox displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color::Red if the number is negative and to Color::Black if the number is positive. This example requires that you have a Formthat contains a TextBox.
          /// @code
          /// void currencyTextBox_TextChanged(const object& sender, const EventArgs& e) {
          ///   try {
          ///     // Convert the text to a Double and determine if it is a negative number.
          ///     if (Double::Parse(currencyTextBox::Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       currencyTextBox::ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       currencyTextBox::ForeColor = Color::Black;
          ///     }
          ///   } catch(...) {
          ///     // If there is an error, display the text using the system colors.
          ///     currencyTextBox::ForeColor = SystemColors::ControlText;
          ///   }
          /// }
          /// @endcode
          EventHandler BackColorChanged;

          /// @brief Occurs when the control is clicked.
          /// @remarks The Click event passes an EventArgs to its event handler, so it only indicates that a click has occurred. If you need more specific mouse information (button, number of clicks, wheel rotation, or location), use the MouseClick event. However, the MouseClick event will not be raised if the click is caused by action other than that of the mouse, such as pressing the ENTER key.
          /// @remarks A double-click is determined by the mouse settings of the user's operating System. The user can set the time between clicks of a mouse button that should be considered a double-click rather than two clicks. The Click event is raised every time a control is double-clicked. For example, if you have event handlers for the Click and DoubleClick events of a Form, the Click and DoubleClick events are raised when the form is double-clicked and both methods are called. If a control is double-clicked and that control does not support the DoubleClick event, the Click event might be raised twice.
          /// @remarks You must set the StandardClick value ofControlStyles to true for this event to be raised.
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Notes to Inheritors
          /// Inheriting from a standard Windows Forms control and changing the StandardClick or StandardDoubleClick values of ControlStyles to true can cause unexpected behavior or have no effect at all if the control does not support the Click or DoubleClick events.
          ///
          /// The following table lists Windows Forms controls and which event (Click or DoubleClick) is raised in response to the mouse action specified.
          /// | Control                                                                                                             | Left Mouse Click | Left Mouse Double Click | Right Mouse Click | Right Mouse Click  | Middle Mouse Click | Middle Mouse Double Click | XButton1 Mouse Click | XButton1 Mouse Double-Click | XButton2 Mouse Click | XButton2 Mouse Double-Click |
          /// |---------------------------------------------------------------------------------------------------------------------|------------------|-------------------------|-------------------|--------------------|--------------------|---------------------------|----------------------|-----------------------------|----------------------|-----------------------------|
          /// | MonthCalendar, DateTimePicker, HScrollBar, VScrollBar                                                               | none             | none                    | none              | none               | none               | none                      | none                 | none                        | none                 | none                        |
          /// | Button, CheckBox, RichTextBox, RadioButton                                                                          | Click            | Click, Click            | none              | none               | none               | none                      | none                 | none                        | none                 | none                        |
          /// | ListBox, CheckedListBox, ComboBox                                                                                   | Click            | Click, DoubleClick      | none              | none               | none               | none                      | none                 | none                        | none                 | none                        |
          /// | TextBox, DomainUpDown, NumericUpDown                                                                                | Click            | Click, DoubleClick      | none              | none               | none               | none                      | none                 | none                        | none                 | none                        |
          /// | * TreeView, * ListView                                                                                              | Click            | Click, DoubleClick      | Click             | Click, DoubleClick | none               | none                      | none                 | none                        | none                 | none                        |
          /// | ProgressBar, TrackBar                                                                                               | Click            | Click, Click            | Click             | Click, Click       | Click              | Click, Click              | Click                | Click, Click                | Click                | Click, Click                |
          /// | Form, DataGrid, Label, LinkLabel, Panel, GroupBox, PictureBox, Splitter, StatusBar, ToolBar, TabPage, ** TabControl | Click            | Click, DoubleClick      | Click             | Click, DoubleClick | Click              | Click, DoubleClick        | Click                | Click, DoubleClick          | Click                | Click, DoubleClick          |
          ///
          /// @* The mouse pointer must be over a child object (TreeNode or ListViewItem).
          ///
          /// ** The TabControl must have at least one TabPage in its TabPages collection.
          ///
          /// @par examples
          /// The following code example shows the Click event in an event handler.
          /// @code
          /// // This example uses the Parent property and the Find method of Control to set
          /// // properties on the parent control of a Button and its Form. The example assumes
          /// // that a Button control named button1 is located within a GroupBox control. The
          /// // example also assumes that the Click event of the Button control is connected to
          /// // the event handler method defined in the example.
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   // Get the control the Button control is located in. In this case a GroupBox.
          ///   ref<Control> control = button1.Parent;
          ///   // Set the text and backcolor of the parent control.
          ///   control().Text = "My Groupbox";
          ///   control().BackColor = Color::Blue;
          ///   // Get the form that the Button control is contained within.
          ///   ref<Form> myForm = button1.FindForm();
          ///   // Set the text and color of the form containing the Button.
          ///   myForm().Text = "The Form of My Control";
          ///   myForm().BackColor = Color::Red;
          /// }
          /// @endcode
          EventHandler Click;

          /// @brief Occurs when the value of the ClientSize property changes.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the ClientSizeChanged event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the ClientSizeChanged event.
          /// @code
          /// void Control1_ClientSizeChanged(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Control.ClientSizeChanged event.");
          /// }
          /// @endcode
          EventHandler ClientSizeChanged;

          /// @brief Occurs when the control is double-clicked.
          /// @remarks A double-click is determined by the mouse settings of the user's operating System. The user can set the time between clicks of a mouse button that should be considered a double-click rather than two clicks. The Click event is raised every time a control is double-clicked. For example, if you have event handlers for the Click and DoubleClick events of a Form, the Click and DoubleClick events are raised when the form is double-clicked and both methods are called. If a control is double-clicked and that control does not support the DoubleClick event, the Click event might be raised twice.
          /// @remarks You must set the StandardDoubleClick and StandardClick values of ControlStyles to true for this event to be raised. These values might already be set to true if you are inheriting from existing Windows Forms controls.
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Notes to Inheritors:
          /// Inheriting from a standard Windows Forms control and changing the StandardClick or StandardDoubleClick values of ControlStyles to true can cause unexpected behavior or have no effect at all if the control does not support the Click or DoubleClick events.
          ///
          /// The following table lists Windows Forms controls and which event (Click or DoubleClick) is raised in response to the mouse action specified.
          /// | Control                                                                                                             | Left Mouse Click | Left Mouse Double Click | Right Mouse Click | Right Mouse Click  | Middle Mouse Click | Middle Mouse Double Click | XButton1 Mouse Click | XButton1 Mouse Double-Click | XButton2 Mouse Click | XButton2 Mouse Double-Click |
          /// |---------------------------------------------------------------------------------------------------------------------|------------------|-------------------------|-------------------|--------------------|--------------------|---------------------------|----------------------|-----------------------------|----------------------|-----------------------------|
          /// | MonthCalendar, DateTimePicker, HScrollBar, VScrollBar                                                               | none             | none                    | none              | none               | none               | none                      | none                 | none                        | none                 | none                        |
          /// | Button, CheckBox, RichTextBox, RadioButton                                                                          | Click            | Click, Click            | none              | none               | none               | none                      | none                 | none                        | none                 | none                        |
          /// | ListBox, CheckedListBox, ComboBox                                                                                   | Click            | Click, DoubleClick      | none              | none               | none               | none                      | none                 | none                        | none                 | none                        |
          /// | TextBox, DomainUpDown, NumericUpDown                                                                                | Click            | Click, DoubleClick      | none              | none               | none               | none                      | none                 | none                        | none                 | none                        |
          /// | * TreeView, * ListView                                                                                              | Click            | Click, DoubleClick      | Click             | Click, DoubleClick | none               | none                      | none                 | none                        | none                 | none                        |
          /// | ProgressBar, TrackBar                                                                                               | Click            | Click, Click            | Click             | Click, Click       | Click              | Click, Click              | Click                | Click, Click                | Click                | Click, Click                |
          /// | Form, DataGrid, Label, LinkLabel, Panel, GroupBox, PictureBox, Splitter, StatusBar, ToolBar, TabPage, ** TabControl | Click            | Click, DoubleClick      | Click             | Click, DoubleClick | Click              | Click, DoubleClick        | Click                | Click, DoubleClick          | Click                | Click, DoubleClick          |
          ///
          /// @* The mouse pointer must be over a child object (TreeNode or ListViewItem).
          ///
          /// ** The TabControl must have at least one TabPage in its TabPages collection.
          ///
          /// @par examples
          /// The following code example uses the DoubleClick event of a ListBox to load text files listed in the ListBox into a TextBox control.
          /// @code
          /// // This example uses the DoubleClick event of a ListBox to load text files
          /// // listed in the ListBox into a TextBox control. This example
          /// // assumes that the ListBox, named listBox1, contains a list of valid file
          /// // names with path and that this event handler method
          /// // is connected to the DoublClick event of a ListBox control named listBox1.
          /// // This example requires code access permission to access files.
          /// void listBox1_DoubleClick(const object& sender, const System::EventArgs& e) {
          ///   // Get the name of the file to open from the ListBox.
          ///   String file = listBox1.SelectedItem().ToString();
          ///
          ///   try {
          ///     // Determine if the file exists before loading.
          ///     if (System::IO::File::Exists(file)) {
          ///       // Open the file and use a TextReader to read the contents into the TextBox.
          ///       System::IO::FileInfo myFile(listBox1.SelectedItem().ToString());
          ///       System::IO::TextReader myData = myFile.OpenText();;
          ///
          ///       textBox1.Text = myData.ReadToEnd();
          ///       myData.Close();
          ///     }
          ///   } catch(System::IO::FileNotFoundException) {
          ///   // Exception is thrown by the OpenText method of the FileInfo class.
          ///     MessageBox::Show("The file you specified does not exist.");
          ///   } catch(System::IO::IOException) {
          ///   // Exception is thrown by the ReadToEnd method of the TextReader class.
          ///     MessageBox::Show("There was a problem loading the file into the TextBox. Ensure that the file is a valid text file.");
          ///   }
          /// }
          /// @endcode
          EventHandler DoubleClick;

          /// @brief Occurs when the Enabled property value has changed.
          /// @remarks This event is raised if the Enabled property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example uses two RadioButton controls to demonstrate the EnabledChanged event. Clicking one button changes the value of the Enabled property of the other button to false and displays a MessageBox.
          /// @include EnableChangedEvent.cpp
          EventHandler EnabledChanged;

          /// @brief Occurs when the ForeColor property value changes.
          /// @remarks This event is raised if the ForeColor property is changed by either a programmatic modification or through interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example is an event handler that is executed when the Text property value changes. The Control class has several methods with the name pattern PropertyNameChanged that are raised when the corresponding PropertyName value changes (PropertyName represents the name of the corresponding property).<br><br>
          /// The following code example changes the ForeColor of a TextBox displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color::Red if the number is negative and to Color::Black if the number is positive. This example requires that you have a Form that contains a TextBox.
          /// @code
          /// void currencyTextBox_TextChanged(const object& sender, const EventArgs& e) {
          ///   try {
          ///     // Convert the text to a Double and determine if it is a negative number.
          ///     if (Double::Parse(currencyTextBox.Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       currencyTextBox.ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       currencyTextBox.ForeColor = Color::Black;
          ///     }
          ///   } catch {
          ///     // If there is an error, display the text using the system colors.
          ///     currencyTextBox::ForeColor = SystemColors::ControlText;
          ///   }
          /// }
          /// @endcode
          EventHandler ForeColorChanged;

          /// @brief Occurs when a handle is created for the control.
          /// @remarks A handle is created when the Control is displayed for the first time. For example, if a Control is created that has Visible set to false, the HandleCreated event will not be raised until Visible is set to true.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the HandleCreated event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Buttonor ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the HandleCreated event.
          /// @code
          /// void Control1_HandleCreated(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Control.HandleCreated event.");
          /// }
          /// @endcode
          EventHandler HandleCreated;

          /// @brief Occurs when the control's handle is in the process of being destroyed.
          /// @remarks During the HandleDestroyed event, the control is still a valid Windows control and the Handle can be recreated by calling the RecreateHandle method.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the HandleDestroyed event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the HandleDestroyed event.
          /// @code
          /// void Control1_HandleDestroyeded(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Control.HandleDestroyed event.");
          /// }
          /// @endcode
          EventHandler HandleDestroyed;

          /// @brief  Occurs when a control's display requires redrawing.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the Invalidated event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the Invalidated event.
          /// @code
          /// void Control1_Invalidated(const Object& sender, const InvalidateEventArgs& e) {
          ///   System::Text::StringBuilder messageBox;
          ///   messageBox.AppendFormat("{0} = {1}", "InvalidRect", e.InvalidRect);
          ///   messageBox.AppendLine();
          ///   MessageBox::Show(messageBox.ToString(), "Invalidated Event");
          /// }
          /// @endcode
          InvalidateEventHandler Invalidated;

          /// @brief Occurs when a key is pressed while the control has focus.
          /// @remarks Key events occur in the following order:
          /// * KeyDown
          /// * KeyPress
          /// * KeyUp
          /// @remarks To handle keyboard events only at the form level and not enable other controls to receive keyboard events, set the KeyPressEventArgs.Handled property in your form's KeyPress event-handling method to true. Certain keys, such as the TAB, RETURN, ESC, and arrow keys are handled by controls automatically. To have these keys raise the KeyDown event, you must override the IsInputKey method in each control on your form. The code for the override of the IsInputKey would need to determine if one of the special keys is pressed and return a value of true. Instead of overriding the IsInputKey method, you can handle the PreviewKeyDown event and set the IsInputKeyproperty to true. For a code example, see the PreviewKeyDown event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example uses the KeyDown event to determine the type of character entered into the control.
          /// @code
          /// // Boolean flag used to determine when a character other than a number is entered.
          /// bool nonNumberEntered = false;
          ///
          /// // Handle the KeyDown event to determine the type of character entered into the control.
          /// void textBox1_KeyDown(const object& sender, System::Windows::Forms::KeyEventArgs& e) {
          ///   // Initialize the flag to false.
          ///   nonNumberEntered = false;
          ///
          ///   // Determine whether the keystroke is a number from the top of the keyboard.
          ///   if (e.KeyCode < Keys::D0 || e.KeyCode > Keys::D9) {
          ///     // Determine whether the keystroke is a number from the keypad.
          ///     if (e.KeyCode < Keys::NumPad0 || e.KeyCode > Keys::NumPad9) {
          ///       // Determine whether the keystroke is a backspace.
          ///       if (e.KeyCode != Keys::Back) {
          ///         // A non-numerical keystroke was pressed.
          ///         // Set the flag to true and evaluate in KeyPress event.
          ///         nonNumberEntered = true;
          ///       }
          ///     }
          ///   }
          ///   //If shift key was pressed, it's not a number.
          ///   if (Control::ModifierKeys == Keys::Shift) {
          ///     nonNumberEntered = true;
          ///   }
          /// }
          ///
          /// // This event occurs after the KeyDown event and can be used to prevent
          /// // characters from entering the control.
          /// private void textBox1_KeyPress(const object& sender, System::Windows::Forms::KeyPressEventArgs& e) {
          ///   // Check for the flag being set in the KeyDown event.
          ///   if (nonNumberEntered == true) {
          ///     // Stop the character from being entered into the control since it is non-numerical.
          ///     e.Handled = true;
          ///   }
          /// }
          /// @endcode
          KeyEventHandler KeyDown;

          /// @brief Occurs when a character. space or backspace key is pressed while the control has focus.
          /// @remarks Key events occur in the following order:
          /// * KeyDown
          /// * KeyPress
          /// * KeyUp
          /// @remarks The KeyPress event is not raised by non-character keys other than space and backspace; however, the non-character keys do raise the KeyDown and KeyUp events.
          /// @remarks Use the KeyChar property to sample keystrokes at run time and to consume or modify a subset of common keystrokes.
          /// @remarks To handle keyboard events only at the form level and not enable other controls to receive keyboard events, set the KeyPressEventArgs.Handled property in your form's KeyPress event-handling method to true.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example uses the KeyDown event to determine the type of character entered into the control.
          /// @code
          /// // Boolean flag used to determine when a character other than a number is entered.
          /// bool nonNumberEntered = false;
          ///
          /// // Handle the KeyDown event to determine the type of character entered into the control.
          /// void textBox1_KeyDown(const object& sender, System::Windows::Forms::KeyEventArgs& e) {
          ///   // Initialize the flag to false.
          ///   nonNumberEntered = false;
          ///
          ///   // Determine whether the keystroke is a number from the top of the keyboard.
          ///   if (e.KeyCode < Keys::D0 || e.KeyCode > Keys::D9) {
          ///     // Determine whether the keystroke is a number from the keypad.
          ///     if (e.KeyCode < Keys::NumPad0 || e.KeyCode > Keys::NumPad9) {
          ///       // Determine whether the keystroke is a backspace.
          ///       if (e.KeyCode != Keys::Back) {
          ///         // A non-numerical keystroke was pressed.
          ///         // Set the flag to true and evaluate in KeyPress event.
          ///         nonNumberEntered = true;
          ///       }
          ///     }
          ///   }
          ///   //If shift key was pressed, it's not a number.
          ///   if (Control::ModifierKeys == Keys::Shift) {
          ///     nonNumberEntered = true;
          ///   }
          /// }
          ///
          /// // This event occurs after the KeyDown event and can be used to prevent
          /// // characters from entering the control.
          /// private void textBox1_KeyPress(const object& sender, System::Windows::Forms::KeyPressEventArgs& e) {
          ///   // Check for the flag being set in the KeyDown event.
          ///   if (nonNumberEntered == true) {
          ///     // Stop the character from being entered into the control since it is non-numerical.
          ///     e.Handled = true;
          ///   }
          /// }
          /// @endcode
          KeyPressEventHandler KeyPress;

          /// @brief Occurs when a key is released while the control has focus.
          /// @remarks Key events occur in the following order:
          /// * KeyDown
          /// * KeyPress
          /// * KeyUp
          /// @remarks To handle keyboard events only at the form level and not enable other controls to receive keyboard events, set the KeyPressEventArgs.Handled property in your form's KeyPress event-handling method to true. Certain keys, such as the TAB, RETURN, ESC, and arrow keys are handled by controls automatically. To have these keys raise the KeyUp event, you must override the IsInputKey method in each control on your form. The code for the override of IsInputKey would need to determine if one of the special keys is pressed and return a value of true.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example uses the KeyUp event with the Help class to display pop-up style help to the user.
          /// @code
          /// // This example demonstrates how to use the KeyUp event with the Help class to display
          /// // pop-up style help to the user of the application. When the user presses F1, the Help
          /// // class displays a pop-up window, similar to a ToolTip, near the control. This example assumes
          /// // that a TextBox control, named textBox1, has been added to the form and its KeyUp
          /// // event has been contected to this event handler method.
          /// void textBox1_KeyUp(const object& sender, System::Windows::Forms::KeyEventArgs& e) {
          ///   // Determine whether the key entered is the F1 key. Display help if it is.
          ///   if (e.KeyCode == Keys::F1) {
          ///     // Display a pop-up help topic to assist the user.
          ///     Help::ShowPopup(textBox1, "Enter your first name", Point(textBox1.Right, this.textBox1.Bottom));
          ///   }
          /// }
          /// @endcode
          KeyEventHandler KeyUp;

          /// @brief Occurs when the Location property value has changed.
          /// @remarks This event is raised if the Location property is changed by either a programmatic modification or through interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example raises the LocationChanged event on a StatusStrip when the form is resized.
          /// @include LocationChangedEvent.cpp
          EventHandler LocationChanged;

          /// @brief Occurs when the control loses focus.
          /// @remarks When you change the focus by using the keyboard (TAB, SHIFT+TAB, and so on), by calling the Select or SelectNextControl methods, or by setting the ContainerControl.ActiveControl property to the current form, focus events occur in the following order
          /// -# Enter
          /// -# GotFocus
          /// -# Leave
          /// -# Validating
          /// -# Validated
          /// -# LostFocus
          /// @remarks When you change the focus by using the mouse or by calling the Focus method, focus events occur in the following order:
          /// -# Enter
          /// -# GotFocus
          /// -# LostFocus
          /// -# Leave
          /// -# Validating
          /// -# Validated
          /// @remarks If the CausesValidation property is set to false, the Validating and Validated events are suppressed.
          /// @remarks If the Cancel property of the CancelEventArgs is set to true in the Validating event delegate, all events that would usually occur after the Validating event are suppressed.
          /// @note The GotFocus and LostFocus events are low-level focus events that are tied to the WM_KILLFOCUS and WM_SETFOCUS Windows messages. Typically, the GotFocus and LostFocus events are only used when updating UICues or when writing custom controls. Instead the Enter and Leave events should be used for all controls except the Form class, which uses the Activated and Deactivate events. For more information about the GotFocus and LostFocus events, see the WM_KILLFOCUS and WM_KILLFOCUS topics.
          /// @warning Do not attempt to set focus from within the Enter, GotFocus, Leave, LostFocus, Validating, or Validated event handlers. Doing so can cause your application or the operating system to stop responding. For more information, see the WM_KILLFOCUS topic.
          /// @remarks
          /// For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates validating the text for TextBox1. It also demonstrates handling the LostFocus event by setting the FileDialog.InitialDirectory property to the text in TextBox1. The code example used the ErrorProvider.GetError method to check for an error before opening the file dialog box. To run this example, paste the following code into a form containing a TextBox named TextBox1, an OpenFileDialog named OpenFileDialog1, a Button named Button1, and an ErrorProvider named ErrorProvider1. Ensure all events are associated with their event handlers.
          /// @code
          /// void textBox1_Validating(const object& sender, System::ComponentModel::CancelEventArgs& e) {
          ///   // If nothing is entered, an ArgumentException is caught; if an invalid directory is entered,
          ///   // a DirectoryNotFoundException is caught. An appropriate error message is displayed in either case.
          ///   try {
          ///     System::IO::DirectoryInfo directory(textBox1.Text);
          ///     directory.GetFiles();
          ///     errorProvider1.SetError(textBox1, "");
          ///   } catch(const System::ArgumentException& ex1) {
          ///     errorProvider1.SetError(textBox1, "Please enter a directory");
          ///   } catch(const System::IO::DirectoryNotFoundException& ex2) {
          ///     errorProvider1.SetError(textBox1, "The directory does not exist. Try again with a different directory.");
          ///   }
          /// }
          ///
          /// // This method handles the LostFocus event for textBox1 by setting the
          /// // dialog's InitialDirectory property to the text in textBox1.
          /// void textBox1_LostFocus(const object& sender, const System::EventArgs& e) {
          ///   openFileDialog1.InitialDirectory = textBox1.Text;
          /// }
          ///
          /// // This method demonstrates using the ErrorProvider.GetError method
          /// // to check for an error before opening the dialog box.
          /// void button1_Click(const System::Object& sender, const System::EventArgs& e) {
          ///   //If there is no error, then open the dialog box.
          ///   if (errorProvider1.GetError(textBox1) == "") {
          ///     DialogResult dialogResult = openFileDialog1::ShowDialog();
          ///   }
          /// }
          /// @endcode
          EventHandler LostFocus;

          /// @brief Occurs when the control loses mouse capture.
          /// @remarks In rare scenarios, you might need to detect unexpected input. For example, consider the following scenarios.
          /// * During a mouse operation, the user opens the Start menu by pressing the Windows key or CTRL+ESC.
          /// * During a mouse operation, the user switches to another program by pressing ALT+TAB.
          /// * During a mouse operation, another program displays a window or a message box that takes focus away from the current application.
          /// @remarks Mouse operations can include clicking and holding the mouse on a form or a control, or performing a mouse drag operation. If you have to detect when a form or a control loses mouse capture for these and related unexpected scenarios, you can use the MouseCaptureChanged event.
          /// @par Examples
          /// The following code example demonstrates the MouseCaptureChanged event for a Button control.
          /// @code
          /// void button1_MouseDown(const object& sender, const MouseEventArgs& e) {
          ///   System::Diagnostics::Debug::WriteLine("button1_MouseDown");
          /// }
          ///
          /// void button1_MouseUp(const object& sender, const MouseEventArgs& e) {
          ///   System::Diagnostics::Debug::WriteLine("button1_MouseUp");
          /// }
          ///
          /// void button1_MouseCaptureChanged(const object& sender, const EventArgs& e) {
          ///   System::Diagnostics::Debug::WriteLine("button1_MouseCaptureChanged");
          /// }
          /// @endcode
          /// To test this example, run it in the debugger by pressing F5. Open the Output window in Visual Studio so that you can see when events are raised. Click the Button and notice the following output.
          /// @code
          /// button1_MouseDown
          /// button1_MouseUp
          /// button1_MouseCaptureChanged
          /// @endcode
          /// Now, click and hold the left mouse button on the Button control. While still clicking the mouse, press ALT+TAB to switch to another program. Notice that the MouseCaptureChanged event is raised enabling you to potentially handle this scenario. Depending on your actions, the MouseUp event might not be raised. You can also try this test with the Windows key or CTRL+ESC.
          /// @code
          /// button1_MouseDown
          /// button1_MouseCaptureChanged
          /// @endcode
          EventHandler MouseCaptureChanged;

          /// @brief Occurs when the control is clicked by the mouse.
          /// @remarks Depressing a mouse button when the cursor is over a control typically raises the following series of events from the control:
          /// * MouseDown event.
          /// * Click event.
          /// * MouseClick event.
          /// * MouseUp event.
          /// @remarks For this to occur, the various events cannot be disabled in the control's class.
          /// @remarks Two single clicks that occur close enough in time, as determined by the mouse settings of the user's operating system, will generate a MouseDoubleClick event instead of the second MouseClick event.
          /// @par Important
          /// Click events are logically higher-level events of a control. They are often raised by other actions, such as pressing the ENTER key when the control has focus.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the MouseClick event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the MouseClick event.
          /// @code
          /// void Control1_MouseClick(const Object& sender, const MouseEventArgs& e) {
          ///   System::Text::StringBuilder messageBox;
          ///   messageBox.AppendFormat("{0} = {1}", "Button", e.Button);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "Clicks", e.Clicks);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "X", e.X);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "Y", e.Y);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "Delta", e.Delta);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "Location", e.Location);
          ///   messageBox.AppendLine();
          ///   MessageBox::Show(messageBox.ToString(), "MouseClick Event");
          /// }
          /// @endcode
          MouseEventHandler MouseClick;

          /// @brief Occurs when the control is double clicked by the mouse.
          /// @remarks The MouseDoubleClick event occurs when the user depresses a mouse button twice in quick succession when the cursor is over the control. The time interval that separates two single clicks from a double-click is determined by the mouse settings of the user's operating System::
          /// @remarks The following series of events is raised by the control when such a user action takes place:
          /// -# MouseDown event.
          /// -# Click event.
          /// -# MouseClick event.
          /// -# MouseUp event.
          /// -# MouseDown event.
          /// -# DoubleClick event.
          /// -# MouseDoubleClick event.
          /// -# MouseUp event.
          /// @remarks For this to occur, the various events cannot be disabled in the control's class.
          /// @par Important
          /// DoubleClick events are logically higher-level events of a control. They may be raised by other user actions, such as shortcut key combinations.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the MouseDoubleClick event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the MouseDoubleClick event.
          /// @code
          /// void Control1_MouseDoubleClick(const Object& sender, const MouseEventArgs& e) {
          ///   System::Text::StringBuilder messageBox;
          ///   messageBox.AppendFormat("{0} = {1}", "Button", e.Button);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "Clicks", e.Clicks);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "X", e.X);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "Y", e.Y);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "Delta", e.Delta);
          ///   messageBox.AppendLine();
          ///   messageBox.AppendFormat("{0} = {1}", "Location", e.Location);
          ///   messageBox.AppendLine();
          ///   MessageBox::Show(messageBox.ToString(), "MouseDoubleClick Event");
          /// }
          /// @endcode
          MouseEventHandler MouseDoubleClick;

          /// @brief Occurs when the mouse pointer is over the control and a mouse button is pressed.
          /// @remarks Mouse events occur in the following order:
          /// -# MouseEnter
          /// -# MouseMove
          /// -# MouseHover / MouseDown / MouseWheel
          /// -# MouseUp
          /// -# MouseLeave
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates using different mouse events to draw the path of the mouse on a Panel. A line segment is added to the GraphicsPath for each MouseMove and MouseDown events that occur. To update the graphics, the Invalidate method is called for the Panel on each MouseDown and MouseUp event. In addition, the graphic path is scrolled up or down when the MouseWheel event occurs. Additional mouse events, like MouseHover, are identified on screen as well. Also displayed on the screen is additional information about the mouse from the SystemInformation class.
          /// @include MouseEvent.cpp
          MouseEventHandler MouseDown;

          /// @brief Occurs when the mouse pointer enters the control.
          /// @remarks Mouse events occur in the following order:
          /// -# MouseEnter
          /// -# MouseMove
          /// -# MouseHover / MouseDown / MouseWheel
          /// -# MouseUp
          /// -# MouseLeave
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates using different mouse events to draw the path of the mouse on a Panel. A line segment is added to the GraphicsPath for each MouseMove and MouseDown events that occur. To update the graphics, the Invalidate method is called for the Panel on each MouseDown and MouseUp event. In addition, the graphic path is scrolled up or down when the MouseWheel event occurs. Additional mouse events, like MouseHover, are identified on screen as well. Also displayed on the screen is additional information about the mouse from the SystemInformation class.
          /// @include MouseEvent.cpp
          EventHandler MouseEnter;

          /// @brief Occurs when the mouse pointer rests on the control.
          /// @remarks Mouse events occur in the following order:
          /// -# MouseEnter
          /// -# MouseMove
          /// -# MouseHover / MouseDown / MouseWheel
          /// -# MouseUp
          /// -# MouseLeave
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates using different mouse events to draw the path of the mouse on a Panel. A line segment is added to the GraphicsPath for each MouseMove and MouseDown events that occur. To update the graphics, the Invalidate method is called for the Panel on each MouseDown and MouseUp event. In addition, the graphic path is scrolled up or down when the MouseWheel event occurs. Additional mouse events, like MouseHover, are identified on screen as well. Also displayed on the screen is additional information about the mouse from the SystemInformation class.
          /// @include MouseEvent.cpp
          EventHandler MouseHover;

          /// @brief Occurs when the mouse pointer leaves the control.
          /// @remarks Mouse events occur in the following order:
          /// -# MouseEnter
          /// -# MouseMove
          /// -# MouseHover / MouseDown / MouseWheel
          /// -# MouseUp
          /// -# MouseLeave
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates using different mouse events to draw the path of the mouse on a Panel. A line segment is added to the GraphicsPath for each MouseMove and MouseDown events that occur. To update the graphics, the Invalidate method is called for the Panel on each MouseDown and MouseUp event. In addition, the graphic path is scrolled up or down when the MouseWheel event occurs. Additional mouse events, like MouseHover, are identified on screen as well. Also displayed on the screen is additional information about the mouse from the SystemInformation class.
          /// @include MouseEvent.cpp
          EventHandler MouseLeave;

          /// @brief Occurs when the mouse pointer is moved over the control.
          /// @remarks Mouse events occur in the following order:
          /// -# MouseEnter
          /// -# MouseMove
          /// -# MouseHover / MouseDown / MouseWheel
          /// -# MouseUp
          /// -# MouseLeave
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates using different mouse events to draw the path of the mouse on a Panel. A line segment is added to the GraphicsPath for each MouseMove and MouseDown events that occur. To update the graphics, the Invalidate method is called for the Panel on each MouseDown and MouseUp event. In addition, the graphic path is scrolled up or down when the MouseWheel event occurs. Additional mouse events, like MouseHover, are identified on screen as well. Also displayed on the screen is additional information about the mouse from the SystemInformation class.
          /// @include MouseEvent.cpp
          MouseEventHandler MouseMove;

          /// @brief Occurs when the mouse pointer is over the control and a mouse button is released.
          /// @remarks Mouse events occur in the following order:
          /// -# MouseEnter
          /// -# MouseMove
          /// -# MouseHover / MouseDown / MouseWheel
          /// -# MouseUp
          /// -# MouseLeave
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates using different mouse events to draw the path of the mouse on a Panel. A line segment is added to the GraphicsPath for each MouseMove and MouseDown events that occur. To update the graphics, the Invalidate method is called for the Panel on each MouseDown and MouseUp event. In addition, the graphic path is scrolled up or down when the MouseWheel event occurs. Additional mouse events, like MouseHover, are identified on screen as well. Also displayed on the screen is additional information about the mouse from the SystemInformation class.
          /// @include MouseEvent.cpp
          MouseEventHandler MouseUp;

          /// @brief Occurs when the mouse wheel moves while the control has focus.
          /// @remarks Mouse events occur in the following order:
          /// -# MouseEnter
          /// -# MouseMove
          /// -# MouseHover / MouseDown / MouseWheel
          /// -# MouseUp
          /// -# MouseLeave
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates using different mouse events to draw the path of the mouse on a Panel. A line segment is added to the GraphicsPath for each MouseMove and MouseDown events that occur. To update the graphics, the Invalidate method is called for the Panel on each MouseDown and MouseUp event. In addition, the graphic path is scrolled up or down when the MouseWheel event occurs. Additional mouse events, like MouseHover, are identified on screen as well. Also displayed on the screen is additional information about the mouse from the SystemInformation class.
          /// @include MouseEvent.cpp
          MouseEventHandler MouseWheel;

          /// @brief Occurs when the control is redrawn.
          /// @remarks The Paint event is raised when the control is redrawn. It passes an instance of PaintEventArgs to the method(s) that handles the Paint event.
          /// @remarks When creating a new custom control or an inherited control with a different visual appearance, you must provide code to render the control by overriding the OnPaint method. For more information, see Overriding the OnPaint Method and Custom Control Painting and Rendering.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example creates a PictureBox control on the form and uses the Paint event to draw to it.
          /// @code
          /// // This example creates a PictureBox control on the form and draws to it.
          /// // This example assumes that the Form_Load event handler method is
          /// // connected to the Load event of the form.
          ///
          /// PictureBox pictureBox1;
          /// void Form1_Load(const object& sender, const System::EventArgs& e) {
          ///   // Dock the PictureBox to the form and set its background to white.
          ///   pictureBox1.Dock = DockStyle::Fill;
          ///   pictureBox1.BackColor = Color::White;
          ///   // Connect the Paint event of the PictureBox to the event handler method.
          ///   pictureBox1.Paint += System::Windows::Forms::PaintEventHandler(*this &Form1::pictureBox1_Paint);
          ///
          ///   // Add the PictureBox control to the Form.
          ///   this.Controls().Add(pictureBox1);
          /// }::
          ///
          /// void pictureBox1_Paint(const object& sender, System::Windows::Forms::PaintEventArgs& e) {
          ///   // Create a local version of the graphics object for the PictureBox.
          ///   Graphics g = e.Graphics;
          ///
          ///   // Draw a string on the PictureBox.
          ///   g.DrawString("This is a diagonal line drawn on the control", Font("Arial",10), System::Drawing::Brushes::Blue, System::Drawing::Point(30,30));
          ///   // Draw a line in the PictureBox.
          ///   g.DrawLine(System::Drawing::Pens::Red, pictureBox1.Left, pictureBox1.Top, pictureBox1.Right, pictureBox1.Bottom);
          /// }
          /// @endcode
          PaintEventHandler Paint;

          /// @brief Occurs when the Parent property value changes.
          /// @remarks This event is raised if the Parent property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          EventHandler ParentChanged;

          /// @brief Occurs when the Size property value changes.
          /// @remarks It is preferable to use the Layout event to handle custom layouts. The Layout event is raised in response to Resize events, but also in other conditions when layout might need to be applied.
          /// @remarks This event is raised if the Size property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates the SizeChanged event. An instance of a Button control has been provided that can be scaled both horizontally and vertically. A NumericUpDown instance provides the horizontal and vertical scale value. The Button instance named <b>OK</b> is used to set the scale values for the Button control instance. Whenever the size of the control changes, the event handler associated with the SizeChanged event of the control is called. This event handler displays a message box indicating that the size of the control has changed.
          /// @code
          /// void RegisterEventHandler() {
          ///   myButton1.SizeChanged += EventHandler(*this, &Form1::MyButton1_SizeChanged);
          /// }
          ///
          /// void MyButton2_Click(const object& sender, const System::EventArgs& e) {
          ///   // Set the scale for the control to the value provided.
          ///   float scale = (float)myNumericUpDown1.Value;
          ///   myButton1.Scale(scale);
          /// }
          ///
          /// void MyButton1_SizeChanged(const object& sender, const System::EventArgs& e) {
          ///   MessageBox::Show("The size of the 'Button' control has changed");
          /// }
          /// @endcode
          EventHandler SizeChanged;

          /// @brief Occurs when the TabStop property value changes.
          /// @remarks This event is raised if the TabStop property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the TabStopChanged event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the TabStopChanged event.
          /// @code
          /// void Control1_TabStopChanged(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Control.TabStopChanged event.");
          /// }
          /// @endcode
          EventHandler TabStopChanged;

          /// @brief Occurs when the Text property value changes.
          /// @remarks This event is raised if the Text property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example changes the ForeColor of a TextBox displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive.<br>
          /// This example requires that you have a Form that contains a TextBox.
          /// @code
          /// void currencyTextBox_TextChanged(const object& sender, const EventArgs& e) {
          ///   try {
          ///     // Convert the text to a Double and determine if it is a negative number.
          ///     if (Double::Parse(currencyTextBox.Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       currencyTextBox.ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       currencyTextBox.ForeColor = Color::Black;
          ///     }
          ///   } catch {
          ///     // If there is an error, display the text using the system colors.
          ///     currencyTextBox::ForeColor = SystemColors::ControlText;
          ///   }
          /// }
          /// @endcode
          EventHandler TextChanged;

          /// @brief Occurs when the Visible property value changes.
          /// @remarks This event is raised if the Visible property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example raises the VisibleChanged event when the Visible property value of the Label control has changed.
          /// @code
          /// void Button_HideLabel(const object& sender, const EventArgs& e) {
          ///   myLabel.Visible = false;
          /// }
          ///
          /// void AddVisibleChangedEventHandler() {
          ///   myLabel.VisibleChanged += EventHandler(*this, &Form1::Label_VisibleChanged);
          /// }
          ///
          /// void Label_VisibleChanged(const object& sender, const EventArgs& e) {
          ///   MessageBox::Show("Visible change event raised!!!");
          /// }
          /// @endcode
          EventHandler VisibleChanged;

        protected:
          /// @brief Gets the default size of the control.
          /// @return System::Drawing::Size The default Size of the control.
          /// @remarks The DefaultSize property represents the Size of the control when it is initially created. You can adjust the size of the control by setting its Size property value.
          /// @note To maintain better performance, do not set the Size of a control in its constructor. The preferred method is to override the DefaultSize property.
          /// @par Notes to Inheritors
          /// Override GetDefaultsize() method used by DefaultSize property.
          property_<System::Drawing::Size, readonly_> DefaultSize {
            get_ { return this->GetDefaultSize(); }
          };

          /// @brief Creates a handle for the control
          /// @remarks You typically should not call the CreateHandle method directly. The preferred method is to call the CreateControl method, which forces a handle to be created for the control and its child controls when the control is created.
          /// @par Notes to Inheritors
          /// When overriding CreateHandle in a derived class, be sure to call the base class's CreateHandle method to ensure that the handle is created.
          virtual void CreateHandle();

          /// @brief Sends the specified message to the default window procedure.
          /// @param message The Windows Message to process.
          /// @remarks For more information about processing Windows messages, see the WindowProc function.
          virtual void DefWndProc(Message& message);

          /// @brief Destroys the handle associated with the control.
          /// @par Notes to Inheritors
          /// When overriding DestroyHandle in a derived class, be sure to call the base class's DestroyHandle method to ensure that the handle is destroyed.
          virtual void DestroyHandle();

          /// @brief Gets the default size of the control.
          /// @return Switch::System::Drawing::Size The default Size of the control.
          /// @remarks The DefaultSize property represents the Size of the control when it is initially created. You can adjust the size of the control by setting its Size property value.
          /// @note To maintain better performance, do not set the Size of a control in its constructor. The preferred method is to override the DefaultSize property.
          /// @par Notes to Inheritors
          /// Override GetDefaultsize() method used by DefaultSize property.
          virtual System::Drawing::Size GetDefaultSize() const { return System::Drawing::Size(0, 0); }

          /// @brief Sets the parent container of the control.
          /// @return Control A Control that represents the parent or container control of the control.
          /// @remarks Setting the Parent property value to null removes the control from the Control.ControlCollection of its current parent control.
          /// @par Notes to Inheritors
          /// Overide SetParent() method used by Parent property.
          virtual void SetParent(ref<Control> parent) {
            if (this->parent != parent) {
              if (parent == null && this->parent != null)
                this->parent().controls.Remove(*this);
              else
                const_cast<Control&>(parent()).controls.Add(*this);
            }
          }

          /// @brief Gets the window handle that the control is bound to.
          /// @return intptr An IntPtr that contains the window handle (HWND) of the control.
          /// @remarks The value of the Handle property is a Windows HWND. If the handle has not yet been created, referencing this property will force the handle to be created.
          intptr GetHandle() override {
            if (!this->IsHandleCreated)
              CreateHandle();
            return this->handle;
          }

          /// @brief Retrieves the value of the specified control style bit for the control.
          /// @param falg The ControlStyles bit to return the value from.
          /// @return bool true if the specified control style bit is set to true; otherwise, false.
          /// @remarks Control style bit flags are used to categorize supported behavior. A control can enable a style by calling the SetStyle method and passing in the appropriate ControlStyles bit and the Boolean value to set the bit to. To determine the value assigned to a specified ControlStyles bit, use the GetStyle method and pass in the ControlStyles member to evaluate.
          /// @par Examples
          /// The following code example returns the value of the double-buffering related style bits for a Form. This example returns true only if all the style bits are set to true.
          /// @code
          /// bool DoubleBufferingEnabled() {
          ///   // Get the value of the double-buffering style bits.
          ///   return this->GetStyle(ControlStyles::DoubleBuffer |
          ///                         ControlStyles::UserPaint |
          ///                         ControlStyles::AllPaintingInWmPaint);
          /// }
          /// @endcode
          virtual bool GetStyle(ControlStyles flag) { return ((int32)this->style & (int32)flag) == (int32)flag; }

          /// @brief Sets a specified ControlStyles flag to either true or false.
          /// @param flag The ControlStyles bit to set.
          /// @param value rue to apply the specified style to the control; otherwise, false.
          /// @remarks Control style bit flags are used to categorize supported behavior. A control can enable a style by calling the SetStyle method and passing in the appropriate ControlStyles bit (or bits) and the Boolean value to set the bit(s) to. To determine the value assigned to a specified ControlStyles bit, use the GetStyle method and pass in the ControlStyles member to evaluate.
          /// @warning Setting the control style bits can substantially change the behavior of the control. Review the ControlStyles enumeration documentation to understand the effects of changing the control style bits before calling the SetStyle method.
          /// @par Examples
          /// The following code example enables double-buffering on a Form and updates the styles to reflect the changes.
          /// @code
          /// public void EnableDoubleBuffering() {
          ///   // Set the value of the double-buffering style bits to true.
          ///   this->SetStyle(ControlStyles::DoubleBuffer |
          ///                  ControlStyles::UserPaint |
          ///                  ControlStyles::AllPaintingInWmPaint,
          ///                  true);
          ///   this->UpdateStyles();
          /// }
          /// @endcode
          virtual void SetStyle(ControlStyles flag, bool value) { this->style = value ? (ControlStyles)((int32)this->state | (int32)flag) : (ControlStyles)((int32)this->style & ~(int32)flag); }

          /// @brief Raises the BackColorChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnBackColorChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to inheritors
          /// When overriding OnBackColorChanged in a derived class, be sure to call the base class's OnBackColorChanged method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example is an event-raising method that is executed when the Text property value changes. The Control class has several methods with the name pattern OnPropertyNameChanged that raise the corresponding PropertyNameChanged event when the PropertyName value changes (PropertyName represents the name of the corresponding property).<br><br>
          /// The following code example changes the ForeColor of a TextBox derived class displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive. This example requires that you have a class that derives from the TextBox class.
          /// @code
          /// void OnTextChanged(const System::EventArgs& e) override {
          ///   try {
          ///     // Convert the text to a Double and determine
          ///     // if it is a negative number.
          ///     if (Double::Parse(this->Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       this->ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       this->ForeColor = Color::Black;
          ///     }
          ///   } catch(...) {
          ///     // If there is an error, display the
          ///     // text using the system colors.
          ///     this->ForeColor = SystemColors::ControlText;
          ///   }
          ///
          ///   this->TextBox::OnTextChanged(e);
          /// }
          /// @endcode
          virtual void OnBackColorChanged(const EventArgs& e);

          /// @brief Raises the Click event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnClick method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to inheritors
          /// When overriding OnClick in a derived class, be sure to call the base class's OnClick method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example demonstrates overriding the OnClick method in a derived class. To run the example, paste the following code after a form class, in the same file. Add a textbox of type SingleClickTextBox to the form.
          /// @code
          /// // This is a custom TextBox control that overrides the OnClick method
          /// // to allow one-click selection of the text in the text box.
          ///
          /// class SingleClickTextBox : public TextBox {
          ///   protected:
          ///     void OnClick(const EventArgs& e) override {
          ///       this->SelectAll();
          ///       this->TextBox::OnClick(e);
          ///     }
          /// };
          /// @endcode
          /// The following code example shows one of the many uses of the Click event and event han
          /// @code
          /// // This example uses the Parent property and the Find method of Control to set
          /// // properties on the parent control of a Button and its Form. The example assumes
          /// // that a Button control named button1 is located within a GroupBox control. The
          /// // example also assumes that the Click event of the Button control is connected to
          /// // the event handler method defined in the example.
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   // Get the control the Button control is located in. In this case a GroupBox.
          ///   ref<Control> control = button1.Parent;
          ///   // Set the text and backcolor of the parent control.
          ///   control.Text = "My Groupbox";
          ///   control.BackColor = Color::Blue;
          ///   // Get the form that the Button control is contained within.
          ///   ref<Form> myForm = button1.FindForm();
          ///   // Set the text and color of the form containing the Button.
          ///   myForm.Text = "The Form of My Control";
          ///   myForm.BackColor = Color::Red;
          /// }
          /// @endcode
          virtual void OnClick(const EventArgs& e) { this->Click(*this, e); }

          /// @brief Raises the ClientSizeChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnClientSizeChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to inheritors
          /// When overriding OnClientSizeChanged in a derived class, be sure to call the base class's OnClientSizeChanged method so that registered delegates receive the event.
          virtual void OnClientSizeChanged(const EventArgs& e);

          /// @brief Raises the CreateControl method.
          /// @remarks The OnCreateControl method is called when the control is first created.
          /// @remarks The OnCreateControl method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnCreateControl in a derived class, be sure to call the base class's OnCreateControl method so that registered delegates receive the event.
          virtual void OnCreateControl() {}

          /// @brief Raises the DoubleClick event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnDoubleClick method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnDoubleClick in a derived class, be sure to call the base class's OnDoubleClick method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example uses the DoubleClick event of a ListBox to load text files listed in the ListBox into a TextBox control.
          /// @code
          /// // This example uses the DoubleClick event of a ListBox to load text files
          /// // listed in the ListBox into a TextBox control. This example
          /// // assumes that the ListBox, named listBox1, contains a list of valid file
          /// // names with path and that this event handler method
          /// // is connected to the DoublClick event of a ListBox control named listBox1.
          /// // This example requires code access permission to access files.
          /// void listBox1_DoubleClick(const object& sender, const System::EventArgs& e) {
          ///   // Get the name of the file to open from the ListBox.
          ///   String file = listBox1.SelectedItem().ToString();
          ///
          ///   try {
          ///     // Determine if the file exists before loading.
          ///     if (System::IO::File::Exists(file)) {
          ///       // Open the file and use a TextReader to read the contents into the TextBox.
          ///       System::IO::FileInfo myFile(listBox1.SelectedItem().ToString());
          ///       System::IO::TextReader myData = myFile.OpenText();;
          ///
          ///       textBox1.Text = myData.ReadToEnd();
          ///       myData.Close();
          ///     }
          ///   } catch(const System::IO::FileNotFoundException&) {
          ///     // Exception is thrown by the OpenText method of the FileInfo class.
          ///     MessageBox::Show("The file you specified does not exist.");
          ///   } catch(const System::IO::IOException&) {
          ///     // Exception is thrown by the ReadToEnd method of the TextReader class.
          ///     MessageBox::Show("There was a problem loading the file into the TextBox. Ensure that the file is a valid text file.");
          ///   }
          /// }
          /// @endcode
          virtual void OnDoubleClick(const EventArgs& e) { this->DoubleClick(*this, e); }

          /// @brief Raises the EnabledChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnEnabledChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnEnabledChanged in a derived class, be sure to call the base class's OnEnabledChanged method so that registered delegates receive the event.
          virtual void OnEnabledChanged(const EventArgs& e);

          /// @brief Raises the ForeColorChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnForeColorChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnForeColorChanged in a derived class, be sure to call the base class's OnForeColorChanged method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example is an event-raising method that is executed when the Text property value changes. The Control class has several methods with the name pattern OnPropertyNameChanged that raise the corresponding PropertyNameChanged event when the PropertyName value changes (PropertyName represents the name of the corresponding property).<br><br>
          /// The following code example changes the ForeColor of a TextBox derived class displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive. This example requires that you have a class that derives from the TextBox class.
          /// @code
          /// void OnTextChanged(const System::EventArgs& e) override {
          ///   try {
          ///     // Convert the text to a Double and determine
          ///     // if it is a negative number.
          ///     if (Double::Parse(this->Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       this->ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       this->ForeColor = Color::Black;
          ///     }
          ///   } catch(...) {
          ///     // If there is an error, display the
          ///     // text using the system colors.
          ///     this->ForeColor = SystemColors::ControlText;
          ///   }
          ///
          ///   this->TextBox::OnTextChanged(e);
          /// }
          /// @endcode
          virtual void OnForeColorChanged(const EventArgs& e);

          /// @brief Raises the HandleCreated event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnHandleCreated method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnHandleCreated in a derived class, be sure to call the base class's OnHandleCreated method so that registered delegates receive the event.
          virtual void OnHandleCreated(const EventArgs& e) { this->HandleCreated(*this, e); }

          /// @biref Raises the HandleDestroyed event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnHandleDestroyed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnHandleDestroyed in a derived class, be sure to call the base class's OnHandleDestroyed method so that registered delegates receive the event.
          virtual void OnHandleDestroyed(const EventArgs& e) { this->HandleDestroyed(*this, e); }

          /// @brief Raises the Invalidated event.
          /// @param e An InvalidateEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnInvalidated method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnInvalidated in a derived class, be sure to call the base class's OnInvalidated method so that registered delegates receive the event.
          virtual void OnInvalidated(const InvalidateEventArgs& e) { this->Invalidated(*this, e); }

          /// @brief Raises the KeyDown event.
          /// @param e A KeyEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnKeyDown method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnKeyDown in a derived class, be sure to call the base class's OnKeyDown method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example uses the KeyDown event to determine the type of character entered into the control.
          /// @code
          /// // Boolean flag used to determine when a character other than a number is entered.
          /// bool nonNumberEntered = false;
          ///
          /// // Handle the KeyDown event to determine the type of character entered into the control.
          /// void textBox1_KeyDown(const object& sender, const System::Windows::Forms::KeyEventArgs& e) {
          ///   // Initialize the flag to false.
          ///   nonNumberEntered = false;
          ///
          ///   // Determine whether the keystroke is a number from the top of the keyboard.
          ///   if (e.KeyCode < Keys::D0 || e.KeyCode > Keys::D9) {
          ///     // Determine whether the keystroke is a number from the keypad.
          ///     if (e.KeyCode < Keys::NumPad0 || e.KeyCode > Keys::NumPad9) {
          ///       // Determine whether the keystroke is a backspace.
          ///       if(e.KeyCode != Keys::Back) {
          ///         // A non-numerical keystroke was pressed.
          ///         // Set the flag to true and evaluate in KeyPress event.
          ///         nonNumberEntered = true;
          ///       }
          ///     }
          ///   }
          ///
          ///   //If shift key was pressed, it's not a number.
          ///   if (Control::ModifierKeys == Keys::Shift) {
          ///     nonNumberEntered = true;
          ///   }
          /// }
          ///
          /// // This event occurs after the KeyDown event and can be used to prevent
          /// // characters from entering the control.
          /// void textBox1_KeyPress(const object& sender, System::Windows::Forms::KeyPressEventArgs& e) {
          ///   // Check for the flag being set in the KeyDown event.
          ///   if (nonNumberEntered == true) {
          ///     // Stop the character from being entered into the control since it is non-numerical.
          ///     e.Handled = true;
          ///   }
          /// }
          /// @endcode
          virtual void OnKeyDown(KeyEventArgs& e) { this->KeyDown(*this, e); }

          /// @brief Raises the KeyPress event.
          /// @partam e A KeyPressEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnKeyPress method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnKeyPress in a derived class, be sure to call the base class's OnKeyPress method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example uses the KeyDown event to determine the type of character entered into the control.
          /// @code
          /// // Boolean flag used to determine when a character other than a number is entered.
          /// bool nonNumberEntered = false;
          ///
          /// // Handle the KeyDown event to determine the type of character entered into the control.
          /// void textBox1_KeyDown(const object& sender, const System::Windows::Forms::KeyEventArgs& e) {
          ///   // Initialize the flag to false.
          ///   nonNumberEntered = false;
          ///
          ///   // Determine whether the keystroke is a number from the top of the keyboard.
          ///   if (e.KeyCode < Keys::D0 || e.KeyCode > Keys::D9) {
          ///     // Determine whether the keystroke is a number from the keypad.
          ///     if (e.KeyCode < Keys::NumPad0 || e.KeyCode > Keys::NumPad9) {
          ///       // Determine whether the keystroke is a backspace.
          ///       if(e.KeyCode != Keys::Back) {
          ///         // A non-numerical keystroke was pressed.
          ///         // Set the flag to true and evaluate in KeyPress event.
          ///         nonNumberEntered = true;
          ///       }
          ///     }
          ///   }
          ///
          ///   //If shift key was pressed, it's not a number.
          ///   if (Control::ModifierKeys == Keys::Shift) {
          ///     nonNumberEntered = true;
          ///   }
          /// }
          ///
          /// // This event occurs after the KeyDown event and can be used to prevent
          /// // characters from entering the control.
          /// void textBox1_KeyPress(const object& sender, System::Windows::Forms::KeyPressEventArgs& e) {
          ///   // Check for the flag being set in the KeyDown event.
          ///   if (nonNumberEntered == true) {
          ///     // Stop the character from being entered into the control since it is non-numerical.
          ///     e.Handled = true;
          ///   }
          /// }
          /// @endcode
          virtual void OnKeyPress(KeyPressEventArgs& e) { this->KeyPress(*this, e); }

          /// @brief Raises the KeyUp event.
          /// @param e A KeyEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnKeyUp method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes for Inheritors
          /// When overriding OnKeyUp in a derived class, be sure to call the base class's OnKeyUp method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example uses the KeyUp event with the Help class to display pop-up style help to the user.
          /// @code
          /// // This example demonstrates how to use the KeyUp event with the Help class to display
          /// // pop-up style help to the user of the application. When the user presses F1, the Help
          /// // class displays a pop-up window, similar to a ToolTip, near the control. This example assumes
          /// // that a TextBox control, named textBox1, has been added to the form and its KeyUp
          /// // event has been contected to this event handler method.
          /// void textBox1_KeyUp(const object& sender, System::Windows::Forms::KeyEventArgs& e) {
          ///   // Determine whether the key entered is the F1 key. Display help if it is.
          ///   if (e.KeyCode == Keys::F1) {
          ///     // Display a pop-up help topic to assist the user.
          ///     Help::ShowPopup(textBox1, "Enter your first name", Point(textBox1.Right, this.textBox1.Bottom));
          ///   }
          /// }
          /// @endcode
          virtual void OnKeyUp(KeyEventArgs& e) { this->KeyUp(*this, e); }

          /// @brief Raises the LocationChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnLocationChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnLocationChanged in a derived class, be sure to call the base class's OnLocationChanged method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example is an event-raising method that is executed when the Text property value changes. The Control class has several methods with the name pattern OnPropertyNameChanged that raise the corresponding PropertyNameChanged event when the PropertyName value changes (PropertyName represents the name of the corresponding property).<br><br>
          /// The following code example changes the ForeColor of a TextBox derived class displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive. This example requires that you have a class that derives from the TextBox class.
          /// @code
          /// void OnTextChanged(const System::EventArgs& e) override {
          ///   try {
          ///     // Convert the text to a Double and determine
          ///     // if it is a negative number.
          ///     if (Double::Parse(this->Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       this->ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       this->ForeColor = Color::Black;
          ///     }
          ///   } catch(...) {
          ///     // If there is an error, display the
          ///     // text using the system colors.
          ///     this->ForeColor = SystemColors::ControlText;
          ///   }
          ///
          ///   this->TextBox::OnTextChanged(e);
          /// }
          /// @endcode
          virtual void OnLocationChanged(const EventArgs& e);

          /// @brief Raises the LostFocus event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnLostFocus method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnLostFocus in a derived class, be sure to call the base class's OnLostFocus method so that registered delegates receive the event.
          virtual void OnLostFocus(const EventArgs& e) { this->LostFocus(*this, e); }

          /// @brief Raises the MouseCaptureChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseCaptureChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnMouseCaptureChanged in a derived class, be sure to call the base class's OnMouseCaptureChanged method so that registered delegates receive the event.
          virtual void OnMouseCaptureChanged(const EventArgs& e) { this->MouseCaptureChanged(*this, e); }

          /// @brief Raises the MouseClick event.
          /// @param e An MouseEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseClick method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnMouseClick in a derived class, be sure to call the base class's OnMouseClick method so that registered delegates receive the event.
          virtual void OnMouseClick(const MouseEventArgs& e) { this->MouseClick(*this, e); }

          /// @brief Raises the MouseDoubleClick event.
          /// @param e An MouseEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseDoubleClick method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnMouseDoubleClick in a derived class, be sure to call the base class's OnMouseDoubleClick method so that registered delegates receive the event.
          virtual void OnMouseDoubleClick(const MouseEventArgs& e) { this->MouseDoubleClick(*this, e); }

          /// @brief Raises the MouseDown event.
          /// @param e A MouseEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseDown method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnMouseDown in a derived class, be sure to call the base class's OnMouseDown method so that registered delegates receive the event.
          virtual void OnMouseDown(const MouseEventArgs& e) { this->MouseDown(*this, e); }

          /// @brief Raises the MouseEnter event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseEnter method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes for Inheritors
          /// When overriding OnMouseEnter in a derived class, be sure to call the base class's OnMouseEnter method so that registered delegates receive the event.
          virtual void OnMouseEnter(const EventArgs& e) { this->MouseEnter(*this, e); }

          /// @brief Raises the MouseHover event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseHover method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnMouseHover in a derived class, be sure to call the base class's OnMouseHover method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example demonstrates how to override the OnMouseHover and OnMouseMove methods in a derived class. To run the example, paste the following code in a new form and paste this class, forming the same file, after the form. Add a button of type FunButton to the form.
          /// @code
          /// class FunButton : public Button {
          /// protected:
          ///   void OnMouseHover(const System::EventArgs& e) override {
          ///     // Get the font size in Points, add one to the size, and reset the button's font to the larger size.
          ///     float fontSize = this->Font().SizeInPoints;
          ///     fontSize += 1;
          ///     System::Drawing::Size buttonSize = this->Size;
          ///     this->Font = System::Drawing::Font(Font::FontFamily, fontSize, Font::Style);
          ///
          ///     // Increase the size width and height of the button by 5 points each.
          ///     this->Size = System::Drawing::Size(this->Size().Width + 5, this->Size().Height + 5);
          ///
          ///     // Call myBase.OnMouseHover to activate the delegate.
          ///     this->Button::OnMouseHover(e);
          ///   }
          ///
          ///   void OnMouseMove(const MouseEventArgs& e) override {
          ///     // Make the cursor the Hand cursor when the mouse moves over the button.
          ///     this->Cursor = Cursors::Hand;
          ///
          ///     // Call MyBase.OnMouseMove to activate the delegate.
          ///     this->Button::OnMouseMove(e);
          ///   }
          /// @endcode
          virtual void OnMouseHover(const EventArgs& e) { this->MouseHover(*this, e); }

          /// @brief Raises the MouseLeave event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseLeave method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnMouseLeave in a derived class, be sure to call the base class's OnMouseLeave method so that registered delegates receive the event.
          virtual void OnMouseLeave(const EventArgs& e) { this->MouseLeave(*this, e); }

          /// @brief Raises the ouseMove event.
          /// @param e An MouseEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseMove method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnMouseMove in a derived class, be sure to call the base class's OnMouseMove method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example demonstrates how to override the OnMouseHover and OnMouseMove methods in a derived class. To run the example, paste the following code in a new form and paste this class, forming the same file, after the form. Add a button of type FunButton to the form.
          /// @code
          /// class FunButton : public Button {
          /// protected:
          ///   void OnMouseHover(const System::EventArgs& e) override {
          ///     // Get the font size in Points, add one to the size, and reset the button's font to the larger size.
          ///     float fontSize = this->Font().SizeInPoints;
          ///     fontSize += 1;
          ///     System::Drawing::Size buttonSize = this->Size;
          ///     this->Font = System::Drawing::Font(Font::FontFamily, fontSize, Font::Style);
          ///
          ///     // Increase the size width and height of the button by 5 points each.
          ///     this->Size = System::Drawing::Size(this->Size().Width + 5, this->Size().Height + 5);
          ///
          ///     // Call myBase.OnMouseHover to activate the delegate.
          ///     this->Button::OnMouseHover(e);
          ///   }
          ///
          ///   void OnMouseMove(const MouseEventArgs& e) override {
          ///     // Make the cursor the Hand cursor when the mouse moves over the button.
          ///     this->Cursor = Cursors::Hand;
          ///
          ///     // Call MyBase.OnMouseMove to activate the delegate.
          ///     this->Button::OnMouseMove(e);
          ///   }
          /// @endcode
          virtual void OnMouseMove(const MouseEventArgs& e) { this->MouseMove(*this, e); }

          /// @brief Raises the MouseUp event.
          /// @param e An MouseEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseUp method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnMouseUp in a derived class, be sure to call the base class's OnMouseUp method so that registered delegates receive the event.
          virtual void OnMouseUp(const MouseEventArgs& e) { this->MouseUp(*this, e); }

          /// @brief Raises the MouseWheel event.
          /// @param e An MouseEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnMouseWheel method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnMouseWheel in a derived class, be sure to call the base class's OnMouseWheel method so that registered delegates receive the event.
          virtual void OnMouseWheel(const MouseEventArgs& e) { this->MouseWheel(*this, e); }

          /// @brief Notifies the control of Windows messages.
          /// @param m A Message that represents the Windows message.
          /// @remarks The OnNotifyMessage method is called if the control's EnableNotifyMessage style bit is set in ControlStyles. The EnableNotifyMessage style in ControlStyles enables the control to be notified when the WndProc method receives a Windows message. With this method, semi-trusted controls can listen for Windows messages without enabling them to modify the message.
          /// @par Notes to Inheritors
          /// When overriding OnNotifyMessage in a derived class, calling the base class's OnNotifyMessage method is not necessary because there is no initial implementation.
          virtual void OnNotifyMessage(const Message& m) {}

          /// @brief Raises the Paint event.
          /// @param e An PaintEventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnPaint method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnPaint in a derived class, be sure to call the base class's OnPaint method so that registered delegates receive the event.
          /// @par examples
          /// The following code example enables the user to drag an image or image file onto the form, and have it be displayed at the point on it is dropped. The OnPaint method is overridden to repaint the image each time the form is painted; otherwise the image would only persist until the next repainting. The DragEnter event-handling method determines the type of data being dragged into the form and provides the appropriate feedback. The DragDrop event-handling method displays the image on the form, if an Image can be created from the data. Because the DragEventArgs.X and DragEventArgs.Y values are screen coordinates, the example uses the PointToClient method to convert them to client coordinates.
          /// @code
          /// private:
          ///   $<Image> picture;
          ///   Point pictureLocation;
          ///
          /// public:
          ///   Form1() {
          ///     // Enable drag-and-drop operations and
          ///     // add handlers for DragEnter and DragDrop.
          ///     this->AllowDrop = true;
          ///     this->DragDrop += DragEventHandler(*this, &Form1::Form1_DragDrop);
          ///     this->DragEnter += DragEventHandler(*this, &Form1::Form1_DragEnter);
          ///   }
          ///
          /// protected:
          ///   void OnPaint(PaintEventArgs& e) override {
          ///     // If there is an image and it has a location,
          ///     // paint it when the Form is repainted.
          ///     this->Form::OnPaint(e);
          ///     if(this->picture != null && this->pictureLocation != Point::Empty) {
          ///       e.Graphics.DrawImage(*this->picture, this.pictureLocation);
          ///     }
          ///   }
          ///
          /// private:
          ///   void Form1_DragDrop(const object& sender, DragEventArgs& e) {
          ///     // Handle FileDrop data.
          ///     if (e.Data.GetDataPresent(DataFormats::FileDrop) ) {
          ///       // Assign the file names to a string array, in
          ///       // case the user has selected multiple files.
          ///       $<Array<string>> files = as<Array<string>>(e.Data.GetData(DataFormats::FileDrop));
          ///       try {
          ///         // Assign the first image to the picture variable.
          ///         this->picture = Image::FromFile((*files)[0]);
          ///         // Set the picture location equal to the drop point.
          ///         this->pictureLocation = this->PointToClient(Point(e.X, e.Y));
          ///       } catch(const Exception& ex) {
          ///         MessageBox::Show(ex.Message);
          ///         return;
          ///       }
          ///     }
          ///
          ///     // Handle Bitmap data.
          ///     if (e.Data.GetDataPresent(DataFormats::Bitmap) ) {
          ///       try {
          ///         // Create an Image and assign it to the picture variable.
          ///         this->picture = as<Image>(e.Data.GetData(DataFormats.Bitmap));
          ///         // Set the picture location equal to the drop point.
          ///         this->pictureLocation = this->PointToClient(Point(e.X, e.Y) );
          ///       } catch(const Exception& ex) {
          ///         MessageBox::Show(ex.Message);
          ///         return;
          ///       }
          ///     }
          ///     // Force the form to be redrawn with the image.
          ///     this->Invalidate();
          ///   }
          ///
          ///   void Form1_DragEnter(const object& sender, DragEventArgs& e) {
          ///     // If the data is a file or a bitmap, display the copy cursor.
          ///     if (e.Data.GetDataPresent(DataFormats::Bitmap) || e.Data.GetDataPresent(DataFormats::FileDrop) ) {
          ///       e.Effect = DragDropEffects::Copy;
          ///     } else {
          ///       e.Effect = DragDropEffects::None;
          ///     }
          ///   }
          /// @endcode
          /// The following code example creates a PictureBox control on the form and uses the Paint event to draw to it.
          /// @code
          /// // This example creates a PictureBox control on the form and draws to it.
          /// // This example assumes that the Form_Load event handler method is
          /// // connected to the Load event of the form.
          ///
          /// PictureBox pictureBox1;
          ///
          /// void Form1_Load(const object& sender, const System::EventArgs& e) {
          ///   // Dock the PictureBox to the form and set its background to white.
          ///   pictureBox1.Dock = DockStyle::Fill;
          ///   pictureBox1.BackColor = Color::White;
          ///   // Connect the Paint event of the PictureBox to the event handler method.
          ///   pictureBox1.Paint += System::Windows::Forms::PaintEventHandler(*this &Form1::pictureBox1_Paint);
          ///
          ///   // Add the PictureBox control to the Form.
          ///   this->Controls().Add(pictureBox1);
          /// }::
          ///
          /// void pictureBox1_Paint(const object& sender, System::Windows::Forms::PaintEventArgs& e) {
          ///   // Create a local version of the graphics object for the PictureBox.
          ///   Graphics g = e.Graphics;
          ///
          ///   // Draw a string on the PictureBox.
          ///   g.DrawString("This is a diagonal line drawn on the control", Font("Arial",10), System::Drawing::Brushes::Blue, System::Drawing::Point(30,30));
          ///   // Draw a line in the PictureBox.
          ///   g.DrawLine(System::Drawing::Pens::Red, pictureBox1.Left, pictureBox1.Top, pictureBox1.Right, pictureBox1.Bottom);
          /// }
          /// @endcode
          virtual void OnPaint(PaintEventArgs& e) { this->Paint(*this, e); }

          /// @brief Raises the ParentChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnParentChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnParentChanged in a derived class, be sure to call the base class's OnParentChanged method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example is an event-raising method that is executed when the Text property value changes. The Control class has several methods with the name pattern OnPropertyNameChanged that raise the corresponding PropertyNameChanged event when the PropertyName value changes (PropertyName represents the name of the corresponding property).<br><br>
          /// The following code example changes the ForeColor of a TextBox derived class displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive. This example requires that you have a class that derives from the TextBox class.
          /// @code
          /// void OnTextChanged(const System::EventArgs& e) override {
          ///   try {
          ///     // Convert the text to a Double and determine
          ///     // if it is a negative number.
          ///     if (Double::Parse(this->Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       this->ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       this->ForeColor = Color::Black;
          ///     }
          ///   } catch(...) {
          ///     // If there is an error, display the
          ///     // text using the system colors.
          ///     this->ForeColor = SystemColors::ControlText;
          ///   }
          ///
          ///   this->TextBox::OnTextChanged(e);
          /// }
          /// @endcode
          virtual void OnParentChanged(const EventArgs& e);

          /// @brief Raises the SizeChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnSizeChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnSizeChanged in a derived class, be sure to call the base class's OnSizeChanged method so that registered delegates receive the event.
          virtual void OnSizeChanged(const EventArgs& e);

          /// @brief Raises the TabStopChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnTabStopChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnTabStopChanged in a derived class, be sure to call the base class's OnTabStopChanged method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example is an event-raising method that is executed when the Text property value changes. The Control class has several methods with the name pattern OnPropertyNameChanged that raise the corresponding PropertyNameChanged event when the PropertyName value changes (PropertyName represents the name of the corresponding property).<br><br>
          /// The following code example changes the ForeColor of a TextBox derived class displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive. This example requires that you have a class that derives from the TextBox class.
          /// @code
          /// void OnTextChanged(const System::EventArgs& e) override {
          ///   try {
          ///     // Convert the text to a Double and determine
          ///     // if it is a negative number.
          ///     if (Double::Parse(this->Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       this->ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       this->ForeColor = Color::Black;
          ///     }
          ///   } catch(...) {
          ///     // If there is an error, display the
          ///     // text using the system colors.
          ///     this->ForeColor = SystemColors::ControlText;
          ///   }
          ///
          ///   this->TextBox::OnTextChanged(e);
          /// }
          /// @endcode
          virtual void OnTabStopChanged(const EventArgs& e);

          /// @brief Raises the TextChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnTextChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnTextChanged in a derived class, be sure to call the base class's OnTextChanged method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example is an event-raising method that is executed when the Text property value changes. The Control class has several methods with the name pattern OnPropertyNameChanged that raise the corresponding PropertyNameChanged event when the PropertyName value changes (PropertyName represents the name of the corresponding property).<br><br>
          /// The following code example changes the ForeColor of a TextBox derived class displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive. This example requires that you have a class that derives from the TextBox class.
          /// @code
          /// void OnTextChanged(const System::EventArgs& e) override {
          ///   try {
          ///     // Convert the text to a Double and determine
          ///     // if it is a negative number.
          ///     if (Double::Parse(this->Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       this->ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       this->ForeColor = Color::Black;
          ///     }
          ///   } catch(...) {
          ///     // If there is an error, display the
          ///     // text using the system colors.
          ///     this->ForeColor = SystemColors::ControlText;
          ///   }
          ///
          ///   this->TextBox::OnTextChanged(e);
          /// }
          /// @endcode
          virtual void OnTextChanged(const EventArgs& e);

          /// @brief Raises the VisibleChanged event.
          /// @param e An EventArgs that contains the event data.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnVisibleChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          /// @par Notes to Inheritors
          /// When overriding OnVisibleChanged in a derived class, be sure to call the base class's OnVisibleChanged method so that registered delegates receive the event.
          /// @par Examples
          /// The following code example is an event-raising method that is executed when the Text property value changes. The Control class has several methods with the name pattern OnPropertyNameChanged that raise the corresponding PropertyNameChanged event when the PropertyName value changes (PropertyName represents the name of the corresponding property).<br><br>
          /// The following code example changes the ForeColor of a TextBox derived class displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive. This example requires that you have a class that derives from the TextBox class.
          /// @code
          /// void OnTextChanged(const System::EventArgs& e) override {
          ///   try {
          ///     // Convert the text to a Double and determine
          ///     // if it is a negative number.
          ///     if (Double::Parse(this->Text) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       this->ForeColor = Color::Red;
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       this->ForeColor = Color::Black;
          ///     }
          ///   } catch(...) {
          ///     // If there is an error, display the
          ///     // text using the system colors.
          ///     this->ForeColor = SystemColors::ControlText;
          ///   }
          ///
          ///   this->TextBox::OnTextChanged(e);
          /// }
          /// @endcode
          virtual void OnVisibleChanged(const EventArgs& e);

          /// @cond
          Nullable<System::Drawing::Color> backColor;
          mutable System::Drawing::SolidBrush backBrush {System::Drawing::SystemColors::Control};
          System::Drawing::Size clientSize;
          ControlCollection controls {*this};
          System::Drawing::Color defaultBackColor;
          System::Drawing::Color defaultForeColor;
          bool enabled = true;
          Nullable<System::Drawing::Color> foreColor;
          mutable intptr handle = 0;
          static System::Collections::Generic::Dictionary<intptr, ref<Control>> handles;
          System::Drawing::Point location;
          System::Collections::Generic::Dictionary<int32, Action<Message&>> messageActions;
          string name;
          ref<Control> parent;
          System::Drawing::Size size;
          State state = State::Empty;
          ControlStyles style = (ControlStyles)0;
          bool suspendLayout = false;
          bool tabStop = true;
          string text;
          bool visible = true;
          /// @endcond

        private:
          static bool ReflectMessage(intptr hWnd, Message& m);
          intptr SendMessage(int32 msg, intptr wparam, intptr lparam) const;
          void WmCaptureChange(Message& message);
          void WmClose(Message& message);
          void WmCommand(Message& message);
          void WmContextMenu(Message& message);
          void WmCreate(Message& message);
          void WmCtlColorControl(Message& message);
          void WmDestroy(Message& message);
          void WmDisplayChange(Message& message);
          void WmDrawItem(Message& message);
          void WmEraseBkgnd(Message& message);
          void WmExitMenuLoop(Message& message);
          void WmGetObject(Message& message);
          void WmHelp(Message& message);
          void WmImeChar(Message& message);
          void WmImeNotify(Message& message);
          void WmImeStartComposition(Message& message);
          void WmInitMenuPopup(Message& message);
          void WmInputLangChange(Message& messsage);
          void WmInputLangChangeRequest(Message& messsage);
          void WmKeyChar(Message& messsage);
          void WmKillFocus(Message& message);
          void WmMeasureItem(Message& message);
          void WmMenuChar(Message& message);
          void WmMenuSelect(Message& message);
          void WmMouseDown(Message& message);
          void WmMouseEnter(Message& message);
          void WmMouseHover(Message& message);
          void WmMouseLeave(Message& message);
          void WmMouseMove(Message& message);
          void WmMouseUp(Message& message);
          void WmMouseWheel(Message& message);
          void WmNotify(Message& message);
          void WmNotifyFormat(Message& message);
          void WmPaint(Message& message);
          void WmParentNotify(Message& message);
          void WmPrintClient(Message& message);
          void WmQueryNewPalette(Message& message);
          void WmShowWindow(Message& message);
          void WmSetCursor(Message& message);
          void WmSetFocus(Message& message);
          void WmSysCommand(Message& message);
          void WmUpdateUIState(Message& message);
          void WmWindowPosChanged(Message& message);
          void WmWindowPosChanging(Message& message);

          bool GetState(State flag) const { return ((int32)this->state & (int32)flag) == (int32)flag; }
          void SetState(State flag, bool value) { this->state = value ? (State)((int32)this->state | (int32)flag) : (State)((int32)this->state & ~(int32)flag); }

          enum class State {
            Empty = 0,
            DoubleClickFired = 0b1,
            MouseEntered = 0x10,
          };

          static ref<Control> controlEntered;
          bool setFocusAfterHandleCreated = false;
          bool setClientSizeAfterHandleCreated = false;
        };
      }
    }
  }
}
