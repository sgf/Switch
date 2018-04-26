/// @file
/// @brief Contains Switch::System::ComponentModel::CancelEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Exception.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// SystemException addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Provides data for the ThreadException event.
      /// @par Library
      /// Switch.System
      /// @remarks A ThreadExceptionEventArgs is created by a thread when an unhandled exception occurs. ThreadExceptionEventArgs contains the Exception that occurred.
      class system_export_ ThreadExceptionEventArgs : public EventArgs {
      public:
        /// @brief Initializes a new instance of the ThreadExceptionEventArgs class.
        ThreadExceptionEventArgs() = default;

        /// @brief Initializes a new instance of the ThreadExceptionEventArgs class.
        /// @param exception The Exception that occurred.
        explicit ThreadExceptionEventArgs(const Exception& exception) : exception(exception) {}

        /// @cond
        ThreadExceptionEventArgs(const ThreadExceptionEventArgs& tee) : exception(tee.exception) {}
        ThreadExceptionEventArgs& operator=(const ThreadExceptionEventArgs&) = default;
        /// @endcond

        /// @brief Gets the Exception that occurred.
        /// @return The Exception that occurred.
        property_<const System::Exception&, readonly_> Exception {
          get_->const System::Exception& {return exception.ToObject();},
        };

      private:
        ref<System::Exception> exception;
      };
    }
  }
}
