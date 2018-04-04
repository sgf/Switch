/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include <Switch/System/Drawing/Color.hpp>
#include <Switch/System/Drawing/Font.hpp>
#include <Switch/System/EventHandler.hpp>
#include "../../../System/Windows/Forms/CommonDialog.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Prompts the user to choose a font from among those installed on the local computer.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The inherited member ShowDialog must be invoked to create this specific common dialog box. HookProc can be overridden to implement specific dialog box hook functionality.
        /// @remarks When you create an instance of FontDialog, some of the read/write properties are set to initial values. For a list of these values, see the FontDialog constructor.
        /// @par Examples
        /// The following code example uses ShowDialog to display a FontDialog. This code requires that a Form has already been created with a TextBox and button placed on it. It also requires that the fontDialog1 has been created. The Font contains the size information but not the color information.
        /// @code
        /// void button1_Click(const object& sender, const System::EventArgs& e) {
        ///   fontDialog1.ShowColor = true;
        ///
        ///   fontDialog1.Font = textBox1.Font;
        ///   fontDialog1.Color = textBox1.ForeColor;
        ///
        ///   if (fontDialog1.ShowDialog() != DialogResult::Cancel) {
        ///     textBox1.Font = fontDialog1.Font ;
        ///     textBox1.ForeColor = fontDialog1.Color;
        ///   }
        /// }
        /// @endcode
        class system_windows_forms_export_ FontDialog : public CommonDialog {
        public:
          /// @brief Initializes a new instance of the FontDialog class.
          /// @remarks When you create an instance of FontDialog, the following read/write properties are initialized.
          /// | Property           | Initial value                 |
          /// |--------------------|-------------------------------|
          /// | AllowScriptChange  | true                          |
          /// | AllowSimulations   | true                          |
          /// | AllowVectorFonts   | true                          |
          /// | AllowVerticalFonts | true                          |
          /// | Color              | System::Drawing::Color::Black |
          /// | FixedPitchOnly     | false                         |
          /// | MaxSize            | 0                             |
          /// | MinSize            | 0                             |
          /// | ScriptOnly         | false                         |
          /// | ShowApply          | false                         |
          /// | ShowColor          | false                         |
          /// | ShowEffects        | true                          |
          /// | ShowHelp           | false                         |
          /// @remarks You can change the value for any of these properties through a separate call to the property.
          FontDialog();

          /// @brief Gets or sets a value indicating whether the user can change the character set specified in the Script combo box to display a character set other than the one currently displayed.
          /// @return bool true if the user can change the character set specified in the Script combo box; otherwise, false. The default value is true.
          /// @remarks The Script combo box found on the Font dialog box contains character sets associated with the selected font.
          property_<bool> AllowScriptChange {
            get_ {return this->allowScriptChange;},
            set_ {this->allowScriptChange = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box allows graphics device interface (GDI) font simulations.
          /// @return bool true if font simulations are allowed; otherwise, false. The default value is true.
          property_<bool> AllowSimulations {
            get_ {return this->allowSimulations;},
            set_ {this->allowSimulations = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box allows vector font selections.
          /// @return bool true if vector fonts are allowed; otherwise, false. The default value is true.
          property_<bool> AllowVectorFonts {
            get_ {return this->allowVectorFonts;},
            set_ {this->allowVectorFonts = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box displays both vertical and horizontal fonts or only horizontal fonts.
          /// @return bool true if both vertical and horizontal fonts are allowed; otherwise, false. The default value is true.
          property_<bool> AllowVerticalFonts {
            get_ {return this->allowVerticalFonts;},
            set_ {this->allowVerticalFonts = value;}
          };

          /// @brief Gets or sets the selected font color.
          /// @return System::Drawing::Color The color of the selected font. The default value is Black.
          /// @par Examples
          /// The following code example uses ShowDialog to display a FontDialog. This code requires that a Form has already been created with a TextBox and button placed on it. It also requires that the fontDialog1 has been created. The Font contains the size information but not the color information.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   fontDialog1.ShowColor = true;
          ///
          ///   fontDialog1.Font = textBox1.Font;
          ///   fontDialog1.Color = textBox1.ForeColor;
          ///
          ///   if (fontDialog1.ShowDialog() != DialogResult::Cancel) {
          ///     textBox1.Font = fontDialog1.Font ;
          ///     textBox1.ForeColor = fontDialog1.Color;
          ///   }
          /// }
          /// @endcode
          property_<System::Drawing::Color> Color {
            get_ {return this->color;},
            set_ {this->color = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box allows only the selection of fixed-pitch fonts.
          /// @return bool true if only fixed-pitch fonts can be selected; otherwise, false. The default value is false.
          property_<bool> FixedPitchOnly {
            get_ {return this->fixedPitchOnly;},
            set_ {this->fixedPitchOnly = value;}
          };

          /// @brief Gets or sets the selected font.
          /// @return System::Drawing::font The selected font.
          /// @par Examples
          /// The following code example uses ShowDialog to display a FontDialog. This code requires that a Form has already been created with a TextBox and button placed on it. It also requires that the fontDialog1 has been created. The Font contains the size information but not the color information.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   fontDialog1.ShowColor = true;
          ///
          ///   fontDialog1.Font = textBox1.Font;
          ///   fontDialog1.Color = textBox1.ForeColor;
          ///
          ///   if (fontDialog1.ShowDialog() != DialogResult::Cancel) {
          ///     textBox1.Font = fontDialog1.Font ;
          ///     textBox1.ForeColor = fontDialog1.Color;
          ///   }
          /// }
          /// @endcode
          property_<System::Drawing::Font> Font {
            get_ {return this->font;},
            set_ {this->font = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box specifies an error condition if the user attempts to select a font or style that does not exist.
          /// @return bool true if the dialog box specifies an error condition when the user tries to select a font or style that does not exist; otherwise, false. The default is false.
          /// @par Examples
          /// The following code example demonstrates using the MinSize, MaxSize, ShowEffects and FontMustExist members and handling the Apply event. To run this example paste the following code in a form containing a FontDialog named fontDialog1 and a Button named Button1.
          /// @code
          /// void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
          ///   // Set FontMustExist to true, which causes message box error
          ///   // if the user enters a font that does not exist.
          ///   fontDialog1.FontMustExist = true;
          ///
          ///   // Associate the method handling the Apply event with the event.
          ///   fontDialog1.Apply += System::EventHandler(*this, &Form1::FontDialog1_Apply);
          ///
          ///   // Set a minimum and maximum size to be
          ///   // shown in the FontDialog.
          ///   fontDialog1.MaxSize = 32;
          ///   fontDialog1.MinSize = 18;
          ///
          ///   // Show the Apply button in the dialog.
          ///   fontDialog1.ShowApply = true;
          ///
          ///   // Do not show effects such as Underline
          ///   // and Bold.
          ///   fontDialog1.ShowEffects = false;
          ///
          ///   // Save the existing font.
          ///   System::Drawing::Font oldFont = this->Font;
          ///
          ///   //Show the dialog, and get the result
          ///   DialogResult result = fontDialog1.ShowDialog();
          ///
          ///   // If the OK button in the Font dialog box is clicked,
          ///   // set all the controls' fonts to the chosen font by calling
          ///   // the FontDialog1_Apply method.
          ///   if (result == DialogResult::OK) {
          ///     FontDialog1_Apply(this->Button1, System.EventArgs());
          ///   }
          ///   // If Cancel is clicked, set the font back to
          ///   // the original font.
          ///   else if (result == DialogResult::Cancel) {
          ///     this.Font = oldFont;
          ///     for (ref<Control> containedControl : this->Controls()) {
          ///       containedControl.Font = oldFont;
          ///     }
          ///   }
          /// }
          ///
          /// // Handle the Apply event by setting all controls' fonts to
          /// // the chosen font.
          /// void FontDialog1_Apply(const object& sender, const System::EventArgs& e) {
          ///   this->Font = fontDialog1.Font;
          ///   for (ref<Control> containedControl : this->Controls()) {
          ///     containedControl.Font = fontDialog1.Font;
          ///   }
          /// }
          /// @endcode
          property_<bool> FontMustExist {
            get_ {return this->fontMustExist;},
            set_ {this->fontMustExist = value;}
          };

          /// @brief Gets or sets the maximum point size a user can select.
          /// @return int32 The maximum point size a user can select. The default is 0.
          /// @remarks In order for the maximum and minimum size settings to take effect, MaxSize must be greater than MinSize, and both must be greater than 0.
          /// @remarks Attempts to set this property to values less than 0 will result in a value of 0 being used. If you set MaxSize to a value less than MinSize, MinSize is set to MaxSize. The effect of setting MinSize and MaxSize to the same values is to limit the size selection to a single font size.
          /// @remarks When the point size is 0, there are no font size limits.
          /// @par Examples
          /// The following code example demonstrates using the MinSize, MaxSize, ShowEffects and FontMustExist members and handling the Apply event. To run this example paste the following code in a form containing a FontDialog named fontDialog1 and a Button named Button1.
          /// @code
          /// void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
          ///   // Set FontMustExist to true, which causes message box error
          ///   // if the user enters a font that does not exist.
          ///   fontDialog1.FontMustExist = true;
          ///
          ///   // Associate the method handling the Apply event with the event.
          ///   fontDialog1.Apply += System::EventHandler(*this, &Form1::FontDialog1_Apply);
          ///
          ///   // Set a minimum and maximum size to be
          ///   // shown in the FontDialog.
          ///   fontDialog1.MaxSize = 32;
          ///   fontDialog1.MinSize = 18;
          ///
          ///   // Show the Apply button in the dialog.
          ///   fontDialog1.ShowApply = true;
          ///
          ///   // Do not show effects such as Underline
          ///   // and Bold.
          ///   fontDialog1.ShowEffects = false;
          ///
          ///   // Save the existing font.
          ///   System::Drawing::Font oldFont = this->Font;
          ///
          ///   //Show the dialog, and get the result
          ///   DialogResult result = fontDialog1.ShowDialog();
          ///
          ///   // If the OK button in the Font dialog box is clicked,
          ///   // set all the controls' fonts to the chosen font by calling
          ///   // the FontDialog1_Apply method.
          ///   if (result == DialogResult::OK) {
          ///     FontDialog1_Apply(this->Button1, System.EventArgs());
          ///   }
          ///   // If Cancel is clicked, set the font back to
          ///   // the original font.
          ///   else if (result == DialogResult::Cancel) {
          ///     this.Font = oldFont;
          ///     for (ref<Control> containedControl : this->Controls()) {
          ///       containedControl.Font = oldFont;
          ///     }
          ///   }
          /// }
          ///
          /// // Handle the Apply event by setting all controls' fonts to
          /// // the chosen font.
          /// void FontDialog1_Apply(const object& sender, const System::EventArgs& e) {
          ///   this->Font = fontDialog1.Font;
          ///   for (ref<Control> containedControl : this->Controls()) {
          ///     containedControl.Font = fontDialog1.Font;
          ///   }
          /// }
          /// @endcode
          property_<int32> MaxSize {
            get_ {return this->maxSize;},
            set_ {this->maxSize = value;}
          };

          /// @brief Gets or sets the minimum point size a user can select.
          /// @return int32 The minimum point size a user can select. The default is 0.
          /// @remarks In order for the maximum and minimum size settings to take effect, MaxSize must be greater than MinSize, and both must be greater than 0.
          /// @remarks Attempts to set this property to values less than 0 will result in a value of 0 being used. If you set MinSize to a value greater than MaxSize, MaxSize is set to the value of MinSize. The effect of setting MinSize and MaxSize to the same value is to limit the size selection to a single font size.
          /// @remarks When the point size is 0, there are no font size limits.
          /// @par Examples
          /// The following code example demonstrates using the MinSize, MaxSize, ShowEffects and FontMustExist members and handling the Apply event. To run this example paste the following code in a form containing a FontDialog named fontDialog1 and a Button named Button1.
          /// @code
          /// void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
          ///   // Set FontMustExist to true, which causes message box error
          ///   // if the user enters a font that does not exist.
          ///   fontDialog1.FontMustExist = true;
          ///
          ///   // Associate the method handling the Apply event with the event.
          ///   fontDialog1.Apply += System::EventHandler(*this, &Form1::FontDialog1_Apply);
          ///
          ///   // Set a minimum and maximum size to be
          ///   // shown in the FontDialog.
          ///   fontDialog1.MaxSize = 32;
          ///   fontDialog1.MinSize = 18;
          ///
          ///   // Show the Apply button in the dialog.
          ///   fontDialog1.ShowApply = true;
          ///
          ///   // Do not show effects such as Underline
          ///   // and Bold.
          ///   fontDialog1.ShowEffects = false;
          ///
          ///   // Save the existing font.
          ///   System::Drawing::Font oldFont = this->Font;
          ///
          ///   //Show the dialog, and get the result
          ///   DialogResult result = fontDialog1.ShowDialog();
          ///
          ///   // If the OK button in the Font dialog box is clicked,
          ///   // set all the controls' fonts to the chosen font by calling
          ///   // the FontDialog1_Apply method.
          ///   if (result == DialogResult::OK) {
          ///     FontDialog1_Apply(this->Button1, System.EventArgs());
          ///   }
          ///   // If Cancel is clicked, set the font back to
          ///   // the original font.
          ///   else if (result == DialogResult::Cancel) {
          ///     this.Font = oldFont;
          ///     for (ref<Control> containedControl : this->Controls()) {
          ///       containedControl.Font = oldFont;
          ///     }
          ///   }
          /// }
          ///
          /// // Handle the Apply event by setting all controls' fonts to
          /// // the chosen font.
          /// void FontDialog1_Apply(const object& sender, const System::EventArgs& e) {
          ///   this->Font = fontDialog1.Font;
          ///   for (ref<Control> containedControl : this->Controls()) {
          ///     containedControl.Font = fontDialog1.Font;
          ///   }
          /// }
          /// @endcode
          property_<int32> MinSize {
            get_ {return this->minSize;},
            set_ {this->minSize = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box allows selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set.
          /// @return bool true if selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set, is allowed; otherwise, false. The default value is false.
          property_<bool> ScriptOnly {
            get_ {return this->scriptOnly;},
            set_ {this->scriptOnly = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box contains an Apply button.
          /// @return bool true if the dialog box contains an Apply button; otherwise, false. The default value is false.
          /// @par Examples
          /// The following code example shows how to apply the selections in a FontDialog to the text in a RichTextBox. In the event handler that displays the dialog box, the example initializes the ShowApply property to true and then displays the FontDialog. In the Apply event handler, the Font property is assigned to the Control.Font property.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   // Sets the ShowApply property, then displays the dialog.
          ///   fontDialog1.ShowApply = true;
          ///   fontDialog1.ShowDialog();
          /// }
          ///
          /// void fontDialog1_Apply(const object& sender, const System::EventArgs& e) {
          ///   // Applies the selected font to the selected text.
          ///   richTextBox1.Font = fontDialog1.Font;
          /// }
          /// @endcode
          property_<bool> ShowApply {
            get_ {return this->showApply;},
            set_ {this->showApply = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box displays the color choice.
          /// @return bool true if the dialog box displays the color choice; otherwise, false. The default value is false.
          /// @par Examples
          /// The following code example uses ShowDialog to display a FontDialog. This code requires that a Form has already been created with a TextBox and button placed on it. It also requires that the fontDialog1 has been created. The Font contains the size information but not the color information.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   fontDialog1.ShowColor = true;
          ///
          ///   fontDialog1.Font = textBox1.Font;
          ///   fontDialog1.Color = textBox1.ForeColor;
          ///
          ///   if (fontDialog1.ShowDialog() != DialogResult::Cancel) {
          ///     textBox1.Font = fontDialog1.Font ;
          ///     textBox1.ForeColor = fontDialog1.Color;
          ///   }
          /// }
          /// @endcode
          property_<bool> ShowColor {
            get_ {return this->showColor;},
            set_ {this->showColor = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box contains controls that allow the user to specify strikethrough, underline, and text color options.
          /// @return bool true if the dialog box contains controls to set strikethrough, underline, and text color options; otherwise, false. The default value is true.
          /// @par Examples
          /// The following code example demonstrates using the MinSize, MaxSize, ShowEffects and FontMustExist members and handling the Apply event. To run this example paste the following code in a form containing a FontDialog named fontDialog1 and a Button named Button1.
          /// @code
          /// void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
          ///   // Set FontMustExist to true, which causes message box error
          ///   // if the user enters a font that does not exist.
          ///   fontDialog1.FontMustExist = true;
          ///
          ///   // Associate the method handling the Apply event with the event.
          ///   fontDialog1.Apply += System::EventHandler(*this, &Form1::FontDialog1_Apply);
          ///
          ///   // Set a minimum and maximum size to be
          ///   // shown in the FontDialog.
          ///   fontDialog1.MaxSize = 32;
          ///   fontDialog1.MinSize = 18;
          ///
          ///   // Show the Apply button in the dialog.
          ///   fontDialog1.ShowApply = true;
          ///
          ///   // Do not show effects such as Underline
          ///   // and Bold.
          ///   fontDialog1.ShowEffects = false;
          ///
          ///   // Save the existing font.
          ///   System::Drawing::Font oldFont = this->Font;
          ///
          ///   //Show the dialog, and get the result
          ///   DialogResult result = fontDialog1.ShowDialog();
          ///
          ///   // If the OK button in the Font dialog box is clicked,
          ///   // set all the controls' fonts to the chosen font by calling
          ///   // the FontDialog1_Apply method.
          ///   if (result == DialogResult::OK) {
          ///     FontDialog1_Apply(this->Button1, System.EventArgs());
          ///   }
          ///   // If Cancel is clicked, set the font back to
          ///   // the original font.
          ///   else if (result == DialogResult::Cancel) {
          ///     this.Font = oldFont;
          ///     for (ref<Control> containedControl : this->Controls()) {
          ///       containedControl.Font = oldFont;
          ///     }
          ///   }
          /// }
          ///
          /// // Handle the Apply event by setting all controls' fonts to
          /// // the chosen font.
          /// void FontDialog1_Apply(const object& sender, const System::EventArgs& e) {
          ///   this->Font = fontDialog1.Font;
          ///   for (ref<Control> containedControl : this->Controls()) {
          ///     containedControl.Font = fontDialog1.Font;
          ///   }
          /// }
          /// @endcode
          property_<bool> ShowEffects {
            get_ {return this->showEffects;},
            set_ {this->showEffects = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box displays a Help button.
          /// @return bool true if the dialog box displays a Help button; otherwise, false. The default value is false.
          property_<bool> ShowHelp {
            get_ {return this->showHelp;},
            set_ {this->showHelp = value;}
          };

          /// @brief Occurs when the user clicks the Apply button in the font dialog box.
          /// @remarks Every time the Apply button is clicked, another Apply event is raised.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example demonstrates using the MinSize, MaxSize, ShowEffects and FontMustExist members and handling the Apply event. To run this example paste the following code in a form containing a FontDialog named fontDialog1 and a Button named Button1.
          /// @code
          /// void Button1_Click(const System::Object& sender, const System::EventArgs& e) {
          ///   // Set FontMustExist to true, which causes message box error
          ///   // if the user enters a font that does not exist.
          ///   fontDialog1.FontMustExist = true;
          ///
          ///   // Associate the method handling the Apply event with the event.
          ///   fontDialog1.Apply += System::EventHandler(*this, &Form1::FontDialog1_Apply);
          ///
          ///   // Set a minimum and maximum size to be
          ///   // shown in the FontDialog.
          ///   fontDialog1.MaxSize = 32;
          ///   fontDialog1.MinSize = 18;
          ///
          ///   // Show the Apply button in the dialog.
          ///   fontDialog1.ShowApply = true;
          ///
          ///   // Do not show effects such as Underline
          ///   // and Bold.
          ///   fontDialog1.ShowEffects = false;
          ///
          ///   // Save the existing font.
          ///   System::Drawing::Font oldFont = this->Font;
          ///
          ///   //Show the dialog, and get the result
          ///   DialogResult result = fontDialog1.ShowDialog();
          ///
          ///   // If the OK button in the Font dialog box is clicked,
          ///   // set all the controls' fonts to the chosen font by calling
          ///   // the FontDialog1_Apply method.
          ///   if (result == DialogResult::OK) {
          ///     FontDialog1_Apply(this->Button1, System.EventArgs());
          ///   }
          ///   // If Cancel is clicked, set the font back to
          ///   // the original font.
          ///   else if (result == DialogResult::Cancel) {
          ///     this.Font = oldFont;
          ///     for (ref<Control> containedControl : this->Controls()) {
          ///       containedControl.Font = oldFont;
          ///     }
          ///   }
          /// }
          ///
          /// // Handle the Apply event by setting all controls' fonts to
          /// // the chosen font.
          /// void FontDialog1_Apply(const object& sender, const System::EventArgs& e) {
          ///   this->Font = fontDialog1.Font;
          ///   for (ref<Control> containedControl : this->Controls()) {
          ///     containedControl.Font = fontDialog1.Font;
          ///   }
          /// }
          /// @endcode
          EventHandler Apply;

          /// @brief When overridden in a derived class, resets the properties of a common dialog box to their default values.
          void Reset() override;

        protected:
          /// @cond
          bool allowScriptChange = true;
          bool allowSimulations = true;
          bool allowVectorFonts  = true;
          bool allowVerticalFonts = true;
          System::Drawing::Color color;
          bool fixedPitchOnly = false;
          System::Drawing::Font font;
          bool fontMustExist = false;
          int32 maxSize = 0;
          int32 minSize = 0;
          bool scriptOnly = false;
          bool showApply = false;
          bool showColor = false;
          bool showEffects = true;
          bool showHelp = false;
          /// @endcond

        private:
          bool RunDialog(intptr hwndOwner) override;
        };
      }
    }
  }
}
