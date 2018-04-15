/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

#include <Switch/System/IntPtr.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/Drawing/Point.hpp>
#include <Switch/System/Drawing/Size.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents the image used to paint the mouse pointer.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks A cursor is a small picture whose location on the screen is controlled by a pointing device, such as a mouse, pen, or trackball. When the user moves the pointing device, the operating system moves the cursor accordingly.
        /// @remarks Different cursor shapes are used to inform the user what operation the mouse will have. For example, when editing or selecting text, a Cursors.IBeam cursor is typically displayed. A wait cursor is commonly used to inform the user that a process is currently running. Examples of processes you might have the user wait for are opening a file, saving a file, or filling a control such as a DataGrid, ListBox or TreeView with a large amount of data.
        /// @remarks All controls that derive from the Control class have a Cursor property. To change the cursor displayed by the mouse pointer when it is within the bounds of the control, assign a Cursor to the Cursor property of the control. Alternatively, you can display cursors at the application level by assigning a Cursor to the Current property. For example, if the purpose of your application is to edit a text file, you might set the Current property to Cursors.WaitCursor to display a wait cursor over the application while the file loads or saves to prevent any mouse events from being processed. When the process is complete, set the Current property to Cursors.Default for the application to display the appropriate cursor over each control type.
        /// @note If you call Application.DoEvents before resetting the Current property back to the Cursors.Default cursor, the application will resume listening for mouse events and will resume displaying the appropriate Cursor for each control in the application.
        /// @remarks Cursor objects can be created from several sources, such as the handle of an existing Cursor, a standard Cursor file, a resource, or a data stream.
        /// @note The Cursor class does not support animated cursors (.ani files) or cursors with colors other than black and white.
        /// @remarks If the image you are using as a cursor is too small, you can use the DrawStretched method to force the image to fill the bounds of the cursor. You can temporarily hide the cursor by calling the Hide method, and restore it by calling the Show method.
        /// @par Examples
        /// The following code example displays a form that demonstrates using a custom cursor. The custom Cursor is embedded in the application's resource file. The example requires a cursor contained in a cursor file named MyCursor.cur. To compile this example using the command line, include the following flag: /res:MyCursor.Cur, CustomCursor.MyCursor.Cur
        /// @include Cursor.cpp
        class system_windows_forms_export_ Cursor : public object {
        public:
          /// @cond
          Cursor() {}
          Cursor(const Cursor& cursor) : data(cursor.data) {}
          Cursor& operator=(const Cursor&) = default;
          bool operator<(const Cursor& cursor) const { return this->data->handle < cursor.data->handle; }
          bool operator>(const Cursor& cursor) const { return this->data->handle > cursor.data->handle; }
          ~Cursor();
          /// @endcond

          /// @brief Initializes a new instance of the Cursor class from the specified Windows handle.
          /// @param handle An IntPtr that represents the Windows handle of the cursor to create.
          /// @exception ArgumentException handle is IntPtr::Zero.
          /// @remarks You must free the cursor handle when you are done with it. For more information about disposing of resources, see Cleaning Up Unmanaged Resources.
          /// @par Examples
          /// The following code example creates a cursor from the Current cursor's Handle, changes its position and clipping rectangle. The result is the cursor will move up and to the left 50 pixels from where it is when the code is executed. Additionally, the cursor's clipping rectangle is changed to the bounds of the form (by default it is the user's whole screen). This example requires a Form and a Button to call this code when it is clicked.
          /// @code
          /// void MoveCursor() {
          ///   // Set the Current cursor, move the cursor's Position,
          ///   // and set its clipping rectangle to the form.
          ///
          ///   this->cursor = Cursor(Cursor::Current().Handle);
          ///   Cursor::Position = System::Drawing::Point(Cursor::Position().X - 50, Cursor::Position().Y - 50);
          ///   Cursor::Clip = System::Drawing::Rectangle(this->Location, this->Size);
          /// }
          /// @endcode
          explicit Cursor(intptr handle);

          /// @brief Gets the handle of the cursor.
          /// @return An IntPtr that represents the cursor's handle.
          /// @exception xception The handle value is IntPtr::Zero.
          /// @remarks This is not a copy of the handle; do not dispose of it.
          /// @par Examples
          /// The following code example creates a cursor from the Current cursor's Handle, changes its position and clipping rectangle. The result is the cursor will move up and to the left 50 pixels from where it is when the code is executed. Additionally, the cursor's clipping rectangle is changed to the bounds of the form (by default it is the user's whole screen). This example requires a Form and a Button to call this code when it is clicked.
          /// @code
          /// void MoveCursor() {
          ///   // Set the Current cursor, move the cursor's Position,
          ///   // and set its clipping rectangle to the form.
          ///
          ///   this->cursor = Cursor(Cursor::Current().Handle);
          ///   Cursor::Position = System::Drawing::Point(Cursor::Position().X - 50, Cursor::Position().Y - 50);
          ///   Cursor::Clip = System::Drawing::Rectangle(this->Location, this->Size);
          /// }
          /// @endcode
          property_<intptr, readonly_> Handle {
            get_ {return this->data->handle;}
          };

          /// @brief Gets the cursor hot spot.
          /// @return A Point representing the cursor hot spot.
          /// @remarks The HotSpot is the Point in the cursor that interacts with other elements on the screen.
          property_<System::Drawing::Point, readonly_> HotSpot {
            get_ {return this->data->hotSpot;}
          };

          /// @brief Gets or sets the cursor's position.
          /// @return A Point that represents the cursor's position in screen coordinates.
          /// @remarks The Position property is identical to the Control.MousePosition property.
          /// @par Examples
          /// The following code example creates a cursor from the Current cursor's Handle, changes its position and clipping rectangle. The result is the cursor will move up and to the left 50 pixels from where it is when the code is executed. Additionally, the cursor's clipping rectangle is changed to the bounds of the form (by default it is the user's whole screen). This example requires a Form and a Button to call this code when it is clicked.
          /// @code
          /// void MoveCursor() {
          ///   // Set the Current cursor, move the cursor's Position, and set its clipping rectangle to the form.
          ///   this->Cursor = System::Windows::Forms::Cursor(System::Windows::Forms::Cursor::Current().Handle);
          ///   System::Windows::Forms::Cursor::Position = System::Drawing::Point(System::Windows::Forms::Cursor::Position().X - 50, System::Windows::Forms::Cursor::Position().Y - 50);
          ///   System::Windows::Forms::Cursor::Clip = System::Drawing::Rectangle(this->Location, this->Size);
          /// }
          /// @endcode
          static property_<System::Drawing::Point> Position;

          /// @brief Gets the size of the cursor object.
          /// @return A Size that represents the width and height of the Cursor.
          /// @par Examples
          /// The following code example draws the specified cursor on the form in its normal size, and in stretched mode, twice its size. This example requires a Form and a Cursor object to pass into the method when it is called.
          /// @code
          /// void DrawCursorsOnForm(Cursor& cursor) {
          ///   // If the form's cursor is not the Hand cursor and the
          ///   // Current cursor is the Default, Draw the specified
          ///   // cursor on the form in normal size and twice normal size.
          ///   if (this->Cursor != Cursors::Hand && Cursor::Current == Cursors::Default) {
          ///     // Draw the cursor stretched.
          ///     Graphics graphics = this->CreateGraphics();
          ///     Rectangle rectangle = System::Drawing::Rectangle(System::Drawing::Point(10,10), System::Drawing::Size(cursor.Size().Width * 2, cursor.Size().Height * 2));
          ///     cursor.DrawStretched(graphics, rectangle);
          ///
          ///     // Draw the cursor in normal size.
          ///     rectangle.Location = System::Drawing::Point(rectangle.Width + rectangle.Location().X, rectangle.Height + rectangle.Location().Y);
          ///     rectangle.Size = cursor.Size;
          ///     cursor.Draw(graphics, rectangle);
          ///   }
          /// }
          /// @endcode
          property_<System::Drawing::Size, readonly_> Size {
            get_ {return this->data->size;}
          };

          /// @brief Gets or sets the object that contains data about the Cursor.
          /// @return An Object that contains data about the Cursor. The default is null.
          property_<ref<object>> Tag {
            get_ {return this->data->tag;},
            set_ {this->data->tag = value;}
          };

          /// @brief Hides the cursor.
          /// @remarks The Show and Hide method calls must be balanced. For every call to the Hide method there must be a corresponding call to the Show method.
          /// @par Examples
          /// The following code example hides the cursor when the mouse pointer enters the button's client area. Likewise, when the mouse pointer leaves the button's client area, the cursor is shown again. This example requires a Form with a Button named myButton.
          /// @code
          /// void myButton_MouseEnter(const object& sender, const System::EventArgs& e) {
          ///   // Hide the cursor when the mouse pointer enters the button.
          ///   Cursor::Hide();
          /// }
          ///
          /// void myButton_MouseLeave(const object& sender, const System::EventArgs& e) {
          ///   // Show the cursor when the mouse pointer leaves the button.
          ///   Cursor::Show();
          /// }
          /// @endcode
          static void Hide();

          /// @brief Shows the cursor.
          /// @remarks The Show and Hide method calls must be balanced. For every call to the Hide method there must be a corresponding call to the Show method.
          /// @par Examples
          /// The following code example hides the cursor when the mouse pointer enters the button's client area. Likewise, when the mouse pointer leaves the button's client area, the cursor is shown again. This example requires a Form with a Button named myButton.
          /// @code
          /// void myButton_MouseEnter(const object& sender, const System::EventArgs& e) {
          ///   // Hide the cursor when the mouse pointer enters the button.
          ///   Cursor::Hide();
          /// }
          ///
          /// void myButton_MouseLeave(const object& sender, const System::EventArgs& e) {
          ///   // Show the cursor when the mouse pointer leaves the button.
          ///   Cursor::Show();
          /// }
          /// @endcode
          static void Show();

        private:
          struct Data {
            intptr handle = IntPtr::Zero;
            System::Drawing::Point hotSpot;
            System::Drawing::Size size;
            ref<object> tag;
          };

          $<Data> data = new_<Data>();
        };
      }
    }
  }
}
