/// @file
/// @brief Contains Pcf::System::Windows::Forms::Button class.
#pragma once

#include <Pcf/System/Drawing/Color.h>
#include <Pcf/System/Drawing/ContentAlignment.h>
#include <Pcf/System/Drawing/Size.h>

#include "AutoSizeMode.h"
#include "ButtonBase.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        /// @brief Represents a Windows button control.
        /// @remarks A Button can be clicked by using the mouse, ENTER key, or SPACEBAR if the button has focus.
        /// @remarks Set the AcceptButton or CancelButton property of a Form to allow users to click a button by pressing the ENTER or ESC keys even if the button does not have focus. This gives the form the behavior of a dialog box.
        /// @remarks When you display a form using the ShowDialog method, you can use the DialogResult property of a button to specify the return value of ShowDialog.
        /// @remarks You can change the button's appearance. For example, to make it appear flat for a Web look, set the FlatStyle property to FlatStyle.Flat. The FlatStyle property can also be set to FlatStyle.Popup, which appears flat until the mouse pointer passes over the button; then the button takes on the standard Windows button appearance.
        /// @note If the control that has focus accepts and processes the ENTER key press, the Button does not process it. For example, if a multiline TextBox or another button has focus, that control processes the ENTER key press instead of the accept button.
        class Button : public ButtonBase {
        public:
          Button();

          Property<System::Windows::FormsD::AutoSizeMode> AutoSizeMode {
            pcf_get {return this->GetAutoSizeMode();},
            pcf_set {this->SetAutoSizeMode(value);}
          };
          
          Property<System::Drawing::ContentAlignment> TextAlign {
            pcf_get {return this->textAlign;},
            pcf_set {this->SetTextAlign(value);}
          };
          
          void PerformClick() {
            if (this->Visible && this->Enabled)
              this->OnClick(EventArgs());
          }

        private:
          System::Windows::FormsD::AutoSizeMode GetAutoSizeMode() const;
          void SetAutoSizeMode(System::Windows::FormsD::AutoSizeMode autoSizeMode);
          
          bool GetCanFocus() const override {return true;}
          
          System::Drawing::SizeF GetComputeSize() const override {
            System::Drawing::SizeF size = this->CreateGraphics().MeasureString(this->Text(), this->Font());
            size.Width += 23;
            if (size.Height < 23)
              size.Height = 23;
            if (size.Width < 75)
              size.Width = 75;
            return size;
          }

          System::Drawing::Size GetDefaultSize() const override {return System::Drawing::Size(75, 23);}
          
          bool HasClickRaised(MouseButtons button) const override {
            static System::Collections::Generic::SortedDictionary<Enum<MouseButtons>, Boolean> hasClickRaised = {{MouseButtons::None, false}, {MouseButtons::Left, true}, {MouseButtons::Right, false}, {MouseButtons::Middle, false}, {MouseButtons::XButton1, false}, {MouseButtons::XButton2, false}};
            return hasClickRaised[button];
          }

          bool HasClickReplaceDoubleClick(MouseButtons button) const override {
            static System::Collections::Generic::SortedDictionary<Enum<MouseButtons>, Boolean> hasClickReplaceDoubleClick = {{MouseButtons::None, false}, {MouseButtons::Left, true}, {MouseButtons::Right, false}, {MouseButtons::Middle, false}, {MouseButtons::XButton1, false}, {MouseButtons::XButton2, false}};
            return hasClickReplaceDoubleClick[button];
          }

          bool HasDoubleClickRaised(MouseButtons button) const override {
            static System::Collections::Generic::SortedDictionary<Enum<MouseButtons>, Boolean> hasDoubleClickRaised = {{MouseButtons::None, false}, {MouseButtons::Left, false}, {MouseButtons::Right, false}, {MouseButtons::Middle, false}, {MouseButtons::XButton1, false}, {MouseButtons::XButton2, false}};
            return hasDoubleClickRaised[button];
          }
          
          void SetTextAlign(System::Drawing::ContentAlignment textAlign);
          
          System::Drawing::ContentAlignment textAlign;
          System::Windows::FormsD::AutoSizeMode autoSizeMode;
          static const System::Drawing::Color defaultSelectedColor;
        };
      }
    }
  }
}
