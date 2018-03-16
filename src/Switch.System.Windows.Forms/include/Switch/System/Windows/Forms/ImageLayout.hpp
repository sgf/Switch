/// @file
/// @brief Contains Switch::System::Windows::Forms::ImageLayout enum.
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
        /// @brief Specifies the position of the image on the control.
        /// @par Library
        /// Switch.System.Windows.Forms
        enum class ImageLayout {
          /// @brief The image is left-aligned at the top across the control's client rectangle.
          None = 0,
          /// @brief The image is tiled across the control's client rectangle.
          Tile = 1,
          /// @brief The image is centered within the control's client rectangle.
          Center = 2,
          /// @brief The image is streched across the control's client rectangle.
          Stretch = 3,
          /// @brief The image is enlarged within the control's client rectangle.
          Zoom = 4
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::ImageLayout> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::ImageLayout, string>& values, bool& flags) {
    values[System::Windows::Forms::ImageLayout::None] = "None";
    values[System::Windows::Forms::ImageLayout::Tile] = "Tile";
    values[System::Windows::Forms::ImageLayout::Center] = "Center";
    values[System::Windows::Forms::ImageLayout::Stretch] = "Stretch";
    values[System::Windows::Forms::ImageLayout::Zoom] = "Zoom";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
