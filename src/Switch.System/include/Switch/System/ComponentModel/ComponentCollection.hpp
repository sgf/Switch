/// @file
/// @brief Contains Switch::System::ComponentModel::ComponentCollection class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/RefPtr.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/Collections/ArrayList.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @cond
      class IComponent;
      /// @endcond

      /// @brief Provides a read-only container for a collection of IComponent objects.
      /// @par Library
      /// Switch.System
      class system_export_ ComponentCollection : public object {
      public:
        /// @brief Initializes a new instance of the ComponentCollection class using the specified array of components.
        /// @param components An array of IComponent objects to initialize the collection with.
        /// @remarks This method adds each IComponent in the specified IComponent array to the collection.
        ComponentCollection(const Array<Any>& components) {
          for (auto component : components)
            this->components.Add(component);
        }

        int32 Count() const { return this->components.Count(); }

        const System::Collections::ArrayList& GetInnerList() const { return this->components; }

        Any operator [](int32 index) const { return this->components[index]; }

        Any operator [](int32 index) { return this->components[index]; }

        Any operator [](string name) {
          /*
          for($<Object> component : components) {
            if (component.As<IComponent>().GetSite().Name() == name)
              return component.ChangeType<IComponent>();
          }
           */
          return "";
        }

      private:
        System::Collections::ArrayList components;
      };
    }
  }
}
