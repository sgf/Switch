/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the border style for a control.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks Use the members of this enumeration to set the border style for controls that have a changeable border.
        /// @par Examples
        /// The following code example demonstrates how to use the BorderStyle enumeration and the TreeView.BorderStyle, TreeView.HideSelection and the TreeView.ShowRootLines properties. To run this example, paste the following code in a form and call the InitializeTreeView method in the form's constructor or Load method.
        /// @code
        /// // Declare the TreeView control.
        /// System::Windows::Forms::TreeView treeView1;
        ///
        /// // Initialize the TreeView to blend with the form, giving it the
        /// // same color as the form and no border.
        /// void InitializeTreeView() {
        ///   // Create a new TreeView control and set the location and size.
        ///   this->treeView1.Location = System::Drawing::Point(72, 48);
        ///   this->treeView1.Size = System::Drawing::Size(200, 200);
        ///
        ///   // Set the BorderStyle property to none, the BackColor property to
        ///   // the form's backcolor, and the Scrollable property to false.
        ///   // This allows the TreeView to blend in form.
        ///
        ///   this->treeView1.BorderStyle = BorderStyle::None;
        ///   this->treeView1.BackColor = this->BackColor;
        ///   this->treeView1.Scrollable = false;
        ///
        ///   // Set the HideSelection property to false to keep the
        ///   // selection highlighted when the user leaves the control.
        ///   // This helps it blend with form.
        ///   this->treeView1.HideSelection = false;
        ///
        ///   // Set the ShowRootLines and ShowLines properties to false to
        ///   // give the TreeView a list-like appearance.
        ///   this->treeView1.ShowRootLines = false;
        ///   this->treeView1.ShowLines = false;
        ///
        ///   // Add the nodes.
        ///   this->treeView1.Nodes.AddRange(Array<TreeNode>
        ///                                  {TreeNode("Features",
        ///                                            Array<TreeNode> {
        ///                                              TreeNode("Full Color"),
        ///                                              TreeNode("Project Wizards"),
        ///                                              TreeNode("Visual C# and Visual Basic Support")}),
        ///                                    TreeNode("System Requirements",
        ///                                             Array<TreeNode>{
        ///                                               TreeNode("Pentium 133 MHz or faster processor "),
        ///                                               TreeNode("Windows 98 or later"),
        ///                                               TreeNode("100 MB Disk space")})
        ///                                  });
        ///
        ///   // Set the tab index and add the TreeView to the form.
        ///   this->treeView1.TabIndex = 0;
        ///   this->Controls().Add(this->treeView1);
        /// }
        /// @endcode
        enum class BorderStyle {
          /// @brief No border.
          None = 0,
          /// @brief A single-line border.
          FixedSingle = 1,
          /// @brief A three-dimensional border.
          Fixed3D = 2,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::BorderStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::BorderStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::BorderStyle::None] = "None";
    values[System::Windows::Forms::BorderStyle::FixedSingle] = "FixedSingle";
    values[System::Windows::Forms::BorderStyle::Fixed3D] = "Fixed3D";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
