/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the state of a control, such as a check box, that can be checked, unchecked, or set to an indeterminate state.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks Multiple methods in CheckBox, CheckedListBox, and ItemCheckEventArgs use this enumeration.
        /// @note Use an indeterminately checked control when you do not want to set a default value.
        /// @par Examples
        /// The following code example demonstrates the use of the CheckState enumeration.
        /// @code
        /// namespace WindowsApplication1 {
        ///   using namespace System;
        ///   using namespace System::Drawing;
        ///   using namespace System::Collections;
        ///   using namespace System::Collections::Generic;
        ///   using namespace System::ComponentModel;
        ///   using namespace System::Windows::Forms;
        ///   using namespace System::Data;
        ///   using namespace System::IO ;
        ///
        ///   class Form1 : public System::Windows::Forms::Form {
        ///   private:
        ///     System::Windows::Forms::CheckedListBox checkedListBox1;
        ///     System::Windows::Forms::TextBox textBox1;
        ///     System::Windows::Forms::Button button1;
        ///     System::Windows::Forms::Button button2;
        ///     System::Windows::Forms::ListBox listBox1;
        ///     System::Windows::Forms::Button button3;
        ///     System::ComponentModel::Container components;
        ///
        ///   public:
        ///     Form1() {
        ///       InitializeComponent();
        ///
        ///       // Sets up the initial objects in the CheckedListBox.
        ///       Array<strin> myFruit = {"Apples", "Oranges","Tomato"};
        ///       checkedListBox1.Items().AddRange(myFruit);
        ///
        ///       // Changes the selection mode from double-click to single click.
        ///       checkedListBox1.CheckOnClick = true;
        ///     }
        ///
        ///   private:
        ///     void InitializeComponent() {
        ///       this->textBox1.Location = System::Drawing::Point(144, 64);
        ///       this->textBox1.Size = System::Drawing::Size(128, 20);
        ///       this->textBox1.TabIndex = 1;
        ///       this->textBox1.TextChanged += System::EventHandler(*this, @Form1::textBox1_TextChanged);
        ///       this->checkedListBox1.Location = System::Drawing::Point(16, 64);
        ///       this->checkedListBox1.Size = System::Drawing::Size(120, 184);
        ///       this->checkedListBox1.TabIndex = 0;
        ///       this->checkedListBox1.ItemCheck += System::Windows::Forms::ItemCheckEventHandler(*this, &Form1::checkedListBox1_ItemCheck);
        ///       this->listBox1.Location = System::Drawing::Point(408, 64);
        ///       this->listBox1.Size = System::Drawing::Size(128, 186);
        ///       this->listBox1.TabIndex = 3;
        ///       this->button1.Enabled = false;
        ///       this->button1.Location = System::Drawing::Point(144, 104);
        ///       this->button1.Size = System::Drawing::Size(104, 32);
        ///       this->button1.TabIndex = 2;
        ///       this->button1.Text = "Add Fruit";
        ///       this->button1.Click += System::EventHandler(*this, &Form1::button1_Click);
        ///       this->button2.Enabled = false;
        ///       this->button2.Location = System::Drawing::Point(288, 64);
        ///       this->button2.Size = System::Drawing::Size(104, 32);
        ///       this->button2.TabIndex = 2;
        ///       this->button2.Text = "Show Order";
        ///       this->button2.Click += System::EventHandler(*this, &Form1::button2_Click);
        ///       this->button3.Enabled = false;
        ///       this->button3.Location = System::Drawing::Point(288, 104);
        ///       this->button3.Size = System::Drawing::Size(104, 32);
        ///       this->button3.TabIndex = 2;
        ///       this->button3.Text = "Save Order";
        ///       this->button3.Click += System::EventHandler(*this, &Form1::button3_Click);
        ///       this->ClientSize = System::Drawing::Size(563, 273);
        ///       this->Controls.AddRange(Array<System::Windows::Forms::Control> {this->listBox1,
        ///         this->button3,
        ///         this->button2,
        ///         this->button1,
        ///         this->textBox1,
        ///         this->checkedListBox1});
        ///       this->Text = "Fruit Order";
        ///     }
        ///
        ///   public:
        ///     static void Main(Array<string> args) {
        ///       Application::Run(Form1());
        ///     }
        ///
        ///   private:
        ///     // Adds the string if the text box has data in it.
        ///     void button1_Click(const object& sender, const System::EventArgs& e) {
        ///       if(textBox1.Text != "") {
        ///         if(checkedListBox1.CheckedItems().Contains(textBox1.Text) == false)
        ///           checkedListBox1.Items().Add(textBox1.Text, CheckState::Checked);
        ///         textBox1.Text = "";
        ///       }
        ///
        ///     }
        ///     // Activates or deactivates the Add button.
        ///     void textBox1_TextChanged(const object& sender, const System::EventArgs& e) {
        ///       if (textBox1.Text == "") {
        ///         button1.Enabled = false;
        ///       } else {
        ///         button1.Enabled = true;
        ///       }
        ///     }
        ///
        ///     // Moves the checked items from the CheckedListBox to the listBox.
        ///     void button2_Click(const object& sender, const System::EventArgs& e) {
        ///       listBox1.Items().Clear();
        ///       button3.Enabled = false;
        ///       for (int i = 0; i< checkedListBox1.CheckedItems().Count; i++) {
        ///         listBox1.Items().Add(checkedListBox1.CheckedItems()[i]);
        ///       }
        ///       if (listBox1.Items().Count > 0)
        ///         button3.Enabled = true;
        ///     }
        ///
        ///     // Activates the move button if there are checked items.
        ///     void checkedListBox1_ItemCheck(const object& sender, const ItemCheckEventArgs& e) {
        ///       if (e.NewValue == CheckState::Unchecked) {
        ///         if(checkedListBox1.CheckedItems().Count==1) {
        ///           button2.Enabled = false;
        ///         }
        ///       } else {
        ///         button2.Enabled = true;
        ///       }
        ///     }
        ///
        ///     // Saves the items to a file.
        ///     void button3_Click(const object& sender, const System::EventArgs& e) {
        ///       // Insert code to save a file.
        ///       listBox1.Items().Clear();
        ///       Enumerator<bool> myEnumerator;
        ///       myEnumerator = checkedListBox1.CheckedIndices().GetEnumerator();
        ///       int y;
        ///       while (myEnumerator.MoveNext() != false) {
        ///         y = (int)myEnumerator.Current;
        ///         checkedListBox1.SetItemChecked(y, false);
        ///       }
        ///       button3.Enabled = false ;
        ///     }
        ///   }
        /// }
        /// @endcode
        enum class CheckState {
          /// @brief The control is unchecked.
          Unchecked = 0,
          /// @brief The control is checked.
          Checked = 1,
          /// @brief The control is indeterminate. An indeterminate control generally has a shaded appearance.
          Indeterminate = 2,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::CheckState> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::CheckState, string>& values, bool& flags) {
    values[System::Windows::Forms::CheckState::Unchecked] = "Unchecked";
    values[System::Windows::Forms::CheckState::Checked] = "Checked";
    values[System::Windows::Forms::CheckState::Indeterminate] = "Indeterminate";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
