/// @file
/// @brief Contains Switch::System::Windows::Forms::AutoSizeMode class.
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
        /// @brief Specifies how a control will behave when its AutoSize property is enabled.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks Setting the GrowAndShrink value produces the same behavior that you get for controls with the AutoSize property enabled but which have no
        /// @remarks AutoSizeMode property. The MinimumSize and MaximumSize properties are respected, but the current value of the Size property is ignored.
        /// @par Examples
        /// The following code example shows a form created using code that automatically resizes to fit its contents. When ran, the form will display a Label, a TextBox for entering a URL, and a Button for displaying that URL inside of the user's default Web browser. The code example uses a FlowLayoutPanel to lay out the contained controls one after the other, and sets the AutoSize and AutoSizeMode to grow and shrink to fit the contents of its form.
        /// @code
        /// void Form1_Load(const object& sender, const EventArgs& e) {
        ///   this->AutoSize = true;
        ///   this->AutoSizeMode = AutoSizeMode::GrowAndShrink;
        ///   this->Text = "URL Opener";
        ///
        ///   flowPanel.AutoSize = true;
        ///   flowPanel.AutoSizeMode = AutoSizeMode::GrowAndShrink;
        ///   this->Controls().Add(flowPanel);
        ///
        ///   urlLabel.Name = "urlLabel";
        ///   urlLabel.Text = "URL:";
        ///   urlLabel.Width = 50;
        ///   urlLabel.TextAlign = ContentAlignment::MiddleCenter;
        ///   flowPanel.Controls().Add(urlLabel);
        ///
        ///   urlTextBox.Name = "urlTextBox";
        ///   urlTextBox.Width = 250;
        ///   flowPanel.Controls().Add(urlTextBox);
        ///
        ///   urlButton.Name = "urlButton";
        ///   urlButton.Text = "Open URL in Browser";
        ///   urlButton.Click += EventHandler(*this, &Form1::urlButton_Click);
        ///   flowPanel.Controls().Add(urlButton);
        /// }
        ///
        /// void urlButton_Click(const object& sender, const EventArgs& e) {
        ///   try {
        ///     Uri newUri(urlTextBox.Text);
        ///   } catch (const UriFormatException& uriEx) {
        ///     MessageBox::Show("Sorry, your URL is malformed. Try again. Error: "_s + uriEx.Message);
        ///     urlTextBox.ForeColor = Color::Red;
        ///     return;
        ///   }
        ///
        ///   // Valid URI. Reset any previous error color, and launch the URL in the
        ///   // default browser.
        ///   // NOTE: Depending on the user's settings, this method of starting the
        ///   // browser may use an existing window in an existing Web browser process.
        ///   // To get around this, start up a specific browser instance instead using one of
        ///   // the overloads for Process.Start. You can examine the registry to find the
        ///   // current default browser and launch that, or hard-code a specific browser.
        ///   urlTextBox.ForeColor = Color::Black;
        ///   Process::Start(urlTextBox.Text);
        /// }
        /// @endcode
        enum class AutoSizeMode {
          /// @brief The control grows or shrinks to fit its contents. The control cannot be resized manually.
          GrowAndShrink = 0,
          /// @brief The control grows as much as necessary to fit its contents but does not shrink smaller than the value of its Size property. The form can be resized, but cannot be made so small that any of its contained controls are hidden.
          GrowOnly = 1,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::AutoSizeMode> {
public:
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AutoSizeMode, string>& values, bool& flags) {
    values[System::Windows::Forms::AutoSizeMode::GrowAndShrink] = "GrowAndShrink";
    values[System::Windows::Forms::AutoSizeMode::GrowOnly] = "GrowOnly";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
