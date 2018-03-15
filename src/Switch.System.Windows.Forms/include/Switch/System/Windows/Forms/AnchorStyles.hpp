/// @file
/// @brief Contains Switch::System::Windows::Forms::AnchorStyles enum.
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
        /// @brief Specifies how a control anchors to the edges of its container.
        /// @remarks This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
        /// @remarks When a control is anchored to an edge of its container, the distance between the control and the specified edge remains constant when the container resizes. For example, if a control is anchored to the right edge of its container, the distance between the right edge of the control and the right edge of the container remains constant when the container resizes. A control can be anchored to any combination of control edges. If the control is anchored to opposite edges of its container (for example, to the top and bottom), it resizes when the container resizes. If a control has its Anchor property set to AnchorStyles.None, the control moves half of the distance that the container of the control is resized. For example, if a Button has its Anchor property set to AnchorStyles.None and the Form that the control is located on is resized by 20 pixels in either direction, the button will be moved 10 pixels in both directions.
        /// @par Examples
        /// The following example adds a Button to a form and sets some of its common properties. The example anchors the button to the bottom-right corner of the form so it keeps its relative position as the form is resized. Next it sets the BackgroundImage and resizes the button to the same size as the Image. The example then sets the TabStop to true and sets the TabIndex property. Lastly, it adds an event handler to handle the Click event of the button. This example assumes you have an ImageList named imageList1.
        /// @code
        /// $<Button> button1;
        ///
        /// // Add a button to a form and set some of its common properties.
        /// void AddMyButton() {
        ///   // Create a button and add it to the form.
        ///   this->button1 = new_<Button>();
        ///
        ///   // Anchor the button to the bottom right corner of the form
        ///   this->button1->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
        ///
        ///   // Assign a background image.
        ///   this->button1->BackgroundImage = this->imageList1->Images()[0];
        ///
        ///   // Specify the layout style of the background image. Tile is the default.
        ///   this->button1->BackgroundImageLayout = ImageLayout::Center;
        ///
        ///   // Make the button the same size as the image.
        ///   this->button1->Size = this->button1->BackgroundImage().Size;
        ///
        ///   // Set the button's TabIndex and TabStop properties.
        ///   this->button1->TabIndex = 1;
        ///   this->button1->TabStop = true;
        ///
        ///   // Add a delegate to handle the Click event.
        ///   this->button1->Click += System::EventHandler(*this, &Form1::button1_Click);
        ///
        ///   // Add the button to the form.
        ///   this->Controls().Add(*this->button1);
        /// }
        /// @endcode
        enum class AnchorStyles {
          /// @brief The control is not anchored to any edges of its container.
          None = 0,
          /// @brief The control is anchored to the top edge of its container.
          Top = 0b1,
          /// @brief The control is anchored to the bottom edge of its container.
          Bottom = 0b10,
          /// @brief The control is anchored to the left edge of its container.
          Left = 0b100,
          /// @brief The control is anchored to the right edge of its container.
          Right = 0b1000,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::AnchorStyles> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::AnchorStyles> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AnchorStyles, string>& values, bool& flags) {
    values[System::Windows::Forms::AnchorStyles::None] = "None";
    values[System::Windows::Forms::AnchorStyles::Top] = "Top";
    values[System::Windows::Forms::AnchorStyles::Bottom] = "Bottom";
    values[System::Windows::Forms::AnchorStyles::Left] = "Left";
    values[System::Windows::Forms::AnchorStyles::Right] = "Right";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
