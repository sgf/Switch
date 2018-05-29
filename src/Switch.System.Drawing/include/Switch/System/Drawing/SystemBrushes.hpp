/// @file
/// @brief Contains Switch::System::Drawing::Brush class.
#pragma once

#include "Color.hpp"
#include "SolidBrush.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Each property of the SystemBrushes class is a SolidBrush that is the color of a Windows display element.
      /// @par Library
      /// Switch.System.Drawing
      /// @par Examples
      /// The following code example shows how to set a keyboard shortcut using the HotkeyPrefix property. It also demonstrates how to use the FromSystemColor method. To run this example, paste the code into a form, handle the form's Paint event and call the following method, passing e as PaintEventArgs.
      /// @code
      /// void ShowHotKey(PaintEventArg&s e) {
      ///   // Declare the string with a keyboard shortcut.
      ///   string text = "&Click Here";
      ///
      ///   // Declare a new StringFormat.
      ///   StringFormat format;
      ///
      ///   // Set the HotkeyPrefix property.
      ///   format.HotkeyPrefix = System::Drawing::Text::HotkeyPrefix::Show;
      ///
      ///   // Draw the string.
      ///   Brush theBrush = SystemBrushes::FromSystemColor(SystemColors::Highlight);
      ///
      ///   e.Graphics().DrawString(text, this->Font, theBrush, 30, 40, format);
      /// }
      /// @endcode
      class system_drawing_export_ SystemBrushes static_ {
      public:
        /// @brief Gets a SolidBrush that is the color of the active window's border.
        /// @return A SolidBrush that is the color of the active window's border.
        static property_<SolidBrush, readonly_> ActiveBorder;

        /// @brief Gets a SolidBrush that is the color of the background of the active window's title bar.
        /// @return A SolidBrush that is the color of the background of the active window's title bar.
        static property_<SolidBrush, readonly_> ActiveCaption;

        /// @brief Gets a SolidBrush that is the color of the text in the active window's title bar.
        /// @return A SolidBrush that is the color of the text in the active window's title bar.
        static property_<SolidBrush, readonly_> ActiveCaptionText;

        /// @brief Gets a SolidBrush that is the color of the application workspace.
        /// @return A SolidBrush that is the color of the application workspace.
        static property_<SolidBrush, readonly_> AppWorkspace;

        /// @brief Gets a SolidBrush that is the face color of a 3-D element.
        /// @return A SolidBrush that is the face color of a 3-D element.
        static property_<SolidBrush, readonly_> ButtonFace;

        /// @brief Gets a SolidBrush that is the highlight color of a 3-D element.
        /// @return A SolidBrush that is the highlight color of a 3-D element.
        static property_<SolidBrush, readonly_> ButtonHighlight;

        /// @brief Gets a SolidBrush that is the shadow color of a 3-D element.
        /// @return A SolidBrush that is the shadow color of a 3-D element.
        static property_<SolidBrush, readonly_> ButtonShadow;

        /// @brief Gets a SolidBrush that is the face color of a 3-D element.
        /// @return A SolidBrush that is the face color of a 3-D element.
        static property_<SolidBrush, readonly_> Control;

        /// @brief Gets a SolidBrush that is the shadow color of a 3-D element.
        /// @return A SolidBrush that is the shadow color of a 3-D element.
        static property_<SolidBrush, readonly_> ControlDark;

        /// @brief Gets a SolidBrush that is the dark shadow color of a 3-D element.
        /// @return A SolidBrush that is the dark shadow color of a 3-D element.
        static property_<SolidBrush, readonly_> ControlDarkDark;

        /// @brief Gets a SolidBrush that is the light color of a 3-D element.
        /// @return A SolidBrush that is the light color of a 3-D element.
        static property_<SolidBrush, readonly_> ControlLight;

        /// @brief Gets a SolidBrush that is the highlight color of a 3-D element.
        /// @return A SolidBrush that is the highlight color of a 3-D element.
        static property_<SolidBrush, readonly_> ControlLightLight;

        /// @brief Gets a SolidBrush that is the color of text in a 3-D element.
        /// @return A SolidBrush that is the color of text in a 3-D element.
        static property_<SolidBrush, readonly_> ControlText;

        /// @brief Gets a SolidBrush that is the color of the desktop.
        /// @return A SolidBrush that is the color of the desktop.
        static property_<SolidBrush, readonly_> Desktop;

        /// @brief Gets a SolidBrush that is the lightest color in the color gradient of an active window's title bar.
        /// @return A SolidBrush that is the lightest color in the color gradient of an active window's title bar.
        static property_<SolidBrush, readonly_> GradientActiveCaption;

        /// @brief Gets a SolidBrush that is the lightest color in the color gradient of an inactive window's title bar.
        /// @return A SolidBrush that is the lightest color in the color gradient of an inactive window's title bar.
        static property_<SolidBrush, readonly_> GradientInactiveCaption;

        /// @brief Gets a SolidBrush that is the color of dimmed text.
        /// @return A SolidBrush that is the color of dimmed text.
        static property_<SolidBrush, readonly_> GrayText;

        /// @brief Gets a SolidBrush that is the color of the background of selected items.
        /// @return A SolidBrush that is the color of the background of selected items.
        static property_<SolidBrush, readonly_> Highlight;

        /// @brief Gets a SolidBrush that is the color of the text of selected items.
        /// @return A SolidBrush that is the color of the text of selected items.
        static property_<SolidBrush, readonly_> HighlightText;

        /// @brief Gets a SolidBrush that is the color used to designate a hot-tracked item.
        /// @return A SolidBrush that is the color used to designate a hot-tracked item.
        static property_<SolidBrush, readonly_> HotTrack;

        /// @brief Gets a SolidBrush that is the color of an inactive window's border.
        /// @return A SolidBrush that is the color of an inactive window's border.
        static property_<SolidBrush, readonly_> InactiveBorder;

        /// @brief Gets a SolidBrush that is the color of the background of an inactive window's title bar.
        /// @return A SolidBrush that is the color of the background of an inactive window's title bar.
        static property_<SolidBrush, readonly_> InactiveCaption;

        /// @brief Gets a SolidBrush that is the color of the text in an inactive window's title bar.
        /// @return A SolidBrush that is the color of the text in an inactive window's title bar.
        static property_<SolidBrush, readonly_> InactiveCaptionText;

        /// @brief Gets a SolidBrush that is the color of the background of a ToolTip.
        /// @return A SolidBrush that is the color of the background of a ToolTip.
        static property_<SolidBrush, readonly_> Info;

        /// @brief Gets a SolidBrush that is the color of the text of a ToolTip.
        /// @return A SolidBrush that is the color of the text of a ToolTip.
        static property_<SolidBrush, readonly_> InfoText;

        /// @brief Gets a SolidBrush that is the color of a menu's background.
        /// @return A SolidBrush that is the color of a menu's background.
        static property_<SolidBrush, readonly_> Menu;

        /// @brief Gets a SolidBrush that is the color of the background of a menu bar.
        /// @return A SolidBrush that is the color of the background of a menu bar.
        static property_<SolidBrush, readonly_> MenuBar;

        /// @brief Gets a SolidBrush that is the color used to highlight menu items when the menu appears as a flat menu.
        /// @return A SolidBrush that is the color used to highlight menu items when the menu appears as a flat menu.
        static property_<SolidBrush, readonly_> MenuHighlight;

        /// @brief Gets a SolidBrush that is the color of a menu's text.
        /// @return A SolidBrush that is the color of a menu's text.
        static property_<SolidBrush, readonly_> MenuText;

        /// @brief Gets a SolidBrush that is the color of the background of a scroll bar.
        /// @return A SolidBrush that is the color of the background of a scroll bar.
        static property_<SolidBrush, readonly_> ScrollBar;

        /// @brief Gets a SolidBrush that is the color of the background in the client area of a window.
        /// @return A SolidBrush that is the color of the background in the client area of a window.
        static property_<SolidBrush, readonly_> Window;

        /// @brief Gets a SolidBrush that is the color of a window frame.
        /// @return A SolidBrush that is the color of a window frame.
        static property_<SolidBrush, readonly_> WindowFrame;

        /// @brief Gets a SolidBrush that is the color of the text in the client area of a window.
        /// @return A SolidBrush that is the color of the text in the client area of a window.
        static property_<SolidBrush, readonly_> WindowText;

        /// @brief Creates a SolidBrush from the specified Color.
        /// @param color The Color structure from which to create the Brush.
        /// @return The Brush this method creates.
        static SolidBrush FromSystemColor(const Color& color);
      };
    }
  }
}
