/// @file
/// @brief Contains Switch::System::Windows::Forms::ButtonBase class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Encapsulates the information needed when creating a control.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The information in a CreateParams can be used to pass information about the initial state and appearance of a control. Most Control derived controls override the CreateParams property to pass in the appropriate values or include additional information in the CreateParams.
        /// @remarks For more information about creating control parameters, see the CreateWindow and CreateWindowEx functions and the CREATESTRUCT structure documentation in the Windows Platform SDK reference located in the MSDN Library.
        /// @note The constants used to set the Style, ExStyle, and ClassStyle properties are defined in the Winuser.h header file. This file is installed by the Platform SDK or Visual Studio.
        class system_windows_forms_export_ CreateParams : public object {
        public:
          /// @brief Initializes a new instance of the ButtonBase class.
          CreateParams() {}

          /// @cond
          CreateParams(const CreateParams& createParams) : caption(createParams.caption), className(createParams.className), classStyle(createParams.classStyle), exStyle(createParams.exStyle), height(createParams.height), param(createParams.param), parent(createParams.parent), style(createParams.style), width(createParams.width), x(createParams.x), y(createParams.y) {}
          CreateParams& operator=(const CreateParams&) = default;
          /// @endcond

          /// @brief Gets or sets the control's initial text.
          /// @return The control's initial text.
          property_<string> Caption {
            get_ {return this->caption;},
            set_ {this->caption = value;}
          };

          /// @brief Gets or sets the name of the Windows class to derive the control from.
          /// @return The name of the Windows class to derive the control from.
          /// @remarks The default value for this property is string::Empty, indicating that the control is not derived from an existing control class. To derive from an existing control class, store the system class name in this property. For example, to derive from the standard Button control, set this property to "BUTTON".
          property_<string> ClassName {
            get_ {return this->className;},
            set_ {this->className = value;}
          };

          /// @brief Gets or sets a bitwise combination of class style values.
          /// @return A bitwise combination of the class style values.
          /// @remarks The ClassStyle property is ignored if the ClassName property is not string::Empty.
          /// @remarks For more information about creating control parameters, see the CreateWindow and CreateWindowEx functions and the CREATESTRUCT structure documentation in the Windows Platform SDK reference located in the MSDN Library.
          /// @note The constants used to set the Style, ExStyle, and ClassStyle properties are defined in the Winuser.h header file. This file is installed by the Platform SDK or Visual Studio.
          property_<int32> ClassStyle {
            get_ {return this->classStyle;},
            set_ {this->classStyle = value;}
          };

          /// @brief Gets or sets a bitwise combination of extended window style values.
          /// @return A bitwise combination of the extended window style values.
          /// @remarks The ExStyle property supports extended appearance and initial state values to apply to the control.
          /// @remarks For more information about creating control parameters, see the CreateWindow and CreateWindowEx functions and the CREATESTRUCT structure documentation in the Windows Platform SDK reference located in the MSDN Library.
          /// @note The constants used to set the Style, ExStyle, and ClassStyle properties are defined in the Winuser.h header file. This file is installed by the Platform SDK or Visual Studio.
          property_<int32> ExStyle {
            get_ {return this->exStyle;},
            set_ {this->exStyle = value;}
          };

          /// @brief Gets or sets the initial height of the control.
          /// @return The numeric value that represents the initial height of the control.
          property_<int32> Height {
            get_ {return this->height;},
            set_ {this->height = value;}
          };

          /// @brief Gets or sets additional parameter information needed to create the control.
          /// @return The Object that holds additional parameter information needed to create the control.
          /// @remarks If you are creating a multiple document interface (MDI) client window, the Param property must reference a CLIENTCREATESTRUCT structure.
          /// @remarks For more information about creating control parameters, see the CreateWindow and CreateWindowEx functions and the CLIENTCREATESTRUCT structure documentation in the Windows Platform SDK reference located in the MSDN Library.
          property_ < $<object >> Param {
            get_ {return this->param;},
            set_ {this->param = value;}
          };

          /// @brief Gets or sets the control's parent.
          /// @return An intptr that contains the window handle of the control's parent.
          property_<intptr> Parent {
            get_ {return this->parent;},
            set_ {this->parent = value;}
          };

          /// @brief Gets or sets a bitwise combination of window style values.
          /// @return A bitwise combination of the window style values.
          /// @remarks The Style property controls the appearance of the control and its initial state.
          /// @remarks For more information about creating control parameters, see the CreateWindow and CreateWindowEx functions and the CREATESTRUCT structure documentation in the Windows Platform SDK reference located in the MSDN Library.
          /// @note The constants used to set the Style, ExStyle, and ClassStyle properties are defined in the Winuser.h header file. This file is installed by the Platform SDK or Visual Studio.
          property_<int32> Style {
            get_ {return this->style;},
            set_ {this->style = value;}
          };

          /// @brief Gets or sets the initial width of the control.
          /// @return The numeric value that represents the initial width of the control.
          property_<int32> Width {
            get_ {return this->width;},
            set_ {this->width = value;}
          };

          /// @brief Gets or sets the initial left position of the control.
          /// @return The numeric value that represents the initial left position of the control.
          property_<int32> X {
            get_ {return this->x;},
            set_ {this->x = value;}
          };

          /// @brief Gets or sets the top position of the initial location of the control.
          /// @return The numeric value that represents the top position of the initial location of the control.
          property_<int32> Y {
            get_ {return this->y;},
            set_ {this->y = value;}
          };

          /// @brief Returns a string that represents the current object.
          /// @return A string that represents the current object.
          string ToString() const override {return string::Format("'{0}', '{1}', 0x{2:X2}, 0x{3:X2}, {{{4}, {5}, {6}, {7}}}", this->Caption, this->ClassName, this->Style, this->ExStyle, this->X, this->Y, this->Width, this->Height);}

        private:
          string caption;
          string className;
          int32 classStyle = 0;
          int32 exStyle = 0;
          int32 height = 0;
          $<object> param;
          intptr parent = IntPtr::Zero;
          int32 style = 0;
          int32 width = 0;
          int32 x = 0;
          int32 y = 0;
        };
      }
    }
  }
}
