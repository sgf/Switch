/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include <Switch/System/Drawing/Color.hpp>
#include "../../../System/Windows/Forms/CommonDialog.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The inherited member ShowDialog must be invoked to create this specific common dialog box. HookProc can be overridden to implement specific dialog box hook functionality. Use Color to retrieve the color selected by the user.
        /// @remarks When you create an instance of ColorDialog, some of the read/write properties are set to initial values. For a list of these values, see the ColorDialog constructor.
        /// @par Examples
        /// The following example illustrates the creation of new ColorDialog. This example requires that the method is called from within an existing form that has a TextBox and Button placed on it.
        /// @code
        /// void button1_Click(const object& sender, const System::EventArgs& e) {
        ///   ColorDialog myDialog;
        ///   // Keeps the user from selecting a custom color.
        ///   myDialog.AllowFullOpen = false ;
        ///   // Allows the user to get help. (The default is false.)
        ///   myDialog.ShowHelp = true;
        ///   // Sets the initial color select to the current text color.
        ///   myDialog.Color = this->textBox1.ForeColor ;
        ///
        ///   // Update the text box color if the user clicks OK
        ///   if (myDialog.ShowDialog() == DialogResult::OK)
        ///     textBox1.ForeColor =  myDialog.Color;
        /// }
        /// @endcode
        class system_windows_forms_export_ ColorDialog : public CommonDialog {
        public:
          /// @brief Initializes a new instance of the ColorDialog class.
          /// @remarks When you create an instance of ColorDialog, the following read/write properties are set to initial values.
          /// | Property       | Initial alue |
          /// |----------------|--------------|
          /// | AllowFullOpen  | true         |
          /// | AnyColor       | false        |
          /// | Color          | Color::Black |
          /// | CustomColors   | Empty        |
          /// | FullOpen       | false        |
          /// | ShowHelp       | false        |
          /// | SolidColorOnly | false        |
          /// You can change the value for any of these properties through a separate call to the property.
          ColorDialog();

          /// @brief Gets or sets a value indicating whether the user can use the dialog box to define custom colors.
          /// @return bool true if the user can define custom colors; otherwise, false. The default is true.
          /// @remarks When set to false, the associated button in the dialog box is disabled and the user cannot access the custom colors control in the dialog box.
          /// @par Examples
          /// The following example illustrates the creation of new ColorDialog. This example requires that the method is called from within an existing form that has a TextBox and Button placed on it.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   ColorDialog myDialog;
          ///   // Keeps the user from selecting a custom color.
          ///   myDialog.AllowFullOpen = false ;
          ///   // Allows the user to get help. (The default is false.)
          ///   myDialog.ShowHelp = true;
          ///   // Sets the initial color select to the current text color.
          ///   myDialog.Color = this->textBox1.ForeColor ;
          ///
          ///   // Update the text box color if the user clicks OK
          ///   if (myDialog.ShowDialog() == DialogResult::OK)
          ///     textBox1.ForeColor =  myDialog.Color;
          /// }
          /// @endcode
          property_<bool> AllowFullOpen {
            get_ {return this->allowFullOpen;},
            set_ {this->allowFullOpen = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box displays all available colors in the set of basic colors.
          /// @return bool true if the dialog box displays all available colors in the set of basic colors; otherwise, false. The default value is false.
          /// @par Examples
          /// The following code example demonstrates initializing a ColorDialog object setting the AnyColor, AllowFullOpen properties. The ColorDialog object does not allow the user to set a custom color, but it allows the full set of basic colors to be displayed. By setting the SolidColorOnly property to false, it allows the display of colors that are combinations of other colors on systems with 256 or less colors. The example also shows setting the ShowHelp property and handling a HelpRequest event for a dialog box. To run the example, paste the following code in a form and call the InitializeColorDialog method in the form's constructor or Load method. This example requires that the Click event of the button is connected to the event handler defined in the example.
          /// @code
          /// ColorDialog colorDialog1;
          ///
          /// // This method initializes ColorDialog1 to allow any colors,
          /// // and combination colors on systems with 256 colors or less,
          /// // but will not allow the user to set custom colors.  The
          /// // dialog will contain the help button.
          /// void InitializeColorDialog() {
          ///   this->colorDialog1.AllowFullOpen = false;
          ///   this->colorDialog1.AnyColor = true;
          ///   this->colorDialog1.SolidColorOnly = false;
          ///   this->colorDialog1.ShowHelp = true;
          ///
          ///   // Associate the event-handling method with
          ///   // the HelpRequest event.
          ///   this->colorDialog1.HelpRequest += System::EventHandler(*this, &Form1::ColorDialog1_HelpRequest);
          /// }
          ///
          /// // This method opens the dialog and checks the DialogResult value.
          /// // If the result is OK, the text box's background color will be changed
          /// // to the user-selected color.
          /// void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
          ///   DialogResult result = this->colorDialog1.ShowDialog();
          ///   if (result == DialogResult::OK) {
          ///     TextBox1.BackColor = this->colorDialog1.Color;
          ///   }
          /// }
          ///
          /// // This method is called when the HelpRequest event is raised,
          /// // which occurs when the user clicks the Help button on the ColorDialog object.
          /// void ColorDialog1_HelpRequest(const object& sender, const System::EventArgs& e) {
          ///   MessageBox::Show("Please select a color by clicking it. This will change the BackColor property of the TextBox.");
          /// }
          /// @endcode
          property_<bool> AnyColor {
            get_ {return this->anyColor;},
            set_ {this->anyColor = value;}
          };

          /// @brief Gets or sets the color selected by the user.
          /// @return System::Drawing::Color The color selected by the user. If a color is not selected, the default value is black.
          /// @remarks The color selected by the user in the dialog box at run time, as defined in Color structure.
          /// @par Examples
          /// The following example illustrates the creation of new ColorDialog. This example requires that the method is called from within an existing form that has a TextBox and Button placed on it.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   ColorDialog myDialog;
          ///   // Keeps the user from selecting a custom color.
          ///   myDialog.AllowFullOpen = false ;
          ///   // Allows the user to get help. (The default is false.)
          ///   myDialog.ShowHelp = true;
          ///   // Sets the initial color select to the current text color.
          ///   myDialog.Color = this->textBox1.ForeColor ;
          ///
          ///   // Update the text box color if the user clicks OK
          ///   if (myDialog.ShowDialog() == DialogResult::OK)
          ///     textBox1.ForeColor =  myDialog.Color;
          /// }
          /// @endcode
          property_<System::Drawing::Color> Color {
            get_ {return this->color;},
            set_ {this->color = value;}
          };

          /// @brief Gets or sets the set of custom colors shown in the dialog box.
          /// @return Array<System::Drawing::Colors> A set of custom colors shown by the dialog box. The default value is empty.
          /// @remarks Users can create their own set of custom colors. These colors are contained in an Int32 composed of the BGR (blue, green, red) values necessary to create the color. For more information on the structure of this data, see Color.
          /// @remarks Custom colors can only be defined if AllowFullOpen is set to true.
          /// @par Examples
          /// The following code example shows how to add an array of type Int32 representing custom colors to CustomColors. This example requires that the code is run from within a Form.
          /// @code
          /// System::Windows::Forms::ColorDialog myDialog;
          /// // Allows the user to select or edit a custom color.
          /// myDialog.AllowFullOpen = true;
          /// // Assigns an array of custom colors to the CustomColors property
          /// myDialog.CustomColors = Array<System::Drawing::Color> {6916092, 15195440, 16107657, 1836924, 3758726, 12566463, 7526079, 7405793, 6945974, 241502, 2296476, 5130294, 3102017, 7324121, 14993507, 11730944,};
          ///
          /// // Allows the user to get help. (The default is false.)
          /// myDialog.ShowHelp = true;
          /// // Sets the initial color select to the current text color,
          /// // so that if the user cancels out, the original color is restored.
          /// myDialog.Color = this->BackColor;
          /// myDialog.ShowDialog();
          /// this->BackColor =  myDialog.Color;
          /// @endcode
          property_<Array<System::Drawing::Color>&, readonly_> CustomColors {
            get_->Array<System::Drawing::Color>& {return this->customColors;}
          };

          /// @brief Gets or sets a value indicating whether the controls used to create custom colors are visible when the dialog box is opened
          /// @return bool true if the custom color controls are available when the dialog box is opened; otherwise, false. The default value is false.
          /// @remarks By default, the custom color controls are not visible when the dialog box is first opened. You must click the Custom Colors button to display them.
          /// @note If AllowFullOpen is false, then FullOpen has no effect.
          property_<bool> FullOpen {
            get_ {return this->fullOpen;},
            set_ {this->fullOpen = value;}
          };

          /// @brief Gets or sets a value indicating whether a Help button appears in the color dialog box.
          /// @return bool true if the Help button is shown in the dialog box; otherwise, false. The default value is false.
          /// @par Examples
          /// The following code example shows how to add an array of type Int32 representing custom colors to CustomColors. This example requires that the code is run from within a Form.
          /// @code
          /// System::Windows::Forms::ColorDialog myDialog;
          /// // Allows the user to select or edit a custom color.
          /// myDialog.AllowFullOpen = true;
          /// // Assigns an array of custom colors to the CustomColors property
          /// myDialog.CustomColors = Array<System::Drawing::Color> {6916092, 15195440, 16107657, 1836924, 3758726, 12566463, 7526079, 7405793, 6945974, 241502, 2296476, 5130294, 3102017, 7324121, 14993507, 11730944,};
          ///
          /// // Allows the user to get help. (The default is false.)
          /// myDialog.ShowHelp = true;
          /// // Sets the initial color select to the current text color,
          /// // so that if the user cancels out, the original color is restored.
          /// myDialog.Color = this->BackColor;
          /// myDialog.ShowDialog();
          /// this->BackColor =  myDialog.Color;
          /// @endcode
          property_<bool> ShowHelp {
            get_ {return this->showHelp;},
            set_ {this->showHelp = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box will restrict users to selecting solid colors only.
          /// @return bool true if users can select only solid colors; otherwise, false. The default value is false.
          /// @remarks This property is applicable to systems with 256 or fewer colors. On these types of systems, some colors are composites of others.
          /// @par Examples
          /// The following code example demonstrates initializing a ColorDialog object setting the AnyColor, AllowFullOpen properties. The ColorDialog object does not allow the user to set a custom color, but it allows the full set of basic colors to be displayed. By setting the SolidColorOnly property to false, it allows the display of colors that are combinations of other colors on systems with 256 or less colors. The example also shows setting the ShowHelp property and handling a HelpRequest event for a dialog box. To run the example, paste the following code in a form and call the InitializeColorDialog method in the form's constructor or Load method. This example requires that the Click event of the button is connected to the event handler defined in the example.
          /// @code
          /// ColorDialog colorDialog1;
          ///
          /// // This method initializes ColorDialog1 to allow any colors,
          /// // and combination colors on systems with 256 colors or less,
          /// // but will not allow the user to set custom colors.  The
          /// // dialog will contain the help button.
          /// void InitializeColorDialog() {
          ///   this->colorDialog1.AllowFullOpen = false;
          ///   this->colorDialog1.AnyColor = true;
          ///   this->colorDialog1.SolidColorOnly = false;
          ///   this->colorDialog1.ShowHelp = true;
          ///
          ///   // Associate the event-handling method with
          ///   // the HelpRequest event.
          ///   this->colorDialog1.HelpRequest += System::EventHandler(*this, &Form1::ColorDialog1_HelpRequest);
          /// }
          ///
          /// // This method opens the dialog and checks the DialogResult value.
          /// // If the result is OK, the text box's background color will be changed
          /// // to the user-selected color.
          /// void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
          ///   DialogResult result = this->colorDialog1.ShowDialog();
          ///   if (result == DialogResult::OK) {
          ///     TextBox1.BackColor = this->colorDialog1.Color;
          ///   }
          /// }
          ///
          /// // This method is called when the HelpRequest event is raised,
          /// // which occurs when the user clicks the Help button on the ColorDialog object.
          /// void ColorDialog1_HelpRequest(const object& sender, const System::EventArgs& e) {
          ///   MessageBox::Show("Please select a color by clicking it. This will change the BackColor property of the TextBox.");
          /// }
          /// @endcode
          property_<bool> SolidColorOnly {
            get_ {return this->solidColorOnly;},
            set_ {this->solidColorOnly = value;}
          };

          /// @brief When overridden in a derived class, resets the properties of a common dialog box to their default values.
          /// @par Notes to Inheritors
          /// Inheriting classes can override this method to reset their properties.
          virtual void Reset();

          /// @brief When overridden in a derived class, specifies a common dialog box.
          /// @param hwndOwner A value that represents the window handle of the owner window for the common dialog box.
          /// @return bool true if the dialog box was successfully run; otherwise, false.
          /// @remarks This method is invoked when the user of a common dialog box calls ShowDialog, and it must be overridden by inherited classes of CommonDialog to implement a specific common dialog box.
          virtual bool RunDialog(intptr hwndOwner);

        protected:
          /// @cond
          bool allowFullOpen = true;
          bool anyColor = false;
          System::Drawing::Color color;
          Array<System::Drawing::Color> customColors {16};
          bool fullOpen = false;
          bool showHelp = false;
          bool solidColorOnly = false;
          /// @endcond
        };
      }
    }
  }
}
