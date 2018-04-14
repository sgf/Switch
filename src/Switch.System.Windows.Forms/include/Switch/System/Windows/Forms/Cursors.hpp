/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

#include "Cursor.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Provides a collection of Cursor objects for use by a Windows Forms application.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks Some of the Cursor objects in this class can take on a different appearance than those described. The user can change the cursor appearance by adjusting the mouse pointer settings in their operating system. The panning and no move cursors are static and cannot be changed by the operating system.
        /// @remarks The panning and no move cursors are used during mouse wheel operations. Depending on the direction the window can be scrolled, the cursor changes to the appropriate no move cursor when the mouse wheel is clicked. The cursor then changes to the appropriate panning cursor as the mouse is moved.
        /// @par EXamples
        /// The following example demonstrates changing the mouse cursor using the Control.Cursor property, the Cursor class, and the Cursors class. The example creates a form that contains a ComboBox control, a Panel control, and a ListView control. The ComboBox contains all cursors provided by the Cursors class. When the user selects a mouse cursor in the ComboBox, the Control.Cursor property is set to the selected cursor, which updates the cursor for the Panel. The ListView is updated every time the Control.CursorChanged event occurs.
        /// @include Cursor.cpp
        class system_windows_forms_export_ Cursors static_ {
        public:
          /// @brief Gets the cursor that appears when an application starts.
          /// @return The Cursor that represents the cursor that appears when an application starts.
          static property_<Cursor, readonly_> AppStarting;

          /// @brief Gets the arrow cursor.
          /// @return The Cursor that represents the arrow cursor.
          static property_<Cursor, readonly_> Arrow;

          /// @brief Gets the close hand cursor.
          /// @return The Cursor that represents the close hand cursor.
          static property_<Cursor, readonly_> CloseHand;

          /// @brief Gets the contextual menu cursor.
          /// @return The Cursor that represents the contextual menu cursor.
          static property_<Cursor, readonly_> ContextualMenu;

          /// @brief Gets the crosshair cursor.
          /// @return The Cursor that represents the crosshair cursor.
          static property_<Cursor, readonly_> Cross;

          /// @brief Gets the default cursor, which is usually an arrow cursor.
          /// @return The Cursor that represents the default cursor.
          static property_<Cursor, readonly_> Default;

          /// @brief Gets the disappearing item cursor.
          /// @return The Cursor that represents the disappearing item cursor.
          static property_<Cursor, readonly_> DisappearingItem;

          /// @brief Gets the drag copy cursor.
          /// @return The Cursor that represents the drag copy cursor.
          static property_<Cursor, readonly_> DragCopy;

          /// @brief Gets the drag link cursor.
          /// @return The Cursor that represents the drag link cursor.
          static property_<Cursor, readonly_> DragLink;

          /// @brief Gets the hand cursor, typically used when hovering over a Web link.
          /// @return The Cursor that represents the hand cursor.
          static property_<Cursor, readonly_> Hand;

          /// @brief Gets the Help cursor, which is a combination of an arrow and a question mark.
          /// @return The Cursor that represents the Help cursor.
          static property_<Cursor, readonly_> Help;

          /// @brief Gets the cursor that appears when the mouse is positioned over a horizontal splitter bar.
          /// @return The Cursor that represents the cursor that appears when the mouse is positioned over a horizontal splitter bar.
          static property_<Cursor, readonly_> HSplit;

          /// @brief Gets the I-beam cursor, which is used to show where the text cursor appears when the mouse is clicked.
          /// @return The Cursor that represents the I-beam cursor.
          static property_<Cursor, readonly_> IBeam;

          /// @brief Gets the cursor that indicates that a particular region is invalid for the current operation.
          /// @return The Cursor that represents the cursor that indicates that a particular region is invalid for the current operation.
          static property_<Cursor, readonly_> No;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in both a horizontal and vertical direction.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
          static property_<Cursor, readonly_> NoMove2D;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in a horizontal direction.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
          static property_<Cursor, readonly_> NoMoveHoriz;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in a vertical direction.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
          static property_<Cursor, readonly_> NoMoveVert;

          /// @brief Gets the open hand cursor.
          /// @return The Cursor that represents the open hand cursor.
          static property_<Cursor, readonly_> OpenHand;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the right.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the right.
          static property_<Cursor, readonly_> PanEast;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the right.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the right.
          static property_<Cursor, readonly_> PanNE;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in an upward direction.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in an upward direction.
          static property_<Cursor, readonly_> PanNorth;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the left.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the left.
          static property_<Cursor, readonly_> PanNW;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the right.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the right.
          static property_<Cursor, readonly_> PanSE;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in a downward direction.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in a downward direction.
          static property_<Cursor, readonly_> PanSouth;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the left.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the left.
          static property_<Cursor, readonly_> PanSW;

          /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the left.
          /// @return The Cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the left.
          static property_<Cursor, readonly_> PanWest;

          /// @brief Gets the four-headed sizing cursor, which consists of four joined arrows that point north, south, east, and west.
          /// @return The Cursor that represents the four-headed sizing cursor.
          static property_<Cursor, readonly_> SizeAll;

          /// @brief Gets the two-headed diagonal (northeast/southwest) sizing cursor.
          /// @return The Cursor that represents two-headed diagonal (northeast/southwest) sizing cursor.
          static property_<Cursor, readonly_> SizeNESW;

          /// @brief Gets the two-headed vertical (north/south) sizing cursor.
          /// @return The Cursor that represents the two-headed vertical (north/south) sizing cursor.
          static property_<Cursor, readonly_> SizeNS;

          /// @brief Gets the two-headed diagonal (northwest/southeast) sizing cursor.
          /// @return The Cursor that represents the two-headed diagonal (northwest/southeast) sizing cursor.
          static property_<Cursor, readonly_> SizeNWSE;

          /// @brief Gets the two-headed diagonal (northwest/southeast) sizing cursor.
          /// @return The Cursor that represents the two-headed diagonal (northwest/southeast) sizing cursor.
          static property_<Cursor, readonly_> SizeWE;

          /// @brief Gets the up arrow cursor, typically used to identify an insertion point.
          /// @return The Cursor that represents the up arrow cursor.
          static property_<Cursor, readonly_> UpArrow;

          /// @brief Gets the vertical I-beam cursor, which is used to show where the text cursor appears when the mouse is clicked for vertical layout.
          /// @return The Cursor that represents the vertical I-beam cursor.
          static property_<Cursor, readonly_> VIBeam;

          /// @brief Gets the cursor that appears when the mouse is positioned over a vertical splitter bar.
          /// @return The Cursor that represents the cursor that appears when the mouse is positioned over a vertical splitter bar.
          static property_<Cursor, readonly_> VSplit;

          /// @brief Gets the wait cursor, typically an hourglass shape.
          /// @return The Cursor that represents the wait cursor.
          static property_<Cursor, readonly_> WaitCursor;
        };
      }
    }
  }
}
