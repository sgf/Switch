/// @file
/// @brief Contains Switch::System::Drawing::Font class.
#pragma once

#include <Switch/Static.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemDrawingExport.hpp"
#include "Font.hpp"
#include "FontFamily.hpp"
#include "FontStyle.hpp"
#include "GraphicsUnit.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Specifies the fonts used to display text in Windows display elements.
      /// @remarks Each property of the SystemFonts class returns a Font used to display text in a particular Windows display element, such as the title bar of a window. These fonts reflect the current settings in Control Panel.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ SystemFonts static_ {
      public:
        /// @brief Gets a Font that is used to display text in the title bars of windows.
        /// @return Font A Font that is used to display text in the title bars of windows.
        static property_<Font, readonly_> CaptionFont;

        /// @brief Gets the default font that applications can use for dialog boxes and forms.
        /// @return Font The default Font of the system. The value returned will vary depending on the user's operating system and the local culture setting of their system.
        /// @remarks The following table describes the value returned by the DefaultFont property depending on the operating system and local culture.
        /// | System and/or culture           | Font                                                               |
        /// |---------------------------------|--------------------------------------------------------------------|
        /// | Windows NT 4x, Japanese version | MS UI Gothic, 9 point                                              |
        /// | Arabic Windows                  | Tahoma, 8 point                                                    |
        /// | Other operating system/culture  | MS Shell Dlg logical font, typically Microsoft Sans Serif, 8 point |
        /// @remarks MS Shell Dlg maps to a font set in the system registry.
        /// @remarks If the above fonts are not installed, the default font is Tahoma, 8 point. If Tahoma, 8 point, is not installed, DefaultFont returns the value of the GenericSansSerif property.
        /// @remarks The Font returned by DefaultFont does not change when the user is in High Contrast mode. For a font that changes when the user is in High Contrast mode use another system font such as IconTitleFont.
        static property_<Font, readonly_> DefaultFont;

        /// @brief Gets a font that applications can use for dialog boxes and forms.
        /// @return Font A Font that can be used for dialog boxes and forms, depending on the operating system and local culture setting of the system.
        /// @remarks If the operating system is Windows 2000 or Windows XP, the DialogFont property returns Tahoma, 8 point. Otherwise, DialogFont returns the value of the DefaultFont property. The Font returned by DialogFont does not change when the user is in High Contrast mode. For a font that changes when the user is in High Contrast mode use another system font such as IconTitleFont.
        static property_<Font, readonly_> DialogFont;

        /// @brief Gets a Font that is used for icon titles.
        /// @return Font A Font that is used for icon titles.
        static property_<Font, readonly_> IconTitleFont;

        /// @brief Gets a Font that is used for menus.
        /// @return Font A Font that is used for menus.
        static property_<Font, readonly_> MenuFont;

        /// @brief Gets a Font that is used for message boxes.
        /// @return Font A Font that is used for message boxes.
        static property_<Font, readonly_> MessageBoxFont;

        /// @brief Gets a Font that is used to display text in the title bars of small windows, such as tool windows.
        /// @return Font A Font that is used to display text in the title bars of small windows, such as tool windows.
        static property_<Font, readonly_> SmallCaptionFont;

        /// @brief Gets a Font that is used to display text in the status bar.
        /// @return Font A Font that is used to display text in the status bar.
        static property_<Font, readonly_> StatusFont;
      };
    }
  }
}
