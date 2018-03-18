/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include <Switch/System/Drawing/Color.hpp>
#include "../../../System/Windows/Forms/FileDialogCustomPlaceCollection.hpp"
#include "../../../System/Windows/Forms/CommonDialog.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Displays a dialog box from which the user can select a file.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks FileDialog is an abstract class that contains common behavior for the OpenFileDialog and SaveFileDialog classes. It is not intended to be used directly but contains common behavior for those two classes. You cannot create an instance of FileDialog. Although the class is declared public, you cannot inherit from it, as it contains internal abstract methods. To create a dialog box to select or save a file, use OpenFileDialog or SaveFileDialog.
        /// @remarks FileDialog is a modal dialog box; therefore, when shown, it blocks the rest of the application until the user has chosen a file. When a dialog box is displayed modally, no input (keyboard or mouse click) can occur except to objects on the dialog box. The program must hide or close the dialog box (usually in response to some user action) before input to the calling program can occur.
        /// @warning When you use classes derived from FileDialog, such as OpenFileDialog and SaveFileDialog, avoid using string literals containing absolute paths. Instead, dynamically obtain the path using one or more of the techniques described in the following table.
        /// @remarks If you want to enable users to select a folder instead of a file, use the FolderBrowserDialog.
        /// @remarks Depending upon the type of application, how data associated with the application is stored, and the reason for accessing the file system, there are many possible ways in which you can create a directory path. The following table shows the techniques for creating paths dynamically.
        /// | Path or program category                                                          | Class and members to use                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
        /// |-----------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        /// | Standard Windows paths, such as Program Files, MyDocuments, the Desktop and so on | The System.Environment class is the most complete source for these, either through its static methods, such as SystemDirectory, or through the GetFolderPath method, using one of the Environment.SpecialFolder enumerated values.                                                                                                                                                                                                                                                        |
        /// | Paths related to the current application                                          | The Application class has static members to obtain certain paths, such as StartupPath, ExecutablePath, LocalUserAppDataPath, and CommonAppDataPath.<br><br>The GetTempPath method of the System.IO.Path returns the path of the temporary folder.<br><br>The GetCurrentDirectory method of the System.IO.Directory class returns the application's current executing directory.<br><br>The RootDirectory property of the DriveInfo class represents the specified drive's root directory. |
        /// | Paths stored as application settings                                              | Access the corresponding applications settings property of the wrapper class derived from ApplicationSettingsBase. For more information, see Application Settings for Windows Forms.                                                                                                                                                                                                                                                                                                      |
        /// | Registry storage                                                                  | Some applications store directory information in the registry. The Application class has the CommonAppDataPath and LocalUserAppDataPath properties that resolve to a RegistryKey value.                                                                                                                                                                                                                                                                                                   |
        /// | ClickOnce applications                                                            | For ClickOnce applications, use Application class members such as UserAppDataPath, which will return a pointer to the ClickOnce data directory. For more information, see Accessing Local and Remote Data in ClickOnce Applications.                                                                                                                                                                                                                                                      |
        /// | International applications                                                        | For international applications, retrieve the relative path portion from a string resource in your application by using the System.Resources.ResourceReader class. For more information about globalization and localization, see the topic Globalizing and Localizing .NET Framework Applications.                                                                                                                                                                                        |
        /// @remarks Notice that a full path may be built up using one or more of the described techniques. For example, the GetFolderPath method might be used to obtain the path to the MyDocuments folder, then an application setting may be used to add a relative subdirectory portion.
        /// @remarks The System.IO.Path class contains static members to assist in manipulating absolute and relative path strings, whereas the System.IO.File and System.IO.Directory classes have static members that actually manipulate files and directories, respectively.
        /// @par Important
        /// If the user of your application changes the folder in the FileDialog, then the current working directory for your application is set to the location specified in the FileDialog. To prevent this, set the RestoreDirectory property to true.
        /// @par Examples
        /// The following code example uses the OpenFileDialog implementation of FileDialog and illustrates creating, setting of properties, and showing the dialog box. The example uses the ShowDialog method to display the dialog box and return the DialogResult. The example requires a form with a Button placed on it and the System.IO namespace added to it.
        /// @code
        /// void button1_Click(const object& sender, const System::EventArgs& e) {
        ///   Stream myStream;
        ///   OpenFileDialog openFileDialog1;
        ///
        ///   openFileDialog1.InitialDirectory = "c:\\" ;
        ///   openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*" ;
        ///   openFileDialog1.FilterIndex = 2 ;
        ///   openFileDialog1.RestoreDirectory = true ;
        ///
        ///   if (openFileDialog1.ShowDialog() == DialogResult::OK) {
        ///     try {
        ///       using_ (myStream = openFileDialog1.OpenFile()) {
        ///         // Insert code to read the stream here.
        ///       }
        ///     } catch (const Exception& ex) {
        ///       MessageBox::Show("Error: Could not read file from disk. Original error: "_s + ex.Message);
        ///     }
        ///   }
        /// }
        /// @endcode
        class system_windows_forms_export_ FileDialog : public CommonDialog {
        public:
          /// @brief Gets or sets a value indicating whether the dialog box automatically adds an extension to a file name if the user omits the extension.
          /// @return bool true if the dialog box adds an extension to a file name if the user omits the extension; otherwise, false. The default value is true.
          /// @remarks The extension added to a file name depends on the currently selected file filter and the value of the CheckFileExists property.
          /// @remarks If the CheckFileExists property is true, the dialog box adds the first extension from the current file filter that matches an existing file. If no files match the current file filter, the dialog box adds the extension specified in the DefaultExt property.
          /// @remarks If the CheckFileExists property is false, the dialog box adds the first valid file name extension from the current file filter. If the current file filter contains no valid file name extensions, the dialog box adds the extension specified in the DefaultExt property.
          property_<bool> AddExtension {
            get_ {return this->addExtension;},
            set_ {this->addExtension = value;}
          };

          /// @brief Gets or sets a value indicating whether this FileDialog instance should automatically upgrade appearance and behavior when running on Windows Vista.
          /// @return bool true if this FileDialog instance should automatically upgrade appearance and behavior when running on Windows Vista; otherwise, false. The default is true.
          /// @remarks If this property is false, the FileDialog class will have a Windows XP-style appearance and behavior on Windows Vista.
          /// @remarks On macOS, Linux and Windows XP, this property does not have any effect.
          property_<bool>AutoUpgradeEnabled {
            get_ {return this->autoUpgradeEnabled;},
            set_ {this->autoUpgradeEnabled = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box displays a warning if the user specifies a file name that does not exist.
          /// @return bool true if the dialog box displays a warning if the user specifies a file name that does not exist; otherwise, false. The default value is false.
          /// @remarks The default value is true for an inheriting OpenFileDialog and false for an inheriting SaveFileDialog.
          property_<bool> CheckFileExists {
            get_ {return this->checkFileExists;},
            set_ {this->checkFileExists = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box displays a warning if the user specifies a path that does not exist.
          /// @return bool true if the dialog box displays a warning when the user specifies a path that does not exist; otherwise, false. The default value is true.
          property_<bool> CheckPathExists {
            get_ {return this->checkPathExists;},
            set_ {this->checkPathExists = value;}
          };

          /// @brief Gets the custom places collection for this FileDialog instance.
          /// @return System::Windows::Forms::FileDialogCustomPlaceCollection The custom places collection for this FileDialog instance.
          /// @remarks On macOS, Linux and Windows XP, this property does not have any effect.
          /// @par Examples
          /// The following code example demonstrates how to use the CustomPlaces collection. To run this example, paste the following code into a Windows Form and call InitializeDialogAndButton from the form's constructor or Load event-handling method.
          /// @code
          /// OpenFileDialog openFileDialog1;
          /// Button button1;
          ///
          /// void InitializeDialogAndButton() {
          ///   this->button1.Location = System::Drawing::Point(53, 37);
          ///   this->button1.AutoSize = true;
          ///   this->button1.Text = "Show dialog with custom places.";
          ///   this->button1.UseVisualStyleBackColor = true;
          ///   this->button1.Click += System::EventHandler(*this, &Form1::button1_Click);
          ///   this->Controls().Add(this->button1);
          /// }
          ///
          /// void button1_Click(const object& sender, const EventArgs& e) {
          ///   // Add Pictures custom place using GUID.
          ///   openFileDialog1.CustomPlaces().Add("33E28130-4E1E-4676-835A-98395C3BC3BB");
          ///
          ///   // Add Links custom place using GUID
          ///   openFileDialog1.CustomPlaces().Add(FileDialogCustomPlace(Guid("BFB9D5E0-C6A9-404C-B2B2-AE6DB6AF4968")));
          ///
          ///   // Add Windows custom place using file path.
          ///   openFileDialog1.CustomPlaces().Add(R"(c:\Windows)");
          ///
          ///   openFileDialog1.ShowDialog();
          /// }
          /// @endcode
          property_<System::Windows::Forms::FileDialogCustomPlaceCollection&> FileDialogCustomPlaceCollection {
            get_->System::Windows::Forms::FileDialogCustomPlaceCollection& {return this->fileDialogCustomPlaceCollection;},
            set_ {this->fileDialogCustomPlaceCollection = value;}
          };

          /// @brief Gets or sets the default file name extension.
          /// @return string The default file name extension. The returned string does not include the period. The default value is an empty string ("").
          /// @remarks When the user of your application specifies a file name without an extension, the FileDialog appends an extension to the file name. The extension that is used is determined by the Filter and DefaultExt properties. If a filter is selected in the FileDialog and the filter specifies an extension, then that extension is used. If the filter selected uses a wildcard in place of the extension, then the extension specified in the DefaultExt property is used.
          property_<string> DefaultExt {
            get_ {return this->defaultExt;},
            set_ {this->defaultExt = value;}
          };

        protected:
          /// @cond
          bool addExtension = true;
          bool autoUpgradeEnabled = true;
          bool checkFileExists = false;
          bool checkPathExists = false;
          System::Windows::Forms::FileDialogCustomPlaceCollection fileDialogCustomPlaceCollection;
          string defaultExt;
          /// @endcond
        };
      }
    }
  }
}
