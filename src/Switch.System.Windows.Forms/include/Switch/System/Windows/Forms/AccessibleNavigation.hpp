/// @file
/// @brief Contains Switch::System::Windows::Forms::AccessibleNavigation enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies values for navigating among accessible objects.
        /// @remarks Accessible navigation directions are either spatial (up, down, left, and right) or logical (first child, last child, next, and previous). Logical directions are used when clients navigate from one user interface element to another within the same container.
        /// @remarks AccessibleObject uses this enumeration.
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
        enum class AccessibleNavigation {
          /// @brief Navigation to a sibling object located above the starting object.
          Up = 1,
          /// @brief Navigation to a sibling object located below the starting object.
          Down = 2,
          /// @brief Navigation to the sibling object located to the left of the starting object.
          Left = 3,
          /// @brief Navigation to the sibling object located to the right of the starting object.
          Right = 4,
          /// @brief Navigation to the next logical object, typically from a sibling object to the starting object.
          Next = 5,
          /// @brief Navigation to the previous logical object, typically from a sibling object to the starting object.
          Previous = 6,
          /// @brief Navigation to the first child of the object.
          FirstChild = 7,
          /// @brief Navigation to the last child of the object.
          LastChild = 8,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::AccessibleNavigation> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AccessibleNavigation, string>& values, bool& flags) {
    values[System::Windows::Forms::AccessibleNavigation::Up] = "Up";
    values[System::Windows::Forms::AccessibleNavigation::Down] = "Down";
    values[System::Windows::Forms::AccessibleNavigation::Left] = "Left";
    values[System::Windows::Forms::AccessibleNavigation::Right] = "Right";
    values[System::Windows::Forms::AccessibleNavigation::Next] = "Next";
    values[System::Windows::Forms::AccessibleNavigation::Previous] = "Previous";
    values[System::Windows::Forms::AccessibleNavigation::FirstChild] = "FirstChild";
    values[System::Windows::Forms::AccessibleNavigation::LastChild] = "LastChild";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
