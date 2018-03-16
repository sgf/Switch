/// @file
/// @brief Contains Switch::System::Windows::Forms::AccessibleRole enum.
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
        /// @brief Specifies values representing possible roles for an accessible object.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The role of the object describes the function of the object and is used by accessibility applications.
        /// @remarks This enumeration is used by AccessibleObject and Control.AccessibleRole
        /// @par Examples
        /// The following code example demonstrates the creation of an accessibility-aware chart control, using the AccessibleObject and Control.ControlAccessibleObject classes to expose accessible information. The control plots two curves along with a legend. The ChartControlAccessibleObject class, which derives from ControlAccessibleObject, is used in the CreateAccessibilityInstance method to provide custom accessible information for the chart control. Since the chart legend is not an actual Control -based control, but instead is drawn by the chart control, it does not any built-in accessible information. Because of this, the ChartControlAccessibleObject class overrides the GetChild method to return the CurveLegendAccessibleObject that represents accessible information for each part of the legend. When an accessible-aware application uses this control, the control can provide the necessary accessible information.<br><br>
        /// This example demonstrates using the AccessibleNavigation enumeration with the Navigate method. See the AccessibleObject class overview for the complete code example.
        /// @code
        /// // Inner class ChartControlAccessibleObject represents accessible information associated with the ChartControl.
        /// // The ChartControlAccessibleObject is returned in the ChartControl.CreateAccessibilityInstance override.
        /// class ChartControlAccessibleObject : public ControlAccessibleObject {
        /// private:
        ///   ChartControl chartControl;
        ///
        /// public:
        ///   ChartControlAccessibleObject(ChartControl ctrl) : ControlAccessibleObject(ctrl), chartControl(ctrl) {}
        ///
        ///   // Gets the role for the Chart. This is used by accessibility programs.
        ///   AccessibleRole GetRole() const override {return AccessibleRole.Chart;}
        ///
        ///   // Gets the state for the Chart. This is used by accessibility programs.
        ///   AccessibleStates GetState() const override {return AccessibleStates.ReadOnly;}
        ///
        ///   // The CurveLegend objects are "child" controls in terms of accessibility so
        ///   // return the number of ChartLengend objects.
        ///   int GetChildCount() override {return chartControl.Legends.Length;}
        ///
        ///   // Gets the Accessibility object of the child CurveLegend idetified by index.
        ///   ref<AccessibleObject> GetChild(int index) override {
        ///     if (index >= 0 && index < chartControl.Legends().Length) {
        ///       return chartControl.Legends()[index].AccessibilityObject;
        ///     }
        ///     return null;
        ///   }
        ///
        /// private:
        ///   // Helper function that is used by the CurveLegend's accessibility object
        ///   // to navigate between sibiling controls. Specifically, this function is used in
        ///   // the CurveLegend.CurveLegendAccessibleObject.Navigate function.
        ///   AccessibleObject NavigateFromChild(const CurveLegend::CurveLegendAccessibleObject& child, AccessibleNavigation navdir) {
        ///     switch(navdir) {
        ///       case AccessibleNavigation::Down:
        ///       case AccessibleNavigation::Next:
        ///         return GetChild(child.ID + 1);
        ///
        ///       case AccessibleNavigation::Up:
        ///       case AccessibleNavigation::Previous:
        ///         return GetChild(child.ID - 1);
        ///     }
        ///     return null;
        ///   }
        ///
        ///   // Helper function that is used by the CurveLegend's accessibility object
        ///   // to select a specific CurveLegend control. Specifically, this function is used
        ///   // in the CurveLegend.CurveLegendAccessibleObject.Select function.
        ///   void SelectChild(const CurveLegend::CurveLegendAccessibleObject& child, AccessibleSelection selection) {
        ///     int childID = child.ID;
        ///
        ///     // Determine which selection action should occur, based on the
        ///     // AccessibleSelection value.
        ///     if ((selection & AccessibleSelection::TakeSelection) != 0) {
        ///       for(int i = 0; i < chartControl.Legends().Length; i++) {
        ///         if (i == childID) {
        ///           chartControl.Legends()[i].Selected = true;
        ///         } else {
        ///           chartControl.Legends()[i].Selected = false;
        ///         }
        ///       }
        ///
        ///       // AccessibleSelection.AddSelection means that the CurveLegend will be selected.
        ///       if ((selection & AccessibleSelection::AddSelection) != 0) {
        ///         chartControl.Legends()[childID].Selected = true;
        ///       }
        ///
        ///       // AccessibleSelection.AddSelection means that the CurveLegend will be unselected.
        ///       if ((selection & AccessibleSelection::RemoveSelection) != 0) {
        ///         chartControl.Legends()[childID].Selected = false;
        ///       }
        ///     }
        ///   }
        /// }
        /// @endcode
        enum class AccessibleRole {
          /// @brief A system-provided role.
          Default = -1,
          /// @brief No role.
          None = 0,
          ///  @brief A title or caption bar for a window.
          TitleBar = 1,
          /// @brief A menu bar, usually beneath the title bar of a window, from which users can select menus.
          MenuBar = 2,
          /// @brief A vertical or horizontal scroll bar, which can be either part of the client area or used in a control.
          ScrollBar = 3,
          /// @brief A special mouse pointer, which allows a user to manipulate user interface elements such as a window. For example, a user can click and drag a sizing grip in the lower-right corner of a window to resize it.
          Grip = 4,
          /// @brief A system sound, which is associated with various system events.
          Sound = 5,
          /// @brief A mouse pointer.
          Cursor = 6,
          /// @brief A caret, which is a flashing line, block, or bitmap that marks the location of the insertion point in a window's client area.
          Caret = 7,
          /// @brief An alert or condition that you can notify a user about. Use this role only for objects that embody an alert but are not associated with another user interface element, such as a message box, graphic, text, or sound.
          Alert = 8,
          /// @brief A window frame, which usually contains child objects such as a title bar, client, and other objects typically contained in a window.
          Window = 9,
          /// @brief A window's user area.
          Client = 10,
          /// @brief A menu, which presents a list of options from which the user can make a selection to perform an action. All menu types must have this role, including drop-down menus that are displayed by selection from a menu bar, and shortcut menus that are displayed when the right mouse button is clicked.
          MenuPopup = 11,
          /// @brief A menu item, which is an entry in a menu that a user can choose to carry out a command, select an option, or display another menu. Functionally, a menu item can be equivalent to a push button, radio button, check box, or menu.
          MenuItem = 12,
          /// @brief A tool tip, which is a small rectangular pop-up window that displays a brief description of the purpose of a button.
          ToolTip = 13,
          /// @brief The main window for an application.
          Application = 14,
          /// @brief A document window, which is always contained within an application window. This role applies only to multiple-document interface (MDI) windows and refers to an object that contains the MDI title bar.
          Document = 15,
          /// @brief A separate area in a frame, a split document window, or a rectangular area of the status bar that can be used to display information. Users can navigate between panes and within the contents of the current pane, but cannot navigate between items in different panes. Thus, panes represent a level of grouping lower than frame windows or documents, but above individual controls. Typically, the user navigates between panes by pressing TAB, F6, or CTRL+TAB, depending on the context.
          Pane = 16,
          /// @brief A graphical image used to represent data.
          Chart = 17,
          /// @brief A dialog box or message box.
          Dialog = 18,
          /// @brief A window border. The entire border is represented by a single object, rather than by separate objects for each side.
          Border = 19,
          /// @brief The objects grouped in a logical manner. There can be a parent-child relationship between the grouping object and the objects it contains.
          Grouping = 20,
          /// @brief A space divided visually into two regions, such as a separator menu item or a separator dividing split panes within a window.
          Separator = 21,
          /// @brief A toolbar, which is a grouping of controls that provide easy access to frequently used features.
          ToolBar = 22,
          /// @brief A status bar, which is an area typically at the bottom of an application window that displays information about the current operation, state of the application, or selected object. The status bar can have multiple fields that display different kinds of information, such as an explanation of the currently selected menu command in the status bar.
          StatusBar = 23,
          /// @brief A table containing rows and columns of cells and, optionally, row headers and column headers.
          Table = 24,
          /// @brief A column header, which provides a visual label for a column in a table.
          ColumnHeader = 25,
          /// @brief A row header, which provides a visual label for a table row.
          RowHeader = 26,
          /// @brief A column of cells within a table.
          Column = 27,
          /// @brief A row of cells within a table.
          Row = 28,
          /// @brief A cell within a table.
          Cell = 29,
          /// @brief A link, which is a connection between a source document and a destination document. This object might look like text or a graphic, but it acts like a button.
          Link = 30,
          /// @brief A Help display in the form of a ToolTip or Help balloon, which contains buttons and labels that users can click to open custom Help topics.
          HelpBalloon = 31,
          /// @brief A cartoon-like graphic object, such as Microsoft Office Assistant, which is typically displayed to provide help to users of an application.
          Character = 32,
          /// @brief A list box, which allows the user to select one or more items.
          List = 33,
          /// @brief An item in a list box or the list portion of a combo box, drop-down list box, or drop-down combo box.
          ListItem = 34,
          /// @brief An outline or tree structure, such as a tree view control, which displays a hierarchical list and usually allows the user to expand and collapse branches.
          Outline = 35,
          /// @brief An item in an outline or tree structure.
          OutlineItem = 36,
          /// @brief A property page that allows a user to view the attributes for a page, such as the page's title, whether it is a home page, or whether the page has been modified. Normally, the only child of this control is a grouped object that contains the contents of the associated page.
          PageTab = 37,
          /// @brief A property page, which is a dialog box that controls the appearance and the behavior of an object, such as a file or resource. A property page's appearance differs according to its purpose.
          PropertyPage = 38,
          /// @brief An indicator, such as a pointer graphic, that points to the current item.
          Indicator = 39,
          /// @brief A picture.
          Graphic = 40,
          /// @brief The read-only text, such as in a label, for other controls or instructions in a dialog box. Static text cannot be modified or selected.
          StaticText = 41,
          /// @brief The selectable text that can be editable or read-only.
          Text = 42,
          /// @brief A push button control, which is a small rectangular control that a user can turn on or off. A push button, also known as a command button, has a raised appearance in its default off state and a sunken appearance when it is turned on.
          PushButton = 43,
          /// @brief A check box control, which is an option that can be turned on or off independent of other options.
          CheckButton = 44,
          /// @brief An option button, also known as a radio button. All objects sharing a single parent that have this attribute are assumed to be part of a single mutually exclusive group. You can use grouped objects to divide option buttons into separate groups when necessary.
          RadioButton = 45,
          /// @brief A combo box, which is an edit control with an associated list box that provides a set of predefined choices.
          ComboBox = 46,
          /// @brief A drop-down list box. This control shows one item and allows the user to display and select another from a list of alternative choices.
          DropList = 47,
          /// @brief A progress bar, which indicates the progress of a lengthy operation by displaying colored lines inside a horizontal rectangle. The length of the lines in relation to the length of the rectangle corresponds to the percentage of the operation that is complete. This control does not take user input.
          ProgressBar = 48,
          /// @brief A dial or knob. This can also be a read-only object, like a speedometer.
          Dial = 49,
          /// @brief A hot-key field that allows the user to enter a combination or sequence of keystrokes to be used as a hot key, which enables users to perform an action quickly. A hot-key control displays the keystrokes entered by the user and ensures that the user selects a valid key combination.
          HotkeyField = 50,
          /// @brief A control, sometimes called a trackbar, that enables a user to adjust a setting in given increments between minimum and maximum values by moving a slider. The volume controls in the Windows operating system are slider controls.
          Slider = 51,
          /// @brief A spin box, also known as an up-down control, which contains a pair of arrow buttons. A user clicks the arrow buttons with a mouse to increment or decrement a value. A spin button control is most often used with a companion control, called a buddy window, where the current value is displayed.
          SpinButton = 52,
          /// @brief A graphical image used to diagram data.
          Diagram = 53,
          /// @brief An animation control, which contains content that is changing over time, such as a control that displays a series of bitmap frames, like a filmstrip. Animation controls are usually displayed when files are being copied, or when some other time-consuming task is being performed.
          Animation = 54,
          /// @brief A mathematical equation.
          Equation = 55,
          /// @brief A button that drops down a list of items.
          ButtonDropDown = 56,
          /// @brief A button that drops down a menu.
          ButtonMenu = 57,
          /// @brief A button that drops down a grid.
          ButtonDropDownGrid = 58,
          /// @brief A blank space between other objects.
          WhiteSpace = 59,
          /// @brief A container of page tab controls.
          PageTabList = 60,
          /// @brief A control that displays the time.
          Clock = 61,
          /// @brief A toolbar button that has a drop-down list icon directly adjacent to the button.
          SplitButton = 62,
          /// @brief A control designed for entering Internet Protocol (IP) addresses.
          IpAddress = 63,
          /// @brief A control that navigates like an outline item.
          OutlineButton = 64
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::AccessibleRole> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AccessibleRole, string>& values, bool& flags) {
    values[System::Windows::Forms::AccessibleRole::None] = "None";
    values[System::Windows::Forms::AccessibleRole::TitleBar] = "TitleBar";
    values[System::Windows::Forms::AccessibleRole::MenuBar] = "MenuBar";
    values[System::Windows::Forms::AccessibleRole::ScrollBar] = "ScrollBar";
    values[System::Windows::Forms::AccessibleRole::Grip] = "Grip";
    values[System::Windows::Forms::AccessibleRole::Sound] = "Sound";
    values[System::Windows::Forms::AccessibleRole::Cursor] = "Cursor";
    values[System::Windows::Forms::AccessibleRole::Caret] = "Caret";
    values[System::Windows::Forms::AccessibleRole::Alert] = "Alert";
    values[System::Windows::Forms::AccessibleRole::Window] = "Window";
    values[System::Windows::Forms::AccessibleRole::Client] = "Client";
    values[System::Windows::Forms::AccessibleRole::MenuPopup] = "MenuPopup";
    values[System::Windows::Forms::AccessibleRole::MenuItem] = "MenuItem";
    values[System::Windows::Forms::AccessibleRole::ToolTip] = "ToolTip";
    values[System::Windows::Forms::AccessibleRole::Application] = "Application";
    values[System::Windows::Forms::AccessibleRole::Document] = "Document";
    values[System::Windows::Forms::AccessibleRole::Pane] = "Pane";
    values[System::Windows::Forms::AccessibleRole::Chart] = "Chart";
    values[System::Windows::Forms::AccessibleRole::Dialog] = "Dialog";
    values[System::Windows::Forms::AccessibleRole::Border] = "Border";
    values[System::Windows::Forms::AccessibleRole::Grouping] = "Grouping";
    values[System::Windows::Forms::AccessibleRole::Separator] = "Separator";
    values[System::Windows::Forms::AccessibleRole::ToolBar] = "ToolBar";
    values[System::Windows::Forms::AccessibleRole::StatusBar] = "StatusBar";
    values[System::Windows::Forms::AccessibleRole::Table] = "Table";
    values[System::Windows::Forms::AccessibleRole::ColumnHeader] = "ColumnHeader";
    values[System::Windows::Forms::AccessibleRole::RowHeader] = "RowHeader";
    values[System::Windows::Forms::AccessibleRole::Column] = "Column";
    values[System::Windows::Forms::AccessibleRole::Row] = "Row";
    values[System::Windows::Forms::AccessibleRole::Cell] = "Cell";
    values[System::Windows::Forms::AccessibleRole::Link] = "Link";
    values[System::Windows::Forms::AccessibleRole::HelpBalloon] = "HelpBalloon";
    values[System::Windows::Forms::AccessibleRole::Character] = "Character";
    values[System::Windows::Forms::AccessibleRole::List] = "List";
    values[System::Windows::Forms::AccessibleRole::ListItem] = "ListItem";
    values[System::Windows::Forms::AccessibleRole::Outline] = "Outline";
    values[System::Windows::Forms::AccessibleRole::OutlineItem] = "OutlineItem";
    values[System::Windows::Forms::AccessibleRole::PageTab] = "PageTab";
    values[System::Windows::Forms::AccessibleRole::PropertyPage] = "PropertyPage";
    values[System::Windows::Forms::AccessibleRole::Indicator] = "Indicator";
    values[System::Windows::Forms::AccessibleRole::Graphic] = "Graphic";
    values[System::Windows::Forms::AccessibleRole::StaticText] = "StaticText";
    values[System::Windows::Forms::AccessibleRole::PushButton] = "PushButton";
    values[System::Windows::Forms::AccessibleRole::CheckButton] = "CheckButton";
    values[System::Windows::Forms::AccessibleRole::RadioButton] = "RadioButton";
    values[System::Windows::Forms::AccessibleRole::ComboBox] = "ComboBox";
    values[System::Windows::Forms::AccessibleRole::DropList] = "DropList";
    values[System::Windows::Forms::AccessibleRole::ProgressBar] = "ProgressBar";
    values[System::Windows::Forms::AccessibleRole::Dial] = "Dial";
    values[System::Windows::Forms::AccessibleRole::HotkeyField] = "HotkeyField";
    values[System::Windows::Forms::AccessibleRole::Slider] = "Slider";
    values[System::Windows::Forms::AccessibleRole::SpinButton] = "SpinButton";
    values[System::Windows::Forms::AccessibleRole::Diagram] = "Diagram";
    values[System::Windows::Forms::AccessibleRole::Animation] = "Animation";
    values[System::Windows::Forms::AccessibleRole::Equation] = "Equation";
    values[System::Windows::Forms::AccessibleRole::ButtonDropDown] = "ButtonDropDown";
    values[System::Windows::Forms::AccessibleRole::ButtonMenu] = "ButtonMenu";
    values[System::Windows::Forms::AccessibleRole::ButtonDropDownGrid] = "ButtonDropDownGrid";
    values[System::Windows::Forms::AccessibleRole::WhiteSpace] = "WhiteSpace";
    values[System::Windows::Forms::AccessibleRole::PageTabList] = "PageTabList";
    values[System::Windows::Forms::AccessibleRole::Clock] = "Clock";
    values[System::Windows::Forms::AccessibleRole::Default] = "Default";
    values[System::Windows::Forms::AccessibleRole::SplitButton] = "SplitButton";
    values[System::Windows::Forms::AccessibleRole::IpAddress] = "IpAddress";
    values[System::Windows::Forms::AccessibleRole::OutlineButton] = "OutlineButton";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
