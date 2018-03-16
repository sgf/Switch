/// @file
/// @brief Contains Switch::System::Windows::Forms::DragDropEffects enum.
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
        /// @brief Specifies the possible effects of a drag-and-drop operation.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
        /// @remarks This enumeration is used by the following classes: DragEventArgs, GiveFeedbackEventArgs, and Control.
        /// @remarks You can use DragDropEffects to display different mouse pointers for drag-and-drop operations. For example, you can display a plus symbol for a Copy drag-and-drop operation, an arrow symbol for a Move drag-and-drop operation, or a red circle with a line through it symbol for a None drag-and-drop operation.
        /// @remarks If you want to drop data at a position in the target that is not currently visible, you could scroll the target while dragging. If a target does not support scrolling, you must make sure that the drop position is visible in the target before you begin the drag-and-drop operation. The following are some scenarios when you might want to scroll a target:
        /// * You are dragging text into a document, and you want to drop the text at a position not visible in the document window.
        /// * You are dragging a file into a file tree, and you want to drop the file on a node not visible in the file tree.
        /// @par Examples
        /// This code example demonstrates using the DragDropEffects enumeration when the user moves the mouse over the drop target during a drag-and-drop operation. This code example is part of a larger example provided for the DoDragDrop method of the Control class. See the DoDragDrop method for the complete code example.
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
        enum class DragDropEffects {
          None = 0,
          Copy = 0b1,
          Move = 0x10,
          Link = 0b100,
          Scroll = 0b1000000000000000,
          All = 0b1000000000000111,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::DragDropEffects> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::DragDropEffects> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::DragDropEffects, string>& values, bool& flags) {
    values[System::Windows::Forms::DragDropEffects::None] = "None";
    values[System::Windows::Forms::DragDropEffects::Copy] = "Copy";
    values[System::Windows::Forms::DragDropEffects::Move] = "Move";
    values[System::Windows::Forms::DragDropEffects::Link] = "Link";
    values[System::Windows::Forms::DragDropEffects::Scroll] = "Scroll";
    values[System::Windows::Forms::DragDropEffects::All] = "All";
    flags = true;
  }
};

/// @endcond

using namespace Switch;
