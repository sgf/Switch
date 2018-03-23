/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Drawing/Color.hpp>
#include <Switch/System/ComponentModel/CancelEventHandler.hpp>
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
        ///   openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
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
          /// @par Examples
          /// The following code example demonstrates using the RichTextBox.SaveFile and RichTextBox.LoadFile methods with streams. It also demonstrates using the FileName, DefaultExt, SaveFileDialog.CreatePrompt, and SaveFileDialog.OverwritePrompt members.<br><br>
          /// This is a complete example that is ready to run when you copy it to your project.
          /// @include RichTextBox.cpp
          property_<string> DefaultExt {
            get_ {return this->defaultExt;},
            set_ {this->defaultExt = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box returns the location of the file referenced by the shortcut or whether it returns the location of the shortcut (.lnk).
          /// @return bool true if the dialog box returns the location of the file referenced by the shortcut; otherwise, false. The default value is true.
          property_<bool> DereferenceLinks {
            get_ {return this->dereferenceLinks;},
            set_ {this->dereferenceLinks = value;}
          };

          /// @brief Gets or sets a string containing the file name selected in the file dialog box.
          /// @return string The file name selected in the file dialog box. The default value is an empty string ("").
          /// @remarks The file name includes both the file path and the extension. If no files are selected, this method returns an empty string ("").
          /// @remarks When used from the SaveFileDialog class, this property represents the file being saved; when used from the OpenFileDialog class, it represents the file being opened.
          /// @remarks This property can only be the name of one selected file. If you want to return an array containing the names of all selected files in a multiple-selection dialog box, use FileNames.
          /// @par Examples
          /// The following code example demonstrates using the RichTextBox.SaveFile and RichTextBox.LoadFile methods with streams. It also demonstrates using the FileName, DefaultExt, SaveFileDialog.CreatePrompt, and SaveFileDialog.OverwritePrompt members.<br><br>
          /// This is a complete example that is ready to run when you copy it to your project.
          /// @include RichTextBox.cpp
          property_<string> FileName {
            get_ {return this->fileName;},
            set_ {this->fileName = value;}
          };

          /// @brief Gets the file names of all selected files in the dialog box.
          /// @return Array<string> An array of type String, containing the file names of all selected files in the dialog box.
          /// @remarks Each file name includes both the file path and the extension. If no files are selected, this method returns an empty array.
          /// @par Examples
          /// The following code example allows the user to select a number of images and display them in PictureBox controls on a Form. It demonstrates initializing an OpenFileDialog, setting the Title and Filter properties, and allowing the user to select multiple files by setting the Multiselect property to true. This code example assumes that your form already has an OpenFileDialog control named openFileDialog1, a Button named SelectFileButton, and a FlowLayoutPanel named flowLayoutPanel1.
          /// @code
          /// void Form1_Load(const object& sender, const EventArgs& e) {
          ///   InitializeOpenFileDialog();
          /// }
          ///
          /// void InitializeOpenFileDialog() {
          ///   // Set the file dialog to filter for graphics files.
          ///   this->openFileDialog1.Filter = "Images (*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.*";
          ///
          ///   // Allow the user to select multiple images.
          ///   this->openFileDialog1.Multiselect = true;
          ///   this->openFileDialog1.Title = "My Image Browser";
          /// }
          ///
          /// void selectFilesButton_Click(const object& sender, const EventArgs& e) {
          ///   DialogResult dr = this->openFileDialog1.ShowDialog();
          ///   if (dr == System::Windows::Forms::DialogResult::OK) {
          ///     // Read the files
          ///     for (const String& file : openFileDialog1.FileNames) {
          ///       // Create a PictureBox.
          ///       try {
          ///         this->pictureBoxes.Add(new_<PictureBox>());
          ///         Image loadedImage = Image.FromFile(file);
          ///         this->pictureBoxes[this->pictureBoxes.Count - 1]->Height = loadedImage.Height;
          ///         this->pictureBoxes[this->pictureBoxes.Count - 1]->Width = loadedImage.Width;
          ///         this->pictureBoxes[this->pictureBoxes.Count - 1]->Image = loadedImage;
          ///         flowLayoutPanel1.Controls().Add(*this->pictureBoxes[this->pictureBoxes.Count - 1]);
          ///       }
          ///       catch (const SecurityException& ex) {
          ///         // The user lacks appropriate permissions to read files, discover paths, etc.
          ///         MessageBox::Show("Security error. Please contact your administrator for details.\n\nError message: "_s + ex.Message + "\n\nDetails (send to Support):\n\n"_s + ex.StackTrace);
          ///       }
          ///       catch (const Exception& ex) {
          ///         // Could not load the image - probably related to Windows file system permissions.
          ///         MessageBox.Show("Cannot display the image: "_s + file.Substring(file.LastIndexOf('\\')) + ". You may not have permission to read the file, or it may be corrupt.\n\nReported error: "_s + ex.Message);
          ///       }
          ///     }
          ///   }
          /// @endcode
          property_<Array<string>, readonly_> FileNames {
            get_ {return this->fileNames.ToArray();}
          };

          /// @brief Gets or sets the current file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box.
          /// @return string The file filtering options available in the dialog box.
          /// @exception ArgumentException Filter format is invalid.
          /// @remarks For each filtering option, the filter string contains a description of the filter, followed by the vertical bar (|) and the filter pattern. The strings for different filtering options are separated by the vertical bar.
          /// @remarks The following is an example of a filter string:
          /// @code
          /// Text files (*.txt)|*.txt|All files (*.*)|*.*
          /// @endcode
          /// @remarks You can add several filter patterns to a filter by separating the file types with semicolons, for example:
          /// @code
          /// Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.*
          /// @endcode
          /// Use the FilterIndex property to set which filtering option is shown first to the user.
          /// @par Examples
          /// The following code example uses the OpenFileDialog implementation of FileDialog and illustrates creating, setting of properties, and showing the dialog box. The example uses the Filter and FilterIndex properties to provide a list of filters for the user. The example requires a form with a Button placed on it and the System.IO namespace added to it.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   OpenFileDialog openFileDialog1;
          ///
          ///   openFileDialog1.InitialDirectory = "c:\\" ;
          ///   openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*" ;
          ///   openFileDialog1.FilterIndex = 2 ;
          ///   openFileDialog1.RestoreDirectory = true ;
          ///
          ///   if (openFileDialog1.ShowDialog() == DialogResult::OK) {
          ///     try {
          ///       using_ (FileStream myStream = openFileDialog1.OpenFile()) {
          ///         // Insert code to read the stream here.
          ///       }
          ///     } catch (const Exception& ex) {
          ///       MessageBox::Show("Error: Could not read file from disk. Original error: "_s + ex.Message);
          ///     }
          ///   }
          /// }
          /// @endcode
          property_<string> Filter {
            get_ {return this->filter;},
            set_ {
              if (this->filter != value) {
                Array<string> filterPatterns = value.Split('|');
                if (filterPatterns.Count % 2 != 0) throw ArgumentException(caller_);
                for (int32 index = 0; index < filterPatterns.Count; index += 2)
                  this->filters.Add({filterPatterns[index], filterPatterns[index + 1].Split(';')});
                this->filter = value;
              }
            }
          };

          /// @brief Gets or sets the index of the filter currently selected in the file dialog box.
          /// @return int32 A value containing the index of the filter currently selected in the file dialog box. The default value is 1.
          /// @remarks Use the FilterIndex property to set which filtering option is shown first to the user. You can also use the value of FilterIndex after showing the file dialog to perform special file operations depending upon the filter chosen.
          /// @note The index value of the first filter entry is 1.
          /// @par Examples
          /// The following code example uses the OpenFileDialog implementation of FileDialog and illustrates creating, setting of properties, and showing the dialog box. The example uses the Filter and FilterIndex properties to provide a list of filters for the user. The example requires a form with a Button placed on it and the System.IO namespace added to it.
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
          property_<int32> FilterIndex {
            get_ {return this->filterIndex;},
            set_ {this->filterIndex = value;}
          };

          /// @brief Gets or sets the initial directory displayed by the file dialog box.
          /// @brief return string The initial directory displayed by the file dialog box. The default is an empty string ("").
          /// @remarks The InitialDirectory property is typically set using one of the following sources:
          /// * A path that was previously used in the program, perhaps retained from the last directory or file operation.
          /// * A path read from a persistent source, such as an application setting, a Registry or a string resource in the application.
          /// * Standard Windows system and user paths, such as Program Files, MyDocuments, MyMusic, and so on (which you can obtain using the GetFolderPath method)
          /// * A path related to the current application, such as its startup directory (which you can obtain using properties on the Application object).
          /// @remarks For more information about creating dynamic paths, see the FileDialog class overview.
          /// @remarks On Windows Vista, if InitialDirectory is set to a full file name instead of just a directory path, the initial directory will default either to the application path, or to the directory from which the user last selected a file.
          /// @par Examples
          /// The following code example uses the OpenFileDialog implementation of FileDialog and illustrates creating, setting of properties, and showing the dialog box. The example uses the Filter and FilterIndex properties to provide a list of filters for the user. The example requires a form with a Button placed on it and the System.IO namespace added to it.
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
          property_<string> InitialDirectory {
            get_ {return this->initialDirectory;},
            set_ {this->initialDirectory = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box restores the directory to the previously selected directory before closing.
          /// @return bool rue if the dialog box restores the current directory to the previously selected directory if the user changed the directory while searching for files; otherwise, false. The default value is false.
          /// @par Examples
          /// The following code example uses the OpenFileDialog implementation of FileDialog and illustrates creating, setting of properties, and showing the dialog box. The example uses the Filter and FilterIndex properties to provide a list of filters for the user. The example requires a form with a Button placed on it and the System.IO namespace added to it.
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
          property_<bool> RestoreDirectory {
            get_ {return this->restoreDirectory;},
            set_ {this->restoreDirectory = value;}
          };

          /// @brief Gets or sets a value indicating whether the Help button is displayed in the file dialog box.
          /// @return bool true if the dialog box includes a help button; otherwise, false. The default value is false.
          /// @remarks A HelpRequested event is raised when the user clicks the Help button.
          property_<bool> ShowHelp {
            get_ {return this->showHelp;},
            set_ {this->showHelp = value;}
          };

          /// @brief Gets or sets a value that indicates whether the panel displays files that are normally hidden from the user.
          /// @return bool true if the dialog box shows hidden files; otherwise false. the default value is false;
          /// @remarks On Windows, this property does not have any effect.
          property_<bool> ShowHiddenFiles {
            get_ {return this->showHiddenFiles;},
            set_ {this->showHiddenFiles = value;}
          };

          /// @brief Gets or sets whether the dialog box supports displaying and saving files that have multiple file name extensions.
          /// @return bool true if the dialog box supports multiple file name extensions; otherwise, false. The default is false.
          /// @remarks Sometimes users must open and save files that use multiple file name extensions. For example, the application manifest files used by the ClickOnce deployment technology end in the complex file name extension ".exe.manifest". Setting this property to true enables you to set the Filter property to a multi-dotted extension.
          /// @remarks If SupportMultiDottedExtensions is false, and you assign a multi-dotted extension to Filter, derived controls such as SaveFileDialog will only use the last extension in the string. For example, ".manifest" will be used instead of ".exe.manifest".
          /// @par Examples
          /// The following code example saves files with the extension ".data.txt". This code example requires that your application host a SaveFileDialog named saveFileDialog1 and a Button named button1.
          /// @code
          /// Form1() {
          ///   this->InitializeComponent();
          ///   this->button1.Click += EventHandler(*this, &Form1::button1_Click);
          /// }
          ///
          /// void button1_Click(const object& sender, const EventArgs& e) {
          ///   saveFileDialog1.Filter = "Data text files|.data.txt";
          ///   saveFileDialog1.SupportMultiDottedExtensions = true;
          ///   saveFileDialog1.FileOk += CancelEventHandler(*this, &Form::saveFileDialog1_FileOk);
          ///   saveFileDialog1.ShowDialog();
          /// }
          ///
          /// void saveFileDialog1_FileOk(const object& sender, CancelEventArgs e) {
          ///   try {
          ///     FileStream s = saveFileDialog1.OpenFile();
          ///     StreamWriter sw(s, Encoding.Unicode);
          ///     sw.WriteLine("Hello, world!");
          ///     sw.Close();
          ///   } catch (const Exception& ex) {
          ///     MessageBox.Show("Error: Could not write file. Please try again later. Error message: "_s + ex.Message, "Error Writing File", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
          ///   }
          /// }
          /// @endcode
          property_<bool> SupportMultiDottedExtensions {
            get_ {return this->supportMultiDottedExtensions;},
            set_ {this->supportMultiDottedExtensions = value;}
          };

          /// @brief Gets or sets the file dialog box title.
          /// @return string The file dialog box title. The default value is an empty string ("").
          /// @remarks The string is placed in the title bar of the dialog box. If the title is an empty string, the system uses a default title, which is either "Save As" or "Open".
          /// @par Examples
          /// The following code example demonstrates initializing an OpenFileDialog, setting the Title and Filter properties, and allowing the user to select multiple files by setting the OpenFileDialog.Multiselect property to true. To run this example, paste the following code in a form containing an OpenFileDialog named OpenFileDialog1 and a Button named fileButton. Call the InitializeOpenFileDialog method in the form's constructor or Load method. The example also requires that the Click event of the Button control is connected to the event handler defined in the example.
          /// @code
          /// void InitializeOpenFileDialog() {
          ///   // Set the file dialog to filter for graphics files.
          ///   this->openFileDialog1.Filter = "Images (*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.*";
          ///
          ///   // Allow the user to select multiple images.
          ///   this->openFileDialog1.Multiselect = true;
          ///   this->openFileDialog1.Title = "My Image Browser";
          /// }
          ///
          /// void selectFilesButton_Click(const object& sender, const EventArgs& e) {
          ///   this->openFileDialog1.ShowDialog();
          /// }
          /// @endcode
          property_<string> Title {
            get_ {return this->title;},
            set_ {this->title = value;}
          };

          /// @brief Gets or sets a value indicating whether the dialog box accepts only valid Win32 file names.
          /// @return bool true if the dialog box accepts only valid Win32 file names; otherwise, false. The default value is true.
          /// @remarks If the edit control contains anything but spaces when the user clicks OK, the dialog box returns the file name, whether it is valid or not. No default extension is added to the text.
          property_<bool> ValidateNames {
            get_ {return this->validateNames;},
            set_ {this->validateNames = value;}
          };

          /// @brief Occurs when the user clicks on the Open or Save button on a file dialog box.
          /// @remarks For information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example saves files with the extension ".data.txt". This code example requires that your application host a SaveFileDialog named saveFileDialog1 and a Button named button1.
          /// @code
          /// Form1() {
          ///   this->InitializeComponent();
          ///   this->button1.Click += EventHandler(*this, &Form1::button1_Click);
          /// }
          ///
          /// void button1_Click(const object& sender, const EventArgs& e) {
          ///   saveFileDialog1.Filter = "Data text files|.data.txt";
          ///   saveFileDialog1.SupportMultiDottedExtensions = true;
          ///   saveFileDialog1.FileOk += CancelEventHandler(*this, &Form::saveFileDialog1_FileOk);
          ///   saveFileDialog1.ShowDialog();
          /// }
          ///
          /// void saveFileDialog1_FileOk(const object& sender, CancelEventArgs e) {
          ///   try {
          ///     FileStream s = saveFileDialog1.OpenFile();
          ///     StreamWriter sw(s, Encoding.Unicode);
          ///     sw.WriteLine("Hello, world!");
          ///     sw.Close();
          ///   } catch (const Exception& ex) {
          ///     MessageBox.Show("Error: Could not write file. Please try again later. Error message: "_s + ex.Message, "Error Writing File", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
          ///   }
          /// }
          /// @endcode
          ComponentModel::CancelEventHandler FileOk;

          /// @cond
          Array<System::Collections::Generic::KeyValuePair<string, Array<string>>> __get_filters__() {return this->filters.ToArray();}
          void __set__file_names__(const Array<string>& fileNames) {this->fileNames = fileNames;}
          /// @endcond

        protected:
          /// @brief Raises the FileOk event.
          /// @param e A CancelEventArgs that contains the event data.
          void OnFileOk(ComponentModel::CancelEventArgs& e) {this->FileOk(*this, e);}

          /// @cond
          bool addExtension = true;
          bool autoUpgradeEnabled = true;
          bool checkFileExists = false;
          bool checkPathExists = false;
          System::Windows::Forms::FileDialogCustomPlaceCollection fileDialogCustomPlaceCollection;
          string defaultExt;
          bool dereferenceLinks = true;
          string fileName;
          System::Collections::Generic::List<string> fileNames;
          string filter;
          System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<string, Array<string>>> filters;
          int32 filterIndex = 1;
          string initialDirectory;
          bool restoreDirectory = false;
          bool showHelp = false;
          bool showHiddenFiles = false;
          bool supportMultiDottedExtensions = false;
          string title;
          bool validateNames = true;
          /// @endcond
        };
      }
    }
  }
}
