/// @file
/// @brief Contains Switch::System::Windows::Forms::DockStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies the position and manner in which a control is docked.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks When a control is docked to an edge of its container, it is always positioned flush against that edge when the container is resized. If more than one control is docked to an edge, the controls appear side by side according to their z-order; controls higher in the z-order are positioned farther from the container's edge.
        /// @remarks If Left, Right, Top, or Bottom is selected, the specified and opposite edges of the control are resized to the size of the containing control's corresponding edges. If Fill is selected, all four sides of the control are resized to match the containing control's edges.
        /// @par Examples
        /// The following example creates a GroupBox and sets some of its common properties. The example creates a TextBox and sets its Location within the group box. Next, it sets the Text property of the group box, and docks the group box to the top of the form. Lastly, it disables the group box by setting the Enabled property to false, which causes all controls contained within the group box to be disabled.
        /// @code
        /// GroupBox groupBox1;
        /// TextBox textBox1;
        ///
        /// // Add a GroupBox to a form and set some of its common properties.
        /// void AddMyGroupBox() {
        ///   // Create a GroupBox and add a TextBox to it.
        ///   textBox1.Location = Point(15, 15);
        ///   groupBox1.Controls().Add(textBox1);
        ///
        ///   // Set the Text and Dock properties of the GroupBox.
        ///   groupBox1.Text = "MyGroupBox";
        ///   groupBox1.Dock = DockStyle::Top;
        ///
        ///   // Disable the GroupBox (which disables all its child controls)
        ///   groupBox1.Enabled = false;
        ///
        ///   // Add the Groupbox to the form.
        ///   this.Controls().Add(groupBox1);
        /// }
        /// @endcode
        enum class DockStyle {
          /// @brief The control is not docked.
          None = 0,
          /// @brief The control's top edge is docked to the top of its containing control.
          Top,
          /// @brief The control's bottom edge is docked to the bottom of its containing control.
          Bottom,
          /// @brief The control's left edge is docked to the left edge of its containing control.
          Left,
          /// @brief The control's right edge is docked to the right edge of its containing control.
          Right,
          /// @brief The control's bottom edge is docked to the bottom of its containing control.
          Fill
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::DockStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::DockStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::DockStyle::None] = "None";
    values[System::Windows::Forms::DockStyle::None] = "None";
    values[System::Windows::Forms::DockStyle::Top] = "Top";
    values[System::Windows::Forms::DockStyle::Bottom] = "Bottom";
    values[System::Windows::Forms::DockStyle::Left] = "Left";
    values[System::Windows::Forms::DockStyle::Right] = "Right";
    values[System::Windows::Forms::DockStyle::Fill] = "Fill";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
