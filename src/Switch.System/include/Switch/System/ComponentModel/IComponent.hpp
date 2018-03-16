/// @file
/// @brief Contains Switch::System::ComponentModel::IComponent interface.
#pragma once

#include <Switch/Interface.hpp>
#include <Switch/System/EventHandler.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @interface IComponent
      /// @brief Provides the base implementation for the IComponent interface and enables object sharing between applications.
      /// @par Library
      /// Switch.System
      class system_export_ IComponent interface_ {
      public:
        /// @brief Performs application-defined tasks associated with freeing, releasing, or resetting resources.
        virtual void Close() = 0;

        /// @brief Represents the method that handles the Closed event of a component.
        /// @remarks When you create a Closed delegate, you identify the method that handles the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate.
        System::EventHandler Closed;
      };
    }
  }
}
