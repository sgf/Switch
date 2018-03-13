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
#include "../../../SystemWindowsFormsExport.hpp"
#include "../../ComponentModel/Component.hpp"
#include "../../ComponentModel/EventHandlerList.hpp"
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
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Defines the base class for controls, which are components with visual representation.
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
          /// @par Examples
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
            /// @brief Adds the specified control to the control collection.
            /// @exception Exception The specified control is a top-level control, or a circular control reference would result if this control were added to the control collection.
            /// @exception ArgumentException The object assigned to the value parameter is not a Control.
            /// @remarks The Add method allows you to add Control objects to the end of the control collection.
            /// @remarks You can also add new Control objects to the collection by using the AddRange method.
            /// @remarks To remove a Control that you previously added, use the Remove, RemoveAt, or Clear methods.
            /// @note A Control can only be assigned to one Control.ControlCollection at a time. If the Control is already a child of another control it is removed from that control before it is added to another control.
            /// @par Notes to Inheritors
            /// When overriding Add in a derived class, be sure to call the base class's Add method to ensure that the control is added to the collection.
            /// @par Example
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
            /// @par Example
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
            /// @par Example
            /// The following code example removes the first Control in the Control.ControlCollection of the derived class Panel if the count of the collection is greater than zero. The example requires that you have created a Panel, a Button, and at least one other control on a Form. The other controls are added to the Panel control, and the Panel control added to the Form. When the button is clicked, the first control contained in the panel is removed from the Control.ControlCollection.
            /// @code
            /// // Remove the first control in the collection.
            /// void removeAtButton_Click(object sender, System.EventArgs e) {
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
          /// @par Example
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
          /// @par Example
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
          /// @par Example
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
          /// @par Example
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

          property_<System::Drawing::Size> ClientSize{
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
          property_<ControlCollection&, readonly_> Controls {
            get_->ControlCollection& {return this->controls; }
          };

          static property_<System::Drawing::Color, readonly_> DefaultBackColor;

          static property_<System::Drawing::Color, readonly_> DefaultForeColor;

          property_<bool, readonly_> HasChildren {
            get_ {return this->Controls().Count != 0;}
          };

          property_<bool> Enabled{
            get_ {return this->enabled; },
            set_ {
              if (this->enabled != value) {
                this->enabled = value;
                this->OnEnabledChanged(EventArgs::Empty);
              }
            }
          };

          property_<System::Drawing::Color> ForeColor {
            get_{ return (!this->foreColor.HasValue && this->parent != null) ? this->parent().ForeColor : this->foreColor.GetValueOrDefault(DefaultForeColor); },
            set_ {
              if (this->foreColor != value) {
                this->foreColor = value;
                this->OnForeColorChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets or sets the height of the control.
          /// @return int32 The height of the control in pixels.
          /// @remarks Changes made to the Height and Top property values cause the Bottom property value of the control to change.
          /// @note The minimum height for the derived control Splitter is one pixel. The default height for the Splitter control is three pixels. Setting the height of the Splitter control to a value less than one will reset the property value to the default height.
          property_<int32> Height {
            get_ { return this->size.Height(); },
            set_ { this->Size(System::Drawing::Size(this->size.Width(), value)); }
          };

          property_<bool, readonly_> IsHandleCreated {
            get_ { return this->handle != 0; }
          };

          property_<int32> Left {
            get_{ return this->location.X(); },
            set_{ this->Location(System::Drawing::Point(value, this->location.Y())); }
          };

          /// @brief Gets or sets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
          /// @return System::Drawing::Point The Point that represents the upper-left corner of the control relative to the upper-left corner of its container.
          /// @remarks Because the Point class is returned by value, meaning accessing the property returns a copy of the upper-left point of the control. So, adjusting the X or Y properties of the Point returned from this property will not affect the Left, Right, Top, or Bottom property values of the control. To adjust these properties set each property value individually, or set the Location property with a new Point.
          /// @remarks If the Control is a Form, the Location property value represents the upper-left corner of the Form in screen coordinates.
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
          property_<string> Name {
            get_ { return this->name; },
            set_ {
              if (this->name != value) {
                this->name = value;
                this->OnNameChanged(EventArgs::Empty);
              }
            }
          };

          /// @brief Gets or sets the parent container of the control.
          /// @return Control A Control that represents the parent or container control of the control.
          /// @remarks Setting the Parent property value to null removes the control from the Control.ControlCollection of its current parent control.
          property_<ref<Control>> Parent {
            get_ {return this->parent;},
            set_ {this->SetParent(value);}
          };

          property_<int32, readonly_> Right{
            get_{ return this->location.X() + this->size.Width(); }
          };

          /// @brief Gets or sets the height and width of the control.
          /// @return System::Drawing::Size The Size that represents the height and width of the control in pixels.
          /// @remarks Because the Size class is returned by value, meaning accessing the property returns a copy of the size of the control. So, adjusting the Width or Height properties of the Size returned from this property will not affect the Width or Height of the control. To adjust the Width or Height of the control, you must set the control's Width or Height property, or set the Size property with a new Size.
          /// @note To maintain better performance, do not set the Size of a control in its constructor. The preferred method is to override the DefaultSize property.
          property_<System::Drawing::Size> Size {
            get_ { return this->size; },
            set_ {
              if (this->size != value) {
                this->size = value;
                this->OnSizeChanged(EventArgs::Empty);
              }
            }
          };

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
          /// @note When overriding the Text property in a derived class, use the base class's Text property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and setaccessors of the Text property; you can override only one if needed.
          property_<const string&> Text {
            get_->const string& { return this->text; },
            set_ {
              if (this->text != value) {
                this->text = value;
                this->OnTextChanged(EventArgs::Empty);
              }
            }
          };

          property_<int32> Top {
            get_{ return this->location.Y(); },
            set_{ this->Location(System::Drawing::Point(this->location.X(), value)); }
          };

          property_<bool> Visible {
            get_ { return this->visible; },
            set_ {
              if (this->visible != value) {
                this->visible = value;
                this->OnVisibleChanged(EventArgs::Empty);
              }
            }
          };

          property_<int32> Width {
            get_ { return this->size.Width(); },
            set_ { this->Size(System::Drawing::Size(value, this->size.Height())); }
          };

          void CreateControl();

          bool Focus();

          static ref<Control> FromHandle(intptr handle) {
            try {
              return handles[handle];
            } catch (...) {
              return ref<Control>::Null();
            }
          }

          void Hide();

          void Invalidate() { Invalidate(false); }

          void Invalidate(bool invalidateChildren);

          void Invalidate(const System::Drawing::Rectangle& rect) { Invalidate(rect, false); }

          void Invalidate(const System::Drawing::Rectangle& rect, bool invalidateChildren);

          System::Drawing::Point PointToClient(System::Drawing::Point point) const;

          System::Drawing::Point PointToScreen(System::Drawing::Point point) const;

          bool PreProcessMessage(const Message& msg);

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

          virtual void WndProc(Message& message);

          EventHandler BackColorChanged;
          EventHandler Click;
          EventHandler ClientSizeChanged;
          EventHandler DoubleClick;
          EventHandler EnabledChanged;
          EventHandler ForeColorChanged;
          EventHandler HandleCreated;
          EventHandler HandleDestroyed;
          InvalidateEventHandler Invalidated;
          KeyEventHandler KeyDown;
          KeyPressEventHandler KeyPress;
          KeyEventHandler KeyUp;
          EventHandler LocationChanged;
          EventHandler LostFocus;
          EventHandler MouseCaptureChanged;
          MouseEventHandler MouseClick;
          MouseEventHandler MouseDoubleClick;
          MouseEventHandler MouseDown;
          EventHandler MouseEnter;
          EventHandler MouseHover;
          EventHandler MouseLeave;
          MouseEventHandler MouseMove;
          MouseEventHandler MouseUp;
          MouseEventHandler MouseWheel;
          EventHandler NameChanged;
          PaintEventHandler Paint;
          EventHandler ParentChanged;
          EventHandler SizeChanged;
          EventHandler TabStopChanged;
          EventHandler TextChanged;
          EventHandler VisibleChanged;

        protected:
          property_<System::Drawing::Size, readonly_> DefaultSize {
            get_ { return this->GetDefaultSize(); }
          };

          /// @brief Creates a handle for the control
          /// @remarks You typically should not call the CreateHandle method directly. The preferred method is to call the CreateControl method, which forces a handle to be created for the control and its child controls when the control is created.
          /// @par Notes to Inheritors
          /// When overriding CreateHandle in a derived class, be sure to call the base class's CreateHandle method to ensure that the handle is created.
          virtual void CreateHandle();

          virtual void DefWndProc(Message& message);

          virtual void DestroyHandle();

          /// @brief Gets the default size of the control.
          /// @return Switch::System::Drawing::Size The default Size of the control.
          virtual System::Drawing::Size GetDefaultSize() const { return System::Drawing::Size(0, 0); }

          virtual void SetParent(ref<Control> parent) {
            if (this->parent != parent) {
              if (parent == null && this->parent != null)
                this->parent().controls.Remove(*this);
              else
                const_cast<Control&>(parent()).controls.Add(*this);
              this->OnParentChanged(EventArgs::Empty);
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

          virtual bool GetStyle(ControlStyles flag) { return ((int32)this->style & (int32)flag) == (int32)flag; }

          virtual void SetStyle(ControlStyles flag, bool value) { this->style = value ? (ControlStyles)((int32)this->state | (int32)flag) : (ControlStyles)((int32)this->style & ~(int32)flag); }

          virtual void OnCreateControl() {}

          virtual void OnBackColorChanged(const EventArgs& e);

          virtual void OnClick(const EventArgs& e) { this->Click(*this, e); }

          virtual void OnClientSizeChanged(const EventArgs& e);

          virtual void OnDoubleClick(const EventArgs& e) { this->DoubleClick(*this, e); }

          virtual void OnEnabledChanged(const EventArgs& e);

          virtual void OnForeColorChanged(const EventArgs& e);

          virtual void OnHandleCreated(const EventArgs& e) { this->HandleCreated(*this, e); }

          virtual void OnHandleDestroyed(const EventArgs& e) { this->HandleDestroyed(*this, e); }

          virtual void OnKeyDown(KeyEventArgs& e) { this->KeyDown(*this, e); }

          virtual void OnKeyPress(KeyPressEventArgs& e) { this->KeyPress(*this, e); }

          virtual void OnKeyUp(KeyEventArgs& e) { this->KeyUp(*this, e); }

          virtual void OnInvalidated(const InvalidateEventArgs& e) { this->Invalidated(*this, e); }

          virtual void OnLocationChanged(const EventArgs& e);

          virtual void OnLostFocus(const EventArgs& e) { this->LostFocus(*this, e); }

          virtual void OnMouseCaptureChanged(const EventArgs& e) { this->MouseCaptureChanged(*this, e); }

          virtual void OnMouseClick(const MouseEventArgs& e) { this->MouseClick(*this, e); }

          virtual void OnMouseDoubleClick(const MouseEventArgs& e) { this->MouseDoubleClick(*this, e); }

          virtual void OnMouseDown(const MouseEventArgs& e) { this->MouseDown(*this, e); }

          virtual void OnMouseEnter(const EventArgs& e) { this->MouseEnter(*this, e); }

          virtual void OnMouseHover(const EventArgs& e) { this->MouseHover(*this, e); }

          virtual void OnMouseLeave(const EventArgs& e) { this->MouseLeave(*this, e); }

          virtual void OnMouseMove(const MouseEventArgs& e) { this->MouseMove(*this, e); }

          virtual void OnMouseUp(const MouseEventArgs& e) { this->MouseUp(*this, e); }

          virtual void OnMouseWheel(const MouseEventArgs& e) { this->MouseWheel(*this, e); }

          virtual void OnNameChanged(const EventArgs& e) { this->NameChanged(*this, e); }

          virtual void OnNotifyMessage(const Message& m) {}

          virtual void OnPaint(PaintEventArgs& e) { this->Paint(*this, e); }

          virtual void OnParentChanged(const EventArgs& e);

          virtual void OnSizeChanged(const EventArgs& e);

          virtual void OnTabStopChanged(const EventArgs& e);

          virtual void OnTextChanged(const EventArgs& e);

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
