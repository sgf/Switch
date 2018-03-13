/// @file
/// @brief Contains Switch::System::Windows::Forms::Form class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "ContainerControl.hpp"
#include "BorderStyle.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Used to group collections of controls.
        class system_windows_forms_export_ Panel : public ContainerControl {
        public:
          Panel() : ContainerControl("", 0, 0, 200, 100) {
            this->SetStyle(ControlStyles::UserPaint, false);
          }

          property_<System::Windows::Forms::BorderStyle> BorderStyle {
            get_{return this->borderStyle;},
            set_{this->SetBorderStyle(value);}
          };

        protected:
          Panel(const string& text, int32 left, int32 top, int32 width, int32 height) : ContainerControl(text, left, top, width, height) {
            this->SetStyle(ControlStyles::UserPaint, false);
          }

          /// @brief Creates a handle for the control
          /// @remarks You typically should not call the CreateHandle method directly. The preferred method is to call the CreateControl method, which forces a handle to be created for the control and its child controls when the control is created.
          /// @par Notes to Inheritors
          /// When overriding CreateHandle in a derived class, be sure to call the base class's CreateHandle method to ensure that the handle is created.
          void CreateHandle() override;

          /// @brief Gets the default size of the control.
          /// @return Switch::System::Drawing::Size The default Size of the control.
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(200, 100); }

          virtual void SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle);

          /// @cond
          System::Windows::Forms::BorderStyle borderStyle = System::Windows::Forms::BorderStyle::None;
          /// @endcond
        };
      }
    }
  }
}
