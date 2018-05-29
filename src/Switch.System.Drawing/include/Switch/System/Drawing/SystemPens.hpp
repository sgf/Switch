/// @file
/// @brief Contains Switch::System::Drawing::Pen class.
#pragma once

#include "Pen.hpp"

/// @cond
namespace Native {
  class GdiApi;
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Each property of the SystemPens class is a Pen that is the color of a Windows display element and that has a width of 1 pixel.
      /// @par Library
      /// Switch.System.Drawing
      /// @remarks The Pen objects returned by this class are immutable, meaning their properties cannot be changed. To see the colors represented by pens in this class, see Colors by Name.
      /// @par Examples
      /// The following code example creates points and sizes using several of the overloaded operators defined for these types. It also demonstrates how to use the SystemPens class.<br><br>
      /// This example is designed to be used with Windows Forms. Create a form that contains a Button named subtractButton. Paste the code into the form and call the CreatePointsAndSizes method from the form's Paint event-handling method, passing e as PaintEventArgs.
      /// @code
      /// void CreatePointsAndSizes(PaintEventArgs& e) {
      ///   // Create the starting point.
      ///   Point startPoint(subtractButton.Size);
      ///
      ///   // Use the addition operator to get the end point.
      ///   Point endPoint = startPoint + Size(140, 150);
      ///
      ///   // Draw a line between the points.
      ///   e.Graphics().DrawLine(SystemPens::Highlight, startPoint, endPoint);
      ///
      ///   // Convert the starting point to a size and compare it to the
      ///   // subtractButton size.
      ///   Size buttonSize = startPoint;
      ///   if (buttonSize == subtractButton.Size) {
      ///     // If the sizes are equal, tell the user.
      ///     e.Graphics().DrawString("The sizes are equal.", Font(this->Font, FontStyle::Italic), Brushes::Indigo, 10.0F, 65.0F);
      ///   }
      /// }
      /// @endcode
      class system_drawing_export_ SystemPens static_ {
      public:
        /// @brief Gets a Pen that is the color of the active window's border.
        /// @return A Pen that is the color of the active window's border.
        static property_<Pen, readonly_> ActiveBorder;

        /// @brief Gets a Pen that is the color of the background of the active window's title bar.
        /// @return A Pen that is the color of the background of the active window's title bar.
        static property_<Pen, readonly_> ActiveCaption;

        /// @brief Gets a Pen that is the color of the text in the active window's title bar.
        /// @return A Pen that is the color of the text in the active window's title bar.
        static property_<Pen, readonly_> ActiveCaptionText;

        /// @brief Gets a Pen that is the color of the application workspace.
        /// @return A Pen that is the color of the application workspace.
        static property_<Pen, readonly_> AppWorkspace;

        /// @brief Gets a Pen that is the face color of a 3-D element.
        /// @return A Pen that is the face color of a 3-D element.
        static property_<Pen, readonly_> ButtonFace;

        /// @brief Gets a Pen that is the highlight color of a 3-D element.
        /// @return A Pen that is the highlight color of a 3-D element.
        static property_<Pen, readonly_> ButtonHighlight;

        /// @brief Gets a Pen that is the shadow color of a 3-D element.
        /// @return A Pen that is the shadow color of a 3-D element.
        static property_<Pen, readonly_> ButtonShadow;

        /// @brief Gets a Pen that is the face color of a 3-D element.
        /// @return A Pen that is the face color of a 3-D element.
        static property_<Pen, readonly_> Control;

        /// @brief Gets a Pen that is the shadow color of a 3-D element.
        /// @return A Pen that is the shadow color of a 3-D element.
        static property_<Pen, readonly_> ControlDark;

        /// @brief Gets a Pen that is the dark shadow color of a 3-D element.
        /// @return A Pen that is the dark shadow color of a 3-D element.
        static property_<Pen, readonly_> ControlDarkDark;

        /// @brief Gets a Pen that is the light color of a 3-D element.
        /// @return A Pen that is the light color of a 3-D element.
        static property_<Pen, readonly_> ControlLight;

        /// @brief Gets a Pen that is the highlight color of a 3-D element.
        /// @return A Pen that is the highlight color of a 3-D element.
        static property_<Pen, readonly_> ControlLightLight;

        /// @brief Gets a Pen that is the color of text in a 3-D element.
        /// @return A Pen that is the color of text in a 3-D element.
        static property_<Pen, readonly_> ControlText;

        /// @brief Gets a Pen that is the color of the desktop.
        /// @return A Pen that is the color of the desktop.
        static property_<Pen, readonly_> Desktop;

        /// @brief Gets a Pen that is the lightest color in the color gradient of an active window's title bar.
        /// @return A Pen that is the lightest color in the color gradient of an active window's title bar.
        static property_<Pen, readonly_> GradientActiveCaption;

        /// @brief Gets a Pen that is the lightest color in the color gradient of an inactive window's title bar.
        /// @return A Pen that is the lightest color in the color gradient of an inactive window's title bar.
        static property_<Pen, readonly_> GradientInactiveCaption;

        /// @brief Gets a Pen that is the color of dimmed text.
        /// @return A Pen that is the color of dimmed text.
        static property_<Pen, readonly_> GrayText;

        /// @brief Gets a Pen that is the color of the background of selected items.
        /// @return A Pen that is the color of the background of selected items.
        static property_<Pen, readonly_> Highlight;

        /// @brief Gets a Pen that is the color of the text of selected items.
        /// @return A Pen that is the color of the text of selected items.
        static property_<Pen, readonly_> HighlightText;

        /// @brief Gets a Pen that is the color used to designate a hot-tracked item.
        /// @return A Pen that is the color used to designate a hot-tracked item.
        static property_<Pen, readonly_> HotTrack;

        /// @brief Gets a Pen that is the color of an inactive window's border.
        /// @return A Pen that is the color of an inactive window's border.
        static property_<Pen, readonly_> InactiveBorder;

        /// @brief Gets a Pen that is the color of the background of an inactive window's title bar.
        /// @return A Pen that is the color of the background of an inactive window's title bar.
        static property_<Pen, readonly_> InactiveCaption;

        /// @brief Gets a Pen that is the color of the text in an inactive window's title bar.
        /// @return A Pen that is the color of the text in an inactive window's title bar.
        static property_<Pen, readonly_> InactiveCaptionText;

        /// @brief Gets a Pen that is the color of the background of a ToolTip.
        /// @return A Pen that is the color of the background of a ToolTip.
        static property_<Pen, readonly_> Info;

        /// @brief Gets a Pen that is the color of the text of a ToolTip.
        /// @return A Pen that is the color of the text of a ToolTip.
        static property_<Pen, readonly_> InfoText;

        /// @brief Gets a Pen that is the color of a menu's background.
        /// @return A Pen that is the color of a menu's background.
        static property_<Pen, readonly_> Menu;

        /// @brief Gets a Pen that is the color of the background of a menu bar.
        /// @return A Pen that is the color of the background of a menu bar.
        static property_<Pen, readonly_> MenuBar;

        /// @brief Gets a Pen that is the color used to highlight menu items when the menu appears as a flat menu.
        /// @return A Pen that is the color used to highlight menu items when the menu appears as a flat menu.
        static property_<Pen, readonly_> MenuHighlight;

        /// @brief Gets a Pen that is the color of a menu's text.
        /// @return A Pen that is the color of a menu's text.
        static property_<Pen, readonly_> MenuText;

        /// @brief Gets a Pen that is the color of the background of a scroll bar.
        /// @return A Pen that is the color of the background of a scroll bar.
        static property_<Pen, readonly_> ScrollBar;

        /// @brief Gets a Pen that is the color of the background in the client area of a window.
        /// @return A Pen that is the color of the background in the client area of a window.
        static property_<Pen, readonly_> Window;

        /// @brief Gets a Pen that is the color of a window frame.
        /// @return A Pen that is the color of a window frame.
        static property_<Pen, readonly_> WindowFrame;

        /// @brief Gets a Pen that is the color of the text in the client area of a window.
        /// @return A Pen that is the color of the text in the client area of a window.
        static property_<Pen, readonly_> WindowText;

        /// @brief Creates a Pen from the specified Color.
        /// @param color The Color structure from which to create the Pen.
        /// @return The Pen this method creates.
        static Pen FromSystemColor(const Color& color);
      };
    }
  }
}
