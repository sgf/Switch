/// @file
/// @brief Contains Switch::System::Windows::Forms::HelpEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "HelpEventArgs.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents the method that will handle the HelpRequested event of a Control.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @param sender The object where the event handler is attached.
        /// @param e The event data.
        /// @remarks When you create a HelpEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about handling events with delegates, see Events and Delegates.
        using HelpEventHandler = GenericEventHandler<HelpEventArgs&>;
      }
    }
  }
}
