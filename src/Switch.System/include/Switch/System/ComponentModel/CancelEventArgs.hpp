/// @file
/// @brief Contains Switch::System::ComponentModel::CancelEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @vrief Provides data for a cancelable event.
      /// @par Library
      /// Switch.System
      /// @remarks A cancelable event is raised by a component when it is about to perform an action that can be canceled, such as the Closing event of a Form.
      /// @note The Closing event is deprecated and has been replaced by FormClosing. It is offered as an example here only to illustrate the usage of CancelEventArgs.
      /// @remarks CancelEventArgs provides the Cancel property to indicate whether the event should be canceled.
      /// @par Examples
      /// The following example uses CancelEventArgs and a CancelEventHandler to handle the Closing event of a Form. This code assumes that you have created a Form with a class-level Boolean variable named isDataSaved. It also assumes that you have added a statement to invoke the OtherInitialize method from the form's Load method or the constructor (after the call to InitializeComponent).
      /// @code
      /// // Call this method from the constructor of your form
      /// void OtherInitialize() {
      ///   this.Closing += CancelEventHandler(*this, &Form1::Form1_Closing);
      ///   // Exchange commented line and note the difference.
      ///   this-->isDataSaved = true;
      ///   //this->isDataSaved = false;
      /// }
      ///
      /// void Form1_Closing(const Object& sender, CancelEventArgs& e) {
      ///   if (!isDataSaved) {
      ///     e.Cancel = true;
      ///     MessageBox::Show("You must save first.");
      ///   } else {
      ///     e.Cancel = false;
      ///     MessageBox::Show("Goodbye.");
      ///   }
      /// }
      /// @endcode
      class system_export_ CancelEventArgs : public EventArgs {
      public:
        /// @brief Initializes a new instance of the CancelEventArgs class with the Cancel property set to false.
        CancelEventArgs() = default;
        
        /// @brief Initializes a new instance of the CancelEventArgs class with the Cancel property set to the given value.
        /// @param cancel true to cancel the event; otherwise, false.
        explicit CancelEventArgs(bool cancel) : cancel(cancel) {}
        
        /// @cond
        CancelEventArgs(const CancelEventArgs& ce) : cancel(ce.cancel) {}
        CancelEventArgs& operator=(const CancelEventArgs&) = default;
        /// @endcond

        /// @brief Gets or sets a value indicating whether the event should be canceled.
        /// @return bool true if the event should be canceled; otherwise, false.
        property_<bool> Cancel {
          get_ {return cancel;},
          set_ {this->cancel = value;}
        };

      private:
        bool cancel = false;
      };
    }
  }
}
