/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include "../../../System/Windows/Forms/FileDialog.hpp"
#include <Switch/System/IO/File.hpp>
#include <Switch/System/IO/Path.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Prompts the user to select a location for saving a file. This class cannot be inherited.
        /// @par Library
        /// Switch.System.Windows.Forms
        class system_windows_forms_export_ SaveFileDialog final : public FileDialog {
        public:
          /// @brief Initializes an instance of the SaveFileDialog class.
          /// @remarks This is the default, compiler-supplied constructor for the SaveFileDialog class.
          SaveFileDialog();

          /// @brief Gets or sets a value indicating whether the dialog box prompts the user for permission to create a file if the user specifies a file that does not exist.
          /// @return bool true if the dialog box prompts the user before creating a file if the user specifies a file name that does not exist; false if the dialog box automatically creates the new file without prompting the user for permission. The default value is false.
          /// @par Examples
          /// The following code example demonstrates using the RichTextBox.SaveFile and RichTextBox.LoadFile methods with streams. It also demonstrates using the FileName, DefaultExt, SaveFileDialog.CreatePrompt, and SaveFileDialog.OverwritePrompt members.<br><br>
          /// This is a complete example that is ready to run when you copy it to your project.
          /// @include RichTextBox.cpp
          property_<bool> CreatePrompt {
            get_ {return this->createPrompt;},
            set_ {this->createPrompt = value;}
          };

          /// @brief Opens the file with read/write permission selected by the user.
          /// @return FileStream The read/write file selected by the user.
          /// @warning For security purposes, this method creates a new file with the selected name and opens it with read/write permissions. This can cause unintentional loss of data if you select an existing file to save to. To save data to an existing file while retaining existing data, use the File class to open the file using the file name returned in the FileName property.
          /// @par Examples
          /// The following code example illustrates creating a SaveFileDialog, setting members, calling the dialog box using the ShowDialog method, and opening the selected file. The example requires a form with a button placed on it.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   SaveFileDialog saveFileDialog1;
          ///
          ///   saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*"  ;
          ///   saveFileDialog1.FilterIndex = 2 ;
          ///   saveFileDialog1.RestoreDirectory = true ;
          ///
          ///   if (saveFileDialog1.ShowDialog() == DialogResult::OK) {
          ///     using_(FileStream myStream = saveFileDialog1.OpenFile()) {
          ///       // Code to write the stream goes here.
          ///       myStream.Close();
          ///     }
          ///   }
          /// }
          /// @endcode
          System::IO::FileStream OpenFile() {return System::IO::File::Open(this->FileName, Switch::System::IO::FileMode::OpenOrCreate, Switch::System::IO::FileAccess::ReadWrite);}

          /// @brief Resets all properties to their default values.
          void Reset() override;

        protected:
          /// @cond
          bool createPrompt = false;
          /// @endcond

        private:
          bool RunDialog(intptr hwndOwner) override;
        };
      }
    }
  }
}
