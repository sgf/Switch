/// @file
/// @brief Contains Switch::System::Windows::Forms::AccessibleEvents enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies events that are reported by accessible applications.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The operating system and accessibility server applications generate accessibility events in response to changes in the user interface.
        /// @remarks This enumeration is used by AccessibleObject and Control.
        /// @par Examples
        /// The following code example demonstrates the creation of an accessibility-aware chart control, using the AccessibleObject and Control.ControlAccessibleObject classes to expose accessible information. The control plots two curves along with a legend. The ChartControlAccessibleObject class, which derives from ControlAccessibleObject, is used in the CreateAccessibilityInstance method to provide custom accessible information for the chart control. Because the chart legend is not an actual Control -based control, but instead is drawn by the chart control, it does not any built-in accessible information. Because of this, the ChartControlAccessibleObject class overrides the GetChild method to return the CurveLegendAccessibleObject that represents accessible information for each part of the legend. When an accessible-aware application uses this control, the control can provide the necessary accessible information.<br><br>
        /// This example demonstrates using the AccessibleEvents enumeration with the AccessibilityNotifyClients method. See the AccessibleObject class overview for the complete code example.
        /// @code
        /// // Gets or sets the location for the curve legend.
        /// property_<Point> Location {
        ///   get_ {return this->location;},
        ///   set_ {
        ///     this->location = value;
        ///     this->chart.Invalidate();
        ///
        ///     // Notifies the chart of the location change. This is used for
        ///     // the accessibility information. AccessibleEvents.LocationChange
        ///     // tells the chart the reason for the notification.
        ///     this->chart.AccessibilityNotifyClients(this->AccessibleEvents().LocationChange, as<CurveLegendAccessibleObject>(this->AccessibilityObject).ID);
        ///   }
        /// }
        ///
        /// // Gets or sets the Name for the curve legend.
        /// property_<string> Name {
        ///   get_ {return this->name;},
        ///   set_ {
        ///     if (this->name != value) {
        ///       this->name = value;
        ///       this->chart.Invalidate();
        ///
        ///       // Notifies the chart of the name change. This is used for
        ///       // the accessibility information. AccessibleEvents.NameChange
        ///       // tells the chart the reason for the notification.
        ///       this->chart.AccessibilityNotifyClients(this->AccessibleEvents().NameChange, as<CurveLegendAccessibleObject>(this->AccessibilityObject).ID);
        ///     }
        ///   }
        /// }
        ///
        /// // Gets or sets the Selected state for the curve legend.
        /// property_<bool> Selected {
        ///   get_ {return this->selected;},
        ///   set_ {
        ///     if (this->selected != value) {
        ///       this->selected = value;
        ///       this->chart.Invalidate();
        ///
        ///       // Notifies the chart of the selection value change. This is used for
        ///       // the accessibility information. The AccessibleEvents value depends upon
        ///       // if the selection is true (AccessibleEvents.SelectionAdd) or
        ///       // false (AccessibleEvents.SelectionRemove).
        ///       this->chart.AccessibilityNotifyClients(this->selected ? this->AccessibleEvents().SelectionAdd : this->AccessibleEvents().SelectionRemove, as<CurveLegendAccessibleObject>(AccessibilityObject).ID);
        ///     }
        ///   }
        /// }
        /// @endcode
        enum class AccessibleEvents {
          /// @brief A sound was played. The system sends this event when a system sound, such as for menus, is played, even if no sound is audible. This might be caused by lack of a sound file or sound card. Servers send this event if a custom user interface element generates a sound.
          SystemSound = 1,
          /// @brief An alert was generated. Server applications send this event whenever an important user interface change has occurred that a user might need to know about. The system does not send the event consistently for dialog box objects.
          SystemAlert = 2,
          /// @brief The foreground window changed. The system sends this event even if the foreground window is changed to another window in the same thread. Server applications never send this event.
          SystemForeground = 3,
          /// @brief A menu item on the menu bar was selected. The system sends this event for standard menus. Servers send this event for custom menus. The system might raise more than one MenuStart event that might or might not have a corresponding MenuEnd event.
          SystemMenuStart = 4,
          /// @brief A menu from the menu bar was closed. The system sends this event for standard menus. Servers send this event for custom menus.
          SystemMenuEnd = 5,
          /// @brief A shortcut menu was displayed. The system sends this event for standard menus. Servers send this event for custom menus. The system does not send the event consistently.
          SystemMenuPopupStart = 6,
          /// @brief A shortcut menu was closed. The system sends this event for standard menus. Servers send this event for custom menus. When a shortcut menu is closed, the client receives this message followed almost immediately by the SystemMenuEnd event. The system does not send the event consistently.
          SystemMenuPopupEnd = 7,
          /// @brief A window is being moved or resized. The system sends the event; servers never send this event.
          SystemCaptureStart = 8,
          /// @brief A window has lost mouse capture. The system sends the event; servers never send this event.
          SystemCaptureEnd = 9,
          /// @brief A window is being moved or resized. The system sends the event; servers never send this event.
          SystemMoveSizeStart = 10,
          /// @biref The movement or resizing of a window is finished. The system sends the event; servers never send this event.
          SystemMoveSizeEnd = 11,
          /// @brief A window entered context-sensitive Help mode. The system does not send the event consistently.
          SystemContextHelpStart = 12,
          /// @brief A window exited context-sensitive Help mode. The system does not send the event consistently.
          SystemContextHelpEnd = 13,
          /// @brief An application is about to enter drag-and-drop mode. Applications that support drag-and-drop operations must send this event; the system does not.
          SystemDragDropStart = 14,
          /// @brief An application is about to exit drag-and-drop mode. Applications that support drag-and-drop operations must send this event; the system does not.
          SystemDragDropEnd = 15,
          /// @brief A dialog box was displayed. The system sends the event for standard dialog boxes. Servers send this event for custom dialog boxes. The system does not send the event consistently.
          SystemDialogStart = 16,
          /// @brief A dialog box was closed. The system does not send the event for standard dialog boxes. Servers send this event for custom dialog boxes. The system does not send the event consistently.
          SystemDialogEnd = 17,
          /// @brief Scrolling has started on a scroll bar. The system sends the event for scroll bars attached to a window and for standard scroll bar controls. Servers send this event for custom scroll bars.
          SystemScrollingStart = 18,
          /// @brief Scrolling has ended on a scroll bar. The system sends this event for scroll bars attached to a window and for standard scroll bar controls. Servers send this event for custom scroll bars.
          SystemScrollingEnd = 19,
          /// @brief The user pressed ALT+TAB, which activates the switch window. If only one application is running when the user presses ALT+TAB, the system raises the SwitchEnd event without a corresponding SwitchStart event.
          SystemSwitchStart = 20,
          /// @brief The user released ALT+TAB. The system sends the SwitchEnd event; servers never send this event. If only one application is running when the user presses ALT+TAB, the system sends the SwitchEnd event without a corresponding SwitchStart event.
          SystemSwitchEnd = 21,
          /// @brief A window object is about to be minimized or maximized. The system sends the event; servers never send this event.
          SystemMinimizeStart = 22,
          /// @brief A window object was minimized or maximized. The system sends the event; servers never send this event.
          SystemMinimizeEnd = 23,
          /// @brief An object was created. The operating system sends the event for the following user interface elements: caret, header control, list view control, tab control, toolbar control, tree view control, and window object. Server applications send this event for their accessible objects. Servers must send this event for all an object's child objects before sending the event for the parent object. Servers must ensure that all child objects are fully created and ready to accept calls from clients when the parent object sends the event.
          Create = 32768,
          /// @brief An object was destroyed. The system sends this event for the following user interface elements: caret, header control, list view control, tab control, toolbar control, tree view control, and window object. Server applications send this event for their accessible objects. This event may or may not be sent for child objects. However, clients can conclude that all the children of an object have been destroyed when the parent object sends this event.
          Destroy = 32769,
          /// @brief A hidden object is being shown. The system sends this event for the following user interface elements: caret, cursor, and window object. Server applications send this event for their accessible objects. Clients can conclude that, when this event is sent by a parent object, all child objects have already been displayed. Therefore, server applications do not need to send this event for the child objects.
          Show = 32770,
          /// @brief An object is hidden. The system sends the event for the following user interface elements: caret and cursor. Server applications send the event for their accessible objects. When the event is generated for a parent object, all child objects have already been hidden. Therefore, server applications do not need to send the event for the child objects. The system does not send the event consistently.
          Hide = 32771,
          /// @brief A container object has added, removed, or reordered its children. The system sends this event for the following user interface elements: header control, list view control, toolbar control, and window object. Server applications send this event as appropriate for their accessible objects. This event is also sent by a parent window when the z order for the child windows changes.
          Reorder = 32772,
          /// @brief An object has received the keyboard focus. The system sends this event for the following user interface elements: list view control, menu bar, shortcut menu, switch window, tab control, tree view control, and window object. Server applications send this event for their accessible objects.
          Focus = 32773,
          /// @brief An accessible object within a container object has been selected. This event signals a single selection. Either a child has been selected in a container that previously did not contain any selected children, or the selection has changed from one child to another.
          Selection = 32774,
          /// @brief An item within a container object was added to the selection. The system sends this event for the following user interface elements: list box, list view control, and tree view control. Server applications send this event for their accessible objects. This event signals that a child has been added to an existing selection.
          SelectionAdd = 32775,
          /// @brief An item within a container object was removed from the selection. The system sends this event for the following user interface elements: list box, list view control, and tree view control. Server applications send this event for their accessible objects. This event signals that a child has been removed from an existing selection.
          SelectionRemove = 32776,
          /// @brief Numerous selection changes occurred within a container object. The system sends this event for list boxes. Server applications send this event for their accessible objects. This event can be sent when the selected items within a control have changed substantially. This event informs the client that many selection changes have occurred. This is preferable to sending several SelectionAdd or SelectionRemove events.
          SelectionWithin = 32777,
          /// @brief An object's state has changed. The system sends the event for the following user interface elements: check box, combo box, header control, push button, radio button, scroll bar, toolbar control, tree view control, up-down control, and window object. Server applications send the event for their accessible objects. For example, a state change can occur when a button object has been pressed or released, or when an object is being enabled or disabled. The system does not send the event consistently.
          StateChange = 32778,
          /// @brief An object has changed location, shape, or size. The system sends this event for the following user interface elements: caret and window object. Server applications send this event for their accessible objects. This event is generated in response to the top-level object within the object hierarchy that has changed, not for any children it might contain. For example, if the user resizes a window, the system sends this notification for the window, but not for the menu bar, title bar, scroll bars, or other objects that have also changed. The system does not send this event for every non-floating child window when the parent moves. However, if an application explicitly resizes child windows as a result of being resized, the system sends multiple events for the resized children. If an object's State property is set to AccessibleStates.Floating, servers should send a location change event whenever the object changes location. If an object does not have this state, servers should raise this event when the object moves relative to its parent.
          LocationChange = 32779,
          /// @brief An object's Name property changed. The system sends this event for the following user interface elements: check box, cursor, list view control, push button, radio button, status bar control, tree view control, and window object. Server applications send this event for their accessible objects.
          NameChange = 32780,
          /// @brief An object's Description property changed. Server applications send this event for their accessible objects.
          DescriptionChange = 32781,
          /// @brief An object's Value property changed. The system raises the ValueChange event for the following user interface elements: edit control, header control, hot key control, progress bar control, scroll bar, slider control, and up-down control. Server applications send this event for their accessible objects.
          ValueChange = 32782,
          /// @brief An object has a new parent object. Server applications send this event for their accessible objects.
          ParentChange = 32783,
          /// @brief An object's Help property changed. Server applications send this event for their accessible objects.
          HelpChange = 32784,
          /// @brief An object's DefaultAction property changed. The system sends this event for dialog boxes. Server applications send this event for their accessible objects. Therefore, server applications do not need to send this event for the child objects. Hidden objects have a state of AccessibleStates.Invisible, and shown objects do not. Events of type AccessibleEvents.Hide indicate that a state of AccessibleStates.Invisible has been set. Therefore, servers do not need to send the AccessibleEvents.StateChange event in this case.
          DefaultActionChange = 32785,
          /// @brief An object's KeyboardShortcut property changed. Server applications send the event for their accessible objects.
          AcceleratorChange = 32786,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::AccessibleEvents> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AccessibleEvents, string>& values, bool& flags) {
    values[System::Windows::Forms::AccessibleEvents::SystemSound] = "SystemSound";
    values[System::Windows::Forms::AccessibleEvents::SystemAlert] = "SystemAlert";
    values[System::Windows::Forms::AccessibleEvents::SystemForeground] = "SystemForeground";
    values[System::Windows::Forms::AccessibleEvents::SystemMenuStart] = "SystemMenuStart";
    values[System::Windows::Forms::AccessibleEvents::SystemMenuEnd] = "SystemMenuEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemMenuPopupStart] = "SystemMenuPopupStart";
    values[System::Windows::Forms::AccessibleEvents::SystemMenuPopupEnd] = "SystemMenuPopupEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemCaptureStart] = "SystemCaptureStart";
    values[System::Windows::Forms::AccessibleEvents::SystemCaptureEnd] = "SystemCaptureEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemMoveSizeStart] = "SystemMoveSizeStart";
    values[System::Windows::Forms::AccessibleEvents::SystemMoveSizeEnd] = "SystemMoveSizeEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemContextHelpStart] = "SystemContextHelpStart";
    values[System::Windows::Forms::AccessibleEvents::SystemContextHelpEnd] = "SystemContextHelpEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemDragDropStart] = "SystemDragDropStart";
    values[System::Windows::Forms::AccessibleEvents::SystemDragDropEnd] = "SystemDragDropEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemDialogStart] = "SystemDialogStart";
    values[System::Windows::Forms::AccessibleEvents::SystemDialogEnd] = "SystemDialogEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemScrollingStart] = "SystemScrollingStart";
    values[System::Windows::Forms::AccessibleEvents::SystemScrollingEnd] = "SystemScrollingEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemSwitchStart] = "SystemSwitchStart";
    values[System::Windows::Forms::AccessibleEvents::SystemSwitchEnd] = "SystemSwitchEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemMinimizeStart] = "SystemMinimizeStart";
    values[System::Windows::Forms::AccessibleEvents::SystemMinimizeEnd] = "SystemMinimizeEnd";
    values[System::Windows::Forms::AccessibleEvents::Create] = "Create";
    values[System::Windows::Forms::AccessibleEvents::Destroy] = "Destroy";
    values[System::Windows::Forms::AccessibleEvents::Show] = "Show";
    values[System::Windows::Forms::AccessibleEvents::Hide] = "Hide";
    values[System::Windows::Forms::AccessibleEvents::Reorder] = "Reorder";
    values[System::Windows::Forms::AccessibleEvents::Focus] = "Focus";
    values[System::Windows::Forms::AccessibleEvents::Selection] = "Selection";
    values[System::Windows::Forms::AccessibleEvents::SelectionAdd] = "SelectionAdd";
    values[System::Windows::Forms::AccessibleEvents::SelectionRemove] = "SelectionRemove";
    values[System::Windows::Forms::AccessibleEvents::SelectionWithin] = "SelectionWithin";
    values[System::Windows::Forms::AccessibleEvents::StateChange] = "StateChange";
    values[System::Windows::Forms::AccessibleEvents::LocationChange] = "LocationChange";
    values[System::Windows::Forms::AccessibleEvents::NameChange] = "NameChange";
    values[System::Windows::Forms::AccessibleEvents::DescriptionChange] = "DescriptionChange";
    values[System::Windows::Forms::AccessibleEvents::ValueChange] = "ValueChange";
    values[System::Windows::Forms::AccessibleEvents::ParentChange] = "ParentChange";
    values[System::Windows::Forms::AccessibleEvents::HelpChange] = "HelpChange";
    values[System::Windows::Forms::AccessibleEvents::DefaultActionChange] = "DefaultActionChange";
    values[System::Windows::Forms::AccessibleEvents::AcceleratorChange] = "AcceleratorChange";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
