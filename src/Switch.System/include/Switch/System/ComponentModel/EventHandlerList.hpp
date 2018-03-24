/// @file
/// @brief Contains Switch::System::ComponentModel::Component class.
#pragma once

#include <Switch/System/Delegate.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @brief Provides a simple list of delegates. This class cannot be inherited.
      /// @par Library
      /// Switch.System
      template<typename Result, typename... Arguments>
      class system_export_ EventHandlerList final : public object {
      public:
        /// @brief Initializes a new instance of the EventHandlerList class.
        EventHandlerList() {}

        /// @cond
        EventHandlerList(const EventHandlerList& eventHandlerList) = default;
        /// @endcond

        delegate<Result, Arguments...> operator[](ref<object>) {}

      private:
        struct Item {
          ref<object> key;
          delegate<Result, Arguments...> handler;
          $<Item> next;
        };

        $<Item> head;
      };
    }
  }
}
