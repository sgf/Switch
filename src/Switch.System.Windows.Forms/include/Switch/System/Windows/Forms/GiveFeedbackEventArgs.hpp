/// @file
/// @brief Contains Switch::System::Windows::Forms::GiveFeedbackEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "DragDropEffects.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Provides data for the GiveFeedback event, which occurs during a drag operation.
        /// @par Library
        /// Switch.System.Windows.Forms
        class system_windows_forms_export_ GiveFeedbackEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the GiveFeedbackEventArgs class.
          GiveFeedbackEventArgs() : useDefaultCursors(true) {}
          /// @brief Initializes a new instance of the GiveFeedbackEventArgs class.
          /// @param effects The type of drag-and-drop operation. Possible values are obtained by applying the bitwise OR (|) operation to the constants defined in the DragDropEffects.
          /// @param true if default pointers are used; otherwise, false.
          GiveFeedbackEventArgs(DragDropEffects effect, bool useDefaultCursors) : effect(effect), useDefaultCursors(useDefaultCursors) {}

          /// @brief Gets the drag-and-drop operation feedback that is displayed.
          /// @return One of the DragDropEffects values.
          DragDropEffects Effect() const { return this->effect; }

          /// @brief Gets whether drag operation should use the default cursors that are associated with drag-drop effects.
          /// @return true if the default pointers are used; otherwise, false.
          bool UseDefaultCursors() const { return this->useDefaultCursors; }

          /// @brief Sets whether drag operation should use the default cursors that are associated with drag-drop effects.
          /// @param useDefaultCursors true if the default pointers are used; otherwise, false.
          void UseDefaultCursors(bool useDefaultCursors) { this->useDefaultCursors = useDefaultCursors; }

        private:
          DragDropEffects effect;
          bool useDefaultCursors;
        };
      }
    }
  }
}
