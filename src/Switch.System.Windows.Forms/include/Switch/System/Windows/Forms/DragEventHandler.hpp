/// @file
/// @brief Contains Switch::System::Windows::Forms::DragEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "DragEventArgs.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents the method that will handle the DragDrop, DragEnter, or DragOver event of a Control.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @param sender The source of the event.
        /// @param e A DragEventArgs that contains the event data.
        /// @remarks When you create a DragEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about handling events with delegates, see Handling and Raising Events.
        /// @par Examples
        /// The following example demonstrates a drag-and-drop operation between two ListBox controls. The example calls the DoDragDrop method when the drag action starts. The drag action starts if the mouse has moved more than SystemInformation.DragSize from the mouse location during the MouseDown event. The IndexFromPoint method is used to determine the index of the item to drag during the MouseDown event.<br><br>
        /// The example also demonstrates using custom cursors for the drag-and-drop operation. The example assumes that two cursor files, 3dwarro.cur and 3dwno.cur, exist in the application directory, for the custom drag and no-drop cursors, respectively. The custom cursors will be used if the UseCustomCursorsCheckCheckBox is checked. The custom cursors are set in the GiveFeedback event handler.<br><br>
        /// The keyboard state is evaluated in the DragOver event handler for the right ListBox, to determine what the drag operation will be based upon state of the SHIFT, CTRL, ALT, or CTRL+ALT keys. The location in the ListBox where the drop would occur is also determined during the DragOver event. If the data to drop is not a String, then the DragEventArgs.Effect is set to DragDropEffects.None. Finally, the status of the drop is displayed in the DropLocationLabelLabel.<br><br>
        /// The data to drop for the right ListBox is determined in the DragDrop event handler and the String value is added at the appropriate place in the ListBox. If the drag operation moves outside the bounds of the form, then the drag-and-drop operation is canceled in the QueryContinueDrag event handler.<br><br>
        /// This code excerpt demonstrates using the DragEventHandler delegate with the DragOver event. See the DoDragDrop method for the complete code example.
        /// @code
        /// void ListDragTarget_DragOver(const object& sender, System::Windows::Forms::DragEventArgs& e) {
        ///   // Determine whether string data exists in the drop data. If not, then
        ///   // the drop effect reflects that the drop cannot occur.
        ///   if (!e.GetData().GetDataPresent<System::String>())) {
        ///     e.Effect(DragDropEffects::None);
        ///     DropLocationLabel->Text("None - no string data.");
        ///     return;
        ///   }
        ///   // Set the effect based upon the KeyState.
        ///   if ((e.KeyState() & (8+32)) == (8+32) && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
        ///     // KeyState 8 + 32 = CTL + ALT
        ///     // Link drag-and-drop effect.
        ///     e.Effect(DragDropEffects::Link);
        ///   } else if ((e.KeyState() & 32) == 32 && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
        ///     // ALT KeyState for link.
        ///     e.Effect(DragDropEffects::Link);
        ///   } else if ((e.KeyState() & 4) == 4 && (e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects::Move) {
        ///     // SHIFT KeyState for move.
        ///     e.Effect(DragDropEffects::Move);
        ///   } else if ((e.KeyState() & 8) == 8 && (e.AllowedEffect() & DragDropEffects::Copy) == DragDropEffects::Copy) {
        ///     // CTL KeyState for copy.
        ///     e.Effect(DragDropEffects::Copy);
        ///   } else if ((e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects::Move) {
        ///     // By default, the drop action should be move, if allowed.
        ///     e.Effect(DragDropEffects::Move);
        ///   } else
        ///     e.Effect(DragDropEffects::None);
        ///   // Get the index of the item the mouse is below.
        ///   // The mouse locations are relative to the screen, so they must be
        ///   // converted to client coordinates.
        ///   indexOfItemUnderMouseToDrop =
        ///   ListDragTarget->SetIndexFromPoint(ListDragTarget->SetPointToClient(Point(e.X, e.Y)));
        ///   // Updates the label text.
        ///   if (indexOfItemUnderMouseToDrop != ListBox->NoMatches()) {
        ///     DropLocationLabel->Text("Drops before item #" + (indexOfItemUnderMouseToDrop + 1));
        ///   } else {
        ///     DropLocationLabel->Text("Drops at the end.");
        ///   }
        /// }
        /// @endcode
        using DragEventHandler = GenericEventHandler<DragEventArgs&>;
      }
    }
  }
}
