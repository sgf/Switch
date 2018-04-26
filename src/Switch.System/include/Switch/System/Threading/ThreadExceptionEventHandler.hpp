/// @file
/// @brief Contains Switch::System::ComponentModel::CancelEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>
#include "ThreadExceptionEventArgs.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// SystemException addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Represents the method that will handle the ThreadException event of an Application.
      /// @par Library
      /// Switch.System
      /// @param sender The source of the event.
      /// @param e A ThreadExceptionEventArgs that contains the event data.
      /// @remarks When you create a ThreadExceptionEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about event-handler delegates, see Handling and Raising Events.
      using ThreadExceptionEventHandler = GenericEventHandler<const ThreadExceptionEventArgs&>;
    }
  }
}
