/// @file
/// @brief Contains Switch::System::ComponentModel::IContainer interface.
#pragma once

#include <Switch/Interface.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @interface IContainer
      /// @brief Provides functionality for containers. Containers are objects that logically contain zero or more components.
      /// @par Library
      /// Switch.System
      class system_export_ IContainer interface_ {
      public:
      };
    }
  }
}
