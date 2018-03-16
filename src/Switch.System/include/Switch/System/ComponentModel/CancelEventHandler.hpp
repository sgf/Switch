/// @file
/// @brief Contains Switch::System::ComponentModel::CancelEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>
#include "CancelEventArgs.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @brief Represents the method that handles a cancelable event.
      /// @par Library
      /// Switch.System
      /// @param sender The source of the event.
      /// @param e A CancelEventArgs that contains the event data.
      /// @remarks When you create a CancelEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event-handler method is called whenever the event occurs, unless you remove the delegate. For more information about event-handler delegates, see NIB: Events and Delegates.
      /// @par Example
      /// For an example of how to use the CancelEventHandler delegate, please see the sample code in the CancelEventArgs class.
      using CancelEventHandler = GenericEventHandler<CancelEventArgs&>;
    }
  }
}
