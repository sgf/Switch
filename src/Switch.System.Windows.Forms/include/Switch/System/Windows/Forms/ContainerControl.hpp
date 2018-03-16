/// @file
/// @brief Contains Switch::System::Windows::Forms::ContainerControl class.
#pragma once

#include <Switch/System/ComponentModel/Component.hpp>
#include <Switch/System/ComponentModel/IContainer.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "ScrollableControl.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Provides focus-management functionality for controls that can function as a container for other controls.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks A ContainerControl represents a control that can function as a container for other controls and provides focus management. Controls that inherit from this class can track the active control they contain, even when the focus moves somewhere within a different container.
        /// @remarks ContainerControl objects provide a logical boundary for contained controls. The container control can capture the TAB key press and move focus to the next control in the collection.
        /// @note The container control does not receive focus; the focus is always set to the first child control in the collection of contained controls.
        /// @remarks You do not typically inherit directly from the ContainerControl class. Form, UserControl, and UpDownBase classes inherit from ContainerControl.
        class system_windows_forms_export_ ContainerControl: public ScrollableControl {
        public:
          /// @brief Initializes a new instance of the ContainerControl class.
          /// @par Examples
          /// The following code example inherits from the ScrollableControl class and implements the IContainerControl interface. Implementation is added to the ActiveControl property and the ActivateControl method.
          /// @code
          /// using namespace System;
          /// using namespace System::Windows::Forms;
          /// using namespace System::Drawing;
          ///
          /// class MyContainer : public ScrollableControl, public IContainerControl {
          /// private:
          ///   ref<Control> activeControl;
          ///
          /// public:
          ///   MyContainer() {
          ///     // Make the container control Blue so it can be distinguished on the form.
          ///     this->BackColor = Color::Blue;
          ///
          ///     // Make the container scrollable.
          ///     this->AutoScroll = true;
          ///   }
          ///
          ///   // Add implementation to the IContainerControl.ActiveControl property.
          ///   property_<ref<Control>> ActiveControl {
          ///     get_ {return this->activeControl;},
          ///     set_ {
          ///       // Make sure the control is a member of the ControlCollection.
          ///       if (this->Controls().Contains(value)) {
          ///         activeControl = value;
          ///       }
          ///     }
          ///   }
          ///
          ///   // Add implementations to the IContainerControl.ActivateControl(Control) method.
          ///   bool ActivateControl(ref<Control> active) {
          ///     if(this->Controls().Contains(active)) {
          ///       // Select the control and scroll the control into view if needed.
          ///       active().Select();
          ///       this->ScrollControlIntoView(active());
          ///       this->activeControl = active;
          ///       return true;
          ///     }
          ///     return false;
          ///   }
          /// }
          /// @endcode
          ContainerControl() {}

          /// @brief Initializes a new instance of the ContainerControl class with specific text, size, and location.
          /// @param text The text displayed by the control.
          /// @param left The X position of the control, in pixels, from the left edge of the control's container. The value is assigned to the Left property.
          /// @param top The Y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the Top property.
          /// @param width The height of the control, in pixels. The value is assigned to the Height property.
          /// @param height The width of the control, in pixels. The value is assigned to the Width property.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The initial Size and Location of the control are determined by the left, top, width and height parameter values.
          /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to virtual the DefaultSize property.
          ContainerControl(const string& text, int32 left, int32 top, int32 width, int32 height) : ScrollableControl(text, left, top, width, height) {
          }

          /// @brief Gets the IContainer that contains the Component.
          /// @return Switch::System::ComponentModel::IContainer The IContainer that contains the Component, if any, or null if the Component is not encapsulated in an IContainer.
          /// @remarks The components in a container are tracked in a first-in, first-out list, which also defines the order of the components within the container. The last component added is the last component in the list.
          property_<const System::ComponentModel::IContainer&, readonly_> Container {
            get_->const System::ComponentModel::IContainer& {return this->GetContainer();}
          };

          /// @brief Gets the IContainer that contains the Component.
          /// @return Switch::System::ComponentModel::IContainer The IContainer that contains the Component, if any, or null if the Component is not encapsulated in an IContainer.
          /// @remarks The components in a container are tracked in a first-in, first-out list, which also defines the order of the components within the container. The last component added is the last component in the list.
          virtual const System::ComponentModel::IContainer& GetContainer() const {return ref<NullContainer>::Null();}

        private:
          class NullContainer : public System::ComponentModel::IContainer {};
        };
      }
    }
  }
}
