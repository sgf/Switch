/// @file
/// @brief Contains Switch::System::Windows::Forms::ControlEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>

#include "../../../SystemWindowsFormsExport.hpp"
#include "UICues.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        /// @brief Provides data for the ControlAdded and ControlRemoved events.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks For more information about handling events, see Handling and Raising Events.
        /// @par Examples
        /// The following code example demonstrates the use of the ControlAdded and ControlRemoved events. The example requires that two Button controls are added to the form and connected to the addControl_Click and removeControl_Click event handling methods.
        /// @code
        /// // This example demonstrates the use of the ControlAdded and
        /// // ControlRemoved events. This example assumes that two Button controls
        /// // are added to the form and connected to the AddControlClick and
        /// // RemoveControlClick event-handler methods.
        /// void Form1Load(const object& sender, const System::EventArgs& e) {
        ///   // Connect the ControlRemoved and ControlAdded event handlers
        ///   // to the event-handler methods.
        ///   // ControlRemoved and ControlAdded are not available at design time.
        ///   ControlRemoved += System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlRemoved);
        ///   ControlAdded += System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlAdded);
        /// }
        /// void ControlAdded(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
        ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been added to the form.");
        /// }
        /// void ControlRemoved(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
        ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been removed from the form.");
        /// }
        /// // Click event handler for a Button control. Adds a TextBox to the form.
        /// void AddControlClick(const object& sender, const System::EventArgs& e) {
        ///   // Create a new TextBox control and add it to the form.
        ///   $<TextBox> textBox1 = new_<TextBox>();
        ///   textBox1->Size(Size(100, 10));
        ///   textBox1->Location(Point(10, 10));
        ///   // Name the control in order to remove it later. The name must be specified
        ///   // if a control is added at run time.
        ///   textBox1->Name("textBox1");
        ///   // Add the control to the form's control collection.
        ///   Controls.Add(textBox1);
        /// }
        /// // Click event handler for a Button control.
        /// // Removes the previously added TextBox from the form.
        /// void RemoveControlClick(const object& sender, const System::EventArgs& e) {
        ///   // Loop through all controls in the form's control collection.
        ///   for ($<Control> tempCtrl : Controls) {
        ///     // Determine whether the control is textBox1,
        ///     // and if it is, remove it.
        ///     if (tempCtrl->Name() == "textBox1") {
        ///       Controls.Remove(tempCtrl);
        ///     }
        ///   }
        /// }
        /// @endcode
        class system_windows_forms_export_ ControlEventArgs : public EventArgs {
        public:
          /// @brief nitializes a new instance of the ControlEventArgs class.
          ControlEventArgs() {}

          /// @brief nitializes a new instance of the ControlEventArgs class for the specified control.
          /// @param control The Control to store in this event.
          /// @par Examples
          /// The following code example demonstrates the use of the ControlAdded and ControlRemoved events. The example requires that two Button controls are added to the form and connected to the addControl_Click and removeControl_Click event handling methods.
          /// @code
          /// // This example demonstrates the use of the ControlAdded and
          /// // ControlRemoved events. This example assumes that two Button controls
          /// // are added to the form and connected to the AddControlClick and
          /// // RemoveControlClick event-handler methods.
          /// void Form1Load(const object& sender, const System::EventArgs& e) {
          ///   // Connect the ControlRemoved and ControlAdded event handlers
          ///   // to the event-handler methods.
          ///   // ControlRemoved and ControlAdded are not available at design time.
          ///   ControlRemoved += System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlRemoved);
          ///   ControlAdded += System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlAdded);
          /// }
          /// void ControlAdded(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
          ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been added to the form.");
          /// }
          /// void ControlRemoved(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
          ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been removed from the form.");
          /// }
          /// // Click event handler for a Button control. Adds a TextBox to the form.
          /// void AddControlClick(const object& sender, const System::EventArgs& e) {
          ///   // Create a new TextBox control and add it to the form.
          ///   $<TextBox> textBox1 = new_<TextBox>();
          ///   textBox1->Size(Size(100, 10));
          ///   textBox1->Location(Point(10, 10));
          ///   // Name the control in order to remove it later. The name must be specified
          ///   // if a control is added at run time.
          ///   textBox1->Name("textBox1");
          ///   // Add the control to the form's control collection.
          ///   Controls.Add(textBox1);
          /// }
          /// // Click event handler for a Button control.
          /// // Removes the previously added TextBox from the form.
          /// void RemoveControlClick(const object& sender, const System::EventArgs& e) {
          ///   // Loop through all controls in the form's control collection.
          ///   for ($<Control> tempCtrl : Controls) {
          ///     // Determine whether the control is textBox1,
          ///     // and if it is, remove it.
          ///     if (tempCtrl->Name() == "textBox1") {
          ///       Controls.Remove(tempCtrl);
          ///     }
          ///   }
          /// }
          /// @endcode
          ControlEventArgs(const System::Windows::Forms::Control& control) : control(&control) {}

          /// @brief Gets the control object used by this event.
          /// @return The Control used by this event.
          /// @par Examples
          /// The following code example demonstrates the use of the ControlAdded and ControlRemoved events. The example requires that two Button controls are added to the form and connected to the addControl_Click and removeControl_Click event handling methods.
          /// @code
          /// // This example demonstrates the use of the ControlAdded and
          /// // ControlRemoved events. This example assumes that two Button controls
          /// // are added to the form and connected to the AddControlClick and
          /// // RemoveControlClick event-handler methods.
          /// void Form1Load(const object& sender, const System::EventArgs& e) {
          ///   // Connect the ControlRemoved and ControlAdded event handlers
          ///   // to the event-handler methods.
          ///   // ControlRemoved and ControlAdded are not available at design time.
          ///   ControlRemoved += System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlRemoved);
          ///   ControlAdded += System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlAdded);
          /// }
          /// void ControlAdded(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
          ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been added to the form.");
          /// }
          /// void ControlRemoved(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
          ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been removed from the form.");
          /// }
          /// // Click event handler for a Button control. Adds a TextBox to the form.
          /// void AddControlClick(const object& sender, const System::EventArgs& e) {
          ///   // Create a new TextBox control and add it to the form.
          ///   $<TextBox> textBox1 = new_<TextBox>();
          ///   textBox1->Size(Size(100, 10));
          ///   textBox1->Location(Point(10, 10));
          ///   // Name the control in order to remove it later. The name must be specified
          ///   // if a control is added at run time.
          ///   textBox1->Name("textBox1");
          ///   // Add the control to the form's control collection.
          ///   Controls.Add(textBox1);
          /// }
          /// // Click event handler for a Button control.
          /// // Removes the previously added TextBox from the form.
          /// void RemoveControlClick(const object& sender, const System::EventArgs& e) {
          ///   // Loop through all controls in the form's control collection.
          ///   for ($<Control> tempCtrl : Controls) {
          ///     // Determine whether the control is textBox1,
          ///     // and if it is, remove it.
          ///     if (tempCtrl->Name() == "textBox1") {
          ///       Controls.Remove(tempCtrl);
          ///     }
          ///   }
          /// }
          /// @endcode
          const System::Windows::Forms::Control& Control() const { return *control; }

        private:
          const System::Windows::Forms::Control* control;
        };
      }
    }
  }
}
