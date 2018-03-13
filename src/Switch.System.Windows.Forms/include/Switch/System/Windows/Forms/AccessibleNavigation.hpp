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
