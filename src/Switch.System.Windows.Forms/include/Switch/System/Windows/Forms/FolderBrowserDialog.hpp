/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include <Switch/System/Environment.hpp>
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
        /// @brief Prompts the user to select a folder. This class cannot be inherited.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks This class provides a way to prompt the user to browse, create, and eventually select a folder. Use this class when you only want to allow the user to select folders, not files. Browsing of the folders is done through a tree control. Only folders from the file system can be selected; virtual folders cannot.
        /// @remarks Typically, after creating a new FolderBrowserDialog, you set the RootFolder to the location from which to start browsing. Optionally, you can set the SelectedPath to an absolute path of a subfolder of RootFolder that will initially be selected. You can also optionally set the Description property to provide additional instructions to the user. Finally, call the ShowDialog method to display the dialog box to the user. When the dialog box is closed and the dialog box result from ShowDialog is DialogResult.OK, the SelectedPath will be a string containing the path to the selected folder.
        /// @remarks You can use the ShowNewFolderButton property to control if the user is able to create new folders with the New Folder button.
        /// @remarks FolderBrowserDialog is a modal dialog box; therefore, when shown, it blocks the rest of the application until the user has chosen a folder. When a dialog box is displayed modally, no input (keyboard or mouse click) can occur except to objects on the dialog box. The program must hide or close the dialog box (usually in response to some user action) before input to the calling program can occur.
        /// @par Examples
        /// The following code example creates an application that enables the user to open rich text (.rtf) files within the RichTextBox control.
        /// @include RichTextBox.cpp
        class system_windows_forms_export_ FolderBrowserDialog final : public CommonDialog {
        public:
          /// @brief Initializes a new instance of the FolderBrowserDialog class.
          /// @remarks The default constructor initializes properties to their default values.
          /// @remarks When a new FolderBrowserDialog is created, the RootFolder property is set to Environment.SpecialFolder.Desktop, the Description property is set to an empty string (""), the SelectedPath property is set to an empty string, and the ShowNewFolderButton property is set to true.
          /// @remarks ypically, after creating a new FolderBrowserDialog, you set the RootFolder to the location from which to start browsing. Optionally, you can set the SelectedPath to the path of a subfolder of RootFolder that will initially be selected. You can also optionally set the Description property to provide additional instructions to the user. Finally, call the ShowDialog method to display the dialog box to the user. When the dialog box is closed and the dialog result from ShowDialog is DialogResult.OK, the SelectedPath will be a string containing the path to the selected folder.
          /// @remarks FolderBrowserDialog is a modal dialog box; therefore, when shown, it blocks the rest of the application until the user has chosen a folder. When a dialog box is displayed modally, no input (keyboard or mouse click) can occur except to objects on the dialog box. The program must hide or close the dialog box (usually in response to some user action) before input to the calling program can occur.
          /// @par Examples
          /// The following code example creates an application that enables the user to open rich text (.rtf) files within the RichTextBox control.
          /// @include RichTextBox.cpp
          FolderBrowserDialog();

          /// @brief Gets or sets the descriptive text displayed above the tree view control in the dialog box.
          /// @return string The description to display. The default is an empty string ("").
          /// @remarks The Description property can be used to specify additional information to the user, like instructions.
          /// @par Examples
          /// The following code example creates an application that enables the user to open rich text (.rtf) files within the RichTextBox control.
          /// @include RichTextBox.cpp
          property_<string> Description {
            get_ {return this->description;},
            set_ {this->description = value;}
          };

          /// @brief Gets or sets the root folder where the browsing starts from.
          /// @return Environment::SpecialFolder One of the Environment::SpecialFolder values. The default is Desktop.
          /// @exception InvalidEnumArgumentException The value assigned is not one of the Environment.SpecialFolder values.
          /// @remarks Only the specified folder and any subfolders that are beneath it will appear in the dialog box and be selectable. The SelectedPath property, along with RootFolder, determines what the selected folder will be when the dialog box is displayed, as long as SelectedPath is an absolute path that is a subfolder of RootFolder (or more accurately, points to a subfolder of the shell namespace represented by RootFolder).
          /// @par Examples
          /// The following code example creates an application that enables the user to open rich text (.rtf) files within the RichTextBox control.
          /// @include RichTextBox.cpp
          property_<Environment::SpecialFolder> RootFolder {
            get_ {return this->rootFolder;},
            set_ {this->rootFolder = value;}
          };

          /// @brief Gets or sets the path selected by the user.
          /// @return string The path of the folder first selected in the dialog box or the last folder selected by the user. The default is an empty string ("").
          /// @remarks If the SelectedPath property is set before showing the dialog box, the folder with this path will be the selected folder, as long as SelectedPath is set to an absolute path that is a subfolder of RootFolder (or more accurately, points to a subfolder of the shell namespace represented by RootFolder).
          /// @remarks If the ShowDialog returns OK, meaning the user clicked the OK button, the SelectedPath property will return a string containing the path to the selected folder. If ShowDialog returns Cancel, meaning the user canceled out of the dialog box, this property will have the same value that it had prior to displaying the dialog box. If the user selects a folder that does not have a physical path (for example, My Computer), the OK button on the dialog box will be disabled.
          /// @par Examples
          /// The following code example creates an application that enables the user to open rich text (.rtf) files within the RichTextBox control.
          /// @include RichTextBox.cpp
          property_<string> SelectedPath {
            get_ {return this->selectedPath;},
            set_ {this->selectedPath = value;}
          };

          /// @brief Gets or sets a value indicating whether the New Folder button appears in the folder browser dialog box.
          /// @return bool true if the New Folder button is shown in the dialog box; otherwise, false. The default is true.
          /// @remarks When ShowNewFolderButton is true, the New Folder button is visible, giving the user a chance to create a folder. When the user clicks the New Folder button, a new folder is created and the user is prompted to specify the folder name. The selected node in the tree becomes the parent of the new folder. The actual caption of the New Folder button can vary depending upon the operating system
          /// @par Examples
          /// The following code example creates an application that enables the user to open rich text (.rtf) files within the RichTextBox control.
          /// @include RichTextBox.cpp
          property_<bool> ShowNewFolderButton {
            get_ {return this->showNewFolderButton;},
            set_ {this->showNewFolderButton = value;}
          };

          /// @brief When overridden in a derived class, resets the properties of a common dialog box to their default values.
          void Reset() override;

        private:
          bool RunDialog(intptr hwndOwner) override;

          /// @cond
          string description;
          Environment::SpecialFolder rootFolder = Environment::SpecialFolder::Desktop;
          string selectedPath;
          bool showNewFolderButton = true;
          /// @endcond
        };
      }
    }
  }
}
