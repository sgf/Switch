/// @file
/// @brief Contains Switch::System::ComponentModel::Component class.
#pragma once

#include <Switch/System/Object.hpp>
#include "../../SystemExport.hpp"
#include "IComponent.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @brief Provides the base implementation for the IComponent interface and enables object sharing between applications.
      /// @par Library
      /// Switch.System
      class system_export_ Component : public object, public IComponent {
      public:
        /// @brief Initializes a new instance of the Component class.
        Component() {}

        /// @cond
        Component(const Component& component) {}
        Component& operator=(const Component&) = default;
        /// @endcond

      protected:
        /// @brief Determines if events can be raised on the control.
        /// @return true if the control is hosted as an ActiveX control whose events are not frozen; otherwise, false.
        /// @remarks If this control is being hosted as an ActiveX control, this property will return false if the ActiveX control has its events frozen.
        property_<bool, readonly_> CanRaiseEvents {
          get_ {return this->GetCanRaiseEvents();}
        };

        /// @brief Determines if events can be raised on the control.
        /// @return true if the control is hosted as an ActiveX control whose events are not frozen; otherwise, false.
        /// @remarks If this control is being hosted as an ActiveX control, this property will return false if the ActiveX control has its events frozen.
        virtual bool GetCanRaiseEvents() const {return this->canRaiseEvents;}

        /// @brief Performs application-defined tasks associated with freeing, releasing, or resetting resources.
        virtual void Close() {}

        /// @cond
        bool canRaiseEvents = true;
        /// @endcond
      };
    }
  }
}
