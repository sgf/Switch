/// @file
/// @brief Contains Switch::System::ComponentModel::ISite interface.
#pragma once

#include <Switch/Interface.hpp>
#include "../../SystemExport.hpp"

/// @cond
namespace Switch { namespace System { namespace ComponentModel {
  class IComponenent;
}}}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @interface ISite
      /// @brief Provides functionality required by sites.
      /// @par Library
      /// Switch.System.Windows.Forms
      class system_export_ ISite interface_ {
      public:
        /// @brief A valid value for this property (that is, the value is not null) indicates that the component has been added to a container.
        virtual const IComponenent& GetComponent() const = 0;
      };
    }
  }
}
