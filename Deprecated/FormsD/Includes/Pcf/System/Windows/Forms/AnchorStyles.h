/// @file
/// @brief Contains Pcf::System::Windows::Forms::AnchorStyles enum.
#pragma once

#include <Pcf/System/Enum.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        /// @brief Specifies how a control anchors to the edges of its container.
        /// @remarks When a control is anchored to an edge of its container, the distance between the control and the specified edge remains constant when the container resizes. For example, if a control is anchored to the right edge of its container, the distance between the right edge of the control and the right edge of the container remains constant when the container resizes. A control can be anchored to any combination of control edges. If the control is anchored to opposite edges of its container (for example, to the top and bottom), it resizes when the container resizes. If a control has its Anchor property set to AnchorStyles.None, the control moves half of the distance that the container of the control is resized. For example, if a Button has its Anchor property set to AnchorStyles.None and the Form that the control is located on is resized by 20 pixels in either direction, the button will be moved 10 pixels in both directions.
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
class AddFlagOperators<System::Windows::FormsD::AnchorStyles> : public TrueType {};

template<>
class EnumToStrings<System::Windows::FormsD::AnchorStyles> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::FormsD::AnchorStyles::None, "None"}, {(int64)System::Windows::FormsD::AnchorStyles::Top, "Top"}, {(int64)System::Windows::FormsD::AnchorStyles::Bottom, "Bottom"}, {(int64)System::Windows::FormsD::AnchorStyles::Left, "Left"}, {(int64)System::Windows::FormsD::AnchorStyles::Right, "Right"}};
    flags = true;
  }
};
/// @endcond

using namespace Pcf;
