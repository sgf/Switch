/// @file
/// @brief Contains Switch::System::Windows::Forms::MethodInvoker delegate.
#pragma once

#include <Switch/System/Delegate.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a delegate that can execute any method in managed code that is declared void and takes no parameters.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks MethodInvoker provides a simple delegate that is used to invoke a method with a void parameter list. This delegate can be used when making calls to a control's Invoke method, or when you need a simple delegate but do not want to define one yourself.
        using MethodInvoker = Delegate<void>;
      }
    }
  }
}
